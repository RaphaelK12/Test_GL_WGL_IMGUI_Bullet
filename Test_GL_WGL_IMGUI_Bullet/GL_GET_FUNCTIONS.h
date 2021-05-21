#pragma once

#define GL_FUNC_DEF extern
#define GL_FUNC_DEF2

struct _cl_context;
struct _cl_event;
typedef void (APIENTRY* GLDEBUGPROC)(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, const void* userParam);
typedef void (APIENTRY* GLDEBUGPROCARB)(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, const void* userParam);
typedef void (APIENTRY* GLVULKANPROCNV)(void);
typedef void (APIENTRY* GLDEBUGPROCAMD)(unsigned int id, unsigned int category, unsigned int severity, int length, const char* message, void* userParam);

#include "GL_GL_All_Proc.h"

int LoadOGL();

