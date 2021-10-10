#pragma once
//#include "core+ext.h"
//#include "GLFunctions.h"

#define USE_SHADER_LIST (1)

using std::string;

//#define or ||
//#define not !
//#define and &&

extern const char defaultVS[];

extern const char defaultFS[];

//FILE *ShaderLOG;

/* class shader: wraper to opengl glsl to load, compile, link and use shader and program.
   usage:
    shader s;
	s.getExistentShaderFilenamesFromSingleName("myShaderFile");
	s.readSrcFromFilenames()
	s.generateShadersAndProgram(true)
	if(!s.use()){
		something goes wrong
	}

    shader s("myShaderFile");
	if(!s.use()){
		something goes wrong
	}

    shader s("myShaderFile.vs", "myShaderFile.fs");
	if(!s.use()){
		something goes wrong
	}

    shader s("myShaderFile.vs", "myShaderFile.fs", "myShaderFile.tc", "myShaderFile.te", "myShaderFile.gs");
	if(!s.use()){
		something goes wrong
	}

*/
enum class ShaderType {
	SHADER_FRAGMENT = 1,
	SHADER_VERTEX,
	SHADER_TESSELATIONC,
	SHADER_TESSELATIONE,
	SHADER_GEOMETRY,
	SHADER_COMPUTE,
	SHADER_PROGRAM,
};

struct subroutine {
	uint index;
	string name;
	inline ~subroutine() {};
	inline subroutine() : index(0) {};
	inline subroutine(const subroutine& v) {
		index = v.index;
		name = v.name;
	}
	inline subroutine& operator=(const subroutine& v) {
		index = v.index;
		name = v.name;
		return *this;
	}
};
struct subroutineUniform {
	GLuint active;
	string name;
	vector<subroutine> subroutines;
	inline subroutineUniform() 
		:active(0)
	{};
	inline subroutineUniform(const subroutineUniform& v) :
		name(v.name),
		active(v.active) 
	{
		subroutines.reserve(v.subroutines.size());
		for (int i = 0; i < v.subroutines.size(); ++i) {
			subroutines.push_back(v.subroutines[i]);
		}
	};
	inline ~subroutineUniform() {};
	inline subroutineUniform& operator=(const subroutineUniform& v) {
		name = v.name;
		active = v.active;
		for (int i = 0; i < v.subroutines.size(); ++i) {
			subroutines.push_back(v.subroutines[i]);
		}
		return *this;
	}
};

class shader;

struct valuesBase {
	string name;
	inline valuesBase() {};
	inline valuesBase(const string& n) :name(n) {};
	virtual inline void setUniform(const shader* s) {};
};

template <class T>
struct values: public valuesBase {
	T value;
	inline values(const string& n, const T& v) : valuesBase(n), value(v) {};
	virtual  void setUniform(const shader* s);
};

//class valures {
//public:
//	vector<values<float>> float1;
//	vector<values<vec2>> float2;
//	vector<values<vec3>> float3;
//	vector<values<vec4>> float4;
//
//	vector<values<int>> int1;
//	vector<values<ivec2>> int2;
//	vector<values<ivec3>> int3;
//	vector<values<ivec4>> int4;
//
//	vector<values<uint>> uint1;
//	vector<values<uivec2>> uint2;
//	vector<values<uivec3>> uint3;
//	vector<values<uivec4>> uint4;
//};

//char ___a[sizeof(valures)];
//char ___b[sizeof(values<vec4>)];
//char ___c[sizeof(vec4)];

// usage: 1) shader s(filename); /*search for filename+(.vs, .fs, .tcs, .tes, .gs or .cs) and generate a usable shader*/ s.use();
// 2) shader s(); s.setfilenames(vs, fs, tc, te, gs or cs); s.readSrcFromFilenames(); s.generateShadersAndProgram(); s.use();
// 3) shader s(); s.setSource(source, ShaderType); s.generateShadersAndProgram(); s.use();
// 4) shader s(); s.setSources(vertex, fragment ... or compute); s.generateShadersAndProgram(); s.use();
class shader{
public:
	static string defaultIncludeGeral;
	static string defaultIncludeVS;
	static string defaultIncludeFS;
	static uint g_count;	// total number of shaders actual in the program
	uint count;				// number of times the shader is used
	uint mIndex;			// index of this shader in global list of shaders

