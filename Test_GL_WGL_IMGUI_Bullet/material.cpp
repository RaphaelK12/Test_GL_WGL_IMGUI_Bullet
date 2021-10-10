#include "pch.h"
#include "shader.h"
#include "texture.h"
#include "material.h"
#include "objetob.h"
#include "camera.h"

std::map<string, MaterialData*> g_material_list; // filename, material

vec4 Material::time = vec4(0);
vec4 Material::deltatime = vec4(0);
vec4 Material::sintime = vec4(0);
vec4 Material::costime = vec4(0);
uint Material::frame = 0;

MaterialData::MaterialData() :
	castShadows(1),
	receiveShadows(1),
	renderable(1),
	transparent(0),
	alphaBlendMode(0),
	colorBlendMode(0),
	cullFace(0),
	dephtTest(1),
	dephtWrite(1),
	shadingModel(1),
	lineWidth(1),

	polygonOffset(0),
	mColor1(1),			// color passed to program
	mColor2(1),			// color passed to program
	mColor3(1),			// color passed to program
	mDifuse(1),			// color passed to program
	mAmbient(0),			// color passed to program
	mEmission(0),			// color passed to program
	mTranslucenci(0),		// color passed to program
	mSadowsColor(0),		// color passed to program

	mSpecular(1),			// color passed to program
	mReflex(1),			// color passed to program
	mShinines(16),			// color passed to program

	mName("default"),
	mFileName(" "),
	mShaderName("default"),
	//mTextures({ "defaultDiff", "defaultSpec" , "defaultNor" , "defaultCube" }),	// textures objects
	mShader(0) 
{
}

//MaterialData::MaterialData(const MaterialData& m) {
//	castShadows = m.castShadows;
//	receiveShadows = m.receiveShadows;
//	renderable = m.renderable;
//	transparent = m.transparent;
//	alphaBlendMode = m.alphaBlendMode;
//	colorBlendMode = m.colorBlendMode;
//	cullFace = m.cullFace;
//	dephtTest = m.dephtTest;
//	dephtWrite = m.dephtWrite;
//	shadingModel = m.shadingModel;
//	lineWidth = m.lineWidth;
//
//	polygonOffset = m.polygonOffset;
//	mColor1 = m.mColor1;
//	mColor2 = m.mColor2;
//	mColor3 = m.mColor3;
//	mDifuse = m.mDifuse;
//	mAmbient = m.mAmbient;
//	mEmission = m.mEmission;
//	mTranslucenci = m.mTranslucenci;
//	mSadowsColor = m.mSadowsColor;
//
//	mSpecular = m.mSpecular;
//	mReflex = m.mReflex;
//	mShinines = m.mShinines;
//
//	mName = m.mName;
//	mFileName = m.mFileName;
//	mShaderName = m.mShaderName;
//	mShaderNames = m.mShaderNames;
//	mTextures = m.mTextures;
//	mShader = m.mShader;
//
//}
MaterialData::~MaterialData() {
	if (mShader)
		delete mShader;
	for (uint i = 0; i < mTextures.size(); i++) {
		if(mTextures[i])
			delete mTextures[i];
		 mTextures[i]=0;
	}
	if (mFileName.length() > 4)
		g_material_list.erase(mFileName);
}

Material::Material(void) :
	mData(0),
	mName("default"),
	mFileName("default.json")
{
}

Material::Material(string mname) : mData(0), mName(mname), mFileName(" ") {
	mFileName = searchMaterialFileName(mname);
	if (mFileName.length() < 5) {
		mname = "default";
	}
	mFileName = searchMaterialFileName(mname);
	mData = loadMaterial(mFileName);
	createShaderSubroutinesList();
	createShaderUniformsList();
}

Material::~Material(void)
{
	if (mData && mData->RemoveReference()) 	{
		delete mData;
		mData = 0;
	}
}

