#include "pch.h"
#include "shader.h"
#include "GLSLinclude.h"

std::vector<shader*> g_shader_list;

uint shader::g_count = 0;
string shader::defaultIncludeGeral = "";
string shader::defaultIncludeVS = "";
string shader::defaultIncludeFS = "";

/*
const char defaultVS[] = 
"#version 330 core\n"
"layout (location = 0) in vec4 Position;\n"
"out vec4 VertPosition;\n"
"void main(void){\n"
"	vec4 pos = ftransform()*vec4(0.5,0.5,0.5,0.5);//	vec4 pos = Position;\n"
"	VertPosition = pos;\n"
"	gl_Position = pos*vec4(0.5,0.5,0.5,0.5);\n"
"}\n"
;

const char defaultFS[] = 
"#version 330 core\n"
"layout (location = 0) out vec4 fragColor;\n"
//"layout (depth_unchanged) in float gl_FragDepth;\n"
"in vec4 VertPosition;\n"
"void main(void){\n"
"	fragColor = vec4(VertPosition*0.5+0.5);\n"
"}\n"
;

const char defaultFSmagenta[] = 
"#version 330 core\n"
"layout (location = 0) out vec4 fragColor;\n"
//"layout (depth_unchanged) in float gl_FragDepth;\n"
"in vec4 VertPosition;\n"
"void main(void){\n"
"	fragColor = vec4(1,0.2,1,1);\n"
"}\n"
;

*/

static const vector<string> dirs = {
	"",
	 "../",
		"shader/",
		"shaders/",
	 "../shader/",
	 "../shaders/",
  "../../shader/",
  "../../shaders/",
};

static const vector<string> exts = {
	"",
	".vs",
	".fs",
	".tc",
	".te",
	".gs",
	".cs"
};

shader::~shader(void){
	deleteShaders();
	if(program)
		glDeleteProgram(program);
	name.clear();
	shadersName.clear();
	VS.clear();
	TC.clear();
	TE.clear();
	GS.clear();
	FS.clear();
	VSsrc.clear();
	TCsrc.clear();
	TEsrc.clear();
	GSsrc.clear();
	FSsrc.clear();
	if (g_shader_list.size() >= mIndex)
		g_shader_list[mIndex] = 0;
	g_count--;
	for (int i = 0; i < shaderUniforms.size(); ++i) {
		delete shaderUniforms[i];
		shaderUniforms[i]=0;
	}
	//for (int i = 0; i < uniformSubroutines.size(); ++i) {
	//	delete uniformSubroutines[i];
	//	uniformSubroutines[i]=0;
	//}
}

shader::shader(void):
	count(0),
	program(0),
	VShader(0),	
	TCShader(0),	
	TEShader(0),	
	GShader(0),	
	FShader(0),	
	CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0)
{
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = (uint)g_shader_list.size() - 1;

	//shadersName = "default";
	//getExistentShaderFilenamesFromSingleName(shadersName);
	//readSrcFromFilenames();
	//shadersObjLoaded = generateShadersAndProgram(1);
}

shader::shader(const string &fileName):
	count(0),
	program(0),
	VShader(0),	
	TCShader(0),	
	TEShader(0),	
	GShader(0),	
	FShader(0),	
	//CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0)
{
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = (uint)g_shader_list.size() - 1;

	shadersName = fileName;
	if((shadersFilesExistent = getExistentShaderFilenamesFromSingleName(fileName))>1)
		if((shadersSourceLoaded = readSrcFromFilenames())>1)
			shadersObjLoaded = generateShadersAndProgram(1);
}

shader::shader(const char *fileName):
	count(0),
	program(0),
	VShader(0),	
	FShader(0),	
	TCShader(0),	
	TEShader(0),	
	GShader(0),	
	CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0)
{
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = (uint)g_shader_list.size() - 1;

	shadersName = fileName;
	if((shadersFilesExistent = getExistentShaderFilenamesFromSingleName(fileName))>1)
		if((shadersSourceLoaded = readSrcFromFilenames())>1)
			shadersObjLoaded = generateShadersAndProgram(1);
}

shader::shader(const char* vs, const char* fs, const char* tc, const char* te, const char* gs, const char* cs) :
	count(0),
	program(0),
	VShader(0),
	FShader(0),
	TCShader(0),
	TEShader(0),
	GShader(0),
	CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0) {
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = (uint)g_shader_list.size() - 1;
	uint cnt = 0;
	if (vs) {
		cnt++;		VS = vs;
	}
	if (fs) {
		cnt++; FS = fs;
	}
	if (tc) {
		cnt++; TC = tc;
	}
	if (te) {
		cnt++; TE = te;
	}
	if (gs) {
		cnt++; GS = gs;
	}
	if (cs) {
		if (cnt == 0) {
			cnt++; CS = cs;
		}
	}
	if ((shadersSourceLoaded = readSrcFromFilenames()))
		shadersObjLoaded = generateShadersAndProgram(1);
}

