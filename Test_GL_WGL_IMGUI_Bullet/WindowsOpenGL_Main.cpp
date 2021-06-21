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
Word word;
frameBuffer* fbo;
objeto* plane;
objeto* skyBox;
cTimer t;

GLuint hdrTextures[10];
texto* txt;
float theta = 0;
char limit = 1;

// program procedure

void initializeMainWindow();
void setCallbackFunctions();
void init();
void reshape(GLFWwindow* window, int x, int y);
void mainLoop();

// main render functions

void onRenderScene();
void onRenderScene2();

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
	if (ImGui::IsItemHovered()) {
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

// * main program function
int main(int argc, char* argv[]) {
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
	int vsync = 0;
	static float testFloat = 0;
	static vec2  testVec2 = vec2(0);
	static vec3  testVec3 = vec3(0);
	static vec4  testVec4 = vec4(0);
	int textureType = 0;
	const char* textureTypeItems[] = { "Texture", "Cubemap", "Spherical map", "Cilindrical map" };
	int filter = 0;
	const char* filterItems[] = { "Nearest", "Linear", "Smoothstep", "Cubic", "Bicubic" };
	static float f = 0.0f;
	static int counter = 0;
	static float fpsValues[100] = {};
	static int fpsValues_offset = 0;
	char fpsCounterOverlay[128];

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

		ImGui::Begin("Perf");                          // Create a window called "Hello, world!" and append into it.
		{
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
				ImGui::SetNextItemWidth(-40);
				ImGui::PlotLines("FPS", fpsValues, IM_ARRAYSIZE(fpsValues), fpsValues_offset + 1, fpsCounterOverlay, minimum, maximum, ImVec2(0, 80.0f));
			}
			ImGui::SliderInt("Vsync", &vsync, 0, 5); HelpMarker("0 = Vsync disabled\n1 = vesync same monitor hate\n2 = half monitor hate");
			ImGui::End();
		}


		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit4("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}

		// 3. Show another simple window.
		if (show_another_window)         {
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}
		// 
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
	//glfwSwapInterval(1);
}

void setCallbackFunctions() {
	glfwSetFramebufferSizeCallback(ctx.window, reshape);
	glfwSetCursorPosCallback(ctx.window, onMouseMove);
	glfwSetKeyCallback(ctx.window, key);
	glfwSetScrollCallback(ctx.window, onMouseWhell);
	glfwGetFramebufferSize(ctx.window, &ctx.size.x, &ctx.size.y);
}

void init() {
	fbo = new frameBuffer(1, uivec2(100, 60) * 10);
	vec3 pos(0, 4, 0);
	for (int i = 1; i < objType::objGrid; i++) {
		word.addObj(objType(i), rotateZDeg(pos, 45.f * (i - 1.f)), vec3(0, 0, 0), vec3(1), uivec3(40, 20, 10), "DiffSpecNormalDisp");
	}

	word.addObj(objType::objQuad, vec3(0, 0, -1.1), vec3(0), vec3(40), uivec3(60, 60, 10), "DiffSpecNormalDisp");
	word.addObj(objType::objSkyBox, vec3(0, 0, 0), vec3(0, 0, 0), vec3(4), uivec3(10, 10, 10), "SphericalCubeMap");
	word.addObj(objType::objAxis, vec3(1, 0, 0), vec3(0, 0, 0), vec3(1), uivec3(10, 10, 10), "lineVertexColor");
	word.addObj(objType::objCapsule, vec3(7, 0, 0), vec3(0, 0, 0), vec3(1), uivec3(100, 100, 10), "DiffSpecNormalDisp");
	word.addObj(objType::objGrid, vec3(0, 0, 0), vec3(0, 0, 0), vec3(2), uivec3(10, 10, 10), "lineVertexColor");
	word.addObj(objType::objAxis, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1), uivec3(10, 10, 10), "lineVertexColor");
	//skyBox = new objeto(0, objType::objSkyBox, vec3(0, 0, 0), vec3(0, 0, 0), vec3(4), uivec3(10, 10, 10), "SphericalCubeMap.mat");
	plane = new objeto(0, objType::objQuad, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1), uivec3(50, 50, 10), "screen");
	plane->atach();

	txt = new texto("abcdefghijklmnopqrstuvwxyz ,.;/\\[]{}´`=+-_()!¹²³£¢¬@#$%¨&*'\"+-*/asdasdkhj	bfksdhgfgh	diasghfh hgfhjksdghfhj \ndhgadesfghadshfshg\nfsdfsd	asd\ndfsdfdsgdsgsdg)");
	glEnable(GL_CULL_FACE);
	glDisable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	//glEnable(GL_MULTISAMPLE_ARB);
	//glDisable(GL_MULTISAMPLE_ARB);
	glClearColor(0.2f, 0.2f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

}