int Material::reload() {
	mFileName = searchMaterialFileName(mName);
	if (mFileName.length() > 4) {
		std::ifstream f;
		f.open(mFileName);
		if (f.is_open()) {
			json j = json::parse(f);
			if (!mData) {
				mData = new MaterialData;
			}
			from_json(j, *mData);
			//*mData = j;
			f.close();
			createShaderSubroutinesList();
			createShaderUniformsList();
			return 1;
		}
		else {
			printf("!f.is_open() %s", mName.c_str());
		}
	}
	else {
		printf("searchMaterialFileName(%s); failed", mName.c_str());
	}
	return 0;
	/*
	string file = filename;
	string fr = "Material";
	int i;
	if (file.size() >= 1) {
		FILE* f = fopen(filename.c_str(), "r");
		string s;
		if (!f) {
			file = filename + string(".mat");
			f = fopen(file.c_str(), "r");
		}
		if (!f)
			return 0;
		char* txt = new char[100];
		i = fscanf(f, "%s\n", txt);
		if (fr != txt) {
			fclose(f);
			delete[] txt;
			return 0;
		}
		i = fscanf(f, "i  type: 				%i\n", &type);
		i = fscanf(f, "i  filter_mag:			%i\n", &filter_mag);
		i = fscanf(f, "i  filter_min:			%i\n", &filter_min);
		i = fscanf(f, "i  wrap_s:			%i\n", &wrap_s);
		i = fscanf(f, "i  wrap_t:			%i\n", &wrap_t);
		i = fscanf(f, "i  wrap_r:			%i\n", &wrap_r);
		i = fscanf(f, "i  castShadows:			%i\n", &castShadows);
		i = fscanf(f, "i  receiveShadows:		%i\n", &receiveShadows);
		i = fscanf(f, "i  renderable:			%i\n", &renderable);
		i = fscanf(f, "i  transparent:			%i\n", &transparent);
		i = fscanf(f, "i  alphaBlendMode:		%i\n", &alphaBlendMode);
		i = fscanf(f, "i  colorBlendMode:		%i\n", &colorBlendMode);
		i = fscanf(f, "i  cullFace:				%i\n", &cullFace);
		i = fscanf(f, "i  dephtTest:			%i\n", &dephtTest);
		i = fscanf(f, "i  dephtWrite:			%i\n", &dephtWrite);
		i = fscanf(f, "i  shadingModel:			%i\n", &shadingModel);
		i = fscanf(f, "v2 polygonOffset:		%f %f\n", &polygonOffset.x, &polygonOffset.y);
		i = fscanf(f, "v4 color1:				%f %f %f %f\n", &mColor1.r, &mColor1.g, &mColor1.b, &mColor1.a);
		i = fscanf(f, "v4 color2:				%f %f %f %f\n", &mColor2.r, &mColor2.g, &mColor2.b, &mColor2.a);
		i = fscanf(f, "v4 color3:				%f %f %f %f\n", &mColor3.r, &mColor3.g, &mColor3.b, &mColor3.a);
		i = fscanf(f, "v4 diffuse:				%f %f %f %f\n", &mDifuse.r, &mDifuse.g, &mDifuse.b, &mDifuse.a);
		i = fscanf(f, "v4 ambient:				%f %f %f %f\n", &mAmbient.r, &mAmbient.g, &mAmbient.b, &mAmbient.a);
		i = fscanf(f, "v4 emission:				%f %f %f %f\n", &mEmission.r, &mEmission.g, &mEmission.b, &mEmission.a);
		i = fscanf(f, "v4 translucenci:			%f %f %f %f\n", &mTranslucenci.r, &mTranslucenci.g, &mTranslucenci.b, &mTranslucenci.a);
		i = fscanf(f, "v4 sadowsColor:			%f %f %f %f\n", &mSadowsColor.r, &mSadowsColor.g, &mSadowsColor.b, &mSadowsColor.a);
		i = fscanf(f, "v4 specular:				%f %f %f %f\n", &mSpecular.r, &mSpecular.g, &mSpecular.b, &mSpecular.a);
		i = fscanf(f, "v4 reflex:				%f %f %f %f\n", &mReflex.r, &mReflex.g, &mReflex.b, &mReflex.a);
		i = fscanf(f, "v4 shinines:				%f %f %f %f\n", &mShinines.r, &mShinines.g, &mShinines.b, &mShinines.a);
		i = fscanf(f, "s  name:					%s\n", txt);	mName = txt;
		i = fscanf(f, "s  fileName:				%s\n", txt);	mFileName = txt;
		i = fscanf(f, "s  shaderName:			%s\n", txt);	mShaderName = txt;

		i = fscanf(f, "s  textures:				%s ", txt);
		s = txt;
		texture* tx = 0;
		if (s.size() > 1) {
			texture* tx = new texture(s);
			tx->read();
			mTextures.push_back(tx);
		}
		for (int c = 0; c < 10; c++) {
			i = fscanf(f, "%s ", txt);
			s = txt;
			if (i > 0 && s.size() > 1) {
				tx = new texture(s);
				tx->read();
				mTextures.push_back(tx);
			}
			else
				break;
		}

		fclose(f);
		delete[] txt;

		if (mShader) {
			mShader->detach();
			mShader = new shader(mShaderName);
			mShader->atach();
		}
	}
	return 1;
	*/
}