	uint program;			// gl program object (contain the compiled shaders).
	uint VShader;			// gl vertex shader object
	uint TCShader;			// gl tesselator control shader object
	uint TEShader;			// gl tesselator evaluator shader object
	uint GShader;			// gl geometri shader object
	uint FShader;			// gl fragment shader object
	uint CShader;			// gl fragment shader object

	uint shadersFilesExistent;
	uint shadersSourceLoaded;
	uint shadersObjLoaded;
	uint programUsable;

	string name;			// name of this shader
	string shadersName;		// name of shaders(without extension to load all .vs .tc .ts .te .gs .fs .cs

	string  VS;			// gl vertex shader name
	string  FS;			// gl fragment shader name
	string  TC;			// gl tesselator control shader name
	string  TE;			// gl tesselator evaluator shader name
	string  GS;			// gl geometri shader name
	string  CS;			// gl compute shader name

	string  VSsrc;		// gl vertex shader source
	string  TCsrc;		// gl tesselator control shader source
	string  TEsrc;		// gl tesselator evaluator shader source
	string  GSsrc;		// gl geometri shader source
	string  FSsrc;		// gl fragment shader source
	string  CSsrc;		// gl compute shader source

	vector<subroutineUniform> uniformSubroutines;
	vector<uint> subroutinesIndexes;

	vector<valuesBase*> shaderUniforms;

	// delete all shader stuff
	~shader(void);

    // generates empty shader to add files or source later
	shader(void);

	// create shader with single filename
	shader(const string &fileName);
	// create shader with single filename
    shader(const char* fileName);

	// create shader with specific shader filename 
	// vertex, fragment, tesselation control, tesselation evaluatin, geometric or compute
    shader(const char* vs, const char* fs, const char* tc=0, const char* te=0, const char* gs=0, const char* cs=0);

	// create shader with specifc shader filename 
	// vertex, fragment, tesselation control, tesselation evaluatin, geometric or compute
	shader(const string &vs, const string &fs, const string &tc=0, const string &te=0, const string &gs=0, const string &cs=0);

	// add a filename
	void shader2(const string& fileName);

	// link shader into another material
	shader* atach(void);

	// delink shader from material
	// if no more material using this sahder then delete this shader
	void detach(void);

	// search for a existent file with shaderName + extencions 
	// and add filenames found to shader (VS, FS, TC, TE and GS) or CS
	uint getExistentShaderFilenamesFromSingleName(const string & shaderName);

	// read shader source code from filenames (VS, FS, TC, TE and GS) or CS
	// and add source to (VSsrc, FSsrc, TCsrc, TEsrc, GSsrc) or CSsrc if no VS and FS
	uint readSrcFromFilenames();

	// read the default include files
	uint readIncludeFiles(BOOL reload = 0);

    // activate the shader
	int compile();

	// Set filename of each shader type
	void setFilenames(const string& vs, const string& fs, const string& tc = 0, const string& te = 0, const string& gs = 0, const string& cs = 0);

	// Set shader source code src = text source code, type = vertex, fragment, tesselation, ...
	int setSource(const string& src, const ShaderType type);

	// Set shader source code src = text source code, type = vertex, fragment, tesselation, ...
	int setSource(const char* src, const ShaderType type);

	// Set shader source code
	int setSources(const string& fs, const string& vs, const string& tc, const string& te, const string& gs, const string& cs);

	// Set shader source code
	int setSources(const char* fs, const char* vs, const char* tc, const char* te, const char* gs, const char* cs);

	// delete old shaders and program, create new program and shaders, 
	// compile shaders and link shader to program, print erros
	// return number of shaders compiled
	uint generateShadersAndProgram( int deleteShaderObjs = TRUE);

	// activate the shader glUseProgram, setUniforms and activeSubroutines
    uint use() const;

	// set active subroutines to shader
	void activeSubroutines() const;

	// set current Subroutines to shader
	void setUniforms() const;

