#pragma warning(disable:4018)
#include "pch.h"
#include "WindowsOpengl.h"
#include "resource.h"
#include "manager.h"
#include "Utils.h"
#define IMGUI_IMPL_OPENGL_LOADER_GL3W
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

char szTitle[128] = "Test OpenGL 01\0";
GLFWContextStruct ctx;
objeto* plane;
cTimer t;
Word word;

// program procedure

void initializeMainWindow();
void setCallbackFunctions();
void init();
void reshape(GLFWwindow* window, int x, int y);
void mainLoop();

// main render functions

void onRenderScene();

// callbacks

void onMouseWhell(GLFWwindow* window, double x, double y);
void onMouseMove(GLFWwindow* window, double x, double y);

// * process keyboard input at every frame
void processKeyPress(GLFWwindow* window);

// * process single key press input
void key(GLFWwindow* window, int k, int s, int action, int mods);

// * clear console
void cls();

static void glfw_error_callback(int error, const char* description) {
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

void HelpMarker(const char* desc) {
	ImGui::SameLine();
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())     {
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

namespace ui {
	void draw(const char* label, mat4& m) {
		if (ImGui::TreeNode(label)) {
			//ImGui::Text("Matrix %s", label);
			ImGui::SliderFloat4("V[0][X]", (float*)&m[0], -F_PI, F_PI); // Edit 4 floats representing a color
			ImGui::SliderFloat4("V[1][X]", (float*)&m[1], -F_PI, F_PI); // Edit 4 floats representing a color
			ImGui::SliderFloat4("V[2][X]", (float*)&m[2], -F_PI, F_PI); // Edit 4 floats representing a color
			ImGui::SliderFloat4("V[3][X]", (float*)&m[3], -F_PI, F_PI); // Edit 4 floats representing a color
			ImGui::TreePop();
		}
	}

	void show(MaterialData* mat) {
		if (ImGui::TreeNode("Material")) {
			ImGui::Checkbox("castShadows", (bool*)&mat->castShadows);
			ImGui::Checkbox("receiveShadows", (bool*)&mat->receiveShadows);
			ImGui::Checkbox("renderable", (bool*)&mat->renderable);
			ImGui::Checkbox("transparent", (bool*)&mat->transparent);

			uint alphaBlendMode;
			//GL_ZERO							
			//GL_ONE							
			//GL_SRC_COLOR					
			//GL_ONE_MINUS_SRC_COLOR			
			//GL_DST_COLOR					
			//GL_ONE_MINUS_DST_COLOR			
			//GL_SRC_ALPHA					
			//GL_ONE_MINUS_SRC_ALPHA			
			//GL_DST_ALPHA					
			//GL_ONE_MINUS_DST_ALPHA			
			//GL_CONSTANT_COLOR				
			//GL_ONE_MINUS_CONSTANT_COLOR		
			//GL_CONSTANT_ALPHA				
			//GL_ONE_MINUS_CONSTANT_ALPHA
			//glEnable(GL_BLEND);
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			//or
			//glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
			uint colorBlendMode;
			uint cullFace;
			uint dephtTest;
			uint dephtWrite;
			uint shadingModel;

			ImGui::DragScalar("lineWidth", ImGuiDataType_U32, &mat->lineWidth, 0.2, NULL, 0, "%u");
			ImGui::DragScalar("polygonOffset", ImGuiDataType_U32, &mat->polygonOffset, 0.2, NULL, 0, "%u");

			ImGui::ColorEdit4("mColor1", (float*)&mat->mColor1); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mColor2", (float*)&mat->mColor2); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mColor3", (float*)&mat->mColor3); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mDifuse", (float*)&mat->mDifuse); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mAmbient", (float*)&mat->mAmbient); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mEmission", (float*)&mat->mEmission); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mTranslucenci", (float*)&mat->mTranslucenci); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mSadowsColor", (float*)&mat->mSadowsColor); // Edit 4 floats representing a color

			ImGui::ColorEdit4("mSpecular", (float*)&mat->mSpecular); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mReflex", (float*)&mat->mReflex); // Edit 4 floats representing a color
			ImGui::SliderFloat4("mShinines", (float*)&mat->mShinines, 0, 1000, "%.3f", ImGuiSliderFlags_Logarithmic); // Edit 4 floats representing a color

			std::string mName;
			std::string mFileName;
			std::string mShaderName;
			std::vector<std::string> mShaderNames;
			std::vector<Texture*> mTextures;	// textures objects
			shader* mShader;
			ImGui::TreePop();
		}

	}

	void show(camera* m) {
		if (ImGui::TreeNode("Camera")) {
			if (ImGui::TreeNode("Camera Properties")) {
				ImGui::SliderFloat("nearClip", (float*)&m->nearClip, -1, 10);
				ImGui::SliderFloat("farClip", (float*)&m->farClip, 1, 1000);
				ImGui::SliderFloat("left", (float*)&m->left, -10, 10);
				ImGui::SliderFloat("right", (float*)&m->right, -10, 10);
				ImGui::SliderFloat("botton", (float*)&m->botton, -10, 10);
				ImGui::SliderFloat("top", (float*)&m->top, -10, 10);
				ImGui::SliderFloat("fov", (float*)&m->fov, 0, 3);
				ImGui::SliderFloat("aspect", (float*)&m->aspect, -10, 10);
				ImGui::SliderFloat3("dir", (float*)&m->dir, -10, 10);
				ImGui::SliderFloat3("up", (float*)&m->up, -10, 10);

				ImGui::SliderFloat4("grot", (float*)&m->grot, -F_PI, F_PI);
				ImGui::SliderFloat3("gsize", (float*)&m->gsize, -10, 10);
				ImGui::SliderFloat3("gpos", (float*)&m->gpos, -10, 10);
				ImGui::TreePop();
			}
			if (ImGui::TreeNode("Camera Matrix")) {
				draw("Matrix V", m->matrix.V);
				//ImGui::Text("Matrix V");
				//ImGui::SliderFloat4("V[0][X]", (float*)&m->matrix.V[0], -F_PI, F_PI); // Edit 4 floats representing a color
				//ImGui::SliderFloat4("V[1][X]", (float*)&m->matrix.V[1], -F_PI, F_PI); // Edit 4 floats representing a color
				//ImGui::SliderFloat4("V[2][X]", (float*)&m->matrix.V[2], -F_PI, F_PI); // Edit 4 floats representing a color
				//ImGui::SliderFloat4("V[3][X]", (float*)&m->matrix.V[3], -F_PI, F_PI); // Edit 4 floats representing a color

				draw("Matrix P", m->matrix.P);
				//ImGui::Text("Matrix P");
				//ImGui::SliderFloat4("P[0][X]", (float*)&m->matrix.P[0], -F_PI, F_PI); // Edit 4 floats representing a color
				//ImGui::SliderFloat4("P[1][X]", (float*)&m->matrix.P[1], -F_PI, F_PI); // Edit 4 floats representing a color
				//ImGui::SliderFloat4("P[2][X]", (float*)&m->matrix.P[2], -F_PI, F_PI); // Edit 4 floats representing a color
				//ImGui::SliderFloat4("P[3][X]", (float*)&m->matrix.P[3], -F_PI, F_PI); // Edit 4 floats representing a color
				ImGui::TreePop();
			}
			ImGui::TreePop();
		}

	}

	void show(matrix_block* m) {
		if (ImGui::TreeNode("matrix_block")) {
			draw("Matrix M", m->M);
			draw("Matrix V", m->V);
			draw("Matrix P", m->P);
			draw("Matrix MV", m->MV);
			draw("Matrix MVP", m->MVP);
			ImGui::TreePop();
		}

	}

	void show(malha* m) {

		ui::show(m->mMaterial->mData);

		ImGui::Text("Name: %s", m->name.c_str());
		ImGui::Text("renderMode: %i", m->renderMode);
		ImGui::Text("g_count: %i", m->g_count);
		ImGui::Text("count: %i", m->count);
		ImGui::Text("mIndex: %i", m->mIndex);

		//std::string fileName;

		ImGui::Text("nIndex: %i", m->nIndex);
		ImGui::Text("nVertex: %i", m->nVertex);
		ImGui::Text("VBO: %i", m->VBO);
		ImGui::Text("EBO: %i", m->EBO);
		ImGui::Text("VAO: %i", m->VAO);

		GLuint pBuffers[10] = { 0,0,0,0,0,0,0,0,0,0 }; // buffers used for vertex, normal, uv, color and others (tangent, bitangent, ...)

		std::vector<usvec3> pIndex;
		std::vector<usvec2> pIndex2;
		std::vector<vertex> pVertex; // standard vertex, more commom use
		// standard atributes separated
		std::vector<vec3> pPosition;
		std::vector<vec3> pNormal;
		std::vector<vec3> pTangent;
		std::vector<vec3> pBiTangent;
		std::vector<vec2> pUv;
		std::vector<vec4> pColor;
		// optional
		std::vector<vec2> pUv1;
		std::vector<vec2> pUv2;
		std::vector<vec4> pColor1;
		std::vector<vec4> pColor2;

	}

	void show(objetob* obj) {
		if (ImGui::TreeNode("ObjetoB")) {
			ui::show(&obj->matrix);
			if (ImGui::TreeNode("Bounding Box")) {
				static char cha[] = "bb 0";
				for (int i = 0; i < 8; i++) {
					cha[3] = '0' + i;
					ImGui::SliderFloat3(cha, (float*)&obj->bb[i], 0, 100, "%.4f");
				}
				ImGui::TreePop();
			}

			ImGui::Text("name: %s", obj->name.c_str());
			ImGui::Text("type: %i", &obj->type);
			ImGui::Text("g_count: %i", &obj->g_count);
			ImGui::Text("count: %i", &obj->count);
			ImGui::Text("mIndex: %i", &obj->mIndex);
			ImGui::Text("mIndex: %i", &obj->mIndex);

			ImGui::SliderFloat4("lrot", (float*)&obj->lrot, -F_PI, F_PI, "%.4f");
			ImGui::SliderFloat3("lsize", (float*)&obj->lsize, 0, 100, "%.4f");
			ImGui::SliderFloat3("lpos", (float*)&obj->lpos, -100, 100, "%.4f");

			ImGui::SliderFloat4("grot", (float*)&obj->grot, -F_PI, F_PI, "%.4f");
			ImGui::SliderFloat3("gsize", (float*)&obj->gsize, 0, 100, "%.4f");
			ImGui::SliderFloat3("gpos", (float*)&obj->gpos, -100, 100, "%.4f");

			ImGui::SliderFloat("raius", &obj->raius, 0, 100, "%.4f");

			ImGui::TreePop();
		}
	}

	void show(objeto* obj) {
		if (ImGui::CollapsingHeader("Objeto")) {
			if (ImGui::TreeNode("Malhas")) {
				for (int i = 0; i < obj->malhas.size(); i++) {
					static char cha[12] = "Malha 0";
					if (obj->malhas[i]) {
						sprintf(cha, "Malha %s %i", obj->malhas[i]->name.c_str(), i);
						if (ImGui::TreeNode(cha)) {
							ui::show(obj->malhas[i]);
							ImGui::TreePop();
						}
					}
				}
				ImGui::TreePop();
			}
			if (obj->child.size())
				if (ImGui::TreeNode("Child")) {
					for (int i = 0; i < obj->child.size(); i++) {
						ui::show(obj->child[i]);
					}
					ImGui::TreePop();
				}
			show((objetob*)obj);
		}
	}

	void showProfiler(float fps, float ms, int* vsync) {
		static float fpsValues[370] = {};
		static int fpsValues_offset = 0;
		static char fpsCounterOverlay[128];
		fpsValues_offset = word.frame % IM_ARRAYSIZE(fpsValues);
		fpsValues[fpsValues_offset] = ms;
		{
			float minimum = fpsValues[0];
			float average = 0.0f;
			float maximum = fpsValues[0];
			for (int n = 0; n < IM_ARRAYSIZE(fpsValues); n++) {
				minimum = min(fpsValues[n], minimum);
				average += fpsValues[n];
				maximum = max(fpsValues[n], maximum);
			}
			average /= (float)IM_ARRAYSIZE(fpsValues);
			// Plots can display overlay texts
			// (in this example, we will display an average value)
			sprintf(fpsCounterOverlay, "Min: %.3fms    Avg %.3fms    Max: %.3fms", minimum, average, maximum);
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::SetNextItemWidth(-21);
			ImGui::PlotLines("FPS", fpsValues, IM_ARRAYSIZE(fpsValues), fpsValues_offset + 1, fpsCounterOverlay, minimum, maximum, ImVec2(0, 80.0f));
		}
		ImGui::SliderInt("Vsync", vsync, 0, 5); HelpMarker("0 = Vsync disabled\n1 = vesync same monitor hate\n2 = half monitor hate");

	}

	static void ShowExampleMenuFile() {
		ImGui::MenuItem("(demo menu)", NULL, false, false);
		if (ImGui::MenuItem("New")) {
		}
		if (ImGui::MenuItem("Open", "Ctrl+O")) {
		}
		if (ImGui::BeginMenu("Open Recent")) {
			ImGui::MenuItem("fish_hat.c");
			ImGui::MenuItem("fish_hat.inl");
			ImGui::MenuItem("fish_hat.h");
			if (ImGui::BeginMenu("More..")) {
				ImGui::MenuItem("Hello");
				ImGui::MenuItem("Sailor");
				if (ImGui::BeginMenu("Recurse..")) {
					ui::ShowExampleMenuFile();
					ImGui::EndMenu();
				}
				ImGui::EndMenu();
			}
			ImGui::EndMenu();
		}
		if (ImGui::MenuItem("Save", "Ctrl+S")) {
		}
		if (ImGui::MenuItem("Save As..")) {
		}

		ImGui::Separator();
		if (ImGui::BeginMenu("Options")) {
			static bool enabled = true;
			ImGui::MenuItem("Enabled", "", &enabled);
			ImGui::BeginChild("child", ImVec2(0, 60), true);
			for (int i = 0; i < 10; i++)
				ImGui::Text("Scrolling Text %d", i);
			ImGui::EndChild();
			static float f = 0.5f;
			static int n = 0;
			ImGui::SliderFloat("Value", &f, 0.0f, 1.0f);
			ImGui::InputFloat("Input", &f, 0.1f);
			ImGui::Combo("Combo", &n, "Yes\0No\0Maybe\0\0");
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Colors")) {
			float sz = ImGui::GetTextLineHeight();
			for (int i = 0; i < ImGuiCol_COUNT; i++) {
				const char* name = ImGui::GetStyleColorName((ImGuiCol)i);
				ImVec2 p = ImGui::GetCursorScreenPos();
				ImGui::GetWindowDrawList()->AddRectFilled(p, ImVec2(p.x + sz, p.y + sz), ImGui::GetColorU32((ImGuiCol)i));
				ImGui::Dummy(ImVec2(sz, sz));
				ImGui::SameLine();
				ImGui::MenuItem(name);
			}
			ImGui::EndMenu();
		}

		// Here we demonstrate appending again to the "Options" menu (which we already created above)
		// Of course in this demo it is a little bit silly that this function calls BeginMenu("Options") twice.
		// In a real code-base using it would make senses to use this feature from very different code locations.
		if (ImGui::BeginMenu("Options")) // <-- Append!
		{
			static bool b = true;
			ImGui::Checkbox("SomeOption", &b);
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Disabled", false)) // Disabled
		{
			IM_ASSERT(0);
		}
		if (ImGui::MenuItem("Checked", NULL, true)) {
		}
		if (ImGui::MenuItem("Quit", "Alt+F4")) {
		}
	}

	static void ShowExampleAppMainMenuBar() {
		if (ImGui::BeginMainMenuBar()) {
			if (ImGui::BeginMenu("File")) {
				ui::ShowExampleMenuFile();
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit")) {
				if (ImGui::MenuItem("Undo", "CTRL+Z")) {
				}
				if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {
				}  // Disabled item
				ImGui::Separator();
				if (ImGui::MenuItem("Cut", "CTRL+X")) {
				}
				if (ImGui::MenuItem("Copy", "CTRL+C")) {
				}
				if (ImGui::MenuItem("Paste", "CTRL+V")) {
				}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}

}

// * main program function
int main(int argc, char* argv[]) {
	{
		glfwSetErrorCallback(glfw_error_callback);
		const char* glsl_version = "#version 130";

		initializeMainWindow();
		setCallbackFunctions();
		init();

		reshape(ctx.window, ctx.size.x, ctx.size.y);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(ctx.window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);
	}
	// Load Fonts
	// - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
	// - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
	// - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
	// - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
	// - Read 'docs/FONTS.md' for more instructions and details.
	// - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
	//io.Fonts->AddFontDefault();
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
	//ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
	//IM_ASSERT(font != NULL);

	// Our state
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	float ms = 0;
	float fps = 0;
	static int vsync = 0;
	static float testFloat = 0;
	static vec2  testVec2 = vec2(0);
	static vec3  testVec3 = vec3(0);
	static vec4  testVec4 = vec4(0);
	int textureType = 0;
	const char* textureTypeItems[] = { "Texture", "Cube map", "Spherical map", "Cilindrical map" };
	int filter = 0;
	const char* filterItems[] = { "Nearest", "Linear", "Smoothstep", "Cubic", "Bicubic" };
	static float f = 0.0f;
	static int counter = 0;
	// Main loop
	while (!glfwWindowShouldClose(ctx.window)) {
		t.setFrameEnd();
		ms = t.getFrameMS();
		t.setFrameStart();
		fps = 1000 / ms;// t.getMedianFPS(60);
		word.frame++;
		word.time += vec4(ms, ms / 10.f, ms / 100.f, ms / 1000.f);
		word.sintime = vec4(sin(word.time.x), sin(word.time.y), sin(word.time.z), sin(word.time.w));
		word.costime = vec4(cos(word.time.x), cos(word.time.y), cos(word.time.z), cos(word.time.w));
		sprintf(szTitle, "FPS: %2.2f - Test OpenGL 01", fps);
		glfwSetWindowTitle(ctx.window, szTitle);
		t.setTimer("getMedianFPS and print");

		glfwSwapInterval(vsync);
		glClearColor(clear_color.r, clear_color.g, clear_color.b, clear_color.a);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		t.setTimer("glfwPollEvents");
		ImGuiIO& io = ImGui::GetIO();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		t.setTimer("ImGui::NewFrame");
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);
		
		ui::ShowExampleAppMainMenuBar();

		ImGui::Begin("Perf");                          // Create a window called "Hello, world!" and append into it.
		ui::showProfiler(fps, ms, &vsync);
		ImGui::End();

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
		{
			static float nextWidth = -80;
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			//ImGui::Checkbox("Another Window", &show_another_window);
			//if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			//	counter++;
			//ImGui::SameLine();
			//ImGui::Text("counter = %d", counter);
			ImGui::SetNextItemWidth(nextWidth);
			ImGui::ColorEdit4("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			ImGui::SetNextItemWidth(nextWidth);
			ImGui::SliderFloat("Float", &testFloat, 0, 2); HelpMarker("Test float");
			ImGui::SetNextItemWidth(nextWidth);
			ImGui::SliderFloat2("Vec2", &testVec2.x, 0, 2); HelpMarker("Test vec2");
			ImGui::SetNextItemWidth(nextWidth);
			ImGui::SliderFloat3("vec3", &testVec3.x, 0, 2); HelpMarker("Test vec3");
			ImGui::SetNextItemWidth(nextWidth);
			ImGui::SliderFloat4("vec4", &testVec4.x, 0, 2); HelpMarker("Test vec4");
			ImGui::SetNextItemWidth(nextWidth);
			ImGui::ColorEdit4("Color 1", (float*)&testVec4); // Edit 4 floats representing a color

			ImGui::SetNextItemWidth(nextWidth);
			if (ImGui::BeginCombo("Type", textureTypeItems[textureType])) {
				for (int n = 0; n < IM_ARRAYSIZE(textureTypeItems); n++) {
					const bool is_selected = (textureType == n);
					if (ImGui::Selectable(textureTypeItems[n], is_selected))
						textureType = n;
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}
			HelpMarker("Texture type Test");

			ImGui::SetNextItemWidth(nextWidth);
			if (ImGui::BeginCombo("Filter", filterItems[filter])) {
				for (int n = 0; n < IM_ARRAYSIZE(filterItems); n++) {
					const bool is_selected = (filter == n);
					if (ImGui::Selectable(filterItems[n], is_selected))
						filter = n;
					// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}
			HelpMarker("Texture filter Test");

			ImGui::End();
		}
		ImGui::Begin("Materials");                          // Create a window called "Hello, world!" and append into it.
		ui::show(plane);
		ui::show(activecamera);
		ui::show(plane->malhas[0]->mMaterial->mData);
		ImGui::End();
		if (show_another_window) {
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}

		if (!io.WantCaptureKeyboard)
			processKeyPress(ctx.window);
		mainLoop();
		onRenderScene();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		//glFlush();
		glFinish();
		t.setTimer("glFinish");
		glfwSwapBuffers(ctx.window);
		t.setTimer("SwapBuffers");
		if (word.frame == 1000) {
			//__debugbreak();
		}
	}
	// Terminate GLFW
	glfwTerminate();
	// Exit program
	exit(EXIT_SUCCESS);
}

void initializeMainWindow() {
	ctx.size.x = 1165 /*+ 16*/;
	ctx.size.y = 695 /*+ 39*/;

	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_DEPTH_BITS, 16);
	glfwWindowHint(GLFW_REFRESH_RATE, 20);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_FALSE);

	//glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

	ctx.window = glfwCreateWindow(ctx.size.x, ctx.size.y, szTitle, NULL, NULL);
	if (!ctx.window) {
		fprintf(stderr, "Failed to open GLFW window\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetWindowPos(ctx.window, 200, 30);

	glfwMakeContextCurrent(ctx.window);
	LoadOGL();
	LoadWGL();
	glfwSetInputMode(ctx.window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
}

void setCallbackFunctions() {
	glfwSetFramebufferSizeCallback(ctx.window, reshape);
	glfwSetCursorPosCallback(ctx.window, onMouseMove);
	glfwSetKeyCallback(ctx.window, key);
	glfwSetScrollCallback(ctx.window, onMouseWhell);
	glfwGetFramebufferSize(ctx.window, &ctx.size.x, &ctx.size.y);
}

void init() {
	plane = new objeto(0, objType::objQuad, vec3(0, 0, 0), vec3(0, 0, M_PI_2), vec3(1), uivec3(50, 50, 10), "SphericalCubeMap");
	plane->atach();
	glDisable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glClearColor(0.2f, 0.2f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
}

void reshape(GLFWwindow* window, int x, int y) {
	activecamera->aspect = max(float(x), 1.0f) / max(float(y), 1.0f);
	//printf("aspect:%f\n", activecamera->aspect);
	ctx.size.x = x;
	ctx.size.y = y;
	glViewport(0, 0, x, y);
	onRenderScene();
	glfwSwapBuffers(ctx.window);
}

void onMouseWhell(GLFWwindow* window, double x, double y) {
	ImGuiIO& io = ImGui::GetIO();
	if (io.WantCaptureMouse)
		return;
	if (y > 0) {
		activecamera->fov -= 0.05f;
	}
	else if (y < 0) {
		activecamera->fov += 0.05f;
	}
	activecamera->calcMatrix();
}

void onMouseMove(GLFWwindow* window, double x, double y) {
	ImGuiIO& io = ImGui::GetIO();
	if (io.WantCaptureMouse)
		return;

	static float lastPosX = float(x);
	static float lastPosY = float(y);
	float mx = float(x) - lastPosX;
	float my = float(y) - lastPosY;
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		activecamera->gpos.z += (my) * 0.016f * (pow(activecamera->fov / F_PI, 2.f) + 0.0001f);
		activecamera->gpos.y -= (mx) * 0.016f * (pow(activecamera->fov / F_PI, 2.f) + 0.0001f);
	}
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS) {
		activecamera->fov -= (mx) * 0.002f + (my) * 0.002f;
	}
	lastPosX = float(x);
	lastPosY = float(y);
}

void processKeyPress(GLFWwindow* window) {
	bool keyCtrl = 0;
	bool keyRCtrl = 0;
	bool keyLCtrl = 0;

	bool keyShift = 0;
	bool keyRShift = 0;
	bool keyLShift = 0;

	bool keyAlt = 0;
	bool keyRAlt = 0;
	bool keyLAlt = 0;

	bool keyRSuper = 0;
	bool keyLSuper = 0;
	bool keySuper = 0;

	bool keyNumLock = 0;
	bool keyCapsLock = 0;

	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		keyRCtrl = 1;
	if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
		keyLCtrl = 1;
	if (keyRCtrl || keyLCtrl)
		keyCtrl = 1;

	if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
		keyRAlt = 1;
	if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS)
		keyLAlt = 1;
	if (keyRAlt || keyLAlt)
		keyAlt = 1;

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		keyRShift = 1;
	if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
		keyLShift = 1;
	if (keyRShift || keyLShift)
		keyShift = 1;

	if (glfwGetKey(window, GLFW_KEY_LEFT_SUPER) == GLFW_PRESS)
		keyRSuper = 1;
	if (glfwGetKey(window, GLFW_KEY_RIGHT_SUPER) == GLFW_PRESS)
		keyLSuper = 1;
	if (keyRSuper || keyLSuper)
		keySuper = 1;

	if (glfwGetKey(window, GLFW_KEY_NUM_LOCK) == GLFW_PRESS)
		keyNumLock = 1;

	if (glfwGetKey(window, GLFW_KEY_CAPS_LOCK) == GLFW_PRESS)
		keyCapsLock = 1;

	if (glfwGetKey(window, GLFW_KEY_DELETE) == GLFW_PRESS) {
		cls();
	}
	if (glfwGetKey(window, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS) {
		activecamera->fov -= 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_PRESS) {
		activecamera->fov += 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		activecamera->gpos.z -= 0.01f;
		//activecamera->rotate(vec3(0,0.05f,0));
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		activecamera->gpos.z += 0.01f;
		//activecamera->rotate(vec3(0, -0.05f, 0));
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		activecamera->gpos.y += 0.01f;
		//activecamera->rotate(vec3(0, 0, 0.05f));
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		activecamera->gpos.y -= 0.01f;
		//activecamera->rotate(vec3(0, 0, -0.05f));
	}
	activecamera->calcMatrix();
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
	}
#if 0
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		if (keyShift)
			activecamera->moveF(16 * 4);
		else if (keyCtrl)
			activecamera->moveF(16 / 4);
		else
			activecamera->moveF(16);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		if (keyShift)
			activecamera->moveB(16 * 4);
		else if (keyCtrl)
			activecamera->moveB(16 / 4);
		else
			activecamera->moveB(16);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		if (keyShift)
			activecamera->moveL(16 * 4);
		else if (keyCtrl)
			activecamera->moveL(16 / 4);
		else
			activecamera->moveL(16);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		if (keyShift)
			activecamera->moveR(16 * 4);
		else if (keyCtrl)
			activecamera->moveR(16 / 4);
		else
			activecamera->moveR(16);
	}
#endif
}

void key(GLFWwindow* window, int k, int s, int action, int mods) {
	ImGuiIO& io = ImGui::GetIO();
	if (io.WantCaptureKeyboard)
		return;

	if (action != GLFW_PRESS) return;

	switch (k) {
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GLFW_TRUE);
			break;
		case GLFW_KEY_SPACE:
		{
			word.refreshShaders();
			printf("Material Reloaded\n\n");
		}
		break;
		default:
			return;
	}
}

void onDropFiles(GLFWwindow* window, int numFiles, const char* files[]) {
	if (numFiles > 0) {

	}
}

void mainLoop() {}

void onRenderScene() {
	//activecamera->aspect = max(float(ctx.size.x), 1.0f) / max(float(ctx.size.y), 1.0f);
	activecamera->calcMatrix();
	plane->draw();
	t.setTimer("plane->draw");
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("time", word.time);
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("frame", word.frame);
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("sintime", word.sintime);
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("costime", word.costime);
}

void cls() {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	// Get the number of character cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// Fill the entire screen with blanks.
	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
									(TCHAR)' ',      // Character to write to the buffer
									dwConSize,       // Number of cells to write
									coordScreen,     // Coordinates of first cell
									&cCharsWritten)) // Receive number of characters written
	{
		return;
	}
	// Get the current text attribute.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}
	// Set the buffer's attributes accordingly.
	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
									csbi.wAttributes, // Character attributes to use
									dwConSize,        // Number of cells to set attribute
									coordScreen,      // Coordinates of first cell
									&cCharsWritten))  // Receive number of characters written
	{
		return;
	}
	// Put the cursor at its home coordinates.
	SetConsoleCursorPosition(hConsole, coordScreen);
}