void Material::setShaderVariables() {
	if (!mData)
		return;
	if (!mData->mShader)
		mData->mShader = new shader(mData->mShaderName);
	if (!mData->mShader)
		return;
	//mShader->setUniform("mt.color", mColor);
	//mShader->setInt("texture1", 0);
	mData->mShader->setUniform("mt.color1", mData->mColor1);
	mData->mShader->setUniform("mt.color2", mData->mColor2);
	mData->mShader->setUniform("mt.color3", mData->mColor3);
	mData->mShader->setUniform("mt.diffuse", mData->mDifuse);
	mData->mShader->setUniform("mt.ambient", mData->mAmbient);
	mData->mShader->setUniform("mt.emission", mData->mEmission);
	mData->mShader->setUniform("mt.translucenci", mData->mTranslucenci);
	mData->mShader->setUniform("mt.sadowsColor", mData->mSadowsColor);
	mData->mShader->setUniform("mt.specular", mData->mSpecular);
	mData->mShader->setUniform("mt.reflex", mData->mReflex);
	mData->mShader->setUniform("mt.shinines", mData->mShinines);

	mData->mShader->setUniform("time", time);
	mData->mShader->setUniform("frame", frame);
	mData->mShader->setUniform("sintime", sintime);
	mData->mShader->setUniform("costime", costime);


	for (int i = 0; uint(i) < mData->mTextures.size(); i++) {
		char txt[] = "texture1";
		glActiveTexture(GL_TEXTURE0+i); // activate the texture unit first before binding texture
		mData->mTextures[i]->bind();
		//mData->mTextures[i]->setTextureVariables();

		txt[7] = '1' + i;
		//glUniform1i(glGetUniformLocation(mShader->program, s.c_str()), i);
		mData->mShader->setUniform(txt, i);
	}
}

int Material::active(matrix_block* m) {
	if (!mData)
		return 0;
	if (!mData->mShader) {
		mData->mShader = new shader(mData->mShaderName);
		mData->mShader->atach();
	}
	mData->mShader->use();
#if(!USE_SHADER_LIST)
	setShaderUniforms();
	setShaderSubroutines();
#endif
	setShaderVariables();
	setMatrix(m);
	return 1;
}

void Material::setMatrix(matrix_block* m) {
	if (!mData ||!mData->mShader || !m)
		return;
	mData->mShader->setUniform("mt_model", m->M);						  //	uniform mat4 mt_model;
	mData->mShader->setUniform("mt_view", m->V);						  //	uniform mat4 mt_view;
	mData->mShader->setUniform("mt_projection", m->P);					  //	uniform mat4 mt_projection;
	mData->mShader->setUniform("mt_modelView", m->MV);					  //	uniform mat4 mt_modelView;
	mData->mShader->setUniform("mt_modelViewProjection", m->MVP);		  // 	uniform mat4 mt_modelViewProjection;
	mData->mShader->setUniform("viewPos", vec3(activecamera->gpos));		  // 	uniform mat4 mt_modelViewProjection;
}

string Material::searchMaterialFileName(string & filename) const {
	static const vector<string> dirs = {
		"",
		"../",
		"material/",
		"materials/",
		"../material/",
		"../materials/",
		"../../material/",
		"../../materials/",
		"../../../material/",
		"../../../materials/",
	};
	static const vector<string> exts = {
		"",
		".json",
		".material",
		".mat",
		".mtl",
	};
	FILE* f = 0;
	string fname = "";
	for (uint ext = 0; ext < exts.size(); ext++) {
		for (uint dir = 0; dir < dirs.size(); dir++) {
			fname = dirs[dir] + filename + exts[ext];
			f = fopen(fname.c_str(), "r");
			if (f) {
				fclose(f);
				return fname;
			}
		}
	}
	return "";
}

