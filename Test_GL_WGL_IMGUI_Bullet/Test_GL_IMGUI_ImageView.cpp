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


template <typename T>
static T _bezier_interp(float t, T start, T control_1, T control_2, T end) {
	/* Formula from Wikipedia article on Bezier curves. */
	float omt = (1.0f - t);
	float omt2 = omt * omt;
	float omt3 = omt2 * omt;
	float t2 = t * t;
	float t3 = t2 * t;

	return start * omt3 + control_1 * omt2 * t * 3.0f + control_2 * omt * t2 * 3.0f + end * t3;
}





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
	void comboBox(const char* name, int& index, const char* itens[], int size) {
		index = clamp(index, 0, size);
		if (ImGui::BeginCombo(name, itens[index])) {
			for (int n = 0; n < size; n++) {
				const bool is_selected = (index == n);
				if (ImGui::Selectable(itens[n], is_selected))
					index = n;
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();
		}
	}

	void draw(const char* label, mat4& m) {
		if (ImGui::TreeNode(label)) {
			//ImGui::Text("Matrix %s", label);
			ImGui::DragFloat4("V[0][X]", (float*)&m[0], 0.001f, -F_PI, F_PI); // Edit 4 floats representing a color
			ImGui::DragFloat4("V[1][X]", (float*)&m[1], 0.001f, -F_PI, F_PI); // Edit 4 floats representing a color
			ImGui::DragFloat4("V[2][X]", (float*)&m[2], 0.001f, -F_PI, F_PI); // Edit 4 floats representing a color
			ImGui::DragFloat4("V[3][X]", (float*)&m[3], 0.001f, -F_PI, F_PI); // Edit 4 floats representing a color
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

	void show(TextureData* m, uint id) {
		static float nextWidth = -80;

		static int textureType = 0;
		static int filter = 0;
		static int magFilter = 0;
		static int minFilter = 0;
		static int textureWrapS = 0;
		static int textureWrapT = 0;
		static int textureWrapR = 0;

		{
			enum textureTypeEnum {
				ETexture,
				ECubeMap,
				ESphericalMap,
				ECilindricalMap
			};
			enum textureFilterEnum {
				Nearest,
				Linear,
				ESmoothstep,
				ECubic,
				EBicubic
			};
			enum textureWrapModesEnum {
				EREPEAT,
				EMIRRORED_REPEAT,
				ECLAMP_TO_EDGE,
				ECLAMP_TO_BORDER
			};
			enum textureFilterMinMagEnum {
				ENEAREST,
				ELINEAR,
				ENEAREST_MIPMAP_NEAREST,
				ELINEAR_MIPMAP_NEAREST,
				ENEAREST_MIPMAP_LINEAR,
				ELINEAR_MIPMAP_LINEAR
			};
		}



		static const char* textureTypeItems[] = { "Texture", "Cube map", "Spherical map", "Cilindrical map" };
		static const char* filterItems[] = { "Nearest", "Linear", "Smoothstep", "Cubic", "Bicubic" };
		static const char* textureWrapModes[] = { "GL_REPEAT","GL_MIRRORED_REPEAT" ,"GL_MIRROR_CLAMP_TO_EDGE", "GL_CLAMP_TO_EDGE"  ,"GL_CLAMP_TO_BORDER"};
		static const char* textureMagFilter[] = { "GL_NEAREST", "GL_LINEAR"};
		static const char* textureMinFilter[] = { "GL_NEAREST", "GL_LINEAR", "GL_NEAREST_MIPMAP_NEAREST", 
			"GL_LINEAR_MIPMAP_NEAREST", "GL_NEAREST_MIPMAP_LINEAR", "GL_LINEAR_MIPMAP_LINEAR" };

		m->wrap_s = clamp(m->wrap_s, 0, IM_ARRAYSIZE(textureWrapModes)-1);
		m->wrap_t = clamp(m->wrap_t, 0, IM_ARRAYSIZE(textureWrapModes)-1);
		m->wrap_r = clamp(m->wrap_r, 0, IM_ARRAYSIZE(textureWrapModes)-1);

		m->filter_min = clamp(m->filter_min, 0, IM_ARRAYSIZE(textureMinFilter)-1);
		m->filter_mag = clamp(m->filter_mag, 0, IM_ARRAYSIZE(textureMagFilter)-1);

		ImGui::Text("FileName: %s", m->mFileName.c_str());
		ImGui::Text("Name: %s", m->mName.c_str());

		ImGui::Text("globj: %i", m->globj);
		//ImGui::Text("res %i %u", m->res.x, m->res.y );
		//ImGui::Text("format %u", m->format);
		//ImGui::Text("dataType %u", m->dataType);

		ImGui::Text("filter_mag: %i", m->filter_mag);
		ImGui::Text("filter_min: %i", m->filter_min);
		ImGui::SetNextItemWidth(nextWidth);
		ui::comboBox("filter_mag", m->filter_mag, textureMagFilter, IM_ARRAYSIZE(textureMagFilter));
		ImGui::SetNextItemWidth(nextWidth);
		ui::comboBox("filter_min", m->filter_min, textureMinFilter, IM_ARRAYSIZE(textureMinFilter));

		ImGui::SetNextItemWidth(nextWidth);
		ui::comboBox("wrap_s", m->wrap_s, textureWrapModes, IM_ARRAYSIZE(textureWrapModes));
		ImGui::SetNextItemWidth(nextWidth);
		ui::comboBox("wrap_t", m->wrap_t, textureWrapModes, IM_ARRAYSIZE(textureWrapModes));
		ImGui::SetNextItemWidth(nextWidth);
		ui::comboBox("wrap_r", m->wrap_r, textureWrapModes, IM_ARRAYSIZE(textureWrapModes));

		ImGui::Text("wrap_s: %i", m->wrap_s);
		ImGui::Text("wrap_t: %i", m->wrap_t);
		ImGui::Text("wrap_r: %i", m->wrap_r);

		//if (ImGui::BeginCombo("filter_mag", textureMagFilter[magFilter])) {
		//	for (int n = 0; n < IM_ARRAYSIZE(textureMagFilter); n++) {
		//		const bool is_selected = (magFilter == n);
		//		if (ImGui::Selectable(textureMagFilter[n], is_selected))
		//			magFilter = n;
		//		if (is_selected)
		//			ImGui::SetItemDefaultFocus();
		//	}
		//	ImGui::EndCombo();
		//}

		//if (ImGui::BeginCombo("filter_min", textureMinFilter[minFilter])) {
		//	for (int n = 0; n < IM_ARRAYSIZE(textureMinFilter); n++) {
		//		const bool is_selected = (minFilter == n);
		//		if (ImGui::Selectable(textureMinFilter[n], is_selected))
		//			minFilter = n;
		//		if (is_selected)
		//			ImGui::SetItemDefaultFocus();
		//	}
		//	ImGui::EndCombo();
		//}
		
		//if (ImGui::BeginCombo("wrap_s", textureWrapModes[textureWrapS])) {
		//	for (int n = 0; n < IM_ARRAYSIZE(textureWrapModes); n++) {
		//		const bool is_selected = (textureWrapS == n);
		//		if (ImGui::Selectable(textureWrapModes[n], is_selected))
		//			textureWrapS = n;
		//		if (is_selected)
		//			ImGui::SetItemDefaultFocus();
		//	}
		//	ImGui::EndCombo();
		//}
		
		//ImGui::SetNextItemWidth(nextWidth);
		//if (ImGui::BeginCombo("wrap_t", textureWrapModes[textureWrapT])) {
		//	for (int n = 0; n < IM_ARRAYSIZE(textureWrapModes); n++) {
		//		const bool is_selected = (textureWrapT == n);
		//		if (ImGui::Selectable(textureWrapModes[n], is_selected))
		//			textureWrapT = n;
		//		if (is_selected)
		//			ImGui::SetItemDefaultFocus();
		//	}
		//	ImGui::EndCombo();
		//}
		
		//ImGui::SetNextItemWidth(nextWidth);
		//if (ImGui::BeginCombo("wrap_r", textureWrapModes[textureWrapR])) {
		//	for (int n = 0; n < IM_ARRAYSIZE(textureWrapModes); n++) {
		//		const bool is_selected = (textureWrapR == n);
		//		if (ImGui::Selectable(textureWrapModes[n], is_selected))
		//			textureWrapR = n;
		//		if (is_selected)
		//			ImGui::SetItemDefaultFocus();
		//	}
		//	ImGui::EndCombo();
		//}

		//switch (magFilter) {
		//	case 0:
		//		m->filter_mag = GL_NEAREST;
		//		break;
		//	case 1:
		//		m->filter_mag = GL_LINEAR;
		//		break;
		//	default:
		//		m->filter_mag = GL_NEAREST;
		//		break;
		//}
		//switch (minFilter) {
		//	case 0:
		//		m->filter_min = GL_NEAREST;
		//		break;
		//	case 1:
		//		m->filter_min = GL_LINEAR;
		//		break;
		//	case 2:
		//		m->filter_min = GL_NEAREST_MIPMAP_NEAREST;
		//		break;
		//	case 3:
		//		m->filter_min = GL_LINEAR_MIPMAP_NEAREST;
		//		break;
		//	case 4:
		//		m->filter_min = GL_NEAREST_MIPMAP_LINEAR;
		//		break;
		//	case 5:
		//		m->filter_min = GL_LINEAR_MIPMAP_LINEAR;
		//		break;
		//	default:
		//		m->filter_min = GL_NEAREST;
		//		break;
		//}		

		//if (ImGui::BeginCombo("Type", textureTypeItems[textureType])) {
		//	for (int n = 0; n < IM_ARRAYSIZE(textureTypeItems); n++) {
		//		const bool is_selected = (textureType == n);
		//		if (ImGui::Selectable(textureTypeItems[n], is_selected))
		//			textureType = n;
		//		if (is_selected)
		//			ImGui::SetItemDefaultFocus();
		//	}
		//	ImGui::EndCombo();
		//}
		
		//if (ImGui::BeginCombo("Filter", filterItems[filter])) {
		//	for (int n = 0; n < IM_ARRAYSIZE(filterItems); n++) {
		//		const bool is_selected = (filter == n);
		//		if (ImGui::Selectable(filterItems[n], is_selected))
		//			filter = n;
		//		// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
		//		if (is_selected)
		//			ImGui::SetItemDefaultFocus();
		//	}
		//	ImGui::EndCombo();
		//}

		ImGui::SetNextItemWidth(nextWidth);
		ui::comboBox("Type", textureType, textureTypeItems, IM_ARRAYSIZE(textureTypeItems));
		HelpMarker("Texture type Test");

		ImGui::SetNextItemWidth(nextWidth);
		ui::comboBox("Filter", filter, filterItems, IM_ARRAYSIZE(filterItems));
		HelpMarker("Texture filter Test");

	}

	void show(Texture* m, uint id) {
		char c[150] = "Texture";
		sprintf(c, "%s#%i", m->mName.c_str(), id);
		if (m) {
			if (ImGui::TreeNode(c)) {
				//ImGui::Text("Name %s", mat->mName.c_str());
				ImGui::Text("FileName: %s", m->mFileName.c_str());
				ui::show(m->mData, 0);
				ImGui::TreePop();
			}
		}
	}

	void show(MaterialData* m, uint id) {
		if (!m)
			return;
		char c[150] = "Material";
		sprintf(c, "Data: %s#%i", m->mName.c_str(), id);
		if (ImGui::TreeNode(c)) {
			ImGui::Text("Name: %s", m->mName.c_str());
			ImGui::Text("FileName: %s", m->mFileName.c_str());
#if(USE_SHADER_LIST)
			if (ImGui::TreeNode("Shader subroutines")) {
				auto& subs = m->mShader->uniformSubroutines;
				auto& indexes = m->mShader->subroutinesIndexes;
				for (int i = 0; i < subs.size(); ++i) {
					ImGui::SetNextItemWidth(-100);
					if (ImGui::BeginCombo(subs[i].name.c_str(), subs[i].subroutines[subs[i].active].name.c_str())) {
						for (int j = 0; j < subs[i].subroutines.size(); ++j) {
							const bool is_selected = (subs[i].active == j);
							if (ImGui::Selectable(subs[i].subroutines[j].name.c_str(), is_selected)) {
								subs[i].active = j;
								indexes[i] = subs[i].subroutines[subs[i].active].index;
							}
							if (is_selected)
								ImGui::SetItemDefaultFocus();
						}
						ImGui::EndCombo();
					}
				}
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("Uniforms")) {
				auto& v = m->mShader->shaderUniforms;
				for (int i = 0; i < v.size(); i++) {
					if(typeid(*v[i]) == typeid(values<float >))ImGui::DragFloat  (v[i]->name.c_str(),			(float*) &((values<float >*)(v[i]))->value, 0.001f, -10, 10.f, "%.4f");
					if(typeid(*v[i]) == typeid(values<vec2  >))ImGui::DragFloat2 (v[i]->name.c_str(),			(float*) &((values<vec2  >*)(v[i]))->value, 0.001f, -10, 10.f, "%.4f");
					if(typeid(*v[i]) == typeid(values<vec3  >))ImGui::DragFloat3 (v[i]->name.c_str(),			(float*) &((values<vec3  >*)(v[i]))->value, 0.001f, -10, 10.f, "%.4f");
					if(typeid(*v[i]) == typeid(values<vec4  >))ImGui::DragFloat4 (v[i]->name.c_str(),			(float*) &((values<vec4  >*)(v[i]))->value, 0.001f, -10, 10.f, "%.4f");
					if(typeid(*v[i]) == typeid(values<int   >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &((values<int   >*)(v[i]))->value, 1, 0.2f, NULL, 0, "%d");
					if(typeid(*v[i]) == typeid(values<ivec2 >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &((values<ivec2 >*)(v[i]))->value, 2, 0.2f, NULL, 0, "%d");
					if(typeid(*v[i]) == typeid(values<ivec3 >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &((values<ivec3 >*)(v[i]))->value, 3, 0.2f, NULL, 0, "%d");
					if(typeid(*v[i]) == typeid(values<ivec4 >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &((values<ivec4 >*)(v[i]))->value, 4, 0.2f, NULL, 0, "%d");
					if(typeid(*v[i]) == typeid(values<uint  >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &((values<uint  >*)(v[i]))->value, 1, 0.2f, NULL, 0, "%u");
					if(typeid(*v[i]) == typeid(values<uivec2>))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &((values<uivec2>*)(v[i]))->value, 2, 0.2f, NULL, 0, "%u");
					if(typeid(*v[i]) == typeid(values<uivec3>))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &((values<uivec3>*)(v[i]))->value, 3, 0.2f, NULL, 0, "%u");
					if(typeid(*v[i]) == typeid(values<uivec4>))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &((values<uivec4>*)(v[i]))->value, 4, 0.2f, NULL, 0, "%u");
				};
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragFloat  (v[i]->name.c_str(),			(float*)&v.float1[i].value, 0.001f, -10, 10.f, "%.4f");	}
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragFloat2 (v[i]->name.c_str(),			(float*)&v.float2[i].value, 0.001f, -10, 10.f, "%.4f");	}
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragFloat3 (v[i]->name.c_str(),			(float*)&v.float3[i].value, 0.001f, -10, 10.f, "%.4f");	}
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragFloat4 (v[i]->name.c_str(),			(float*)&v.float4[i].value, 0.001f, -10, 10.f, "%.4f");	}															      
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &v. int1[i].value, 1, 0.2f, NULL, 0, "%d");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &v. int2[i].value, 2, 0.2f, NULL, 0, "%d");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &v. int3[i].value, 3, 0.2f, NULL, 0, "%d");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &v. int4[i].value, 4, 0.2f, NULL, 0, "%d");   }															      
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &v.uint1[i].value, 1, 0.2f, NULL, 0, "%u");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &v.uint2[i].value, 2, 0.2f, NULL, 0, "%u");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &v.uint3[i].value, 3, 0.2f, NULL, 0, "%u");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &v.uint4[i].value, 4, 0.2f, NULL, 0, "%u");   }
				ImGui::TreePop();
			}