shader::shader(const string& vs, const string& fs, const string& tc, const string& te, const string& gs, const string& cs) :
	count(0),
	program(0),
	VShader(0),
	TCShader(0),
	TEShader(0),
	GShader(0),
	FShader(0),
	CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0) 
{
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = (uint)g_shader_list.size() - 1;

	VS = vs;
	FS = fs;
	TC = tc;
	TE = te;
	GS = gs;
	if (!VS.length() && !TC.length() && !TE.length() && !GS.length() && !FS.length())
		CS = cs;

	if ((shadersSourceLoaded = readSrcFromFilenames()) )
		shadersObjLoaded = generateShadersAndProgram(1);
}

void shader::setFilenames(const string& vs, const string& fs, const string& tc, const string& te, const string& gs, const string& cs){
	VS = vs;
	TC = tc;
	TE = te;
	GS = gs;
	FS = fs;
	CS = cs;
}

void shader::shader2(const string &fileName){
	return;
	readIncludeFiles();
	// 1. retrieve the vertex/fragment source code from filePath
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        // open files
		FILE *vs = 0;
		FILE *fs = 0;
		string filevs = fileName + ".vs";
		string filefs = fileName + ".fs";
		vs = fopen(filevs.c_str(), "r");
		if(!vs){
			std::cout << "::ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ::" << filevs << std::endl;
			return;
		};
		fs = fopen(filefs.c_str(), "r");
		if(!fs){
			fclose(vs);
			std::cout << "::ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ::" << filefs << std::endl;
			return;
		};
		fclose(vs);
		fclose(fs);
		vs = fs = 0;

        vShaderFile.open(filevs);
        fShaderFile.open(filefs);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();		
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        VSsrc = defaultIncludeGeral + defaultIncludeVS + vShaderStream.str();
        FSsrc = defaultIncludeGeral + defaultIncludeFS + fShaderStream.str();
    }
    catch (std::ifstream::failure e){
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ:" << fileName << std::endl;
		return;
    }

    const char* vShaderCode = VSsrc.c_str();
    const char* fShaderCode = FSsrc.c_str();
    // 2. compile shaders
    //unsigned int vertex, fragment;
    //int success;
    //char infoLog[512];
    // vertex shader
    VShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VShader, 1, &vShaderCode, NULL);
    glCompileShader(VShader);
    checkCompileErrors(VShader, "VERTEX");
    // fragment Shader
    FShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FShader, 1, &fShaderCode, NULL);
    glCompileShader(FShader);
    checkCompileErrors(FShader, "FRAGMENT");
    // shader Program
    program = glCreateProgram();
    glAttachShader(program, VShader);
    glAttachShader(program, FShader);
    glLinkProgram(program);
    if(!checkCompileErrors(program, "PROGRAM"))
		programUsable = 1;
    // delete the shaders as they're linked into our program now and no longer necessery
    glDeleteShader(VShader);
    glDeleteShader(FShader);
}

uint shader::getExistentShaderFilenamesFromSingleName(const string& shaderName) {
	readIncludeFiles();
	string fname = shaderName;
	size_t divisor = max(fname.find_last_of("/") , fname.find_last_of("\\"));
	size_t point = fname.find_last_of(".");
	if (point > divisor) {
		fname = fname.substr(0, point);
	}

	//char ext[] = ".ff";
	//ext[0] = fname[size - 3];
	//ext[1] = fname[size - 2];
	//ext[2] = fname[size - 1];

	//if (ext[0] == '.' &&
	//	(exts[1] == ext || exts[2] == ext || exts[3] == ext || exts[4] == ext || exts[5] == ext || exts[6] == ext)) 	{
	//	fname.resize(size - 3);
	//}

	FILE* f = NULL;
	uint cnt = 0;
	name = shaderName;
	shadersName = fname;
	string vs = name + ".vs"; VS = searchShaderFileName(vs);
	string fs = name + ".fs"; FS = searchShaderFileName(fs);
	string tc = name + ".tc"; TC = searchShaderFileName(tc);
	string te = name + ".te"; TE = searchShaderFileName(te);
	string gs = name + ".gs"; GS = searchShaderFileName(gs);
	string cs = name + ".cs"; CS = searchShaderFileName(cs);
	if (f = fopen(VS.c_str(), "r")) {
		cnt++;
		fclose(f);
	}
	if (f = fopen(FS.c_str(), "r")) {
		cnt++;
		fclose(f);
	}
	if (f = fopen(TC.c_str(), "r")) {
		cnt++;
		fclose(f);
	}
	if (f = fopen(TE.c_str(), "r")) {
		cnt++;
		fclose(f);
	}
	if (f = fopen(GS.c_str(), "r")) {
		cnt++;
		fclose(f);
	}
	if (cnt == 0) {
		if (f = fopen(cs.c_str(), "r")) {
			CS = cs;
			cnt++;
			fclose(f);
		}
	}
	return cnt;
}