MaterialData* Material::getMaterial(string& name) {
	MaterialData* m =0;
	auto it = g_material_list.find(name);
	if (it != g_material_list.end()) {
		m = it->second;
	}
	return m;
}

MaterialData* Material::loadMaterial(string& name) {
	MaterialData* m = 0;
	m = getMaterial(name);
	if (m) {
		m->AddReference();
		createShaderSubroutinesList();
		createShaderUniformsList();
		return m;
	}
	m = new MaterialData;
	g_material_list.insert(std::pair<std::string, MaterialData*>(name,m));
	if (mFileName.length() > 4) {
		std::ifstream f;
		f.open(mFileName);
		if (f.is_open()) {
			json j = json::parse(f);
			from_json(j, *m);
			//*m = j;
		}
	}
	createShaderSubroutinesList();
	createShaderUniformsList();
	return m;
}

void from_json(const json& j, MaterialData& v) {
	if(j.find("castShadows"		) != j.end())	{j.at("castShadows"			  ).get_to(v.castShadows		);																																									}
	if(j.find("receiveShadows"	) != j.end())	{j.at("receiveShadows"		  ).get_to(v.receiveShadows		);																																									}
	if(j.find("renderable"		) != j.end())	{j.at("renderable"			  ).get_to(v.renderable			);																																									}
	if(j.find("transparent"		) != j.end())	{j.at("transparent"			  ).get_to(v.transparent		);																																									}
	if(j.find("alphaBlendMode"	) != j.end())	{j.at("alphaBlendMode"		  ).get_to(v.alphaBlendMode		);																																									}
	if(j.find("colorBlendMode"	) != j.end())	{j.at("colorBlendMode"		  ).get_to(v.colorBlendMode		);																																									}
	if(j.find("cullFace"		) != j.end())	{j.at("cullFace"			  ).get_to(v.cullFace			);																																									}
	if(j.find("dephtTest"		) != j.end())	{j.at("dephtTest"			  ).get_to(v.dephtTest			);																																									}
	if(j.find("dephtWrite"		) != j.end())	{j.at("dephtWrite"			  ).get_to(v.dephtWrite			);																																									}
	if(j.find("shadingModel"	) != j.end())	{j.at("shadingModel"		  ).get_to(v.shadingModel		);																																									}
	if(j.find("lineWidth"		) != j.end())	{j.at("lineWidth"			  ).get_to(v.lineWidth			);																																									}
	if(j.find("polygonOffset"	) != j.end())	{j.at("polygonOffset")		[0].get_to(v.polygonOffset	.x);j.at("polygonOffset")[1].get_to(v.polygonOffset .y);																												}
	if(j.find("color1"		 	) != j.end())	{j.at("color1")				[0].get_to(v.mColor1		.x);j.at("color1")		 [1].get_to(v.mColor1		.y);j.at("color1")		[2].get_to(v.mColor1		.z);j.at("color1")		[3].get_to(v.mColor1		.w);		}
	if(j.find("color2"		 	) != j.end())	{j.at("color2")				[0].get_to(v.mColor2		.x);j.at("color2")		 [1].get_to(v.mColor2		.y);j.at("color2")		[2].get_to(v.mColor2		.z);j.at("color2")		[3].get_to(v.mColor2		.w);		}
	if(j.find("color3"		 	) != j.end())	{j.at("color3")				[0].get_to(v.mColor3		.x);j.at("color3")		 [1].get_to(v.mColor3		.y);j.at("color3")		[2].get_to(v.mColor3		.z);j.at("color3")		[3].get_to(v.mColor3		.w);		}
	if(j.find("diffuse"			) != j.end()) 	{j.at("diffuse")			[0].get_to(v.mDifuse		.x);j.at("diffuse")		 [1].get_to(v.mDifuse		.y);j.at("diffuse")		[2].get_to(v.mDifuse		.z);j.at("diffuse")		[3].get_to(v.mDifuse		.w);		}
	if(j.find("ambient"			) != j.end()) 	{j.at("ambient")			[0].get_to(v.mAmbient		.x);j.at("ambient")		 [1].get_to(v.mAmbient		.y);j.at("ambient")		[2].get_to(v.mAmbient		.z);j.at("ambient")		[3].get_to(v.mAmbient		.w);		}
	if(j.find("emission"	 	) != j.end())	{j.at("emission")			[0].get_to(v.mEmission		.x);j.at("emission")	 [1].get_to(v.mEmission		.y);j.at("emission")	[2].get_to(v.mEmission		.z);j.at("emission")	[3].get_to(v.mEmission		.w);		}
	if(j.find("translucenci" 	) != j.end())	{j.at("translucenci")		[0].get_to(v.mTranslucenci	.x);j.at("translucenci") [1].get_to(v.mTranslucenci	.y);j.at("translucenci")[2].get_to(v.mTranslucenci	.z);j.at("translucenci")[3].get_to(v.mTranslucenci	.w);		}
	if(j.find("sadowsColor"		) != j.end()) 	{j.at("sadowsColor")		[0].get_to(v.mSadowsColor	.x);j.at("sadowsColor")	 [1].get_to(v.mSadowsColor	.y);j.at("sadowsColor")	[2].get_to(v.mSadowsColor	.z);j.at("sadowsColor")	[3].get_to(v.mSadowsColor	.w);		}
	if(j.find("specular"	 	) != j.end())	{j.at("specular")			[0].get_to(v.mSpecular		.x);j.at("specular")	 [1].get_to(v.mSpecular		.y);j.at("specular")	[2].get_to(v.mSpecular		.z);j.at("specular")	[3].get_to(v.mSpecular		.w);		}
	if(j.find("reflex"		 	) != j.end())	{j.at("reflex")				[0].get_to(v.mReflex		.x);j.at("reflex")		 [1].get_to(v.mReflex		.y);j.at("reflex")		[2].get_to(v.mReflex		.z);j.at("reflex")		[3].get_to(v.mReflex		.w);		}
	if(j.find("shinines"	 	) != j.end())	{j.at("shinines")			[0].get_to(v.mShinines		.x);j.at("shinines")	 [1].get_to(v.mShinines		.y);j.at("shinines")	[2].get_to(v.mShinines		.z);j.at("shinines")	[3].get_to(v.mShinines		.w);		}
	if(j.find("name"		 	) != j.end())	{j.at("name")				   .get_to(v.mName				);																																									}
	if(j.find("fileName"	 	) != j.end())	{j.at("fileName")			   .get_to(v.mFileName			);																																									}
	if(j.find("shaderName"	 	) != j.end())	{j.at("shaderName")			   .get_to(v.mShaderName		);																																									}
	
	if (v.mShader) {
		delete v.mShader;
		v.mShader = 0;
	}
	string vs, fs, tc, te, gs, cs;
	int cnt = 0;
	if (j.find("shaderList") != j.end()) {
		if (j["shaderList"].find("vs") != j["shaderList"].end())	{	j["shaderList"].at("vs").get_to(vs);	cnt++;	}
		if (j["shaderList"].find("fs") != j["shaderList"].end())	{	j["shaderList"].at("fs").get_to(fs);	cnt++;	}
		if (j["shaderList"].find("tc") != j["shaderList"].end())	{	j["shaderList"].at("tc").get_to(tc);	cnt++;	}
		if (j["shaderList"].find("te") != j["shaderList"].end())	{	j["shaderList"].at("te").get_to(te);	cnt++;	}
		if (j["shaderList"].find("gs") != j["shaderList"].end())	{	j["shaderList"].at("gs").get_to(gs);	cnt++;	}
		if (j["shaderList"].find("cs") != j["shaderList"].end())	{	j["shaderList"].at("cs").get_to(cs);	cnt++;	}
	}
	if (cnt) {
		v.mShader = new shader(vs, fs, tc, te, gs, cs);
		v.mShader->name = v.mShaderName;
		//v.mShader->readSrcFromFilenames();
		//v.mShader->generateShadersAndProgram();
	}
	else
		v.mShader = new shader(v.mShaderName);
	for (unsigned int i = 0; i < v.mTextures.size(); i++) {
		delete v.mTextures[i];
		v.mTextures[i] = 0;
	}
	v.mTextures.clear();
	v.mTextures.resize(0);
	if(j.find("textures")!= j.end())
	for (unsigned int i = 0; i < j["textures"].size(); i++) {
		v.mTextures.push_back(new Texture( j["textures"][i]));
	}
}

