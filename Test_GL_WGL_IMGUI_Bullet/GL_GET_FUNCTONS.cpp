#include "pch.h"

#ifdef GL_FUNC_DEF
#undef GL_FUNC_DEF
#define GL_FUNC_DEF
#endif
#ifdef GL_FUNC_DEF2
#undef GL_FUNC_DEF2
#define GL_FUNC_DEF2 = NULL
#endif

#ifndef _opengl32_dll_
#define _opengl32_dll_ 1
HMODULE opengl32_dll = NULL;
#endif

#ifndef invalidPointer
#define	invalidPointer (p == (void*)0x0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1) )
#endif

FILE* LogGlGetFunctions_py = NULL;
char GlBuffer256[256];

void* GL_GetF(const char* name) {
	void* p = (void*)wglGetProcAddress(name);
	// opengl32.dll
	if (invalidPointer) {
		p = (void*)GetProcAddress(opengl32_dll, name);
	}
	if (invalidPointer) {
		p = NULL;
	}
	fprintf(LogGlGetFunctions_py, "	%p : %s\n", (p), name);
	return p;
}
void* GL_GetF2(const char* name) {
	void* p;
	p = (void*)wglGetProcAddress(name);
	// opengl32.dll
	if (invalidPointer) {
		p = (void*)GetProcAddress(opengl32_dll, name);
	}
	fprintf(LogGlGetFunctions_py, "	%p : %s\n", (p), name);

	if (invalidPointer) {
		// ARB
		sprintf(GlBuffer256, "%s%s\0\0", name, "ARB");
		p = (void*)wglGetProcAddress(GlBuffer256);
		if (invalidPointer) {
			p = (void*)GetProcAddress(opengl32_dll, GlBuffer256);
		}

		// EXT
		if (invalidPointer) {
			sprintf(GlBuffer256, "%s%s\0\0", name, "EXT");
			p = (void*)wglGetProcAddress(GlBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}

		// NV
		if (invalidPointer) {
			sprintf(GlBuffer256, "%s%s\0\0", name, "NV");
			p = (void*)wglGetProcAddress(GlBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}

		// AMD
		if (invalidPointer) {
			sprintf(GlBuffer256, "%s%s\0\0", name, "AMD");
			p = (void*)wglGetProcAddress(GlBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}

		// ATI
		if (invalidPointer) {
			sprintf(GlBuffer256, "%s%s\0\0", name, "ATI");
			p = (void*)wglGetProcAddress(GlBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}

		// NVX
		if (invalidPointer) {
			sprintf(GlBuffer256, "%s%s\0\0", name, "NVX");
			p = (void*)wglGetProcAddress(GlBuffer256);
			if (invalidPointer) {
				p = (void*)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}
		if (invalidPointer)
			p = NULL;
		if (!invalidPointer)
			fprintf(LogGlGetFunctions_py, "	  %p : %s\n", (p), GlBuffer256);
	}
	return p;
}

#define LOG_fprintf(buf, str)
#define GL_GetFunc(type, _name_, name) type _name_ = NULL;
#include "GL_GL_Funcdef_Proc.h"
#undef LOG_fprintf
#undef GL_GetFunc
#define LOG_fprintf(buf, str) fprintf(buf,str)
#define GL_GetFuncEXT(type, _name_, name) _name_=(type)GL_GetF(#name);
#define GL_GetFunc(type, _name_, name) _name_=(type)GL_GetF2(#name);

int LoadOGL() {
	LogGlGetFunctions_py = fopen("LogGlGetFunctions.py", "wb");
	if (!opengl32_dll)
		opengl32_dll = LoadLibraryA("opengl32.dll");

#include "GL_GL_Funcdef_Proc.h"

	fclose(LogGlGetFunctions_py);
	return 0;
}






