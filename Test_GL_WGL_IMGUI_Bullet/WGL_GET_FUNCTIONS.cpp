#include "pch.h"
#include "WGL_GET_FUNCTIONS.h"

#ifdef WGL_FUNC_DEF
#undef WGL_FUNC_DEF
#define WGL_FUNC_DEF
#endif

#ifdef WGL_FUNC_DEF2
#undef WGL_FUNC_DEF2
#define WGL_FUNC_DEF2 = NULL
#endif

#ifndef _wopengl32_dll_
#define _wopengl32_dll_ 1
HMODULE wopengl32_dll = NULL;
#endif

#ifndef invalidPointer
#define	invalidPointer (p == (void*)0x0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1) )
#endif

FILE* LogWGlGetFunctions_py = NULL;
char WglBuffer256[256];

void* WGL_GetF(const char* name) {
	void* p = (void*)wglGetProcAddress(name);
	// opengl32.dll
	if (invalidPointer) {
		p = (void*)GetProcAddress(wopengl32_dll, name);
	}
	if (invalidPointer) {
		p = NULL;
	}
	fprintf(LogWGlGetFunctions_py, "    %p : %s\n", (p), name);
	return p;
}
void* WGL_GetF2(const char* name) {
	void* p;
	p = (void*)wglGetProcAddress(name);
	// opengl32.dll
	if (invalidPointer) {
		p = (void*)GetProcAddress(wopengl32_dll, name);
	}
	fprintf(LogWGlGetFunctions_py, "	%p : %s\n", (p), name);
	if (invalidPointer) {
		// ARB
		sprintf(WglBuffer256, "%s%s\0\0", name, "ARB");
		p = (void*)wglGetProcAddress(WglBuffer256);
		if (invalidPointer) {
			p = (void*)GetProcAddress(wopengl32_dll, WglBuffer256);
		}
		// EXT
		if (invalidPointer) {
			sprintf(WglBuffer256, "%s%s\0\0", name, "EXT");
			p = (void*)wglGetProcAddress(WglBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		// NV
		if (invalidPointer) {
			sprintf(WglBuffer256, "%s%s\0\0", name, "NV");
			p = (void*)wglGetProcAddress(WglBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		// AMD
		if (invalidPointer) {
			sprintf(WglBuffer256, "%s%s\0\0", name, "AMD");
			p = (void*)wglGetProcAddress(WglBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		// ATI
		if (invalidPointer) {
			sprintf(WglBuffer256, "%s%s\0\0", name, "ATI");
			p = (void*)wglGetProcAddress(WglBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		// NVX
		if (invalidPointer) {
			sprintf(WglBuffer256, "%s%s\0\0", name, "NVX");
			p = (void*)wglGetProcAddress(WglBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		if (invalidPointer)
			p = NULL;
		if (!invalidPointer)
			fprintf(LogWGlGetFunctions_py, "	  %p : %s\n", (p), WglBuffer256);
	}
	return p;
}

#define LOG_fprintf(buf, str)
#define WGL_GetFunc(type,_name_,name) type _name_ = NULL;

#include "GL_WGL_Funcdef_Proc.h"

#undef LOG_fprintf
#define LOG_fprintf(buf, str) fprintf(buf,str)

#undef WGL_GetFunc
#define WGL_GetFuncEXT(type,name) name=(type)WGL_GetF(#name);
#define WGL_GetFunc(type,_name_,name) _name_=(type)WGL_GetF2(#name);

int LoadWGL() {
	LogWGlGetFunctions_py = fopen("LogWGlGetFunctions.py", "wb");
	if (!wopengl32_dll)
		wopengl32_dll = LoadLibraryA("opengl32.dll");

	#include "GL_WGL_Funcdef_Proc.h"

	fclose(LogWGlGetFunctions_py);
	return 0;
}