void to_json(json& j, const MaterialData& p) {
	j = json{
		{"castShadows" 		     , p.castShadows       },
		{"receiveShadows" 	     , p.receiveShadows    },
		{"renderable" 		     , p.renderable        },
		{"transparent" 		     , p.transparent       },
		{"alphaBlendMode" 	     , p.alphaBlendMode    },
		{"colorBlendMode" 	     , p.colorBlendMode    },
		{"cullFace" 		     , p.cullFace          },
		{"dephtTest" 		     , p.dephtTest         },
		{"dephtWrite" 		     , p.dephtWrite        },
		{"shadingModel" 	     , p.shadingModel      },
		{"lineWidth" 		     , p.lineWidth		   },
		{"polygonOffset" 	     , p.polygonOffset	   .x, p.polygonOffset	   .y												 },
		{"color1" 			     , p.mColor1           .x, p.mColor1           .y, p.mColor1           .x, p.mColor1           .w},
		{"color2" 			     , p.mColor2           .x, p.mColor2           .y, p.mColor2           .x, p.mColor2           .w},
		{"color3" 			     , p.mColor3           .x, p.mColor3           .y, p.mColor3           .x, p.mColor3           .w},
		{"diffuse" 			     , p.mDifuse           .x, p.mDifuse           .y, p.mDifuse           .x, p.mDifuse           .w},
		{"ambient" 			     , p.mAmbient          .x, p.mAmbient          .y, p.mAmbient          .x, p.mAmbient          .w},
		{"emission" 		     , p.mEmission         .x, p.mEmission         .y, p.mEmission         .x, p.mEmission         .w},
		{"translucenci" 	     , p.mTranslucenci     .x, p.mTranslucenci     .y, p.mTranslucenci     .x, p.mTranslucenci     .w},
		{"sadowsColor" 		     , p.mSadowsColor      .x, p.mSadowsColor      .y, p.mSadowsColor      .x, p.mSadowsColor      .w},
		{"specular" 		     , p.mSpecular         .x, p.mSpecular         .y, p.mSpecular         .x, p.mSpecular         .w},
		{"reflex" 			     , p.mReflex           .x, p.mReflex           .y, p.mReflex           .x, p.mReflex           .w},
		{"shinines" 		     , p.mShinines         .x, p.mShinines         .y, p.mShinines         .x, p.mShinines         .w},
		{"name" 			     , p.mName             },
		{"fileName" 		     , p.mFileName         },
		{"shaderName" 		     , p.mShaderName       }
	};
	for (unsigned int i = 0; i < p.mShaderNames.size(); i++) {
		j["shaderList"][i] = p.mShaderNames[i];
	}
	for (unsigned int i = 0; i < p.mTextures.size(); i++) {
		j["textures"][i] = *p.mTextures[i]->mData;
	}
}