#endif
			if (ImGui::TreeNode("Textures")) {
				for (int i = 0; i < m->mTextures.size(); i++) {
					ui::show(m->mTextures[i], i);
				}
				ImGui::TreePop();
			}
			ImGui::Checkbox("castShadows", (bool*)&m->castShadows);
			ImGui::Checkbox("receiveShadows", (bool*)&m->receiveShadows);
			ImGui::Checkbox("renderable", (bool*)&m->renderable);
			ImGui::Checkbox("transparent", (bool*)&m->transparent);

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
			uint faceHorientation;

			ImGui::Checkbox("dephtWrite", (bool*)&m->dephtWrite);

			ImGui::DragScalar("lineWidth", ImGuiDataType_U32, &m->lineWidth, 0.2f, NULL, 0, "%u");
			ImGui::DragFloat2("polygonOffset", (float*)&m->polygonOffset, 0.001f, -1, 1.f, "%.4f", ImGuiSliderFlags_Logarithmic);

			ImGui::ColorEdit4("mColor1", (float*)&m->mColor1); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mColor2", (float*)&m->mColor2); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mColor3", (float*)&m->mColor3); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mDifuse", (float*)&m->mDifuse); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mAmbient", (float*)&m->mAmbient); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mEmission", (float*)&m->mEmission); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mTranslucenci", (float*)&m->mTranslucenci); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mSadowsColor", (float*)&m->mSadowsColor); // Edit 4 floats representing a color

			ImGui::ColorEdit4("mSpecular", (float*)&m->mSpecular); // Edit 4 floats representing a color
			ImGui::ColorEdit4("mReflex", (float*)&m->mReflex); // Edit 4 floats representing a color
			ImGui::DragFloat4("mShinines", (float*)&m->mShinines, 1.f, 0, 1000, "%.3f", ImGuiSliderFlags_Logarithmic); // Edit 4 floats representing a color

			ImGui::Text("ShaderName: %s", m->mShaderName.c_str());
			for (int i = 0; i < m->mShaderNames.size(); i++) {
				ImGui::Text("ShaderNames: %s", m->mShaderNames[i].c_str());
			}

			ImGui::Text(     "Time: %.4fm %.3fs %.2f %.1fms", Material::time.x,      Material::time.y,      Material::time.z,      Material::time.w     );
			ImGui::Text("DeltaTime: %.4fm %.3fs %.2f %.1fms", Material::deltatime.x, Material::deltatime.y, Material::deltatime.z, Material::deltatime.w);
			ImGui::Text( "Sin Time: %.4f %.3f %.2f %.1f",     Material::sintime.x,	 Material::sintime.y,   Material::sintime.z,   Material::sintime.w  );
			ImGui::Text( "Cos Time: %.4f %.3f %.2f %.1f",     Material::costime.x,	 Material::costime.y,   Material::costime.z,   Material::costime.w  );
			ImGui::Text( "Frame: %i", Material::frame);

			ImGui::TreePop();
		}
	}

	void show(Material* m, uint id) {
		if (!m)
			return;
		char c[150] = "Material";
		sprintf(c, "Material %s#%i", m->mName.c_str(), id);
#if(!USE_SHADER_LIST)
		if (ImGui::TreeNode(c)) {
			ImGui::Text("Name: %s", m->mName.c_str());
			ImGui::Text("FileName: %s", m->mFileName.c_str());
			if (ImGui::TreeNode("Shader subroutines")) {
				auto& subs = m->uniformSubroutines;
				auto& indexes = m->subroutinesIndexes;
				for (int i = 0; i < subs.size(); ++i) {
					ImGui::SetNextItemWidth(-100);
					if (ImGui::BeginCombo(subs[i].name.c_str(), subs[i].subroutines[subs[i].active].name.c_str())) {
						for (int j = 0; j < subs[i].subroutines.size(); ++j) {
							const bool is_selected = (subs[i].active == j);
							if (ImGui::Selectable(subs[i].subroutines[j].name.c_str(), is_selected)) {
								subs[i].active = j;
								indexes[i] = subs[i].subroutines[subs[i].active].index;
							}
							if (is_selected)
								ImGui::SetItemDefaultFocus();
						}
						ImGui::EndCombo();
					}
				}
				ImGui::TreePop();
			}
			if (ImGui::TreeNode("Uniforms")) {
				auto& v = m->shaderUniforms;
				for (int i = 0; i < v.size(); i++) {
					if(typeid(*v[i]) == typeid(uniforms<float >))ImGui::DragFloat  (v[i]->name.c_str(),			  (float*) &((uniforms<float >*)(v[i]))->value, 0.001f, -10, 10.f, "%.4f");
					if(typeid(*v[i]) == typeid(uniforms<vec2  >))ImGui::DragFloat2 (v[i]->name.c_str(),			  (float*) &((uniforms<vec2  >*)(v[i]))->value, 0.001f, -10, 10.f, "%.4f");
					if(typeid(*v[i]) == typeid(uniforms<vec3  >))ImGui::DragFloat3 (v[i]->name.c_str(),			  (float*) &((uniforms<vec3  >*)(v[i]))->value, 0.001f, -10, 10.f, "%.4f");
					if(typeid(*v[i]) == typeid(uniforms<vec4  >))ImGui::DragFloat4 (v[i]->name.c_str(),			  (float*) &((uniforms<vec4  >*)(v[i]))->value, 0.001f, -10, 10.f, "%.4f");
					if(typeid(*v[i]) == typeid(uniforms<int   >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &((uniforms<int   >*)(v[i]))->value, 1, 0.2f, NULL, 0, "%d");
					if(typeid(*v[i]) == typeid(uniforms<ivec2 >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &((uniforms<ivec2 >*)(v[i]))->value, 2, 0.2f, NULL, 0, "%d");
					if(typeid(*v[i]) == typeid(uniforms<ivec3 >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &((uniforms<ivec3 >*)(v[i]))->value, 3, 0.2f, NULL, 0, "%d");
					if(typeid(*v[i]) == typeid(uniforms<ivec4 >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &((uniforms<ivec4 >*)(v[i]))->value, 4, 0.2f, NULL, 0, "%d");
					if(typeid(*v[i]) == typeid(uniforms<uint  >))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &((uniforms<uint  >*)(v[i]))->value, 1, 0.2f, NULL, 0, "%u");
					if(typeid(*v[i]) == typeid(uniforms<uivec2>))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &((uniforms<uivec2>*)(v[i]))->value, 2, 0.2f, NULL, 0, "%u");
					if(typeid(*v[i]) == typeid(uniforms<uivec3>))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &((uniforms<uivec3>*)(v[i]))->value, 3, 0.2f, NULL, 0, "%u");
					if(typeid(*v[i]) == typeid(uniforms<uivec4>))ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &((uniforms<uivec4>*)(v[i]))->value, 4, 0.2f, NULL, 0, "%u");
				};
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragFloat  (v[i]->name.c_str(),			(float*)&v.float1[i].value, 0.001f, -10, 10.f, "%.4f");	}
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragFloat2 (v[i]->name.c_str(),			(float*)&v.float2[i].value, 0.001f, -10, 10.f, "%.4f");	}
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragFloat3 (v[i]->name.c_str(),			(float*)&v.float3[i].value, 0.001f, -10, 10.f, "%.4f");	}
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragFloat4 (v[i]->name.c_str(),			(float*)&v.float4[i].value, 0.001f, -10, 10.f, "%.4f");	}															      
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &v. int1[i].value, 1, 0.2f, NULL, 0, "%d");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &v. int2[i].value, 2, 0.2f, NULL, 0, "%d");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &v. int3[i].value, 3, 0.2f, NULL, 0, "%d");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_S32, &v. int4[i].value, 4, 0.2f, NULL, 0, "%d");   }															      
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &v.uint1[i].value, 1, 0.2f, NULL, 0, "%u");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &v.uint2[i].value, 2, 0.2f, NULL, 0, "%u");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &v.uint3[i].value, 3, 0.2f, NULL, 0, "%u");   }
				//for (int i = 0; i < v.size(); i++)	{  ImGui::DragScalarN(v[i]->name.c_str(), ImGuiDataType_U32, &v.uint4[i].value, 4, 0.2f, NULL, 0, "%u");   }
				ImGui::TreePop();
			}
