#pragma once

class aplication {
	string title ;
	vector <GLFWwindow> window;
	vector<Word*> words;
	frameBuffer* fbo;
	objeto* screenPlane;
	objeto* skyBox;
	cTimer t;
	ivec3 windowSIze;
	GLuint hdrTextures[10];
	texto* txt;

	float theta = 0;
	char limit = 1;
	union         {
		struct             {
			unsigned int    fullscreen : 1;
			unsigned int    vsync : 1;
			unsigned int    cursor : 1;
			unsigned int    stereo : 1;
			unsigned int    debug : 1;
			unsigned int    robust : 1;
		};
		unsigned int        all;
	} flags;


};