int Material::createShaderSubroutinesList() {
#if(USE_SHADER_LIST)
	return 0;
#endif
	if (!mData || !mData->mShader || !mData->mShader->program)
		return 0;
	char name[256];
	int  countActiveSU;
	int len, numCompS, numSubs = 0;
	uint p = mData->mShader->program;
	// get number of uniform subroutines
	glGetProgramStageiv(p, GL_FRAGMENT_SHADER, GL_ACTIVE_SUBROUTINE_UNIFORMS, &countActiveSU);
	if (countActiveSU) {
		uniformSubroutines.resize(countActiveSU);
		subroutinesIndexes.resize(countActiveSU);
	}
	for (int i = 0; i < countActiveSU; ++i) {
		// get uniform subroutine name
		glGetActiveSubroutineUniformName(p, GL_FRAGMENT_SHADER, i, 256, &len, name);
		// number of subroutines in this uniform
		glGetActiveSubroutineUniformiv(p, GL_FRAGMENT_SHADER, i, GL_NUM_COMPATIBLE_SUBROUTINES, &numCompS);
		int* s = new int[numCompS];	// alocate the number of subroutines on this uniform
		uniformSubroutines[i].name = name;
		subroutinesIndexes[i] = 0;
		// get indexes of subroutines of this uniform subroutine
		glGetActiveSubroutineUniformiv(p, GL_FRAGMENT_SHADER, i, GL_COMPATIBLE_SUBROUTINES, s);
		if (numCompS)
			uniformSubroutines[i].subroutines.resize(numCompS);
		for (int j = 0; j < numCompS; ++j) {
			// get subroutine name 
			glGetActiveSubroutineName(p, GL_FRAGMENT_SHADER, s[j], 256, &len, name);
			uniformSubroutines[i].subroutines[j].index = s[j];
			uniformSubroutines[i].subroutines[j].name = name;
			numSubs++;
		}
		delete[]s;
	}
	return numSubs;
}
int Material::createShaderUniformsList() {
#if(USE_SHADER_LIST)
	return 0;
#endif
	if (!mData || !mData->mShader || !mData->mShader->program)
		return 0;
	char name[256];
	uint p = mData->mShader->program;
	
	GLint count;
	GLint size; // size of the variable
	GLenum type; // type of the variable (float, vec3 or mat4, etc)
	const GLsizei bufSize = 256; // maximum name length
	GLsizei len; // name length
	// get number of uniforms
	glGetProgramiv(p, GL_ACTIVE_UNIFORMS, &count);
	printf("Active Uniforms: %d\n", count);
	float	 float1;
	float2	 float2;
	float3	 float3;
	float4	 float4;
	int		 int1;
	int2	 int2;
	int3	 int3;
	int4	 int4;
	uint	 uint1;
	uint2	 uint2;
	uint3	 uint3;
	uint4	 uint4;
	for (int i = 0; i < shaderUniforms.size(); i++) {
		delete shaderUniforms[i];
		shaderUniforms[i] = 0;
	}
	shaderUniforms.clear();
	for (int i = 0; i < count; i++) {
		glGetActiveUniform(p, (GLuint)i, bufSize, &len, &size, &type, name);
		switch (type) {
			case GL_FLOAT:				glGetUniformfv (p, glGetUniformLocation(p, name), &float1);			shaderUniforms.push_back(new uniforms<float>(	name, float1));		break;
			case GL_FLOAT_VEC2:			glGetUniformfv (p, glGetUniformLocation(p, name), &float2.x);		shaderUniforms.push_back(new uniforms<vec2>(	name, float2));		break;
			case GL_FLOAT_VEC3:			glGetUniformfv (p, glGetUniformLocation(p, name), &float3.x);		shaderUniforms.push_back(new uniforms<vec3>(	name, float3));		break;
			case GL_FLOAT_VEC4:			glGetUniformfv (p, glGetUniformLocation(p, name), &float4.x);		shaderUniforms.push_back(new uniforms<vec4>(	name, float4));		break;
			case GL_INT:				glGetUniformiv (p, glGetUniformLocation(p, name), &int1);			shaderUniforms.push_back(new uniforms<int>(		name, int1));		break;
			case GL_INT_VEC2:			glGetUniformiv (p, glGetUniformLocation(p, name), &int2.x);			shaderUniforms.push_back(new uniforms<ivec2>(	name, int2));		break;
			case GL_INT_VEC3:			glGetUniformiv (p, glGetUniformLocation(p, name), &int3.x);			shaderUniforms.push_back(new uniforms<ivec3>(	name, int3));		break;
			case GL_INT_VEC4:			glGetUniformiv (p, glGetUniformLocation(p, name), &int4.x);			shaderUniforms.push_back(new uniforms<ivec4>(	name, int4));		break;
			case GL_UNSIGNED_INT:		glGetUniformuiv(p, glGetUniformLocation(p, name), &uint1);			shaderUniforms.push_back(new uniforms<uint>(	name, uint1));		break;
			case GL_UNSIGNED_INT_VEC2:	glGetUniformuiv(p, glGetUniformLocation(p, name), &uint2.x);		shaderUniforms.push_back(new uniforms<uivec2>(	name, uint2));		break;
			case GL_UNSIGNED_INT_VEC3:	glGetUniformuiv(p, glGetUniformLocation(p, name), &uint3.x);		shaderUniforms.push_back(new uniforms<uivec3>(	name, uint3));		break;
			case GL_UNSIGNED_INT_VEC4:	glGetUniformuiv(p, glGetUniformLocation(p, name), &uint4.x);		shaderUniforms.push_back(new uniforms<uivec4>(	name, uint4));		break;
			default:
				//printf("Uniform #%d, Type: %u, Name: %s\n", i, type, name);
				break;
		}
		switch (type) {
			case GL_BOOL:				printf("Uniform #%d, Type: GL_BOOL "  				", 0x%x Name: %s\n", i, type, name);         break;
			case GL_BOOL_VEC2:			printf("Uniform #%d, Type: GL_BOOL_VEC2 " 			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_BOOL_VEC3:			printf("Uniform #%d, Type: GL_BOOL_VEC3 " 			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_BOOL_VEC4:			printf("Uniform #%d, Type: GL_BOOL_VEC4 " 			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_INT:				printf("Uniform #%d, Type: INT "  					", 0x%x Name: %s\n", i, type, name);         break;
			case GL_INT_VEC2:			printf("Uniform #%d, Type: INT_VEC2 " 				", 0x%x Name: %s\n", i, type, name);         break;
			case GL_INT_VEC3:			printf("Uniform #%d, Type: INT_VEC3 " 				", 0x%x Name: %s\n", i, type, name);         break;
			case GL_INT_VEC4:			printf("Uniform #%d, Type: INT_VEC4 " 				", 0x%x Name: %s\n", i, type, name);         break;
			case GL_UNSIGNED_INT:		printf("Uniform #%d, Type: UNSIGNED_INT " 			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_UNSIGNED_INT_VEC2:	printf("Uniform #%d, Type: UNSIGNED_INT_VEC2 "		", 0x%x Name: %s\n", i, type, name);         break;
			case GL_UNSIGNED_INT_VEC3:	printf("Uniform #%d, Type: UNSIGNED_INT_VEC3 "		", 0x%x Name: %s\n", i, type, name);         break;
			case GL_UNSIGNED_INT_VEC4:	printf("Uniform #%d, Type: UNSIGNED_INT_VEC4 "		", 0x%x Name: %s\n", i, type, name);         break;
			case GL_FLOAT:				printf("Uniform #%d, Type: FLOAT "					", 0x%x Name: %s\n", i, type, name);         break;
			case GL_FLOAT_VEC2:			printf("Uniform #%d, Type: FLOAT_VEC2 "   			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_FLOAT_VEC3:			printf("Uniform #%d, Type: FLOAT_VEC3 "   			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_FLOAT_VEC4:			printf("Uniform #%d, Type: FLOAT_VEC4 "   			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_FLOAT_MAT2:			printf("Uniform #%d, Type: GL_FLOAT_MAT2 "			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_FLOAT_MAT3:			printf("Uniform #%d, Type: GL_FLOAT_MAT3 "			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_FLOAT_MAT4:			printf("Uniform #%d, Type: GL_FLOAT_MAT4 "			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_SAMPLER_1D:			printf("Uniform #%d, Type: GL_SAMPLER_1D "			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_SAMPLER_2D:			printf("Uniform #%d, Type: GL_SAMPLER_2D "			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_SAMPLER_3D:			printf("Uniform #%d, Type: GL_SAMPLER_3D "			", 0x%x Name: %s\n", i, type, name);         break;
			case GL_SAMPLER_CUBE:		printf("Uniform #%d, Type: GL_SAMPLER_CUBE "  		", 0x%x Name: %s\n", i, type, name);         break;
			case GL_SAMPLER_1D_SHADOW:	printf("Uniform #%d, Type: GL_SAMPLER_1D_SHADOW " 	", 0x%x Name: %s\n", i, type, name);         break;
			case GL_SAMPLER_2D_SHADOW:	printf("Uniform #%d, Type: GL_SAMPLER_2D_SHADOW " 	", 0x%x Name: %s\n", i, type, name);         break;
			default:
				printf("Uniform #%d, Type: 0x%u, Name: %s\n", i, type, name); break;
		}
	}	
	return count;
}
void Material::setShaderSubroutines() const {
#if(USE_SHADER_LIST)
	return ;
#endif
	if (subroutinesIndexes.size() > 0)
		glUniformSubroutinesuiv(GL_FRAGMENT_SHADER, (GLsizei)subroutinesIndexes.size(), &subroutinesIndexes[0]);
}
void Material::setShaderUniforms() const {
#if(USE_SHADER_LIST)
	return ;
#endif
	if (!mData || !mData->mShader || !mData->mShader->program)
		return;
	for (int i = 0; i < shaderUniforms.size(); i++) {
		shaderUniforms[i]->setUniform(mData->mShader);
	};
}