uint shader::readIncludeFiles(BOOL reload) {
	uint cnt = 0;
	if (defaultIncludeFS.length() < 2 || reload) {
		defaultIncludeFS = readSource("defaultInclude.glsl.fs");
		if (!defaultIncludeFS.empty())
			cnt++;
	}
	if (defaultIncludeVS.length() < 2 || reload) {
		defaultIncludeVS = readSource("defaultInclude.glsl.vs");
		if (!defaultIncludeVS.empty())
			cnt++;
	}
	if (defaultIncludeGeral.length() < 2 || reload) {
		defaultIncludeGeral = readSource("defaultInclude.glsl");
		if (!defaultIncludeGeral.empty())
			cnt++;
	}
	return cnt;
}

uint shader::readSrcFromFilenames() {
	uint cnt = 0;
	readIncludeFiles();
	string src;
	if (VS.length() > 3) {
		src = readSource(VS);
		if (!src.empty()) {
			VSsrc = defaultIncludeGeral + defaultIncludeVS + src;
			cnt++;
		}
	}
	if (TC.length() > 3) {
		src = readSource(TC);
		if (!src.empty()) {
			TCsrc = defaultIncludeGeral + src;
			cnt++;
		}
	}
	if (TE.length() > 3) {
		src = readSource(TE);
		if (!src.empty()) {
			TEsrc = defaultIncludeGeral + src;
			cnt++;
		}
	}
	if (GS.length() > 3) {
		src = readSource(GS);
		if (!src.empty()) {
			GSsrc = defaultIncludeGeral + src;
			cnt++;
		}
	}
	if (FS.length() > 3) {
		src = readSource(FS);
		if (!src.empty()) {
			FSsrc = defaultIncludeGeral + defaultIncludeFS + src;
			cnt++;
		}
	}
	if (CS.length() > 3 && cnt == 0) {
		src = readSource(CS);
		if (!src.empty()) {
			CSsrc = defaultIncludeGeral + src;
			cnt++;
		}
	}
	return cnt;
}

int shader::compile() {
	if ((VSsrc.length() > 3 && FSsrc.length() > 3) /*|| CSsrc.size()>3*/) {
		shadersObjLoaded = generateShadersAndProgram(1);
		//return programUsable;
	} else {
		if ((VS.length() > 3 && FS.length() > 3) /*|| CS.size()>3*/) {
			if ((shadersSourceLoaded = readSrcFromFilenames()) > 1)
				shadersObjLoaded = generateShadersAndProgram(1);
			//return programUsable;
		} else {
			if (shadersName.length() > 3) {
				if ((shadersFilesExistent = getExistentShaderFilenamesFromSingleName(shadersName)) > 1)
					if ((shadersSourceLoaded = readSrcFromFilenames()) > 1)
						shadersObjLoaded = generateShadersAndProgram(1);
				//return programUsable;
			}
		}
	}

#if(USE_SHADER_LIST)
	createSubroutinesList();
	createUniformsList();
#endif
	return programUsable;
}

int shader::setSource(const string &src, const ShaderType type){
	readIncludeFiles();
	switch (type) {
	case ShaderType::SHADER_FRAGMENT:
			FSsrc = src;
			return 1;
		case ShaderType::SHADER_VERTEX:
			VSsrc = src;
			return 1;
		case ShaderType::SHADER_TESSELATIONC:
			TCsrc = src;
			return 1;
		case ShaderType::SHADER_TESSELATIONE:
			TEsrc = src;
			return 1;
		case ShaderType::SHADER_GEOMETRY:
			GSsrc = src;
			return 1;
		case ShaderType::SHADER_COMPUTE:
			CSsrc = src;
			return 1;
		default:
			return 0;
	}
	return 0;
}