void reshape(GLFWwindow* window, int x, int y) {
	activecamera->aspect = max(float(x), 1.0f) / max(float(y), 1.0f);
	//printf("aspect:%f\n", activecamera->aspect);
	ctx.size.x = x;
	ctx.size.y = y;
	fbo->resize(uivec2(x, y)/**1.25f*/);
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
		activecamera->grot.y -= (my) * 0.016f * (pow(activecamera->fov / F_PI, 2.f) + 0.0001f);
		activecamera->grot.x += (mx) * 0.016f * (pow(activecamera->fov / F_PI, 2.f) + 0.0001f);
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
		activecamera->grot.y -= 0.05f;
		//activecamera->rotate(vec3(0,0.05f,0));
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		activecamera->grot.y += 0.05f;
		//activecamera->rotate(vec3(0, -0.05f, 0));
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		activecamera->grot.x += 0.05f;
		//activecamera->rotate(vec3(0, 0, 0.05f));
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		activecamera->grot.x -= 0.05f;
		//activecamera->rotate(vec3(0, 0, -0.05f));
	}
	activecamera->calcMatrix();
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
	}
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
			word.reloadMaterials();
			printf("Material Reloaded\n\n");
		}
		break;
		default:
			return;
	}
}

void mainLoop() {
}

void onRenderScene() {
	fbo->bind(t);
	glEnable(GL_DEPTH_TEST);

	//glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
	//glBindTexture(GL_TEXTURE_2D, hdrTextures[0]);
	//glLineWidth(1.f);

	//glLineWidth(1.0f);
	//glLineWidth(2.0f);
	glDepthFunc(GL_LEQUAL);
	t.setTimer("glDepthFunc");
	word.draw();
	//glDisable(GL_DEPTH_WRITEMASK);
	//glDepthMask(0);
	//skyBox->draw();
	//glEnable(GL_DEPTH_WRITEMASK);
	//glDepthMask(1);
	//glFlush();

	t.setTimer("word.draw()");
	fbo->unbind();
	glDisable(GL_DEPTH_TEST);
	activecamera->aspect = max(float(ctx.size.x), 1.0f) / max(float(ctx.size.y), 1.0f);
	activecamera->calcMatrix();
	glBindTexture(GL_TEXTURE_2D, fbo->textures[0]);
	//if (plane->malhas[0]->mMaterial->mData->mTextures[0]->mData)
	//	plane->malhas[0]->mMaterial->mData->mTextures[0]->mData->globj = fbo->textures[0];
	//else {
	//	plane->malhas[0]->mMaterial->mData->mTextures[0]->mData = new TextureData;
	//	plane->malhas[0]->mMaterial->mData->mTextures[0]->mData->globj = fbo->textures[0];
	//}
	plane->draw();
	t.setTimer("plane->draw");
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("time", word.time);
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("frame", word.frame);
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("sintime", word.sintime);
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("costime", word.costime);
}

void onRenderScene2() {
	glEnable(GL_MULTISAMPLE_ARB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(theta, 0.5f, -1.5f, 0.0f);
	//glBegin (GL_TRIANGLES);
	//	glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (0.0f, 1.0f, 1.0f);
	//	glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (0.87f, -0.5f, -0.5f);
	//	glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (-0.87f, -0.5f, -0.5f);
	//glEnd ();
	glPopMatrix();
	glDisable(GL_DEPTH_TEST);
	drawText("abcdefghijklmnopqrstuvwxyz\n", vec2(-1.f, 1.f), vec2(1.f, 1.f), vec4(1.f, 1.f, 1.f, 1.f), vec2(0.f, 0.f));
	glEnable(GL_DEPTH_TEST);

	theta -= 0.1f;
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