	// delete compiled shaders
	void deleteShaders();

	// create a list of subroutines existent in shader source
	int createSubroutinesList();

	// create a list of uniforms existent in shader source
	int createUniformsList();

    // utility uniform functions
 #pragma region utility uniform functions

    void setUniform(const string &uname, const bool &val) const;
    void setUniform(const string &uname, const bvec2 &val) const;
    void setUniform(const string &uname, const bvec3 &val) const;
    void setUniform(const string &uname, const bvec4 &val) const;
    void setUniform(const string &uname, const int &val) const;
    void setUniform(const string &uname, const ivec2 &val) const;
    void setUniform(const string &uname, const ivec3 &val) const;
    void setUniform(const string &uname, const ivec4 &val) const;
    void setUniform(const string &uname, const uint &val) const;
    void setUniform(const string &uname, const uivec2 &val) const;
    void setUniform(const string &uname, const uivec3 &val) const;
    void setUniform(const string &uname, const uivec4 &val) const;
    void setUniform(const string &uname, const float &val) const;
    void setUniform(const string &uname, const vec2 &val) const;
    void setUniform(const string &uname, const vec3 &val) const;
    void setUniform(const string &uname, const vec4 &val) const;
    void setUniform(const string &uname, const double &val) const;
    void setUniform(const string &uname, const dvec2 &val) const;
    void setUniform(const string &uname, const dvec3 &val) const;
    void setUniform(const string &uname, const dvec4 &val) const;
    void setUniform(const string &uname, const mat2 &val) const;
    void setUniform(const string &uname, const mat3 &val) const;
    void setUniform(const string &uname, const mat4 &val) const;
    void setUniform(const string &uname, const dmat2 &val) const;
    void setUniform(const string &uname, const dmat3 &val) const;
    void setUniform(const string &uname, const dmat4 &val) const;

    void setUniform(const char *uname, const bool &val) const;
    void setUniform(const char *uname, const bvec2 &val) const;
    void setUniform(const char *uname, const bvec3 &val) const;
    void setUniform(const char *uname, const bvec4 &val) const;
    void setUniform(const char *uname, const int &val) const;
    void setUniform(const char *uname, const ivec2 &val) const;
    void setUniform(const char *uname, const ivec3 &val) const;
    void setUniform(const char *uname, const ivec4 &val) const;
    void setUniform(const char *uname, const uint &val) const;
    void setUniform(const char *uname, const uivec2 &val) const;
    void setUniform(const char *uname, const uivec3 &val) const;
    void setUniform(const char *uname, const uivec4 &val) const;
    void setUniform(const char *uname, const float &val) const;
    void setUniform(const char *uname, const vec2 &val) const;
    void setUniform(const char *uname, const vec3 &val) const;
    void setUniform(const char *uname, const vec4 &val) const;
    void setUniform(const char *uname, const double &val) const;
    void setUniform(const char *uname, const dvec2 &val) const;
    void setUniform(const char *uname, const dvec3 &val) const;
    void setUniform(const char *uname, const dvec4 &val) const;
    void setUniform(const char *uname, const mat2 &val) const;
    void setUniform(const char *uname, const mat3 &val) const;
    void setUniform(const char *uname, const mat4 &val) const;
    void setUniform(const char *uname, const dmat2 &val) const;
    void setUniform(const char *uname, const dmat3 &val) const;
    void setUniform(const char *uname, const dmat4 &val) const;
#pragma endregion

private:
    // utility function for checking shader compilation/linking errors.
    uint checkCompileErrors(GLuint shader, string type);

	// search a existent shader in predefined directories
	string searchShaderFileName(const string& filename) const;

	// read source file fron filename
	string readSource(const string& file) const;

	int reload();
};

//char ___a[sizeof(shader)];
//char ___a[sizeof(shader::uniformSubroutines)];
//char ___b[sizeof(shader::subroutinesIndexes)];
//char ___c[sizeof(shader::shaderUniforms)];
//char ___d[sizeof(string)];
//char ___e[sizeof(string)*14];
//char ___f[sizeof(uint)*12];

extern std::vector<shader*> g_shader_list;