int shader::setSource(const char *src, const ShaderType type){
	readIncludeFiles();
	switch(type){
		case ShaderType::SHADER_FRAGMENT:
			FSsrc = src;
			return 1;
		case ShaderType::SHADER_VERTEX:
			VSsrc = src;
			return 1;
		case ShaderType::SHADER_TESSELATIONC:
			TCsrc = src;
			return 1;
		case ShaderType::SHADER_TESSELATIONE:
			TEsrc = src;
			return 1;
		case ShaderType::SHADER_GEOMETRY:
			GSsrc = src;
			return 1;
		case ShaderType::SHADER_COMPUTE:
			CSsrc = src;
			return 1;
		default:
			return 0;
	}
	return 0;
}

int shader::setSources(const string& fs, const string& vs, const string& tc, const string& te, const string& gs, const string& cs) {
	//if(fs.length()>3)
		FSsrc = fs;
	//if (vs.length() > 3)
		VSsrc = vs;
	//if (tc.length() > 3)
		TCsrc = tc;
	//if (te.length() > 3)
		TEsrc = te;
	//if (gs.length() > 3)
		GSsrc = gs;
	//if (cs.length() > 3)
		CSsrc = cs;
	return 1;
}

int shader::setSources(const char* fs, const char* vs, const char* tc, const char* te, const char* gs, const char* cs) {
	//if (fs)
		FSsrc = fs;
	//if (vs)
		VSsrc = vs;
	//if (tc)
		TCsrc = tc;
	//if (te)
		TEsrc = te;
	//if (gs)
		GSsrc = gs;
	//if (cs)
		CSsrc = cs;
	return 1;
}

uint shader::generateShadersAndProgram( int deleteShaderObjs){
	glUseProgram(0);
	if (program)
		glDeleteProgram(program);

	deleteShaders();
	program = glCreateProgram();
	const char * str;
	uint cnt = 0;
	if(VSsrc.length()>3){
		VShader = glCreateShader(GL_VERTEX_SHADER);	
		str = VSsrc.c_str();
		glShaderSource(VShader, 1, &str, NULL);
		glCompileShader(VShader);
		cnt+=checkCompileErrors(VShader, "VertexShader");
		glAttachShader(program, VShader);
	}
	if(FSsrc.length()>3){
		FShader = glCreateShader(GL_FRAGMENT_SHADER);
		str = FSsrc.c_str();
		glShaderSource(FShader, 1, &str, NULL);
		glCompileShader(FShader);
		cnt+=checkCompileErrors(FShader, "FragmentShader");
		glAttachShader(program, FShader);
	}
	if(TCsrc.length()>3){
		TCShader = glCreateShader(GL_TESS_CONTROL_SHADER);	
		str = TCsrc.c_str();
		glShaderSource(TCShader, 1, &str, NULL);
		glCompileShader(TCShader);
		cnt+=checkCompileErrors(TCShader, "TessControlShader");
		glAttachShader(program, TCShader);
	}
	if(TEsrc.length()>3){
		TEShader = glCreateShader(GL_TESS_EVALUATION_SHADER);	
		str = TEsrc.c_str();
		glShaderSource(TEShader, 1, &str, NULL);
		glCompileShader(TEShader);
		cnt+=checkCompileErrors(TEShader, "TessEvaluationShader");
		glAttachShader(program, TEShader);
	}
	if(GSsrc.length()>3){
		GShader = glCreateShader(GL_GEOMETRY_SHADER);	
		str = GSsrc.c_str();
		glShaderSource(GShader, 1, &str, NULL);
		glCompileShader(GShader);
		cnt+=checkCompileErrors(GShader, "GeometryShader");
		glAttachShader(program, GShader);
	}
	if(CSsrc.length()>3 && cnt==0 ){
		CShader = glCreateShader(GL_COMPUTE_SHADER);	
		str = CSsrc.c_str();
		glShaderSource(CShader, 1, &str, NULL);
		glCompileShader(CShader);
		cnt+=checkCompileErrors(CShader, "ComputeShader");
		glAttachShader(program, CShader);
	}
	shadersObjLoaded = cnt;
	glLinkProgram(program);
    programUsable = checkCompileErrors(program, "PROGRAM");
#if(USE_SHADER_LIST)
	if (programUsable) {
		createSubroutinesList();
		createUniformsList();
	}
#endif
	//if (VShader)
	//	checkCompileErrors(VShader, "vertex");
	//if (FShader)
	//	checkCompileErrors(FShader, "fragment");
	//if (TEShader)
	//	checkCompileErrors(TEShader, "tesselation evaluation");
	//if (TCShader)
	//	checkCompileErrors(TCShader, "tesselation control");
	//if (GShader)
	//	checkCompileErrors(GShader, "geometry");
	//if (CShader)
	//	checkCompileErrors(CShader, "compute");

    // delete the shaders as they're linked into our program now and no longer necessery
	if(deleteShaderObjs && programUsable)
		deleteShaders();
	return cnt;
}

