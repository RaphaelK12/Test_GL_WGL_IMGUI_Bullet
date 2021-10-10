#pragma once

class MaterialData :public ReferenceCounter{
public:

	MaterialData();
	//MaterialData(const MaterialData& m);
	~MaterialData();


	uint castShadows;
	uint receiveShadows;
	uint renderable;
	uint transparent;
	uint alphaBlendMode;
	uint colorBlendMode;
	uint cullFace;
	uint dephtTest;
	uint dephtWrite;
	uint shadingModel;
	uint lineWidth;

	vec2 polygonOffset;
	vec4 mColor1;			// color passed to program
	vec4 mColor2;			// color passed to program
	vec4 mColor3;			// color passed to program
	vec4 mDifuse;			// color passed to program
	vec4 mAmbient;			// color passed to program
	vec4 mEmission;			// color passed to program
	vec4 mTranslucenci;		// color passed to program
	vec4 mSadowsColor;		// color passed to program

	vec4 mSpecular;			// color passed to program
	vec4 mReflex;			// color passed to program
	vec4 mShinines;			// color passed to program

	std::string mName;							// name of material
	std::string mFileName;						// complete filename (directory) of file	
	std::string mShaderName;					// main shader name	
	std::vector<std::string> mShaderNames;		// detailed shaders names	
	std::vector<Texture*> mTextures;			// textures objects	
	shader* mShader;							// shader used by this material
};

struct uniformsBase {
	string name;
	inline uniformsBase() {};
	inline uniformsBase(const string& n) :name(n) {};
	virtual inline void setUniform(const shader* s) {};
};

template <class T>
struct uniforms : public uniformsBase {
	T value;
	inline uniforms(const string& n, const T& v) : uniformsBase(n), value(v) {};
	virtual inline void setUniform(const shader* s) {
		s->setUniform(name, value);
	}
};

class Material{
public:
	static vec4 time, deltatime, sintime, costime;
	static uint frame;

	Material(void);
	Material(string name);
	~Material(void);

	inline static void setTimes(vec4 t, vec4 dt, vec4 st, vec4 ct, uint fr) {
		time = t;
		deltatime = dt;
		sintime = st;
		costime = ct;
		frame = fr;
	}

	vector<subroutineUniform> uniformSubroutines;
	vector<uint> subroutinesIndexes;
	vector<uniformsBase*> shaderUniforms;

	int createShaderSubroutinesList();
	int createShaderUniformsList();
	void setShaderUniforms() const;
	void setShaderSubroutines() const;


	void setShaderVariables();

	int active(matrix_block* m);
	int reload();
	void setMatrix(matrix_block* m);
	MaterialData* getMaterial(string& name);
	MaterialData* loadMaterial(string& name);
	string searchMaterialFileName(string& filename) const;
	std::string mName;
	std::string mFileName;
	MaterialData* mData;
};

extern std::map<string, MaterialData*> g_material_list;

void from_json(const json& j, MaterialData& v);
void to_json(json& j, const MaterialData& p);