#endif
			if (m->mData)
				ui::show(m->mData, 0);
#if(!USE_SHADER_LIST)
			ImGui::TreePop();
		}
#endif
	}

	void show(objetob* m) {
		if (ImGui::TreeNode("ObjetoB")) {
			ui::show(&m->matrix);
			if (ImGui::TreeNode("Bounding Box")) {
				static char cha[] = "bb 0";
				for (int i = 0; i < 8; i++) {
					cha[3] = '0' + i;
					ImGui::DragFloat3(cha, (float*)&m->bb[i], 0.01f, -100, 100, "%.4f");
				}
				ImGui::TreePop();
			}

			ImGui::Text("name: %s", m->name.c_str());
			ImGui::Text("type: %i", &m->type);
			ImGui::Text("g_count: %i", &m->g_count);
			ImGui::Text("count: %i", &m->count);
			ImGui::Text("mIndex: %i", &m->mIndex);
			ImGui::Text("mIndex: %i", &m->mIndex);

			ImGui::DragFloat4("lrot", (float*)&m->lrot, 0.01f, -F_PI, F_PI, "%.4f");
			ImGui::DragFloat3("lsize", (float*)&m->lsize, 0.01f, 0, 100, "%.4f");
			ImGui::DragFloat3("lpos", (float*)&m->lpos, 0.01f, -100, 100, "%.4f");

			ImGui::DragFloat4("grot", (float*)&m->grot, 0.01f, -F_PI, F_PI, "%.4f");
			ImGui::DragFloat3("gsize", (float*)&m->gsize, 0.01f, 0, 100, "%.4f");
			ImGui::DragFloat3("gpos", (float*)&m->gpos, 0.01f, -100, 100, "%.4f");

			ImGui::DragFloat("raius", &m->raius, 0.01f, 0, 100, "%.4f");

			ImGui::TreePop();
		}
	}

	void show(camera* m, uint id) {
		char c[150] = "Camera";
		sprintf(c, "Main Camera#%i", id);

		if (ImGui::TreeNode(c)) {
			if (ImGui::TreeNode("Camera Properties")) {
				ImGui::DragFloat("nearClip", (float*)&m->nearClip, 0.1f, -1, 10, "%.4f", ImGuiSliderFlags_Logarithmic);
				ImGui::DragFloat("farClip", (float*)&m->farClip, 100.f, 0, 100000, "%.4f", ImGuiSliderFlags_Logarithmic);
				ImGui::DragFloat("left", (float*)&m->left, 0.01f, -10, 10);
				ImGui::DragFloat("right", (float*)&m->right, 0.01f, -10, 10);
				ImGui::DragFloat("botton", (float*)&m->botton, 0.01f, -10, 10);
				ImGui::DragFloat("top", (float*)&m->top, 0.01f, -10, 10);
				ImGui::DragFloat("fov", (float*)&m->fov, 0.01f, 0, 3);
				ImGui::DragFloat("aspect", (float*)&m->aspect, 0.01f, -10, 10);
				ImGui::DragFloat3("dir", (float*)&m->dir, 0.01f, -10, 10);
				ImGui::DragFloat3("up", (float*)&m->up, 0.01f, -10, 10);
				ImGui::DragFloat4("grot", (float*)&m->grot, 0.001f, -F_PI, F_PI);
				ImGui::DragFloat3("gsize", (float*)&m->gsize, 0.001f, -10, 10);
				ImGui::DragFloat3("gpos", (float*)&m->gpos, 0.001f, -10, 10);
				ImGui::TreePop();
			}
			//show(m);
			if (ImGui::TreeNode("Camera Matrix")) {
				draw("Matrix V", m->matrix.V);
				draw("Matrix P", m->matrix.P);
				ImGui::TreePop();
			}
			ImGui::TreePop();
		}
	}

	void show(malha* m, uint id) {
		if (!m)
			return;
		char cha[150] = "Malha";
		sprintf(cha, "Malha: %s#%i", m->name.c_str(), id);
		if (ImGui::TreeNode(cha)) {
			ui::show(m->mMaterial, 0);

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

			{
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

			ImGui::TreePop();
		}
	}

	void show(objeto* m, uint id) {
		static char c[150] = "Objeto";
		sprintf(c, "Objeto : %s#%i", m->name.c_str(), id);
		if (ImGui::TreeNode(c)) {
			if (ImGui::TreeNode("Malhas")) {
				for (int i = 0; i < m->malhas.size(); i++) {
					static char cha[150] = "Malha";
					if (m->malhas[i]) {
						ui::show(m->malhas[i], i);
					}
				}
				ImGui::TreePop();
			}
			if (m->child.size()) {
				if (ImGui::TreeNode("Childs")) {
					for (uint i = 0; i < m->child.size(); i++) {
						if (m->child[i])
							ui::show(m->child[i], i);
					}
					ImGui::TreePop();
				}
			}
			ui::show((objetob*)m);
			ImGui::TreePop();
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
			ImGui::PlotLines("MS", fpsValues, IM_ARRAYSIZE(fpsValues), fpsValues_offset + 1, fpsCounterOverlay, 0, maximum, ImVec2(0, 180.0f));
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

	//int maxSub, maxSubU, activeS, countActiveSU;
	//char name[256]; int len, numCompS;
	//glGetIntegerv(GL_MAX_SUBROUTINES, &maxSub);
	//glGetIntegerv(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS, &maxSubU);
	//printf("Max Subroutines: %d  Max Subroutine Uniforms: %d\n", maxSub, maxSubU);

	// Main loop
	while (!glfwWindowShouldClose(ctx.window)) {
		t.setFrameEnd();
		ms = t.getFrameMS();
		t.setFrameStart();
		fps = 1000 / ms;// t.getMedianFPS(60);
		word.frame++;
		word.deltatime = vec4((ms / 1000.f) / 60, ms / 1000.f, ms / 100.f, ms);
		word.time += word.deltatime;
		word.sintime = vec4(sin(word.time.x), sin(word.time.y), sin(word.time.z), sin(word.time.w));
		word.costime = vec4(cos(word.time.x), cos(word.time.y), cos(word.time.z), cos(word.time.w));
		Material::setTimes(word.time, word.deltatime, word.sintime, word.costime, word.frame);

		sprintf(szTitle, "FPS: %2.2f - Test OpenGL 01", fps);
		glfwSetWindowTitle(ctx.window, szTitle);
		t.setTimer("getMedianFPS and print");

		glfwSwapInterval(vsync);
		glClearColor(clear_color.r, clear_color.g, clear_color.b, clear_color.a);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();
		t.setTimer("glfwPollEvents");
		ImGuiIO& io = ImGui::GetIO();
		// ui
		{
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			t.setTimer("ImGui::NewFrame");
			if (show_demo_window)
				ImGui::ShowDemoWindow(&show_demo_window);

			ui::ShowExampleAppMainMenuBar();

			ImGui::Begin("Perf");
			ui::showProfiler(fps, ms, &vsync);
			ImGui::End();

			if (0) {
				ImGui::Begin("Hello, world!");
				{
					static float nextWidth = -80;
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
			}
			ImGui::Begin("Properties");	{
				ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
				if (ImGui::CollapsingHeader("Objetos")) {
					ui::show(plane, 0);
				}
				if (ImGui::CollapsingHeader("Materiais")) {
					std::map<std::string, MaterialData*>::const_iterator it;
					uint i = 0;
					for (it = g_material_list.begin(); it != g_material_list.end(); it++) {
						if (it->second) {
							ui::show(it->second, i);
							i++;
						}
					}
				}
				if (ImGui::CollapsingHeader("Camera")) {
					ui::show(activecamera, 0);
				}
				if (ImGui::CollapsingHeader("Texturas")) {
					std::map<std::string, TextureData*>::const_iterator it;
					uint i = 0;
					for (it = g_texture_list.begin(); it != g_texture_list.end(); it++) {
						static char c[150];
						if (it->second) {
							sprintf(c, "%s#%i", it->second->mName.c_str(), i);
							i++;
							if (ImGui::TreeNode(c)) {
								ui::show(it->second, 0);
								ImGui::TreePop();
							}
						}
					}
				}
				ImGui::End();
			}
			if (show_another_window) {
				ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
				ImGui::Text("Hello from another window!");
				if (ImGui::Button("Close Me"))
					show_another_window = false;
				ImGui::End();
			}
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
	plane = new objeto(0, objType::objCapsule, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1), uivec3(50, 50, 10), "DiffSpecNormalDisp2");
	plane->atach();
	glDisable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glClearColor(0.2f, 0.2f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
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
	//plane->malhas[0]->mMaterial->mData->mShader->setUniform("time", word.time);
	//plane->malhas[0]->mMaterial->mData->mShader->setUniform("frame", word.frame);
	//plane->malhas[0]->mMaterial->mData->mShader->setUniform("sintime", word.sintime);
	//plane->malhas[0]->mMaterial->mData->mShader->setUniform("costime", word.costime);
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