uint shader::use() const{ 
	if(program && programUsable){
		glUseProgram(program);
#if(USE_SHADER_LIST)
		setUniforms();
		activeSubroutines();
#endif
		return 1;
	}
 	return 0;
}

void shader::deleteShaders(){
	if (VShader) {
		glDeleteShader(VShader);
	}
	if (TCShader) {
		glDeleteShader(TCShader);
	}
	if (TEShader) {
		glDeleteShader(TEShader);
	}
	if (GShader) {
		glDeleteShader(GShader);
	}
	if (FShader) {
		glDeleteShader(FShader);
	}
	if (CShader) {
		glDeleteShader(CShader);
	}
	VShader =
	TCShader =
	TEShader =
	GShader =
	FShader =
	CShader = 0;
}

shader* shader::atach(void) {
	count++;
	return this;
}

void shader::detach(void) {
	count--;
	if (count <= 0) {
		g_shader_list[mIndex] = NULL;
		delete this;
	}
}

int shader::createSubroutinesList() {
#if(!USE_SHADER_LIST)
	return 0;
#endif
	const GLsizei bufSize = 256; // maximum name length
	char name[bufSize];
	int  countActiveSU;
	int len, numCompS, numSubs = 0;
	uint p = program;
	// get number of uniform subroutines
	glGetProgramStageiv(p, GL_FRAGMENT_SHADER, GL_ACTIVE_SUBROUTINE_UNIFORMS, &countActiveSU);
	if (countActiveSU) {
		uniformSubroutines.resize(countActiveSU);
		subroutinesIndexes.resize(countActiveSU);
	}
	for (int i = 0; i < countActiveSU; ++i) {
		// get uniform subroutine name
		glGetActiveSubroutineUniformName(p, GL_FRAGMENT_SHADER, i, bufSize, &len, name);
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
			glGetActiveSubroutineName(p, GL_FRAGMENT_SHADER, s[j], bufSize, &len, name);
			uniformSubroutines[i].subroutines[j].index = s[j];
			uniformSubroutines[i].subroutines[j].name = name;
			numSubs++;
		}
		delete[]s;
	}
	return numSubs;
}
int shader::createUniformsList() {
#if(!USE_SHADER_LIST)
	return 0;
#endif
	const GLsizei bufSize = 256; // maximum name length
	char name[bufSize];
	uint p = program;
	GLint count;
	GLint size; // size of the variable
	GLenum type; // type of the variable (float, vec3 or mat4, etc)
	GLsizei length; // name length
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
	glGetProgramiv(p, GL_ACTIVE_UNIFORMS, &count);
	printf("Active Uniforms: %d\n", count);
	for (int i = 0; i < shaderUniforms.size(); i++) {
		delete shaderUniforms[i];
		shaderUniforms[i] = 0;
	}
	shaderUniforms.clear();
	for (int i = 0; i < count; i++) {
		glGetActiveUniform(p, (GLuint)i, bufSize, &length, &size, &type, name);
		switch (type) {
			case GL_FLOAT:				glGetUniformfv	(p, glGetUniformLocation(p, name), &float1  );		shaderUniforms.push_back(new values<float>		(name, float1   ));		break;
			case GL_FLOAT_VEC2:			glGetUniformfv	(p, glGetUniformLocation(p, name), &float2.x);		shaderUniforms.push_back(new values<vec2>		(name, float2   ));		break;
			case GL_FLOAT_VEC3:			glGetUniformfv	(p, glGetUniformLocation(p, name), &float3.x);		shaderUniforms.push_back(new values<vec3>		(name, float3   ));		break;
			case GL_FLOAT_VEC4:			glGetUniformfv	(p, glGetUniformLocation(p, name), &float4.x);		shaderUniforms.push_back(new values<vec4>		(name, float4   ));		break;
			case GL_INT:				glGetUniformiv	(p, glGetUniformLocation(p, name), &int1    );		shaderUniforms.push_back(new values<int>		(name, int1     ));		break;
			case GL_INT_VEC2:			glGetUniformiv	(p, glGetUniformLocation(p, name), &int2  .x);		shaderUniforms.push_back(new values<ivec2>		(name, int2     ));		break;
			case GL_INT_VEC3:			glGetUniformiv	(p, glGetUniformLocation(p, name), &int3  .x);		shaderUniforms.push_back(new values<ivec3>		(name, int3     ));		break;
			case GL_INT_VEC4:			glGetUniformiv	(p, glGetUniformLocation(p, name), &int4  .x);		shaderUniforms.push_back(new values<ivec4>		(name, int4     ));		break;
			case GL_UNSIGNED_INT:		glGetUniformuiv	(p, glGetUniformLocation(p, name), &uint1   );		shaderUniforms.push_back(new values<uint>		(name, uint1    ));		break;
			case GL_UNSIGNED_INT_VEC2:	glGetUniformuiv	(p, glGetUniformLocation(p, name), &uint2 .x);		shaderUniforms.push_back(new values<uivec2>		(name, uint2    ));		break;
			case GL_UNSIGNED_INT_VEC3:	glGetUniformuiv	(p, glGetUniformLocation(p, name), &uint3 .x);		shaderUniforms.push_back(new values<uivec3>		(name, uint3    ));		break;
			case GL_UNSIGNED_INT_VEC4:	glGetUniformuiv	(p, glGetUniformLocation(p, name), &uint4 .x);		shaderUniforms.push_back(new values<uivec4>		(name, uint4    ));		break;
			default:
				//printf("Uniform #%d Type: 0x%x Name: %s\n", i, type, name);
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
		//printf("Uniform #%d Type: %u Name: %s\n", i, type, name);
	}
	return count;
}

void shader::setUniforms() const {
#if(!USE_SHADER_LIST)
	return ;
#endif
	//for (int i = 0; i < shaderUniforms.float1.size(); i++)	{  setUniform(shaderUniforms.float1[i].name, shaderUniforms.float1[i].value);}
	//for (int i = 0; i < shaderUniforms.float2.size(); i++)	{  setUniform(shaderUniforms.float2[i].name, shaderUniforms.float2[i].value);}
	//for (int i = 0; i < shaderUniforms.float3.size(); i++)	{  setUniform(shaderUniforms.float3[i].name, shaderUniforms.float3[i].value);}
	//for (int i = 0; i < shaderUniforms.float4.size(); i++)	{  setUniform(shaderUniforms.float4[i].name, shaderUniforms.float4[i].value);}														      
	//for (int i = 0; i < shaderUniforms . int1.size(); i++)	{  setUniform(shaderUniforms.int1  [i].name, shaderUniforms.  int1[i].value);}
	//for (int i = 0; i < shaderUniforms . int2.size(); i++)	{  setUniform(shaderUniforms.int2  [i].name, shaderUniforms.  int2[i].value);}
	//for (int i = 0; i < shaderUniforms . int3.size(); i++)	{  setUniform(shaderUniforms.int3  [i].name, shaderUniforms.  int3[i].value);}
	//for (int i = 0; i < shaderUniforms . int4.size(); i++)	{  setUniform(shaderUniforms.int4  [i].name, shaderUniforms.  int4[i].value);}						      
	//for (int i = 0; i < shaderUniforms .uint1.size(); i++)	{  setUniform(shaderUniforms.uint1 [i].name, shaderUniforms. uint1[i].value);}
	//for (int i = 0; i < shaderUniforms .uint2.size(); i++)	{  setUniform(shaderUniforms.uint2 [i].name, shaderUniforms. uint2[i].value);}
	//for (int i = 0; i < shaderUniforms .uint3.size(); i++)	{  setUniform(shaderUniforms.uint3 [i].name, shaderUniforms. uint3[i].value);}
	//for (int i = 0; i < shaderUniforms .uint4.size(); i++)	{  setUniform(shaderUniforms.uint4 [i].name, shaderUniforms. uint4[i].value);}
	// 
	for (int i = 0; i < shaderUniforms.size(); i++) {
		shaderUniforms[i]->setUniform(this);
		//setUniform(shaderUniforms[i]->name, shaderUniforms[i]->value);
	};
}
void shader::activeSubroutines() const {
#if(!USE_SHADER_LIST)
	return;
#endif
	//static GLuint indexes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//for (int i = 0; i < uniformSubroutines.size(); ++i) {
	//	indexes[i] = uniformSubroutines[i].subroutines[subroutinesIndexes[i].active].index;
	//	//glUniformSubroutinesuiv(GL_FRAGMENT_SHADER, 1, &uniformSubroutines[i].subroutines[uniformSubroutines[i].active].index);
	//	//GLuint idx = glGetSubroutineIndex(program, GL_FRAGMENT_SHADER, uniformSubroutines[i].subroutines[uniformSubroutines[i].active].name.c_str());
	//	//glUniformSubroutinesuiv(GL_FRAGMENT_SHADER, 1, &idx);
	//	//for (int j = 0; j < uniformSubroutines[i].subroutines.size(); ++j) {
	//	//}
	//}
	//glUniformSubroutinesuiv(GL_FRAGMENT_SHADER, uniformSubroutines.size(), indexes);
	if (subroutinesIndexes.size() > 0)
		glUniformSubroutinesuiv(GL_FRAGMENT_SHADER, (GLsizei)subroutinesIndexes.size(), &subroutinesIndexes[0]);
	//delete[] indexes;
}

uint shader::checkCompileErrors(GLuint shader, string type) {
	GLint success;
	GLint size;
	GLchar* infoLog;
	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
		if (/*!success ||*/ size > 1) {
			infoLog = new GLchar[size + 2];
			infoLog[size] = 0;
			glGetShaderInfoLog(shader, size - 1, NULL, infoLog);
			std::cout << " -- -----\nERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog <<
				"\n -- --------------------------------------------------- -- " << FSsrc << std::endl <<
				"   shader: " << shadersName << ", " << name << "\n\n" << std::endl;
			delete[] infoLog;
			return success;
		}
		return success;
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &size);
		if (/*!success ||*/ size > 1) {
			infoLog = new GLchar[size + 1];
			infoLog[size] = 0;
			glGetProgramInfoLog(shader, size - 1, NULL, infoLog);
			std::cout << " -- ------\nERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "   shader: " << shadersName << ", " << name <<
				"\n -- --------------------------------------------------- -- \n\n" << std::endl;
			delete[] infoLog;
			return success;
		}
		return success;
	}
}

