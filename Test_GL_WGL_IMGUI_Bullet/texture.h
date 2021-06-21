#pragma once
class TextureData :public ReferenceCounter{
public:
	TextureData(void);
	~TextureData(void);
		
	string mFileName;	// complete filename (directory) of file
	string mName;		// name of this texture
	int filter_mag;
	int filter_min;
	int wrap_s;
	int wrap_t;
	int wrap_r;

	uint globj;			// OpenGL texture object
	usvec2 res;			// Resolution
	uint format;
	uint dataType;
};
class Texture {
public:
	Texture(void);
	Texture(std::string& mname);
	Texture(const json& j);
	~Texture(void);
	int read();
	int bind();
	void setTextureVariables();

	string searchTextureFileName(string& filename);
	TextureData* getTexture(string& name);
	TextureData* loadTexture(string& name);

	string mFileName;
	string mName;
	TextureData* mData;
};

extern std::map<string, TextureData*> g_texture_list;

void to_json(json& j, const TextureData& p);
void from_json(const json& j, TextureData& p);