#pragma region setUniform

void shader::setUniform(const string &uname, const bool  &		val) const{ glUniform1i(glGetUniformLocation(program,		 uname.c_str()),		 		(int)val);}
void shader::setUniform(const string &uname, const bvec2 &		val) const{ glUniform2i(glGetUniformLocation(program,		 uname.c_str()),		 		(int)val.x,(int)val.y);}
void shader::setUniform(const string &uname, const bvec3 &		val) const{ glUniform3i(glGetUniformLocation(program,		 uname.c_str()),		 		(int)val.x,(int)val.y,(int)val.z);}
void shader::setUniform(const string &uname, const bvec4 &		val) const{ glUniform4i(glGetUniformLocation(program,		 uname.c_str()),		 		(int)val.x,(int)val.y,(int)val.z,(int)val.w);}
void shader::setUniform(const string &uname, const int &		val) const{ glUniform1i (glGetUniformLocation(program,		 uname.c_str()),		  		val);}
void shader::setUniform(const string &uname, const ivec2&		val) const{	glUniform2iv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const ivec3&		val) const{	glUniform3iv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const ivec4&		val) const{	glUniform4iv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const uint	&		val) const{ glUniform1ui (glGetUniformLocation(program,		 uname.c_str()),		 		val);}
void shader::setUniform(const string &uname, const uivec2 &		val) const{ glUniform2uiv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const uivec3 &		val) const{ glUniform3uiv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const uivec4 &		val) const{ glUniform4uiv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const float &		val) const{ glUniform1f (glGetUniformLocation(program,		 uname.c_str()),		 		val);}
void shader::setUniform(const string &uname, const vec2 &		val) const{ glUniform2fv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const vec3 &		val) const{ glUniform3fv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const vec4 &		val) const{ glUniform4fv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const double &		val) const{ glUniform1d (glGetUniformLocation(program,		 uname.c_str()),		  		val);}
void shader::setUniform(const string &uname, const dvec2 &		val) const{ glUniform2dv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const dvec3 &		val) const{ glUniform3dv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const dvec4 &		val) const{ glUniform4dv(glGetUniformLocation(program,		 uname.c_str()),		 1,		&val.x);}
void shader::setUniform(const string &uname, const mat2 &		val) const{ glUniformMatrix2fv(glGetUniformLocation(program, uname.c_str()),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const string &uname, const mat3 &		val) const{ glUniformMatrix3fv(glGetUniformLocation(program, uname.c_str()),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const string &uname, const mat4 &		val) const{ glUniformMatrix4fv(glGetUniformLocation(program, uname.c_str()),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const string &uname, const dmat2 &		val) const{ glUniformMatrix2dv(glGetUniformLocation(program, uname.c_str()),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const string &uname, const dmat3 &		val) const{ glUniformMatrix3dv(glGetUniformLocation(program, uname.c_str()),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const string &uname, const dmat4 &		val) const{ glUniformMatrix4dv(glGetUniformLocation(program, uname.c_str()),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const char* uname, const bool&			val) const{	glUniform1i(glGetUniformLocation(program,		 uname),		 		 (int)val);}
void shader::setUniform(const char* uname, const bvec2 &		val) const{ glUniform2i(glGetUniformLocation(program,		 uname),		 		 (int)val.x,(int)val.y);}
void shader::setUniform(const char* uname, const bvec3 &		val) const{ glUniform3i(glGetUniformLocation(program,		 uname),		 		 (int)val.x,(int)val.y,(int)val.z);}
void shader::setUniform(const char* uname, const bvec4 &		val) const{ glUniform4i(glGetUniformLocation(program,		 uname),		 		 (int)val.x,(int)val.y,(int)val.z,(int)val.w);}
void shader::setUniform(const char* uname, const int&			val) const{	glUniform1i (glGetUniformLocation(program,		 uname),		 		 val);}
void shader::setUniform(const char* uname, const ivec2&			val) const{	glUniform2iv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const ivec3&			val) const{	glUniform3iv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const ivec4&			val) const{	glUniform4iv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const uint&			val) const{	glUniform1ui (glGetUniformLocation(program,		 uname),		 		 val);}
void shader::setUniform(const char* uname, const uivec2&		val) const{	glUniform2uiv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const uivec3&		val) const{	glUniform3uiv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const uivec4&		val) const{	glUniform4uiv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const float&			val) const{	glUniform1f (glGetUniformLocation(program,		 uname),		 		 val);}
void shader::setUniform(const char* uname, const vec2&			val) const{	glUniform2fv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const vec3&			val) const{	glUniform3fv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const vec4&			val) const{	glUniform4fv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const double&		val) const{	glUniform1d (glGetUniformLocation(program,		 uname),		 		 val);}
void shader::setUniform(const char* uname, const dvec2&			val) const{	glUniform2dv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const dvec3&			val) const{	glUniform3dv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const dvec4&			val) const{	glUniform4dv(glGetUniformLocation(program,		 uname),		 1,		 &val.x);}
void shader::setUniform(const char* uname, const mat2&			val) const{	glUniformMatrix2fv(glGetUniformLocation(program, uname),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const char* uname, const mat3&			val) const{	glUniformMatrix3fv(glGetUniformLocation(program, uname),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const char* uname, const mat4&			val) const{	glUniformMatrix4fv(glGetUniformLocation(program, uname),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const char* uname, const dmat2&			val) const{	glUniformMatrix2dv(glGetUniformLocation(program, uname),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const char* uname, const dmat3&			val) const{	glUniformMatrix3dv(glGetUniformLocation(program, uname),		 1,		 GL_FALSE,		 &val[0][0]);}
void shader::setUniform(const char* uname, const dmat4&			val) const{	glUniformMatrix4dv(glGetUniformLocation(program, uname),		 1,		 GL_FALSE,		 &val[0][0]);}

#pragma endregion

template <typename T>
void values<T>::setUniform(const shader* s) {
	s->setUniform(name, value);
};

string shader::searchShaderFileName(const string& filename) const {
	FILE* f = 0;
	string fname ;
	for (uint dir = 0; dir < dirs.size(); dir++) {
		fname = dirs[dir] + filename;
		f = fopen(fname.c_str(), "r");
		if (f) {
			fclose(f);
			return fname;
		}
	}
	return string();
}

string shader::readSource(const string& file) const {
	string f = searchShaderFileName(file);
	if (f.empty()) {
		std::cout << "ERROR::SHADER::FILE_NOT_FOUND:" << file << ": " << __LINE__ << std::endl;
		return string();
	}
	if (f.length() > 3) {
		//std::ifstream ShaderFile;
		//ShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try {
			//ShaderFile.open(f);
			//std::stringstream ShaderStream;
			//ShaderStream << ShaderFile.rdbuf();
			//ShaderFile.close();
			//return ShaderStream.str();
			string str = ShaderIncludeRecursive::load(f);
			return str;
		}
		catch (std::ifstream::failure e) {
			std::cout << "ERROR::SHADER::FILE_NOT_READ:" << f << ": " << __LINE__ << std::endl;
		}
	}
	return string();
}

int shader::reload() {
	deleteShaders();
	glUseProgram(0);
	if (program)
		glDeleteProgram(program);
	program = 0;
	readIncludeFiles(TRUE);
	readSrcFromFilenames();
	generateShadersAndProgram();
#if(USE_SHADER_LIST)
	createSubroutinesList();
	createUniformsList();
#endif
	return (shadersSourceLoaded && shadersObjLoaded && programUsable);
}




