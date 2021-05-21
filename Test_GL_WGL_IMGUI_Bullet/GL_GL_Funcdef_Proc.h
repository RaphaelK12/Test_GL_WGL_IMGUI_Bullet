// Globals
#ifndef GL_VERSION_1_0
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_0\n");
GL_GetFunc( PFN_GLCULLFACE_PROC, _glCullFace_, glCullFace);
GL_GetFunc( PFN_GLFRONTFACE_PROC, _glFrontFace_, glFrontFace);
GL_GetFunc( PFN_GLHINT_PROC, _glHint_, glHint);
GL_GetFunc( PFN_GLLINEWIDTH_PROC, _glLineWidth_, glLineWidth);
GL_GetFunc( PFN_GLPOINTSIZE_PROC, _glPointSize_, glPointSize);
GL_GetFunc( PFN_GLPOLYGONMODE_PROC, _glPolygonMode_, glPolygonMode);
GL_GetFunc( PFN_GLSCISSOR_PROC, _glScissor_, glScissor);
GL_GetFunc( PFN_GLTEXPARAMETERF_PROC, _glTexParameterf_, glTexParameterf);
GL_GetFunc( PFN_GLTEXPARAMETERFV_PROC, _glTexParameterfv_, glTexParameterfv);
GL_GetFunc( PFN_GLTEXPARAMETERI_PROC, _glTexParameteri_, glTexParameteri);
GL_GetFunc( PFN_GLTEXPARAMETERIV_PROC, _glTexParameteriv_, glTexParameteriv);
GL_GetFunc( PFN_GLTEXIMAGE1D_PROC, _glTexImage1D_, glTexImage1D);
GL_GetFunc( PFN_GLTEXIMAGE2D_PROC, _glTexImage2D_, glTexImage2D);
GL_GetFunc( PFN_GLDRAWBUFFER_PROC, _glDrawBuffer_, glDrawBuffer);
GL_GetFunc( PFN_GLCLEAR_PROC, _glClear_, glClear);
GL_GetFunc( PFN_GLCLEARCOLOR_PROC, _glClearColor_, glClearColor);
GL_GetFunc( PFN_GLCLEARSTENCIL_PROC, _glClearStencil_, glClearStencil);
GL_GetFunc( PFN_GLCLEARDEPTH_PROC, _glClearDepth_, glClearDepth);
GL_GetFunc( PFN_GLSTENCILMASK_PROC, _glStencilMask_, glStencilMask);
GL_GetFunc( PFN_GLCOLORMASK_PROC, _glColorMask_, glColorMask);
GL_GetFunc( PFN_GLDEPTHMASK_PROC, _glDepthMask_, glDepthMask);
GL_GetFunc( PFN_GLDISABLE_PROC, _glDisable_, glDisable);
GL_GetFunc( PFN_GLENABLE_PROC, _glEnable_, glEnable);
GL_GetFunc( PFN_GLFINISH_PROC, _glFinish_, glFinish);
GL_GetFunc( PFN_GLFLUSH_PROC, _glFlush_, glFlush);
GL_GetFunc( PFN_GLBLENDFUNC_PROC, _glBlendFunc_, glBlendFunc);
GL_GetFunc( PFN_GLLOGICOP_PROC, _glLogicOp_, glLogicOp);
GL_GetFunc( PFN_GLSTENCILFUNC_PROC, _glStencilFunc_, glStencilFunc);
GL_GetFunc( PFN_GLSTENCILOP_PROC, _glStencilOp_, glStencilOp);
GL_GetFunc( PFN_GLDEPTHFUNC_PROC, _glDepthFunc_, glDepthFunc);
GL_GetFunc( PFN_GLPIXELSTOREF_PROC, _glPixelStoref_, glPixelStoref);
GL_GetFunc( PFN_GLPIXELSTOREI_PROC, _glPixelStorei_, glPixelStorei);
GL_GetFunc( PFN_GLREADBUFFER_PROC, _glReadBuffer_, glReadBuffer);
GL_GetFunc( PFN_GLREADPIXELS_PROC, _glReadPixels_, glReadPixels);
GL_GetFunc( PFN_GLGETBOOLEANV_PROC, _glGetBooleanv_, glGetBooleanv);
GL_GetFunc( PFN_GLGETDOUBLEV_PROC, _glGetDoublev_, glGetDoublev);
GL_GetFunc( PFN_GLGETERROR_PROC, _glGetError_, glGetError);
GL_GetFunc( PFN_GLGETFLOATV_PROC, _glGetFloatv_, glGetFloatv);
GL_GetFunc( PFN_GLGETINTEGERV_PROC, _glGetIntegerv_, glGetIntegerv);
GL_GetFunc( PFN_GLGETSTRING_PROC, _glGetString_, glGetString);
GL_GetFunc( PFN_GLGETTEXIMAGE_PROC, _glGetTexImage_, glGetTexImage);
GL_GetFunc( PFN_GLGETTEXPARAMETERFV_PROC, _glGetTexParameterfv_, glGetTexParameterfv);
GL_GetFunc( PFN_GLGETTEXPARAMETERIV_PROC, _glGetTexParameteriv_, glGetTexParameteriv);
GL_GetFunc( PFN_GLGETTEXLEVELPARAMETERFV_PROC, _glGetTexLevelParameterfv_, glGetTexLevelParameterfv);
GL_GetFunc( PFN_GLGETTEXLEVELPARAMETERIV_PROC, _glGetTexLevelParameteriv_, glGetTexLevelParameteriv);
GL_GetFunc( PFN_GLISENABLED_PROC, _glIsEnabled_, glIsEnabled);
GL_GetFunc( PFN_GLDEPTHRANGE_PROC, _glDepthRange_, glDepthRange);
GL_GetFunc( PFN_GLVIEWPORT_PROC, _glViewport_, glViewport);
#endif //GL_VERSION_1_0

#ifndef GL_VERSION_1_1
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_1\n");
GL_GetFunc( PFN_GLDRAWARRAYS_PROC, _glDrawArrays_, glDrawArrays);
GL_GetFunc( PFN_GLDRAWELEMENTS_PROC, _glDrawElements_, glDrawElements);
GL_GetFunc( PFN_GLGETPOINTERV_PROC, _glGetPointerv_, glGetPointerv);
GL_GetFunc( PFN_GLPOLYGONOFFSET_PROC, _glPolygonOffset_, glPolygonOffset);
GL_GetFunc( PFN_GLCOPYTEXIMAGE1D_PROC, _glCopyTexImage1D_, glCopyTexImage1D);
GL_GetFunc( PFN_GLCOPYTEXIMAGE2D_PROC, _glCopyTexImage2D_, glCopyTexImage2D);
GL_GetFunc( PFN_GLCOPYTEXSUBIMAGE1D_PROC, _glCopyTexSubImage1D_, glCopyTexSubImage1D);
GL_GetFunc( PFN_GLCOPYTEXSUBIMAGE2D_PROC, _glCopyTexSubImage2D_, glCopyTexSubImage2D);
GL_GetFunc( PFN_GLTEXSUBIMAGE1D_PROC, _glTexSubImage1D_, glTexSubImage1D);
GL_GetFunc( PFN_GLTEXSUBIMAGE2D_PROC, _glTexSubImage2D_, glTexSubImage2D);
GL_GetFunc( PFN_GLBINDTEXTURE_PROC, _glBindTexture_, glBindTexture);
GL_GetFunc( PFN_GLDELETETEXTURES_PROC, _glDeleteTextures_, glDeleteTextures);
GL_GetFunc( PFN_GLGENTEXTURES_PROC, _glGenTextures_, glGenTextures);
GL_GetFunc( PFN_GLISTEXTURE_PROC, _glIsTexture_, glIsTexture);
#endif //GL_VERSION_1_1

#ifndef GL_VERSION_1_2
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_2\n");
GL_GetFunc( PFN_GLDRAWRANGEELEMENTS_PROC, _glDrawRangeElements_, glDrawRangeElements);
GL_GetFunc( PFN_GLTEXIMAGE3D_PROC, _glTexImage3D_, glTexImage3D);
GL_GetFunc( PFN_GLTEXSUBIMAGE3D_PROC, _glTexSubImage3D_, glTexSubImage3D);
GL_GetFunc( PFN_GLCOPYTEXSUBIMAGE3D_PROC, _glCopyTexSubImage3D_, glCopyTexSubImage3D);
#endif //GL_VERSION_1_2

#ifndef GL_VERSION_1_3
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_3\n");
GL_GetFunc( PFN_GLACTIVETEXTURE_PROC, _glActiveTexture_, glActiveTexture);
GL_GetFunc( PFN_GLSAMPLECOVERAGE_PROC, _glSampleCoverage_, glSampleCoverage);
GL_GetFunc( PFN_GLCOMPRESSEDTEXIMAGE3D_PROC, _glCompressedTexImage3D_, glCompressedTexImage3D);
GL_GetFunc( PFN_GLCOMPRESSEDTEXIMAGE2D_PROC, _glCompressedTexImage2D_, glCompressedTexImage2D);
GL_GetFunc( PFN_GLCOMPRESSEDTEXIMAGE1D_PROC, _glCompressedTexImage1D_, glCompressedTexImage1D);
GL_GetFunc( PFN_GLCOMPRESSEDTEXSUBIMAGE3D_PROC, _glCompressedTexSubImage3D_, glCompressedTexSubImage3D);
GL_GetFunc( PFN_GLCOMPRESSEDTEXSUBIMAGE2D_PROC, _glCompressedTexSubImage2D_, glCompressedTexSubImage2D);
GL_GetFunc( PFN_GLCOMPRESSEDTEXSUBIMAGE1D_PROC, _glCompressedTexSubImage1D_, glCompressedTexSubImage1D);
GL_GetFunc( PFN_GLGETCOMPRESSEDTEXIMAGE_PROC, _glGetCompressedTexImage_, glGetCompressedTexImage);
GL_GetFunc( PFN_GLCLIENTACTIVETEXTURE_PROC, _glClientActiveTexture_, glClientActiveTexture);
GL_GetFunc( PFN_GLMULTITEXCOORD1D_PROC, _glMultiTexCoord1d_, glMultiTexCoord1d);
GL_GetFunc( PFN_GLMULTITEXCOORD1DV_PROC, _glMultiTexCoord1dv_, glMultiTexCoord1dv);
GL_GetFunc( PFN_GLMULTITEXCOORD1F_PROC, _glMultiTexCoord1f_, glMultiTexCoord1f);
GL_GetFunc( PFN_GLMULTITEXCOORD1FV_PROC, _glMultiTexCoord1fv_, glMultiTexCoord1fv);
GL_GetFunc( PFN_GLMULTITEXCOORD1I_PROC, _glMultiTexCoord1i_, glMultiTexCoord1i);
GL_GetFunc( PFN_GLMULTITEXCOORD1IV_PROC, _glMultiTexCoord1iv_, glMultiTexCoord1iv);
GL_GetFunc( PFN_GLMULTITEXCOORD1S_PROC, _glMultiTexCoord1s_, glMultiTexCoord1s);
GL_GetFunc( PFN_GLMULTITEXCOORD1SV_PROC, _glMultiTexCoord1sv_, glMultiTexCoord1sv);
GL_GetFunc( PFN_GLMULTITEXCOORD2D_PROC, _glMultiTexCoord2d_, glMultiTexCoord2d);
GL_GetFunc( PFN_GLMULTITEXCOORD2DV_PROC, _glMultiTexCoord2dv_, glMultiTexCoord2dv);
GL_GetFunc( PFN_GLMULTITEXCOORD2F_PROC, _glMultiTexCoord2f_, glMultiTexCoord2f);
GL_GetFunc( PFN_GLMULTITEXCOORD2FV_PROC, _glMultiTexCoord2fv_, glMultiTexCoord2fv);
GL_GetFunc( PFN_GLMULTITEXCOORD2I_PROC, _glMultiTexCoord2i_, glMultiTexCoord2i);
GL_GetFunc( PFN_GLMULTITEXCOORD2IV_PROC, _glMultiTexCoord2iv_, glMultiTexCoord2iv);
GL_GetFunc( PFN_GLMULTITEXCOORD2S_PROC, _glMultiTexCoord2s_, glMultiTexCoord2s);
GL_GetFunc( PFN_GLMULTITEXCOORD2SV_PROC, _glMultiTexCoord2sv_, glMultiTexCoord2sv);
GL_GetFunc( PFN_GLMULTITEXCOORD3D_PROC, _glMultiTexCoord3d_, glMultiTexCoord3d);
GL_GetFunc( PFN_GLMULTITEXCOORD3DV_PROC, _glMultiTexCoord3dv_, glMultiTexCoord3dv);
GL_GetFunc( PFN_GLMULTITEXCOORD3F_PROC, _glMultiTexCoord3f_, glMultiTexCoord3f);
GL_GetFunc( PFN_GLMULTITEXCOORD3FV_PROC, _glMultiTexCoord3fv_, glMultiTexCoord3fv);
GL_GetFunc( PFN_GLMULTITEXCOORD3I_PROC, _glMultiTexCoord3i_, glMultiTexCoord3i);
GL_GetFunc( PFN_GLMULTITEXCOORD3IV_PROC, _glMultiTexCoord3iv_, glMultiTexCoord3iv);
GL_GetFunc( PFN_GLMULTITEXCOORD3S_PROC, _glMultiTexCoord3s_, glMultiTexCoord3s);
GL_GetFunc( PFN_GLMULTITEXCOORD3SV_PROC, _glMultiTexCoord3sv_, glMultiTexCoord3sv);
GL_GetFunc( PFN_GLMULTITEXCOORD4D_PROC, _glMultiTexCoord4d_, glMultiTexCoord4d);
GL_GetFunc( PFN_GLMULTITEXCOORD4DV_PROC, _glMultiTexCoord4dv_, glMultiTexCoord4dv);
GL_GetFunc( PFN_GLMULTITEXCOORD4F_PROC, _glMultiTexCoord4f_, glMultiTexCoord4f);
GL_GetFunc( PFN_GLMULTITEXCOORD4FV_PROC, _glMultiTexCoord4fv_, glMultiTexCoord4fv);
GL_GetFunc( PFN_GLMULTITEXCOORD4I_PROC, _glMultiTexCoord4i_, glMultiTexCoord4i);
GL_GetFunc( PFN_GLMULTITEXCOORD4IV_PROC, _glMultiTexCoord4iv_, glMultiTexCoord4iv);
GL_GetFunc( PFN_GLMULTITEXCOORD4S_PROC, _glMultiTexCoord4s_, glMultiTexCoord4s);
GL_GetFunc( PFN_GLMULTITEXCOORD4SV_PROC, _glMultiTexCoord4sv_, glMultiTexCoord4sv);
GL_GetFunc( PFN_GLLOADTRANSPOSEMATRIXF_PROC, _glLoadTransposeMatrixf_, glLoadTransposeMatrixf);
GL_GetFunc( PFN_GLLOADTRANSPOSEMATRIXD_PROC, _glLoadTransposeMatrixd_, glLoadTransposeMatrixd);
GL_GetFunc( PFN_GLMULTTRANSPOSEMATRIXF_PROC, _glMultTransposeMatrixf_, glMultTransposeMatrixf);
GL_GetFunc( PFN_GLMULTTRANSPOSEMATRIXD_PROC, _glMultTransposeMatrixd_, glMultTransposeMatrixd);
#endif //GL_VERSION_1_3

#ifndef GL_VERSION_1_4
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_4\n");
GL_GetFunc( PFN_GLBLENDFUNCSEPARATE_PROC, _glBlendFuncSeparate_, glBlendFuncSeparate);
GL_GetFunc( PFN_GLMULTIDRAWARRAYS_PROC, _glMultiDrawArrays_, glMultiDrawArrays);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTS_PROC, _glMultiDrawElements_, glMultiDrawElements);
GL_GetFunc( PFN_GLPOINTPARAMETERF_PROC, _glPointParameterf_, glPointParameterf);
GL_GetFunc( PFN_GLPOINTPARAMETERFV_PROC, _glPointParameterfv_, glPointParameterfv);
GL_GetFunc( PFN_GLPOINTPARAMETERI_PROC, _glPointParameteri_, glPointParameteri);
GL_GetFunc( PFN_GLPOINTPARAMETERIV_PROC, _glPointParameteriv_, glPointParameteriv);
GL_GetFunc( PFN_GLBLENDCOLOR_PROC, _glBlendColor_, glBlendColor);
GL_GetFunc( PFN_GLBLENDEQUATION_PROC, _glBlendEquation_, glBlendEquation);
GL_GetFunc( PFN_GLFOGCOORDF_PROC, _glFogCoordf_, glFogCoordf);
GL_GetFunc( PFN_GLFOGCOORDFV_PROC, _glFogCoordfv_, glFogCoordfv);
GL_GetFunc( PFN_GLFOGCOORDD_PROC, _glFogCoordd_, glFogCoordd);
GL_GetFunc( PFN_GLFOGCOORDDV_PROC, _glFogCoorddv_, glFogCoorddv);
GL_GetFunc( PFN_GLFOGCOORDPOINTER_PROC, _glFogCoordPointer_, glFogCoordPointer);
GL_GetFunc( PFN_GLSECONDARYCOLOR3B_PROC, _glSecondaryColor3b_, glSecondaryColor3b);
GL_GetFunc( PFN_GLSECONDARYCOLOR3BV_PROC, _glSecondaryColor3bv_, glSecondaryColor3bv);
GL_GetFunc( PFN_GLSECONDARYCOLOR3D_PROC, _glSecondaryColor3d_, glSecondaryColor3d);
GL_GetFunc( PFN_GLSECONDARYCOLOR3DV_PROC, _glSecondaryColor3dv_, glSecondaryColor3dv);
GL_GetFunc( PFN_GLSECONDARYCOLOR3F_PROC, _glSecondaryColor3f_, glSecondaryColor3f);
GL_GetFunc( PFN_GLSECONDARYCOLOR3FV_PROC, _glSecondaryColor3fv_, glSecondaryColor3fv);
GL_GetFunc( PFN_GLSECONDARYCOLOR3I_PROC, _glSecondaryColor3i_, glSecondaryColor3i);
GL_GetFunc( PFN_GLSECONDARYCOLOR3IV_PROC, _glSecondaryColor3iv_, glSecondaryColor3iv);
GL_GetFunc( PFN_GLSECONDARYCOLOR3S_PROC, _glSecondaryColor3s_, glSecondaryColor3s);
GL_GetFunc( PFN_GLSECONDARYCOLOR3SV_PROC, _glSecondaryColor3sv_, glSecondaryColor3sv);
GL_GetFunc( PFN_GLSECONDARYCOLOR3UB_PROC, _glSecondaryColor3ub_, glSecondaryColor3ub);
GL_GetFunc( PFN_GLSECONDARYCOLOR3UBV_PROC, _glSecondaryColor3ubv_, glSecondaryColor3ubv);
GL_GetFunc( PFN_GLSECONDARYCOLOR3UI_PROC, _glSecondaryColor3ui_, glSecondaryColor3ui);
GL_GetFunc( PFN_GLSECONDARYCOLOR3UIV_PROC, _glSecondaryColor3uiv_, glSecondaryColor3uiv);
GL_GetFunc( PFN_GLSECONDARYCOLOR3US_PROC, _glSecondaryColor3us_, glSecondaryColor3us);
GL_GetFunc( PFN_GLSECONDARYCOLOR3USV_PROC, _glSecondaryColor3usv_, glSecondaryColor3usv);
GL_GetFunc( PFN_GLSECONDARYCOLORPOINTER_PROC, _glSecondaryColorPointer_, glSecondaryColorPointer);
GL_GetFunc( PFN_GLWINDOWPOS2D_PROC, _glWindowPos2d_, glWindowPos2d);
GL_GetFunc( PFN_GLWINDOWPOS2DV_PROC, _glWindowPos2dv_, glWindowPos2dv);
GL_GetFunc( PFN_GLWINDOWPOS2F_PROC, _glWindowPos2f_, glWindowPos2f);
GL_GetFunc( PFN_GLWINDOWPOS2FV_PROC, _glWindowPos2fv_, glWindowPos2fv);
GL_GetFunc( PFN_GLWINDOWPOS2I_PROC, _glWindowPos2i_, glWindowPos2i);
GL_GetFunc( PFN_GLWINDOWPOS2IV_PROC, _glWindowPos2iv_, glWindowPos2iv);
GL_GetFunc( PFN_GLWINDOWPOS2S_PROC, _glWindowPos2s_, glWindowPos2s);
GL_GetFunc( PFN_GLWINDOWPOS2SV_PROC, _glWindowPos2sv_, glWindowPos2sv);
GL_GetFunc( PFN_GLWINDOWPOS3D_PROC, _glWindowPos3d_, glWindowPos3d);
GL_GetFunc( PFN_GLWINDOWPOS3DV_PROC, _glWindowPos3dv_, glWindowPos3dv);
GL_GetFunc( PFN_GLWINDOWPOS3F_PROC, _glWindowPos3f_, glWindowPos3f);
GL_GetFunc( PFN_GLWINDOWPOS3FV_PROC, _glWindowPos3fv_, glWindowPos3fv);
GL_GetFunc( PFN_GLWINDOWPOS3I_PROC, _glWindowPos3i_, glWindowPos3i);
GL_GetFunc( PFN_GLWINDOWPOS3IV_PROC, _glWindowPos3iv_, glWindowPos3iv);
GL_GetFunc( PFN_GLWINDOWPOS3S_PROC, _glWindowPos3s_, glWindowPos3s);
GL_GetFunc( PFN_GLWINDOWPOS3SV_PROC, _glWindowPos3sv_, glWindowPos3sv);
#endif //GL_VERSION_1_4

#ifndef GL_VERSION_1_5
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_5\n");
GL_GetFunc( PFN_GLGENQUERIES_PROC, _glGenQueries_, glGenQueries);
GL_GetFunc( PFN_GLDELETEQUERIES_PROC, _glDeleteQueries_, glDeleteQueries);
GL_GetFunc( PFN_GLISQUERY_PROC, _glIsQuery_, glIsQuery);
GL_GetFunc( PFN_GLBEGINQUERY_PROC, _glBeginQuery_, glBeginQuery);
GL_GetFunc( PFN_GLENDQUERY_PROC, _glEndQuery_, glEndQuery);
GL_GetFunc( PFN_GLGETQUERYIV_PROC, _glGetQueryiv_, glGetQueryiv);
GL_GetFunc( PFN_GLGETQUERYOBJECTIV_PROC, _glGetQueryObjectiv_, glGetQueryObjectiv);
GL_GetFunc( PFN_GLGETQUERYOBJECTUIV_PROC, _glGetQueryObjectuiv_, glGetQueryObjectuiv);
GL_GetFunc( PFN_GLBINDBUFFER_PROC, _glBindBuffer_, glBindBuffer);
GL_GetFunc( PFN_GLDELETEBUFFERS_PROC, _glDeleteBuffers_, glDeleteBuffers);
GL_GetFunc( PFN_GLGENBUFFERS_PROC, _glGenBuffers_, glGenBuffers);
GL_GetFunc( PFN_GLISBUFFER_PROC, _glIsBuffer_, glIsBuffer);
GL_GetFunc( PFN_GLBUFFERDATA_PROC, _glBufferData_, glBufferData);
GL_GetFunc( PFN_GLBUFFERSUBDATA_PROC, _glBufferSubData_, glBufferSubData);
GL_GetFunc( PFN_GLGETBUFFERSUBDATA_PROC, _glGetBufferSubData_, glGetBufferSubData);
GL_GetFunc( PFN_GLMAPBUFFER_PROC, _glMapBuffer_, glMapBuffer);
GL_GetFunc( PFN_GLUNMAPBUFFER_PROC, _glUnmapBuffer_, glUnmapBuffer);
GL_GetFunc( PFN_GLGETBUFFERPARAMETERIV_PROC, _glGetBufferParameteriv_, glGetBufferParameteriv);
GL_GetFunc( PFN_GLGETBUFFERPOINTERV_PROC, _glGetBufferPointerv_, glGetBufferPointerv);
#endif //GL_VERSION_1_5

#ifndef GL_VERSION_2_0
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_2_0\n");
GL_GetFunc( PFN_GLBLENDEQUATIONSEPARATE_PROC, _glBlendEquationSeparate_, glBlendEquationSeparate);
GL_GetFunc( PFN_GLDRAWBUFFERS_PROC, _glDrawBuffers_, glDrawBuffers);
GL_GetFunc( PFN_GLSTENCILOPSEPARATE_PROC, _glStencilOpSeparate_, glStencilOpSeparate);
GL_GetFunc( PFN_GLSTENCILFUNCSEPARATE_PROC, _glStencilFuncSeparate_, glStencilFuncSeparate);
GL_GetFunc( PFN_GLSTENCILMASKSEPARATE_PROC, _glStencilMaskSeparate_, glStencilMaskSeparate);
GL_GetFunc( PFN_GLATTACHSHADER_PROC, _glAttachShader_, glAttachShader);
GL_GetFunc( PFN_GLBINDATTRIBLOCATION_PROC, _glBindAttribLocation_, glBindAttribLocation);
GL_GetFunc( PFN_GLCOMPILESHADER_PROC, _glCompileShader_, glCompileShader);
GL_GetFunc( PFN_GLCREATEPROGRAM_PROC, _glCreateProgram_, glCreateProgram);
GL_GetFunc( PFN_GLCREATESHADER_PROC, _glCreateShader_, glCreateShader);
GL_GetFunc( PFN_GLDELETEPROGRAM_PROC, _glDeleteProgram_, glDeleteProgram);
GL_GetFunc( PFN_GLDELETESHADER_PROC, _glDeleteShader_, glDeleteShader);
GL_GetFunc( PFN_GLDETACHSHADER_PROC, _glDetachShader_, glDetachShader);
GL_GetFunc( PFN_GLDISABLEVERTEXATTRIBARRAY_PROC, _glDisableVertexAttribArray_, glDisableVertexAttribArray);
GL_GetFunc( PFN_GLENABLEVERTEXATTRIBARRAY_PROC, _glEnableVertexAttribArray_, glEnableVertexAttribArray);
GL_GetFunc( PFN_GLGETACTIVEATTRIB_PROC, _glGetActiveAttrib_, glGetActiveAttrib);
GL_GetFunc( PFN_GLGETACTIVEUNIFORM_PROC, _glGetActiveUniform_, glGetActiveUniform);
GL_GetFunc( PFN_GLGETATTACHEDSHADERS_PROC, _glGetAttachedShaders_, glGetAttachedShaders);
GL_GetFunc( PFN_GLGETATTRIBLOCATION_PROC, _glGetAttribLocation_, glGetAttribLocation);
GL_GetFunc( PFN_GLGETPROGRAMIV_PROC, _glGetProgramiv_, glGetProgramiv);
GL_GetFunc( PFN_GLGETPROGRAMINFOLOG_PROC, _glGetProgramInfoLog_, glGetProgramInfoLog);
GL_GetFunc( PFN_GLGETSHADERIV_PROC, _glGetShaderiv_, glGetShaderiv);
GL_GetFunc( PFN_GLGETSHADERINFOLOG_PROC, _glGetShaderInfoLog_, glGetShaderInfoLog);
GL_GetFunc( PFN_GLGETSHADERSOURCE_PROC, _glGetShaderSource_, glGetShaderSource);
GL_GetFunc( PFN_GLGETUNIFORMLOCATION_PROC, _glGetUniformLocation_, glGetUniformLocation);
GL_GetFunc( PFN_GLGETUNIFORMFV_PROC, _glGetUniformfv_, glGetUniformfv);
GL_GetFunc( PFN_GLGETUNIFORMIV_PROC, _glGetUniformiv_, glGetUniformiv);
GL_GetFunc( PFN_GLGETVERTEXATTRIBDV_PROC, _glGetVertexAttribdv_, glGetVertexAttribdv);
GL_GetFunc( PFN_GLGETVERTEXATTRIBFV_PROC, _glGetVertexAttribfv_, glGetVertexAttribfv);
GL_GetFunc( PFN_GLGETVERTEXATTRIBIV_PROC, _glGetVertexAttribiv_, glGetVertexAttribiv);
GL_GetFunc( PFN_GLGETVERTEXATTRIBPOINTERV_PROC, _glGetVertexAttribPointerv_, glGetVertexAttribPointerv);
GL_GetFunc( PFN_GLISPROGRAM_PROC, _glIsProgram_, glIsProgram);
GL_GetFunc( PFN_GLISSHADER_PROC, _glIsShader_, glIsShader);
GL_GetFunc( PFN_GLLINKPROGRAM_PROC, _glLinkProgram_, glLinkProgram);
GL_GetFunc( PFN_GLSHADERSOURCE_PROC, _glShaderSource_, glShaderSource);
GL_GetFunc( PFN_GLUSEPROGRAM_PROC, _glUseProgram_, glUseProgram);
GL_GetFunc( PFN_GLUNIFORM1F_PROC, _glUniform1f_, glUniform1f);
GL_GetFunc( PFN_GLUNIFORM2F_PROC, _glUniform2f_, glUniform2f);
GL_GetFunc( PFN_GLUNIFORM3F_PROC, _glUniform3f_, glUniform3f);
GL_GetFunc( PFN_GLUNIFORM4F_PROC, _glUniform4f_, glUniform4f);
GL_GetFunc( PFN_GLUNIFORM1I_PROC, _glUniform1i_, glUniform1i);
GL_GetFunc( PFN_GLUNIFORM2I_PROC, _glUniform2i_, glUniform2i);
GL_GetFunc( PFN_GLUNIFORM3I_PROC, _glUniform3i_, glUniform3i);
GL_GetFunc( PFN_GLUNIFORM4I_PROC, _glUniform4i_, glUniform4i);
GL_GetFunc( PFN_GLUNIFORM1FV_PROC, _glUniform1fv_, glUniform1fv);
GL_GetFunc( PFN_GLUNIFORM2FV_PROC, _glUniform2fv_, glUniform2fv);
GL_GetFunc( PFN_GLUNIFORM3FV_PROC, _glUniform3fv_, glUniform3fv);
GL_GetFunc( PFN_GLUNIFORM4FV_PROC, _glUniform4fv_, glUniform4fv);
GL_GetFunc( PFN_GLUNIFORM1IV_PROC, _glUniform1iv_, glUniform1iv);
GL_GetFunc( PFN_GLUNIFORM2IV_PROC, _glUniform2iv_, glUniform2iv);
GL_GetFunc( PFN_GLUNIFORM3IV_PROC, _glUniform3iv_, glUniform3iv);
GL_GetFunc( PFN_GLUNIFORM4IV_PROC, _glUniform4iv_, glUniform4iv);
GL_GetFunc( PFN_GLUNIFORMMATRIX2FV_PROC, _glUniformMatrix2fv_, glUniformMatrix2fv);
GL_GetFunc( PFN_GLUNIFORMMATRIX3FV_PROC, _glUniformMatrix3fv_, glUniformMatrix3fv);
GL_GetFunc( PFN_GLUNIFORMMATRIX4FV_PROC, _glUniformMatrix4fv_, glUniformMatrix4fv);
GL_GetFunc( PFN_GLVALIDATEPROGRAM_PROC, _glValidateProgram_, glValidateProgram);
GL_GetFunc( PFN_GLVERTEXATTRIB1D_PROC, _glVertexAttrib1d_, glVertexAttrib1d);
GL_GetFunc( PFN_GLVERTEXATTRIB1DV_PROC, _glVertexAttrib1dv_, glVertexAttrib1dv);
GL_GetFunc( PFN_GLVERTEXATTRIB1F_PROC, _glVertexAttrib1f_, glVertexAttrib1f);
GL_GetFunc( PFN_GLVERTEXATTRIB1FV_PROC, _glVertexAttrib1fv_, glVertexAttrib1fv);
GL_GetFunc( PFN_GLVERTEXATTRIB1S_PROC, _glVertexAttrib1s_, glVertexAttrib1s);
GL_GetFunc( PFN_GLVERTEXATTRIB1SV_PROC, _glVertexAttrib1sv_, glVertexAttrib1sv);
GL_GetFunc( PFN_GLVERTEXATTRIB2D_PROC, _glVertexAttrib2d_, glVertexAttrib2d);
GL_GetFunc( PFN_GLVERTEXATTRIB2DV_PROC, _glVertexAttrib2dv_, glVertexAttrib2dv);
GL_GetFunc( PFN_GLVERTEXATTRIB2F_PROC, _glVertexAttrib2f_, glVertexAttrib2f);
GL_GetFunc( PFN_GLVERTEXATTRIB2FV_PROC, _glVertexAttrib2fv_, glVertexAttrib2fv);
GL_GetFunc( PFN_GLVERTEXATTRIB2S_PROC, _glVertexAttrib2s_, glVertexAttrib2s);
GL_GetFunc( PFN_GLVERTEXATTRIB2SV_PROC, _glVertexAttrib2sv_, glVertexAttrib2sv);
GL_GetFunc( PFN_GLVERTEXATTRIB3D_PROC, _glVertexAttrib3d_, glVertexAttrib3d);
GL_GetFunc( PFN_GLVERTEXATTRIB3DV_PROC, _glVertexAttrib3dv_, glVertexAttrib3dv);
GL_GetFunc( PFN_GLVERTEXATTRIB3F_PROC, _glVertexAttrib3f_, glVertexAttrib3f);
GL_GetFunc( PFN_GLVERTEXATTRIB3FV_PROC, _glVertexAttrib3fv_, glVertexAttrib3fv);
GL_GetFunc( PFN_GLVERTEXATTRIB3S_PROC, _glVertexAttrib3s_, glVertexAttrib3s);
GL_GetFunc( PFN_GLVERTEXATTRIB3SV_PROC, _glVertexAttrib3sv_, glVertexAttrib3sv);
GL_GetFunc( PFN_GLVERTEXATTRIB4NBV_PROC, _glVertexAttrib4Nbv_, glVertexAttrib4Nbv);
GL_GetFunc( PFN_GLVERTEXATTRIB4NIV_PROC, _glVertexAttrib4Niv_, glVertexAttrib4Niv);
GL_GetFunc( PFN_GLVERTEXATTRIB4NSV_PROC, _glVertexAttrib4Nsv_, glVertexAttrib4Nsv);
GL_GetFunc( PFN_GLVERTEXATTRIB4NUB_PROC, _glVertexAttrib4Nub_, glVertexAttrib4Nub);
GL_GetFunc( PFN_GLVERTEXATTRIB4NUBV_PROC, _glVertexAttrib4Nubv_, glVertexAttrib4Nubv);
GL_GetFunc( PFN_GLVERTEXATTRIB4NUIV_PROC, _glVertexAttrib4Nuiv_, glVertexAttrib4Nuiv);
GL_GetFunc( PFN_GLVERTEXATTRIB4NUSV_PROC, _glVertexAttrib4Nusv_, glVertexAttrib4Nusv);
GL_GetFunc( PFN_GLVERTEXATTRIB4BV_PROC, _glVertexAttrib4bv_, glVertexAttrib4bv);
GL_GetFunc( PFN_GLVERTEXATTRIB4D_PROC, _glVertexAttrib4d_, glVertexAttrib4d);
GL_GetFunc( PFN_GLVERTEXATTRIB4DV_PROC, _glVertexAttrib4dv_, glVertexAttrib4dv);
GL_GetFunc( PFN_GLVERTEXATTRIB4F_PROC, _glVertexAttrib4f_, glVertexAttrib4f);
GL_GetFunc( PFN_GLVERTEXATTRIB4FV_PROC, _glVertexAttrib4fv_, glVertexAttrib4fv);
GL_GetFunc( PFN_GLVERTEXATTRIB4IV_PROC, _glVertexAttrib4iv_, glVertexAttrib4iv);
GL_GetFunc( PFN_GLVERTEXATTRIB4S_PROC, _glVertexAttrib4s_, glVertexAttrib4s);
GL_GetFunc( PFN_GLVERTEXATTRIB4SV_PROC, _glVertexAttrib4sv_, glVertexAttrib4sv);
GL_GetFunc( PFN_GLVERTEXATTRIB4UBV_PROC, _glVertexAttrib4ubv_, glVertexAttrib4ubv);
GL_GetFunc( PFN_GLVERTEXATTRIB4UIV_PROC, _glVertexAttrib4uiv_, glVertexAttrib4uiv);
GL_GetFunc( PFN_GLVERTEXATTRIB4USV_PROC, _glVertexAttrib4usv_, glVertexAttrib4usv);
GL_GetFunc( PFN_GLVERTEXATTRIBPOINTER_PROC, _glVertexAttribPointer_, glVertexAttribPointer);
#endif //GL_VERSION_2_0

#ifndef GL_VERSION_2_1
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_2_1\n");
GL_GetFunc( PFN_GLUNIFORMMATRIX2X3FV_PROC, _glUniformMatrix2x3fv_, glUniformMatrix2x3fv);
GL_GetFunc( PFN_GLUNIFORMMATRIX3X2FV_PROC, _glUniformMatrix3x2fv_, glUniformMatrix3x2fv);
GL_GetFunc( PFN_GLUNIFORMMATRIX2X4FV_PROC, _glUniformMatrix2x4fv_, glUniformMatrix2x4fv);
GL_GetFunc( PFN_GLUNIFORMMATRIX4X2FV_PROC, _glUniformMatrix4x2fv_, glUniformMatrix4x2fv);
GL_GetFunc( PFN_GLUNIFORMMATRIX3X4FV_PROC, _glUniformMatrix3x4fv_, glUniformMatrix3x4fv);
GL_GetFunc( PFN_GLUNIFORMMATRIX4X3FV_PROC, _glUniformMatrix4x3fv_, glUniformMatrix4x3fv);
#endif //GL_VERSION_2_1

#ifndef GL_VERSION_3_0
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_3_0\n");
GL_GetFunc( PFN_GLCOLORMASKI_PROC, _glColorMaski_, glColorMaski);
GL_GetFunc( PFN_GLGETBOOLEANI_V_PROC, _glGetBooleani_v_, glGetBooleani_v);
GL_GetFunc( PFN_GLGETINTEGERI_V_PROC, _glGetIntegeri_v_, glGetIntegeri_v);
GL_GetFunc( PFN_GLENABLEI_PROC, _glEnablei_, glEnablei);
GL_GetFunc( PFN_GLDISABLEI_PROC, _glDisablei_, glDisablei);
GL_GetFunc( PFN_GLISENABLEDI_PROC, _glIsEnabledi_, glIsEnabledi);
GL_GetFunc( PFN_GLBEGINTRANSFORMFEEDBACK_PROC, _glBeginTransformFeedback_, glBeginTransformFeedback);
GL_GetFunc( PFN_GLENDTRANSFORMFEEDBACK_PROC, _glEndTransformFeedback_, glEndTransformFeedback);
GL_GetFunc( PFN_GLBINDBUFFERRANGE_PROC, _glBindBufferRange_, glBindBufferRange);
GL_GetFunc( PFN_GLBINDBUFFERBASE_PROC, _glBindBufferBase_, glBindBufferBase);
GL_GetFunc( PFN_GLTRANSFORMFEEDBACKVARYINGS_PROC, _glTransformFeedbackVaryings_, glTransformFeedbackVaryings);
GL_GetFunc( PFN_GLGETTRANSFORMFEEDBACKVARYING_PROC, _glGetTransformFeedbackVarying_, glGetTransformFeedbackVarying);
GL_GetFunc( PFN_GLCLAMPCOLOR_PROC, _glClampColor_, glClampColor);
GL_GetFunc( PFN_GLBEGINCONDITIONALRENDER_PROC, _glBeginConditionalRender_, glBeginConditionalRender);
GL_GetFunc( PFN_GLENDCONDITIONALRENDER_PROC, _glEndConditionalRender_, glEndConditionalRender);
GL_GetFunc( PFN_GLVERTEXATTRIBIPOINTER_PROC, _glVertexAttribIPointer_, glVertexAttribIPointer);
GL_GetFunc( PFN_GLGETVERTEXATTRIBIIV_PROC, _glGetVertexAttribIiv_, glGetVertexAttribIiv);
GL_GetFunc( PFN_GLGETVERTEXATTRIBIUIV_PROC, _glGetVertexAttribIuiv_, glGetVertexAttribIuiv);
GL_GetFunc( PFN_GLVERTEXATTRIBI1I_PROC, _glVertexAttribI1i_, glVertexAttribI1i);
GL_GetFunc( PFN_GLVERTEXATTRIBI2I_PROC, _glVertexAttribI2i_, glVertexAttribI2i);
GL_GetFunc( PFN_GLVERTEXATTRIBI3I_PROC, _glVertexAttribI3i_, glVertexAttribI3i);
GL_GetFunc( PFN_GLVERTEXATTRIBI4I_PROC, _glVertexAttribI4i_, glVertexAttribI4i);
GL_GetFunc( PFN_GLVERTEXATTRIBI1UI_PROC, _glVertexAttribI1ui_, glVertexAttribI1ui);
GL_GetFunc( PFN_GLVERTEXATTRIBI2UI_PROC, _glVertexAttribI2ui_, glVertexAttribI2ui);
GL_GetFunc( PFN_GLVERTEXATTRIBI3UI_PROC, _glVertexAttribI3ui_, glVertexAttribI3ui);
GL_GetFunc( PFN_GLVERTEXATTRIBI4UI_PROC, _glVertexAttribI4ui_, glVertexAttribI4ui);
GL_GetFunc( PFN_GLVERTEXATTRIBI1IV_PROC, _glVertexAttribI1iv_, glVertexAttribI1iv);
GL_GetFunc( PFN_GLVERTEXATTRIBI2IV_PROC, _glVertexAttribI2iv_, glVertexAttribI2iv);
GL_GetFunc( PFN_GLVERTEXATTRIBI3IV_PROC, _glVertexAttribI3iv_, glVertexAttribI3iv);
GL_GetFunc( PFN_GLVERTEXATTRIBI4IV_PROC, _glVertexAttribI4iv_, glVertexAttribI4iv);
GL_GetFunc( PFN_GLVERTEXATTRIBI1UIV_PROC, _glVertexAttribI1uiv_, glVertexAttribI1uiv);
GL_GetFunc( PFN_GLVERTEXATTRIBI2UIV_PROC, _glVertexAttribI2uiv_, glVertexAttribI2uiv);
GL_GetFunc( PFN_GLVERTEXATTRIBI3UIV_PROC, _glVertexAttribI3uiv_, glVertexAttribI3uiv);
GL_GetFunc( PFN_GLVERTEXATTRIBI4UIV_PROC, _glVertexAttribI4uiv_, glVertexAttribI4uiv);
GL_GetFunc( PFN_GLVERTEXATTRIBI4BV_PROC, _glVertexAttribI4bv_, glVertexAttribI4bv);
GL_GetFunc( PFN_GLVERTEXATTRIBI4SV_PROC, _glVertexAttribI4sv_, glVertexAttribI4sv);
GL_GetFunc( PFN_GLVERTEXATTRIBI4UBV_PROC, _glVertexAttribI4ubv_, glVertexAttribI4ubv);
GL_GetFunc( PFN_GLVERTEXATTRIBI4USV_PROC, _glVertexAttribI4usv_, glVertexAttribI4usv);
GL_GetFunc( PFN_GLGETUNIFORMUIV_PROC, _glGetUniformuiv_, glGetUniformuiv);
GL_GetFunc( PFN_GLBINDFRAGDATALOCATION_PROC, _glBindFragDataLocation_, glBindFragDataLocation);
GL_GetFunc( PFN_GLGETFRAGDATALOCATION_PROC, _glGetFragDataLocation_, glGetFragDataLocation);
GL_GetFunc( PFN_GLUNIFORM1UI_PROC, _glUniform1ui_, glUniform1ui);
GL_GetFunc( PFN_GLUNIFORM2UI_PROC, _glUniform2ui_, glUniform2ui);
GL_GetFunc( PFN_GLUNIFORM3UI_PROC, _glUniform3ui_, glUniform3ui);
GL_GetFunc( PFN_GLUNIFORM4UI_PROC, _glUniform4ui_, glUniform4ui);
GL_GetFunc( PFN_GLUNIFORM1UIV_PROC, _glUniform1uiv_, glUniform1uiv);
GL_GetFunc( PFN_GLUNIFORM2UIV_PROC, _glUniform2uiv_, glUniform2uiv);
GL_GetFunc( PFN_GLUNIFORM3UIV_PROC, _glUniform3uiv_, glUniform3uiv);
GL_GetFunc( PFN_GLUNIFORM4UIV_PROC, _glUniform4uiv_, glUniform4uiv);
GL_GetFunc( PFN_GLTEXPARAMETERIIV_PROC, _glTexParameterIiv_, glTexParameterIiv);
GL_GetFunc( PFN_GLTEXPARAMETERIUIV_PROC, _glTexParameterIuiv_, glTexParameterIuiv);
GL_GetFunc( PFN_GLGETTEXPARAMETERIIV_PROC, _glGetTexParameterIiv_, glGetTexParameterIiv);
GL_GetFunc( PFN_GLGETTEXPARAMETERIUIV_PROC, _glGetTexParameterIuiv_, glGetTexParameterIuiv);
GL_GetFunc( PFN_GLCLEARBUFFERIV_PROC, _glClearBufferiv_, glClearBufferiv);
GL_GetFunc( PFN_GLCLEARBUFFERUIV_PROC, _glClearBufferuiv_, glClearBufferuiv);
GL_GetFunc( PFN_GLCLEARBUFFERFV_PROC, _glClearBufferfv_, glClearBufferfv);
GL_GetFunc( PFN_GLCLEARBUFFERFI_PROC, _glClearBufferfi_, glClearBufferfi);
GL_GetFunc( PFN_GLGETSTRINGI_PROC, _glGetStringi_, glGetStringi);
GL_GetFunc( PFN_GLISRENDERBUFFER_PROC, _glIsRenderbuffer_, glIsRenderbuffer);
GL_GetFunc( PFN_GLBINDRENDERBUFFER_PROC, _glBindRenderbuffer_, glBindRenderbuffer);
GL_GetFunc( PFN_GLDELETERENDERBUFFERS_PROC, _glDeleteRenderbuffers_, glDeleteRenderbuffers);
GL_GetFunc( PFN_GLGENRENDERBUFFERS_PROC, _glGenRenderbuffers_, glGenRenderbuffers);
GL_GetFunc( PFN_GLRENDERBUFFERSTORAGE_PROC, _glRenderbufferStorage_, glRenderbufferStorage);
GL_GetFunc( PFN_GLGETRENDERBUFFERPARAMETERIV_PROC, _glGetRenderbufferParameteriv_, glGetRenderbufferParameteriv);
GL_GetFunc( PFN_GLISFRAMEBUFFER_PROC, _glIsFramebuffer_, glIsFramebuffer);
GL_GetFunc( PFN_GLBINDFRAMEBUFFER_PROC, _glBindFramebuffer_, glBindFramebuffer);
GL_GetFunc( PFN_GLDELETEFRAMEBUFFERS_PROC, _glDeleteFramebuffers_, glDeleteFramebuffers);
GL_GetFunc( PFN_GLGENFRAMEBUFFERS_PROC, _glGenFramebuffers_, glGenFramebuffers);
GL_GetFunc( PFN_GLCHECKFRAMEBUFFERSTATUS_PROC, _glCheckFramebufferStatus_, glCheckFramebufferStatus);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURE1D_PROC, _glFramebufferTexture1D_, glFramebufferTexture1D);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURE2D_PROC, _glFramebufferTexture2D_, glFramebufferTexture2D);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURE3D_PROC, _glFramebufferTexture3D_, glFramebufferTexture3D);
GL_GetFunc( PFN_GLFRAMEBUFFERRENDERBUFFER_PROC, _glFramebufferRenderbuffer_, glFramebufferRenderbuffer);
GL_GetFunc( PFN_GLGETFRAMEBUFFERATTACHMENTPARAMETERIV_PROC, _glGetFramebufferAttachmentParameteriv_, glGetFramebufferAttachmentParameteriv);
GL_GetFunc( PFN_GLGENERATEMIPMAP_PROC, _glGenerateMipmap_, glGenerateMipmap);
GL_GetFunc( PFN_GLBLITFRAMEBUFFER_PROC, _glBlitFramebuffer_, glBlitFramebuffer);
GL_GetFunc( PFN_GLRENDERBUFFERSTORAGEMULTISAMPLE_PROC, _glRenderbufferStorageMultisample_, glRenderbufferStorageMultisample);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURELAYER_PROC, _glFramebufferTextureLayer_, glFramebufferTextureLayer);
GL_GetFunc( PFN_GLMAPBUFFERRANGE_PROC, _glMapBufferRange_, glMapBufferRange);
GL_GetFunc( PFN_GLFLUSHMAPPEDBUFFERRANGE_PROC, _glFlushMappedBufferRange_, glFlushMappedBufferRange);
GL_GetFunc( PFN_GLBINDVERTEXARRAY_PROC, _glBindVertexArray_, glBindVertexArray);
GL_GetFunc( PFN_GLDELETEVERTEXARRAYS_PROC, _glDeleteVertexArrays_, glDeleteVertexArrays);
GL_GetFunc( PFN_GLGENVERTEXARRAYS_PROC, _glGenVertexArrays_, glGenVertexArrays);
GL_GetFunc( PFN_GLISVERTEXARRAY_PROC, _glIsVertexArray_, glIsVertexArray);
#endif //GL_VERSION_3_0

#ifndef GL_VERSION_3_1
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_3_1\n");
GL_GetFunc( PFN_GLDRAWARRAYSINSTANCED_PROC, _glDrawArraysInstanced_, glDrawArraysInstanced);
GL_GetFunc( PFN_GLDRAWELEMENTSINSTANCED_PROC, _glDrawElementsInstanced_, glDrawElementsInstanced);
GL_GetFunc( PFN_GLTEXBUFFER_PROC, _glTexBuffer_, glTexBuffer);
GL_GetFunc( PFN_GLPRIMITIVERESTARTINDEX_PROC, _glPrimitiveRestartIndex_, glPrimitiveRestartIndex);
GL_GetFunc( PFN_GLCOPYBUFFERSUBDATA_PROC, _glCopyBufferSubData_, glCopyBufferSubData);
GL_GetFunc( PFN_GLGETUNIFORMINDICES_PROC, _glGetUniformIndices_, glGetUniformIndices);
GL_GetFunc( PFN_GLGETACTIVEUNIFORMSIV_PROC, _glGetActiveUniformsiv_, glGetActiveUniformsiv);
GL_GetFunc( PFN_GLGETACTIVEUNIFORMNAME_PROC, _glGetActiveUniformName_, glGetActiveUniformName);
GL_GetFunc( PFN_GLGETUNIFORMBLOCKINDEX_PROC, _glGetUniformBlockIndex_, glGetUniformBlockIndex);
GL_GetFunc( PFN_GLGETACTIVEUNIFORMBLOCKIV_PROC, _glGetActiveUniformBlockiv_, glGetActiveUniformBlockiv);
GL_GetFunc( PFN_GLGETACTIVEUNIFORMBLOCKNAME_PROC, _glGetActiveUniformBlockName_, glGetActiveUniformBlockName);
GL_GetFunc( PFN_GLUNIFORMBLOCKBINDING_PROC, _glUniformBlockBinding_, glUniformBlockBinding);
#endif //GL_VERSION_3_1

#ifndef GL_VERSION_3_2
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_3_2\n");
GL_GetFunc( PFN_GLDRAWELEMENTSBASEVERTEX_PROC, _glDrawElementsBaseVertex_, glDrawElementsBaseVertex);
GL_GetFunc( PFN_GLDRAWRANGEELEMENTSBASEVERTEX_PROC, _glDrawRangeElementsBaseVertex_, glDrawRangeElementsBaseVertex);
GL_GetFunc( PFN_GLDRAWELEMENTSINSTANCEDBASEVERTEX_PROC, _glDrawElementsInstancedBaseVertex_, glDrawElementsInstancedBaseVertex);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTSBASEVERTEX_PROC, _glMultiDrawElementsBaseVertex_, glMultiDrawElementsBaseVertex);
GL_GetFunc( PFN_GLPROVOKINGVERTEX_PROC, _glProvokingVertex_, glProvokingVertex);
GL_GetFunc( PFN_GLFENCESYNC_PROC, _glFenceSync_, glFenceSync);
GL_GetFunc( PFN_GLISSYNC_PROC, _glIsSync_, glIsSync);
GL_GetFunc( PFN_GLDELETESYNC_PROC, _glDeleteSync_, glDeleteSync);
GL_GetFunc( PFN_GLCLIENTWAITSYNC_PROC, _glClientWaitSync_, glClientWaitSync);
GL_GetFunc( PFN_GLWAITSYNC_PROC, _glWaitSync_, glWaitSync);
GL_GetFunc( PFN_GLGETINTEGER64V_PROC, _glGetInteger64v_, glGetInteger64v);
GL_GetFunc( PFN_GLGETSYNCIV_PROC, _glGetSynciv_, glGetSynciv);
GL_GetFunc( PFN_GLGETINTEGER64I_V_PROC, _glGetInteger64i_v_, glGetInteger64i_v);
GL_GetFunc( PFN_GLGETBUFFERPARAMETERI64V_PROC, _glGetBufferParameteri64v_, glGetBufferParameteri64v);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURE_PROC, _glFramebufferTexture_, glFramebufferTexture);
GL_GetFunc( PFN_GLTEXIMAGE2DMULTISAMPLE_PROC, _glTexImage2DMultisample_, glTexImage2DMultisample);
GL_GetFunc( PFN_GLTEXIMAGE3DMULTISAMPLE_PROC, _glTexImage3DMultisample_, glTexImage3DMultisample);
GL_GetFunc( PFN_GLGETMULTISAMPLEFV_PROC, _glGetMultisamplefv_, glGetMultisamplefv);
GL_GetFunc( PFN_GLSAMPLEMASKI_PROC, _glSampleMaski_, glSampleMaski);
#endif //GL_VERSION_3_2

#ifndef GL_VERSION_3_3
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_3_3\n");
GL_GetFunc( PFN_GLBINDFRAGDATALOCATIONINDEXED_PROC, _glBindFragDataLocationIndexed_, glBindFragDataLocationIndexed);
GL_GetFunc( PFN_GLGETFRAGDATAINDEX_PROC, _glGetFragDataIndex_, glGetFragDataIndex);
GL_GetFunc( PFN_GLGENSAMPLERS_PROC, _glGenSamplers_, glGenSamplers);
GL_GetFunc( PFN_GLDELETESAMPLERS_PROC, _glDeleteSamplers_, glDeleteSamplers);
GL_GetFunc( PFN_GLISSAMPLER_PROC, _glIsSampler_, glIsSampler);
GL_GetFunc( PFN_GLBINDSAMPLER_PROC, _glBindSampler_, glBindSampler);
GL_GetFunc( PFN_GLSAMPLERPARAMETERI_PROC, _glSamplerParameteri_, glSamplerParameteri);
GL_GetFunc( PFN_GLSAMPLERPARAMETERIV_PROC, _glSamplerParameteriv_, glSamplerParameteriv);
GL_GetFunc( PFN_GLSAMPLERPARAMETERF_PROC, _glSamplerParameterf_, glSamplerParameterf);
GL_GetFunc( PFN_GLSAMPLERPARAMETERFV_PROC, _glSamplerParameterfv_, glSamplerParameterfv);
GL_GetFunc( PFN_GLSAMPLERPARAMETERIIV_PROC, _glSamplerParameterIiv_, glSamplerParameterIiv);
GL_GetFunc( PFN_GLSAMPLERPARAMETERIUIV_PROC, _glSamplerParameterIuiv_, glSamplerParameterIuiv);
GL_GetFunc( PFN_GLGETSAMPLERPARAMETERIV_PROC, _glGetSamplerParameteriv_, glGetSamplerParameteriv);
GL_GetFunc( PFN_GLGETSAMPLERPARAMETERIIV_PROC, _glGetSamplerParameterIiv_, glGetSamplerParameterIiv);
GL_GetFunc( PFN_GLGETSAMPLERPARAMETERFV_PROC, _glGetSamplerParameterfv_, glGetSamplerParameterfv);
GL_GetFunc( PFN_GLGETSAMPLERPARAMETERIUIV_PROC, _glGetSamplerParameterIuiv_, glGetSamplerParameterIuiv);
GL_GetFunc( PFN_GLQUERYCOUNTER_PROC, _glQueryCounter_, glQueryCounter);
GL_GetFunc( PFN_GLGETQUERYOBJECTI64V_PROC, _glGetQueryObjecti64v_, glGetQueryObjecti64v);
GL_GetFunc( PFN_GLGETQUERYOBJECTUI64V_PROC, _glGetQueryObjectui64v_, glGetQueryObjectui64v);
GL_GetFunc( PFN_GLVERTEXATTRIBDIVISOR_PROC, _glVertexAttribDivisor_, glVertexAttribDivisor);
GL_GetFunc( PFN_GLVERTEXATTRIBP1UI_PROC, _glVertexAttribP1ui_, glVertexAttribP1ui);
GL_GetFunc( PFN_GLVERTEXATTRIBP1UIV_PROC, _glVertexAttribP1uiv_, glVertexAttribP1uiv);
GL_GetFunc( PFN_GLVERTEXATTRIBP2UI_PROC, _glVertexAttribP2ui_, glVertexAttribP2ui);
GL_GetFunc( PFN_GLVERTEXATTRIBP2UIV_PROC, _glVertexAttribP2uiv_, glVertexAttribP2uiv);
GL_GetFunc( PFN_GLVERTEXATTRIBP3UI_PROC, _glVertexAttribP3ui_, glVertexAttribP3ui);
GL_GetFunc( PFN_GLVERTEXATTRIBP3UIV_PROC, _glVertexAttribP3uiv_, glVertexAttribP3uiv);
GL_GetFunc( PFN_GLVERTEXATTRIBP4UI_PROC, _glVertexAttribP4ui_, glVertexAttribP4ui);
GL_GetFunc( PFN_GLVERTEXATTRIBP4UIV_PROC, _glVertexAttribP4uiv_, glVertexAttribP4uiv);
GL_GetFunc( PFN_GLVERTEXP2UI_PROC, _glVertexP2ui_, glVertexP2ui);
GL_GetFunc( PFN_GLVERTEXP2UIV_PROC, _glVertexP2uiv_, glVertexP2uiv);
GL_GetFunc( PFN_GLVERTEXP3UI_PROC, _glVertexP3ui_, glVertexP3ui);
GL_GetFunc( PFN_GLVERTEXP3UIV_PROC, _glVertexP3uiv_, glVertexP3uiv);
GL_GetFunc( PFN_GLVERTEXP4UI_PROC, _glVertexP4ui_, glVertexP4ui);
GL_GetFunc( PFN_GLVERTEXP4UIV_PROC, _glVertexP4uiv_, glVertexP4uiv);
GL_GetFunc( PFN_GLTEXCOORDP1UI_PROC, _glTexCoordP1ui_, glTexCoordP1ui);
GL_GetFunc( PFN_GLTEXCOORDP1UIV_PROC, _glTexCoordP1uiv_, glTexCoordP1uiv);
GL_GetFunc( PFN_GLTEXCOORDP2UI_PROC, _glTexCoordP2ui_, glTexCoordP2ui);
GL_GetFunc( PFN_GLTEXCOORDP2UIV_PROC, _glTexCoordP2uiv_, glTexCoordP2uiv);
GL_GetFunc( PFN_GLTEXCOORDP3UI_PROC, _glTexCoordP3ui_, glTexCoordP3ui);
GL_GetFunc( PFN_GLTEXCOORDP3UIV_PROC, _glTexCoordP3uiv_, glTexCoordP3uiv);
GL_GetFunc( PFN_GLTEXCOORDP4UI_PROC, _glTexCoordP4ui_, glTexCoordP4ui);
GL_GetFunc( PFN_GLTEXCOORDP4UIV_PROC, _glTexCoordP4uiv_, glTexCoordP4uiv);
GL_GetFunc( PFN_GLMULTITEXCOORDP1UI_PROC, _glMultiTexCoordP1ui_, glMultiTexCoordP1ui);
GL_GetFunc( PFN_GLMULTITEXCOORDP1UIV_PROC, _glMultiTexCoordP1uiv_, glMultiTexCoordP1uiv);
GL_GetFunc( PFN_GLMULTITEXCOORDP2UI_PROC, _glMultiTexCoordP2ui_, glMultiTexCoordP2ui);
GL_GetFunc( PFN_GLMULTITEXCOORDP2UIV_PROC, _glMultiTexCoordP2uiv_, glMultiTexCoordP2uiv);
GL_GetFunc( PFN_GLMULTITEXCOORDP3UI_PROC, _glMultiTexCoordP3ui_, glMultiTexCoordP3ui);
GL_GetFunc( PFN_GLMULTITEXCOORDP3UIV_PROC, _glMultiTexCoordP3uiv_, glMultiTexCoordP3uiv);
GL_GetFunc( PFN_GLMULTITEXCOORDP4UI_PROC, _glMultiTexCoordP4ui_, glMultiTexCoordP4ui);
GL_GetFunc( PFN_GLMULTITEXCOORDP4UIV_PROC, _glMultiTexCoordP4uiv_, glMultiTexCoordP4uiv);
GL_GetFunc( PFN_GLNORMALP3UI_PROC, _glNormalP3ui_, glNormalP3ui);
GL_GetFunc( PFN_GLNORMALP3UIV_PROC, _glNormalP3uiv_, glNormalP3uiv);
GL_GetFunc( PFN_GLCOLORP3UI_PROC, _glColorP3ui_, glColorP3ui);
GL_GetFunc( PFN_GLCOLORP3UIV_PROC, _glColorP3uiv_, glColorP3uiv);
GL_GetFunc( PFN_GLCOLORP4UI_PROC, _glColorP4ui_, glColorP4ui);
GL_GetFunc( PFN_GLCOLORP4UIV_PROC, _glColorP4uiv_, glColorP4uiv);
GL_GetFunc( PFN_GLSECONDARYCOLORP3UI_PROC, _glSecondaryColorP3ui_, glSecondaryColorP3ui);
GL_GetFunc( PFN_GLSECONDARYCOLORP3UIV_PROC, _glSecondaryColorP3uiv_, glSecondaryColorP3uiv);
#endif //GL_VERSION_3_3

#ifndef GL_VERSION_4_0
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_0\n");
GL_GetFunc( PFN_GLMINSAMPLESHADING_PROC, _glMinSampleShading_, glMinSampleShading);
GL_GetFunc( PFN_GLBLENDEQUATIONI_PROC, _glBlendEquationi_, glBlendEquationi);
GL_GetFunc( PFN_GLBLENDEQUATIONSEPARATEI_PROC, _glBlendEquationSeparatei_, glBlendEquationSeparatei);
GL_GetFunc( PFN_GLBLENDFUNCI_PROC, _glBlendFunci_, glBlendFunci);
GL_GetFunc( PFN_GLBLENDFUNCSEPARATEI_PROC, _glBlendFuncSeparatei_, glBlendFuncSeparatei);
GL_GetFunc( PFN_GLDRAWARRAYSINDIRECT_PROC, _glDrawArraysIndirect_, glDrawArraysIndirect);
GL_GetFunc( PFN_GLDRAWELEMENTSINDIRECT_PROC, _glDrawElementsIndirect_, glDrawElementsIndirect);
GL_GetFunc( PFN_GLUNIFORM1D_PROC, _glUniform1d_, glUniform1d);
GL_GetFunc( PFN_GLUNIFORM2D_PROC, _glUniform2d_, glUniform2d);
GL_GetFunc( PFN_GLUNIFORM3D_PROC, _glUniform3d_, glUniform3d);
GL_GetFunc( PFN_GLUNIFORM4D_PROC, _glUniform4d_, glUniform4d);
GL_GetFunc( PFN_GLUNIFORM1DV_PROC, _glUniform1dv_, glUniform1dv);
GL_GetFunc( PFN_GLUNIFORM2DV_PROC, _glUniform2dv_, glUniform2dv);
GL_GetFunc( PFN_GLUNIFORM3DV_PROC, _glUniform3dv_, glUniform3dv);
GL_GetFunc( PFN_GLUNIFORM4DV_PROC, _glUniform4dv_, glUniform4dv);
GL_GetFunc( PFN_GLUNIFORMMATRIX2DV_PROC, _glUniformMatrix2dv_, glUniformMatrix2dv);
GL_GetFunc( PFN_GLUNIFORMMATRIX3DV_PROC, _glUniformMatrix3dv_, glUniformMatrix3dv);
GL_GetFunc( PFN_GLUNIFORMMATRIX4DV_PROC, _glUniformMatrix4dv_, glUniformMatrix4dv);
GL_GetFunc( PFN_GLUNIFORMMATRIX2X3DV_PROC, _glUniformMatrix2x3dv_, glUniformMatrix2x3dv);
GL_GetFunc( PFN_GLUNIFORMMATRIX2X4DV_PROC, _glUniformMatrix2x4dv_, glUniformMatrix2x4dv);
GL_GetFunc( PFN_GLUNIFORMMATRIX3X2DV_PROC, _glUniformMatrix3x2dv_, glUniformMatrix3x2dv);
GL_GetFunc( PFN_GLUNIFORMMATRIX3X4DV_PROC, _glUniformMatrix3x4dv_, glUniformMatrix3x4dv);
GL_GetFunc( PFN_GLUNIFORMMATRIX4X2DV_PROC, _glUniformMatrix4x2dv_, glUniformMatrix4x2dv);
GL_GetFunc( PFN_GLUNIFORMMATRIX4X3DV_PROC, _glUniformMatrix4x3dv_, glUniformMatrix4x3dv);
GL_GetFunc( PFN_GLGETUNIFORMDV_PROC, _glGetUniformdv_, glGetUniformdv);
GL_GetFunc( PFN_GLGETSUBROUTINEUNIFORMLOCATION_PROC, _glGetSubroutineUniformLocation_, glGetSubroutineUniformLocation);
GL_GetFunc( PFN_GLGETSUBROUTINEINDEX_PROC, _glGetSubroutineIndex_, glGetSubroutineIndex);
GL_GetFunc( PFN_GLGETACTIVESUBROUTINEUNIFORMIV_PROC, _glGetActiveSubroutineUniformiv_, glGetActiveSubroutineUniformiv);
GL_GetFunc( PFN_GLGETACTIVESUBROUTINEUNIFORMNAME_PROC, _glGetActiveSubroutineUniformName_, glGetActiveSubroutineUniformName);
GL_GetFunc( PFN_GLGETACTIVESUBROUTINENAME_PROC, _glGetActiveSubroutineName_, glGetActiveSubroutineName);
GL_GetFunc( PFN_GLUNIFORMSUBROUTINESUIV_PROC, _glUniformSubroutinesuiv_, glUniformSubroutinesuiv);
GL_GetFunc( PFN_GLGETUNIFORMSUBROUTINEUIV_PROC, _glGetUniformSubroutineuiv_, glGetUniformSubroutineuiv);
GL_GetFunc( PFN_GLGETPROGRAMSTAGEIV_PROC, _glGetProgramStageiv_, glGetProgramStageiv);
GL_GetFunc( PFN_GLPATCHPARAMETERI_PROC, _glPatchParameteri_, glPatchParameteri);
GL_GetFunc( PFN_GLPATCHPARAMETERFV_PROC, _glPatchParameterfv_, glPatchParameterfv);
GL_GetFunc( PFN_GLBINDTRANSFORMFEEDBACK_PROC, _glBindTransformFeedback_, glBindTransformFeedback);
GL_GetFunc( PFN_GLDELETETRANSFORMFEEDBACKS_PROC, _glDeleteTransformFeedbacks_, glDeleteTransformFeedbacks);
GL_GetFunc( PFN_GLGENTRANSFORMFEEDBACKS_PROC, _glGenTransformFeedbacks_, glGenTransformFeedbacks);
GL_GetFunc( PFN_GLISTRANSFORMFEEDBACK_PROC, _glIsTransformFeedback_, glIsTransformFeedback);
GL_GetFunc( PFN_GLPAUSETRANSFORMFEEDBACK_PROC, _glPauseTransformFeedback_, glPauseTransformFeedback);
GL_GetFunc( PFN_GLRESUMETRANSFORMFEEDBACK_PROC, _glResumeTransformFeedback_, glResumeTransformFeedback);
GL_GetFunc( PFN_GLDRAWTRANSFORMFEEDBACK_PROC, _glDrawTransformFeedback_, glDrawTransformFeedback);
GL_GetFunc( PFN_GLDRAWTRANSFORMFEEDBACKSTREAM_PROC, _glDrawTransformFeedbackStream_, glDrawTransformFeedbackStream);
GL_GetFunc( PFN_GLBEGINQUERYINDEXED_PROC, _glBeginQueryIndexed_, glBeginQueryIndexed);
GL_GetFunc( PFN_GLENDQUERYINDEXED_PROC, _glEndQueryIndexed_, glEndQueryIndexed);
GL_GetFunc( PFN_GLGETQUERYINDEXEDIV_PROC, _glGetQueryIndexediv_, glGetQueryIndexediv);
#endif //GL_VERSION_4_0

#ifndef GL_VERSION_4_1
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_1\n");
GL_GetFunc( PFN_GLRELEASESHADERCOMPILER_PROC, _glReleaseShaderCompiler_, glReleaseShaderCompiler);
GL_GetFunc( PFN_GLSHADERBINARY_PROC, _glShaderBinary_, glShaderBinary);
GL_GetFunc( PFN_GLGETSHADERPRECISIONFORMAT_PROC, _glGetShaderPrecisionFormat_, glGetShaderPrecisionFormat);
GL_GetFunc( PFN_GLDEPTHRANGEF_PROC, _glDepthRangef_, glDepthRangef);
GL_GetFunc( PFN_GLCLEARDEPTHF_PROC, _glClearDepthf_, glClearDepthf);
GL_GetFunc( PFN_GLGETPROGRAMBINARY_PROC, _glGetProgramBinary_, glGetProgramBinary);
GL_GetFunc( PFN_GLPROGRAMBINARY_PROC, _glProgramBinary_, glProgramBinary);
GL_GetFunc( PFN_GLPROGRAMPARAMETERI_PROC, _glProgramParameteri_, glProgramParameteri);
GL_GetFunc( PFN_GLUSEPROGRAMSTAGES_PROC, _glUseProgramStages_, glUseProgramStages);
GL_GetFunc( PFN_GLACTIVESHADERPROGRAM_PROC, _glActiveShaderProgram_, glActiveShaderProgram);
GL_GetFunc( PFN_GLCREATESHADERPROGRAMV_PROC, _glCreateShaderProgramv_, glCreateShaderProgramv);
GL_GetFunc( PFN_GLBINDPROGRAMPIPELINE_PROC, _glBindProgramPipeline_, glBindProgramPipeline);
GL_GetFunc( PFN_GLDELETEPROGRAMPIPELINES_PROC, _glDeleteProgramPipelines_, glDeleteProgramPipelines);
GL_GetFunc( PFN_GLGENPROGRAMPIPELINES_PROC, _glGenProgramPipelines_, glGenProgramPipelines);
GL_GetFunc( PFN_GLISPROGRAMPIPELINE_PROC, _glIsProgramPipeline_, glIsProgramPipeline);
GL_GetFunc( PFN_GLGETPROGRAMPIPELINEIV_PROC, _glGetProgramPipelineiv_, glGetProgramPipelineiv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1I_PROC, _glProgramUniform1i_, glProgramUniform1i);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1IV_PROC, _glProgramUniform1iv_, glProgramUniform1iv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1F_PROC, _glProgramUniform1f_, glProgramUniform1f);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1FV_PROC, _glProgramUniform1fv_, glProgramUniform1fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1D_PROC, _glProgramUniform1d_, glProgramUniform1d);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1DV_PROC, _glProgramUniform1dv_, glProgramUniform1dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1UI_PROC, _glProgramUniform1ui_, glProgramUniform1ui);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1UIV_PROC, _glProgramUniform1uiv_, glProgramUniform1uiv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2I_PROC, _glProgramUniform2i_, glProgramUniform2i);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2IV_PROC, _glProgramUniform2iv_, glProgramUniform2iv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2F_PROC, _glProgramUniform2f_, glProgramUniform2f);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2FV_PROC, _glProgramUniform2fv_, glProgramUniform2fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2D_PROC, _glProgramUniform2d_, glProgramUniform2d);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2DV_PROC, _glProgramUniform2dv_, glProgramUniform2dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2UI_PROC, _glProgramUniform2ui_, glProgramUniform2ui);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2UIV_PROC, _glProgramUniform2uiv_, glProgramUniform2uiv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3I_PROC, _glProgramUniform3i_, glProgramUniform3i);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3IV_PROC, _glProgramUniform3iv_, glProgramUniform3iv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3F_PROC, _glProgramUniform3f_, glProgramUniform3f);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3FV_PROC, _glProgramUniform3fv_, glProgramUniform3fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3D_PROC, _glProgramUniform3d_, glProgramUniform3d);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3DV_PROC, _glProgramUniform3dv_, glProgramUniform3dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3UI_PROC, _glProgramUniform3ui_, glProgramUniform3ui);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3UIV_PROC, _glProgramUniform3uiv_, glProgramUniform3uiv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4I_PROC, _glProgramUniform4i_, glProgramUniform4i);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4IV_PROC, _glProgramUniform4iv_, glProgramUniform4iv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4F_PROC, _glProgramUniform4f_, glProgramUniform4f);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4FV_PROC, _glProgramUniform4fv_, glProgramUniform4fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4D_PROC, _glProgramUniform4d_, glProgramUniform4d);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4DV_PROC, _glProgramUniform4dv_, glProgramUniform4dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4UI_PROC, _glProgramUniform4ui_, glProgramUniform4ui);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4UIV_PROC, _glProgramUniform4uiv_, glProgramUniform4uiv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2FV_PROC, _glProgramUniformMatrix2fv_, glProgramUniformMatrix2fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3FV_PROC, _glProgramUniformMatrix3fv_, glProgramUniformMatrix3fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4FV_PROC, _glProgramUniformMatrix4fv_, glProgramUniformMatrix4fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2DV_PROC, _glProgramUniformMatrix2dv_, glProgramUniformMatrix2dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3DV_PROC, _glProgramUniformMatrix3dv_, glProgramUniformMatrix3dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4DV_PROC, _glProgramUniformMatrix4dv_, glProgramUniformMatrix4dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2X3FV_PROC, _glProgramUniformMatrix2x3fv_, glProgramUniformMatrix2x3fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3X2FV_PROC, _glProgramUniformMatrix3x2fv_, glProgramUniformMatrix3x2fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2X4FV_PROC, _glProgramUniformMatrix2x4fv_, glProgramUniformMatrix2x4fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4X2FV_PROC, _glProgramUniformMatrix4x2fv_, glProgramUniformMatrix4x2fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3X4FV_PROC, _glProgramUniformMatrix3x4fv_, glProgramUniformMatrix3x4fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4X3FV_PROC, _glProgramUniformMatrix4x3fv_, glProgramUniformMatrix4x3fv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2X3DV_PROC, _glProgramUniformMatrix2x3dv_, glProgramUniformMatrix2x3dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3X2DV_PROC, _glProgramUniformMatrix3x2dv_, glProgramUniformMatrix3x2dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2X4DV_PROC, _glProgramUniformMatrix2x4dv_, glProgramUniformMatrix2x4dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4X2DV_PROC, _glProgramUniformMatrix4x2dv_, glProgramUniformMatrix4x2dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3X4DV_PROC, _glProgramUniformMatrix3x4dv_, glProgramUniformMatrix3x4dv);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4X3DV_PROC, _glProgramUniformMatrix4x3dv_, glProgramUniformMatrix4x3dv);
GL_GetFunc( PFN_GLVALIDATEPROGRAMPIPELINE_PROC, _glValidateProgramPipeline_, glValidateProgramPipeline);
GL_GetFunc( PFN_GLGETPROGRAMPIPELINEINFOLOG_PROC, _glGetProgramPipelineInfoLog_, glGetProgramPipelineInfoLog);
GL_GetFunc( PFN_GLVERTEXATTRIBL1D_PROC, _glVertexAttribL1d_, glVertexAttribL1d);
GL_GetFunc( PFN_GLVERTEXATTRIBL2D_PROC, _glVertexAttribL2d_, glVertexAttribL2d);
GL_GetFunc( PFN_GLVERTEXATTRIBL3D_PROC, _glVertexAttribL3d_, glVertexAttribL3d);
GL_GetFunc( PFN_GLVERTEXATTRIBL4D_PROC, _glVertexAttribL4d_, glVertexAttribL4d);
GL_GetFunc( PFN_GLVERTEXATTRIBL1DV_PROC, _glVertexAttribL1dv_, glVertexAttribL1dv);
GL_GetFunc( PFN_GLVERTEXATTRIBL2DV_PROC, _glVertexAttribL2dv_, glVertexAttribL2dv);
GL_GetFunc( PFN_GLVERTEXATTRIBL3DV_PROC, _glVertexAttribL3dv_, glVertexAttribL3dv);
GL_GetFunc( PFN_GLVERTEXATTRIBL4DV_PROC, _glVertexAttribL4dv_, glVertexAttribL4dv);
GL_GetFunc( PFN_GLVERTEXATTRIBLPOINTER_PROC, _glVertexAttribLPointer_, glVertexAttribLPointer);
GL_GetFunc( PFN_GLGETVERTEXATTRIBLDV_PROC, _glGetVertexAttribLdv_, glGetVertexAttribLdv);
GL_GetFunc( PFN_GLVIEWPORTARRAYV_PROC, _glViewportArrayv_, glViewportArrayv);
GL_GetFunc( PFN_GLVIEWPORTINDEXEDF_PROC, _glViewportIndexedf_, glViewportIndexedf);
GL_GetFunc( PFN_GLVIEWPORTINDEXEDFV_PROC, _glViewportIndexedfv_, glViewportIndexedfv);
GL_GetFunc( PFN_GLSCISSORARRAYV_PROC, _glScissorArrayv_, glScissorArrayv);
GL_GetFunc( PFN_GLSCISSORINDEXED_PROC, _glScissorIndexed_, glScissorIndexed);
GL_GetFunc( PFN_GLSCISSORINDEXEDV_PROC, _glScissorIndexedv_, glScissorIndexedv);
GL_GetFunc( PFN_GLDEPTHRANGEARRAYV_PROC, _glDepthRangeArrayv_, glDepthRangeArrayv);
GL_GetFunc( PFN_GLDEPTHRANGEINDEXED_PROC, _glDepthRangeIndexed_, glDepthRangeIndexed);
GL_GetFunc( PFN_GLGETFLOATI_V_PROC, _glGetFloati_v_, glGetFloati_v);
GL_GetFunc( PFN_GLGETDOUBLEI_V_PROC, _glGetDoublei_v_, glGetDoublei_v);
#endif //GL_VERSION_4_1

#ifndef GL_VERSION_4_2
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_2\n");
GL_GetFunc( PFN_GLDRAWARRAYSINSTANCEDBASEINSTANCE_PROC, _glDrawArraysInstancedBaseInstance_, glDrawArraysInstancedBaseInstance);
GL_GetFunc( PFN_GLDRAWELEMENTSINSTANCEDBASEINSTANCE_PROC, _glDrawElementsInstancedBaseInstance_, glDrawElementsInstancedBaseInstance);
GL_GetFunc( PFN_GLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE_PROC, _glDrawElementsInstancedBaseVertexBaseInstance_, glDrawElementsInstancedBaseVertexBaseInstance);
GL_GetFunc( PFN_GLGETINTERNALFORMATIV_PROC, _glGetInternalformativ_, glGetInternalformativ);
GL_GetFunc( PFN_GLGETACTIVEATOMICCOUNTERBUFFERIV_PROC, _glGetActiveAtomicCounterBufferiv_, glGetActiveAtomicCounterBufferiv);
GL_GetFunc( PFN_GLBINDIMAGETEXTURE_PROC, _glBindImageTexture_, glBindImageTexture);
GL_GetFunc( PFN_GLMEMORYBARRIER_PROC, _glMemoryBarrier_, glMemoryBarrier);
GL_GetFunc( PFN_GLTEXSTORAGE1D_PROC, _glTexStorage1D_, glTexStorage1D);
GL_GetFunc( PFN_GLTEXSTORAGE2D_PROC, _glTexStorage2D_, glTexStorage2D);
GL_GetFunc( PFN_GLTEXSTORAGE3D_PROC, _glTexStorage3D_, glTexStorage3D);
GL_GetFunc( PFN_GLDRAWTRANSFORMFEEDBACKINSTANCED_PROC, _glDrawTransformFeedbackInstanced_, glDrawTransformFeedbackInstanced);
GL_GetFunc( PFN_GLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED_PROC, _glDrawTransformFeedbackStreamInstanced_, glDrawTransformFeedbackStreamInstanced);
#endif //GL_VERSION_4_2

#ifndef GL_VERSION_4_3
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_3\n");
GL_GetFunc( PFN_GLCLEARBUFFERDATA_PROC, _glClearBufferData_, glClearBufferData);
GL_GetFunc( PFN_GLCLEARBUFFERSUBDATA_PROC, _glClearBufferSubData_, glClearBufferSubData);
GL_GetFunc( PFN_GLDISPATCHCOMPUTE_PROC, _glDispatchCompute_, glDispatchCompute);
GL_GetFunc( PFN_GLDISPATCHCOMPUTEINDIRECT_PROC, _glDispatchComputeIndirect_, glDispatchComputeIndirect);
GL_GetFunc( PFN_GLCOPYIMAGESUBDATA_PROC, _glCopyImageSubData_, glCopyImageSubData);
GL_GetFunc( PFN_GLFRAMEBUFFERPARAMETERI_PROC, _glFramebufferParameteri_, glFramebufferParameteri);
GL_GetFunc( PFN_GLGETFRAMEBUFFERPARAMETERIV_PROC, _glGetFramebufferParameteriv_, glGetFramebufferParameteriv);
GL_GetFunc( PFN_GLGETINTERNALFORMATI64V_PROC, _glGetInternalformati64v_, glGetInternalformati64v);
GL_GetFunc( PFN_GLINVALIDATETEXSUBIMAGE_PROC, _glInvalidateTexSubImage_, glInvalidateTexSubImage);
GL_GetFunc( PFN_GLINVALIDATETEXIMAGE_PROC, _glInvalidateTexImage_, glInvalidateTexImage);
GL_GetFunc( PFN_GLINVALIDATEBUFFERSUBDATA_PROC, _glInvalidateBufferSubData_, glInvalidateBufferSubData);
GL_GetFunc( PFN_GLINVALIDATEBUFFERDATA_PROC, _glInvalidateBufferData_, glInvalidateBufferData);
GL_GetFunc( PFN_GLINVALIDATEFRAMEBUFFER_PROC, _glInvalidateFramebuffer_, glInvalidateFramebuffer);
GL_GetFunc( PFN_GLINVALIDATESUBFRAMEBUFFER_PROC, _glInvalidateSubFramebuffer_, glInvalidateSubFramebuffer);
GL_GetFunc( PFN_GLMULTIDRAWARRAYSINDIRECT_PROC, _glMultiDrawArraysIndirect_, glMultiDrawArraysIndirect);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTSINDIRECT_PROC, _glMultiDrawElementsIndirect_, glMultiDrawElementsIndirect);
GL_GetFunc( PFN_GLGETPROGRAMINTERFACEIV_PROC, _glGetProgramInterfaceiv_, glGetProgramInterfaceiv);
GL_GetFunc( PFN_GLGETPROGRAMRESOURCEINDEX_PROC, _glGetProgramResourceIndex_, glGetProgramResourceIndex);
GL_GetFunc( PFN_GLGETPROGRAMRESOURCENAME_PROC, _glGetProgramResourceName_, glGetProgramResourceName);
GL_GetFunc( PFN_GLGETPROGRAMRESOURCEIV_PROC, _glGetProgramResourceiv_, glGetProgramResourceiv);
GL_GetFunc( PFN_GLGETPROGRAMRESOURCELOCATION_PROC, _glGetProgramResourceLocation_, glGetProgramResourceLocation);
GL_GetFunc( PFN_GLGETPROGRAMRESOURCELOCATIONINDEX_PROC, _glGetProgramResourceLocationIndex_, glGetProgramResourceLocationIndex);
GL_GetFunc( PFN_GLSHADERSTORAGEBLOCKBINDING_PROC, _glShaderStorageBlockBinding_, glShaderStorageBlockBinding);
GL_GetFunc( PFN_GLTEXBUFFERRANGE_PROC, _glTexBufferRange_, glTexBufferRange);
GL_GetFunc( PFN_GLTEXSTORAGE2DMULTISAMPLE_PROC, _glTexStorage2DMultisample_, glTexStorage2DMultisample);
GL_GetFunc( PFN_GLTEXSTORAGE3DMULTISAMPLE_PROC, _glTexStorage3DMultisample_, glTexStorage3DMultisample);
GL_GetFunc( PFN_GLTEXTUREVIEW_PROC, _glTextureView_, glTextureView);
GL_GetFunc( PFN_GLBINDVERTEXBUFFER_PROC, _glBindVertexBuffer_, glBindVertexBuffer);
GL_GetFunc( PFN_GLVERTEXATTRIBFORMAT_PROC, _glVertexAttribFormat_, glVertexAttribFormat);
GL_GetFunc( PFN_GLVERTEXATTRIBIFORMAT_PROC, _glVertexAttribIFormat_, glVertexAttribIFormat);
GL_GetFunc( PFN_GLVERTEXATTRIBLFORMAT_PROC, _glVertexAttribLFormat_, glVertexAttribLFormat);
GL_GetFunc( PFN_GLVERTEXATTRIBBINDING_PROC, _glVertexAttribBinding_, glVertexAttribBinding);
GL_GetFunc( PFN_GLVERTEXBINDINGDIVISOR_PROC, _glVertexBindingDivisor_, glVertexBindingDivisor);
GL_GetFunc( PFN_GLDEBUGMESSAGECONTROL_PROC, _glDebugMessageControl_, glDebugMessageControl);
GL_GetFunc( PFN_GLDEBUGMESSAGEINSERT_PROC, _glDebugMessageInsert_, glDebugMessageInsert);
GL_GetFunc( PFN_GLDEBUGMESSAGECALLBACK_PROC, _glDebugMessageCallback_, glDebugMessageCallback);
GL_GetFunc( PFN_GLGETDEBUGMESSAGELOG_PROC, _glGetDebugMessageLog_, glGetDebugMessageLog);
GL_GetFunc( PFN_GLPUSHDEBUGGROUP_PROC, _glPushDebugGroup_, glPushDebugGroup);
GL_GetFunc( PFN_GLPOPDEBUGGROUP_PROC, _glPopDebugGroup_, glPopDebugGroup);
GL_GetFunc( PFN_GLOBJECTLABEL_PROC, _glObjectLabel_, glObjectLabel);
GL_GetFunc( PFN_GLGETOBJECTLABEL_PROC, _glGetObjectLabel_, glGetObjectLabel);
GL_GetFunc( PFN_GLOBJECTPTRLABEL_PROC, _glObjectPtrLabel_, glObjectPtrLabel);
GL_GetFunc( PFN_GLGETOBJECTPTRLABEL_PROC, _glGetObjectPtrLabel_, glGetObjectPtrLabel);
#endif //GL_VERSION_4_3

#ifndef GL_VERSION_4_4
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_4\n");
GL_GetFunc( PFN_GLBUFFERSTORAGE_PROC, _glBufferStorage_, glBufferStorage);
GL_GetFunc( PFN_GLCLEARTEXIMAGE_PROC, _glClearTexImage_, glClearTexImage);
GL_GetFunc( PFN_GLCLEARTEXSUBIMAGE_PROC, _glClearTexSubImage_, glClearTexSubImage);
GL_GetFunc( PFN_GLBINDBUFFERSBASE_PROC, _glBindBuffersBase_, glBindBuffersBase);
GL_GetFunc( PFN_GLBINDBUFFERSRANGE_PROC, _glBindBuffersRange_, glBindBuffersRange);
GL_GetFunc( PFN_GLBINDTEXTURES_PROC, _glBindTextures_, glBindTextures);
GL_GetFunc( PFN_GLBINDSAMPLERS_PROC, _glBindSamplers_, glBindSamplers);
GL_GetFunc( PFN_GLBINDIMAGETEXTURES_PROC, _glBindImageTextures_, glBindImageTextures);
GL_GetFunc( PFN_GLBINDVERTEXBUFFERS_PROC, _glBindVertexBuffers_, glBindVertexBuffers);
#endif //GL_VERSION_4_4

#ifndef GL_VERSION_4_5
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_5\n");
GL_GetFunc( PFN_GLCLIPCONTROL_PROC, _glClipControl_, glClipControl);
GL_GetFunc( PFN_GLCREATETRANSFORMFEEDBACKS_PROC, _glCreateTransformFeedbacks_, glCreateTransformFeedbacks);
GL_GetFunc( PFN_GLTRANSFORMFEEDBACKBUFFERBASE_PROC, _glTransformFeedbackBufferBase_, glTransformFeedbackBufferBase);
GL_GetFunc( PFN_GLTRANSFORMFEEDBACKBUFFERRANGE_PROC, _glTransformFeedbackBufferRange_, glTransformFeedbackBufferRange);
GL_GetFunc( PFN_GLGETTRANSFORMFEEDBACKIV_PROC, _glGetTransformFeedbackiv_, glGetTransformFeedbackiv);
GL_GetFunc( PFN_GLGETTRANSFORMFEEDBACKI_V_PROC, _glGetTransformFeedbacki_v_, glGetTransformFeedbacki_v);
GL_GetFunc( PFN_GLGETTRANSFORMFEEDBACKI64_V_PROC, _glGetTransformFeedbacki64_v_, glGetTransformFeedbacki64_v);
GL_GetFunc( PFN_GLCREATEBUFFERS_PROC, _glCreateBuffers_, glCreateBuffers);
GL_GetFunc( PFN_GLNAMEDBUFFERSTORAGE_PROC, _glNamedBufferStorage_, glNamedBufferStorage);
GL_GetFunc( PFN_GLNAMEDBUFFERDATA_PROC, _glNamedBufferData_, glNamedBufferData);
GL_GetFunc( PFN_GLNAMEDBUFFERSUBDATA_PROC, _glNamedBufferSubData_, glNamedBufferSubData);
GL_GetFunc( PFN_GLCOPYNAMEDBUFFERSUBDATA_PROC, _glCopyNamedBufferSubData_, glCopyNamedBufferSubData);
GL_GetFunc( PFN_GLCLEARNAMEDBUFFERDATA_PROC, _glClearNamedBufferData_, glClearNamedBufferData);
GL_GetFunc( PFN_GLCLEARNAMEDBUFFERSUBDATA_PROC, _glClearNamedBufferSubData_, glClearNamedBufferSubData);
GL_GetFunc( PFN_GLMAPNAMEDBUFFER_PROC, _glMapNamedBuffer_, glMapNamedBuffer);
GL_GetFunc( PFN_GLMAPNAMEDBUFFERRANGE_PROC, _glMapNamedBufferRange_, glMapNamedBufferRange);
GL_GetFunc( PFN_GLUNMAPNAMEDBUFFER_PROC, _glUnmapNamedBuffer_, glUnmapNamedBuffer);
GL_GetFunc( PFN_GLFLUSHMAPPEDNAMEDBUFFERRANGE_PROC, _glFlushMappedNamedBufferRange_, glFlushMappedNamedBufferRange);
GL_GetFunc( PFN_GLGETNAMEDBUFFERPARAMETERIV_PROC, _glGetNamedBufferParameteriv_, glGetNamedBufferParameteriv);
GL_GetFunc( PFN_GLGETNAMEDBUFFERPARAMETERI64V_PROC, _glGetNamedBufferParameteri64v_, glGetNamedBufferParameteri64v);
GL_GetFunc( PFN_GLGETNAMEDBUFFERPOINTERV_PROC, _glGetNamedBufferPointerv_, glGetNamedBufferPointerv);
GL_GetFunc( PFN_GLGETNAMEDBUFFERSUBDATA_PROC, _glGetNamedBufferSubData_, glGetNamedBufferSubData);
GL_GetFunc( PFN_GLCREATEFRAMEBUFFERS_PROC, _glCreateFramebuffers_, glCreateFramebuffers);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERRENDERBUFFER_PROC, _glNamedFramebufferRenderbuffer_, glNamedFramebufferRenderbuffer);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERPARAMETERI_PROC, _glNamedFramebufferParameteri_, glNamedFramebufferParameteri);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERTEXTURE_PROC, _glNamedFramebufferTexture_, glNamedFramebufferTexture);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERTEXTURELAYER_PROC, _glNamedFramebufferTextureLayer_, glNamedFramebufferTextureLayer);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERDRAWBUFFER_PROC, _glNamedFramebufferDrawBuffer_, glNamedFramebufferDrawBuffer);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERDRAWBUFFERS_PROC, _glNamedFramebufferDrawBuffers_, glNamedFramebufferDrawBuffers);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERREADBUFFER_PROC, _glNamedFramebufferReadBuffer_, glNamedFramebufferReadBuffer);
GL_GetFunc( PFN_GLINVALIDATENAMEDFRAMEBUFFERDATA_PROC, _glInvalidateNamedFramebufferData_, glInvalidateNamedFramebufferData);
GL_GetFunc( PFN_GLINVALIDATENAMEDFRAMEBUFFERSUBDATA_PROC, _glInvalidateNamedFramebufferSubData_, glInvalidateNamedFramebufferSubData);
GL_GetFunc( PFN_GLCLEARNAMEDFRAMEBUFFERIV_PROC, _glClearNamedFramebufferiv_, glClearNamedFramebufferiv);
GL_GetFunc( PFN_GLCLEARNAMEDFRAMEBUFFERUIV_PROC, _glClearNamedFramebufferuiv_, glClearNamedFramebufferuiv);
GL_GetFunc( PFN_GLCLEARNAMEDFRAMEBUFFERFV_PROC, _glClearNamedFramebufferfv_, glClearNamedFramebufferfv);
GL_GetFunc( PFN_GLCLEARNAMEDFRAMEBUFFERFI_PROC, _glClearNamedFramebufferfi_, glClearNamedFramebufferfi);
GL_GetFunc( PFN_GLBLITNAMEDFRAMEBUFFER_PROC, _glBlitNamedFramebuffer_, glBlitNamedFramebuffer);
GL_GetFunc( PFN_GLCHECKNAMEDFRAMEBUFFERSTATUS_PROC, _glCheckNamedFramebufferStatus_, glCheckNamedFramebufferStatus);
GL_GetFunc( PFN_GLGETNAMEDFRAMEBUFFERPARAMETERIV_PROC, _glGetNamedFramebufferParameteriv_, glGetNamedFramebufferParameteriv);
GL_GetFunc( PFN_GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV_PROC, _glGetNamedFramebufferAttachmentParameteriv_, glGetNamedFramebufferAttachmentParameteriv);
GL_GetFunc( PFN_GLCREATERENDERBUFFERS_PROC, _glCreateRenderbuffers_, glCreateRenderbuffers);
GL_GetFunc( PFN_GLNAMEDRENDERBUFFERSTORAGE_PROC, _glNamedRenderbufferStorage_, glNamedRenderbufferStorage);
GL_GetFunc( PFN_GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE_PROC, _glNamedRenderbufferStorageMultisample_, glNamedRenderbufferStorageMultisample);
GL_GetFunc( PFN_GLGETNAMEDRENDERBUFFERPARAMETERIV_PROC, _glGetNamedRenderbufferParameteriv_, glGetNamedRenderbufferParameteriv);
GL_GetFunc( PFN_GLCREATETEXTURES_PROC, _glCreateTextures_, glCreateTextures);
GL_GetFunc( PFN_GLTEXTUREBUFFER_PROC, _glTextureBuffer_, glTextureBuffer);
GL_GetFunc( PFN_GLTEXTUREBUFFERRANGE_PROC, _glTextureBufferRange_, glTextureBufferRange);
GL_GetFunc( PFN_GLTEXTURESTORAGE1D_PROC, _glTextureStorage1D_, glTextureStorage1D);
GL_GetFunc( PFN_GLTEXTURESTORAGE2D_PROC, _glTextureStorage2D_, glTextureStorage2D);
GL_GetFunc( PFN_GLTEXTURESTORAGE3D_PROC, _glTextureStorage3D_, glTextureStorage3D);
GL_GetFunc( PFN_GLTEXTURESTORAGE2DMULTISAMPLE_PROC, _glTextureStorage2DMultisample_, glTextureStorage2DMultisample);
GL_GetFunc( PFN_GLTEXTURESTORAGE3DMULTISAMPLE_PROC, _glTextureStorage3DMultisample_, glTextureStorage3DMultisample);
GL_GetFunc( PFN_GLTEXTURESUBIMAGE1D_PROC, _glTextureSubImage1D_, glTextureSubImage1D);
GL_GetFunc( PFN_GLTEXTURESUBIMAGE2D_PROC, _glTextureSubImage2D_, glTextureSubImage2D);
GL_GetFunc( PFN_GLTEXTURESUBIMAGE3D_PROC, _glTextureSubImage3D_, glTextureSubImage3D);
GL_GetFunc( PFN_GLCOMPRESSEDTEXTURESUBIMAGE1D_PROC, _glCompressedTextureSubImage1D_, glCompressedTextureSubImage1D);
GL_GetFunc( PFN_GLCOMPRESSEDTEXTURESUBIMAGE2D_PROC, _glCompressedTextureSubImage2D_, glCompressedTextureSubImage2D);
GL_GetFunc( PFN_GLCOMPRESSEDTEXTURESUBIMAGE3D_PROC, _glCompressedTextureSubImage3D_, glCompressedTextureSubImage3D);
GL_GetFunc( PFN_GLCOPYTEXTURESUBIMAGE1D_PROC, _glCopyTextureSubImage1D_, glCopyTextureSubImage1D);
GL_GetFunc( PFN_GLCOPYTEXTURESUBIMAGE2D_PROC, _glCopyTextureSubImage2D_, glCopyTextureSubImage2D);
GL_GetFunc( PFN_GLCOPYTEXTURESUBIMAGE3D_PROC, _glCopyTextureSubImage3D_, glCopyTextureSubImage3D);
GL_GetFunc( PFN_GLTEXTUREPARAMETERF_PROC, _glTextureParameterf_, glTextureParameterf);
GL_GetFunc( PFN_GLTEXTUREPARAMETERFV_PROC, _glTextureParameterfv_, glTextureParameterfv);
GL_GetFunc( PFN_GLTEXTUREPARAMETERI_PROC, _glTextureParameteri_, glTextureParameteri);
GL_GetFunc( PFN_GLTEXTUREPARAMETERIIV_PROC, _glTextureParameterIiv_, glTextureParameterIiv);
GL_GetFunc( PFN_GLTEXTUREPARAMETERIUIV_PROC, _glTextureParameterIuiv_, glTextureParameterIuiv);
GL_GetFunc( PFN_GLTEXTUREPARAMETERIV_PROC, _glTextureParameteriv_, glTextureParameteriv);
GL_GetFunc( PFN_GLGENERATETEXTUREMIPMAP_PROC, _glGenerateTextureMipmap_, glGenerateTextureMipmap);
GL_GetFunc( PFN_GLBINDTEXTUREUNIT_PROC, _glBindTextureUnit_, glBindTextureUnit);
GL_GetFunc( PFN_GLGETTEXTUREIMAGE_PROC, _glGetTextureImage_, glGetTextureImage);
GL_GetFunc( PFN_GLGETCOMPRESSEDTEXTUREIMAGE_PROC, _glGetCompressedTextureImage_, glGetCompressedTextureImage);
GL_GetFunc( PFN_GLGETTEXTURELEVELPARAMETERFV_PROC, _glGetTextureLevelParameterfv_, glGetTextureLevelParameterfv);
GL_GetFunc( PFN_GLGETTEXTURELEVELPARAMETERIV_PROC, _glGetTextureLevelParameteriv_, glGetTextureLevelParameteriv);
GL_GetFunc( PFN_GLGETTEXTUREPARAMETERFV_PROC, _glGetTextureParameterfv_, glGetTextureParameterfv);
GL_GetFunc( PFN_GLGETTEXTUREPARAMETERIIV_PROC, _glGetTextureParameterIiv_, glGetTextureParameterIiv);
GL_GetFunc( PFN_GLGETTEXTUREPARAMETERIUIV_PROC, _glGetTextureParameterIuiv_, glGetTextureParameterIuiv);
GL_GetFunc( PFN_GLGETTEXTUREPARAMETERIV_PROC, _glGetTextureParameteriv_, glGetTextureParameteriv);
GL_GetFunc( PFN_GLCREATEVERTEXARRAYS_PROC, _glCreateVertexArrays_, glCreateVertexArrays);
GL_GetFunc( PFN_GLDISABLEVERTEXARRAYATTRIB_PROC, _glDisableVertexArrayAttrib_, glDisableVertexArrayAttrib);
GL_GetFunc( PFN_GLENABLEVERTEXARRAYATTRIB_PROC, _glEnableVertexArrayAttrib_, glEnableVertexArrayAttrib);
GL_GetFunc( PFN_GLVERTEXARRAYELEMENTBUFFER_PROC, _glVertexArrayElementBuffer_, glVertexArrayElementBuffer);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXBUFFER_PROC, _glVertexArrayVertexBuffer_, glVertexArrayVertexBuffer);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXBUFFERS_PROC, _glVertexArrayVertexBuffers_, glVertexArrayVertexBuffers);
GL_GetFunc( PFN_GLVERTEXARRAYATTRIBBINDING_PROC, _glVertexArrayAttribBinding_, glVertexArrayAttribBinding);
GL_GetFunc( PFN_GLVERTEXARRAYATTRIBFORMAT_PROC, _glVertexArrayAttribFormat_, glVertexArrayAttribFormat);
GL_GetFunc( PFN_GLVERTEXARRAYATTRIBIFORMAT_PROC, _glVertexArrayAttribIFormat_, glVertexArrayAttribIFormat);
GL_GetFunc( PFN_GLVERTEXARRAYATTRIBLFORMAT_PROC, _glVertexArrayAttribLFormat_, glVertexArrayAttribLFormat);
GL_GetFunc( PFN_GLVERTEXARRAYBINDINGDIVISOR_PROC, _glVertexArrayBindingDivisor_, glVertexArrayBindingDivisor);
GL_GetFunc( PFN_GLGETVERTEXARRAYIV_PROC, _glGetVertexArrayiv_, glGetVertexArrayiv);
GL_GetFunc( PFN_GLGETVERTEXARRAYINDEXEDIV_PROC, _glGetVertexArrayIndexediv_, glGetVertexArrayIndexediv);
GL_GetFunc( PFN_GLGETVERTEXARRAYINDEXED64IV_PROC, _glGetVertexArrayIndexed64iv_, glGetVertexArrayIndexed64iv);
GL_GetFunc( PFN_GLCREATESAMPLERS_PROC, _glCreateSamplers_, glCreateSamplers);
GL_GetFunc( PFN_GLCREATEPROGRAMPIPELINES_PROC, _glCreateProgramPipelines_, glCreateProgramPipelines);
GL_GetFunc( PFN_GLCREATEQUERIES_PROC, _glCreateQueries_, glCreateQueries);
GL_GetFunc( PFN_GLGETQUERYBUFFEROBJECTI64V_PROC, _glGetQueryBufferObjecti64v_, glGetQueryBufferObjecti64v);
GL_GetFunc( PFN_GLGETQUERYBUFFEROBJECTIV_PROC, _glGetQueryBufferObjectiv_, glGetQueryBufferObjectiv);
GL_GetFunc( PFN_GLGETQUERYBUFFEROBJECTUI64V_PROC, _glGetQueryBufferObjectui64v_, glGetQueryBufferObjectui64v);
GL_GetFunc( PFN_GLGETQUERYBUFFEROBJECTUIV_PROC, _glGetQueryBufferObjectuiv_, glGetQueryBufferObjectuiv);
GL_GetFunc( PFN_GLMEMORYBARRIERBYREGION_PROC, _glMemoryBarrierByRegion_, glMemoryBarrierByRegion);
GL_GetFunc( PFN_GLGETTEXTURESUBIMAGE_PROC, _glGetTextureSubImage_, glGetTextureSubImage);
GL_GetFunc( PFN_GLGETCOMPRESSEDTEXTURESUBIMAGE_PROC, _glGetCompressedTextureSubImage_, glGetCompressedTextureSubImage);
GL_GetFunc( PFN_GLGETGRAPHICSRESETSTATUS_PROC, _glGetGraphicsResetStatus_, glGetGraphicsResetStatus);
GL_GetFunc( PFN_GLGETNCOMPRESSEDTEXIMAGE_PROC, _glGetnCompressedTexImage_, glGetnCompressedTexImage);
GL_GetFunc( PFN_GLGETNTEXIMAGE_PROC, _glGetnTexImage_, glGetnTexImage);
GL_GetFunc( PFN_GLGETNUNIFORMDV_PROC, _glGetnUniformdv_, glGetnUniformdv);
GL_GetFunc( PFN_GLGETNUNIFORMFV_PROC, _glGetnUniformfv_, glGetnUniformfv);
GL_GetFunc( PFN_GLGETNUNIFORMIV_PROC, _glGetnUniformiv_, glGetnUniformiv);
GL_GetFunc( PFN_GLGETNUNIFORMUIV_PROC, _glGetnUniformuiv_, glGetnUniformuiv);
GL_GetFunc( PFN_GLREADNPIXELS_PROC, _glReadnPixels_, glReadnPixels);
GL_GetFunc( PFN_GLTEXTUREBARRIER_PROC, _glTextureBarrier_, glTextureBarrier);
GL_GetFunc( PFN_GLGETNMAPDV_PROC, _glGetnMapdv_, glGetnMapdv);
GL_GetFunc( PFN_GLGETNMAPFV_PROC, _glGetnMapfv_, glGetnMapfv);
GL_GetFunc( PFN_GLGETNMAPIV_PROC, _glGetnMapiv_, glGetnMapiv);
GL_GetFunc( PFN_GLGETNPIXELMAPFV_PROC, _glGetnPixelMapfv_, glGetnPixelMapfv);
GL_GetFunc( PFN_GLGETNPIXELMAPUIV_PROC, _glGetnPixelMapuiv_, glGetnPixelMapuiv);
GL_GetFunc( PFN_GLGETNPIXELMAPUSV_PROC, _glGetnPixelMapusv_, glGetnPixelMapusv);
GL_GetFunc( PFN_GLGETNPOLYGONSTIPPLE_PROC, _glGetnPolygonStipple_, glGetnPolygonStipple);
GL_GetFunc( PFN_GLGETNCOLORTABLE_PROC, _glGetnColorTable_, glGetnColorTable);
GL_GetFunc( PFN_GLGETNCONVOLUTIONFILTER_PROC, _glGetnConvolutionFilter_, glGetnConvolutionFilter);
GL_GetFunc( PFN_GLGETNSEPARABLEFILTER_PROC, _glGetnSeparableFilter_, glGetnSeparableFilter);
GL_GetFunc( PFN_GLGETNHISTOGRAM_PROC, _glGetnHistogram_, glGetnHistogram);
GL_GetFunc( PFN_GLGETNMINMAX_PROC, _glGetnMinmax_, glGetnMinmax);
#endif //GL_VERSION_4_5

#ifndef GL_VERSION_4_6
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_6\n");
GL_GetFunc( PFN_GLSPECIALIZESHADER_PROC, _glSpecializeShader_, glSpecializeShader);
GL_GetFunc( PFN_GLMULTIDRAWARRAYSINDIRECTCOUNT_PROC, _glMultiDrawArraysIndirectCount_, glMultiDrawArraysIndirectCount);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTSINDIRECTCOUNT_PROC, _glMultiDrawElementsIndirectCount_, glMultiDrawElementsIndirectCount);
GL_GetFunc( PFN_GLPOLYGONOFFSETCLAMP_PROC, _glPolygonOffsetClamp_, glPolygonOffsetClamp);
#endif //GL_VERSION_4_6

// GL_ARB_ES2_compatibility

// GL_ARB_ES3_1_compatibility

#ifndef GL_ARB_ES3_2_compatibility
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_ES3_2_compatibility\n");
GL_GetFunc( PFN_GLPRIMITIVEBOUNDINGBOXARB_PROC, _glPrimitiveBoundingBoxARB_, glPrimitiveBoundingBoxARB);
#endif //GL_ARB_ES3_2_compatibility

// GL_ARB_ES3_compatibility

// GL_ARB_arrays_of_arrays

// GL_ARB_base_instance

#ifndef GL_ARB_bindless_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_bindless_texture\n");
GL_GetFunc( PFN_GLGETTEXTUREHANDLEARB_PROC, _glGetTextureHandleARB_, glGetTextureHandleARB);
GL_GetFunc( PFN_GLGETTEXTURESAMPLERHANDLEARB_PROC, _glGetTextureSamplerHandleARB_, glGetTextureSamplerHandleARB);
GL_GetFunc( PFN_GLMAKETEXTUREHANDLERESIDENTARB_PROC, _glMakeTextureHandleResidentARB_, glMakeTextureHandleResidentARB);
GL_GetFunc( PFN_GLMAKETEXTUREHANDLENONRESIDENTARB_PROC, _glMakeTextureHandleNonResidentARB_, glMakeTextureHandleNonResidentARB);
GL_GetFunc( PFN_GLGETIMAGEHANDLEARB_PROC, _glGetImageHandleARB_, glGetImageHandleARB);
GL_GetFunc( PFN_GLMAKEIMAGEHANDLERESIDENTARB_PROC, _glMakeImageHandleResidentARB_, glMakeImageHandleResidentARB);
GL_GetFunc( PFN_GLMAKEIMAGEHANDLENONRESIDENTARB_PROC, _glMakeImageHandleNonResidentARB_, glMakeImageHandleNonResidentARB);
GL_GetFunc( PFN_GLUNIFORMHANDLEUI64ARB_PROC, _glUniformHandleui64ARB_, glUniformHandleui64ARB);
GL_GetFunc( PFN_GLUNIFORMHANDLEUI64VARB_PROC, _glUniformHandleui64vARB_, glUniformHandleui64vARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORMHANDLEUI64ARB_PROC, _glProgramUniformHandleui64ARB_, glProgramUniformHandleui64ARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORMHANDLEUI64VARB_PROC, _glProgramUniformHandleui64vARB_, glProgramUniformHandleui64vARB);
GL_GetFunc( PFN_GLISTEXTUREHANDLERESIDENTARB_PROC, _glIsTextureHandleResidentARB_, glIsTextureHandleResidentARB);
GL_GetFunc( PFN_GLISIMAGEHANDLERESIDENTARB_PROC, _glIsImageHandleResidentARB_, glIsImageHandleResidentARB);
GL_GetFunc( PFN_GLVERTEXATTRIBL1UI64ARB_PROC, _glVertexAttribL1ui64ARB_, glVertexAttribL1ui64ARB);
GL_GetFunc( PFN_GLVERTEXATTRIBL1UI64VARB_PROC, _glVertexAttribL1ui64vARB_, glVertexAttribL1ui64vARB);
GL_GetFunc( PFN_GLGETVERTEXATTRIBLUI64VARB_PROC, _glGetVertexAttribLui64vARB_, glGetVertexAttribLui64vARB);
#endif //GL_ARB_bindless_texture

// GL_ARB_blend_func_extended

// GL_ARB_buffer_storage

#ifndef GL_ARB_cl_event
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_cl_event\n");
GL_GetFunc( PFN_GLCREATESYNCFROMCLEVENTARB_PROC, _glCreateSyncFromCLeventARB_, glCreateSyncFromCLeventARB);
#endif //GL_ARB_cl_event

// GL_ARB_clear_buffer_object

// GL_ARB_clear_texture

// GL_ARB_clip_control

// GL_ARB_compressed_texture_pixel_storage

// GL_ARB_compute_shader

#ifndef GL_ARB_compute_variable_group_size
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_compute_variable_group_size\n");
GL_GetFunc( PFN_GLDISPATCHCOMPUTEGROUPSIZEARB_PROC, _glDispatchComputeGroupSizeARB_, glDispatchComputeGroupSizeARB);
#endif //GL_ARB_compute_variable_group_size

// GL_ARB_conditional_render_inverted

// GL_ARB_conservative_depth

// GL_ARB_copy_buffer

// GL_ARB_copy_image

// GL_ARB_cull_distance

#ifndef GL_ARB_debug_output
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_debug_output\n");
GL_GetFunc( PFN_GLDEBUGMESSAGECONTROLARB_PROC, _glDebugMessageControlARB_, glDebugMessageControlARB);
GL_GetFunc( PFN_GLDEBUGMESSAGEINSERTARB_PROC, _glDebugMessageInsertARB_, glDebugMessageInsertARB);
GL_GetFunc( PFN_GLDEBUGMESSAGECALLBACKARB_PROC, _glDebugMessageCallbackARB_, glDebugMessageCallbackARB);
GL_GetFunc( PFN_GLGETDEBUGMESSAGELOGARB_PROC, _glGetDebugMessageLogARB_, glGetDebugMessageLogARB);
#endif //GL_ARB_debug_output

// GL_ARB_depth_buffer_float

// GL_ARB_depth_clamp

// GL_ARB_derivative_control

// GL_ARB_direct_state_access

#ifndef GL_ARB_draw_buffers_blend
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_draw_buffers_blend\n");
GL_GetFunc( PFN_GLBLENDEQUATIONIARB_PROC, _glBlendEquationiARB_, glBlendEquationiARB);
GL_GetFunc( PFN_GLBLENDEQUATIONSEPARATEIARB_PROC, _glBlendEquationSeparateiARB_, glBlendEquationSeparateiARB);
GL_GetFunc( PFN_GLBLENDFUNCIARB_PROC, _glBlendFunciARB_, glBlendFunciARB);
GL_GetFunc( PFN_GLBLENDFUNCSEPARATEIARB_PROC, _glBlendFuncSeparateiARB_, glBlendFuncSeparateiARB);
#endif //GL_ARB_draw_buffers_blend

// GL_ARB_draw_elements_base_vertex

// GL_ARB_draw_indirect

#ifndef GL_ARB_draw_instanced
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_draw_instanced\n");
GL_GetFunc( PFN_GLDRAWARRAYSINSTANCEDARB_PROC, _glDrawArraysInstancedARB_, glDrawArraysInstancedARB);
GL_GetFunc( PFN_GLDRAWELEMENTSINSTANCEDARB_PROC, _glDrawElementsInstancedARB_, glDrawElementsInstancedARB);
#endif //GL_ARB_draw_instanced

// GL_ARB_enhanced_layouts

// GL_ARB_explicit_attrib_location

// GL_ARB_explicit_uniform_location

// GL_ARB_fragment_coord_conventions

// GL_ARB_fragment_layer_viewport

// GL_ARB_fragment_shader_interlock

// GL_ARB_framebuffer_no_attachments

// GL_ARB_framebuffer_object

// GL_ARB_framebuffer_sRGB

#ifndef GL_ARB_geometry_shader4
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_geometry_shader4\n");
GL_GetFunc( PFN_GLPROGRAMPARAMETERIARB_PROC, _glProgramParameteriARB_, glProgramParameteriARB);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTUREARB_PROC, _glFramebufferTextureARB_, glFramebufferTextureARB);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURELAYERARB_PROC, _glFramebufferTextureLayerARB_, glFramebufferTextureLayerARB);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTUREFACEARB_PROC, _glFramebufferTextureFaceARB_, glFramebufferTextureFaceARB);
#endif //GL_ARB_geometry_shader4

// GL_ARB_get_program_binary

// GL_ARB_get_texture_sub_image

#ifndef GL_ARB_gl_spirv
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_gl_spirv\n");
GL_GetFunc( PFN_GLSPECIALIZESHADERARB_PROC, _glSpecializeShaderARB_, glSpecializeShaderARB);
#endif //GL_ARB_gl_spirv

// GL_ARB_gpu_shader5

// GL_ARB_gpu_shader_fp64

#ifndef GL_ARB_gpu_shader_int64
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_gpu_shader_int64\n");
GL_GetFunc( PFN_GLUNIFORM1I64ARB_PROC, _glUniform1i64ARB_, glUniform1i64ARB);
GL_GetFunc( PFN_GLUNIFORM2I64ARB_PROC, _glUniform2i64ARB_, glUniform2i64ARB);
GL_GetFunc( PFN_GLUNIFORM3I64ARB_PROC, _glUniform3i64ARB_, glUniform3i64ARB);
GL_GetFunc( PFN_GLUNIFORM4I64ARB_PROC, _glUniform4i64ARB_, glUniform4i64ARB);
GL_GetFunc( PFN_GLUNIFORM1I64VARB_PROC, _glUniform1i64vARB_, glUniform1i64vARB);
GL_GetFunc( PFN_GLUNIFORM2I64VARB_PROC, _glUniform2i64vARB_, glUniform2i64vARB);
GL_GetFunc( PFN_GLUNIFORM3I64VARB_PROC, _glUniform3i64vARB_, glUniform3i64vARB);
GL_GetFunc( PFN_GLUNIFORM4I64VARB_PROC, _glUniform4i64vARB_, glUniform4i64vARB);
GL_GetFunc( PFN_GLUNIFORM1UI64ARB_PROC, _glUniform1ui64ARB_, glUniform1ui64ARB);
GL_GetFunc( PFN_GLUNIFORM2UI64ARB_PROC, _glUniform2ui64ARB_, glUniform2ui64ARB);
GL_GetFunc( PFN_GLUNIFORM3UI64ARB_PROC, _glUniform3ui64ARB_, glUniform3ui64ARB);
GL_GetFunc( PFN_GLUNIFORM4UI64ARB_PROC, _glUniform4ui64ARB_, glUniform4ui64ARB);
GL_GetFunc( PFN_GLUNIFORM1UI64VARB_PROC, _glUniform1ui64vARB_, glUniform1ui64vARB);
GL_GetFunc( PFN_GLUNIFORM2UI64VARB_PROC, _glUniform2ui64vARB_, glUniform2ui64vARB);
GL_GetFunc( PFN_GLUNIFORM3UI64VARB_PROC, _glUniform3ui64vARB_, glUniform3ui64vARB);
GL_GetFunc( PFN_GLUNIFORM4UI64VARB_PROC, _glUniform4ui64vARB_, glUniform4ui64vARB);
GL_GetFunc( PFN_GLGETUNIFORMI64VARB_PROC, _glGetUniformi64vARB_, glGetUniformi64vARB);
GL_GetFunc( PFN_GLGETUNIFORMUI64VARB_PROC, _glGetUniformui64vARB_, glGetUniformui64vARB);
GL_GetFunc( PFN_GLGETNUNIFORMI64VARB_PROC, _glGetnUniformi64vARB_, glGetnUniformi64vARB);
GL_GetFunc( PFN_GLGETNUNIFORMUI64VARB_PROC, _glGetnUniformui64vARB_, glGetnUniformui64vARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1I64ARB_PROC, _glProgramUniform1i64ARB_, glProgramUniform1i64ARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2I64ARB_PROC, _glProgramUniform2i64ARB_, glProgramUniform2i64ARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3I64ARB_PROC, _glProgramUniform3i64ARB_, glProgramUniform3i64ARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4I64ARB_PROC, _glProgramUniform4i64ARB_, glProgramUniform4i64ARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1I64VARB_PROC, _glProgramUniform1i64vARB_, glProgramUniform1i64vARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2I64VARB_PROC, _glProgramUniform2i64vARB_, glProgramUniform2i64vARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3I64VARB_PROC, _glProgramUniform3i64vARB_, glProgramUniform3i64vARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4I64VARB_PROC, _glProgramUniform4i64vARB_, glProgramUniform4i64vARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1UI64ARB_PROC, _glProgramUniform1ui64ARB_, glProgramUniform1ui64ARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2UI64ARB_PROC, _glProgramUniform2ui64ARB_, glProgramUniform2ui64ARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3UI64ARB_PROC, _glProgramUniform3ui64ARB_, glProgramUniform3ui64ARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4UI64ARB_PROC, _glProgramUniform4ui64ARB_, glProgramUniform4ui64ARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1UI64VARB_PROC, _glProgramUniform1ui64vARB_, glProgramUniform1ui64vARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2UI64VARB_PROC, _glProgramUniform2ui64vARB_, glProgramUniform2ui64vARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3UI64VARB_PROC, _glProgramUniform3ui64vARB_, glProgramUniform3ui64vARB);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4UI64VARB_PROC, _glProgramUniform4ui64vARB_, glProgramUniform4ui64vARB);
#endif //GL_ARB_gpu_shader_int64

// GL_ARB_half_float_vertex

#ifndef GL_ARB_imaging
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_imaging\n");
GL_GetFunc( PFN_GLCOLORTABLE_PROC, _glColorTable_, glColorTable);
GL_GetFunc( PFN_GLCOLORTABLEPARAMETERFV_PROC, _glColorTableParameterfv_, glColorTableParameterfv);
GL_GetFunc( PFN_GLCOLORTABLEPARAMETERIV_PROC, _glColorTableParameteriv_, glColorTableParameteriv);
GL_GetFunc( PFN_GLCOPYCOLORTABLE_PROC, _glCopyColorTable_, glCopyColorTable);
GL_GetFunc( PFN_GLGETCOLORTABLE_PROC, _glGetColorTable_, glGetColorTable);
GL_GetFunc( PFN_GLGETCOLORTABLEPARAMETERFV_PROC, _glGetColorTableParameterfv_, glGetColorTableParameterfv);
GL_GetFunc( PFN_GLGETCOLORTABLEPARAMETERIV_PROC, _glGetColorTableParameteriv_, glGetColorTableParameteriv);
GL_GetFunc( PFN_GLCOLORSUBTABLE_PROC, _glColorSubTable_, glColorSubTable);
GL_GetFunc( PFN_GLCOPYCOLORSUBTABLE_PROC, _glCopyColorSubTable_, glCopyColorSubTable);
GL_GetFunc( PFN_GLCONVOLUTIONFILTER1D_PROC, _glConvolutionFilter1D_, glConvolutionFilter1D);
GL_GetFunc( PFN_GLCONVOLUTIONFILTER2D_PROC, _glConvolutionFilter2D_, glConvolutionFilter2D);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERF_PROC, _glConvolutionParameterf_, glConvolutionParameterf);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERFV_PROC, _glConvolutionParameterfv_, glConvolutionParameterfv);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERI_PROC, _glConvolutionParameteri_, glConvolutionParameteri);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERIV_PROC, _glConvolutionParameteriv_, glConvolutionParameteriv);
GL_GetFunc( PFN_GLCOPYCONVOLUTIONFILTER1D_PROC, _glCopyConvolutionFilter1D_, glCopyConvolutionFilter1D);
GL_GetFunc( PFN_GLCOPYCONVOLUTIONFILTER2D_PROC, _glCopyConvolutionFilter2D_, glCopyConvolutionFilter2D);
GL_GetFunc( PFN_GLGETCONVOLUTIONFILTER_PROC, _glGetConvolutionFilter_, glGetConvolutionFilter);
GL_GetFunc( PFN_GLGETCONVOLUTIONPARAMETERFV_PROC, _glGetConvolutionParameterfv_, glGetConvolutionParameterfv);
GL_GetFunc( PFN_GLGETCONVOLUTIONPARAMETERIV_PROC, _glGetConvolutionParameteriv_, glGetConvolutionParameteriv);
GL_GetFunc( PFN_GLGETSEPARABLEFILTER_PROC, _glGetSeparableFilter_, glGetSeparableFilter);
GL_GetFunc( PFN_GLSEPARABLEFILTER2D_PROC, _glSeparableFilter2D_, glSeparableFilter2D);
GL_GetFunc( PFN_GLGETHISTOGRAM_PROC, _glGetHistogram_, glGetHistogram);
GL_GetFunc( PFN_GLGETHISTOGRAMPARAMETERFV_PROC, _glGetHistogramParameterfv_, glGetHistogramParameterfv);
GL_GetFunc( PFN_GLGETHISTOGRAMPARAMETERIV_PROC, _glGetHistogramParameteriv_, glGetHistogramParameteriv);
GL_GetFunc( PFN_GLGETMINMAX_PROC, _glGetMinmax_, glGetMinmax);
GL_GetFunc( PFN_GLGETMINMAXPARAMETERFV_PROC, _glGetMinmaxParameterfv_, glGetMinmaxParameterfv);
GL_GetFunc( PFN_GLGETMINMAXPARAMETERIV_PROC, _glGetMinmaxParameteriv_, glGetMinmaxParameteriv);
GL_GetFunc( PFN_GLHISTOGRAM_PROC, _glHistogram_, glHistogram);
GL_GetFunc( PFN_GLMINMAX_PROC, _glMinmax_, glMinmax);
GL_GetFunc( PFN_GLRESETHISTOGRAM_PROC, _glResetHistogram_, glResetHistogram);
GL_GetFunc( PFN_GLRESETMINMAX_PROC, _glResetMinmax_, glResetMinmax);
#endif //GL_ARB_imaging

#ifndef GL_ARB_indirect_parameters
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_indirect_parameters\n");
GL_GetFunc( PFN_GLMULTIDRAWARRAYSINDIRECTCOUNTARB_PROC, _glMultiDrawArraysIndirectCountARB_, glMultiDrawArraysIndirectCountARB);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTSINDIRECTCOUNTARB_PROC, _glMultiDrawElementsIndirectCountARB_, glMultiDrawElementsIndirectCountARB);
#endif //GL_ARB_indirect_parameters

#ifndef GL_ARB_instanced_arrays
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_instanced_arrays\n");
GL_GetFunc( PFN_GLVERTEXATTRIBDIVISORARB_PROC, _glVertexAttribDivisorARB_, glVertexAttribDivisorARB);
#endif //GL_ARB_instanced_arrays

// GL_ARB_internalformat_query

// GL_ARB_internalformat_query2

// GL_ARB_invalidate_subdata

// GL_ARB_map_buffer_alignment

// GL_ARB_map_buffer_range

// GL_ARB_multi_bind

// GL_ARB_multi_draw_indirect

// GL_ARB_occlusion_query2

#ifndef GL_ARB_parallel_shader_compile
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_parallel_shader_compile\n");
GL_GetFunc( PFN_GLMAXSHADERCOMPILERTHREADSARB_PROC, _glMaxShaderCompilerThreadsARB_, glMaxShaderCompilerThreadsARB);
#endif //GL_ARB_parallel_shader_compile

// GL_ARB_pipeline_statistics_query

// GL_ARB_pixel_buffer_object

// GL_ARB_polygon_offset_clamp

// GL_ARB_post_depth_coverage

// GL_ARB_program_interface_query

// GL_ARB_provoking_vertex

// GL_ARB_query_buffer_object

// GL_ARB_robust_buffer_access_behavior

#ifndef GL_ARB_robustness
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_robustness\n");
GL_GetFunc( PFN_GLGETGRAPHICSRESETSTATUSARB_PROC, _glGetGraphicsResetStatusARB_, glGetGraphicsResetStatusARB);
GL_GetFunc( PFN_GLGETNTEXIMAGEARB_PROC, _glGetnTexImageARB_, glGetnTexImageARB);
GL_GetFunc( PFN_GLREADNPIXELSARB_PROC, _glReadnPixelsARB_, glReadnPixelsARB);
GL_GetFunc( PFN_GLGETNCOMPRESSEDTEXIMAGEARB_PROC, _glGetnCompressedTexImageARB_, glGetnCompressedTexImageARB);
GL_GetFunc( PFN_GLGETNUNIFORMFVARB_PROC, _glGetnUniformfvARB_, glGetnUniformfvARB);
GL_GetFunc( PFN_GLGETNUNIFORMIVARB_PROC, _glGetnUniformivARB_, glGetnUniformivARB);
GL_GetFunc( PFN_GLGETNUNIFORMUIVARB_PROC, _glGetnUniformuivARB_, glGetnUniformuivARB);
GL_GetFunc( PFN_GLGETNUNIFORMDVARB_PROC, _glGetnUniformdvARB_, glGetnUniformdvARB);
GL_GetFunc( PFN_GLGETNMAPDVARB_PROC, _glGetnMapdvARB_, glGetnMapdvARB);
GL_GetFunc( PFN_GLGETNMAPFVARB_PROC, _glGetnMapfvARB_, glGetnMapfvARB);
GL_GetFunc( PFN_GLGETNMAPIVARB_PROC, _glGetnMapivARB_, glGetnMapivARB);
GL_GetFunc( PFN_GLGETNPIXELMAPFVARB_PROC, _glGetnPixelMapfvARB_, glGetnPixelMapfvARB);
GL_GetFunc( PFN_GLGETNPIXELMAPUIVARB_PROC, _glGetnPixelMapuivARB_, glGetnPixelMapuivARB);
GL_GetFunc( PFN_GLGETNPIXELMAPUSVARB_PROC, _glGetnPixelMapusvARB_, glGetnPixelMapusvARB);
GL_GetFunc( PFN_GLGETNPOLYGONSTIPPLEARB_PROC, _glGetnPolygonStippleARB_, glGetnPolygonStippleARB);
GL_GetFunc( PFN_GLGETNCOLORTABLEARB_PROC, _glGetnColorTableARB_, glGetnColorTableARB);
GL_GetFunc( PFN_GLGETNCONVOLUTIONFILTERARB_PROC, _glGetnConvolutionFilterARB_, glGetnConvolutionFilterARB);
GL_GetFunc( PFN_GLGETNSEPARABLEFILTERARB_PROC, _glGetnSeparableFilterARB_, glGetnSeparableFilterARB);
GL_GetFunc( PFN_GLGETNHISTOGRAMARB_PROC, _glGetnHistogramARB_, glGetnHistogramARB);
GL_GetFunc( PFN_GLGETNMINMAXARB_PROC, _glGetnMinmaxARB_, glGetnMinmaxARB);
#endif //GL_ARB_robustness

// GL_ARB_robustness_isolation

#ifndef GL_ARB_sample_locations
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_sample_locations\n");
GL_GetFunc( PFN_GLFRAMEBUFFERSAMPLELOCATIONSFVARB_PROC, _glFramebufferSampleLocationsfvARB_, glFramebufferSampleLocationsfvARB);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARB_PROC, _glNamedFramebufferSampleLocationsfvARB_, glNamedFramebufferSampleLocationsfvARB);
GL_GetFunc( PFN_GLEVALUATEDEPTHVALUESARB_PROC, _glEvaluateDepthValuesARB_, glEvaluateDepthValuesARB);
#endif //GL_ARB_sample_locations

#ifndef GL_ARB_sample_shading
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_sample_shading\n");
GL_GetFunc( PFN_GLMINSAMPLESHADINGARB_PROC, _glMinSampleShadingARB_, glMinSampleShadingARB);
#endif //GL_ARB_sample_shading

// GL_ARB_sampler_objects

// GL_ARB_seamless_cube_map

// GL_ARB_seamless_cubemap_per_texture

// GL_ARB_separate_shader_objects

// GL_ARB_shader_atomic_counter_ops

// GL_ARB_shader_atomic_counters

// GL_ARB_shader_ballot

// GL_ARB_shader_bit_encoding

// GL_ARB_shader_clock

// GL_ARB_shader_draw_parameters

// GL_ARB_shader_group_vote

// GL_ARB_shader_image_load_store

// GL_ARB_shader_image_size

// GL_ARB_shader_precision

// GL_ARB_shader_stencil_export

// GL_ARB_shader_storage_buffer_object

// GL_ARB_shader_subroutine

// GL_ARB_shader_texture_image_samples

// GL_ARB_shader_viewport_layer_array

// GL_ARB_shading_language_420pack

#ifndef GL_ARB_shading_language_include
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_shading_language_include\n");
GL_GetFunc( PFN_GLNAMEDSTRINGARB_PROC, _glNamedStringARB_, glNamedStringARB);
GL_GetFunc( PFN_GLDELETENAMEDSTRINGARB_PROC, _glDeleteNamedStringARB_, glDeleteNamedStringARB);
GL_GetFunc( PFN_GLCOMPILESHADERINCLUDEARB_PROC, _glCompileShaderIncludeARB_, glCompileShaderIncludeARB);
GL_GetFunc( PFN_GLISNAMEDSTRINGARB_PROC, _glIsNamedStringARB_, glIsNamedStringARB);
GL_GetFunc( PFN_GLGETNAMEDSTRINGARB_PROC, _glGetNamedStringARB_, glGetNamedStringARB);
GL_GetFunc( PFN_GLGETNAMEDSTRINGIVARB_PROC, _glGetNamedStringivARB_, glGetNamedStringivARB);
#endif //GL_ARB_shading_language_include

// GL_ARB_shading_language_packing

#ifndef GL_ARB_sparse_buffer
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_sparse_buffer\n");
GL_GetFunc( PFN_GLBUFFERPAGECOMMITMENTARB_PROC, _glBufferPageCommitmentARB_, glBufferPageCommitmentARB);
GL_GetFunc( PFN_GLNAMEDBUFFERPAGECOMMITMENTEXT_PROC, _glNamedBufferPageCommitmentEXT_, glNamedBufferPageCommitmentEXT);
GL_GetFunc( PFN_GLNAMEDBUFFERPAGECOMMITMENTARB_PROC, _glNamedBufferPageCommitmentARB_, glNamedBufferPageCommitmentARB);
#endif //GL_ARB_sparse_buffer

#ifndef GL_ARB_sparse_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_sparse_texture\n");
GL_GetFunc( PFN_GLTEXPAGECOMMITMENTARB_PROC, _glTexPageCommitmentARB_, glTexPageCommitmentARB);
#endif //GL_ARB_sparse_texture

// GL_ARB_sparse_texture2

// GL_ARB_sparse_texture_clamp

// GL_ARB_spirv_extensions

// GL_ARB_stencil_texturing

// GL_ARB_sync

// GL_ARB_tessellation_shader

// GL_ARB_texture_barrier

// GL_ARB_texture_border_clamp

#ifndef GL_ARB_texture_buffer_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_texture_buffer_object\n");
GL_GetFunc( PFN_GLTEXBUFFERARB_PROC, _glTexBufferARB_, glTexBufferARB);
#endif //GL_ARB_texture_buffer_object

// GL_ARB_texture_buffer_object_rgb32

// GL_ARB_texture_buffer_range

// GL_ARB_texture_compression_bptc

// GL_ARB_texture_compression_rgtc

// GL_ARB_texture_cube_map_array

// GL_ARB_texture_filter_anisotropic

// GL_ARB_texture_filter_minmax

// GL_ARB_texture_gather

// GL_ARB_texture_mirror_clamp_to_edge

// GL_ARB_texture_mirrored_repeat

// GL_ARB_texture_multisample

// GL_ARB_texture_non_power_of_two

// GL_ARB_texture_query_levels

// GL_ARB_texture_query_lod

// GL_ARB_texture_rg

// GL_ARB_texture_rgb10_a2ui

// GL_ARB_texture_stencil8

// GL_ARB_texture_storage

// GL_ARB_texture_storage_multisample

// GL_ARB_texture_swizzle

// GL_ARB_texture_view

// GL_ARB_timer_query

// GL_ARB_transform_feedback2

// GL_ARB_transform_feedback3

// GL_ARB_transform_feedback_instanced

// GL_ARB_transform_feedback_overflow_query

// GL_ARB_uniform_buffer_object

// GL_ARB_vertex_array_bgra

// GL_ARB_vertex_array_object

// GL_ARB_vertex_attrib_64bit

// GL_ARB_vertex_attrib_binding

// GL_ARB_vertex_type_10f_11f_11f_rev

// GL_ARB_vertex_type_2_10_10_10_rev

// GL_ARB_viewport_array

#ifndef GL_KHR_blend_equation_advanced
LOG_fprintf(LogGlGetFunctions_py, "\nGL_KHR_blend_equation_advanced\n");
GL_GetFunc( PFN_GLBLENDBARRIERKHR_PROC, _glBlendBarrierKHR_, glBlendBarrierKHR);
#endif //GL_KHR_blend_equation_advanced

// GL_KHR_blend_equation_advanced_coherent

// GL_KHR_context_flush_control

// GL_KHR_debug

// GL_KHR_no_error

#ifndef GL_KHR_parallel_shader_compile
LOG_fprintf(LogGlGetFunctions_py, "\nGL_KHR_parallel_shader_compile\n");
GL_GetFunc( PFN_GLMAXSHADERCOMPILERTHREADSKHR_PROC, _glMaxShaderCompilerThreadsKHR_, glMaxShaderCompilerThreadsKHR);
#endif //GL_KHR_parallel_shader_compile

// GL_KHR_robust_buffer_access_behavior

// GL_KHR_robustness

// GL_KHR_shader_subgroup

// GL_KHR_texture_compression_astc_hdr

// GL_KHR_texture_compression_astc_ldr

// GL_KHR_texture_compression_astc_sliced_3d

#ifndef GL_AMD_framebuffer_multisample_advanced
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_framebuffer_multisample_advanced\n");
GL_GetFunc( PFN_GLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMD_PROC, _glRenderbufferStorageMultisampleAdvancedAMD_, glRenderbufferStorageMultisampleAdvancedAMD);
GL_GetFunc( PFN_GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMD_PROC, _glNamedRenderbufferStorageMultisampleAdvancedAMD_, glNamedRenderbufferStorageMultisampleAdvancedAMD);
#endif //GL_AMD_framebuffer_multisample_advanced

#ifndef GL_AMD_performance_monitor
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_performance_monitor\n");
GL_GetFunc( PFN_GLGETPERFMONITORGROUPSAMD_PROC, _glGetPerfMonitorGroupsAMD_, glGetPerfMonitorGroupsAMD);
GL_GetFunc( PFN_GLGETPERFMONITORCOUNTERSAMD_PROC, _glGetPerfMonitorCountersAMD_, glGetPerfMonitorCountersAMD);
GL_GetFunc( PFN_GLGETPERFMONITORGROUPSTRINGAMD_PROC, _glGetPerfMonitorGroupStringAMD_, glGetPerfMonitorGroupStringAMD);
GL_GetFunc( PFN_GLGETPERFMONITORCOUNTERSTRINGAMD_PROC, _glGetPerfMonitorCounterStringAMD_, glGetPerfMonitorCounterStringAMD);
GL_GetFunc( PFN_GLGETPERFMONITORCOUNTERINFOAMD_PROC, _glGetPerfMonitorCounterInfoAMD_, glGetPerfMonitorCounterInfoAMD);
GL_GetFunc( PFN_GLGENPERFMONITORSAMD_PROC, _glGenPerfMonitorsAMD_, glGenPerfMonitorsAMD);
GL_GetFunc( PFN_GLDELETEPERFMONITORSAMD_PROC, _glDeletePerfMonitorsAMD_, glDeletePerfMonitorsAMD);
GL_GetFunc( PFN_GLSELECTPERFMONITORCOUNTERSAMD_PROC, _glSelectPerfMonitorCountersAMD_, glSelectPerfMonitorCountersAMD);
GL_GetFunc( PFN_GLBEGINPERFMONITORAMD_PROC, _glBeginPerfMonitorAMD_, glBeginPerfMonitorAMD);
GL_GetFunc( PFN_GLENDPERFMONITORAMD_PROC, _glEndPerfMonitorAMD_, glEndPerfMonitorAMD);
GL_GetFunc( PFN_GLGETPERFMONITORCOUNTERDATAAMD_PROC, _glGetPerfMonitorCounterDataAMD_, glGetPerfMonitorCounterDataAMD);
#endif //GL_AMD_performance_monitor

// GL_APPLE_rgb_422

#ifndef GL_EXT_EGL_image_storage
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_EGL_image_storage\n");
GL_GetFunc( PFN_GLEGLIMAGETARGETTEXSTORAGEEXT_PROC, _glEGLImageTargetTexStorageEXT_, glEGLImageTargetTexStorageEXT);
GL_GetFunc( PFN_GLEGLIMAGETARGETTEXTURESTORAGEEXT_PROC, _glEGLImageTargetTextureStorageEXT_, glEGLImageTargetTextureStorageEXT);
#endif //GL_EXT_EGL_image_storage

// GL_EXT_EGL_sync

#ifndef GL_EXT_debug_label
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_debug_label\n");
GL_GetFunc( PFN_GLLABELOBJECTEXT_PROC, _glLabelObjectEXT_, glLabelObjectEXT);
GL_GetFunc( PFN_GLGETOBJECTLABELEXT_PROC, _glGetObjectLabelEXT_, glGetObjectLabelEXT);
#endif //GL_EXT_debug_label

#ifndef GL_EXT_debug_marker
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_debug_marker\n");
GL_GetFunc( PFN_GLINSERTEVENTMARKEREXT_PROC, _glInsertEventMarkerEXT_, glInsertEventMarkerEXT);
GL_GetFunc( PFN_GLPUSHGROUPMARKEREXT_PROC, _glPushGroupMarkerEXT_, glPushGroupMarkerEXT);
GL_GetFunc( PFN_GLPOPGROUPMARKEREXT_PROC, _glPopGroupMarkerEXT_, glPopGroupMarkerEXT);
#endif //GL_EXT_debug_marker

#ifndef GL_EXT_direct_state_access
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_direct_state_access\n");
GL_GetFunc( PFN_GLMATRIXLOADFEXT_PROC, _glMatrixLoadfEXT_, glMatrixLoadfEXT);
GL_GetFunc( PFN_GLMATRIXLOADDEXT_PROC, _glMatrixLoaddEXT_, glMatrixLoaddEXT);
GL_GetFunc( PFN_GLMATRIXMULTFEXT_PROC, _glMatrixMultfEXT_, glMatrixMultfEXT);
GL_GetFunc( PFN_GLMATRIXMULTDEXT_PROC, _glMatrixMultdEXT_, glMatrixMultdEXT);
GL_GetFunc( PFN_GLMATRIXLOADIDENTITYEXT_PROC, _glMatrixLoadIdentityEXT_, glMatrixLoadIdentityEXT);
GL_GetFunc( PFN_GLMATRIXROTATEFEXT_PROC, _glMatrixRotatefEXT_, glMatrixRotatefEXT);
GL_GetFunc( PFN_GLMATRIXROTATEDEXT_PROC, _glMatrixRotatedEXT_, glMatrixRotatedEXT);
GL_GetFunc( PFN_GLMATRIXSCALEFEXT_PROC, _glMatrixScalefEXT_, glMatrixScalefEXT);
GL_GetFunc( PFN_GLMATRIXSCALEDEXT_PROC, _glMatrixScaledEXT_, glMatrixScaledEXT);
GL_GetFunc( PFN_GLMATRIXTRANSLATEFEXT_PROC, _glMatrixTranslatefEXT_, glMatrixTranslatefEXT);
GL_GetFunc( PFN_GLMATRIXTRANSLATEDEXT_PROC, _glMatrixTranslatedEXT_, glMatrixTranslatedEXT);
GL_GetFunc( PFN_GLMATRIXFRUSTUMEXT_PROC, _glMatrixFrustumEXT_, glMatrixFrustumEXT);
GL_GetFunc( PFN_GLMATRIXORTHOEXT_PROC, _glMatrixOrthoEXT_, glMatrixOrthoEXT);
GL_GetFunc( PFN_GLMATRIXPOPEXT_PROC, _glMatrixPopEXT_, glMatrixPopEXT);
GL_GetFunc( PFN_GLMATRIXPUSHEXT_PROC, _glMatrixPushEXT_, glMatrixPushEXT);
GL_GetFunc( PFN_GLCLIENTATTRIBDEFAULTEXT_PROC, _glClientAttribDefaultEXT_, glClientAttribDefaultEXT);
GL_GetFunc( PFN_GLPUSHCLIENTATTRIBDEFAULTEXT_PROC, _glPushClientAttribDefaultEXT_, glPushClientAttribDefaultEXT);
GL_GetFunc( PFN_GLTEXTUREPARAMETERFEXT_PROC, _glTextureParameterfEXT_, glTextureParameterfEXT);
GL_GetFunc( PFN_GLTEXTUREPARAMETERFVEXT_PROC, _glTextureParameterfvEXT_, glTextureParameterfvEXT);
GL_GetFunc( PFN_GLTEXTUREPARAMETERIEXT_PROC, _glTextureParameteriEXT_, glTextureParameteriEXT);
GL_GetFunc( PFN_GLTEXTUREPARAMETERIVEXT_PROC, _glTextureParameterivEXT_, glTextureParameterivEXT);
GL_GetFunc( PFN_GLTEXTUREIMAGE1DEXT_PROC, _glTextureImage1DEXT_, glTextureImage1DEXT);
GL_GetFunc( PFN_GLTEXTUREIMAGE2DEXT_PROC, _glTextureImage2DEXT_, glTextureImage2DEXT);
GL_GetFunc( PFN_GLTEXTURESUBIMAGE1DEXT_PROC, _glTextureSubImage1DEXT_, glTextureSubImage1DEXT);
GL_GetFunc( PFN_GLTEXTURESUBIMAGE2DEXT_PROC, _glTextureSubImage2DEXT_, glTextureSubImage2DEXT);
GL_GetFunc( PFN_GLCOPYTEXTUREIMAGE1DEXT_PROC, _glCopyTextureImage1DEXT_, glCopyTextureImage1DEXT);
GL_GetFunc( PFN_GLCOPYTEXTUREIMAGE2DEXT_PROC, _glCopyTextureImage2DEXT_, glCopyTextureImage2DEXT);
GL_GetFunc( PFN_GLCOPYTEXTURESUBIMAGE1DEXT_PROC, _glCopyTextureSubImage1DEXT_, glCopyTextureSubImage1DEXT);
GL_GetFunc( PFN_GLCOPYTEXTURESUBIMAGE2DEXT_PROC, _glCopyTextureSubImage2DEXT_, glCopyTextureSubImage2DEXT);
GL_GetFunc( PFN_GLGETTEXTUREIMAGEEXT_PROC, _glGetTextureImageEXT_, glGetTextureImageEXT);
GL_GetFunc( PFN_GLGETTEXTUREPARAMETERFVEXT_PROC, _glGetTextureParameterfvEXT_, glGetTextureParameterfvEXT);
GL_GetFunc( PFN_GLGETTEXTUREPARAMETERIVEXT_PROC, _glGetTextureParameterivEXT_, glGetTextureParameterivEXT);
GL_GetFunc( PFN_GLGETTEXTURELEVELPARAMETERFVEXT_PROC, _glGetTextureLevelParameterfvEXT_, glGetTextureLevelParameterfvEXT);
GL_GetFunc( PFN_GLGETTEXTURELEVELPARAMETERIVEXT_PROC, _glGetTextureLevelParameterivEXT_, glGetTextureLevelParameterivEXT);
GL_GetFunc( PFN_GLTEXTUREIMAGE3DEXT_PROC, _glTextureImage3DEXT_, glTextureImage3DEXT);
GL_GetFunc( PFN_GLTEXTURESUBIMAGE3DEXT_PROC, _glTextureSubImage3DEXT_, glTextureSubImage3DEXT);
GL_GetFunc( PFN_GLCOPYTEXTURESUBIMAGE3DEXT_PROC, _glCopyTextureSubImage3DEXT_, glCopyTextureSubImage3DEXT);
GL_GetFunc( PFN_GLBINDMULTITEXTUREEXT_PROC, _glBindMultiTextureEXT_, glBindMultiTextureEXT);
GL_GetFunc( PFN_GLMULTITEXCOORDPOINTEREXT_PROC, _glMultiTexCoordPointerEXT_, glMultiTexCoordPointerEXT);
GL_GetFunc( PFN_GLMULTITEXENVFEXT_PROC, _glMultiTexEnvfEXT_, glMultiTexEnvfEXT);
GL_GetFunc( PFN_GLMULTITEXENVFVEXT_PROC, _glMultiTexEnvfvEXT_, glMultiTexEnvfvEXT);
GL_GetFunc( PFN_GLMULTITEXENVIEXT_PROC, _glMultiTexEnviEXT_, glMultiTexEnviEXT);
GL_GetFunc( PFN_GLMULTITEXENVIVEXT_PROC, _glMultiTexEnvivEXT_, glMultiTexEnvivEXT);
GL_GetFunc( PFN_GLMULTITEXGENDEXT_PROC, _glMultiTexGendEXT_, glMultiTexGendEXT);
GL_GetFunc( PFN_GLMULTITEXGENDVEXT_PROC, _glMultiTexGendvEXT_, glMultiTexGendvEXT);
GL_GetFunc( PFN_GLMULTITEXGENFEXT_PROC, _glMultiTexGenfEXT_, glMultiTexGenfEXT);
GL_GetFunc( PFN_GLMULTITEXGENFVEXT_PROC, _glMultiTexGenfvEXT_, glMultiTexGenfvEXT);
GL_GetFunc( PFN_GLMULTITEXGENIEXT_PROC, _glMultiTexGeniEXT_, glMultiTexGeniEXT);
GL_GetFunc( PFN_GLMULTITEXGENIVEXT_PROC, _glMultiTexGenivEXT_, glMultiTexGenivEXT);
GL_GetFunc( PFN_GLGETMULTITEXENVFVEXT_PROC, _glGetMultiTexEnvfvEXT_, glGetMultiTexEnvfvEXT);
GL_GetFunc( PFN_GLGETMULTITEXENVIVEXT_PROC, _glGetMultiTexEnvivEXT_, glGetMultiTexEnvivEXT);
GL_GetFunc( PFN_GLGETMULTITEXGENDVEXT_PROC, _glGetMultiTexGendvEXT_, glGetMultiTexGendvEXT);
GL_GetFunc( PFN_GLGETMULTITEXGENFVEXT_PROC, _glGetMultiTexGenfvEXT_, glGetMultiTexGenfvEXT);
GL_GetFunc( PFN_GLGETMULTITEXGENIVEXT_PROC, _glGetMultiTexGenivEXT_, glGetMultiTexGenivEXT);
GL_GetFunc( PFN_GLMULTITEXPARAMETERIEXT_PROC, _glMultiTexParameteriEXT_, glMultiTexParameteriEXT);
GL_GetFunc( PFN_GLMULTITEXPARAMETERIVEXT_PROC, _glMultiTexParameterivEXT_, glMultiTexParameterivEXT);
GL_GetFunc( PFN_GLMULTITEXPARAMETERFEXT_PROC, _glMultiTexParameterfEXT_, glMultiTexParameterfEXT);
GL_GetFunc( PFN_GLMULTITEXPARAMETERFVEXT_PROC, _glMultiTexParameterfvEXT_, glMultiTexParameterfvEXT);
GL_GetFunc( PFN_GLMULTITEXIMAGE1DEXT_PROC, _glMultiTexImage1DEXT_, glMultiTexImage1DEXT);
GL_GetFunc( PFN_GLMULTITEXIMAGE2DEXT_PROC, _glMultiTexImage2DEXT_, glMultiTexImage2DEXT);
GL_GetFunc( PFN_GLMULTITEXSUBIMAGE1DEXT_PROC, _glMultiTexSubImage1DEXT_, glMultiTexSubImage1DEXT);
GL_GetFunc( PFN_GLMULTITEXSUBIMAGE2DEXT_PROC, _glMultiTexSubImage2DEXT_, glMultiTexSubImage2DEXT);
GL_GetFunc( PFN_GLCOPYMULTITEXIMAGE1DEXT_PROC, _glCopyMultiTexImage1DEXT_, glCopyMultiTexImage1DEXT);
GL_GetFunc( PFN_GLCOPYMULTITEXIMAGE2DEXT_PROC, _glCopyMultiTexImage2DEXT_, glCopyMultiTexImage2DEXT);
GL_GetFunc( PFN_GLCOPYMULTITEXSUBIMAGE1DEXT_PROC, _glCopyMultiTexSubImage1DEXT_, glCopyMultiTexSubImage1DEXT);
GL_GetFunc( PFN_GLCOPYMULTITEXSUBIMAGE2DEXT_PROC, _glCopyMultiTexSubImage2DEXT_, glCopyMultiTexSubImage2DEXT);
GL_GetFunc( PFN_GLGETMULTITEXIMAGEEXT_PROC, _glGetMultiTexImageEXT_, glGetMultiTexImageEXT);
GL_GetFunc( PFN_GLGETMULTITEXPARAMETERFVEXT_PROC, _glGetMultiTexParameterfvEXT_, glGetMultiTexParameterfvEXT);
GL_GetFunc( PFN_GLGETMULTITEXPARAMETERIVEXT_PROC, _glGetMultiTexParameterivEXT_, glGetMultiTexParameterivEXT);
GL_GetFunc( PFN_GLGETMULTITEXLEVELPARAMETERFVEXT_PROC, _glGetMultiTexLevelParameterfvEXT_, glGetMultiTexLevelParameterfvEXT);
GL_GetFunc( PFN_GLGETMULTITEXLEVELPARAMETERIVEXT_PROC, _glGetMultiTexLevelParameterivEXT_, glGetMultiTexLevelParameterivEXT);
GL_GetFunc( PFN_GLMULTITEXIMAGE3DEXT_PROC, _glMultiTexImage3DEXT_, glMultiTexImage3DEXT);
GL_GetFunc( PFN_GLMULTITEXSUBIMAGE3DEXT_PROC, _glMultiTexSubImage3DEXT_, glMultiTexSubImage3DEXT);
GL_GetFunc( PFN_GLCOPYMULTITEXSUBIMAGE3DEXT_PROC, _glCopyMultiTexSubImage3DEXT_, glCopyMultiTexSubImage3DEXT);
GL_GetFunc( PFN_GLENABLECLIENTSTATEINDEXEDEXT_PROC, _glEnableClientStateIndexedEXT_, glEnableClientStateIndexedEXT);
GL_GetFunc( PFN_GLDISABLECLIENTSTATEINDEXEDEXT_PROC, _glDisableClientStateIndexedEXT_, glDisableClientStateIndexedEXT);
GL_GetFunc( PFN_GLGETFLOATINDEXEDVEXT_PROC, _glGetFloatIndexedvEXT_, glGetFloatIndexedvEXT);
GL_GetFunc( PFN_GLGETDOUBLEINDEXEDVEXT_PROC, _glGetDoubleIndexedvEXT_, glGetDoubleIndexedvEXT);
GL_GetFunc( PFN_GLGETPOINTERINDEXEDVEXT_PROC, _glGetPointerIndexedvEXT_, glGetPointerIndexedvEXT);
GL_GetFunc( PFN_GLENABLEINDEXEDEXT_PROC, _glEnableIndexedEXT_, glEnableIndexedEXT);
GL_GetFunc( PFN_GLDISABLEINDEXEDEXT_PROC, _glDisableIndexedEXT_, glDisableIndexedEXT);
GL_GetFunc( PFN_GLISENABLEDINDEXEDEXT_PROC, _glIsEnabledIndexedEXT_, glIsEnabledIndexedEXT);
GL_GetFunc( PFN_GLGETINTEGERINDEXEDVEXT_PROC, _glGetIntegerIndexedvEXT_, glGetIntegerIndexedvEXT);
GL_GetFunc( PFN_GLGETBOOLEANINDEXEDVEXT_PROC, _glGetBooleanIndexedvEXT_, glGetBooleanIndexedvEXT);
GL_GetFunc( PFN_GLCOMPRESSEDTEXTUREIMAGE3DEXT_PROC, _glCompressedTextureImage3DEXT_, glCompressedTextureImage3DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDTEXTUREIMAGE2DEXT_PROC, _glCompressedTextureImage2DEXT_, glCompressedTextureImage2DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDTEXTUREIMAGE1DEXT_PROC, _glCompressedTextureImage1DEXT_, glCompressedTextureImage1DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDTEXTURESUBIMAGE3DEXT_PROC, _glCompressedTextureSubImage3DEXT_, glCompressedTextureSubImage3DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDTEXTURESUBIMAGE2DEXT_PROC, _glCompressedTextureSubImage2DEXT_, glCompressedTextureSubImage2DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDTEXTURESUBIMAGE1DEXT_PROC, _glCompressedTextureSubImage1DEXT_, glCompressedTextureSubImage1DEXT);
GL_GetFunc( PFN_GLGETCOMPRESSEDTEXTUREIMAGEEXT_PROC, _glGetCompressedTextureImageEXT_, glGetCompressedTextureImageEXT);
GL_GetFunc( PFN_GLCOMPRESSEDMULTITEXIMAGE3DEXT_PROC, _glCompressedMultiTexImage3DEXT_, glCompressedMultiTexImage3DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDMULTITEXIMAGE2DEXT_PROC, _glCompressedMultiTexImage2DEXT_, glCompressedMultiTexImage2DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDMULTITEXIMAGE1DEXT_PROC, _glCompressedMultiTexImage1DEXT_, glCompressedMultiTexImage1DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDMULTITEXSUBIMAGE3DEXT_PROC, _glCompressedMultiTexSubImage3DEXT_, glCompressedMultiTexSubImage3DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDMULTITEXSUBIMAGE2DEXT_PROC, _glCompressedMultiTexSubImage2DEXT_, glCompressedMultiTexSubImage2DEXT);
GL_GetFunc( PFN_GLCOMPRESSEDMULTITEXSUBIMAGE1DEXT_PROC, _glCompressedMultiTexSubImage1DEXT_, glCompressedMultiTexSubImage1DEXT);
GL_GetFunc( PFN_GLGETCOMPRESSEDMULTITEXIMAGEEXT_PROC, _glGetCompressedMultiTexImageEXT_, glGetCompressedMultiTexImageEXT);
GL_GetFunc( PFN_GLMATRIXLOADTRANSPOSEFEXT_PROC, _glMatrixLoadTransposefEXT_, glMatrixLoadTransposefEXT);
GL_GetFunc( PFN_GLMATRIXLOADTRANSPOSEDEXT_PROC, _glMatrixLoadTransposedEXT_, glMatrixLoadTransposedEXT);
GL_GetFunc( PFN_GLMATRIXMULTTRANSPOSEFEXT_PROC, _glMatrixMultTransposefEXT_, glMatrixMultTransposefEXT);
GL_GetFunc( PFN_GLMATRIXMULTTRANSPOSEDEXT_PROC, _glMatrixMultTransposedEXT_, glMatrixMultTransposedEXT);
GL_GetFunc( PFN_GLNAMEDBUFFERDATAEXT_PROC, _glNamedBufferDataEXT_, glNamedBufferDataEXT);
GL_GetFunc( PFN_GLNAMEDBUFFERSUBDATAEXT_PROC, _glNamedBufferSubDataEXT_, glNamedBufferSubDataEXT);
GL_GetFunc( PFN_GLMAPNAMEDBUFFEREXT_PROC, _glMapNamedBufferEXT_, glMapNamedBufferEXT);
GL_GetFunc( PFN_GLUNMAPNAMEDBUFFEREXT_PROC, _glUnmapNamedBufferEXT_, glUnmapNamedBufferEXT);
GL_GetFunc( PFN_GLGETNAMEDBUFFERPARAMETERIVEXT_PROC, _glGetNamedBufferParameterivEXT_, glGetNamedBufferParameterivEXT);
GL_GetFunc( PFN_GLGETNAMEDBUFFERPOINTERVEXT_PROC, _glGetNamedBufferPointervEXT_, glGetNamedBufferPointervEXT);
GL_GetFunc( PFN_GLGETNAMEDBUFFERSUBDATAEXT_PROC, _glGetNamedBufferSubDataEXT_, glGetNamedBufferSubDataEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1FEXT_PROC, _glProgramUniform1fEXT_, glProgramUniform1fEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2FEXT_PROC, _glProgramUniform2fEXT_, glProgramUniform2fEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3FEXT_PROC, _glProgramUniform3fEXT_, glProgramUniform3fEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4FEXT_PROC, _glProgramUniform4fEXT_, glProgramUniform4fEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1IEXT_PROC, _glProgramUniform1iEXT_, glProgramUniform1iEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2IEXT_PROC, _glProgramUniform2iEXT_, glProgramUniform2iEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3IEXT_PROC, _glProgramUniform3iEXT_, glProgramUniform3iEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4IEXT_PROC, _glProgramUniform4iEXT_, glProgramUniform4iEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1FVEXT_PROC, _glProgramUniform1fvEXT_, glProgramUniform1fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2FVEXT_PROC, _glProgramUniform2fvEXT_, glProgramUniform2fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3FVEXT_PROC, _glProgramUniform3fvEXT_, glProgramUniform3fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4FVEXT_PROC, _glProgramUniform4fvEXT_, glProgramUniform4fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1IVEXT_PROC, _glProgramUniform1ivEXT_, glProgramUniform1ivEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2IVEXT_PROC, _glProgramUniform2ivEXT_, glProgramUniform2ivEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3IVEXT_PROC, _glProgramUniform3ivEXT_, glProgramUniform3ivEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4IVEXT_PROC, _glProgramUniform4ivEXT_, glProgramUniform4ivEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2FVEXT_PROC, _glProgramUniformMatrix2fvEXT_, glProgramUniformMatrix2fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3FVEXT_PROC, _glProgramUniformMatrix3fvEXT_, glProgramUniformMatrix3fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4FVEXT_PROC, _glProgramUniformMatrix4fvEXT_, glProgramUniformMatrix4fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2X3FVEXT_PROC, _glProgramUniformMatrix2x3fvEXT_, glProgramUniformMatrix2x3fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3X2FVEXT_PROC, _glProgramUniformMatrix3x2fvEXT_, glProgramUniformMatrix3x2fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2X4FVEXT_PROC, _glProgramUniformMatrix2x4fvEXT_, glProgramUniformMatrix2x4fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4X2FVEXT_PROC, _glProgramUniformMatrix4x2fvEXT_, glProgramUniformMatrix4x2fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3X4FVEXT_PROC, _glProgramUniformMatrix3x4fvEXT_, glProgramUniformMatrix3x4fvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4X3FVEXT_PROC, _glProgramUniformMatrix4x3fvEXT_, glProgramUniformMatrix4x3fvEXT);
GL_GetFunc( PFN_GLTEXTUREBUFFEREXT_PROC, _glTextureBufferEXT_, glTextureBufferEXT);
GL_GetFunc( PFN_GLMULTITEXBUFFEREXT_PROC, _glMultiTexBufferEXT_, glMultiTexBufferEXT);
GL_GetFunc( PFN_GLTEXTUREPARAMETERIIVEXT_PROC, _glTextureParameterIivEXT_, glTextureParameterIivEXT);
GL_GetFunc( PFN_GLTEXTUREPARAMETERIUIVEXT_PROC, _glTextureParameterIuivEXT_, glTextureParameterIuivEXT);
GL_GetFunc( PFN_GLGETTEXTUREPARAMETERIIVEXT_PROC, _glGetTextureParameterIivEXT_, glGetTextureParameterIivEXT);
GL_GetFunc( PFN_GLGETTEXTUREPARAMETERIUIVEXT_PROC, _glGetTextureParameterIuivEXT_, glGetTextureParameterIuivEXT);
GL_GetFunc( PFN_GLMULTITEXPARAMETERIIVEXT_PROC, _glMultiTexParameterIivEXT_, glMultiTexParameterIivEXT);
GL_GetFunc( PFN_GLMULTITEXPARAMETERIUIVEXT_PROC, _glMultiTexParameterIuivEXT_, glMultiTexParameterIuivEXT);
GL_GetFunc( PFN_GLGETMULTITEXPARAMETERIIVEXT_PROC, _glGetMultiTexParameterIivEXT_, glGetMultiTexParameterIivEXT);
GL_GetFunc( PFN_GLGETMULTITEXPARAMETERIUIVEXT_PROC, _glGetMultiTexParameterIuivEXT_, glGetMultiTexParameterIuivEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1UIEXT_PROC, _glProgramUniform1uiEXT_, glProgramUniform1uiEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2UIEXT_PROC, _glProgramUniform2uiEXT_, glProgramUniform2uiEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3UIEXT_PROC, _glProgramUniform3uiEXT_, glProgramUniform3uiEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4UIEXT_PROC, _glProgramUniform4uiEXT_, glProgramUniform4uiEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1UIVEXT_PROC, _glProgramUniform1uivEXT_, glProgramUniform1uivEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2UIVEXT_PROC, _glProgramUniform2uivEXT_, glProgramUniform2uivEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3UIVEXT_PROC, _glProgramUniform3uivEXT_, glProgramUniform3uivEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4UIVEXT_PROC, _glProgramUniform4uivEXT_, glProgramUniform4uivEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETERS4FVEXT_PROC, _glNamedProgramLocalParameters4fvEXT_, glNamedProgramLocalParameters4fvEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETERI4IEXT_PROC, _glNamedProgramLocalParameterI4iEXT_, glNamedProgramLocalParameterI4iEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETERI4IVEXT_PROC, _glNamedProgramLocalParameterI4ivEXT_, glNamedProgramLocalParameterI4ivEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETERSI4IVEXT_PROC, _glNamedProgramLocalParametersI4ivEXT_, glNamedProgramLocalParametersI4ivEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETERI4UIEXT_PROC, _glNamedProgramLocalParameterI4uiEXT_, glNamedProgramLocalParameterI4uiEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETERI4UIVEXT_PROC, _glNamedProgramLocalParameterI4uivEXT_, glNamedProgramLocalParameterI4uivEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXT_PROC, _glNamedProgramLocalParametersI4uivEXT_, glNamedProgramLocalParametersI4uivEXT);
GL_GetFunc( PFN_GLGETNAMEDPROGRAMLOCALPARAMETERIIVEXT_PROC, _glGetNamedProgramLocalParameterIivEXT_, glGetNamedProgramLocalParameterIivEXT);
GL_GetFunc( PFN_GLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXT_PROC, _glGetNamedProgramLocalParameterIuivEXT_, glGetNamedProgramLocalParameterIuivEXT);
GL_GetFunc( PFN_GLENABLECLIENTSTATEIEXT_PROC, _glEnableClientStateiEXT_, glEnableClientStateiEXT);
GL_GetFunc( PFN_GLDISABLECLIENTSTATEIEXT_PROC, _glDisableClientStateiEXT_, glDisableClientStateiEXT);
GL_GetFunc( PFN_GLGETFLOATI_VEXT_PROC, _glGetFloati_vEXT_, glGetFloati_vEXT);
GL_GetFunc( PFN_GLGETDOUBLEI_VEXT_PROC, _glGetDoublei_vEXT_, glGetDoublei_vEXT);
GL_GetFunc( PFN_GLGETPOINTERI_VEXT_PROC, _glGetPointeri_vEXT_, glGetPointeri_vEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMSTRINGEXT_PROC, _glNamedProgramStringEXT_, glNamedProgramStringEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETER4DEXT_PROC, _glNamedProgramLocalParameter4dEXT_, glNamedProgramLocalParameter4dEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETER4DVEXT_PROC, _glNamedProgramLocalParameter4dvEXT_, glNamedProgramLocalParameter4dvEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETER4FEXT_PROC, _glNamedProgramLocalParameter4fEXT_, glNamedProgramLocalParameter4fEXT);
GL_GetFunc( PFN_GLNAMEDPROGRAMLOCALPARAMETER4FVEXT_PROC, _glNamedProgramLocalParameter4fvEXT_, glNamedProgramLocalParameter4fvEXT);
GL_GetFunc( PFN_GLGETNAMEDPROGRAMLOCALPARAMETERDVEXT_PROC, _glGetNamedProgramLocalParameterdvEXT_, glGetNamedProgramLocalParameterdvEXT);
GL_GetFunc( PFN_GLGETNAMEDPROGRAMLOCALPARAMETERFVEXT_PROC, _glGetNamedProgramLocalParameterfvEXT_, glGetNamedProgramLocalParameterfvEXT);
GL_GetFunc( PFN_GLGETNAMEDPROGRAMIVEXT_PROC, _glGetNamedProgramivEXT_, glGetNamedProgramivEXT);
GL_GetFunc( PFN_GLGETNAMEDPROGRAMSTRINGEXT_PROC, _glGetNamedProgramStringEXT_, glGetNamedProgramStringEXT);
GL_GetFunc( PFN_GLNAMEDRENDERBUFFERSTORAGEEXT_PROC, _glNamedRenderbufferStorageEXT_, glNamedRenderbufferStorageEXT);
GL_GetFunc( PFN_GLGETNAMEDRENDERBUFFERPARAMETERIVEXT_PROC, _glGetNamedRenderbufferParameterivEXT_, glGetNamedRenderbufferParameterivEXT);
GL_GetFunc( PFN_GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXT_PROC, _glNamedRenderbufferStorageMultisampleEXT_, glNamedRenderbufferStorageMultisampleEXT);
GL_GetFunc( PFN_GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXT_PROC, _glNamedRenderbufferStorageMultisampleCoverageEXT_, glNamedRenderbufferStorageMultisampleCoverageEXT);
GL_GetFunc( PFN_GLCHECKNAMEDFRAMEBUFFERSTATUSEXT_PROC, _glCheckNamedFramebufferStatusEXT_, glCheckNamedFramebufferStatusEXT);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERTEXTURE1DEXT_PROC, _glNamedFramebufferTexture1DEXT_, glNamedFramebufferTexture1DEXT);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERTEXTURE2DEXT_PROC, _glNamedFramebufferTexture2DEXT_, glNamedFramebufferTexture2DEXT);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERTEXTURE3DEXT_PROC, _glNamedFramebufferTexture3DEXT_, glNamedFramebufferTexture3DEXT);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERRENDERBUFFEREXT_PROC, _glNamedFramebufferRenderbufferEXT_, glNamedFramebufferRenderbufferEXT);
GL_GetFunc( PFN_GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXT_PROC, _glGetNamedFramebufferAttachmentParameterivEXT_, glGetNamedFramebufferAttachmentParameterivEXT);
GL_GetFunc( PFN_GLGENERATETEXTUREMIPMAPEXT_PROC, _glGenerateTextureMipmapEXT_, glGenerateTextureMipmapEXT);
GL_GetFunc( PFN_GLGENERATEMULTITEXMIPMAPEXT_PROC, _glGenerateMultiTexMipmapEXT_, glGenerateMultiTexMipmapEXT);
GL_GetFunc( PFN_GLFRAMEBUFFERDRAWBUFFEREXT_PROC, _glFramebufferDrawBufferEXT_, glFramebufferDrawBufferEXT);
GL_GetFunc( PFN_GLFRAMEBUFFERDRAWBUFFERSEXT_PROC, _glFramebufferDrawBuffersEXT_, glFramebufferDrawBuffersEXT);
GL_GetFunc( PFN_GLFRAMEBUFFERREADBUFFEREXT_PROC, _glFramebufferReadBufferEXT_, glFramebufferReadBufferEXT);
GL_GetFunc( PFN_GLGETFRAMEBUFFERPARAMETERIVEXT_PROC, _glGetFramebufferParameterivEXT_, glGetFramebufferParameterivEXT);
GL_GetFunc( PFN_GLNAMEDCOPYBUFFERSUBDATAEXT_PROC, _glNamedCopyBufferSubDataEXT_, glNamedCopyBufferSubDataEXT);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERTEXTUREEXT_PROC, _glNamedFramebufferTextureEXT_, glNamedFramebufferTextureEXT);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERTEXTURELAYEREXT_PROC, _glNamedFramebufferTextureLayerEXT_, glNamedFramebufferTextureLayerEXT);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERTEXTUREFACEEXT_PROC, _glNamedFramebufferTextureFaceEXT_, glNamedFramebufferTextureFaceEXT);
GL_GetFunc( PFN_GLTEXTURERENDERBUFFEREXT_PROC, _glTextureRenderbufferEXT_, glTextureRenderbufferEXT);
GL_GetFunc( PFN_GLMULTITEXRENDERBUFFEREXT_PROC, _glMultiTexRenderbufferEXT_, glMultiTexRenderbufferEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXOFFSETEXT_PROC, _glVertexArrayVertexOffsetEXT_, glVertexArrayVertexOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYCOLOROFFSETEXT_PROC, _glVertexArrayColorOffsetEXT_, glVertexArrayColorOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYEDGEFLAGOFFSETEXT_PROC, _glVertexArrayEdgeFlagOffsetEXT_, glVertexArrayEdgeFlagOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYINDEXOFFSETEXT_PROC, _glVertexArrayIndexOffsetEXT_, glVertexArrayIndexOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYNORMALOFFSETEXT_PROC, _glVertexArrayNormalOffsetEXT_, glVertexArrayNormalOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYTEXCOORDOFFSETEXT_PROC, _glVertexArrayTexCoordOffsetEXT_, glVertexArrayTexCoordOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYMULTITEXCOORDOFFSETEXT_PROC, _glVertexArrayMultiTexCoordOffsetEXT_, glVertexArrayMultiTexCoordOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYFOGCOORDOFFSETEXT_PROC, _glVertexArrayFogCoordOffsetEXT_, glVertexArrayFogCoordOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYSECONDARYCOLOROFFSETEXT_PROC, _glVertexArraySecondaryColorOffsetEXT_, glVertexArraySecondaryColorOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXATTRIBOFFSETEXT_PROC, _glVertexArrayVertexAttribOffsetEXT_, glVertexArrayVertexAttribOffsetEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXATTRIBIOFFSETEXT_PROC, _glVertexArrayVertexAttribIOffsetEXT_, glVertexArrayVertexAttribIOffsetEXT);
GL_GetFunc( PFN_GLENABLEVERTEXARRAYEXT_PROC, _glEnableVertexArrayEXT_, glEnableVertexArrayEXT);
GL_GetFunc( PFN_GLDISABLEVERTEXARRAYEXT_PROC, _glDisableVertexArrayEXT_, glDisableVertexArrayEXT);
GL_GetFunc( PFN_GLENABLEVERTEXARRAYATTRIBEXT_PROC, _glEnableVertexArrayAttribEXT_, glEnableVertexArrayAttribEXT);
GL_GetFunc( PFN_GLDISABLEVERTEXARRAYATTRIBEXT_PROC, _glDisableVertexArrayAttribEXT_, glDisableVertexArrayAttribEXT);
GL_GetFunc( PFN_GLGETVERTEXARRAYINTEGERVEXT_PROC, _glGetVertexArrayIntegervEXT_, glGetVertexArrayIntegervEXT);
GL_GetFunc( PFN_GLGETVERTEXARRAYPOINTERVEXT_PROC, _glGetVertexArrayPointervEXT_, glGetVertexArrayPointervEXT);
GL_GetFunc( PFN_GLGETVERTEXARRAYINTEGERI_VEXT_PROC, _glGetVertexArrayIntegeri_vEXT_, glGetVertexArrayIntegeri_vEXT);
GL_GetFunc( PFN_GLGETVERTEXARRAYPOINTERI_VEXT_PROC, _glGetVertexArrayPointeri_vEXT_, glGetVertexArrayPointeri_vEXT);
GL_GetFunc( PFN_GLMAPNAMEDBUFFERRANGEEXT_PROC, _glMapNamedBufferRangeEXT_, glMapNamedBufferRangeEXT);
GL_GetFunc( PFN_GLFLUSHMAPPEDNAMEDBUFFERRANGEEXT_PROC, _glFlushMappedNamedBufferRangeEXT_, glFlushMappedNamedBufferRangeEXT);
GL_GetFunc( PFN_GLNAMEDBUFFERSTORAGEEXT_PROC, _glNamedBufferStorageEXT_, glNamedBufferStorageEXT);
GL_GetFunc( PFN_GLCLEARNAMEDBUFFERDATAEXT_PROC, _glClearNamedBufferDataEXT_, glClearNamedBufferDataEXT);
GL_GetFunc( PFN_GLCLEARNAMEDBUFFERSUBDATAEXT_PROC, _glClearNamedBufferSubDataEXT_, glClearNamedBufferSubDataEXT);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERPARAMETERIEXT_PROC, _glNamedFramebufferParameteriEXT_, glNamedFramebufferParameteriEXT);
GL_GetFunc( PFN_GLGETNAMEDFRAMEBUFFERPARAMETERIVEXT_PROC, _glGetNamedFramebufferParameterivEXT_, glGetNamedFramebufferParameterivEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1DEXT_PROC, _glProgramUniform1dEXT_, glProgramUniform1dEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2DEXT_PROC, _glProgramUniform2dEXT_, glProgramUniform2dEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3DEXT_PROC, _glProgramUniform3dEXT_, glProgramUniform3dEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4DEXT_PROC, _glProgramUniform4dEXT_, glProgramUniform4dEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1DVEXT_PROC, _glProgramUniform1dvEXT_, glProgramUniform1dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2DVEXT_PROC, _glProgramUniform2dvEXT_, glProgramUniform2dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3DVEXT_PROC, _glProgramUniform3dvEXT_, glProgramUniform3dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4DVEXT_PROC, _glProgramUniform4dvEXT_, glProgramUniform4dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2DVEXT_PROC, _glProgramUniformMatrix2dvEXT_, glProgramUniformMatrix2dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3DVEXT_PROC, _glProgramUniformMatrix3dvEXT_, glProgramUniformMatrix3dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4DVEXT_PROC, _glProgramUniformMatrix4dvEXT_, glProgramUniformMatrix4dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2X3DVEXT_PROC, _glProgramUniformMatrix2x3dvEXT_, glProgramUniformMatrix2x3dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX2X4DVEXT_PROC, _glProgramUniformMatrix2x4dvEXT_, glProgramUniformMatrix2x4dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3X2DVEXT_PROC, _glProgramUniformMatrix3x2dvEXT_, glProgramUniformMatrix3x2dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX3X4DVEXT_PROC, _glProgramUniformMatrix3x4dvEXT_, glProgramUniformMatrix3x4dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4X2DVEXT_PROC, _glProgramUniformMatrix4x2dvEXT_, glProgramUniformMatrix4x2dvEXT);
GL_GetFunc( PFN_GLPROGRAMUNIFORMMATRIX4X3DVEXT_PROC, _glProgramUniformMatrix4x3dvEXT_, glProgramUniformMatrix4x3dvEXT);
GL_GetFunc( PFN_GLTEXTUREBUFFERRANGEEXT_PROC, _glTextureBufferRangeEXT_, glTextureBufferRangeEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGE1DEXT_PROC, _glTextureStorage1DEXT_, glTextureStorage1DEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGE2DEXT_PROC, _glTextureStorage2DEXT_, glTextureStorage2DEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGE3DEXT_PROC, _glTextureStorage3DEXT_, glTextureStorage3DEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGE2DMULTISAMPLEEXT_PROC, _glTextureStorage2DMultisampleEXT_, glTextureStorage2DMultisampleEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGE3DMULTISAMPLEEXT_PROC, _glTextureStorage3DMultisampleEXT_, glTextureStorage3DMultisampleEXT);
GL_GetFunc( PFN_GLVERTEXARRAYBINDVERTEXBUFFEREXT_PROC, _glVertexArrayBindVertexBufferEXT_, glVertexArrayBindVertexBufferEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXATTRIBFORMATEXT_PROC, _glVertexArrayVertexAttribFormatEXT_, glVertexArrayVertexAttribFormatEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXATTRIBIFORMATEXT_PROC, _glVertexArrayVertexAttribIFormatEXT_, glVertexArrayVertexAttribIFormatEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXATTRIBLFORMATEXT_PROC, _glVertexArrayVertexAttribLFormatEXT_, glVertexArrayVertexAttribLFormatEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXATTRIBBINDINGEXT_PROC, _glVertexArrayVertexAttribBindingEXT_, glVertexArrayVertexAttribBindingEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXBINDINGDIVISOREXT_PROC, _glVertexArrayVertexBindingDivisorEXT_, glVertexArrayVertexBindingDivisorEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXATTRIBLOFFSETEXT_PROC, _glVertexArrayVertexAttribLOffsetEXT_, glVertexArrayVertexAttribLOffsetEXT);
GL_GetFunc( PFN_GLTEXTUREPAGECOMMITMENTEXT_PROC, _glTexturePageCommitmentEXT_, glTexturePageCommitmentEXT);
GL_GetFunc( PFN_GLVERTEXARRAYVERTEXATTRIBDIVISOREXT_PROC, _glVertexArrayVertexAttribDivisorEXT_, glVertexArrayVertexAttribDivisorEXT);
#endif //GL_EXT_direct_state_access

#ifndef GL_EXT_draw_instanced
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_draw_instanced\n");
GL_GetFunc( PFN_GLDRAWARRAYSINSTANCEDEXT_PROC, _glDrawArraysInstancedEXT_, glDrawArraysInstancedEXT);
GL_GetFunc( PFN_GLDRAWELEMENTSINSTANCEDEXT_PROC, _glDrawElementsInstancedEXT_, glDrawElementsInstancedEXT);
#endif //GL_EXT_draw_instanced

// GL_EXT_multiview_tessellation_geometry_shader

// GL_EXT_multiview_texture_multisample

// GL_EXT_multiview_timer_query

#ifndef GL_EXT_polygon_offset_clamp
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_polygon_offset_clamp\n");
GL_GetFunc( PFN_GLPOLYGONOFFSETCLAMPEXT_PROC, _glPolygonOffsetClampEXT_, glPolygonOffsetClampEXT);
#endif //GL_EXT_polygon_offset_clamp

// GL_EXT_post_depth_coverage

#ifndef GL_EXT_raster_multisample
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_raster_multisample\n");
GL_GetFunc( PFN_GLRASTERSAMPLESEXT_PROC, _glRasterSamplesEXT_, glRasterSamplesEXT);
#endif //GL_EXT_raster_multisample

#ifndef GL_EXT_separate_shader_objects
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_separate_shader_objects\n");
GL_GetFunc( PFN_GLUSESHADERPROGRAMEXT_PROC, _glUseShaderProgramEXT_, glUseShaderProgramEXT);
GL_GetFunc( PFN_GLACTIVEPROGRAMEXT_PROC, _glActiveProgramEXT_, glActiveProgramEXT);
GL_GetFunc( PFN_GLCREATESHADERPROGRAMEXT_PROC, _glCreateShaderProgramEXT_, glCreateShaderProgramEXT);
#endif //GL_EXT_separate_shader_objects

// GL_EXT_shader_framebuffer_fetch

#ifndef GL_EXT_shader_framebuffer_fetch_non_coherent
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_shader_framebuffer_fetch_non_coherent\n");
GL_GetFunc( PFN_GLFRAMEBUFFERFETCHBARRIEREXT_PROC, _glFramebufferFetchBarrierEXT_, glFramebufferFetchBarrierEXT);
#endif //GL_EXT_shader_framebuffer_fetch_non_coherent

// GL_EXT_shader_integer_mix

// GL_EXT_texture_compression_s3tc

// GL_EXT_texture_filter_minmax

// GL_EXT_texture_sRGB_R8

// GL_EXT_texture_sRGB_decode

// GL_EXT_texture_shadow_lod

#ifndef GL_EXT_window_rectangles
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_window_rectangles\n");
GL_GetFunc( PFN_GLWINDOWRECTANGLESEXT_PROC, _glWindowRectanglesEXT_, glWindowRectanglesEXT);
#endif //GL_EXT_window_rectangles

// GL_INTEL_blackhole_render

// GL_INTEL_conservative_rasterization

#ifndef GL_INTEL_framebuffer_CMAA
LOG_fprintf(LogGlGetFunctions_py, "\nGL_INTEL_framebuffer_CMAA\n");
GL_GetFunc( PFN_GLAPPLYFRAMEBUFFERATTACHMENTCMAAINTEL_PROC, _glApplyFramebufferAttachmentCMAAINTEL_, glApplyFramebufferAttachmentCMAAINTEL);
#endif //GL_INTEL_framebuffer_CMAA

#ifndef GL_INTEL_performance_query
LOG_fprintf(LogGlGetFunctions_py, "\nGL_INTEL_performance_query\n");
GL_GetFunc( PFN_GLBEGINPERFQUERYINTEL_PROC, _glBeginPerfQueryINTEL_, glBeginPerfQueryINTEL);
GL_GetFunc( PFN_GLCREATEPERFQUERYINTEL_PROC, _glCreatePerfQueryINTEL_, glCreatePerfQueryINTEL);
GL_GetFunc( PFN_GLDELETEPERFQUERYINTEL_PROC, _glDeletePerfQueryINTEL_, glDeletePerfQueryINTEL);
GL_GetFunc( PFN_GLENDPERFQUERYINTEL_PROC, _glEndPerfQueryINTEL_, glEndPerfQueryINTEL);
GL_GetFunc( PFN_GLGETFIRSTPERFQUERYIDINTEL_PROC, _glGetFirstPerfQueryIdINTEL_, glGetFirstPerfQueryIdINTEL);
GL_GetFunc( PFN_GLGETNEXTPERFQUERYIDINTEL_PROC, _glGetNextPerfQueryIdINTEL_, glGetNextPerfQueryIdINTEL);
GL_GetFunc( PFN_GLGETPERFCOUNTERINFOINTEL_PROC, _glGetPerfCounterInfoINTEL_, glGetPerfCounterInfoINTEL);
GL_GetFunc( PFN_GLGETPERFQUERYDATAINTEL_PROC, _glGetPerfQueryDataINTEL_, glGetPerfQueryDataINTEL);
GL_GetFunc( PFN_GLGETPERFQUERYIDBYNAMEINTEL_PROC, _glGetPerfQueryIdByNameINTEL_, glGetPerfQueryIdByNameINTEL);
GL_GetFunc( PFN_GLGETPERFQUERYINFOINTEL_PROC, _glGetPerfQueryInfoINTEL_, glGetPerfQueryInfoINTEL);
#endif //GL_INTEL_performance_query

#ifndef GL_MESA_framebuffer_flip_y
LOG_fprintf(LogGlGetFunctions_py, "\nGL_MESA_framebuffer_flip_y\n");
GL_GetFunc( PFN_GLFRAMEBUFFERPARAMETERIMESA_PROC, _glFramebufferParameteriMESA_, glFramebufferParameteriMESA);
GL_GetFunc( PFN_GLGETFRAMEBUFFERPARAMETERIVMESA_PROC, _glGetFramebufferParameterivMESA_, glGetFramebufferParameterivMESA);
#endif //GL_MESA_framebuffer_flip_y

#ifndef GL_NV_bindless_multi_draw_indirect
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_bindless_multi_draw_indirect\n");
GL_GetFunc( PFN_GLMULTIDRAWARRAYSINDIRECTBINDLESSNV_PROC, _glMultiDrawArraysIndirectBindlessNV_, glMultiDrawArraysIndirectBindlessNV);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTSINDIRECTBINDLESSNV_PROC, _glMultiDrawElementsIndirectBindlessNV_, glMultiDrawElementsIndirectBindlessNV);
#endif //GL_NV_bindless_multi_draw_indirect

#ifndef GL_NV_bindless_multi_draw_indirect_count
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_bindless_multi_draw_indirect_count\n");
GL_GetFunc( PFN_GLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNV_PROC, _glMultiDrawArraysIndirectBindlessCountNV_, glMultiDrawArraysIndirectBindlessCountNV);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNV_PROC, _glMultiDrawElementsIndirectBindlessCountNV_, glMultiDrawElementsIndirectBindlessCountNV);
#endif //GL_NV_bindless_multi_draw_indirect_count

#ifndef GL_NV_bindless_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_bindless_texture\n");
GL_GetFunc( PFN_GLGETTEXTUREHANDLENV_PROC, _glGetTextureHandleNV_, glGetTextureHandleNV);
GL_GetFunc( PFN_GLGETTEXTURESAMPLERHANDLENV_PROC, _glGetTextureSamplerHandleNV_, glGetTextureSamplerHandleNV);
GL_GetFunc( PFN_GLMAKETEXTUREHANDLERESIDENTNV_PROC, _glMakeTextureHandleResidentNV_, glMakeTextureHandleResidentNV);
GL_GetFunc( PFN_GLMAKETEXTUREHANDLENONRESIDENTNV_PROC, _glMakeTextureHandleNonResidentNV_, glMakeTextureHandleNonResidentNV);
GL_GetFunc( PFN_GLGETIMAGEHANDLENV_PROC, _glGetImageHandleNV_, glGetImageHandleNV);
GL_GetFunc( PFN_GLMAKEIMAGEHANDLERESIDENTNV_PROC, _glMakeImageHandleResidentNV_, glMakeImageHandleResidentNV);
GL_GetFunc( PFN_GLMAKEIMAGEHANDLENONRESIDENTNV_PROC, _glMakeImageHandleNonResidentNV_, glMakeImageHandleNonResidentNV);
GL_GetFunc( PFN_GLUNIFORMHANDLEUI64NV_PROC, _glUniformHandleui64NV_, glUniformHandleui64NV);
GL_GetFunc( PFN_GLUNIFORMHANDLEUI64VNV_PROC, _glUniformHandleui64vNV_, glUniformHandleui64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORMHANDLEUI64NV_PROC, _glProgramUniformHandleui64NV_, glProgramUniformHandleui64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORMHANDLEUI64VNV_PROC, _glProgramUniformHandleui64vNV_, glProgramUniformHandleui64vNV);
GL_GetFunc( PFN_GLISTEXTUREHANDLERESIDENTNV_PROC, _glIsTextureHandleResidentNV_, glIsTextureHandleResidentNV);
GL_GetFunc( PFN_GLISIMAGEHANDLERESIDENTNV_PROC, _glIsImageHandleResidentNV_, glIsImageHandleResidentNV);
#endif //GL_NV_bindless_texture

#ifndef GL_NV_blend_equation_advanced
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_blend_equation_advanced\n");
GL_GetFunc( PFN_GLBLENDPARAMETERINV_PROC, _glBlendParameteriNV_, glBlendParameteriNV);
GL_GetFunc( PFN_GLBLENDBARRIERNV_PROC, _glBlendBarrierNV_, glBlendBarrierNV);
#endif //GL_NV_blend_equation_advanced

// GL_NV_blend_equation_advanced_coherent

// GL_NV_blend_minmax_factor

#ifndef GL_NV_clip_space_w_scaling
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_clip_space_w_scaling\n");
GL_GetFunc( PFN_GLVIEWPORTPOSITIONWSCALENV_PROC, _glViewportPositionWScaleNV_, glViewportPositionWScaleNV);
#endif //GL_NV_clip_space_w_scaling

#ifndef GL_NV_command_list
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_command_list\n");
GL_GetFunc( PFN_GLCREATESTATESNV_PROC, _glCreateStatesNV_, glCreateStatesNV);
GL_GetFunc( PFN_GLDELETESTATESNV_PROC, _glDeleteStatesNV_, glDeleteStatesNV);
GL_GetFunc( PFN_GLISSTATENV_PROC, _glIsStateNV_, glIsStateNV);
GL_GetFunc( PFN_GLSTATECAPTURENV_PROC, _glStateCaptureNV_, glStateCaptureNV);
GL_GetFunc( PFN_GLGETCOMMANDHEADERNV_PROC, _glGetCommandHeaderNV_, glGetCommandHeaderNV);
GL_GetFunc( PFN_GLGETSTAGEINDEXNV_PROC, _glGetStageIndexNV_, glGetStageIndexNV);
GL_GetFunc( PFN_GLDRAWCOMMANDSNV_PROC, _glDrawCommandsNV_, glDrawCommandsNV);
GL_GetFunc( PFN_GLDRAWCOMMANDSADDRESSNV_PROC, _glDrawCommandsAddressNV_, glDrawCommandsAddressNV);
GL_GetFunc( PFN_GLDRAWCOMMANDSSTATESNV_PROC, _glDrawCommandsStatesNV_, glDrawCommandsStatesNV);
GL_GetFunc( PFN_GLDRAWCOMMANDSSTATESADDRESSNV_PROC, _glDrawCommandsStatesAddressNV_, glDrawCommandsStatesAddressNV);
GL_GetFunc( PFN_GLCREATECOMMANDLISTSNV_PROC, _glCreateCommandListsNV_, glCreateCommandListsNV);
GL_GetFunc( PFN_GLDELETECOMMANDLISTSNV_PROC, _glDeleteCommandListsNV_, glDeleteCommandListsNV);
GL_GetFunc( PFN_GLISCOMMANDLISTNV_PROC, _glIsCommandListNV_, glIsCommandListNV);
GL_GetFunc( PFN_GLLISTDRAWCOMMANDSSTATESCLIENTNV_PROC, _glListDrawCommandsStatesClientNV_, glListDrawCommandsStatesClientNV);
GL_GetFunc( PFN_GLCOMMANDLISTSEGMENTSNV_PROC, _glCommandListSegmentsNV_, glCommandListSegmentsNV);
GL_GetFunc( PFN_GLCOMPILECOMMANDLISTNV_PROC, _glCompileCommandListNV_, glCompileCommandListNV);
GL_GetFunc( PFN_GLCALLCOMMANDLISTNV_PROC, _glCallCommandListNV_, glCallCommandListNV);
#endif //GL_NV_command_list

// GL_NV_compute_shader_derivatives

#ifndef GL_NV_conditional_render
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_conditional_render\n");
GL_GetFunc( PFN_GLBEGINCONDITIONALRENDERNV_PROC, _glBeginConditionalRenderNV_, glBeginConditionalRenderNV);
GL_GetFunc( PFN_GLENDCONDITIONALRENDERNV_PROC, _glEndConditionalRenderNV_, glEndConditionalRenderNV);
#endif //GL_NV_conditional_render

#ifndef GL_NV_conservative_raster
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_conservative_raster\n");
GL_GetFunc( PFN_GLSUBPIXELPRECISIONBIASNV_PROC, _glSubpixelPrecisionBiasNV_, glSubpixelPrecisionBiasNV);
#endif //GL_NV_conservative_raster

#ifndef GL_NV_conservative_raster_dilate
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_conservative_raster_dilate\n");
GL_GetFunc( PFN_GLCONSERVATIVERASTERPARAMETERFNV_PROC, _glConservativeRasterParameterfNV_, glConservativeRasterParameterfNV);
#endif //GL_NV_conservative_raster_dilate

// GL_NV_conservative_raster_pre_snap

#ifndef GL_NV_conservative_raster_pre_snap_triangles
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_conservative_raster_pre_snap_triangles\n");
GL_GetFunc( PFN_GLCONSERVATIVERASTERPARAMETERINV_PROC, _glConservativeRasterParameteriNV_, glConservativeRasterParameteriNV);
#endif //GL_NV_conservative_raster_pre_snap_triangles

// GL_NV_conservative_raster_underestimation

#ifndef GL_NV_draw_vulkan_image
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_draw_vulkan_image\n");
GL_GetFunc( PFN_GLDRAWVKIMAGENV_PROC, _glDrawVkImageNV_, glDrawVkImageNV);
GL_GetFunc( PFN_GLGETVKPROCADDRNV_PROC, _glGetVkProcAddrNV_, glGetVkProcAddrNV);
GL_GetFunc( PFN_GLWAITVKSEMAPHORENV_PROC, _glWaitVkSemaphoreNV_, glWaitVkSemaphoreNV);
GL_GetFunc( PFN_GLSIGNALVKSEMAPHORENV_PROC, _glSignalVkSemaphoreNV_, glSignalVkSemaphoreNV);
GL_GetFunc( PFN_GLSIGNALVKFENCENV_PROC, _glSignalVkFenceNV_, glSignalVkFenceNV);
#endif //GL_NV_draw_vulkan_image

// GL_NV_fill_rectangle

#ifndef GL_NV_fragment_coverage_to_color
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_fragment_coverage_to_color\n");
GL_GetFunc( PFN_GLFRAGMENTCOVERAGECOLORNV_PROC, _glFragmentCoverageColorNV_, glFragmentCoverageColorNV);
#endif //GL_NV_fragment_coverage_to_color

// GL_NV_fragment_shader_barycentric

// GL_NV_fragment_shader_interlock

#ifndef GL_NV_framebuffer_mixed_samples
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_framebuffer_mixed_samples\n");
GL_GetFunc( PFN_GLCOVERAGEMODULATIONTABLENV_PROC, _glCoverageModulationTableNV_, glCoverageModulationTableNV);
GL_GetFunc( PFN_GLGETCOVERAGEMODULATIONTABLENV_PROC, _glGetCoverageModulationTableNV_, glGetCoverageModulationTableNV);
GL_GetFunc( PFN_GLCOVERAGEMODULATIONNV_PROC, _glCoverageModulationNV_, glCoverageModulationNV);
#endif //GL_NV_framebuffer_mixed_samples

#ifndef GL_NV_framebuffer_multisample_coverage
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_framebuffer_multisample_coverage\n");
GL_GetFunc( PFN_GLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENV_PROC, _glRenderbufferStorageMultisampleCoverageNV_, glRenderbufferStorageMultisampleCoverageNV);
#endif //GL_NV_framebuffer_multisample_coverage

// GL_NV_geometry_shader_passthrough

#ifndef GL_NV_gpu_shader5
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_gpu_shader5\n");
GL_GetFunc( PFN_GLUNIFORM1I64NV_PROC, _glUniform1i64NV_, glUniform1i64NV);
GL_GetFunc( PFN_GLUNIFORM2I64NV_PROC, _glUniform2i64NV_, glUniform2i64NV);
GL_GetFunc( PFN_GLUNIFORM3I64NV_PROC, _glUniform3i64NV_, glUniform3i64NV);
GL_GetFunc( PFN_GLUNIFORM4I64NV_PROC, _glUniform4i64NV_, glUniform4i64NV);
GL_GetFunc( PFN_GLUNIFORM1I64VNV_PROC, _glUniform1i64vNV_, glUniform1i64vNV);
GL_GetFunc( PFN_GLUNIFORM2I64VNV_PROC, _glUniform2i64vNV_, glUniform2i64vNV);
GL_GetFunc( PFN_GLUNIFORM3I64VNV_PROC, _glUniform3i64vNV_, glUniform3i64vNV);
GL_GetFunc( PFN_GLUNIFORM4I64VNV_PROC, _glUniform4i64vNV_, glUniform4i64vNV);
GL_GetFunc( PFN_GLUNIFORM1UI64NV_PROC, _glUniform1ui64NV_, glUniform1ui64NV);
GL_GetFunc( PFN_GLUNIFORM2UI64NV_PROC, _glUniform2ui64NV_, glUniform2ui64NV);
GL_GetFunc( PFN_GLUNIFORM3UI64NV_PROC, _glUniform3ui64NV_, glUniform3ui64NV);
GL_GetFunc( PFN_GLUNIFORM4UI64NV_PROC, _glUniform4ui64NV_, glUniform4ui64NV);
GL_GetFunc( PFN_GLUNIFORM1UI64VNV_PROC, _glUniform1ui64vNV_, glUniform1ui64vNV);
GL_GetFunc( PFN_GLUNIFORM2UI64VNV_PROC, _glUniform2ui64vNV_, glUniform2ui64vNV);
GL_GetFunc( PFN_GLUNIFORM3UI64VNV_PROC, _glUniform3ui64vNV_, glUniform3ui64vNV);
GL_GetFunc( PFN_GLUNIFORM4UI64VNV_PROC, _glUniform4ui64vNV_, glUniform4ui64vNV);
GL_GetFunc( PFN_GLGETUNIFORMI64VNV_PROC, _glGetUniformi64vNV_, glGetUniformi64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1I64NV_PROC, _glProgramUniform1i64NV_, glProgramUniform1i64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2I64NV_PROC, _glProgramUniform2i64NV_, glProgramUniform2i64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3I64NV_PROC, _glProgramUniform3i64NV_, glProgramUniform3i64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4I64NV_PROC, _glProgramUniform4i64NV_, glProgramUniform4i64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1I64VNV_PROC, _glProgramUniform1i64vNV_, glProgramUniform1i64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2I64VNV_PROC, _glProgramUniform2i64vNV_, glProgramUniform2i64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3I64VNV_PROC, _glProgramUniform3i64vNV_, glProgramUniform3i64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4I64VNV_PROC, _glProgramUniform4i64vNV_, glProgramUniform4i64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1UI64NV_PROC, _glProgramUniform1ui64NV_, glProgramUniform1ui64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2UI64NV_PROC, _glProgramUniform2ui64NV_, glProgramUniform2ui64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3UI64NV_PROC, _glProgramUniform3ui64NV_, glProgramUniform3ui64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4UI64NV_PROC, _glProgramUniform4ui64NV_, glProgramUniform4ui64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM1UI64VNV_PROC, _glProgramUniform1ui64vNV_, glProgramUniform1ui64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM2UI64VNV_PROC, _glProgramUniform2ui64vNV_, glProgramUniform2ui64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM3UI64VNV_PROC, _glProgramUniform3ui64vNV_, glProgramUniform3ui64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORM4UI64VNV_PROC, _glProgramUniform4ui64vNV_, glProgramUniform4ui64vNV);
#endif //GL_NV_gpu_shader5

#ifndef GL_NV_internalformat_sample_query
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_internalformat_sample_query\n");
GL_GetFunc( PFN_GLGETINTERNALFORMATSAMPLEIVNV_PROC, _glGetInternalformatSampleivNV_, glGetInternalformatSampleivNV);
#endif //GL_NV_internalformat_sample_query

#ifndef GL_NV_memory_attachment
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_memory_attachment\n");
GL_GetFunc( PFN_GLGETMEMORYOBJECTDETACHEDRESOURCESUIVNV_PROC, _glGetMemoryObjectDetachedResourcesuivNV_, glGetMemoryObjectDetachedResourcesuivNV);
GL_GetFunc( PFN_GLRESETMEMORYOBJECTPARAMETERNV_PROC, _glResetMemoryObjectParameterNV_, glResetMemoryObjectParameterNV);
GL_GetFunc( PFN_GLTEXATTACHMEMORYNV_PROC, _glTexAttachMemoryNV_, glTexAttachMemoryNV);
GL_GetFunc( PFN_GLBUFFERATTACHMEMORYNV_PROC, _glBufferAttachMemoryNV_, glBufferAttachMemoryNV);
GL_GetFunc( PFN_GLTEXTUREATTACHMEMORYNV_PROC, _glTextureAttachMemoryNV_, glTextureAttachMemoryNV);
GL_GetFunc( PFN_GLNAMEDBUFFERATTACHMEMORYNV_PROC, _glNamedBufferAttachMemoryNV_, glNamedBufferAttachMemoryNV);
#endif //GL_NV_memory_attachment

#ifndef GL_NV_mesh_shader
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_mesh_shader\n");
GL_GetFunc( PFN_GLDRAWMESHTASKSNV_PROC, _glDrawMeshTasksNV_, glDrawMeshTasksNV);
GL_GetFunc( PFN_GLDRAWMESHTASKSINDIRECTNV_PROC, _glDrawMeshTasksIndirectNV_, glDrawMeshTasksIndirectNV);
GL_GetFunc( PFN_GLMULTIDRAWMESHTASKSINDIRECTNV_PROC, _glMultiDrawMeshTasksIndirectNV_, glMultiDrawMeshTasksIndirectNV);
GL_GetFunc( PFN_GLMULTIDRAWMESHTASKSINDIRECTCOUNTNV_PROC, _glMultiDrawMeshTasksIndirectCountNV_, glMultiDrawMeshTasksIndirectCountNV);
#endif //GL_NV_mesh_shader

#ifndef GL_NV_path_rendering
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_path_rendering\n");
GL_GetFunc( PFN_GLGENPATHSNV_PROC, _glGenPathsNV_, glGenPathsNV);
GL_GetFunc( PFN_GLDELETEPATHSNV_PROC, _glDeletePathsNV_, glDeletePathsNV);
GL_GetFunc( PFN_GLISPATHNV_PROC, _glIsPathNV_, glIsPathNV);
GL_GetFunc( PFN_GLPATHCOMMANDSNV_PROC, _glPathCommandsNV_, glPathCommandsNV);
GL_GetFunc( PFN_GLPATHCOORDSNV_PROC, _glPathCoordsNV_, glPathCoordsNV);
GL_GetFunc( PFN_GLPATHSUBCOMMANDSNV_PROC, _glPathSubCommandsNV_, glPathSubCommandsNV);
GL_GetFunc( PFN_GLPATHSUBCOORDSNV_PROC, _glPathSubCoordsNV_, glPathSubCoordsNV);
GL_GetFunc( PFN_GLPATHSTRINGNV_PROC, _glPathStringNV_, glPathStringNV);
GL_GetFunc( PFN_GLPATHGLYPHSNV_PROC, _glPathGlyphsNV_, glPathGlyphsNV);
GL_GetFunc( PFN_GLPATHGLYPHRANGENV_PROC, _glPathGlyphRangeNV_, glPathGlyphRangeNV);
GL_GetFunc( PFN_GLWEIGHTPATHSNV_PROC, _glWeightPathsNV_, glWeightPathsNV);
GL_GetFunc( PFN_GLCOPYPATHNV_PROC, _glCopyPathNV_, glCopyPathNV);
GL_GetFunc( PFN_GLINTERPOLATEPATHSNV_PROC, _glInterpolatePathsNV_, glInterpolatePathsNV);
GL_GetFunc( PFN_GLTRANSFORMPATHNV_PROC, _glTransformPathNV_, glTransformPathNV);
GL_GetFunc( PFN_GLPATHPARAMETERIVNV_PROC, _glPathParameterivNV_, glPathParameterivNV);
GL_GetFunc( PFN_GLPATHPARAMETERINV_PROC, _glPathParameteriNV_, glPathParameteriNV);
GL_GetFunc( PFN_GLPATHPARAMETERFVNV_PROC, _glPathParameterfvNV_, glPathParameterfvNV);
GL_GetFunc( PFN_GLPATHPARAMETERFNV_PROC, _glPathParameterfNV_, glPathParameterfNV);
GL_GetFunc( PFN_GLPATHDASHARRAYNV_PROC, _glPathDashArrayNV_, glPathDashArrayNV);
GL_GetFunc( PFN_GLPATHSTENCILFUNCNV_PROC, _glPathStencilFuncNV_, glPathStencilFuncNV);
GL_GetFunc( PFN_GLPATHSTENCILDEPTHOFFSETNV_PROC, _glPathStencilDepthOffsetNV_, glPathStencilDepthOffsetNV);
GL_GetFunc( PFN_GLSTENCILFILLPATHNV_PROC, _glStencilFillPathNV_, glStencilFillPathNV);
GL_GetFunc( PFN_GLSTENCILSTROKEPATHNV_PROC, _glStencilStrokePathNV_, glStencilStrokePathNV);
GL_GetFunc( PFN_GLSTENCILFILLPATHINSTANCEDNV_PROC, _glStencilFillPathInstancedNV_, glStencilFillPathInstancedNV);
GL_GetFunc( PFN_GLSTENCILSTROKEPATHINSTANCEDNV_PROC, _glStencilStrokePathInstancedNV_, glStencilStrokePathInstancedNV);
GL_GetFunc( PFN_GLPATHCOVERDEPTHFUNCNV_PROC, _glPathCoverDepthFuncNV_, glPathCoverDepthFuncNV);
GL_GetFunc( PFN_GLCOVERFILLPATHNV_PROC, _glCoverFillPathNV_, glCoverFillPathNV);
GL_GetFunc( PFN_GLCOVERSTROKEPATHNV_PROC, _glCoverStrokePathNV_, glCoverStrokePathNV);
GL_GetFunc( PFN_GLCOVERFILLPATHINSTANCEDNV_PROC, _glCoverFillPathInstancedNV_, glCoverFillPathInstancedNV);
GL_GetFunc( PFN_GLCOVERSTROKEPATHINSTANCEDNV_PROC, _glCoverStrokePathInstancedNV_, glCoverStrokePathInstancedNV);
GL_GetFunc( PFN_GLGETPATHPARAMETERIVNV_PROC, _glGetPathParameterivNV_, glGetPathParameterivNV);
GL_GetFunc( PFN_GLGETPATHPARAMETERFVNV_PROC, _glGetPathParameterfvNV_, glGetPathParameterfvNV);
GL_GetFunc( PFN_GLGETPATHCOMMANDSNV_PROC, _glGetPathCommandsNV_, glGetPathCommandsNV);
GL_GetFunc( PFN_GLGETPATHCOORDSNV_PROC, _glGetPathCoordsNV_, glGetPathCoordsNV);
GL_GetFunc( PFN_GLGETPATHDASHARRAYNV_PROC, _glGetPathDashArrayNV_, glGetPathDashArrayNV);
GL_GetFunc( PFN_GLGETPATHMETRICSNV_PROC, _glGetPathMetricsNV_, glGetPathMetricsNV);
GL_GetFunc( PFN_GLGETPATHMETRICRANGENV_PROC, _glGetPathMetricRangeNV_, glGetPathMetricRangeNV);
GL_GetFunc( PFN_GLGETPATHSPACINGNV_PROC, _glGetPathSpacingNV_, glGetPathSpacingNV);
GL_GetFunc( PFN_GLISPOINTINFILLPATHNV_PROC, _glIsPointInFillPathNV_, glIsPointInFillPathNV);
GL_GetFunc( PFN_GLISPOINTINSTROKEPATHNV_PROC, _glIsPointInStrokePathNV_, glIsPointInStrokePathNV);
GL_GetFunc( PFN_GLGETPATHLENGTHNV_PROC, _glGetPathLengthNV_, glGetPathLengthNV);
GL_GetFunc( PFN_GLPOINTALONGPATHNV_PROC, _glPointAlongPathNV_, glPointAlongPathNV);
GL_GetFunc( PFN_GLMATRIXLOAD3X2FNV_PROC, _glMatrixLoad3x2fNV_, glMatrixLoad3x2fNV);
GL_GetFunc( PFN_GLMATRIXLOAD3X3FNV_PROC, _glMatrixLoad3x3fNV_, glMatrixLoad3x3fNV);
GL_GetFunc( PFN_GLMATRIXLOADTRANSPOSE3X3FNV_PROC, _glMatrixLoadTranspose3x3fNV_, glMatrixLoadTranspose3x3fNV);
GL_GetFunc( PFN_GLMATRIXMULT3X2FNV_PROC, _glMatrixMult3x2fNV_, glMatrixMult3x2fNV);
GL_GetFunc( PFN_GLMATRIXMULT3X3FNV_PROC, _glMatrixMult3x3fNV_, glMatrixMult3x3fNV);
GL_GetFunc( PFN_GLMATRIXMULTTRANSPOSE3X3FNV_PROC, _glMatrixMultTranspose3x3fNV_, glMatrixMultTranspose3x3fNV);
GL_GetFunc( PFN_GLSTENCILTHENCOVERFILLPATHNV_PROC, _glStencilThenCoverFillPathNV_, glStencilThenCoverFillPathNV);
GL_GetFunc( PFN_GLSTENCILTHENCOVERSTROKEPATHNV_PROC, _glStencilThenCoverStrokePathNV_, glStencilThenCoverStrokePathNV);
GL_GetFunc( PFN_GLSTENCILTHENCOVERFILLPATHINSTANCEDNV_PROC, _glStencilThenCoverFillPathInstancedNV_, glStencilThenCoverFillPathInstancedNV);
GL_GetFunc( PFN_GLSTENCILTHENCOVERSTROKEPATHINSTANCEDNV_PROC, _glStencilThenCoverStrokePathInstancedNV_, glStencilThenCoverStrokePathInstancedNV);
GL_GetFunc( PFN_GLPATHGLYPHINDEXRANGENV_PROC, _glPathGlyphIndexRangeNV_, glPathGlyphIndexRangeNV);
GL_GetFunc( PFN_GLPATHGLYPHINDEXARRAYNV_PROC, _glPathGlyphIndexArrayNV_, glPathGlyphIndexArrayNV);
GL_GetFunc( PFN_GLPATHMEMORYGLYPHINDEXARRAYNV_PROC, _glPathMemoryGlyphIndexArrayNV_, glPathMemoryGlyphIndexArrayNV);
GL_GetFunc( PFN_GLPROGRAMPATHFRAGMENTINPUTGENNV_PROC, _glProgramPathFragmentInputGenNV_, glProgramPathFragmentInputGenNV);
GL_GetFunc( PFN_GLGETPROGRAMRESOURCEFVNV_PROC, _glGetProgramResourcefvNV_, glGetProgramResourcefvNV);
GL_GetFunc( PFN_GLPATHCOLORGENNV_PROC, _glPathColorGenNV_, glPathColorGenNV);
GL_GetFunc( PFN_GLPATHTEXGENNV_PROC, _glPathTexGenNV_, glPathTexGenNV);
GL_GetFunc( PFN_GLPATHFOGGENNV_PROC, _glPathFogGenNV_, glPathFogGenNV);
GL_GetFunc( PFN_GLGETPATHCOLORGENIVNV_PROC, _glGetPathColorGenivNV_, glGetPathColorGenivNV);
GL_GetFunc( PFN_GLGETPATHCOLORGENFVNV_PROC, _glGetPathColorGenfvNV_, glGetPathColorGenfvNV);
GL_GetFunc( PFN_GLGETPATHTEXGENIVNV_PROC, _glGetPathTexGenivNV_, glGetPathTexGenivNV);
GL_GetFunc( PFN_GLGETPATHTEXGENFVNV_PROC, _glGetPathTexGenfvNV_, glGetPathTexGenfvNV);
#endif //GL_NV_path_rendering

// GL_NV_path_rendering_shared_edge

// GL_NV_representative_fragment_test

#ifndef GL_NV_sample_locations
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_sample_locations\n");
GL_GetFunc( PFN_GLFRAMEBUFFERSAMPLELOCATIONSFVNV_PROC, _glFramebufferSampleLocationsfvNV_, glFramebufferSampleLocationsfvNV);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNV_PROC, _glNamedFramebufferSampleLocationsfvNV_, glNamedFramebufferSampleLocationsfvNV);
GL_GetFunc( PFN_GLRESOLVEDEPTHVALUESNV_PROC, _glResolveDepthValuesNV_, glResolveDepthValuesNV);
#endif //GL_NV_sample_locations

// GL_NV_sample_mask_override_coverage

#ifndef GL_NV_scissor_exclusive
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_scissor_exclusive\n");
GL_GetFunc( PFN_GLSCISSOREXCLUSIVENV_PROC, _glScissorExclusiveNV_, glScissorExclusiveNV);
GL_GetFunc( PFN_GLSCISSOREXCLUSIVEARRAYVNV_PROC, _glScissorExclusiveArrayvNV_, glScissorExclusiveArrayvNV);
#endif //GL_NV_scissor_exclusive

// GL_NV_shader_atomic_counters

// GL_NV_shader_atomic_float

// GL_NV_shader_atomic_float64

// GL_NV_shader_atomic_fp16_vector

// GL_NV_shader_atomic_int64

#ifndef GL_NV_shader_buffer_load
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_shader_buffer_load\n");
GL_GetFunc( PFN_GLMAKEBUFFERRESIDENTNV_PROC, _glMakeBufferResidentNV_, glMakeBufferResidentNV);
GL_GetFunc( PFN_GLMAKEBUFFERNONRESIDENTNV_PROC, _glMakeBufferNonResidentNV_, glMakeBufferNonResidentNV);
GL_GetFunc( PFN_GLISBUFFERRESIDENTNV_PROC, _glIsBufferResidentNV_, glIsBufferResidentNV);
GL_GetFunc( PFN_GLMAKENAMEDBUFFERRESIDENTNV_PROC, _glMakeNamedBufferResidentNV_, glMakeNamedBufferResidentNV);
GL_GetFunc( PFN_GLMAKENAMEDBUFFERNONRESIDENTNV_PROC, _glMakeNamedBufferNonResidentNV_, glMakeNamedBufferNonResidentNV);
GL_GetFunc( PFN_GLISNAMEDBUFFERRESIDENTNV_PROC, _glIsNamedBufferResidentNV_, glIsNamedBufferResidentNV);
GL_GetFunc( PFN_GLGETBUFFERPARAMETERUI64VNV_PROC, _glGetBufferParameterui64vNV_, glGetBufferParameterui64vNV);
GL_GetFunc( PFN_GLGETNAMEDBUFFERPARAMETERUI64VNV_PROC, _glGetNamedBufferParameterui64vNV_, glGetNamedBufferParameterui64vNV);
GL_GetFunc( PFN_GLGETINTEGERUI64VNV_PROC, _glGetIntegerui64vNV_, glGetIntegerui64vNV);
GL_GetFunc( PFN_GLUNIFORMUI64NV_PROC, _glUniformui64NV_, glUniformui64NV);
GL_GetFunc( PFN_GLUNIFORMUI64VNV_PROC, _glUniformui64vNV_, glUniformui64vNV);
GL_GetFunc( PFN_GLGETUNIFORMUI64VNV_PROC, _glGetUniformui64vNV_, glGetUniformui64vNV);
GL_GetFunc( PFN_GLPROGRAMUNIFORMUI64NV_PROC, _glProgramUniformui64NV_, glProgramUniformui64NV);
GL_GetFunc( PFN_GLPROGRAMUNIFORMUI64VNV_PROC, _glProgramUniformui64vNV_, glProgramUniformui64vNV);
#endif //GL_NV_shader_buffer_load

// GL_NV_shader_buffer_store

// GL_NV_shader_subgroup_partitioned

// GL_NV_shader_texture_footprint

// GL_NV_shader_thread_group

// GL_NV_shader_thread_shuffle

#ifndef GL_NV_shading_rate_image
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_shading_rate_image\n");
GL_GetFunc( PFN_GLBINDSHADINGRATEIMAGENV_PROC, _glBindShadingRateImageNV_, glBindShadingRateImageNV);
GL_GetFunc( PFN_GLGETSHADINGRATEIMAGEPALETTENV_PROC, _glGetShadingRateImagePaletteNV_, glGetShadingRateImagePaletteNV);
GL_GetFunc( PFN_GLGETSHADINGRATESAMPLELOCATIONIVNV_PROC, _glGetShadingRateSampleLocationivNV_, glGetShadingRateSampleLocationivNV);
GL_GetFunc( PFN_GLSHADINGRATEIMAGEBARRIERNV_PROC, _glShadingRateImageBarrierNV_, glShadingRateImageBarrierNV);
GL_GetFunc( PFN_GLSHADINGRATEIMAGEPALETTENV_PROC, _glShadingRateImagePaletteNV_, glShadingRateImagePaletteNV);
GL_GetFunc( PFN_GLSHADINGRATESAMPLEORDERNV_PROC, _glShadingRateSampleOrderNV_, glShadingRateSampleOrderNV);
GL_GetFunc( PFN_GLSHADINGRATESAMPLEORDERCUSTOMNV_PROC, _glShadingRateSampleOrderCustomNV_, glShadingRateSampleOrderCustomNV);
#endif //GL_NV_shading_rate_image

// GL_NV_stereo_view_rendering

#ifndef GL_NV_texture_barrier
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_texture_barrier\n");
GL_GetFunc( PFN_GLTEXTUREBARRIERNV_PROC, _glTextureBarrierNV_, glTextureBarrierNV);
#endif //GL_NV_texture_barrier

// GL_NV_texture_rectangle_compressed

// GL_NV_uniform_buffer_unified_memory

#ifndef GL_NV_vertex_attrib_integer_64bit
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_attrib_integer_64bit\n");
GL_GetFunc( PFN_GLVERTEXATTRIBL1I64NV_PROC, _glVertexAttribL1i64NV_, glVertexAttribL1i64NV);
GL_GetFunc( PFN_GLVERTEXATTRIBL2I64NV_PROC, _glVertexAttribL2i64NV_, glVertexAttribL2i64NV);
GL_GetFunc( PFN_GLVERTEXATTRIBL3I64NV_PROC, _glVertexAttribL3i64NV_, glVertexAttribL3i64NV);
GL_GetFunc( PFN_GLVERTEXATTRIBL4I64NV_PROC, _glVertexAttribL4i64NV_, glVertexAttribL4i64NV);
GL_GetFunc( PFN_GLVERTEXATTRIBL1I64VNV_PROC, _glVertexAttribL1i64vNV_, glVertexAttribL1i64vNV);
GL_GetFunc( PFN_GLVERTEXATTRIBL2I64VNV_PROC, _glVertexAttribL2i64vNV_, glVertexAttribL2i64vNV);
GL_GetFunc( PFN_GLVERTEXATTRIBL3I64VNV_PROC, _glVertexAttribL3i64vNV_, glVertexAttribL3i64vNV);
GL_GetFunc( PFN_GLVERTEXATTRIBL4I64VNV_PROC, _glVertexAttribL4i64vNV_, glVertexAttribL4i64vNV);
GL_GetFunc( PFN_GLVERTEXATTRIBL1UI64NV_PROC, _glVertexAttribL1ui64NV_, glVertexAttribL1ui64NV);
GL_GetFunc( PFN_GLVERTEXATTRIBL2UI64NV_PROC, _glVertexAttribL2ui64NV_, glVertexAttribL2ui64NV);
GL_GetFunc( PFN_GLVERTEXATTRIBL3UI64NV_PROC, _glVertexAttribL3ui64NV_, glVertexAttribL3ui64NV);
GL_GetFunc( PFN_GLVERTEXATTRIBL4UI64NV_PROC, _glVertexAttribL4ui64NV_, glVertexAttribL4ui64NV);
GL_GetFunc( PFN_GLVERTEXATTRIBL1UI64VNV_PROC, _glVertexAttribL1ui64vNV_, glVertexAttribL1ui64vNV);
GL_GetFunc( PFN_GLVERTEXATTRIBL2UI64VNV_PROC, _glVertexAttribL2ui64vNV_, glVertexAttribL2ui64vNV);
GL_GetFunc( PFN_GLVERTEXATTRIBL3UI64VNV_PROC, _glVertexAttribL3ui64vNV_, glVertexAttribL3ui64vNV);
GL_GetFunc( PFN_GLVERTEXATTRIBL4UI64VNV_PROC, _glVertexAttribL4ui64vNV_, glVertexAttribL4ui64vNV);
GL_GetFunc( PFN_GLGETVERTEXATTRIBLI64VNV_PROC, _glGetVertexAttribLi64vNV_, glGetVertexAttribLi64vNV);
GL_GetFunc( PFN_GLGETVERTEXATTRIBLUI64VNV_PROC, _glGetVertexAttribLui64vNV_, glGetVertexAttribLui64vNV);
GL_GetFunc( PFN_GLVERTEXATTRIBLFORMATNV_PROC, _glVertexAttribLFormatNV_, glVertexAttribLFormatNV);
#endif //GL_NV_vertex_attrib_integer_64bit

#ifndef GL_NV_vertex_buffer_unified_memory
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_buffer_unified_memory\n");
GL_GetFunc( PFN_GLBUFFERADDRESSRANGENV_PROC, _glBufferAddressRangeNV_, glBufferAddressRangeNV);
GL_GetFunc( PFN_GLVERTEXFORMATNV_PROC, _glVertexFormatNV_, glVertexFormatNV);
GL_GetFunc( PFN_GLNORMALFORMATNV_PROC, _glNormalFormatNV_, glNormalFormatNV);
GL_GetFunc( PFN_GLCOLORFORMATNV_PROC, _glColorFormatNV_, glColorFormatNV);
GL_GetFunc( PFN_GLINDEXFORMATNV_PROC, _glIndexFormatNV_, glIndexFormatNV);
GL_GetFunc( PFN_GLTEXCOORDFORMATNV_PROC, _glTexCoordFormatNV_, glTexCoordFormatNV);
GL_GetFunc( PFN_GLEDGEFLAGFORMATNV_PROC, _glEdgeFlagFormatNV_, glEdgeFlagFormatNV);
GL_GetFunc( PFN_GLSECONDARYCOLORFORMATNV_PROC, _glSecondaryColorFormatNV_, glSecondaryColorFormatNV);
GL_GetFunc( PFN_GLFOGCOORDFORMATNV_PROC, _glFogCoordFormatNV_, glFogCoordFormatNV);
GL_GetFunc( PFN_GLVERTEXATTRIBFORMATNV_PROC, _glVertexAttribFormatNV_, glVertexAttribFormatNV);
GL_GetFunc( PFN_GLVERTEXATTRIBIFORMATNV_PROC, _glVertexAttribIFormatNV_, glVertexAttribIFormatNV);
GL_GetFunc( PFN_GLGETINTEGERUI64I_VNV_PROC, _glGetIntegerui64i_vNV_, glGetIntegerui64i_vNV);
#endif //GL_NV_vertex_buffer_unified_memory

// GL_NV_viewport_array2

#ifndef GL_NV_viewport_swizzle
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_viewport_swizzle\n");
GL_GetFunc( PFN_GLVIEWPORTSWIZZLENV_PROC, _glViewportSwizzleNV_, glViewportSwizzleNV);
#endif //GL_NV_viewport_swizzle

#ifndef GL_OVR_multiview
LOG_fprintf(LogGlGetFunctions_py, "\nGL_OVR_multiview\n");
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTUREMULTIVIEWOVR_PROC, _glFramebufferTextureMultiviewOVR_, glFramebufferTextureMultiviewOVR);
#endif //GL_OVR_multiview

// GL_OVR_multiview2

#ifndef GL_VERSION_1_11
LOG_fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_11\n");
GL_GetFunc( PFN_GLACCUM_PROC, _glAccum_, glAccum);
GL_GetFunc( PFN_GLALPHAFUNC_PROC, _glAlphaFunc_, glAlphaFunc);
GL_GetFunc( PFN_GLARETEXTURESRESIDENT_PROC, _glAreTexturesResident_, glAreTexturesResident);
GL_GetFunc( PFN_GLARRAYELEMENT_PROC, _glArrayElement_, glArrayElement);
GL_GetFunc( PFN_GLBEGIN_PROC, _glBegin_, glBegin);
GL_GetFunc( PFN_GLBITMAP_PROC, _glBitmap_, glBitmap);
GL_GetFunc( PFN_GLCALLLIST_PROC, _glCallList_, glCallList);
GL_GetFunc( PFN_GLCALLLISTS_PROC, _glCallLists_, glCallLists);
GL_GetFunc( PFN_GLCLEARACCUM_PROC, _glClearAccum_, glClearAccum);
GL_GetFunc( PFN_GLCLEARINDEX_PROC, _glClearIndex_, glClearIndex);
GL_GetFunc( PFN_GLCLIPPLANE_PROC, _glClipPlane_, glClipPlane);
GL_GetFunc( PFN_GLCOLOR3B_PROC, _glColor3b_, glColor3b);
GL_GetFunc( PFN_GLCOLOR3BV_PROC, _glColor3bv_, glColor3bv);
GL_GetFunc( PFN_GLCOLOR3D_PROC, _glColor3d_, glColor3d);
GL_GetFunc( PFN_GLCOLOR3DV_PROC, _glColor3dv_, glColor3dv);
GL_GetFunc( PFN_GLCOLOR3F_PROC, _glColor3f_, glColor3f);
GL_GetFunc( PFN_GLCOLOR3FV_PROC, _glColor3fv_, glColor3fv);
GL_GetFunc( PFN_GLCOLOR3I_PROC, _glColor3i_, glColor3i);
GL_GetFunc( PFN_GLCOLOR3IV_PROC, _glColor3iv_, glColor3iv);
GL_GetFunc( PFN_GLCOLOR3S_PROC, _glColor3s_, glColor3s);
GL_GetFunc( PFN_GLCOLOR3SV_PROC, _glColor3sv_, glColor3sv);
GL_GetFunc( PFN_GLCOLOR3UB_PROC, _glColor3ub_, glColor3ub);
GL_GetFunc( PFN_GLCOLOR3UBV_PROC, _glColor3ubv_, glColor3ubv);
GL_GetFunc( PFN_GLCOLOR3UI_PROC, _glColor3ui_, glColor3ui);
GL_GetFunc( PFN_GLCOLOR3UIV_PROC, _glColor3uiv_, glColor3uiv);
GL_GetFunc( PFN_GLCOLOR3US_PROC, _glColor3us_, glColor3us);
GL_GetFunc( PFN_GLCOLOR3USV_PROC, _glColor3usv_, glColor3usv);
GL_GetFunc( PFN_GLCOLOR4B_PROC, _glColor4b_, glColor4b);
GL_GetFunc( PFN_GLCOLOR4BV_PROC, _glColor4bv_, glColor4bv);
GL_GetFunc( PFN_GLCOLOR4D_PROC, _glColor4d_, glColor4d);
GL_GetFunc( PFN_GLCOLOR4DV_PROC, _glColor4dv_, glColor4dv);
GL_GetFunc( PFN_GLCOLOR4F_PROC, _glColor4f_, glColor4f);
GL_GetFunc( PFN_GLCOLOR4FV_PROC, _glColor4fv_, glColor4fv);
GL_GetFunc( PFN_GLCOLOR4I_PROC, _glColor4i_, glColor4i);
GL_GetFunc( PFN_GLCOLOR4IV_PROC, _glColor4iv_, glColor4iv);
GL_GetFunc( PFN_GLCOLOR4S_PROC, _glColor4s_, glColor4s);
GL_GetFunc( PFN_GLCOLOR4SV_PROC, _glColor4sv_, glColor4sv);
GL_GetFunc( PFN_GLCOLOR4UB_PROC, _glColor4ub_, glColor4ub);
GL_GetFunc( PFN_GLCOLOR4UBV_PROC, _glColor4ubv_, glColor4ubv);
GL_GetFunc( PFN_GLCOLOR4UI_PROC, _glColor4ui_, glColor4ui);
GL_GetFunc( PFN_GLCOLOR4UIV_PROC, _glColor4uiv_, glColor4uiv);
GL_GetFunc( PFN_GLCOLOR4US_PROC, _glColor4us_, glColor4us);
GL_GetFunc( PFN_GLCOLOR4USV_PROC, _glColor4usv_, glColor4usv);
GL_GetFunc( PFN_GLCOLORMATERIAL_PROC, _glColorMaterial_, glColorMaterial);
GL_GetFunc( PFN_GLCOLORPOINTER_PROC, _glColorPointer_, glColorPointer);
GL_GetFunc( PFN_GLCOPYPIXELS_PROC, _glCopyPixels_, glCopyPixels);
GL_GetFunc( PFN_GLDELETELISTS_PROC, _glDeleteLists_, glDeleteLists);
GL_GetFunc( PFN_GLDISABLECLIENTSTATE_PROC, _glDisableClientState_, glDisableClientState);
GL_GetFunc( PFN_GLDRAWPIXELS_PROC, _glDrawPixels_, glDrawPixels);
GL_GetFunc( PFN_GLEDGEFLAG_PROC, _glEdgeFlag_, glEdgeFlag);
GL_GetFunc( PFN_GLEDGEFLAGPOINTER_PROC, _glEdgeFlagPointer_, glEdgeFlagPointer);
GL_GetFunc( PFN_GLEDGEFLAGV_PROC, _glEdgeFlagv_, glEdgeFlagv);
GL_GetFunc( PFN_GLENABLECLIENTSTATE_PROC, _glEnableClientState_, glEnableClientState);
GL_GetFunc( PFN_GLEND_PROC, _glEnd_, glEnd);
GL_GetFunc( PFN_GLENDLIST_PROC, _glEndList_, glEndList);
GL_GetFunc( PFN_GLEVALCOORD1D_PROC, _glEvalCoord1d_, glEvalCoord1d);
GL_GetFunc( PFN_GLEVALCOORD1DV_PROC, _glEvalCoord1dv_, glEvalCoord1dv);
GL_GetFunc( PFN_GLEVALCOORD1F_PROC, _glEvalCoord1f_, glEvalCoord1f);
GL_GetFunc( PFN_GLEVALCOORD1FV_PROC, _glEvalCoord1fv_, glEvalCoord1fv);
GL_GetFunc( PFN_GLEVALCOORD2D_PROC, _glEvalCoord2d_, glEvalCoord2d);
GL_GetFunc( PFN_GLEVALCOORD2DV_PROC, _glEvalCoord2dv_, glEvalCoord2dv);
GL_GetFunc( PFN_GLEVALCOORD2F_PROC, _glEvalCoord2f_, glEvalCoord2f);
GL_GetFunc( PFN_GLEVALCOORD2FV_PROC, _glEvalCoord2fv_, glEvalCoord2fv);
GL_GetFunc( PFN_GLEVALMESH1_PROC, _glEvalMesh1_, glEvalMesh1);
GL_GetFunc( PFN_GLEVALMESH2_PROC, _glEvalMesh2_, glEvalMesh2);
GL_GetFunc( PFN_GLEVALPOINT1_PROC, _glEvalPoint1_, glEvalPoint1);
GL_GetFunc( PFN_GLEVALPOINT2_PROC, _glEvalPoint2_, glEvalPoint2);
GL_GetFunc( PFN_GLFEEDBACKBUFFER_PROC, _glFeedbackBuffer_, glFeedbackBuffer);
GL_GetFunc( PFN_GLFOGF_PROC, _glFogf_, glFogf);
GL_GetFunc( PFN_GLFOGFV_PROC, _glFogfv_, glFogfv);
GL_GetFunc( PFN_GLFOGI_PROC, _glFogi_, glFogi);
GL_GetFunc( PFN_GLFOGIV_PROC, _glFogiv_, glFogiv);
GL_GetFunc( PFN_GLFRUSTUM_PROC, _glFrustum_, glFrustum);
GL_GetFunc( PFN_GLGENLISTS_PROC, _glGenLists_, glGenLists);
GL_GetFunc( PFN_GLGETCLIPPLANE_PROC, _glGetClipPlane_, glGetClipPlane);
GL_GetFunc( PFN_GLGETLIGHTFV_PROC, _glGetLightfv_, glGetLightfv);
GL_GetFunc( PFN_GLGETLIGHTIV_PROC, _glGetLightiv_, glGetLightiv);
GL_GetFunc( PFN_GLGETMAPDV_PROC, _glGetMapdv_, glGetMapdv);
GL_GetFunc( PFN_GLGETMAPFV_PROC, _glGetMapfv_, glGetMapfv);
GL_GetFunc( PFN_GLGETMAPIV_PROC, _glGetMapiv_, glGetMapiv);
GL_GetFunc( PFN_GLGETMATERIALFV_PROC, _glGetMaterialfv_, glGetMaterialfv);
GL_GetFunc( PFN_GLGETMATERIALIV_PROC, _glGetMaterialiv_, glGetMaterialiv);
GL_GetFunc( PFN_GLGETPIXELMAPFV_PROC, _glGetPixelMapfv_, glGetPixelMapfv);
GL_GetFunc( PFN_GLGETPIXELMAPUIV_PROC, _glGetPixelMapuiv_, glGetPixelMapuiv);
GL_GetFunc( PFN_GLGETPIXELMAPUSV_PROC, _glGetPixelMapusv_, glGetPixelMapusv);
GL_GetFunc( PFN_GLGETPOLYGONSTIPPLE_PROC, _glGetPolygonStipple_, glGetPolygonStipple);
GL_GetFunc( PFN_GLGETTEXENVFV_PROC, _glGetTexEnvfv_, glGetTexEnvfv);
GL_GetFunc( PFN_GLGETTEXENVIV_PROC, _glGetTexEnviv_, glGetTexEnviv);
GL_GetFunc( PFN_GLGETTEXGENDV_PROC, _glGetTexGendv_, glGetTexGendv);
GL_GetFunc( PFN_GLGETTEXGENFV_PROC, _glGetTexGenfv_, glGetTexGenfv);
GL_GetFunc( PFN_GLGETTEXGENIV_PROC, _glGetTexGeniv_, glGetTexGeniv);
GL_GetFunc( PFN_GLINDEXMASK_PROC, _glIndexMask_, glIndexMask);
GL_GetFunc( PFN_GLINDEXPOINTER_PROC, _glIndexPointer_, glIndexPointer);
GL_GetFunc( PFN_GLINDEXD_PROC, _glIndexd_, glIndexd);
GL_GetFunc( PFN_GLINDEXDV_PROC, _glIndexdv_, glIndexdv);
GL_GetFunc( PFN_GLINDEXF_PROC, _glIndexf_, glIndexf);
GL_GetFunc( PFN_GLINDEXFV_PROC, _glIndexfv_, glIndexfv);
GL_GetFunc( PFN_GLINDEXI_PROC, _glIndexi_, glIndexi);
GL_GetFunc( PFN_GLINDEXIV_PROC, _glIndexiv_, glIndexiv);
GL_GetFunc( PFN_GLINDEXS_PROC, _glIndexs_, glIndexs);
GL_GetFunc( PFN_GLINDEXSV_PROC, _glIndexsv_, glIndexsv);
GL_GetFunc( PFN_GLINDEXUB_PROC, _glIndexub_, glIndexub);
GL_GetFunc( PFN_GLINDEXUBV_PROC, _glIndexubv_, glIndexubv);
GL_GetFunc( PFN_GLINITNAMES_PROC, _glInitNames_, glInitNames);
GL_GetFunc( PFN_GLINTERLEAVEDARRAYS_PROC, _glInterleavedArrays_, glInterleavedArrays);
GL_GetFunc( PFN_GLISLIST_PROC, _glIsList_, glIsList);
GL_GetFunc( PFN_GLLIGHTMODELF_PROC, _glLightModelf_, glLightModelf);
GL_GetFunc( PFN_GLLIGHTMODELFV_PROC, _glLightModelfv_, glLightModelfv);
GL_GetFunc( PFN_GLLIGHTMODELI_PROC, _glLightModeli_, glLightModeli);
GL_GetFunc( PFN_GLLIGHTMODELIV_PROC, _glLightModeliv_, glLightModeliv);
GL_GetFunc( PFN_GLLIGHTF_PROC, _glLightf_, glLightf);
GL_GetFunc( PFN_GLLIGHTFV_PROC, _glLightfv_, glLightfv);
GL_GetFunc( PFN_GLLIGHTI_PROC, _glLighti_, glLighti);
GL_GetFunc( PFN_GLLIGHTIV_PROC, _glLightiv_, glLightiv);
GL_GetFunc( PFN_GLLINESTIPPLE_PROC, _glLineStipple_, glLineStipple);
GL_GetFunc( PFN_GLLISTBASE_PROC, _glListBase_, glListBase);
GL_GetFunc( PFN_GLLOADIDENTITY_PROC, _glLoadIdentity_, glLoadIdentity);
GL_GetFunc( PFN_GLLOADMATRIXD_PROC, _glLoadMatrixd_, glLoadMatrixd);
GL_GetFunc( PFN_GLLOADMATRIXF_PROC, _glLoadMatrixf_, glLoadMatrixf);
GL_GetFunc( PFN_GLLOADNAME_PROC, _glLoadName_, glLoadName);
GL_GetFunc( PFN_GLMAP1D_PROC, _glMap1d_, glMap1d);
GL_GetFunc( PFN_GLMAP1F_PROC, _glMap1f_, glMap1f);
GL_GetFunc( PFN_GLMAP2D_PROC, _glMap2d_, glMap2d);
GL_GetFunc( PFN_GLMAP2F_PROC, _glMap2f_, glMap2f);
GL_GetFunc( PFN_GLMAPGRID1D_PROC, _glMapGrid1d_, glMapGrid1d);
GL_GetFunc( PFN_GLMAPGRID1F_PROC, _glMapGrid1f_, glMapGrid1f);
GL_GetFunc( PFN_GLMAPGRID2D_PROC, _glMapGrid2d_, glMapGrid2d);
GL_GetFunc( PFN_GLMAPGRID2F_PROC, _glMapGrid2f_, glMapGrid2f);
GL_GetFunc( PFN_GLMATERIALF_PROC, _glMaterialf_, glMaterialf);
GL_GetFunc( PFN_GLMATERIALFV_PROC, _glMaterialfv_, glMaterialfv);
GL_GetFunc( PFN_GLMATERIALI_PROC, _glMateriali_, glMateriali);
GL_GetFunc( PFN_GLMATERIALIV_PROC, _glMaterialiv_, glMaterialiv);
GL_GetFunc( PFN_GLMATRIXMODE_PROC, _glMatrixMode_, glMatrixMode);
GL_GetFunc( PFN_GLMULTMATRIXD_PROC, _glMultMatrixd_, glMultMatrixd);
GL_GetFunc( PFN_GLMULTMATRIXF_PROC, _glMultMatrixf_, glMultMatrixf);
GL_GetFunc( PFN_GLNEWLIST_PROC, _glNewList_, glNewList);
GL_GetFunc( PFN_GLNORMAL3B_PROC, _glNormal3b_, glNormal3b);
GL_GetFunc( PFN_GLNORMAL3BV_PROC, _glNormal3bv_, glNormal3bv);
GL_GetFunc( PFN_GLNORMAL3D_PROC, _glNormal3d_, glNormal3d);
GL_GetFunc( PFN_GLNORMAL3DV_PROC, _glNormal3dv_, glNormal3dv);
GL_GetFunc( PFN_GLNORMAL3F_PROC, _glNormal3f_, glNormal3f);
GL_GetFunc( PFN_GLNORMAL3FV_PROC, _glNormal3fv_, glNormal3fv);
GL_GetFunc( PFN_GLNORMAL3I_PROC, _glNormal3i_, glNormal3i);
GL_GetFunc( PFN_GLNORMAL3IV_PROC, _glNormal3iv_, glNormal3iv);
GL_GetFunc( PFN_GLNORMAL3S_PROC, _glNormal3s_, glNormal3s);
GL_GetFunc( PFN_GLNORMAL3SV_PROC, _glNormal3sv_, glNormal3sv);
GL_GetFunc( PFN_GLNORMALPOINTER_PROC, _glNormalPointer_, glNormalPointer);
GL_GetFunc( PFN_GLORTHO_PROC, _glOrtho_, glOrtho);
GL_GetFunc( PFN_GLPASSTHROUGH_PROC, _glPassThrough_, glPassThrough);
GL_GetFunc( PFN_GLPIXELMAPFV_PROC, _glPixelMapfv_, glPixelMapfv);
GL_GetFunc( PFN_GLPIXELMAPUIV_PROC, _glPixelMapuiv_, glPixelMapuiv);
GL_GetFunc( PFN_GLPIXELMAPUSV_PROC, _glPixelMapusv_, glPixelMapusv);
GL_GetFunc( PFN_GLPIXELTRANSFERF_PROC, _glPixelTransferf_, glPixelTransferf);
GL_GetFunc( PFN_GLPIXELTRANSFERI_PROC, _glPixelTransferi_, glPixelTransferi);
GL_GetFunc( PFN_GLPIXELZOOM_PROC, _glPixelZoom_, glPixelZoom);
GL_GetFunc( PFN_GLPOLYGONSTIPPLE_PROC, _glPolygonStipple_, glPolygonStipple);
GL_GetFunc( PFN_GLPOPATTRIB_PROC, _glPopAttrib_, glPopAttrib);
GL_GetFunc( PFN_GLPOPCLIENTATTRIB_PROC, _glPopClientAttrib_, glPopClientAttrib);
GL_GetFunc( PFN_GLPOPMATRIX_PROC, _glPopMatrix_, glPopMatrix);
GL_GetFunc( PFN_GLPOPNAME_PROC, _glPopName_, glPopName);
GL_GetFunc( PFN_GLPRIORITIZETEXTURES_PROC, _glPrioritizeTextures_, glPrioritizeTextures);
GL_GetFunc( PFN_GLPUSHATTRIB_PROC, _glPushAttrib_, glPushAttrib);
GL_GetFunc( PFN_GLPUSHCLIENTATTRIB_PROC, _glPushClientAttrib_, glPushClientAttrib);
GL_GetFunc( PFN_GLPUSHMATRIX_PROC, _glPushMatrix_, glPushMatrix);
GL_GetFunc( PFN_GLPUSHNAME_PROC, _glPushName_, glPushName);
GL_GetFunc( PFN_GLRASTERPOS2D_PROC, _glRasterPos2d_, glRasterPos2d);
GL_GetFunc( PFN_GLRASTERPOS2DV_PROC, _glRasterPos2dv_, glRasterPos2dv);
GL_GetFunc( PFN_GLRASTERPOS2F_PROC, _glRasterPos2f_, glRasterPos2f);
GL_GetFunc( PFN_GLRASTERPOS2FV_PROC, _glRasterPos2fv_, glRasterPos2fv);
GL_GetFunc( PFN_GLRASTERPOS2I_PROC, _glRasterPos2i_, glRasterPos2i);
GL_GetFunc( PFN_GLRASTERPOS2IV_PROC, _glRasterPos2iv_, glRasterPos2iv);
GL_GetFunc( PFN_GLRASTERPOS2S_PROC, _glRasterPos2s_, glRasterPos2s);
GL_GetFunc( PFN_GLRASTERPOS2SV_PROC, _glRasterPos2sv_, glRasterPos2sv);
GL_GetFunc( PFN_GLRASTERPOS3D_PROC, _glRasterPos3d_, glRasterPos3d);
GL_GetFunc( PFN_GLRASTERPOS3DV_PROC, _glRasterPos3dv_, glRasterPos3dv);
GL_GetFunc( PFN_GLRASTERPOS3F_PROC, _glRasterPos3f_, glRasterPos3f);
GL_GetFunc( PFN_GLRASTERPOS3FV_PROC, _glRasterPos3fv_, glRasterPos3fv);
GL_GetFunc( PFN_GLRASTERPOS3I_PROC, _glRasterPos3i_, glRasterPos3i);
GL_GetFunc( PFN_GLRASTERPOS3IV_PROC, _glRasterPos3iv_, glRasterPos3iv);
GL_GetFunc( PFN_GLRASTERPOS3S_PROC, _glRasterPos3s_, glRasterPos3s);
GL_GetFunc( PFN_GLRASTERPOS3SV_PROC, _glRasterPos3sv_, glRasterPos3sv);
GL_GetFunc( PFN_GLRASTERPOS4D_PROC, _glRasterPos4d_, glRasterPos4d);
GL_GetFunc( PFN_GLRASTERPOS4DV_PROC, _glRasterPos4dv_, glRasterPos4dv);
GL_GetFunc( PFN_GLRASTERPOS4F_PROC, _glRasterPos4f_, glRasterPos4f);
GL_GetFunc( PFN_GLRASTERPOS4FV_PROC, _glRasterPos4fv_, glRasterPos4fv);
GL_GetFunc( PFN_GLRASTERPOS4I_PROC, _glRasterPos4i_, glRasterPos4i);
GL_GetFunc( PFN_GLRASTERPOS4IV_PROC, _glRasterPos4iv_, glRasterPos4iv);
GL_GetFunc( PFN_GLRASTERPOS4S_PROC, _glRasterPos4s_, glRasterPos4s);
GL_GetFunc( PFN_GLRASTERPOS4SV_PROC, _glRasterPos4sv_, glRasterPos4sv);
GL_GetFunc( PFN_GLRECTD_PROC, _glRectd_, glRectd);
GL_GetFunc( PFN_GLRECTDV_PROC, _glRectdv_, glRectdv);
GL_GetFunc( PFN_GLRECTF_PROC, _glRectf_, glRectf);
GL_GetFunc( PFN_GLRECTFV_PROC, _glRectfv_, glRectfv);
GL_GetFunc( PFN_GLRECTI_PROC, _glRecti_, glRecti);
GL_GetFunc( PFN_GLRECTIV_PROC, _glRectiv_, glRectiv);
GL_GetFunc( PFN_GLRECTS_PROC, _glRects_, glRects);
GL_GetFunc( PFN_GLRECTSV_PROC, _glRectsv_, glRectsv);
GL_GetFunc( PFN_GLRENDERMODE_PROC, _glRenderMode_, glRenderMode);
GL_GetFunc( PFN_GLROTATED_PROC, _glRotated_, glRotated);
GL_GetFunc( PFN_GLROTATEF_PROC, _glRotatef_, glRotatef);
GL_GetFunc( PFN_GLSCALED_PROC, _glScaled_, glScaled);
GL_GetFunc( PFN_GLSCALEF_PROC, _glScalef_, glScalef);
GL_GetFunc( PFN_GLSELECTBUFFER_PROC, _glSelectBuffer_, glSelectBuffer);
GL_GetFunc( PFN_GLSHADEMODEL_PROC, _glShadeModel_, glShadeModel);
GL_GetFunc( PFN_GLTEXCOORD1D_PROC, _glTexCoord1d_, glTexCoord1d);
GL_GetFunc( PFN_GLTEXCOORD1DV_PROC, _glTexCoord1dv_, glTexCoord1dv);
GL_GetFunc( PFN_GLTEXCOORD1F_PROC, _glTexCoord1f_, glTexCoord1f);
GL_GetFunc( PFN_GLTEXCOORD1FV_PROC, _glTexCoord1fv_, glTexCoord1fv);
GL_GetFunc( PFN_GLTEXCOORD1I_PROC, _glTexCoord1i_, glTexCoord1i);
GL_GetFunc( PFN_GLTEXCOORD1IV_PROC, _glTexCoord1iv_, glTexCoord1iv);
GL_GetFunc( PFN_GLTEXCOORD1S_PROC, _glTexCoord1s_, glTexCoord1s);
GL_GetFunc( PFN_GLTEXCOORD1SV_PROC, _glTexCoord1sv_, glTexCoord1sv);
GL_GetFunc( PFN_GLTEXCOORD2D_PROC, _glTexCoord2d_, glTexCoord2d);
GL_GetFunc( PFN_GLTEXCOORD2DV_PROC, _glTexCoord2dv_, glTexCoord2dv);
GL_GetFunc( PFN_GLTEXCOORD2F_PROC, _glTexCoord2f_, glTexCoord2f);
GL_GetFunc( PFN_GLTEXCOORD2FV_PROC, _glTexCoord2fv_, glTexCoord2fv);
GL_GetFunc( PFN_GLTEXCOORD2I_PROC, _glTexCoord2i_, glTexCoord2i);
GL_GetFunc( PFN_GLTEXCOORD2IV_PROC, _glTexCoord2iv_, glTexCoord2iv);
GL_GetFunc( PFN_GLTEXCOORD2S_PROC, _glTexCoord2s_, glTexCoord2s);
GL_GetFunc( PFN_GLTEXCOORD2SV_PROC, _glTexCoord2sv_, glTexCoord2sv);
GL_GetFunc( PFN_GLTEXCOORD3D_PROC, _glTexCoord3d_, glTexCoord3d);
GL_GetFunc( PFN_GLTEXCOORD3DV_PROC, _glTexCoord3dv_, glTexCoord3dv);
GL_GetFunc( PFN_GLTEXCOORD3F_PROC, _glTexCoord3f_, glTexCoord3f);
GL_GetFunc( PFN_GLTEXCOORD3FV_PROC, _glTexCoord3fv_, glTexCoord3fv);
GL_GetFunc( PFN_GLTEXCOORD3I_PROC, _glTexCoord3i_, glTexCoord3i);
GL_GetFunc( PFN_GLTEXCOORD3IV_PROC, _glTexCoord3iv_, glTexCoord3iv);
GL_GetFunc( PFN_GLTEXCOORD3S_PROC, _glTexCoord3s_, glTexCoord3s);
GL_GetFunc( PFN_GLTEXCOORD3SV_PROC, _glTexCoord3sv_, glTexCoord3sv);
GL_GetFunc( PFN_GLTEXCOORD4D_PROC, _glTexCoord4d_, glTexCoord4d);
GL_GetFunc( PFN_GLTEXCOORD4DV_PROC, _glTexCoord4dv_, glTexCoord4dv);
GL_GetFunc( PFN_GLTEXCOORD4F_PROC, _glTexCoord4f_, glTexCoord4f);
GL_GetFunc( PFN_GLTEXCOORD4FV_PROC, _glTexCoord4fv_, glTexCoord4fv);
GL_GetFunc( PFN_GLTEXCOORD4I_PROC, _glTexCoord4i_, glTexCoord4i);
GL_GetFunc( PFN_GLTEXCOORD4IV_PROC, _glTexCoord4iv_, glTexCoord4iv);
GL_GetFunc( PFN_GLTEXCOORD4S_PROC, _glTexCoord4s_, glTexCoord4s);
GL_GetFunc( PFN_GLTEXCOORD4SV_PROC, _glTexCoord4sv_, glTexCoord4sv);
GL_GetFunc( PFN_GLTEXCOORDPOINTER_PROC, _glTexCoordPointer_, glTexCoordPointer);
GL_GetFunc( PFN_GLTEXENVF_PROC, _glTexEnvf_, glTexEnvf);
GL_GetFunc( PFN_GLTEXENVFV_PROC, _glTexEnvfv_, glTexEnvfv);
GL_GetFunc( PFN_GLTEXENVI_PROC, _glTexEnvi_, glTexEnvi);
GL_GetFunc( PFN_GLTEXENVIV_PROC, _glTexEnviv_, glTexEnviv);
GL_GetFunc( PFN_GLTEXGEND_PROC, _glTexGend_, glTexGend);
GL_GetFunc( PFN_GLTEXGENDV_PROC, _glTexGendv_, glTexGendv);
GL_GetFunc( PFN_GLTEXGENF_PROC, _glTexGenf_, glTexGenf);
GL_GetFunc( PFN_GLTEXGENFV_PROC, _glTexGenfv_, glTexGenfv);
GL_GetFunc( PFN_GLTEXGENI_PROC, _glTexGeni_, glTexGeni);
GL_GetFunc( PFN_GLTEXGENIV_PROC, _glTexGeniv_, glTexGeniv);
GL_GetFunc( PFN_GLTRANSLATED_PROC, _glTranslated_, glTranslated);
GL_GetFunc( PFN_GLTRANSLATEF_PROC, _glTranslatef_, glTranslatef);
GL_GetFunc( PFN_GLVERTEX2D_PROC, _glVertex2d_, glVertex2d);
GL_GetFunc( PFN_GLVERTEX2DV_PROC, _glVertex2dv_, glVertex2dv);
GL_GetFunc( PFN_GLVERTEX2F_PROC, _glVertex2f_, glVertex2f);
GL_GetFunc( PFN_GLVERTEX2FV_PROC, _glVertex2fv_, glVertex2fv);
GL_GetFunc( PFN_GLVERTEX2I_PROC, _glVertex2i_, glVertex2i);
GL_GetFunc( PFN_GLVERTEX2IV_PROC, _glVertex2iv_, glVertex2iv);
GL_GetFunc( PFN_GLVERTEX2S_PROC, _glVertex2s_, glVertex2s);
GL_GetFunc( PFN_GLVERTEX2SV_PROC, _glVertex2sv_, glVertex2sv);
GL_GetFunc( PFN_GLVERTEX3D_PROC, _glVertex3d_, glVertex3d);
GL_GetFunc( PFN_GLVERTEX3DV_PROC, _glVertex3dv_, glVertex3dv);
GL_GetFunc( PFN_GLVERTEX3F_PROC, _glVertex3f_, glVertex3f);
GL_GetFunc( PFN_GLVERTEX3FV_PROC, _glVertex3fv_, glVertex3fv);
GL_GetFunc( PFN_GLVERTEX3I_PROC, _glVertex3i_, glVertex3i);
GL_GetFunc( PFN_GLVERTEX3IV_PROC, _glVertex3iv_, glVertex3iv);
GL_GetFunc( PFN_GLVERTEX3S_PROC, _glVertex3s_, glVertex3s);
GL_GetFunc( PFN_GLVERTEX3SV_PROC, _glVertex3sv_, glVertex3sv);
GL_GetFunc( PFN_GLVERTEX4D_PROC, _glVertex4d_, glVertex4d);
GL_GetFunc( PFN_GLVERTEX4DV_PROC, _glVertex4dv_, glVertex4dv);
GL_GetFunc( PFN_GLVERTEX4F_PROC, _glVertex4f_, glVertex4f);
GL_GetFunc( PFN_GLVERTEX4FV_PROC, _glVertex4fv_, glVertex4fv);
GL_GetFunc( PFN_GLVERTEX4I_PROC, _glVertex4i_, glVertex4i);
GL_GetFunc( PFN_GLVERTEX4IV_PROC, _glVertex4iv_, glVertex4iv);
GL_GetFunc( PFN_GLVERTEX4S_PROC, _glVertex4s_, glVertex4s);
GL_GetFunc( PFN_GLVERTEX4SV_PROC, _glVertex4sv_, glVertex4sv);
GL_GetFunc( PFN_GLVERTEXPOINTER_PROC, _glVertexPointer_, glVertexPointer);
#endif //GL_VERSION_1_11

#ifndef GL_ARB_color_buffer_float
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_color_buffer_float\n");
GL_GetFunc( PFN_GLCLAMPCOLORARB_PROC, _glClampColorARB_, glClampColorARB);
#endif //GL_ARB_color_buffer_float

// GL_ARB_compatibility

// GL_ARB_depth_texture

#ifndef GL_ARB_draw_buffers
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_draw_buffers\n");
GL_GetFunc( PFN_GLDRAWBUFFERSARB_PROC, _glDrawBuffersARB_, glDrawBuffersARB);
#endif //GL_ARB_draw_buffers

#ifndef GL_ARB_fragment_program
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_fragment_program\n");
GL_GetFunc( PFN_GLPROGRAMSTRINGARB_PROC, _glProgramStringARB_, glProgramStringARB);
GL_GetFunc( PFN_GLBINDPROGRAMARB_PROC, _glBindProgramARB_, glBindProgramARB);
GL_GetFunc( PFN_GLDELETEPROGRAMSARB_PROC, _glDeleteProgramsARB_, glDeleteProgramsARB);
GL_GetFunc( PFN_GLGENPROGRAMSARB_PROC, _glGenProgramsARB_, glGenProgramsARB);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETER4DARB_PROC, _glProgramEnvParameter4dARB_, glProgramEnvParameter4dARB);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETER4DVARB_PROC, _glProgramEnvParameter4dvARB_, glProgramEnvParameter4dvARB);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETER4FARB_PROC, _glProgramEnvParameter4fARB_, glProgramEnvParameter4fARB);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETER4FVARB_PROC, _glProgramEnvParameter4fvARB_, glProgramEnvParameter4fvARB);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETER4DARB_PROC, _glProgramLocalParameter4dARB_, glProgramLocalParameter4dARB);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETER4DVARB_PROC, _glProgramLocalParameter4dvARB_, glProgramLocalParameter4dvARB);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETER4FARB_PROC, _glProgramLocalParameter4fARB_, glProgramLocalParameter4fARB);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETER4FVARB_PROC, _glProgramLocalParameter4fvARB_, glProgramLocalParameter4fvARB);
GL_GetFunc( PFN_GLGETPROGRAMENVPARAMETERDVARB_PROC, _glGetProgramEnvParameterdvARB_, glGetProgramEnvParameterdvARB);
GL_GetFunc( PFN_GLGETPROGRAMENVPARAMETERFVARB_PROC, _glGetProgramEnvParameterfvARB_, glGetProgramEnvParameterfvARB);
GL_GetFunc( PFN_GLGETPROGRAMLOCALPARAMETERDVARB_PROC, _glGetProgramLocalParameterdvARB_, glGetProgramLocalParameterdvARB);
GL_GetFunc( PFN_GLGETPROGRAMLOCALPARAMETERFVARB_PROC, _glGetProgramLocalParameterfvARB_, glGetProgramLocalParameterfvARB);
GL_GetFunc( PFN_GLGETPROGRAMIVARB_PROC, _glGetProgramivARB_, glGetProgramivARB);
GL_GetFunc( PFN_GLGETPROGRAMSTRINGARB_PROC, _glGetProgramStringARB_, glGetProgramStringARB);
GL_GetFunc( PFN_GLISPROGRAMARB_PROC, _glIsProgramARB_, glIsProgramARB);
#endif //GL_ARB_fragment_program

// GL_ARB_fragment_program_shadow

// GL_ARB_fragment_shader

// GL_ARB_half_float_pixel

#ifndef GL_ARB_matrix_palette
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_matrix_palette\n");
GL_GetFunc( PFN_GLCURRENTPALETTEMATRIXARB_PROC, _glCurrentPaletteMatrixARB_, glCurrentPaletteMatrixARB);
GL_GetFunc( PFN_GLMATRIXINDEXUBVARB_PROC, _glMatrixIndexubvARB_, glMatrixIndexubvARB);
GL_GetFunc( PFN_GLMATRIXINDEXUSVARB_PROC, _glMatrixIndexusvARB_, glMatrixIndexusvARB);
GL_GetFunc( PFN_GLMATRIXINDEXUIVARB_PROC, _glMatrixIndexuivARB_, glMatrixIndexuivARB);
GL_GetFunc( PFN_GLMATRIXINDEXPOINTERARB_PROC, _glMatrixIndexPointerARB_, glMatrixIndexPointerARB);
#endif //GL_ARB_matrix_palette

#ifndef GL_ARB_multisample
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_multisample\n");
GL_GetFunc( PFN_GLSAMPLECOVERAGEARB_PROC, _glSampleCoverageARB_, glSampleCoverageARB);
#endif //GL_ARB_multisample

#ifndef GL_ARB_multitexture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_multitexture\n");
GL_GetFunc( PFN_GLACTIVETEXTUREARB_PROC, _glActiveTextureARB_, glActiveTextureARB);
GL_GetFunc( PFN_GLCLIENTACTIVETEXTUREARB_PROC, _glClientActiveTextureARB_, glClientActiveTextureARB);
GL_GetFunc( PFN_GLMULTITEXCOORD1DARB_PROC, _glMultiTexCoord1dARB_, glMultiTexCoord1dARB);
GL_GetFunc( PFN_GLMULTITEXCOORD1DVARB_PROC, _glMultiTexCoord1dvARB_, glMultiTexCoord1dvARB);
GL_GetFunc( PFN_GLMULTITEXCOORD1FARB_PROC, _glMultiTexCoord1fARB_, glMultiTexCoord1fARB);
GL_GetFunc( PFN_GLMULTITEXCOORD1FVARB_PROC, _glMultiTexCoord1fvARB_, glMultiTexCoord1fvARB);
GL_GetFunc( PFN_GLMULTITEXCOORD1IARB_PROC, _glMultiTexCoord1iARB_, glMultiTexCoord1iARB);
GL_GetFunc( PFN_GLMULTITEXCOORD1IVARB_PROC, _glMultiTexCoord1ivARB_, glMultiTexCoord1ivARB);
GL_GetFunc( PFN_GLMULTITEXCOORD1SARB_PROC, _glMultiTexCoord1sARB_, glMultiTexCoord1sARB);
GL_GetFunc( PFN_GLMULTITEXCOORD1SVARB_PROC, _glMultiTexCoord1svARB_, glMultiTexCoord1svARB);
GL_GetFunc( PFN_GLMULTITEXCOORD2DARB_PROC, _glMultiTexCoord2dARB_, glMultiTexCoord2dARB);
GL_GetFunc( PFN_GLMULTITEXCOORD2DVARB_PROC, _glMultiTexCoord2dvARB_, glMultiTexCoord2dvARB);
GL_GetFunc( PFN_GLMULTITEXCOORD2FARB_PROC, _glMultiTexCoord2fARB_, glMultiTexCoord2fARB);
GL_GetFunc( PFN_GLMULTITEXCOORD2FVARB_PROC, _glMultiTexCoord2fvARB_, glMultiTexCoord2fvARB);
GL_GetFunc( PFN_GLMULTITEXCOORD2IARB_PROC, _glMultiTexCoord2iARB_, glMultiTexCoord2iARB);
GL_GetFunc( PFN_GLMULTITEXCOORD2IVARB_PROC, _glMultiTexCoord2ivARB_, glMultiTexCoord2ivARB);
GL_GetFunc( PFN_GLMULTITEXCOORD2SARB_PROC, _glMultiTexCoord2sARB_, glMultiTexCoord2sARB);
GL_GetFunc( PFN_GLMULTITEXCOORD2SVARB_PROC, _glMultiTexCoord2svARB_, glMultiTexCoord2svARB);
GL_GetFunc( PFN_GLMULTITEXCOORD3DARB_PROC, _glMultiTexCoord3dARB_, glMultiTexCoord3dARB);
GL_GetFunc( PFN_GLMULTITEXCOORD3DVARB_PROC, _glMultiTexCoord3dvARB_, glMultiTexCoord3dvARB);
GL_GetFunc( PFN_GLMULTITEXCOORD3FARB_PROC, _glMultiTexCoord3fARB_, glMultiTexCoord3fARB);
GL_GetFunc( PFN_GLMULTITEXCOORD3FVARB_PROC, _glMultiTexCoord3fvARB_, glMultiTexCoord3fvARB);
GL_GetFunc( PFN_GLMULTITEXCOORD3IARB_PROC, _glMultiTexCoord3iARB_, glMultiTexCoord3iARB);
GL_GetFunc( PFN_GLMULTITEXCOORD3IVARB_PROC, _glMultiTexCoord3ivARB_, glMultiTexCoord3ivARB);
GL_GetFunc( PFN_GLMULTITEXCOORD3SARB_PROC, _glMultiTexCoord3sARB_, glMultiTexCoord3sARB);
GL_GetFunc( PFN_GLMULTITEXCOORD3SVARB_PROC, _glMultiTexCoord3svARB_, glMultiTexCoord3svARB);
GL_GetFunc( PFN_GLMULTITEXCOORD4DARB_PROC, _glMultiTexCoord4dARB_, glMultiTexCoord4dARB);
GL_GetFunc( PFN_GLMULTITEXCOORD4DVARB_PROC, _glMultiTexCoord4dvARB_, glMultiTexCoord4dvARB);
GL_GetFunc( PFN_GLMULTITEXCOORD4FARB_PROC, _glMultiTexCoord4fARB_, glMultiTexCoord4fARB);
GL_GetFunc( PFN_GLMULTITEXCOORD4FVARB_PROC, _glMultiTexCoord4fvARB_, glMultiTexCoord4fvARB);
GL_GetFunc( PFN_GLMULTITEXCOORD4IARB_PROC, _glMultiTexCoord4iARB_, glMultiTexCoord4iARB);
GL_GetFunc( PFN_GLMULTITEXCOORD4IVARB_PROC, _glMultiTexCoord4ivARB_, glMultiTexCoord4ivARB);
GL_GetFunc( PFN_GLMULTITEXCOORD4SARB_PROC, _glMultiTexCoord4sARB_, glMultiTexCoord4sARB);
GL_GetFunc( PFN_GLMULTITEXCOORD4SVARB_PROC, _glMultiTexCoord4svARB_, glMultiTexCoord4svARB);
#endif //GL_ARB_multitexture

#ifndef GL_ARB_occlusion_query
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_occlusion_query\n");
GL_GetFunc( PFN_GLGENQUERIESARB_PROC, _glGenQueriesARB_, glGenQueriesARB);
GL_GetFunc( PFN_GLDELETEQUERIESARB_PROC, _glDeleteQueriesARB_, glDeleteQueriesARB);
GL_GetFunc( PFN_GLISQUERYARB_PROC, _glIsQueryARB_, glIsQueryARB);
GL_GetFunc( PFN_GLBEGINQUERYARB_PROC, _glBeginQueryARB_, glBeginQueryARB);
GL_GetFunc( PFN_GLENDQUERYARB_PROC, _glEndQueryARB_, glEndQueryARB);
GL_GetFunc( PFN_GLGETQUERYIVARB_PROC, _glGetQueryivARB_, glGetQueryivARB);
GL_GetFunc( PFN_GLGETQUERYOBJECTIVARB_PROC, _glGetQueryObjectivARB_, glGetQueryObjectivARB);
GL_GetFunc( PFN_GLGETQUERYOBJECTUIVARB_PROC, _glGetQueryObjectuivARB_, glGetQueryObjectuivARB);
#endif //GL_ARB_occlusion_query

#ifndef GL_ARB_point_parameters
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_point_parameters\n");
GL_GetFunc( PFN_GLPOINTPARAMETERFARB_PROC, _glPointParameterfARB_, glPointParameterfARB);
GL_GetFunc( PFN_GLPOINTPARAMETERFVARB_PROC, _glPointParameterfvARB_, glPointParameterfvARB);
#endif //GL_ARB_point_parameters

// GL_ARB_point_sprite

#ifndef GL_ARB_shader_objects
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_shader_objects\n");
GL_GetFunc( PFN_GLDELETEOBJECTARB_PROC, _glDeleteObjectARB_, glDeleteObjectARB);
GL_GetFunc( PFN_GLGETHANDLEARB_PROC, _glGetHandleARB_, glGetHandleARB);
GL_GetFunc( PFN_GLDETACHOBJECTARB_PROC, _glDetachObjectARB_, glDetachObjectARB);
GL_GetFunc( PFN_GLCREATESHADEROBJECTARB_PROC, _glCreateShaderObjectARB_, glCreateShaderObjectARB);
GL_GetFunc( PFN_GLSHADERSOURCEARB_PROC, _glShaderSourceARB_, glShaderSourceARB);
GL_GetFunc( PFN_GLCOMPILESHADERARB_PROC, _glCompileShaderARB_, glCompileShaderARB);
GL_GetFunc( PFN_GLCREATEPROGRAMOBJECTARB_PROC, _glCreateProgramObjectARB_, glCreateProgramObjectARB);
GL_GetFunc( PFN_GLATTACHOBJECTARB_PROC, _glAttachObjectARB_, glAttachObjectARB);
GL_GetFunc( PFN_GLLINKPROGRAMARB_PROC, _glLinkProgramARB_, glLinkProgramARB);
GL_GetFunc( PFN_GLUSEPROGRAMOBJECTARB_PROC, _glUseProgramObjectARB_, glUseProgramObjectARB);
GL_GetFunc( PFN_GLVALIDATEPROGRAMARB_PROC, _glValidateProgramARB_, glValidateProgramARB);
GL_GetFunc( PFN_GLUNIFORM1FARB_PROC, _glUniform1fARB_, glUniform1fARB);
GL_GetFunc( PFN_GLUNIFORM2FARB_PROC, _glUniform2fARB_, glUniform2fARB);
GL_GetFunc( PFN_GLUNIFORM3FARB_PROC, _glUniform3fARB_, glUniform3fARB);
GL_GetFunc( PFN_GLUNIFORM4FARB_PROC, _glUniform4fARB_, glUniform4fARB);
GL_GetFunc( PFN_GLUNIFORM1IARB_PROC, _glUniform1iARB_, glUniform1iARB);
GL_GetFunc( PFN_GLUNIFORM2IARB_PROC, _glUniform2iARB_, glUniform2iARB);
GL_GetFunc( PFN_GLUNIFORM3IARB_PROC, _glUniform3iARB_, glUniform3iARB);
GL_GetFunc( PFN_GLUNIFORM4IARB_PROC, _glUniform4iARB_, glUniform4iARB);
GL_GetFunc( PFN_GLUNIFORM1FVARB_PROC, _glUniform1fvARB_, glUniform1fvARB);
GL_GetFunc( PFN_GLUNIFORM2FVARB_PROC, _glUniform2fvARB_, glUniform2fvARB);
GL_GetFunc( PFN_GLUNIFORM3FVARB_PROC, _glUniform3fvARB_, glUniform3fvARB);
GL_GetFunc( PFN_GLUNIFORM4FVARB_PROC, _glUniform4fvARB_, glUniform4fvARB);
GL_GetFunc( PFN_GLUNIFORM1IVARB_PROC, _glUniform1ivARB_, glUniform1ivARB);
GL_GetFunc( PFN_GLUNIFORM2IVARB_PROC, _glUniform2ivARB_, glUniform2ivARB);
GL_GetFunc( PFN_GLUNIFORM3IVARB_PROC, _glUniform3ivARB_, glUniform3ivARB);
GL_GetFunc( PFN_GLUNIFORM4IVARB_PROC, _glUniform4ivARB_, glUniform4ivARB);
GL_GetFunc( PFN_GLUNIFORMMATRIX2FVARB_PROC, _glUniformMatrix2fvARB_, glUniformMatrix2fvARB);
GL_GetFunc( PFN_GLUNIFORMMATRIX3FVARB_PROC, _glUniformMatrix3fvARB_, glUniformMatrix3fvARB);
GL_GetFunc( PFN_GLUNIFORMMATRIX4FVARB_PROC, _glUniformMatrix4fvARB_, glUniformMatrix4fvARB);
GL_GetFunc( PFN_GLGETOBJECTPARAMETERFVARB_PROC, _glGetObjectParameterfvARB_, glGetObjectParameterfvARB);
GL_GetFunc( PFN_GLGETOBJECTPARAMETERIVARB_PROC, _glGetObjectParameterivARB_, glGetObjectParameterivARB);
GL_GetFunc( PFN_GLGETINFOLOGARB_PROC, _glGetInfoLogARB_, glGetInfoLogARB);
GL_GetFunc( PFN_GLGETATTACHEDOBJECTSARB_PROC, _glGetAttachedObjectsARB_, glGetAttachedObjectsARB);
GL_GetFunc( PFN_GLGETUNIFORMLOCATIONARB_PROC, _glGetUniformLocationARB_, glGetUniformLocationARB);
GL_GetFunc( PFN_GLGETACTIVEUNIFORMARB_PROC, _glGetActiveUniformARB_, glGetActiveUniformARB);
GL_GetFunc( PFN_GLGETUNIFORMFVARB_PROC, _glGetUniformfvARB_, glGetUniformfvARB);
GL_GetFunc( PFN_GLGETUNIFORMIVARB_PROC, _glGetUniformivARB_, glGetUniformivARB);
GL_GetFunc( PFN_GLGETSHADERSOURCEARB_PROC, _glGetShaderSourceARB_, glGetShaderSourceARB);
#endif //GL_ARB_shader_objects

// GL_ARB_shader_texture_lod

// GL_ARB_shading_language_100

// GL_ARB_shadow

// GL_ARB_shadow_ambient

#ifndef GL_ARB_texture_compression
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_texture_compression\n");
GL_GetFunc( PFN_GLCOMPRESSEDTEXIMAGE3DARB_PROC, _glCompressedTexImage3DARB_, glCompressedTexImage3DARB);
GL_GetFunc( PFN_GLCOMPRESSEDTEXIMAGE2DARB_PROC, _glCompressedTexImage2DARB_, glCompressedTexImage2DARB);
GL_GetFunc( PFN_GLCOMPRESSEDTEXIMAGE1DARB_PROC, _glCompressedTexImage1DARB_, glCompressedTexImage1DARB);
GL_GetFunc( PFN_GLCOMPRESSEDTEXSUBIMAGE3DARB_PROC, _glCompressedTexSubImage3DARB_, glCompressedTexSubImage3DARB);
GL_GetFunc( PFN_GLCOMPRESSEDTEXSUBIMAGE2DARB_PROC, _glCompressedTexSubImage2DARB_, glCompressedTexSubImage2DARB);
GL_GetFunc( PFN_GLCOMPRESSEDTEXSUBIMAGE1DARB_PROC, _glCompressedTexSubImage1DARB_, glCompressedTexSubImage1DARB);
GL_GetFunc( PFN_GLGETCOMPRESSEDTEXIMAGEARB_PROC, _glGetCompressedTexImageARB_, glGetCompressedTexImageARB);
#endif //GL_ARB_texture_compression

// GL_ARB_texture_cube_map

// GL_ARB_texture_env_add

// GL_ARB_texture_env_combine

// GL_ARB_texture_env_crossbar

// GL_ARB_texture_env_dot3

// GL_ARB_texture_float

// GL_ARB_texture_rectangle

#ifndef GL_ARB_transpose_matrix
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_transpose_matrix\n");
GL_GetFunc( PFN_GLLOADTRANSPOSEMATRIXFARB_PROC, _glLoadTransposeMatrixfARB_, glLoadTransposeMatrixfARB);
GL_GetFunc( PFN_GLLOADTRANSPOSEMATRIXDARB_PROC, _glLoadTransposeMatrixdARB_, glLoadTransposeMatrixdARB);
GL_GetFunc( PFN_GLMULTTRANSPOSEMATRIXFARB_PROC, _glMultTransposeMatrixfARB_, glMultTransposeMatrixfARB);
GL_GetFunc( PFN_GLMULTTRANSPOSEMATRIXDARB_PROC, _glMultTransposeMatrixdARB_, glMultTransposeMatrixdARB);
#endif //GL_ARB_transpose_matrix

#ifndef GL_ARB_vertex_blend
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_vertex_blend\n");
GL_GetFunc( PFN_GLWEIGHTBVARB_PROC, _glWeightbvARB_, glWeightbvARB);
GL_GetFunc( PFN_GLWEIGHTSVARB_PROC, _glWeightsvARB_, glWeightsvARB);
GL_GetFunc( PFN_GLWEIGHTIVARB_PROC, _glWeightivARB_, glWeightivARB);
GL_GetFunc( PFN_GLWEIGHTFVARB_PROC, _glWeightfvARB_, glWeightfvARB);
GL_GetFunc( PFN_GLWEIGHTDVARB_PROC, _glWeightdvARB_, glWeightdvARB);
GL_GetFunc( PFN_GLWEIGHTUBVARB_PROC, _glWeightubvARB_, glWeightubvARB);
GL_GetFunc( PFN_GLWEIGHTUSVARB_PROC, _glWeightusvARB_, glWeightusvARB);
GL_GetFunc( PFN_GLWEIGHTUIVARB_PROC, _glWeightuivARB_, glWeightuivARB);
GL_GetFunc( PFN_GLWEIGHTPOINTERARB_PROC, _glWeightPointerARB_, glWeightPointerARB);
GL_GetFunc( PFN_GLVERTEXBLENDARB_PROC, _glVertexBlendARB_, glVertexBlendARB);
#endif //GL_ARB_vertex_blend

#ifndef GL_ARB_vertex_buffer_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_vertex_buffer_object\n");
GL_GetFunc( PFN_GLBINDBUFFERARB_PROC, _glBindBufferARB_, glBindBufferARB);
GL_GetFunc( PFN_GLDELETEBUFFERSARB_PROC, _glDeleteBuffersARB_, glDeleteBuffersARB);
GL_GetFunc( PFN_GLGENBUFFERSARB_PROC, _glGenBuffersARB_, glGenBuffersARB);
GL_GetFunc( PFN_GLISBUFFERARB_PROC, _glIsBufferARB_, glIsBufferARB);
GL_GetFunc( PFN_GLBUFFERDATAARB_PROC, _glBufferDataARB_, glBufferDataARB);
GL_GetFunc( PFN_GLBUFFERSUBDATAARB_PROC, _glBufferSubDataARB_, glBufferSubDataARB);
GL_GetFunc( PFN_GLGETBUFFERSUBDATAARB_PROC, _glGetBufferSubDataARB_, glGetBufferSubDataARB);
GL_GetFunc( PFN_GLMAPBUFFERARB_PROC, _glMapBufferARB_, glMapBufferARB);
GL_GetFunc( PFN_GLUNMAPBUFFERARB_PROC, _glUnmapBufferARB_, glUnmapBufferARB);
GL_GetFunc( PFN_GLGETBUFFERPARAMETERIVARB_PROC, _glGetBufferParameterivARB_, glGetBufferParameterivARB);
GL_GetFunc( PFN_GLGETBUFFERPOINTERVARB_PROC, _glGetBufferPointervARB_, glGetBufferPointervARB);
#endif //GL_ARB_vertex_buffer_object

#ifndef GL_ARB_vertex_program
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_vertex_program\n");
GL_GetFunc( PFN_GLVERTEXATTRIB1DARB_PROC, _glVertexAttrib1dARB_, glVertexAttrib1dARB);
GL_GetFunc( PFN_GLVERTEXATTRIB1DVARB_PROC, _glVertexAttrib1dvARB_, glVertexAttrib1dvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB1FARB_PROC, _glVertexAttrib1fARB_, glVertexAttrib1fARB);
GL_GetFunc( PFN_GLVERTEXATTRIB1FVARB_PROC, _glVertexAttrib1fvARB_, glVertexAttrib1fvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB1SARB_PROC, _glVertexAttrib1sARB_, glVertexAttrib1sARB);
GL_GetFunc( PFN_GLVERTEXATTRIB1SVARB_PROC, _glVertexAttrib1svARB_, glVertexAttrib1svARB);
GL_GetFunc( PFN_GLVERTEXATTRIB2DARB_PROC, _glVertexAttrib2dARB_, glVertexAttrib2dARB);
GL_GetFunc( PFN_GLVERTEXATTRIB2DVARB_PROC, _glVertexAttrib2dvARB_, glVertexAttrib2dvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB2FARB_PROC, _glVertexAttrib2fARB_, glVertexAttrib2fARB);
GL_GetFunc( PFN_GLVERTEXATTRIB2FVARB_PROC, _glVertexAttrib2fvARB_, glVertexAttrib2fvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB2SARB_PROC, _glVertexAttrib2sARB_, glVertexAttrib2sARB);
GL_GetFunc( PFN_GLVERTEXATTRIB2SVARB_PROC, _glVertexAttrib2svARB_, glVertexAttrib2svARB);
GL_GetFunc( PFN_GLVERTEXATTRIB3DARB_PROC, _glVertexAttrib3dARB_, glVertexAttrib3dARB);
GL_GetFunc( PFN_GLVERTEXATTRIB3DVARB_PROC, _glVertexAttrib3dvARB_, glVertexAttrib3dvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB3FARB_PROC, _glVertexAttrib3fARB_, glVertexAttrib3fARB);
GL_GetFunc( PFN_GLVERTEXATTRIB3FVARB_PROC, _glVertexAttrib3fvARB_, glVertexAttrib3fvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB3SARB_PROC, _glVertexAttrib3sARB_, glVertexAttrib3sARB);
GL_GetFunc( PFN_GLVERTEXATTRIB3SVARB_PROC, _glVertexAttrib3svARB_, glVertexAttrib3svARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4NBVARB_PROC, _glVertexAttrib4NbvARB_, glVertexAttrib4NbvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4NIVARB_PROC, _glVertexAttrib4NivARB_, glVertexAttrib4NivARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4NSVARB_PROC, _glVertexAttrib4NsvARB_, glVertexAttrib4NsvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4NUBARB_PROC, _glVertexAttrib4NubARB_, glVertexAttrib4NubARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4NUBVARB_PROC, _glVertexAttrib4NubvARB_, glVertexAttrib4NubvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4NUIVARB_PROC, _glVertexAttrib4NuivARB_, glVertexAttrib4NuivARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4NUSVARB_PROC, _glVertexAttrib4NusvARB_, glVertexAttrib4NusvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4BVARB_PROC, _glVertexAttrib4bvARB_, glVertexAttrib4bvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4DARB_PROC, _glVertexAttrib4dARB_, glVertexAttrib4dARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4DVARB_PROC, _glVertexAttrib4dvARB_, glVertexAttrib4dvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4FARB_PROC, _glVertexAttrib4fARB_, glVertexAttrib4fARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4FVARB_PROC, _glVertexAttrib4fvARB_, glVertexAttrib4fvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4IVARB_PROC, _glVertexAttrib4ivARB_, glVertexAttrib4ivARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4SARB_PROC, _glVertexAttrib4sARB_, glVertexAttrib4sARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4SVARB_PROC, _glVertexAttrib4svARB_, glVertexAttrib4svARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4UBVARB_PROC, _glVertexAttrib4ubvARB_, glVertexAttrib4ubvARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4UIVARB_PROC, _glVertexAttrib4uivARB_, glVertexAttrib4uivARB);
GL_GetFunc( PFN_GLVERTEXATTRIB4USVARB_PROC, _glVertexAttrib4usvARB_, glVertexAttrib4usvARB);
GL_GetFunc( PFN_GLVERTEXATTRIBPOINTERARB_PROC, _glVertexAttribPointerARB_, glVertexAttribPointerARB);
GL_GetFunc( PFN_GLENABLEVERTEXATTRIBARRAYARB_PROC, _glEnableVertexAttribArrayARB_, glEnableVertexAttribArrayARB);
GL_GetFunc( PFN_GLDISABLEVERTEXATTRIBARRAYARB_PROC, _glDisableVertexAttribArrayARB_, glDisableVertexAttribArrayARB);
GL_GetFunc( PFN_GLGETVERTEXATTRIBDVARB_PROC, _glGetVertexAttribdvARB_, glGetVertexAttribdvARB);
GL_GetFunc( PFN_GLGETVERTEXATTRIBFVARB_PROC, _glGetVertexAttribfvARB_, glGetVertexAttribfvARB);
GL_GetFunc( PFN_GLGETVERTEXATTRIBIVARB_PROC, _glGetVertexAttribivARB_, glGetVertexAttribivARB);
GL_GetFunc( PFN_GLGETVERTEXATTRIBPOINTERVARB_PROC, _glGetVertexAttribPointervARB_, glGetVertexAttribPointervARB);
#endif //GL_ARB_vertex_program

#ifndef GL_ARB_vertex_shader
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_vertex_shader\n");
GL_GetFunc( PFN_GLBINDATTRIBLOCATIONARB_PROC, _glBindAttribLocationARB_, glBindAttribLocationARB);
GL_GetFunc( PFN_GLGETACTIVEATTRIBARB_PROC, _glGetActiveAttribARB_, glGetActiveAttribARB);
GL_GetFunc( PFN_GLGETATTRIBLOCATIONARB_PROC, _glGetAttribLocationARB_, glGetAttribLocationARB);
#endif //GL_ARB_vertex_shader

#ifndef GL_ARB_window_pos
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ARB_window_pos\n");
GL_GetFunc( PFN_GLWINDOWPOS2DARB_PROC, _glWindowPos2dARB_, glWindowPos2dARB);
GL_GetFunc( PFN_GLWINDOWPOS2DVARB_PROC, _glWindowPos2dvARB_, glWindowPos2dvARB);
GL_GetFunc( PFN_GLWINDOWPOS2FARB_PROC, _glWindowPos2fARB_, glWindowPos2fARB);
GL_GetFunc( PFN_GLWINDOWPOS2FVARB_PROC, _glWindowPos2fvARB_, glWindowPos2fvARB);
GL_GetFunc( PFN_GLWINDOWPOS2IARB_PROC, _glWindowPos2iARB_, glWindowPos2iARB);
GL_GetFunc( PFN_GLWINDOWPOS2IVARB_PROC, _glWindowPos2ivARB_, glWindowPos2ivARB);
GL_GetFunc( PFN_GLWINDOWPOS2SARB_PROC, _glWindowPos2sARB_, glWindowPos2sARB);
GL_GetFunc( PFN_GLWINDOWPOS2SVARB_PROC, _glWindowPos2svARB_, glWindowPos2svARB);
GL_GetFunc( PFN_GLWINDOWPOS3DARB_PROC, _glWindowPos3dARB_, glWindowPos3dARB);
GL_GetFunc( PFN_GLWINDOWPOS3DVARB_PROC, _glWindowPos3dvARB_, glWindowPos3dvARB);
GL_GetFunc( PFN_GLWINDOWPOS3FARB_PROC, _glWindowPos3fARB_, glWindowPos3fARB);
GL_GetFunc( PFN_GLWINDOWPOS3FVARB_PROC, _glWindowPos3fvARB_, glWindowPos3fvARB);
GL_GetFunc( PFN_GLWINDOWPOS3IARB_PROC, _glWindowPos3iARB_, glWindowPos3iARB);
GL_GetFunc( PFN_GLWINDOWPOS3IVARB_PROC, _glWindowPos3ivARB_, glWindowPos3ivARB);
GL_GetFunc( PFN_GLWINDOWPOS3SARB_PROC, _glWindowPos3sARB_, glWindowPos3sARB);
GL_GetFunc( PFN_GLWINDOWPOS3SVARB_PROC, _glWindowPos3svARB_, glWindowPos3svARB);
#endif //GL_ARB_window_pos

#ifndef GL_OES_byte_coordinates
LOG_fprintf(LogGlGetFunctions_py, "\nGL_OES_byte_coordinates\n");
GL_GetFunc( PFN_GLMULTITEXCOORD1BOES_PROC, _glMultiTexCoord1bOES_, glMultiTexCoord1bOES);
GL_GetFunc( PFN_GLMULTITEXCOORD1BVOES_PROC, _glMultiTexCoord1bvOES_, glMultiTexCoord1bvOES);
GL_GetFunc( PFN_GLMULTITEXCOORD2BOES_PROC, _glMultiTexCoord2bOES_, glMultiTexCoord2bOES);
GL_GetFunc( PFN_GLMULTITEXCOORD2BVOES_PROC, _glMultiTexCoord2bvOES_, glMultiTexCoord2bvOES);
GL_GetFunc( PFN_GLMULTITEXCOORD3BOES_PROC, _glMultiTexCoord3bOES_, glMultiTexCoord3bOES);
GL_GetFunc( PFN_GLMULTITEXCOORD3BVOES_PROC, _glMultiTexCoord3bvOES_, glMultiTexCoord3bvOES);
GL_GetFunc( PFN_GLMULTITEXCOORD4BOES_PROC, _glMultiTexCoord4bOES_, glMultiTexCoord4bOES);
GL_GetFunc( PFN_GLMULTITEXCOORD4BVOES_PROC, _glMultiTexCoord4bvOES_, glMultiTexCoord4bvOES);
GL_GetFunc( PFN_GLTEXCOORD1BOES_PROC, _glTexCoord1bOES_, glTexCoord1bOES);
GL_GetFunc( PFN_GLTEXCOORD1BVOES_PROC, _glTexCoord1bvOES_, glTexCoord1bvOES);
GL_GetFunc( PFN_GLTEXCOORD2BOES_PROC, _glTexCoord2bOES_, glTexCoord2bOES);
GL_GetFunc( PFN_GLTEXCOORD2BVOES_PROC, _glTexCoord2bvOES_, glTexCoord2bvOES);
GL_GetFunc( PFN_GLTEXCOORD3BOES_PROC, _glTexCoord3bOES_, glTexCoord3bOES);
GL_GetFunc( PFN_GLTEXCOORD3BVOES_PROC, _glTexCoord3bvOES_, glTexCoord3bvOES);
GL_GetFunc( PFN_GLTEXCOORD4BOES_PROC, _glTexCoord4bOES_, glTexCoord4bOES);
GL_GetFunc( PFN_GLTEXCOORD4BVOES_PROC, _glTexCoord4bvOES_, glTexCoord4bvOES);
GL_GetFunc( PFN_GLVERTEX2BOES_PROC, _glVertex2bOES_, glVertex2bOES);
GL_GetFunc( PFN_GLVERTEX2BVOES_PROC, _glVertex2bvOES_, glVertex2bvOES);
GL_GetFunc( PFN_GLVERTEX3BOES_PROC, _glVertex3bOES_, glVertex3bOES);
GL_GetFunc( PFN_GLVERTEX3BVOES_PROC, _glVertex3bvOES_, glVertex3bvOES);
GL_GetFunc( PFN_GLVERTEX4BOES_PROC, _glVertex4bOES_, glVertex4bOES);
GL_GetFunc( PFN_GLVERTEX4BVOES_PROC, _glVertex4bvOES_, glVertex4bvOES);
#endif //GL_OES_byte_coordinates

// GL_OES_compressed_paletted_texture

#ifndef GL_OES_fixed_point
LOG_fprintf(LogGlGetFunctions_py, "\nGL_OES_fixed_point\n");
GL_GetFunc( PFN_GLALPHAFUNCXOES_PROC, _glAlphaFuncxOES_, glAlphaFuncxOES);
GL_GetFunc( PFN_GLCLEARCOLORXOES_PROC, _glClearColorxOES_, glClearColorxOES);
GL_GetFunc( PFN_GLCLEARDEPTHXOES_PROC, _glClearDepthxOES_, glClearDepthxOES);
GL_GetFunc( PFN_GLCLIPPLANEXOES_PROC, _glClipPlanexOES_, glClipPlanexOES);
GL_GetFunc( PFN_GLCOLOR4XOES_PROC, _glColor4xOES_, glColor4xOES);
GL_GetFunc( PFN_GLDEPTHRANGEXOES_PROC, _glDepthRangexOES_, glDepthRangexOES);
GL_GetFunc( PFN_GLFOGXOES_PROC, _glFogxOES_, glFogxOES);
GL_GetFunc( PFN_GLFOGXVOES_PROC, _glFogxvOES_, glFogxvOES);
GL_GetFunc( PFN_GLFRUSTUMXOES_PROC, _glFrustumxOES_, glFrustumxOES);
GL_GetFunc( PFN_GLGETCLIPPLANEXOES_PROC, _glGetClipPlanexOES_, glGetClipPlanexOES);
GL_GetFunc( PFN_GLGETFIXEDVOES_PROC, _glGetFixedvOES_, glGetFixedvOES);
GL_GetFunc( PFN_GLGETTEXENVXVOES_PROC, _glGetTexEnvxvOES_, glGetTexEnvxvOES);
GL_GetFunc( PFN_GLGETTEXPARAMETERXVOES_PROC, _glGetTexParameterxvOES_, glGetTexParameterxvOES);
GL_GetFunc( PFN_GLLIGHTMODELXOES_PROC, _glLightModelxOES_, glLightModelxOES);
GL_GetFunc( PFN_GLLIGHTMODELXVOES_PROC, _glLightModelxvOES_, glLightModelxvOES);
GL_GetFunc( PFN_GLLIGHTXOES_PROC, _glLightxOES_, glLightxOES);
GL_GetFunc( PFN_GLLIGHTXVOES_PROC, _glLightxvOES_, glLightxvOES);
GL_GetFunc( PFN_GLLINEWIDTHXOES_PROC, _glLineWidthxOES_, glLineWidthxOES);
GL_GetFunc( PFN_GLLOADMATRIXXOES_PROC, _glLoadMatrixxOES_, glLoadMatrixxOES);
GL_GetFunc( PFN_GLMATERIALXOES_PROC, _glMaterialxOES_, glMaterialxOES);
GL_GetFunc( PFN_GLMATERIALXVOES_PROC, _glMaterialxvOES_, glMaterialxvOES);
GL_GetFunc( PFN_GLMULTMATRIXXOES_PROC, _glMultMatrixxOES_, glMultMatrixxOES);
GL_GetFunc( PFN_GLMULTITEXCOORD4XOES_PROC, _glMultiTexCoord4xOES_, glMultiTexCoord4xOES);
GL_GetFunc( PFN_GLNORMAL3XOES_PROC, _glNormal3xOES_, glNormal3xOES);
GL_GetFunc( PFN_GLORTHOXOES_PROC, _glOrthoxOES_, glOrthoxOES);
GL_GetFunc( PFN_GLPOINTPARAMETERXVOES_PROC, _glPointParameterxvOES_, glPointParameterxvOES);
GL_GetFunc( PFN_GLPOINTSIZEXOES_PROC, _glPointSizexOES_, glPointSizexOES);
GL_GetFunc( PFN_GLPOLYGONOFFSETXOES_PROC, _glPolygonOffsetxOES_, glPolygonOffsetxOES);
GL_GetFunc( PFN_GLROTATEXOES_PROC, _glRotatexOES_, glRotatexOES);
GL_GetFunc( PFN_GLSCALEXOES_PROC, _glScalexOES_, glScalexOES);
GL_GetFunc( PFN_GLTEXENVXOES_PROC, _glTexEnvxOES_, glTexEnvxOES);
GL_GetFunc( PFN_GLTEXENVXVOES_PROC, _glTexEnvxvOES_, glTexEnvxvOES);
GL_GetFunc( PFN_GLTEXPARAMETERXOES_PROC, _glTexParameterxOES_, glTexParameterxOES);
GL_GetFunc( PFN_GLTEXPARAMETERXVOES_PROC, _glTexParameterxvOES_, glTexParameterxvOES);
GL_GetFunc( PFN_GLTRANSLATEXOES_PROC, _glTranslatexOES_, glTranslatexOES);
GL_GetFunc( PFN_GLACCUMXOES_PROC, _glAccumxOES_, glAccumxOES);
GL_GetFunc( PFN_GLBITMAPXOES_PROC, _glBitmapxOES_, glBitmapxOES);
GL_GetFunc( PFN_GLBLENDCOLORXOES_PROC, _glBlendColorxOES_, glBlendColorxOES);
GL_GetFunc( PFN_GLCLEARACCUMXOES_PROC, _glClearAccumxOES_, glClearAccumxOES);
GL_GetFunc( PFN_GLCOLOR3XOES_PROC, _glColor3xOES_, glColor3xOES);
GL_GetFunc( PFN_GLCOLOR3XVOES_PROC, _glColor3xvOES_, glColor3xvOES);
GL_GetFunc( PFN_GLCOLOR4XVOES_PROC, _glColor4xvOES_, glColor4xvOES);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERXOES_PROC, _glConvolutionParameterxOES_, glConvolutionParameterxOES);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERXVOES_PROC, _glConvolutionParameterxvOES_, glConvolutionParameterxvOES);
GL_GetFunc( PFN_GLEVALCOORD1XOES_PROC, _glEvalCoord1xOES_, glEvalCoord1xOES);
GL_GetFunc( PFN_GLEVALCOORD1XVOES_PROC, _glEvalCoord1xvOES_, glEvalCoord1xvOES);
GL_GetFunc( PFN_GLEVALCOORD2XOES_PROC, _glEvalCoord2xOES_, glEvalCoord2xOES);
GL_GetFunc( PFN_GLEVALCOORD2XVOES_PROC, _glEvalCoord2xvOES_, glEvalCoord2xvOES);
GL_GetFunc( PFN_GLFEEDBACKBUFFERXOES_PROC, _glFeedbackBufferxOES_, glFeedbackBufferxOES);
GL_GetFunc( PFN_GLGETCONVOLUTIONPARAMETERXVOES_PROC, _glGetConvolutionParameterxvOES_, glGetConvolutionParameterxvOES);
GL_GetFunc( PFN_GLGETHISTOGRAMPARAMETERXVOES_PROC, _glGetHistogramParameterxvOES_, glGetHistogramParameterxvOES);
GL_GetFunc( PFN_GLGETLIGHTXOES_PROC, _glGetLightxOES_, glGetLightxOES);
GL_GetFunc( PFN_GLGETMAPXVOES_PROC, _glGetMapxvOES_, glGetMapxvOES);
GL_GetFunc( PFN_GLGETMATERIALXOES_PROC, _glGetMaterialxOES_, glGetMaterialxOES);
GL_GetFunc( PFN_GLGETPIXELMAPXV_PROC, _glGetPixelMapxv_, glGetPixelMapxv);
GL_GetFunc( PFN_GLGETTEXGENXVOES_PROC, _glGetTexGenxvOES_, glGetTexGenxvOES);
GL_GetFunc( PFN_GLGETTEXLEVELPARAMETERXVOES_PROC, _glGetTexLevelParameterxvOES_, glGetTexLevelParameterxvOES);
GL_GetFunc( PFN_GLINDEXXOES_PROC, _glIndexxOES_, glIndexxOES);
GL_GetFunc( PFN_GLINDEXXVOES_PROC, _glIndexxvOES_, glIndexxvOES);
GL_GetFunc( PFN_GLLOADTRANSPOSEMATRIXXOES_PROC, _glLoadTransposeMatrixxOES_, glLoadTransposeMatrixxOES);
GL_GetFunc( PFN_GLMAP1XOES_PROC, _glMap1xOES_, glMap1xOES);
GL_GetFunc( PFN_GLMAP2XOES_PROC, _glMap2xOES_, glMap2xOES);
GL_GetFunc( PFN_GLMAPGRID1XOES_PROC, _glMapGrid1xOES_, glMapGrid1xOES);
GL_GetFunc( PFN_GLMAPGRID2XOES_PROC, _glMapGrid2xOES_, glMapGrid2xOES);
GL_GetFunc( PFN_GLMULTTRANSPOSEMATRIXXOES_PROC, _glMultTransposeMatrixxOES_, glMultTransposeMatrixxOES);
GL_GetFunc( PFN_GLMULTITEXCOORD1XOES_PROC, _glMultiTexCoord1xOES_, glMultiTexCoord1xOES);
GL_GetFunc( PFN_GLMULTITEXCOORD1XVOES_PROC, _glMultiTexCoord1xvOES_, glMultiTexCoord1xvOES);
GL_GetFunc( PFN_GLMULTITEXCOORD2XOES_PROC, _glMultiTexCoord2xOES_, glMultiTexCoord2xOES);
GL_GetFunc( PFN_GLMULTITEXCOORD2XVOES_PROC, _glMultiTexCoord2xvOES_, glMultiTexCoord2xvOES);
GL_GetFunc( PFN_GLMULTITEXCOORD3XOES_PROC, _glMultiTexCoord3xOES_, glMultiTexCoord3xOES);
GL_GetFunc( PFN_GLMULTITEXCOORD3XVOES_PROC, _glMultiTexCoord3xvOES_, glMultiTexCoord3xvOES);
GL_GetFunc( PFN_GLMULTITEXCOORD4XVOES_PROC, _glMultiTexCoord4xvOES_, glMultiTexCoord4xvOES);
GL_GetFunc( PFN_GLNORMAL3XVOES_PROC, _glNormal3xvOES_, glNormal3xvOES);
GL_GetFunc( PFN_GLPASSTHROUGHXOES_PROC, _glPassThroughxOES_, glPassThroughxOES);
GL_GetFunc( PFN_GLPIXELMAPX_PROC, _glPixelMapx_, glPixelMapx);
GL_GetFunc( PFN_GLPIXELSTOREX_PROC, _glPixelStorex_, glPixelStorex);
GL_GetFunc( PFN_GLPIXELTRANSFERXOES_PROC, _glPixelTransferxOES_, glPixelTransferxOES);
GL_GetFunc( PFN_GLPIXELZOOMXOES_PROC, _glPixelZoomxOES_, glPixelZoomxOES);
GL_GetFunc( PFN_GLPRIORITIZETEXTURESXOES_PROC, _glPrioritizeTexturesxOES_, glPrioritizeTexturesxOES);
GL_GetFunc( PFN_GLRASTERPOS2XOES_PROC, _glRasterPos2xOES_, glRasterPos2xOES);
GL_GetFunc( PFN_GLRASTERPOS2XVOES_PROC, _glRasterPos2xvOES_, glRasterPos2xvOES);
GL_GetFunc( PFN_GLRASTERPOS3XOES_PROC, _glRasterPos3xOES_, glRasterPos3xOES);
GL_GetFunc( PFN_GLRASTERPOS3XVOES_PROC, _glRasterPos3xvOES_, glRasterPos3xvOES);
GL_GetFunc( PFN_GLRASTERPOS4XOES_PROC, _glRasterPos4xOES_, glRasterPos4xOES);
GL_GetFunc( PFN_GLRASTERPOS4XVOES_PROC, _glRasterPos4xvOES_, glRasterPos4xvOES);
GL_GetFunc( PFN_GLRECTXOES_PROC, _glRectxOES_, glRectxOES);
GL_GetFunc( PFN_GLRECTXVOES_PROC, _glRectxvOES_, glRectxvOES);
GL_GetFunc( PFN_GLTEXCOORD1XOES_PROC, _glTexCoord1xOES_, glTexCoord1xOES);
GL_GetFunc( PFN_GLTEXCOORD1XVOES_PROC, _glTexCoord1xvOES_, glTexCoord1xvOES);
GL_GetFunc( PFN_GLTEXCOORD2XOES_PROC, _glTexCoord2xOES_, glTexCoord2xOES);
GL_GetFunc( PFN_GLTEXCOORD2XVOES_PROC, _glTexCoord2xvOES_, glTexCoord2xvOES);
GL_GetFunc( PFN_GLTEXCOORD3XOES_PROC, _glTexCoord3xOES_, glTexCoord3xOES);
GL_GetFunc( PFN_GLTEXCOORD3XVOES_PROC, _glTexCoord3xvOES_, glTexCoord3xvOES);
GL_GetFunc( PFN_GLTEXCOORD4XOES_PROC, _glTexCoord4xOES_, glTexCoord4xOES);
GL_GetFunc( PFN_GLTEXCOORD4XVOES_PROC, _glTexCoord4xvOES_, glTexCoord4xvOES);
GL_GetFunc( PFN_GLTEXGENXOES_PROC, _glTexGenxOES_, glTexGenxOES);
GL_GetFunc( PFN_GLTEXGENXVOES_PROC, _glTexGenxvOES_, glTexGenxvOES);
GL_GetFunc( PFN_GLVERTEX2XOES_PROC, _glVertex2xOES_, glVertex2xOES);
GL_GetFunc( PFN_GLVERTEX2XVOES_PROC, _glVertex2xvOES_, glVertex2xvOES);
GL_GetFunc( PFN_GLVERTEX3XOES_PROC, _glVertex3xOES_, glVertex3xOES);
GL_GetFunc( PFN_GLVERTEX3XVOES_PROC, _glVertex3xvOES_, glVertex3xvOES);
GL_GetFunc( PFN_GLVERTEX4XOES_PROC, _glVertex4xOES_, glVertex4xOES);
GL_GetFunc( PFN_GLVERTEX4XVOES_PROC, _glVertex4xvOES_, glVertex4xvOES);
#endif //GL_OES_fixed_point

#ifndef GL_OES_query_matrix
LOG_fprintf(LogGlGetFunctions_py, "\nGL_OES_query_matrix\n");
GL_GetFunc( PFN_GLQUERYMATRIXXOES_PROC, _glQueryMatrixxOES_, glQueryMatrixxOES);
#endif //GL_OES_query_matrix

// GL_OES_read_format

#ifndef GL_OES_single_precision
LOG_fprintf(LogGlGetFunctions_py, "\nGL_OES_single_precision\n");
GL_GetFunc( PFN_GLCLEARDEPTHFOES_PROC, _glClearDepthfOES_, glClearDepthfOES);
GL_GetFunc( PFN_GLCLIPPLANEFOES_PROC, _glClipPlanefOES_, glClipPlanefOES);
GL_GetFunc( PFN_GLDEPTHRANGEFOES_PROC, _glDepthRangefOES_, glDepthRangefOES);
GL_GetFunc( PFN_GLFRUSTUMFOES_PROC, _glFrustumfOES_, glFrustumfOES);
GL_GetFunc( PFN_GLGETCLIPPLANEFOES_PROC, _glGetClipPlanefOES_, glGetClipPlanefOES);
GL_GetFunc( PFN_GLORTHOFOES_PROC, _glOrthofOES_, glOrthofOES);
#endif //GL_OES_single_precision

// GL_3DFX_multisample

#ifndef GL_3DFX_tbuffer
LOG_fprintf(LogGlGetFunctions_py, "\nGL_3DFX_tbuffer\n");
GL_GetFunc( PFN_GLTBUFFERMASK3DFX_PROC, _glTbufferMask3DFX_, glTbufferMask3DFX);
#endif //GL_3DFX_tbuffer

// GL_3DFX_texture_compression_FXT1

// GL_AMD_blend_minmax_factor

// GL_AMD_conservative_depth

#ifndef GL_AMD_debug_output
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_debug_output\n");
GL_GetFunc( PFN_GLDEBUGMESSAGEENABLEAMD_PROC, _glDebugMessageEnableAMD_, glDebugMessageEnableAMD);
GL_GetFunc( PFN_GLDEBUGMESSAGEINSERTAMD_PROC, _glDebugMessageInsertAMD_, glDebugMessageInsertAMD);
GL_GetFunc( PFN_GLDEBUGMESSAGECALLBACKAMD_PROC, _glDebugMessageCallbackAMD_, glDebugMessageCallbackAMD);
GL_GetFunc( PFN_GLGETDEBUGMESSAGELOGAMD_PROC, _glGetDebugMessageLogAMD_, glGetDebugMessageLogAMD);
#endif //GL_AMD_debug_output

// GL_AMD_depth_clamp_separate

#ifndef GL_AMD_draw_buffers_blend
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_draw_buffers_blend\n");
GL_GetFunc( PFN_GLBLENDFUNCINDEXEDAMD_PROC, _glBlendFuncIndexedAMD_, glBlendFuncIndexedAMD);
GL_GetFunc( PFN_GLBLENDFUNCSEPARATEINDEXEDAMD_PROC, _glBlendFuncSeparateIndexedAMD_, glBlendFuncSeparateIndexedAMD);
GL_GetFunc( PFN_GLBLENDEQUATIONINDEXEDAMD_PROC, _glBlendEquationIndexedAMD_, glBlendEquationIndexedAMD);
GL_GetFunc( PFN_GLBLENDEQUATIONSEPARATEINDEXEDAMD_PROC, _glBlendEquationSeparateIndexedAMD_, glBlendEquationSeparateIndexedAMD);
#endif //GL_AMD_draw_buffers_blend

#ifndef GL_AMD_framebuffer_sample_positions
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_framebuffer_sample_positions\n");
GL_GetFunc( PFN_GLFRAMEBUFFERSAMPLEPOSITIONSFVAMD_PROC, _glFramebufferSamplePositionsfvAMD_, glFramebufferSamplePositionsfvAMD);
GL_GetFunc( PFN_GLNAMEDFRAMEBUFFERSAMPLEPOSITIONSFVAMD_PROC, _glNamedFramebufferSamplePositionsfvAMD_, glNamedFramebufferSamplePositionsfvAMD);
GL_GetFunc( PFN_GLGETFRAMEBUFFERPARAMETERFVAMD_PROC, _glGetFramebufferParameterfvAMD_, glGetFramebufferParameterfvAMD);
GL_GetFunc( PFN_GLGETNAMEDFRAMEBUFFERPARAMETERFVAMD_PROC, _glGetNamedFramebufferParameterfvAMD_, glGetNamedFramebufferParameterfvAMD);
#endif //GL_AMD_framebuffer_sample_positions

// GL_AMD_gcn_shader

// GL_AMD_gpu_shader_half_float

// GL_AMD_gpu_shader_int16

// GL_AMD_gpu_shader_int64

#ifndef GL_AMD_interleaved_elements
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_interleaved_elements\n");
GL_GetFunc( PFN_GLVERTEXATTRIBPARAMETERIAMD_PROC, _glVertexAttribParameteriAMD_, glVertexAttribParameteriAMD);
#endif //GL_AMD_interleaved_elements

#ifndef GL_AMD_multi_draw_indirect
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_multi_draw_indirect\n");
GL_GetFunc( PFN_GLMULTIDRAWARRAYSINDIRECTAMD_PROC, _glMultiDrawArraysIndirectAMD_, glMultiDrawArraysIndirectAMD);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTSINDIRECTAMD_PROC, _glMultiDrawElementsIndirectAMD_, glMultiDrawElementsIndirectAMD);
#endif //GL_AMD_multi_draw_indirect

#ifndef GL_AMD_name_gen_delete
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_name_gen_delete\n");
GL_GetFunc( PFN_GLGENNAMESAMD_PROC, _glGenNamesAMD_, glGenNamesAMD);
GL_GetFunc( PFN_GLDELETENAMESAMD_PROC, _glDeleteNamesAMD_, glDeleteNamesAMD);
GL_GetFunc( PFN_GLISNAMEAMD_PROC, _glIsNameAMD_, glIsNameAMD);
#endif //GL_AMD_name_gen_delete

#ifndef GL_AMD_occlusion_query_event
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_occlusion_query_event\n");
GL_GetFunc( PFN_GLQUERYOBJECTPARAMETERUIAMD_PROC, _glQueryObjectParameteruiAMD_, glQueryObjectParameteruiAMD);
#endif //GL_AMD_occlusion_query_event

// GL_AMD_pinned_memory

// GL_AMD_query_buffer_object

#ifndef GL_AMD_sample_positions
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_sample_positions\n");
GL_GetFunc( PFN_GLSETMULTISAMPLEFVAMD_PROC, _glSetMultisamplefvAMD_, glSetMultisamplefvAMD);
#endif //GL_AMD_sample_positions

// GL_AMD_seamless_cubemap_per_texture

// GL_AMD_shader_atomic_counter_ops

// GL_AMD_shader_ballot

// GL_AMD_shader_explicit_vertex_parameter

// GL_AMD_shader_gpu_shader_half_float_fetch

// GL_AMD_shader_image_load_store_lod

// GL_AMD_shader_stencil_export

// GL_AMD_shader_trinary_minmax

#ifndef GL_AMD_sparse_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_sparse_texture\n");
GL_GetFunc( PFN_GLTEXSTORAGESPARSEAMD_PROC, _glTexStorageSparseAMD_, glTexStorageSparseAMD);
GL_GetFunc( PFN_GLTEXTURESTORAGESPARSEAMD_PROC, _glTextureStorageSparseAMD_, glTextureStorageSparseAMD);
#endif //GL_AMD_sparse_texture

#ifndef GL_AMD_stencil_operation_extended
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_stencil_operation_extended\n");
GL_GetFunc( PFN_GLSTENCILOPVALUEAMD_PROC, _glStencilOpValueAMD_, glStencilOpValueAMD);
#endif //GL_AMD_stencil_operation_extended

// GL_AMD_texture_gather_bias_lod

// GL_AMD_texture_texture4

// GL_AMD_transform_feedback3_lines_triangles

// GL_AMD_transform_feedback4

// GL_AMD_vertex_shader_layer

#ifndef GL_AMD_vertex_shader_tessellator
LOG_fprintf(LogGlGetFunctions_py, "\nGL_AMD_vertex_shader_tessellator\n");
GL_GetFunc( PFN_GLTESSELLATIONFACTORAMD_PROC, _glTessellationFactorAMD_, glTessellationFactorAMD);
GL_GetFunc( PFN_GLTESSELLATIONMODEAMD_PROC, _glTessellationModeAMD_, glTessellationModeAMD);
#endif //GL_AMD_vertex_shader_tessellator

// GL_AMD_vertex_shader_viewport_index

// GL_APPLE_aux_depth_stencil

// GL_APPLE_client_storage

#ifndef GL_APPLE_element_array
LOG_fprintf(LogGlGetFunctions_py, "\nGL_APPLE_element_array\n");
GL_GetFunc( PFN_GLELEMENTPOINTERAPPLE_PROC, _glElementPointerAPPLE_, glElementPointerAPPLE);
GL_GetFunc( PFN_GLDRAWELEMENTARRAYAPPLE_PROC, _glDrawElementArrayAPPLE_, glDrawElementArrayAPPLE);
GL_GetFunc( PFN_GLDRAWRANGEELEMENTARRAYAPPLE_PROC, _glDrawRangeElementArrayAPPLE_, glDrawRangeElementArrayAPPLE);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTARRAYAPPLE_PROC, _glMultiDrawElementArrayAPPLE_, glMultiDrawElementArrayAPPLE);
GL_GetFunc( PFN_GLMULTIDRAWRANGEELEMENTARRAYAPPLE_PROC, _glMultiDrawRangeElementArrayAPPLE_, glMultiDrawRangeElementArrayAPPLE);
#endif //GL_APPLE_element_array

#ifndef GL_APPLE_fence
LOG_fprintf(LogGlGetFunctions_py, "\nGL_APPLE_fence\n");
GL_GetFunc( PFN_GLGENFENCESAPPLE_PROC, _glGenFencesAPPLE_, glGenFencesAPPLE);
GL_GetFunc( PFN_GLDELETEFENCESAPPLE_PROC, _glDeleteFencesAPPLE_, glDeleteFencesAPPLE);
GL_GetFunc( PFN_GLSETFENCEAPPLE_PROC, _glSetFenceAPPLE_, glSetFenceAPPLE);
GL_GetFunc( PFN_GLISFENCEAPPLE_PROC, _glIsFenceAPPLE_, glIsFenceAPPLE);
GL_GetFunc( PFN_GLTESTFENCEAPPLE_PROC, _glTestFenceAPPLE_, glTestFenceAPPLE);
GL_GetFunc( PFN_GLFINISHFENCEAPPLE_PROC, _glFinishFenceAPPLE_, glFinishFenceAPPLE);
GL_GetFunc( PFN_GLTESTOBJECTAPPLE_PROC, _glTestObjectAPPLE_, glTestObjectAPPLE);
GL_GetFunc( PFN_GLFINISHOBJECTAPPLE_PROC, _glFinishObjectAPPLE_, glFinishObjectAPPLE);
#endif //GL_APPLE_fence

// GL_APPLE_float_pixels

#ifndef GL_APPLE_flush_buffer_range
LOG_fprintf(LogGlGetFunctions_py, "\nGL_APPLE_flush_buffer_range\n");
GL_GetFunc( PFN_GLBUFFERPARAMETERIAPPLE_PROC, _glBufferParameteriAPPLE_, glBufferParameteriAPPLE);
GL_GetFunc( PFN_GLFLUSHMAPPEDBUFFERRANGEAPPLE_PROC, _glFlushMappedBufferRangeAPPLE_, glFlushMappedBufferRangeAPPLE);
#endif //GL_APPLE_flush_buffer_range

#ifndef GL_APPLE_object_purgeable
LOG_fprintf(LogGlGetFunctions_py, "\nGL_APPLE_object_purgeable\n");
GL_GetFunc( PFN_GLOBJECTPURGEABLEAPPLE_PROC, _glObjectPurgeableAPPLE_, glObjectPurgeableAPPLE);
GL_GetFunc( PFN_GLOBJECTUNPURGEABLEAPPLE_PROC, _glObjectUnpurgeableAPPLE_, glObjectUnpurgeableAPPLE);
GL_GetFunc( PFN_GLGETOBJECTPARAMETERIVAPPLE_PROC, _glGetObjectParameterivAPPLE_, glGetObjectParameterivAPPLE);
#endif //GL_APPLE_object_purgeable

// GL_APPLE_row_bytes

// GL_APPLE_specular_vector

#ifndef GL_APPLE_texture_range
LOG_fprintf(LogGlGetFunctions_py, "\nGL_APPLE_texture_range\n");
GL_GetFunc( PFN_GLTEXTURERANGEAPPLE_PROC, _glTextureRangeAPPLE_, glTextureRangeAPPLE);
GL_GetFunc( PFN_GLGETTEXPARAMETERPOINTERVAPPLE_PROC, _glGetTexParameterPointervAPPLE_, glGetTexParameterPointervAPPLE);
#endif //GL_APPLE_texture_range

// GL_APPLE_transform_hint

#ifndef GL_APPLE_vertex_array_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_APPLE_vertex_array_object\n");
GL_GetFunc( PFN_GLBINDVERTEXARRAYAPPLE_PROC, _glBindVertexArrayAPPLE_, glBindVertexArrayAPPLE);
GL_GetFunc( PFN_GLDELETEVERTEXARRAYSAPPLE_PROC, _glDeleteVertexArraysAPPLE_, glDeleteVertexArraysAPPLE);
GL_GetFunc( PFN_GLGENVERTEXARRAYSAPPLE_PROC, _glGenVertexArraysAPPLE_, glGenVertexArraysAPPLE);
GL_GetFunc( PFN_GLISVERTEXARRAYAPPLE_PROC, _glIsVertexArrayAPPLE_, glIsVertexArrayAPPLE);
#endif //GL_APPLE_vertex_array_object

#ifndef GL_APPLE_vertex_array_range
LOG_fprintf(LogGlGetFunctions_py, "\nGL_APPLE_vertex_array_range\n");
GL_GetFunc( PFN_GLVERTEXARRAYRANGEAPPLE_PROC, _glVertexArrayRangeAPPLE_, glVertexArrayRangeAPPLE);
GL_GetFunc( PFN_GLFLUSHVERTEXARRAYRANGEAPPLE_PROC, _glFlushVertexArrayRangeAPPLE_, glFlushVertexArrayRangeAPPLE);
GL_GetFunc( PFN_GLVERTEXARRAYPARAMETERIAPPLE_PROC, _glVertexArrayParameteriAPPLE_, glVertexArrayParameteriAPPLE);
#endif //GL_APPLE_vertex_array_range

#ifndef GL_APPLE_vertex_program_evaluators
LOG_fprintf(LogGlGetFunctions_py, "\nGL_APPLE_vertex_program_evaluators\n");
GL_GetFunc( PFN_GLENABLEVERTEXATTRIBAPPLE_PROC, _glEnableVertexAttribAPPLE_, glEnableVertexAttribAPPLE);
GL_GetFunc( PFN_GLDISABLEVERTEXATTRIBAPPLE_PROC, _glDisableVertexAttribAPPLE_, glDisableVertexAttribAPPLE);
GL_GetFunc( PFN_GLISVERTEXATTRIBENABLEDAPPLE_PROC, _glIsVertexAttribEnabledAPPLE_, glIsVertexAttribEnabledAPPLE);
GL_GetFunc( PFN_GLMAPVERTEXATTRIB1DAPPLE_PROC, _glMapVertexAttrib1dAPPLE_, glMapVertexAttrib1dAPPLE);
GL_GetFunc( PFN_GLMAPVERTEXATTRIB1FAPPLE_PROC, _glMapVertexAttrib1fAPPLE_, glMapVertexAttrib1fAPPLE);
GL_GetFunc( PFN_GLMAPVERTEXATTRIB2DAPPLE_PROC, _glMapVertexAttrib2dAPPLE_, glMapVertexAttrib2dAPPLE);
GL_GetFunc( PFN_GLMAPVERTEXATTRIB2FAPPLE_PROC, _glMapVertexAttrib2fAPPLE_, glMapVertexAttrib2fAPPLE);
#endif //GL_APPLE_vertex_program_evaluators

// GL_APPLE_ycbcr_422

#ifndef GL_ATI_draw_buffers
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_draw_buffers\n");
GL_GetFunc( PFN_GLDRAWBUFFERSATI_PROC, _glDrawBuffersATI_, glDrawBuffersATI);
#endif //GL_ATI_draw_buffers

#ifndef GL_ATI_element_array
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_element_array\n");
GL_GetFunc( PFN_GLELEMENTPOINTERATI_PROC, _glElementPointerATI_, glElementPointerATI);
GL_GetFunc( PFN_GLDRAWELEMENTARRAYATI_PROC, _glDrawElementArrayATI_, glDrawElementArrayATI);
GL_GetFunc( PFN_GLDRAWRANGEELEMENTARRAYATI_PROC, _glDrawRangeElementArrayATI_, glDrawRangeElementArrayATI);
#endif //GL_ATI_element_array

#ifndef GL_ATI_envmap_bumpmap
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_envmap_bumpmap\n");
GL_GetFunc( PFN_GLTEXBUMPPARAMETERIVATI_PROC, _glTexBumpParameterivATI_, glTexBumpParameterivATI);
GL_GetFunc( PFN_GLTEXBUMPPARAMETERFVATI_PROC, _glTexBumpParameterfvATI_, glTexBumpParameterfvATI);
GL_GetFunc( PFN_GLGETTEXBUMPPARAMETERIVATI_PROC, _glGetTexBumpParameterivATI_, glGetTexBumpParameterivATI);
GL_GetFunc( PFN_GLGETTEXBUMPPARAMETERFVATI_PROC, _glGetTexBumpParameterfvATI_, glGetTexBumpParameterfvATI);
#endif //GL_ATI_envmap_bumpmap

#ifndef GL_ATI_fragment_shader
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_fragment_shader\n");
GL_GetFunc( PFN_GLGENFRAGMENTSHADERSATI_PROC, _glGenFragmentShadersATI_, glGenFragmentShadersATI);
GL_GetFunc( PFN_GLBINDFRAGMENTSHADERATI_PROC, _glBindFragmentShaderATI_, glBindFragmentShaderATI);
GL_GetFunc( PFN_GLDELETEFRAGMENTSHADERATI_PROC, _glDeleteFragmentShaderATI_, glDeleteFragmentShaderATI);
GL_GetFunc( PFN_GLBEGINFRAGMENTSHADERATI_PROC, _glBeginFragmentShaderATI_, glBeginFragmentShaderATI);
GL_GetFunc( PFN_GLENDFRAGMENTSHADERATI_PROC, _glEndFragmentShaderATI_, glEndFragmentShaderATI);
GL_GetFunc( PFN_GLPASSTEXCOORDATI_PROC, _glPassTexCoordATI_, glPassTexCoordATI);
GL_GetFunc( PFN_GLSAMPLEMAPATI_PROC, _glSampleMapATI_, glSampleMapATI);
GL_GetFunc( PFN_GLCOLORFRAGMENTOP1ATI_PROC, _glColorFragmentOp1ATI_, glColorFragmentOp1ATI);
GL_GetFunc( PFN_GLCOLORFRAGMENTOP2ATI_PROC, _glColorFragmentOp2ATI_, glColorFragmentOp2ATI);
GL_GetFunc( PFN_GLCOLORFRAGMENTOP3ATI_PROC, _glColorFragmentOp3ATI_, glColorFragmentOp3ATI);
GL_GetFunc( PFN_GLALPHAFRAGMENTOP1ATI_PROC, _glAlphaFragmentOp1ATI_, glAlphaFragmentOp1ATI);
GL_GetFunc( PFN_GLALPHAFRAGMENTOP2ATI_PROC, _glAlphaFragmentOp2ATI_, glAlphaFragmentOp2ATI);
GL_GetFunc( PFN_GLALPHAFRAGMENTOP3ATI_PROC, _glAlphaFragmentOp3ATI_, glAlphaFragmentOp3ATI);
GL_GetFunc( PFN_GLSETFRAGMENTSHADERCONSTANTATI_PROC, _glSetFragmentShaderConstantATI_, glSetFragmentShaderConstantATI);
#endif //GL_ATI_fragment_shader

#ifndef GL_ATI_map_object_buffer
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_map_object_buffer\n");
GL_GetFunc( PFN_GLMAPOBJECTBUFFERATI_PROC, _glMapObjectBufferATI_, glMapObjectBufferATI);
GL_GetFunc( PFN_GLUNMAPOBJECTBUFFERATI_PROC, _glUnmapObjectBufferATI_, glUnmapObjectBufferATI);
#endif //GL_ATI_map_object_buffer

// GL_ATI_meminfo

// GL_ATI_pixel_format_float

#ifndef GL_ATI_pn_triangles
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_pn_triangles\n");
GL_GetFunc( PFN_GLPNTRIANGLESIATI_PROC, _glPNTrianglesiATI_, glPNTrianglesiATI);
GL_GetFunc( PFN_GLPNTRIANGLESFATI_PROC, _glPNTrianglesfATI_, glPNTrianglesfATI);
#endif //GL_ATI_pn_triangles

#ifndef GL_ATI_separate_stencil
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_separate_stencil\n");
GL_GetFunc( PFN_GLSTENCILOPSEPARATEATI_PROC, _glStencilOpSeparateATI_, glStencilOpSeparateATI);
GL_GetFunc( PFN_GLSTENCILFUNCSEPARATEATI_PROC, _glStencilFuncSeparateATI_, glStencilFuncSeparateATI);
#endif //GL_ATI_separate_stencil

// GL_ATI_text_fragment_shader

// GL_ATI_texture_env_combine3

// GL_ATI_texture_float

// GL_ATI_texture_mirror_once

#ifndef GL_ATI_vertex_array_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_vertex_array_object\n");
GL_GetFunc( PFN_GLNEWOBJECTBUFFERATI_PROC, _glNewObjectBufferATI_, glNewObjectBufferATI);
GL_GetFunc( PFN_GLISOBJECTBUFFERATI_PROC, _glIsObjectBufferATI_, glIsObjectBufferATI);
GL_GetFunc( PFN_GLUPDATEOBJECTBUFFERATI_PROC, _glUpdateObjectBufferATI_, glUpdateObjectBufferATI);
GL_GetFunc( PFN_GLGETOBJECTBUFFERFVATI_PROC, _glGetObjectBufferfvATI_, glGetObjectBufferfvATI);
GL_GetFunc( PFN_GLGETOBJECTBUFFERIVATI_PROC, _glGetObjectBufferivATI_, glGetObjectBufferivATI);
GL_GetFunc( PFN_GLFREEOBJECTBUFFERATI_PROC, _glFreeObjectBufferATI_, glFreeObjectBufferATI);
GL_GetFunc( PFN_GLARRAYOBJECTATI_PROC, _glArrayObjectATI_, glArrayObjectATI);
GL_GetFunc( PFN_GLGETARRAYOBJECTFVATI_PROC, _glGetArrayObjectfvATI_, glGetArrayObjectfvATI);
GL_GetFunc( PFN_GLGETARRAYOBJECTIVATI_PROC, _glGetArrayObjectivATI_, glGetArrayObjectivATI);
GL_GetFunc( PFN_GLVARIANTARRAYOBJECTATI_PROC, _glVariantArrayObjectATI_, glVariantArrayObjectATI);
GL_GetFunc( PFN_GLGETVARIANTARRAYOBJECTFVATI_PROC, _glGetVariantArrayObjectfvATI_, glGetVariantArrayObjectfvATI);
GL_GetFunc( PFN_GLGETVARIANTARRAYOBJECTIVATI_PROC, _glGetVariantArrayObjectivATI_, glGetVariantArrayObjectivATI);
#endif //GL_ATI_vertex_array_object

#ifndef GL_ATI_vertex_attrib_array_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_vertex_attrib_array_object\n");
GL_GetFunc( PFN_GLVERTEXATTRIBARRAYOBJECTATI_PROC, _glVertexAttribArrayObjectATI_, glVertexAttribArrayObjectATI);
GL_GetFunc( PFN_GLGETVERTEXATTRIBARRAYOBJECTFVATI_PROC, _glGetVertexAttribArrayObjectfvATI_, glGetVertexAttribArrayObjectfvATI);
GL_GetFunc( PFN_GLGETVERTEXATTRIBARRAYOBJECTIVATI_PROC, _glGetVertexAttribArrayObjectivATI_, glGetVertexAttribArrayObjectivATI);
#endif //GL_ATI_vertex_attrib_array_object

#ifndef GL_ATI_vertex_streams
LOG_fprintf(LogGlGetFunctions_py, "\nGL_ATI_vertex_streams\n");
GL_GetFunc( PFN_GLVERTEXSTREAM1SATI_PROC, _glVertexStream1sATI_, glVertexStream1sATI);
GL_GetFunc( PFN_GLVERTEXSTREAM1SVATI_PROC, _glVertexStream1svATI_, glVertexStream1svATI);
GL_GetFunc( PFN_GLVERTEXSTREAM1IATI_PROC, _glVertexStream1iATI_, glVertexStream1iATI);
GL_GetFunc( PFN_GLVERTEXSTREAM1IVATI_PROC, _glVertexStream1ivATI_, glVertexStream1ivATI);
GL_GetFunc( PFN_GLVERTEXSTREAM1FATI_PROC, _glVertexStream1fATI_, glVertexStream1fATI);
GL_GetFunc( PFN_GLVERTEXSTREAM1FVATI_PROC, _glVertexStream1fvATI_, glVertexStream1fvATI);
GL_GetFunc( PFN_GLVERTEXSTREAM1DATI_PROC, _glVertexStream1dATI_, glVertexStream1dATI);
GL_GetFunc( PFN_GLVERTEXSTREAM1DVATI_PROC, _glVertexStream1dvATI_, glVertexStream1dvATI);
GL_GetFunc( PFN_GLVERTEXSTREAM2SATI_PROC, _glVertexStream2sATI_, glVertexStream2sATI);
GL_GetFunc( PFN_GLVERTEXSTREAM2SVATI_PROC, _glVertexStream2svATI_, glVertexStream2svATI);
GL_GetFunc( PFN_GLVERTEXSTREAM2IATI_PROC, _glVertexStream2iATI_, glVertexStream2iATI);
GL_GetFunc( PFN_GLVERTEXSTREAM2IVATI_PROC, _glVertexStream2ivATI_, glVertexStream2ivATI);
GL_GetFunc( PFN_GLVERTEXSTREAM2FATI_PROC, _glVertexStream2fATI_, glVertexStream2fATI);
GL_GetFunc( PFN_GLVERTEXSTREAM2FVATI_PROC, _glVertexStream2fvATI_, glVertexStream2fvATI);
GL_GetFunc( PFN_GLVERTEXSTREAM2DATI_PROC, _glVertexStream2dATI_, glVertexStream2dATI);
GL_GetFunc( PFN_GLVERTEXSTREAM2DVATI_PROC, _glVertexStream2dvATI_, glVertexStream2dvATI);
GL_GetFunc( PFN_GLVERTEXSTREAM3SATI_PROC, _glVertexStream3sATI_, glVertexStream3sATI);
GL_GetFunc( PFN_GLVERTEXSTREAM3SVATI_PROC, _glVertexStream3svATI_, glVertexStream3svATI);
GL_GetFunc( PFN_GLVERTEXSTREAM3IATI_PROC, _glVertexStream3iATI_, glVertexStream3iATI);
GL_GetFunc( PFN_GLVERTEXSTREAM3IVATI_PROC, _glVertexStream3ivATI_, glVertexStream3ivATI);
GL_GetFunc( PFN_GLVERTEXSTREAM3FATI_PROC, _glVertexStream3fATI_, glVertexStream3fATI);
GL_GetFunc( PFN_GLVERTEXSTREAM3FVATI_PROC, _glVertexStream3fvATI_, glVertexStream3fvATI);
GL_GetFunc( PFN_GLVERTEXSTREAM3DATI_PROC, _glVertexStream3dATI_, glVertexStream3dATI);
GL_GetFunc( PFN_GLVERTEXSTREAM3DVATI_PROC, _glVertexStream3dvATI_, glVertexStream3dvATI);
GL_GetFunc( PFN_GLVERTEXSTREAM4SATI_PROC, _glVertexStream4sATI_, glVertexStream4sATI);
GL_GetFunc( PFN_GLVERTEXSTREAM4SVATI_PROC, _glVertexStream4svATI_, glVertexStream4svATI);
GL_GetFunc( PFN_GLVERTEXSTREAM4IATI_PROC, _glVertexStream4iATI_, glVertexStream4iATI);
GL_GetFunc( PFN_GLVERTEXSTREAM4IVATI_PROC, _glVertexStream4ivATI_, glVertexStream4ivATI);
GL_GetFunc( PFN_GLVERTEXSTREAM4FATI_PROC, _glVertexStream4fATI_, glVertexStream4fATI);
GL_GetFunc( PFN_GLVERTEXSTREAM4FVATI_PROC, _glVertexStream4fvATI_, glVertexStream4fvATI);
GL_GetFunc( PFN_GLVERTEXSTREAM4DATI_PROC, _glVertexStream4dATI_, glVertexStream4dATI);
GL_GetFunc( PFN_GLVERTEXSTREAM4DVATI_PROC, _glVertexStream4dvATI_, glVertexStream4dvATI);
GL_GetFunc( PFN_GLNORMALSTREAM3BATI_PROC, _glNormalStream3bATI_, glNormalStream3bATI);
GL_GetFunc( PFN_GLNORMALSTREAM3BVATI_PROC, _glNormalStream3bvATI_, glNormalStream3bvATI);
GL_GetFunc( PFN_GLNORMALSTREAM3SATI_PROC, _glNormalStream3sATI_, glNormalStream3sATI);
GL_GetFunc( PFN_GLNORMALSTREAM3SVATI_PROC, _glNormalStream3svATI_, glNormalStream3svATI);
GL_GetFunc( PFN_GLNORMALSTREAM3IATI_PROC, _glNormalStream3iATI_, glNormalStream3iATI);
GL_GetFunc( PFN_GLNORMALSTREAM3IVATI_PROC, _glNormalStream3ivATI_, glNormalStream3ivATI);
GL_GetFunc( PFN_GLNORMALSTREAM3FATI_PROC, _glNormalStream3fATI_, glNormalStream3fATI);
GL_GetFunc( PFN_GLNORMALSTREAM3FVATI_PROC, _glNormalStream3fvATI_, glNormalStream3fvATI);
GL_GetFunc( PFN_GLNORMALSTREAM3DATI_PROC, _glNormalStream3dATI_, glNormalStream3dATI);
GL_GetFunc( PFN_GLNORMALSTREAM3DVATI_PROC, _glNormalStream3dvATI_, glNormalStream3dvATI);
GL_GetFunc( PFN_GLCLIENTACTIVEVERTEXSTREAMATI_PROC, _glClientActiveVertexStreamATI_, glClientActiveVertexStreamATI);
GL_GetFunc( PFN_GLVERTEXBLENDENVIATI_PROC, _glVertexBlendEnviATI_, glVertexBlendEnviATI);
GL_GetFunc( PFN_GLVERTEXBLENDENVFATI_PROC, _glVertexBlendEnvfATI_, glVertexBlendEnvfATI);
#endif //GL_ATI_vertex_streams

// GL_EXT_422_pixels

// GL_EXT_abgr

// GL_EXT_bgra

#ifndef GL_EXT_bindable_uniform
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_bindable_uniform\n");
GL_GetFunc( PFN_GLUNIFORMBUFFEREXT_PROC, _glUniformBufferEXT_, glUniformBufferEXT);
GL_GetFunc( PFN_GLGETUNIFORMBUFFERSIZEEXT_PROC, _glGetUniformBufferSizeEXT_, glGetUniformBufferSizeEXT);
GL_GetFunc( PFN_GLGETUNIFORMOFFSETEXT_PROC, _glGetUniformOffsetEXT_, glGetUniformOffsetEXT);
#endif //GL_EXT_bindable_uniform

#ifndef GL_EXT_blend_color
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_blend_color\n");
GL_GetFunc( PFN_GLBLENDCOLOREXT_PROC, _glBlendColorEXT_, glBlendColorEXT);
#endif //GL_EXT_blend_color

#ifndef GL_EXT_blend_equation_separate
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_blend_equation_separate\n");
GL_GetFunc( PFN_GLBLENDEQUATIONSEPARATEEXT_PROC, _glBlendEquationSeparateEXT_, glBlendEquationSeparateEXT);
#endif //GL_EXT_blend_equation_separate

#ifndef GL_EXT_blend_func_separate
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_blend_func_separate\n");
GL_GetFunc( PFN_GLBLENDFUNCSEPARATEEXT_PROC, _glBlendFuncSeparateEXT_, glBlendFuncSeparateEXT);
#endif //GL_EXT_blend_func_separate

// GL_EXT_blend_logic_op

#ifndef GL_EXT_blend_minmax
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_blend_minmax\n");
GL_GetFunc( PFN_GLBLENDEQUATIONEXT_PROC, _glBlendEquationEXT_, glBlendEquationEXT);
#endif //GL_EXT_blend_minmax

// GL_EXT_blend_subtract

// GL_EXT_clip_volume_hint

// GL_EXT_cmyka

#ifndef GL_EXT_color_subtable
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_color_subtable\n");
GL_GetFunc( PFN_GLCOLORSUBTABLEEXT_PROC, _glColorSubTableEXT_, glColorSubTableEXT);
GL_GetFunc( PFN_GLCOPYCOLORSUBTABLEEXT_PROC, _glCopyColorSubTableEXT_, glCopyColorSubTableEXT);
#endif //GL_EXT_color_subtable

#ifndef GL_EXT_compiled_vertex_array
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_compiled_vertex_array\n");
GL_GetFunc( PFN_GLLOCKARRAYSEXT_PROC, _glLockArraysEXT_, glLockArraysEXT);
GL_GetFunc( PFN_GLUNLOCKARRAYSEXT_PROC, _glUnlockArraysEXT_, glUnlockArraysEXT);
#endif //GL_EXT_compiled_vertex_array

#ifndef GL_EXT_convolution
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_convolution\n");
GL_GetFunc( PFN_GLCONVOLUTIONFILTER1DEXT_PROC, _glConvolutionFilter1DEXT_, glConvolutionFilter1DEXT);
GL_GetFunc( PFN_GLCONVOLUTIONFILTER2DEXT_PROC, _glConvolutionFilter2DEXT_, glConvolutionFilter2DEXT);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERFEXT_PROC, _glConvolutionParameterfEXT_, glConvolutionParameterfEXT);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERFVEXT_PROC, _glConvolutionParameterfvEXT_, glConvolutionParameterfvEXT);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERIEXT_PROC, _glConvolutionParameteriEXT_, glConvolutionParameteriEXT);
GL_GetFunc( PFN_GLCONVOLUTIONPARAMETERIVEXT_PROC, _glConvolutionParameterivEXT_, glConvolutionParameterivEXT);
GL_GetFunc( PFN_GLCOPYCONVOLUTIONFILTER1DEXT_PROC, _glCopyConvolutionFilter1DEXT_, glCopyConvolutionFilter1DEXT);
GL_GetFunc( PFN_GLCOPYCONVOLUTIONFILTER2DEXT_PROC, _glCopyConvolutionFilter2DEXT_, glCopyConvolutionFilter2DEXT);
GL_GetFunc( PFN_GLGETCONVOLUTIONFILTEREXT_PROC, _glGetConvolutionFilterEXT_, glGetConvolutionFilterEXT);
GL_GetFunc( PFN_GLGETCONVOLUTIONPARAMETERFVEXT_PROC, _glGetConvolutionParameterfvEXT_, glGetConvolutionParameterfvEXT);
GL_GetFunc( PFN_GLGETCONVOLUTIONPARAMETERIVEXT_PROC, _glGetConvolutionParameterivEXT_, glGetConvolutionParameterivEXT);
GL_GetFunc( PFN_GLGETSEPARABLEFILTEREXT_PROC, _glGetSeparableFilterEXT_, glGetSeparableFilterEXT);
GL_GetFunc( PFN_GLSEPARABLEFILTER2DEXT_PROC, _glSeparableFilter2DEXT_, glSeparableFilter2DEXT);
#endif //GL_EXT_convolution

#ifndef GL_EXT_coordinate_frame
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_coordinate_frame\n");
GL_GetFunc( PFN_GLTANGENT3BEXT_PROC, _glTangent3bEXT_, glTangent3bEXT);
GL_GetFunc( PFN_GLTANGENT3BVEXT_PROC, _glTangent3bvEXT_, glTangent3bvEXT);
GL_GetFunc( PFN_GLTANGENT3DEXT_PROC, _glTangent3dEXT_, glTangent3dEXT);
GL_GetFunc( PFN_GLTANGENT3DVEXT_PROC, _glTangent3dvEXT_, glTangent3dvEXT);
GL_GetFunc( PFN_GLTANGENT3FEXT_PROC, _glTangent3fEXT_, glTangent3fEXT);
GL_GetFunc( PFN_GLTANGENT3FVEXT_PROC, _glTangent3fvEXT_, glTangent3fvEXT);
GL_GetFunc( PFN_GLTANGENT3IEXT_PROC, _glTangent3iEXT_, glTangent3iEXT);
GL_GetFunc( PFN_GLTANGENT3IVEXT_PROC, _glTangent3ivEXT_, glTangent3ivEXT);
GL_GetFunc( PFN_GLTANGENT3SEXT_PROC, _glTangent3sEXT_, glTangent3sEXT);
GL_GetFunc( PFN_GLTANGENT3SVEXT_PROC, _glTangent3svEXT_, glTangent3svEXT);
GL_GetFunc( PFN_GLBINORMAL3BEXT_PROC, _glBinormal3bEXT_, glBinormal3bEXT);
GL_GetFunc( PFN_GLBINORMAL3BVEXT_PROC, _glBinormal3bvEXT_, glBinormal3bvEXT);
GL_GetFunc( PFN_GLBINORMAL3DEXT_PROC, _glBinormal3dEXT_, glBinormal3dEXT);
GL_GetFunc( PFN_GLBINORMAL3DVEXT_PROC, _glBinormal3dvEXT_, glBinormal3dvEXT);
GL_GetFunc( PFN_GLBINORMAL3FEXT_PROC, _glBinormal3fEXT_, glBinormal3fEXT);
GL_GetFunc( PFN_GLBINORMAL3FVEXT_PROC, _glBinormal3fvEXT_, glBinormal3fvEXT);
GL_GetFunc( PFN_GLBINORMAL3IEXT_PROC, _glBinormal3iEXT_, glBinormal3iEXT);
GL_GetFunc( PFN_GLBINORMAL3IVEXT_PROC, _glBinormal3ivEXT_, glBinormal3ivEXT);
GL_GetFunc( PFN_GLBINORMAL3SEXT_PROC, _glBinormal3sEXT_, glBinormal3sEXT);
GL_GetFunc( PFN_GLBINORMAL3SVEXT_PROC, _glBinormal3svEXT_, glBinormal3svEXT);
GL_GetFunc( PFN_GLTANGENTPOINTEREXT_PROC, _glTangentPointerEXT_, glTangentPointerEXT);
GL_GetFunc( PFN_GLBINORMALPOINTEREXT_PROC, _glBinormalPointerEXT_, glBinormalPointerEXT);
#endif //GL_EXT_coordinate_frame

#ifndef GL_EXT_copy_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_copy_texture\n");
GL_GetFunc( PFN_GLCOPYTEXIMAGE1DEXT_PROC, _glCopyTexImage1DEXT_, glCopyTexImage1DEXT);
GL_GetFunc( PFN_GLCOPYTEXIMAGE2DEXT_PROC, _glCopyTexImage2DEXT_, glCopyTexImage2DEXT);
GL_GetFunc( PFN_GLCOPYTEXSUBIMAGE1DEXT_PROC, _glCopyTexSubImage1DEXT_, glCopyTexSubImage1DEXT);
GL_GetFunc( PFN_GLCOPYTEXSUBIMAGE2DEXT_PROC, _glCopyTexSubImage2DEXT_, glCopyTexSubImage2DEXT);
GL_GetFunc( PFN_GLCOPYTEXSUBIMAGE3DEXT_PROC, _glCopyTexSubImage3DEXT_, glCopyTexSubImage3DEXT);
#endif //GL_EXT_copy_texture

#ifndef GL_EXT_cull_vertex
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_cull_vertex\n");
GL_GetFunc( PFN_GLCULLPARAMETERDVEXT_PROC, _glCullParameterdvEXT_, glCullParameterdvEXT);
GL_GetFunc( PFN_GLCULLPARAMETERFVEXT_PROC, _glCullParameterfvEXT_, glCullParameterfvEXT);
#endif //GL_EXT_cull_vertex

#ifndef GL_EXT_depth_bounds_test
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_depth_bounds_test\n");
GL_GetFunc( PFN_GLDEPTHBOUNDSEXT_PROC, _glDepthBoundsEXT_, glDepthBoundsEXT);
#endif //GL_EXT_depth_bounds_test

#ifndef GL_EXT_draw_buffers2
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_draw_buffers2\n");
GL_GetFunc( PFN_GLCOLORMASKINDEXEDEXT_PROC, _glColorMaskIndexedEXT_, glColorMaskIndexedEXT);
#endif //GL_EXT_draw_buffers2

#ifndef GL_EXT_draw_range_elements
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_draw_range_elements\n");
GL_GetFunc( PFN_GLDRAWRANGEELEMENTSEXT_PROC, _glDrawRangeElementsEXT_, glDrawRangeElementsEXT);
#endif //GL_EXT_draw_range_elements

#ifndef GL_EXT_external_buffer
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_external_buffer\n");
GL_GetFunc( PFN_GLBUFFERSTORAGEEXTERNALEXT_PROC, _glBufferStorageExternalEXT_, glBufferStorageExternalEXT);
GL_GetFunc( PFN_GLNAMEDBUFFERSTORAGEEXTERNALEXT_PROC, _glNamedBufferStorageExternalEXT_, glNamedBufferStorageExternalEXT);
#endif //GL_EXT_external_buffer

#ifndef GL_EXT_fog_coord
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_fog_coord\n");
GL_GetFunc( PFN_GLFOGCOORDFEXT_PROC, _glFogCoordfEXT_, glFogCoordfEXT);
GL_GetFunc( PFN_GLFOGCOORDFVEXT_PROC, _glFogCoordfvEXT_, glFogCoordfvEXT);
GL_GetFunc( PFN_GLFOGCOORDDEXT_PROC, _glFogCoorddEXT_, glFogCoorddEXT);
GL_GetFunc( PFN_GLFOGCOORDDVEXT_PROC, _glFogCoorddvEXT_, glFogCoorddvEXT);
GL_GetFunc( PFN_GLFOGCOORDPOINTEREXT_PROC, _glFogCoordPointerEXT_, glFogCoordPointerEXT);
#endif //GL_EXT_fog_coord

#ifndef GL_EXT_framebuffer_blit
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_framebuffer_blit\n");
GL_GetFunc( PFN_GLBLITFRAMEBUFFEREXT_PROC, _glBlitFramebufferEXT_, glBlitFramebufferEXT);
#endif //GL_EXT_framebuffer_blit

#ifndef GL_EXT_framebuffer_multisample
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_framebuffer_multisample\n");
GL_GetFunc( PFN_GLRENDERBUFFERSTORAGEMULTISAMPLEEXT_PROC, _glRenderbufferStorageMultisampleEXT_, glRenderbufferStorageMultisampleEXT);
#endif //GL_EXT_framebuffer_multisample

// GL_EXT_framebuffer_multisample_blit_scaled

#ifndef GL_EXT_framebuffer_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_framebuffer_object\n");
GL_GetFunc( PFN_GLISRENDERBUFFEREXT_PROC, _glIsRenderbufferEXT_, glIsRenderbufferEXT);
GL_GetFunc( PFN_GLBINDRENDERBUFFEREXT_PROC, _glBindRenderbufferEXT_, glBindRenderbufferEXT);
GL_GetFunc( PFN_GLDELETERENDERBUFFERSEXT_PROC, _glDeleteRenderbuffersEXT_, glDeleteRenderbuffersEXT);
GL_GetFunc( PFN_GLGENRENDERBUFFERSEXT_PROC, _glGenRenderbuffersEXT_, glGenRenderbuffersEXT);
GL_GetFunc( PFN_GLRENDERBUFFERSTORAGEEXT_PROC, _glRenderbufferStorageEXT_, glRenderbufferStorageEXT);
GL_GetFunc( PFN_GLGETRENDERBUFFERPARAMETERIVEXT_PROC, _glGetRenderbufferParameterivEXT_, glGetRenderbufferParameterivEXT);
GL_GetFunc( PFN_GLISFRAMEBUFFEREXT_PROC, _glIsFramebufferEXT_, glIsFramebufferEXT);
GL_GetFunc( PFN_GLBINDFRAMEBUFFEREXT_PROC, _glBindFramebufferEXT_, glBindFramebufferEXT);
GL_GetFunc( PFN_GLDELETEFRAMEBUFFERSEXT_PROC, _glDeleteFramebuffersEXT_, glDeleteFramebuffersEXT);
GL_GetFunc( PFN_GLGENFRAMEBUFFERSEXT_PROC, _glGenFramebuffersEXT_, glGenFramebuffersEXT);
GL_GetFunc( PFN_GLCHECKFRAMEBUFFERSTATUSEXT_PROC, _glCheckFramebufferStatusEXT_, glCheckFramebufferStatusEXT);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURE1DEXT_PROC, _glFramebufferTexture1DEXT_, glFramebufferTexture1DEXT);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURE2DEXT_PROC, _glFramebufferTexture2DEXT_, glFramebufferTexture2DEXT);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURE3DEXT_PROC, _glFramebufferTexture3DEXT_, glFramebufferTexture3DEXT);
GL_GetFunc( PFN_GLFRAMEBUFFERRENDERBUFFEREXT_PROC, _glFramebufferRenderbufferEXT_, glFramebufferRenderbufferEXT);
GL_GetFunc( PFN_GLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXT_PROC, _glGetFramebufferAttachmentParameterivEXT_, glGetFramebufferAttachmentParameterivEXT);
GL_GetFunc( PFN_GLGENERATEMIPMAPEXT_PROC, _glGenerateMipmapEXT_, glGenerateMipmapEXT);
#endif //GL_EXT_framebuffer_object

// GL_EXT_framebuffer_sRGB

#ifndef GL_EXT_geometry_shader4
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_geometry_shader4\n");
GL_GetFunc( PFN_GLPROGRAMPARAMETERIEXT_PROC, _glProgramParameteriEXT_, glProgramParameteriEXT);
#endif //GL_EXT_geometry_shader4

#ifndef GL_EXT_gpu_program_parameters
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_gpu_program_parameters\n");
GL_GetFunc( PFN_GLPROGRAMENVPARAMETERS4FVEXT_PROC, _glProgramEnvParameters4fvEXT_, glProgramEnvParameters4fvEXT);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETERS4FVEXT_PROC, _glProgramLocalParameters4fvEXT_, glProgramLocalParameters4fvEXT);
#endif //GL_EXT_gpu_program_parameters

#ifndef GL_EXT_gpu_shader4
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_gpu_shader4\n");
GL_GetFunc( PFN_GLGETUNIFORMUIVEXT_PROC, _glGetUniformuivEXT_, glGetUniformuivEXT);
GL_GetFunc( PFN_GLBINDFRAGDATALOCATIONEXT_PROC, _glBindFragDataLocationEXT_, glBindFragDataLocationEXT);
GL_GetFunc( PFN_GLGETFRAGDATALOCATIONEXT_PROC, _glGetFragDataLocationEXT_, glGetFragDataLocationEXT);
GL_GetFunc( PFN_GLUNIFORM1UIEXT_PROC, _glUniform1uiEXT_, glUniform1uiEXT);
GL_GetFunc( PFN_GLUNIFORM2UIEXT_PROC, _glUniform2uiEXT_, glUniform2uiEXT);
GL_GetFunc( PFN_GLUNIFORM3UIEXT_PROC, _glUniform3uiEXT_, glUniform3uiEXT);
GL_GetFunc( PFN_GLUNIFORM4UIEXT_PROC, _glUniform4uiEXT_, glUniform4uiEXT);
GL_GetFunc( PFN_GLUNIFORM1UIVEXT_PROC, _glUniform1uivEXT_, glUniform1uivEXT);
GL_GetFunc( PFN_GLUNIFORM2UIVEXT_PROC, _glUniform2uivEXT_, glUniform2uivEXT);
GL_GetFunc( PFN_GLUNIFORM3UIVEXT_PROC, _glUniform3uivEXT_, glUniform3uivEXT);
GL_GetFunc( PFN_GLUNIFORM4UIVEXT_PROC, _glUniform4uivEXT_, glUniform4uivEXT);
#endif //GL_EXT_gpu_shader4

#ifndef GL_EXT_histogram
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_histogram\n");
GL_GetFunc( PFN_GLGETHISTOGRAMEXT_PROC, _glGetHistogramEXT_, glGetHistogramEXT);
GL_GetFunc( PFN_GLGETHISTOGRAMPARAMETERFVEXT_PROC, _glGetHistogramParameterfvEXT_, glGetHistogramParameterfvEXT);
GL_GetFunc( PFN_GLGETHISTOGRAMPARAMETERIVEXT_PROC, _glGetHistogramParameterivEXT_, glGetHistogramParameterivEXT);
GL_GetFunc( PFN_GLGETMINMAXEXT_PROC, _glGetMinmaxEXT_, glGetMinmaxEXT);
GL_GetFunc( PFN_GLGETMINMAXPARAMETERFVEXT_PROC, _glGetMinmaxParameterfvEXT_, glGetMinmaxParameterfvEXT);
GL_GetFunc( PFN_GLGETMINMAXPARAMETERIVEXT_PROC, _glGetMinmaxParameterivEXT_, glGetMinmaxParameterivEXT);
GL_GetFunc( PFN_GLHISTOGRAMEXT_PROC, _glHistogramEXT_, glHistogramEXT);
GL_GetFunc( PFN_GLMINMAXEXT_PROC, _glMinmaxEXT_, glMinmaxEXT);
GL_GetFunc( PFN_GLRESETHISTOGRAMEXT_PROC, _glResetHistogramEXT_, glResetHistogramEXT);
GL_GetFunc( PFN_GLRESETMINMAXEXT_PROC, _glResetMinmaxEXT_, glResetMinmaxEXT);
#endif //GL_EXT_histogram

// GL_EXT_index_array_formats

#ifndef GL_EXT_index_func
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_index_func\n");
GL_GetFunc( PFN_GLINDEXFUNCEXT_PROC, _glIndexFuncEXT_, glIndexFuncEXT);
#endif //GL_EXT_index_func

#ifndef GL_EXT_index_material
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_index_material\n");
GL_GetFunc( PFN_GLINDEXMATERIALEXT_PROC, _glIndexMaterialEXT_, glIndexMaterialEXT);
#endif //GL_EXT_index_material

// GL_EXT_index_texture

#ifndef GL_EXT_light_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_light_texture\n");
GL_GetFunc( PFN_GLAPPLYTEXTUREEXT_PROC, _glApplyTextureEXT_, glApplyTextureEXT);
GL_GetFunc( PFN_GLTEXTURELIGHTEXT_PROC, _glTextureLightEXT_, glTextureLightEXT);
GL_GetFunc( PFN_GLTEXTUREMATERIALEXT_PROC, _glTextureMaterialEXT_, glTextureMaterialEXT);
#endif //GL_EXT_light_texture

#ifndef GL_EXT_memory_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_memory_object\n");
GL_GetFunc( PFN_GLGETUNSIGNEDBYTEVEXT_PROC, _glGetUnsignedBytevEXT_, glGetUnsignedBytevEXT);
GL_GetFunc( PFN_GLGETUNSIGNEDBYTEI_VEXT_PROC, _glGetUnsignedBytei_vEXT_, glGetUnsignedBytei_vEXT);
GL_GetFunc( PFN_GLDELETEMEMORYOBJECTSEXT_PROC, _glDeleteMemoryObjectsEXT_, glDeleteMemoryObjectsEXT);
GL_GetFunc( PFN_GLISMEMORYOBJECTEXT_PROC, _glIsMemoryObjectEXT_, glIsMemoryObjectEXT);
GL_GetFunc( PFN_GLCREATEMEMORYOBJECTSEXT_PROC, _glCreateMemoryObjectsEXT_, glCreateMemoryObjectsEXT);
GL_GetFunc( PFN_GLMEMORYOBJECTPARAMETERIVEXT_PROC, _glMemoryObjectParameterivEXT_, glMemoryObjectParameterivEXT);
GL_GetFunc( PFN_GLGETMEMORYOBJECTPARAMETERIVEXT_PROC, _glGetMemoryObjectParameterivEXT_, glGetMemoryObjectParameterivEXT);
GL_GetFunc( PFN_GLTEXSTORAGEMEM2DEXT_PROC, _glTexStorageMem2DEXT_, glTexStorageMem2DEXT);
GL_GetFunc( PFN_GLTEXSTORAGEMEM2DMULTISAMPLEEXT_PROC, _glTexStorageMem2DMultisampleEXT_, glTexStorageMem2DMultisampleEXT);
GL_GetFunc( PFN_GLTEXSTORAGEMEM3DEXT_PROC, _glTexStorageMem3DEXT_, glTexStorageMem3DEXT);
GL_GetFunc( PFN_GLTEXSTORAGEMEM3DMULTISAMPLEEXT_PROC, _glTexStorageMem3DMultisampleEXT_, glTexStorageMem3DMultisampleEXT);
GL_GetFunc( PFN_GLBUFFERSTORAGEMEMEXT_PROC, _glBufferStorageMemEXT_, glBufferStorageMemEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGEMEM2DEXT_PROC, _glTextureStorageMem2DEXT_, glTextureStorageMem2DEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGEMEM2DMULTISAMPLEEXT_PROC, _glTextureStorageMem2DMultisampleEXT_, glTextureStorageMem2DMultisampleEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGEMEM3DEXT_PROC, _glTextureStorageMem3DEXT_, glTextureStorageMem3DEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGEMEM3DMULTISAMPLEEXT_PROC, _glTextureStorageMem3DMultisampleEXT_, glTextureStorageMem3DMultisampleEXT);
GL_GetFunc( PFN_GLNAMEDBUFFERSTORAGEMEMEXT_PROC, _glNamedBufferStorageMemEXT_, glNamedBufferStorageMemEXT);
GL_GetFunc( PFN_GLTEXSTORAGEMEM1DEXT_PROC, _glTexStorageMem1DEXT_, glTexStorageMem1DEXT);
GL_GetFunc( PFN_GLTEXTURESTORAGEMEM1DEXT_PROC, _glTextureStorageMem1DEXT_, glTextureStorageMem1DEXT);
#endif //GL_EXT_memory_object

#ifndef GL_EXT_memory_object_fd
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_memory_object_fd\n");
GL_GetFunc( PFN_GLIMPORTMEMORYFDEXT_PROC, _glImportMemoryFdEXT_, glImportMemoryFdEXT);
#endif //GL_EXT_memory_object_fd

#ifndef GL_EXT_memory_object_win32
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_memory_object_win32\n");
GL_GetFunc( PFN_GLIMPORTMEMORYWIN32HANDLEEXT_PROC, _glImportMemoryWin32HandleEXT_, glImportMemoryWin32HandleEXT);
GL_GetFunc( PFN_GLIMPORTMEMORYWIN32NAMEEXT_PROC, _glImportMemoryWin32NameEXT_, glImportMemoryWin32NameEXT);
#endif //GL_EXT_memory_object_win32

// GL_EXT_misc_attribute

#ifndef GL_EXT_multi_draw_arrays
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_multi_draw_arrays\n");
GL_GetFunc( PFN_GLMULTIDRAWARRAYSEXT_PROC, _glMultiDrawArraysEXT_, glMultiDrawArraysEXT);
GL_GetFunc( PFN_GLMULTIDRAWELEMENTSEXT_PROC, _glMultiDrawElementsEXT_, glMultiDrawElementsEXT);
#endif //GL_EXT_multi_draw_arrays

#ifndef GL_EXT_multisample
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_multisample\n");
GL_GetFunc( PFN_GLSAMPLEMASKEXT_PROC, _glSampleMaskEXT_, glSampleMaskEXT);
GL_GetFunc( PFN_GLSAMPLEPATTERNEXT_PROC, _glSamplePatternEXT_, glSamplePatternEXT);
#endif //GL_EXT_multisample

// GL_EXT_packed_depth_stencil

// GL_EXT_packed_float

// GL_EXT_packed_pixels

#ifndef GL_EXT_paletted_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_paletted_texture\n");
GL_GetFunc( PFN_GLCOLORTABLEEXT_PROC, _glColorTableEXT_, glColorTableEXT);
GL_GetFunc( PFN_GLGETCOLORTABLEEXT_PROC, _glGetColorTableEXT_, glGetColorTableEXT);
GL_GetFunc( PFN_GLGETCOLORTABLEPARAMETERIVEXT_PROC, _glGetColorTableParameterivEXT_, glGetColorTableParameterivEXT);
GL_GetFunc( PFN_GLGETCOLORTABLEPARAMETERFVEXT_PROC, _glGetColorTableParameterfvEXT_, glGetColorTableParameterfvEXT);
#endif //GL_EXT_paletted_texture

// GL_EXT_pixel_buffer_object

#ifndef GL_EXT_pixel_transform
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_pixel_transform\n");
GL_GetFunc( PFN_GLPIXELTRANSFORMPARAMETERIEXT_PROC, _glPixelTransformParameteriEXT_, glPixelTransformParameteriEXT);
GL_GetFunc( PFN_GLPIXELTRANSFORMPARAMETERFEXT_PROC, _glPixelTransformParameterfEXT_, glPixelTransformParameterfEXT);
GL_GetFunc( PFN_GLPIXELTRANSFORMPARAMETERIVEXT_PROC, _glPixelTransformParameterivEXT_, glPixelTransformParameterivEXT);
GL_GetFunc( PFN_GLPIXELTRANSFORMPARAMETERFVEXT_PROC, _glPixelTransformParameterfvEXT_, glPixelTransformParameterfvEXT);
GL_GetFunc( PFN_GLGETPIXELTRANSFORMPARAMETERIVEXT_PROC, _glGetPixelTransformParameterivEXT_, glGetPixelTransformParameterivEXT);
GL_GetFunc( PFN_GLGETPIXELTRANSFORMPARAMETERFVEXT_PROC, _glGetPixelTransformParameterfvEXT_, glGetPixelTransformParameterfvEXT);
#endif //GL_EXT_pixel_transform

// GL_EXT_pixel_transform_color_table

#ifndef GL_EXT_point_parameters
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_point_parameters\n");
GL_GetFunc( PFN_GLPOINTPARAMETERFEXT_PROC, _glPointParameterfEXT_, glPointParameterfEXT);
GL_GetFunc( PFN_GLPOINTPARAMETERFVEXT_PROC, _glPointParameterfvEXT_, glPointParameterfvEXT);
#endif //GL_EXT_point_parameters

#ifndef GL_EXT_polygon_offset
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_polygon_offset\n");
GL_GetFunc( PFN_GLPOLYGONOFFSETEXT_PROC, _glPolygonOffsetEXT_, glPolygonOffsetEXT);
#endif //GL_EXT_polygon_offset

#ifndef GL_EXT_provoking_vertex
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_provoking_vertex\n");
GL_GetFunc( PFN_GLPROVOKINGVERTEXEXT_PROC, _glProvokingVertexEXT_, glProvokingVertexEXT);
#endif //GL_EXT_provoking_vertex

// GL_EXT_rescale_normal

#ifndef GL_EXT_secondary_color
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_secondary_color\n");
GL_GetFunc( PFN_GLSECONDARYCOLOR3BEXT_PROC, _glSecondaryColor3bEXT_, glSecondaryColor3bEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3BVEXT_PROC, _glSecondaryColor3bvEXT_, glSecondaryColor3bvEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3DEXT_PROC, _glSecondaryColor3dEXT_, glSecondaryColor3dEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3DVEXT_PROC, _glSecondaryColor3dvEXT_, glSecondaryColor3dvEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3FEXT_PROC, _glSecondaryColor3fEXT_, glSecondaryColor3fEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3FVEXT_PROC, _glSecondaryColor3fvEXT_, glSecondaryColor3fvEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3IEXT_PROC, _glSecondaryColor3iEXT_, glSecondaryColor3iEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3IVEXT_PROC, _glSecondaryColor3ivEXT_, glSecondaryColor3ivEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3SEXT_PROC, _glSecondaryColor3sEXT_, glSecondaryColor3sEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3SVEXT_PROC, _glSecondaryColor3svEXT_, glSecondaryColor3svEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3UBEXT_PROC, _glSecondaryColor3ubEXT_, glSecondaryColor3ubEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3UBVEXT_PROC, _glSecondaryColor3ubvEXT_, glSecondaryColor3ubvEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3UIEXT_PROC, _glSecondaryColor3uiEXT_, glSecondaryColor3uiEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3UIVEXT_PROC, _glSecondaryColor3uivEXT_, glSecondaryColor3uivEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3USEXT_PROC, _glSecondaryColor3usEXT_, glSecondaryColor3usEXT);
GL_GetFunc( PFN_GLSECONDARYCOLOR3USVEXT_PROC, _glSecondaryColor3usvEXT_, glSecondaryColor3usvEXT);
GL_GetFunc( PFN_GLSECONDARYCOLORPOINTEREXT_PROC, _glSecondaryColorPointerEXT_, glSecondaryColorPointerEXT);
#endif //GL_EXT_secondary_color

#ifndef GL_EXT_semaphore
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_semaphore\n");
GL_GetFunc( PFN_GLGENSEMAPHORESEXT_PROC, _glGenSemaphoresEXT_, glGenSemaphoresEXT);
GL_GetFunc( PFN_GLDELETESEMAPHORESEXT_PROC, _glDeleteSemaphoresEXT_, glDeleteSemaphoresEXT);
GL_GetFunc( PFN_GLISSEMAPHOREEXT_PROC, _glIsSemaphoreEXT_, glIsSemaphoreEXT);
GL_GetFunc( PFN_GLSEMAPHOREPARAMETERUI64VEXT_PROC, _glSemaphoreParameterui64vEXT_, glSemaphoreParameterui64vEXT);
GL_GetFunc( PFN_GLGETSEMAPHOREPARAMETERUI64VEXT_PROC, _glGetSemaphoreParameterui64vEXT_, glGetSemaphoreParameterui64vEXT);
GL_GetFunc( PFN_GLWAITSEMAPHOREEXT_PROC, _glWaitSemaphoreEXT_, glWaitSemaphoreEXT);
GL_GetFunc( PFN_GLSIGNALSEMAPHOREEXT_PROC, _glSignalSemaphoreEXT_, glSignalSemaphoreEXT);
#endif //GL_EXT_semaphore

#ifndef GL_EXT_semaphore_fd
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_semaphore_fd\n");
GL_GetFunc( PFN_GLIMPORTSEMAPHOREFDEXT_PROC, _glImportSemaphoreFdEXT_, glImportSemaphoreFdEXT);
#endif //GL_EXT_semaphore_fd

#ifndef GL_EXT_semaphore_win32
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_semaphore_win32\n");
GL_GetFunc( PFN_GLIMPORTSEMAPHOREWIN32HANDLEEXT_PROC, _glImportSemaphoreWin32HandleEXT_, glImportSemaphoreWin32HandleEXT);
GL_GetFunc( PFN_GLIMPORTSEMAPHOREWIN32NAMEEXT_PROC, _glImportSemaphoreWin32NameEXT_, glImportSemaphoreWin32NameEXT);
#endif //GL_EXT_semaphore_win32

// GL_EXT_separate_specular_color

// GL_EXT_shader_image_load_formatted

#ifndef GL_EXT_shader_image_load_store
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_shader_image_load_store\n");
GL_GetFunc( PFN_GLBINDIMAGETEXTUREEXT_PROC, _glBindImageTextureEXT_, glBindImageTextureEXT);
GL_GetFunc( PFN_GLMEMORYBARRIEREXT_PROC, _glMemoryBarrierEXT_, glMemoryBarrierEXT);
#endif //GL_EXT_shader_image_load_store

// GL_EXT_shadow_funcs

// GL_EXT_shared_texture_palette

// GL_EXT_sparse_texture2

#ifndef GL_EXT_stencil_clear_tag
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_stencil_clear_tag\n");
GL_GetFunc( PFN_GLSTENCILCLEARTAGEXT_PROC, _glStencilClearTagEXT_, glStencilClearTagEXT);
#endif //GL_EXT_stencil_clear_tag

#ifndef GL_EXT_stencil_two_side
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_stencil_two_side\n");
GL_GetFunc( PFN_GLACTIVESTENCILFACEEXT_PROC, _glActiveStencilFaceEXT_, glActiveStencilFaceEXT);
#endif //GL_EXT_stencil_two_side

// GL_EXT_stencil_wrap

#ifndef GL_EXT_subtexture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_subtexture\n");
GL_GetFunc( PFN_GLTEXSUBIMAGE1DEXT_PROC, _glTexSubImage1DEXT_, glTexSubImage1DEXT);
GL_GetFunc( PFN_GLTEXSUBIMAGE2DEXT_PROC, _glTexSubImage2DEXT_, glTexSubImage2DEXT);
#endif //GL_EXT_subtexture

// GL_EXT_texture

#ifndef GL_EXT_texture3D
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture3D\n");
GL_GetFunc( PFN_GLTEXIMAGE3DEXT_PROC, _glTexImage3DEXT_, glTexImage3DEXT);
GL_GetFunc( PFN_GLTEXSUBIMAGE3DEXT_PROC, _glTexSubImage3DEXT_, glTexSubImage3DEXT);
#endif //GL_EXT_texture3D

#ifndef GL_EXT_texture_array
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_array\n");
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTURELAYEREXT_PROC, _glFramebufferTextureLayerEXT_, glFramebufferTextureLayerEXT);
#endif //GL_EXT_texture_array

#ifndef GL_EXT_texture_buffer_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_buffer_object\n");
GL_GetFunc( PFN_GLTEXBUFFEREXT_PROC, _glTexBufferEXT_, glTexBufferEXT);
#endif //GL_EXT_texture_buffer_object

// GL_EXT_texture_compression_latc

// GL_EXT_texture_compression_rgtc

// GL_EXT_texture_cube_map

// GL_EXT_texture_env_add

// GL_EXT_texture_env_combine

// GL_EXT_texture_env_dot3

// GL_EXT_texture_filter_anisotropic

#ifndef GL_EXT_texture_integer
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_integer\n");
GL_GetFunc( PFN_GLTEXPARAMETERIIVEXT_PROC, _glTexParameterIivEXT_, glTexParameterIivEXT);
GL_GetFunc( PFN_GLTEXPARAMETERIUIVEXT_PROC, _glTexParameterIuivEXT_, glTexParameterIuivEXT);
GL_GetFunc( PFN_GLGETTEXPARAMETERIIVEXT_PROC, _glGetTexParameterIivEXT_, glGetTexParameterIivEXT);
GL_GetFunc( PFN_GLGETTEXPARAMETERIUIVEXT_PROC, _glGetTexParameterIuivEXT_, glGetTexParameterIuivEXT);
GL_GetFunc( PFN_GLCLEARCOLORIIEXT_PROC, _glClearColorIiEXT_, glClearColorIiEXT);
GL_GetFunc( PFN_GLCLEARCOLORIUIEXT_PROC, _glClearColorIuiEXT_, glClearColorIuiEXT);
#endif //GL_EXT_texture_integer

// GL_EXT_texture_lod_bias

// GL_EXT_texture_mirror_clamp

#ifndef GL_EXT_texture_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_object\n");
GL_GetFunc( PFN_GLARETEXTURESRESIDENTEXT_PROC, _glAreTexturesResidentEXT_, glAreTexturesResidentEXT);
GL_GetFunc( PFN_GLBINDTEXTUREEXT_PROC, _glBindTextureEXT_, glBindTextureEXT);
GL_GetFunc( PFN_GLDELETETEXTURESEXT_PROC, _glDeleteTexturesEXT_, glDeleteTexturesEXT);
GL_GetFunc( PFN_GLGENTEXTURESEXT_PROC, _glGenTexturesEXT_, glGenTexturesEXT);
GL_GetFunc( PFN_GLISTEXTUREEXT_PROC, _glIsTextureEXT_, glIsTextureEXT);
GL_GetFunc( PFN_GLPRIORITIZETEXTURESEXT_PROC, _glPrioritizeTexturesEXT_, glPrioritizeTexturesEXT);
#endif //GL_EXT_texture_object

#ifndef GL_EXT_texture_perturb_normal
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_perturb_normal\n");
GL_GetFunc( PFN_GLTEXTURENORMALEXT_PROC, _glTextureNormalEXT_, glTextureNormalEXT);
#endif //GL_EXT_texture_perturb_normal

// GL_EXT_texture_sRGB

// GL_EXT_texture_shared_exponent

// GL_EXT_texture_snorm

// GL_EXT_texture_swizzle

#ifndef GL_EXT_timer_query
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_timer_query\n");
GL_GetFunc( PFN_GLGETQUERYOBJECTI64VEXT_PROC, _glGetQueryObjecti64vEXT_, glGetQueryObjecti64vEXT);
GL_GetFunc( PFN_GLGETQUERYOBJECTUI64VEXT_PROC, _glGetQueryObjectui64vEXT_, glGetQueryObjectui64vEXT);
#endif //GL_EXT_timer_query

#ifndef GL_EXT_transform_feedback
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_transform_feedback\n");
GL_GetFunc( PFN_GLBEGINTRANSFORMFEEDBACKEXT_PROC, _glBeginTransformFeedbackEXT_, glBeginTransformFeedbackEXT);
GL_GetFunc( PFN_GLENDTRANSFORMFEEDBACKEXT_PROC, _glEndTransformFeedbackEXT_, glEndTransformFeedbackEXT);
GL_GetFunc( PFN_GLBINDBUFFERRANGEEXT_PROC, _glBindBufferRangeEXT_, glBindBufferRangeEXT);
GL_GetFunc( PFN_GLBINDBUFFEROFFSETEXT_PROC, _glBindBufferOffsetEXT_, glBindBufferOffsetEXT);
GL_GetFunc( PFN_GLBINDBUFFERBASEEXT_PROC, _glBindBufferBaseEXT_, glBindBufferBaseEXT);
GL_GetFunc( PFN_GLTRANSFORMFEEDBACKVARYINGSEXT_PROC, _glTransformFeedbackVaryingsEXT_, glTransformFeedbackVaryingsEXT);
GL_GetFunc( PFN_GLGETTRANSFORMFEEDBACKVARYINGEXT_PROC, _glGetTransformFeedbackVaryingEXT_, glGetTransformFeedbackVaryingEXT);
#endif //GL_EXT_transform_feedback

#ifndef GL_EXT_vertex_array
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_vertex_array\n");
GL_GetFunc( PFN_GLARRAYELEMENTEXT_PROC, _glArrayElementEXT_, glArrayElementEXT);
GL_GetFunc( PFN_GLCOLORPOINTEREXT_PROC, _glColorPointerEXT_, glColorPointerEXT);
GL_GetFunc( PFN_GLDRAWARRAYSEXT_PROC, _glDrawArraysEXT_, glDrawArraysEXT);
GL_GetFunc( PFN_GLEDGEFLAGPOINTEREXT_PROC, _glEdgeFlagPointerEXT_, glEdgeFlagPointerEXT);
GL_GetFunc( PFN_GLGETPOINTERVEXT_PROC, _glGetPointervEXT_, glGetPointervEXT);
GL_GetFunc( PFN_GLINDEXPOINTEREXT_PROC, _glIndexPointerEXT_, glIndexPointerEXT);
GL_GetFunc( PFN_GLNORMALPOINTEREXT_PROC, _glNormalPointerEXT_, glNormalPointerEXT);
GL_GetFunc( PFN_GLTEXCOORDPOINTEREXT_PROC, _glTexCoordPointerEXT_, glTexCoordPointerEXT);
GL_GetFunc( PFN_GLVERTEXPOINTEREXT_PROC, _glVertexPointerEXT_, glVertexPointerEXT);
#endif //GL_EXT_vertex_array

// GL_EXT_vertex_array_bgra

#ifndef GL_EXT_vertex_attrib_64bit
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_vertex_attrib_64bit\n");
GL_GetFunc( PFN_GLVERTEXATTRIBL1DEXT_PROC, _glVertexAttribL1dEXT_, glVertexAttribL1dEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBL2DEXT_PROC, _glVertexAttribL2dEXT_, glVertexAttribL2dEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBL3DEXT_PROC, _glVertexAttribL3dEXT_, glVertexAttribL3dEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBL4DEXT_PROC, _glVertexAttribL4dEXT_, glVertexAttribL4dEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBL1DVEXT_PROC, _glVertexAttribL1dvEXT_, glVertexAttribL1dvEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBL2DVEXT_PROC, _glVertexAttribL2dvEXT_, glVertexAttribL2dvEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBL3DVEXT_PROC, _glVertexAttribL3dvEXT_, glVertexAttribL3dvEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBL4DVEXT_PROC, _glVertexAttribL4dvEXT_, glVertexAttribL4dvEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBLPOINTEREXT_PROC, _glVertexAttribLPointerEXT_, glVertexAttribLPointerEXT);
GL_GetFunc( PFN_GLGETVERTEXATTRIBLDVEXT_PROC, _glGetVertexAttribLdvEXT_, glGetVertexAttribLdvEXT);
#endif //GL_EXT_vertex_attrib_64bit

#ifndef GL_EXT_vertex_shader
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_vertex_shader\n");
GL_GetFunc( PFN_GLBEGINVERTEXSHADEREXT_PROC, _glBeginVertexShaderEXT_, glBeginVertexShaderEXT);
GL_GetFunc( PFN_GLENDVERTEXSHADEREXT_PROC, _glEndVertexShaderEXT_, glEndVertexShaderEXT);
GL_GetFunc( PFN_GLBINDVERTEXSHADEREXT_PROC, _glBindVertexShaderEXT_, glBindVertexShaderEXT);
GL_GetFunc( PFN_GLGENVERTEXSHADERSEXT_PROC, _glGenVertexShadersEXT_, glGenVertexShadersEXT);
GL_GetFunc( PFN_GLDELETEVERTEXSHADEREXT_PROC, _glDeleteVertexShaderEXT_, glDeleteVertexShaderEXT);
GL_GetFunc( PFN_GLSHADEROP1EXT_PROC, _glShaderOp1EXT_, glShaderOp1EXT);
GL_GetFunc( PFN_GLSHADEROP2EXT_PROC, _glShaderOp2EXT_, glShaderOp2EXT);
GL_GetFunc( PFN_GLSHADEROP3EXT_PROC, _glShaderOp3EXT_, glShaderOp3EXT);
GL_GetFunc( PFN_GLSWIZZLEEXT_PROC, _glSwizzleEXT_, glSwizzleEXT);
GL_GetFunc( PFN_GLWRITEMASKEXT_PROC, _glWriteMaskEXT_, glWriteMaskEXT);
GL_GetFunc( PFN_GLINSERTCOMPONENTEXT_PROC, _glInsertComponentEXT_, glInsertComponentEXT);
GL_GetFunc( PFN_GLEXTRACTCOMPONENTEXT_PROC, _glExtractComponentEXT_, glExtractComponentEXT);
GL_GetFunc( PFN_GLGENSYMBOLSEXT_PROC, _glGenSymbolsEXT_, glGenSymbolsEXT);
GL_GetFunc( PFN_GLSETINVARIANTEXT_PROC, _glSetInvariantEXT_, glSetInvariantEXT);
GL_GetFunc( PFN_GLSETLOCALCONSTANTEXT_PROC, _glSetLocalConstantEXT_, glSetLocalConstantEXT);
GL_GetFunc( PFN_GLVARIANTBVEXT_PROC, _glVariantbvEXT_, glVariantbvEXT);
GL_GetFunc( PFN_GLVARIANTSVEXT_PROC, _glVariantsvEXT_, glVariantsvEXT);
GL_GetFunc( PFN_GLVARIANTIVEXT_PROC, _glVariantivEXT_, glVariantivEXT);
GL_GetFunc( PFN_GLVARIANTFVEXT_PROC, _glVariantfvEXT_, glVariantfvEXT);
GL_GetFunc( PFN_GLVARIANTDVEXT_PROC, _glVariantdvEXT_, glVariantdvEXT);
GL_GetFunc( PFN_GLVARIANTUBVEXT_PROC, _glVariantubvEXT_, glVariantubvEXT);
GL_GetFunc( PFN_GLVARIANTUSVEXT_PROC, _glVariantusvEXT_, glVariantusvEXT);
GL_GetFunc( PFN_GLVARIANTUIVEXT_PROC, _glVariantuivEXT_, glVariantuivEXT);
GL_GetFunc( PFN_GLVARIANTPOINTEREXT_PROC, _glVariantPointerEXT_, glVariantPointerEXT);
GL_GetFunc( PFN_GLENABLEVARIANTCLIENTSTATEEXT_PROC, _glEnableVariantClientStateEXT_, glEnableVariantClientStateEXT);
GL_GetFunc( PFN_GLDISABLEVARIANTCLIENTSTATEEXT_PROC, _glDisableVariantClientStateEXT_, glDisableVariantClientStateEXT);
GL_GetFunc( PFN_GLBINDLIGHTPARAMETEREXT_PROC, _glBindLightParameterEXT_, glBindLightParameterEXT);
GL_GetFunc( PFN_GLBINDMATERIALPARAMETEREXT_PROC, _glBindMaterialParameterEXT_, glBindMaterialParameterEXT);
GL_GetFunc( PFN_GLBINDTEXGENPARAMETEREXT_PROC, _glBindTexGenParameterEXT_, glBindTexGenParameterEXT);
GL_GetFunc( PFN_GLBINDTEXTUREUNITPARAMETEREXT_PROC, _glBindTextureUnitParameterEXT_, glBindTextureUnitParameterEXT);
GL_GetFunc( PFN_GLBINDPARAMETEREXT_PROC, _glBindParameterEXT_, glBindParameterEXT);
GL_GetFunc( PFN_GLISVARIANTENABLEDEXT_PROC, _glIsVariantEnabledEXT_, glIsVariantEnabledEXT);
GL_GetFunc( PFN_GLGETVARIANTBOOLEANVEXT_PROC, _glGetVariantBooleanvEXT_, glGetVariantBooleanvEXT);
GL_GetFunc( PFN_GLGETVARIANTINTEGERVEXT_PROC, _glGetVariantIntegervEXT_, glGetVariantIntegervEXT);
GL_GetFunc( PFN_GLGETVARIANTFLOATVEXT_PROC, _glGetVariantFloatvEXT_, glGetVariantFloatvEXT);
GL_GetFunc( PFN_GLGETVARIANTPOINTERVEXT_PROC, _glGetVariantPointervEXT_, glGetVariantPointervEXT);
GL_GetFunc( PFN_GLGETINVARIANTBOOLEANVEXT_PROC, _glGetInvariantBooleanvEXT_, glGetInvariantBooleanvEXT);
GL_GetFunc( PFN_GLGETINVARIANTINTEGERVEXT_PROC, _glGetInvariantIntegervEXT_, glGetInvariantIntegervEXT);
GL_GetFunc( PFN_GLGETINVARIANTFLOATVEXT_PROC, _glGetInvariantFloatvEXT_, glGetInvariantFloatvEXT);
GL_GetFunc( PFN_GLGETLOCALCONSTANTBOOLEANVEXT_PROC, _glGetLocalConstantBooleanvEXT_, glGetLocalConstantBooleanvEXT);
GL_GetFunc( PFN_GLGETLOCALCONSTANTINTEGERVEXT_PROC, _glGetLocalConstantIntegervEXT_, glGetLocalConstantIntegervEXT);
GL_GetFunc( PFN_GLGETLOCALCONSTANTFLOATVEXT_PROC, _glGetLocalConstantFloatvEXT_, glGetLocalConstantFloatvEXT);
#endif //GL_EXT_vertex_shader

#ifndef GL_EXT_vertex_weighting
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_vertex_weighting\n");
GL_GetFunc( PFN_GLVERTEXWEIGHTFEXT_PROC, _glVertexWeightfEXT_, glVertexWeightfEXT);
GL_GetFunc( PFN_GLVERTEXWEIGHTFVEXT_PROC, _glVertexWeightfvEXT_, glVertexWeightfvEXT);
GL_GetFunc( PFN_GLVERTEXWEIGHTPOINTEREXT_PROC, _glVertexWeightPointerEXT_, glVertexWeightPointerEXT);
#endif //GL_EXT_vertex_weighting

#ifndef GL_EXT_win32_keyed_mutex
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_win32_keyed_mutex\n");
GL_GetFunc( PFN_GLACQUIREKEYEDMUTEXWIN32EXT_PROC, _glAcquireKeyedMutexWin32EXT_, glAcquireKeyedMutexWin32EXT);
GL_GetFunc( PFN_GLRELEASEKEYEDMUTEXWIN32EXT_PROC, _glReleaseKeyedMutexWin32EXT_, glReleaseKeyedMutexWin32EXT);
#endif //GL_EXT_win32_keyed_mutex

#ifndef GL_EXT_x11_sync_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_EXT_x11_sync_object\n");
GL_GetFunc( PFN_GLIMPORTSYNCEXT_PROC, _glImportSyncEXT_, glImportSyncEXT);
#endif //GL_EXT_x11_sync_object

#ifndef GL_GREMEDY_frame_terminator
LOG_fprintf(LogGlGetFunctions_py, "\nGL_GREMEDY_frame_terminator\n");
GL_GetFunc( PFN_GLFRAMETERMINATORGREMEDY_PROC, _glFrameTerminatorGREMEDY_, glFrameTerminatorGREMEDY);
#endif //GL_GREMEDY_frame_terminator

#ifndef GL_GREMEDY_string_marker
LOG_fprintf(LogGlGetFunctions_py, "\nGL_GREMEDY_string_marker\n");
GL_GetFunc( PFN_GLSTRINGMARKERGREMEDY_PROC, _glStringMarkerGREMEDY_, glStringMarkerGREMEDY);
#endif //GL_GREMEDY_string_marker

// GL_HP_convolution_border_modes

#ifndef GL_HP_image_transform
LOG_fprintf(LogGlGetFunctions_py, "\nGL_HP_image_transform\n");
GL_GetFunc( PFN_GLIMAGETRANSFORMPARAMETERIHP_PROC, _glImageTransformParameteriHP_, glImageTransformParameteriHP);
GL_GetFunc( PFN_GLIMAGETRANSFORMPARAMETERFHP_PROC, _glImageTransformParameterfHP_, glImageTransformParameterfHP);
GL_GetFunc( PFN_GLIMAGETRANSFORMPARAMETERIVHP_PROC, _glImageTransformParameterivHP_, glImageTransformParameterivHP);
GL_GetFunc( PFN_GLIMAGETRANSFORMPARAMETERFVHP_PROC, _glImageTransformParameterfvHP_, glImageTransformParameterfvHP);
GL_GetFunc( PFN_GLGETIMAGETRANSFORMPARAMETERIVHP_PROC, _glGetImageTransformParameterivHP_, glGetImageTransformParameterivHP);
GL_GetFunc( PFN_GLGETIMAGETRANSFORMPARAMETERFVHP_PROC, _glGetImageTransformParameterfvHP_, glGetImageTransformParameterfvHP);
#endif //GL_HP_image_transform

// GL_HP_occlusion_test

// GL_HP_texture_lighting

// GL_IBM_cull_vertex

#ifndef GL_IBM_multimode_draw_arrays
LOG_fprintf(LogGlGetFunctions_py, "\nGL_IBM_multimode_draw_arrays\n");
GL_GetFunc( PFN_GLMULTIMODEDRAWARRAYSIBM_PROC, _glMultiModeDrawArraysIBM_, glMultiModeDrawArraysIBM);
GL_GetFunc( PFN_GLMULTIMODEDRAWELEMENTSIBM_PROC, _glMultiModeDrawElementsIBM_, glMultiModeDrawElementsIBM);
#endif //GL_IBM_multimode_draw_arrays

// GL_IBM_rasterpos_clip

#ifndef GL_IBM_static_data
LOG_fprintf(LogGlGetFunctions_py, "\nGL_IBM_static_data\n");
GL_GetFunc( PFN_GLFLUSHSTATICDATAIBM_PROC, _glFlushStaticDataIBM_, glFlushStaticDataIBM);
#endif //GL_IBM_static_data

// GL_IBM_texture_mirrored_repeat

#ifndef GL_IBM_vertex_array_lists
LOG_fprintf(LogGlGetFunctions_py, "\nGL_IBM_vertex_array_lists\n");
GL_GetFunc( PFN_GLCOLORPOINTERLISTIBM_PROC, _glColorPointerListIBM_, glColorPointerListIBM);
GL_GetFunc( PFN_GLSECONDARYCOLORPOINTERLISTIBM_PROC, _glSecondaryColorPointerListIBM_, glSecondaryColorPointerListIBM);
GL_GetFunc( PFN_GLEDGEFLAGPOINTERLISTIBM_PROC, _glEdgeFlagPointerListIBM_, glEdgeFlagPointerListIBM);
GL_GetFunc( PFN_GLFOGCOORDPOINTERLISTIBM_PROC, _glFogCoordPointerListIBM_, glFogCoordPointerListIBM);
GL_GetFunc( PFN_GLINDEXPOINTERLISTIBM_PROC, _glIndexPointerListIBM_, glIndexPointerListIBM);
GL_GetFunc( PFN_GLNORMALPOINTERLISTIBM_PROC, _glNormalPointerListIBM_, glNormalPointerListIBM);
GL_GetFunc( PFN_GLTEXCOORDPOINTERLISTIBM_PROC, _glTexCoordPointerListIBM_, glTexCoordPointerListIBM);
GL_GetFunc( PFN_GLVERTEXPOINTERLISTIBM_PROC, _glVertexPointerListIBM_, glVertexPointerListIBM);
#endif //GL_IBM_vertex_array_lists

#ifndef GL_INGR_blend_func_separate
LOG_fprintf(LogGlGetFunctions_py, "\nGL_INGR_blend_func_separate\n");
GL_GetFunc( PFN_GLBLENDFUNCSEPARATEINGR_PROC, _glBlendFuncSeparateINGR_, glBlendFuncSeparateINGR);
#endif //GL_INGR_blend_func_separate

// GL_INGR_color_clamp

// GL_INGR_interlace_read

// GL_INTEL_fragment_shader_ordering

#ifndef GL_INTEL_map_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_INTEL_map_texture\n");
GL_GetFunc( PFN_GLSYNCTEXTUREINTEL_PROC, _glSyncTextureINTEL_, glSyncTextureINTEL);
GL_GetFunc( PFN_GLUNMAPTEXTURE2DINTEL_PROC, _glUnmapTexture2DINTEL_, glUnmapTexture2DINTEL);
GL_GetFunc( PFN_GLMAPTEXTURE2DINTEL_PROC, _glMapTexture2DINTEL_, glMapTexture2DINTEL);
#endif //GL_INTEL_map_texture

#ifndef GL_INTEL_parallel_arrays
LOG_fprintf(LogGlGetFunctions_py, "\nGL_INTEL_parallel_arrays\n");
GL_GetFunc( PFN_GLVERTEXPOINTERVINTEL_PROC, _glVertexPointervINTEL_, glVertexPointervINTEL);
GL_GetFunc( PFN_GLNORMALPOINTERVINTEL_PROC, _glNormalPointervINTEL_, glNormalPointervINTEL);
GL_GetFunc( PFN_GLCOLORPOINTERVINTEL_PROC, _glColorPointervINTEL_, glColorPointervINTEL);
GL_GetFunc( PFN_GLTEXCOORDPOINTERVINTEL_PROC, _glTexCoordPointervINTEL_, glTexCoordPointervINTEL);
#endif //GL_INTEL_parallel_arrays

// GL_MESAX_texture_stack

// GL_MESA_pack_invert

// GL_MESA_program_binary_formats

#ifndef GL_MESA_resize_buffers
LOG_fprintf(LogGlGetFunctions_py, "\nGL_MESA_resize_buffers\n");
GL_GetFunc( PFN_GLRESIZEBUFFERSMESA_PROC, _glResizeBuffersMESA_, glResizeBuffersMESA);
#endif //GL_MESA_resize_buffers

// GL_MESA_shader_integer_functions

// GL_MESA_tile_raster_order

#ifndef GL_MESA_window_pos
LOG_fprintf(LogGlGetFunctions_py, "\nGL_MESA_window_pos\n");
GL_GetFunc( PFN_GLWINDOWPOS2DMESA_PROC, _glWindowPos2dMESA_, glWindowPos2dMESA);
GL_GetFunc( PFN_GLWINDOWPOS2DVMESA_PROC, _glWindowPos2dvMESA_, glWindowPos2dvMESA);
GL_GetFunc( PFN_GLWINDOWPOS2FMESA_PROC, _glWindowPos2fMESA_, glWindowPos2fMESA);
GL_GetFunc( PFN_GLWINDOWPOS2FVMESA_PROC, _glWindowPos2fvMESA_, glWindowPos2fvMESA);
GL_GetFunc( PFN_GLWINDOWPOS2IMESA_PROC, _glWindowPos2iMESA_, glWindowPos2iMESA);
GL_GetFunc( PFN_GLWINDOWPOS2IVMESA_PROC, _glWindowPos2ivMESA_, glWindowPos2ivMESA);
GL_GetFunc( PFN_GLWINDOWPOS2SMESA_PROC, _glWindowPos2sMESA_, glWindowPos2sMESA);
GL_GetFunc( PFN_GLWINDOWPOS2SVMESA_PROC, _glWindowPos2svMESA_, glWindowPos2svMESA);
GL_GetFunc( PFN_GLWINDOWPOS3DMESA_PROC, _glWindowPos3dMESA_, glWindowPos3dMESA);
GL_GetFunc( PFN_GLWINDOWPOS3DVMESA_PROC, _glWindowPos3dvMESA_, glWindowPos3dvMESA);
GL_GetFunc( PFN_GLWINDOWPOS3FMESA_PROC, _glWindowPos3fMESA_, glWindowPos3fMESA);
GL_GetFunc( PFN_GLWINDOWPOS3FVMESA_PROC, _glWindowPos3fvMESA_, glWindowPos3fvMESA);
GL_GetFunc( PFN_GLWINDOWPOS3IMESA_PROC, _glWindowPos3iMESA_, glWindowPos3iMESA);
GL_GetFunc( PFN_GLWINDOWPOS3IVMESA_PROC, _glWindowPos3ivMESA_, glWindowPos3ivMESA);
GL_GetFunc( PFN_GLWINDOWPOS3SMESA_PROC, _glWindowPos3sMESA_, glWindowPos3sMESA);
GL_GetFunc( PFN_GLWINDOWPOS3SVMESA_PROC, _glWindowPos3svMESA_, glWindowPos3svMESA);
GL_GetFunc( PFN_GLWINDOWPOS4DMESA_PROC, _glWindowPos4dMESA_, glWindowPos4dMESA);
GL_GetFunc( PFN_GLWINDOWPOS4DVMESA_PROC, _glWindowPos4dvMESA_, glWindowPos4dvMESA);
GL_GetFunc( PFN_GLWINDOWPOS4FMESA_PROC, _glWindowPos4fMESA_, glWindowPos4fMESA);
GL_GetFunc( PFN_GLWINDOWPOS4FVMESA_PROC, _glWindowPos4fvMESA_, glWindowPos4fvMESA);
GL_GetFunc( PFN_GLWINDOWPOS4IMESA_PROC, _glWindowPos4iMESA_, glWindowPos4iMESA);
GL_GetFunc( PFN_GLWINDOWPOS4IVMESA_PROC, _glWindowPos4ivMESA_, glWindowPos4ivMESA);
GL_GetFunc( PFN_GLWINDOWPOS4SMESA_PROC, _glWindowPos4sMESA_, glWindowPos4sMESA);
GL_GetFunc( PFN_GLWINDOWPOS4SVMESA_PROC, _glWindowPos4svMESA_, glWindowPos4svMESA);
#endif //GL_MESA_window_pos

// GL_MESA_ycbcr_texture

// GL_NVX_blend_equation_advanced_multi_draw_buffers

#ifndef GL_NVX_conditional_render
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NVX_conditional_render\n");
GL_GetFunc( PFN_GLBEGINCONDITIONALRENDERNVX_PROC, _glBeginConditionalRenderNVX_, glBeginConditionalRenderNVX);
GL_GetFunc( PFN_GLENDCONDITIONALRENDERNVX_PROC, _glEndConditionalRenderNVX_, glEndConditionalRenderNVX);
#endif //GL_NVX_conditional_render

// GL_NVX_gpu_memory_info

#ifndef GL_NVX_gpu_multicast2
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NVX_gpu_multicast2\n");
GL_GetFunc( PFN_GLUPLOADGPUMASKNVX_PROC, _glUploadGpuMaskNVX_, glUploadGpuMaskNVX);
GL_GetFunc( PFN_GLMULTICASTVIEWPORTARRAYVNVX_PROC, _glMulticastViewportArrayvNVX_, glMulticastViewportArrayvNVX);
GL_GetFunc( PFN_GLMULTICASTVIEWPORTPOSITIONWSCALENVX_PROC, _glMulticastViewportPositionWScaleNVX_, glMulticastViewportPositionWScaleNVX);
GL_GetFunc( PFN_GLMULTICASTSCISSORARRAYVNVX_PROC, _glMulticastScissorArrayvNVX_, glMulticastScissorArrayvNVX);
GL_GetFunc( PFN_GLASYNCCOPYBUFFERSUBDATANVX_PROC, _glAsyncCopyBufferSubDataNVX_, glAsyncCopyBufferSubDataNVX);
GL_GetFunc( PFN_GLASYNCCOPYIMAGESUBDATANVX_PROC, _glAsyncCopyImageSubDataNVX_, glAsyncCopyImageSubDataNVX);
#endif //GL_NVX_gpu_multicast2

#ifndef GL_NVX_linked_gpu_multicast
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NVX_linked_gpu_multicast\n");
GL_GetFunc( PFN_GLLGPUNAMEDBUFFERSUBDATANVX_PROC, _glLGPUNamedBufferSubDataNVX_, glLGPUNamedBufferSubDataNVX);
GL_GetFunc( PFN_GLLGPUCOPYIMAGESUBDATANVX_PROC, _glLGPUCopyImageSubDataNVX_, glLGPUCopyImageSubDataNVX);
GL_GetFunc( PFN_GLLGPUINTERLOCKNVX_PROC, _glLGPUInterlockNVX_, glLGPUInterlockNVX);
#endif //GL_NVX_linked_gpu_multicast

#ifndef GL_NVX_progress_fence
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NVX_progress_fence\n");
GL_GetFunc( PFN_GLCREATEPROGRESSFENCENVX_PROC, _glCreateProgressFenceNVX_, glCreateProgressFenceNVX);
GL_GetFunc( PFN_GLSIGNALSEMAPHOREUI64NVX_PROC, _glSignalSemaphoreui64NVX_, glSignalSemaphoreui64NVX);
GL_GetFunc( PFN_GLWAITSEMAPHOREUI64NVX_PROC, _glWaitSemaphoreui64NVX_, glWaitSemaphoreui64NVX);
GL_GetFunc( PFN_GLCLIENTWAITSEMAPHOREUI64NVX_PROC, _glClientWaitSemaphoreui64NVX_, glClientWaitSemaphoreui64NVX);
#endif //GL_NVX_progress_fence

#ifndef GL_NV_alpha_to_coverage_dither_control
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_alpha_to_coverage_dither_control\n");
GL_GetFunc( PFN_GLALPHATOCOVERAGEDITHERCONTROLNV_PROC, _glAlphaToCoverageDitherControlNV_, glAlphaToCoverageDitherControlNV);
#endif //GL_NV_alpha_to_coverage_dither_control

// GL_NV_blend_square

// GL_NV_compute_program5

// GL_NV_copy_depth_to_color

#ifndef GL_NV_copy_image
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_copy_image\n");
GL_GetFunc( PFN_GLCOPYIMAGESUBDATANV_PROC, _glCopyImageSubDataNV_, glCopyImageSubDataNV);
#endif //GL_NV_copy_image

// GL_NV_deep_texture3D

#ifndef GL_NV_depth_buffer_float
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_depth_buffer_float\n");
GL_GetFunc( PFN_GLDEPTHRANGEDNV_PROC, _glDepthRangedNV_, glDepthRangedNV);
GL_GetFunc( PFN_GLCLEARDEPTHDNV_PROC, _glClearDepthdNV_, glClearDepthdNV);
GL_GetFunc( PFN_GLDEPTHBOUNDSDNV_PROC, _glDepthBoundsdNV_, glDepthBoundsdNV);
#endif //GL_NV_depth_buffer_float

// GL_NV_depth_clamp

#ifndef GL_NV_draw_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_draw_texture\n");
GL_GetFunc( PFN_GLDRAWTEXTURENV_PROC, _glDrawTextureNV_, glDrawTextureNV);
#endif //GL_NV_draw_texture

#ifndef GL_NV_evaluators
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_evaluators\n");
GL_GetFunc( PFN_GLMAPCONTROLPOINTSNV_PROC, _glMapControlPointsNV_, glMapControlPointsNV);
GL_GetFunc( PFN_GLMAPPARAMETERIVNV_PROC, _glMapParameterivNV_, glMapParameterivNV);
GL_GetFunc( PFN_GLMAPPARAMETERFVNV_PROC, _glMapParameterfvNV_, glMapParameterfvNV);
GL_GetFunc( PFN_GLGETMAPCONTROLPOINTSNV_PROC, _glGetMapControlPointsNV_, glGetMapControlPointsNV);
GL_GetFunc( PFN_GLGETMAPPARAMETERIVNV_PROC, _glGetMapParameterivNV_, glGetMapParameterivNV);
GL_GetFunc( PFN_GLGETMAPPARAMETERFVNV_PROC, _glGetMapParameterfvNV_, glGetMapParameterfvNV);
GL_GetFunc( PFN_GLGETMAPATTRIBPARAMETERIVNV_PROC, _glGetMapAttribParameterivNV_, glGetMapAttribParameterivNV);
GL_GetFunc( PFN_GLGETMAPATTRIBPARAMETERFVNV_PROC, _glGetMapAttribParameterfvNV_, glGetMapAttribParameterfvNV);
GL_GetFunc( PFN_GLEVALMAPSNV_PROC, _glEvalMapsNV_, glEvalMapsNV);
#endif //GL_NV_evaluators

#ifndef GL_NV_explicit_multisample
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_explicit_multisample\n");
GL_GetFunc( PFN_GLGETMULTISAMPLEFVNV_PROC, _glGetMultisamplefvNV_, glGetMultisamplefvNV);
GL_GetFunc( PFN_GLSAMPLEMASKINDEXEDNV_PROC, _glSampleMaskIndexedNV_, glSampleMaskIndexedNV);
GL_GetFunc( PFN_GLTEXRENDERBUFFERNV_PROC, _glTexRenderbufferNV_, glTexRenderbufferNV);
#endif //GL_NV_explicit_multisample

#ifndef GL_NV_fence
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_fence\n");
GL_GetFunc( PFN_GLDELETEFENCESNV_PROC, _glDeleteFencesNV_, glDeleteFencesNV);
GL_GetFunc( PFN_GLGENFENCESNV_PROC, _glGenFencesNV_, glGenFencesNV);
GL_GetFunc( PFN_GLISFENCENV_PROC, _glIsFenceNV_, glIsFenceNV);
GL_GetFunc( PFN_GLTESTFENCENV_PROC, _glTestFenceNV_, glTestFenceNV);
GL_GetFunc( PFN_GLGETFENCEIVNV_PROC, _glGetFenceivNV_, glGetFenceivNV);
GL_GetFunc( PFN_GLFINISHFENCENV_PROC, _glFinishFenceNV_, glFinishFenceNV);
GL_GetFunc( PFN_GLSETFENCENV_PROC, _glSetFenceNV_, glSetFenceNV);
#endif //GL_NV_fence

// GL_NV_float_buffer

// GL_NV_fog_distance

#ifndef GL_NV_fragment_program
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_fragment_program\n");
GL_GetFunc( PFN_GLPROGRAMNAMEDPARAMETER4FNV_PROC, _glProgramNamedParameter4fNV_, glProgramNamedParameter4fNV);
GL_GetFunc( PFN_GLPROGRAMNAMEDPARAMETER4FVNV_PROC, _glProgramNamedParameter4fvNV_, glProgramNamedParameter4fvNV);
GL_GetFunc( PFN_GLPROGRAMNAMEDPARAMETER4DNV_PROC, _glProgramNamedParameter4dNV_, glProgramNamedParameter4dNV);
GL_GetFunc( PFN_GLPROGRAMNAMEDPARAMETER4DVNV_PROC, _glProgramNamedParameter4dvNV_, glProgramNamedParameter4dvNV);
GL_GetFunc( PFN_GLGETPROGRAMNAMEDPARAMETERFVNV_PROC, _glGetProgramNamedParameterfvNV_, glGetProgramNamedParameterfvNV);
GL_GetFunc( PFN_GLGETPROGRAMNAMEDPARAMETERDVNV_PROC, _glGetProgramNamedParameterdvNV_, glGetProgramNamedParameterdvNV);
#endif //GL_NV_fragment_program

// GL_NV_fragment_program2

// GL_NV_fragment_program4

// GL_NV_fragment_program_option

#ifndef GL_NV_geometry_program4
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_geometry_program4\n");
GL_GetFunc( PFN_GLPROGRAMVERTEXLIMITNV_PROC, _glProgramVertexLimitNV_, glProgramVertexLimitNV);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTUREEXT_PROC, _glFramebufferTextureEXT_, glFramebufferTextureEXT);
GL_GetFunc( PFN_GLFRAMEBUFFERTEXTUREFACEEXT_PROC, _glFramebufferTextureFaceEXT_, glFramebufferTextureFaceEXT);
#endif //GL_NV_geometry_program4

// GL_NV_geometry_shader4

#ifndef GL_NV_gpu_multicast
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_gpu_multicast\n");
GL_GetFunc( PFN_GLRENDERGPUMASKNV_PROC, _glRenderGpuMaskNV_, glRenderGpuMaskNV);
GL_GetFunc( PFN_GLMULTICASTBUFFERSUBDATANV_PROC, _glMulticastBufferSubDataNV_, glMulticastBufferSubDataNV);
GL_GetFunc( PFN_GLMULTICASTCOPYBUFFERSUBDATANV_PROC, _glMulticastCopyBufferSubDataNV_, glMulticastCopyBufferSubDataNV);
GL_GetFunc( PFN_GLMULTICASTCOPYIMAGESUBDATANV_PROC, _glMulticastCopyImageSubDataNV_, glMulticastCopyImageSubDataNV);
GL_GetFunc( PFN_GLMULTICASTBLITFRAMEBUFFERNV_PROC, _glMulticastBlitFramebufferNV_, glMulticastBlitFramebufferNV);
GL_GetFunc( PFN_GLMULTICASTFRAMEBUFFERSAMPLELOCATIONSFVNV_PROC, _glMulticastFramebufferSampleLocationsfvNV_, glMulticastFramebufferSampleLocationsfvNV);
GL_GetFunc( PFN_GLMULTICASTBARRIERNV_PROC, _glMulticastBarrierNV_, glMulticastBarrierNV);
GL_GetFunc( PFN_GLMULTICASTWAITSYNCNV_PROC, _glMulticastWaitSyncNV_, glMulticastWaitSyncNV);
GL_GetFunc( PFN_GLMULTICASTGETQUERYOBJECTIVNV_PROC, _glMulticastGetQueryObjectivNV_, glMulticastGetQueryObjectivNV);
GL_GetFunc( PFN_GLMULTICASTGETQUERYOBJECTUIVNV_PROC, _glMulticastGetQueryObjectuivNV_, glMulticastGetQueryObjectuivNV);
GL_GetFunc( PFN_GLMULTICASTGETQUERYOBJECTI64VNV_PROC, _glMulticastGetQueryObjecti64vNV_, glMulticastGetQueryObjecti64vNV);
GL_GetFunc( PFN_GLMULTICASTGETQUERYOBJECTUI64VNV_PROC, _glMulticastGetQueryObjectui64vNV_, glMulticastGetQueryObjectui64vNV);
#endif //GL_NV_gpu_multicast

#ifndef GL_NV_gpu_program4
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_gpu_program4\n");
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETERI4INV_PROC, _glProgramLocalParameterI4iNV_, glProgramLocalParameterI4iNV);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETERI4IVNV_PROC, _glProgramLocalParameterI4ivNV_, glProgramLocalParameterI4ivNV);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETERSI4IVNV_PROC, _glProgramLocalParametersI4ivNV_, glProgramLocalParametersI4ivNV);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETERI4UINV_PROC, _glProgramLocalParameterI4uiNV_, glProgramLocalParameterI4uiNV);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETERI4UIVNV_PROC, _glProgramLocalParameterI4uivNV_, glProgramLocalParameterI4uivNV);
GL_GetFunc( PFN_GLPROGRAMLOCALPARAMETERSI4UIVNV_PROC, _glProgramLocalParametersI4uivNV_, glProgramLocalParametersI4uivNV);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETERI4INV_PROC, _glProgramEnvParameterI4iNV_, glProgramEnvParameterI4iNV);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETERI4IVNV_PROC, _glProgramEnvParameterI4ivNV_, glProgramEnvParameterI4ivNV);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETERSI4IVNV_PROC, _glProgramEnvParametersI4ivNV_, glProgramEnvParametersI4ivNV);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETERI4UINV_PROC, _glProgramEnvParameterI4uiNV_, glProgramEnvParameterI4uiNV);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETERI4UIVNV_PROC, _glProgramEnvParameterI4uivNV_, glProgramEnvParameterI4uivNV);
GL_GetFunc( PFN_GLPROGRAMENVPARAMETERSI4UIVNV_PROC, _glProgramEnvParametersI4uivNV_, glProgramEnvParametersI4uivNV);
GL_GetFunc( PFN_GLGETPROGRAMLOCALPARAMETERIIVNV_PROC, _glGetProgramLocalParameterIivNV_, glGetProgramLocalParameterIivNV);
GL_GetFunc( PFN_GLGETPROGRAMLOCALPARAMETERIUIVNV_PROC, _glGetProgramLocalParameterIuivNV_, glGetProgramLocalParameterIuivNV);
GL_GetFunc( PFN_GLGETPROGRAMENVPARAMETERIIVNV_PROC, _glGetProgramEnvParameterIivNV_, glGetProgramEnvParameterIivNV);
GL_GetFunc( PFN_GLGETPROGRAMENVPARAMETERIUIVNV_PROC, _glGetProgramEnvParameterIuivNV_, glGetProgramEnvParameterIuivNV);
#endif //GL_NV_gpu_program4

#ifndef GL_NV_gpu_program5
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_gpu_program5\n");
GL_GetFunc( PFN_GLPROGRAMSUBROUTINEPARAMETERSUIVNV_PROC, _glProgramSubroutineParametersuivNV_, glProgramSubroutineParametersuivNV);
GL_GetFunc( PFN_GLGETPROGRAMSUBROUTINEPARAMETERUIVNV_PROC, _glGetProgramSubroutineParameteruivNV_, glGetProgramSubroutineParameteruivNV);
#endif //GL_NV_gpu_program5

// GL_NV_gpu_program5_mem_extended

#ifndef GL_NV_half_float
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_half_float\n");
GL_GetFunc( PFN_GLVERTEX2HNV_PROC, _glVertex2hNV_, glVertex2hNV);
GL_GetFunc( PFN_GLVERTEX2HVNV_PROC, _glVertex2hvNV_, glVertex2hvNV);
GL_GetFunc( PFN_GLVERTEX3HNV_PROC, _glVertex3hNV_, glVertex3hNV);
GL_GetFunc( PFN_GLVERTEX3HVNV_PROC, _glVertex3hvNV_, glVertex3hvNV);
GL_GetFunc( PFN_GLVERTEX4HNV_PROC, _glVertex4hNV_, glVertex4hNV);
GL_GetFunc( PFN_GLVERTEX4HVNV_PROC, _glVertex4hvNV_, glVertex4hvNV);
GL_GetFunc( PFN_GLNORMAL3HNV_PROC, _glNormal3hNV_, glNormal3hNV);
GL_GetFunc( PFN_GLNORMAL3HVNV_PROC, _glNormal3hvNV_, glNormal3hvNV);
GL_GetFunc( PFN_GLCOLOR3HNV_PROC, _glColor3hNV_, glColor3hNV);
GL_GetFunc( PFN_GLCOLOR3HVNV_PROC, _glColor3hvNV_, glColor3hvNV);
GL_GetFunc( PFN_GLCOLOR4HNV_PROC, _glColor4hNV_, glColor4hNV);
GL_GetFunc( PFN_GLCOLOR4HVNV_PROC, _glColor4hvNV_, glColor4hvNV);
GL_GetFunc( PFN_GLTEXCOORD1HNV_PROC, _glTexCoord1hNV_, glTexCoord1hNV);
GL_GetFunc( PFN_GLTEXCOORD1HVNV_PROC, _glTexCoord1hvNV_, glTexCoord1hvNV);
GL_GetFunc( PFN_GLTEXCOORD2HNV_PROC, _glTexCoord2hNV_, glTexCoord2hNV);
GL_GetFunc( PFN_GLTEXCOORD2HVNV_PROC, _glTexCoord2hvNV_, glTexCoord2hvNV);
GL_GetFunc( PFN_GLTEXCOORD3HNV_PROC, _glTexCoord3hNV_, glTexCoord3hNV);
GL_GetFunc( PFN_GLTEXCOORD3HVNV_PROC, _glTexCoord3hvNV_, glTexCoord3hvNV);
GL_GetFunc( PFN_GLTEXCOORD4HNV_PROC, _glTexCoord4hNV_, glTexCoord4hNV);
GL_GetFunc( PFN_GLTEXCOORD4HVNV_PROC, _glTexCoord4hvNV_, glTexCoord4hvNV);
GL_GetFunc( PFN_GLMULTITEXCOORD1HNV_PROC, _glMultiTexCoord1hNV_, glMultiTexCoord1hNV);
GL_GetFunc( PFN_GLMULTITEXCOORD1HVNV_PROC, _glMultiTexCoord1hvNV_, glMultiTexCoord1hvNV);
GL_GetFunc( PFN_GLMULTITEXCOORD2HNV_PROC, _glMultiTexCoord2hNV_, glMultiTexCoord2hNV);
GL_GetFunc( PFN_GLMULTITEXCOORD2HVNV_PROC, _glMultiTexCoord2hvNV_, glMultiTexCoord2hvNV);
GL_GetFunc( PFN_GLMULTITEXCOORD3HNV_PROC, _glMultiTexCoord3hNV_, glMultiTexCoord3hNV);
GL_GetFunc( PFN_GLMULTITEXCOORD3HVNV_PROC, _glMultiTexCoord3hvNV_, glMultiTexCoord3hvNV);
GL_GetFunc( PFN_GLMULTITEXCOORD4HNV_PROC, _glMultiTexCoord4hNV_, glMultiTexCoord4hNV);
GL_GetFunc( PFN_GLMULTITEXCOORD4HVNV_PROC, _glMultiTexCoord4hvNV_, glMultiTexCoord4hvNV);
GL_GetFunc( PFN_GLFOGCOORDHNV_PROC, _glFogCoordhNV_, glFogCoordhNV);
GL_GetFunc( PFN_GLFOGCOORDHVNV_PROC, _glFogCoordhvNV_, glFogCoordhvNV);
GL_GetFunc( PFN_GLSECONDARYCOLOR3HNV_PROC, _glSecondaryColor3hNV_, glSecondaryColor3hNV);
GL_GetFunc( PFN_GLSECONDARYCOLOR3HVNV_PROC, _glSecondaryColor3hvNV_, glSecondaryColor3hvNV);
GL_GetFunc( PFN_GLVERTEXWEIGHTHNV_PROC, _glVertexWeighthNV_, glVertexWeighthNV);
GL_GetFunc( PFN_GLVERTEXWEIGHTHVNV_PROC, _glVertexWeighthvNV_, glVertexWeighthvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB1HNV_PROC, _glVertexAttrib1hNV_, glVertexAttrib1hNV);
GL_GetFunc( PFN_GLVERTEXATTRIB1HVNV_PROC, _glVertexAttrib1hvNV_, glVertexAttrib1hvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB2HNV_PROC, _glVertexAttrib2hNV_, glVertexAttrib2hNV);
GL_GetFunc( PFN_GLVERTEXATTRIB2HVNV_PROC, _glVertexAttrib2hvNV_, glVertexAttrib2hvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB3HNV_PROC, _glVertexAttrib3hNV_, glVertexAttrib3hNV);
GL_GetFunc( PFN_GLVERTEXATTRIB3HVNV_PROC, _glVertexAttrib3hvNV_, glVertexAttrib3hvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4HNV_PROC, _glVertexAttrib4hNV_, glVertexAttrib4hNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4HVNV_PROC, _glVertexAttrib4hvNV_, glVertexAttrib4hvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS1HVNV_PROC, _glVertexAttribs1hvNV_, glVertexAttribs1hvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS2HVNV_PROC, _glVertexAttribs2hvNV_, glVertexAttribs2hvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS3HVNV_PROC, _glVertexAttribs3hvNV_, glVertexAttribs3hvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS4HVNV_PROC, _glVertexAttribs4hvNV_, glVertexAttribs4hvNV);
#endif //GL_NV_half_float

// GL_NV_light_max_exponent

// GL_NV_multisample_coverage

// GL_NV_multisample_filter_hint

#ifndef GL_NV_occlusion_query
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_occlusion_query\n");
GL_GetFunc( PFN_GLGENOCCLUSIONQUERIESNV_PROC, _glGenOcclusionQueriesNV_, glGenOcclusionQueriesNV);
GL_GetFunc( PFN_GLDELETEOCCLUSIONQUERIESNV_PROC, _glDeleteOcclusionQueriesNV_, glDeleteOcclusionQueriesNV);
GL_GetFunc( PFN_GLISOCCLUSIONQUERYNV_PROC, _glIsOcclusionQueryNV_, glIsOcclusionQueryNV);
GL_GetFunc( PFN_GLBEGINOCCLUSIONQUERYNV_PROC, _glBeginOcclusionQueryNV_, glBeginOcclusionQueryNV);
GL_GetFunc( PFN_GLENDOCCLUSIONQUERYNV_PROC, _glEndOcclusionQueryNV_, glEndOcclusionQueryNV);
GL_GetFunc( PFN_GLGETOCCLUSIONQUERYIVNV_PROC, _glGetOcclusionQueryivNV_, glGetOcclusionQueryivNV);
GL_GetFunc( PFN_GLGETOCCLUSIONQUERYUIVNV_PROC, _glGetOcclusionQueryuivNV_, glGetOcclusionQueryuivNV);
#endif //GL_NV_occlusion_query

// GL_NV_packed_depth_stencil

#ifndef GL_NV_parameter_buffer_object
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_parameter_buffer_object\n");
GL_GetFunc( PFN_GLPROGRAMBUFFERPARAMETERSFVNV_PROC, _glProgramBufferParametersfvNV_, glProgramBufferParametersfvNV);
GL_GetFunc( PFN_GLPROGRAMBUFFERPARAMETERSIIVNV_PROC, _glProgramBufferParametersIivNV_, glProgramBufferParametersIivNV);
GL_GetFunc( PFN_GLPROGRAMBUFFERPARAMETERSIUIVNV_PROC, _glProgramBufferParametersIuivNV_, glProgramBufferParametersIuivNV);
#endif //GL_NV_parameter_buffer_object

// GL_NV_parameter_buffer_object2

#ifndef GL_NV_pixel_data_range
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_pixel_data_range\n");
GL_GetFunc( PFN_GLPIXELDATARANGENV_PROC, _glPixelDataRangeNV_, glPixelDataRangeNV);
GL_GetFunc( PFN_GLFLUSHPIXELDATARANGENV_PROC, _glFlushPixelDataRangeNV_, glFlushPixelDataRangeNV);
#endif //GL_NV_pixel_data_range

#ifndef GL_NV_point_sprite
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_point_sprite\n");
GL_GetFunc( PFN_GLPOINTPARAMETERINV_PROC, _glPointParameteriNV_, glPointParameteriNV);
GL_GetFunc( PFN_GLPOINTPARAMETERIVNV_PROC, _glPointParameterivNV_, glPointParameterivNV);
#endif //GL_NV_point_sprite

#ifndef GL_NV_present_video
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_present_video\n");
GL_GetFunc( PFN_GLPRESENTFRAMEKEYEDNV_PROC, _glPresentFrameKeyedNV_, glPresentFrameKeyedNV);
GL_GetFunc( PFN_GLPRESENTFRAMEDUALFILLNV_PROC, _glPresentFrameDualFillNV_, glPresentFrameDualFillNV);
GL_GetFunc( PFN_GLGETVIDEOIVNV_PROC, _glGetVideoivNV_, glGetVideoivNV);
GL_GetFunc( PFN_GLGETVIDEOUIVNV_PROC, _glGetVideouivNV_, glGetVideouivNV);
GL_GetFunc( PFN_GLGETVIDEOI64VNV_PROC, _glGetVideoi64vNV_, glGetVideoi64vNV);
GL_GetFunc( PFN_GLGETVIDEOUI64VNV_PROC, _glGetVideoui64vNV_, glGetVideoui64vNV);
#endif //GL_NV_present_video

#ifndef GL_NV_primitive_restart
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_primitive_restart\n");
GL_GetFunc( PFN_GLPRIMITIVERESTARTNV_PROC, _glPrimitiveRestartNV_, glPrimitiveRestartNV);
GL_GetFunc( PFN_GLPRIMITIVERESTARTINDEXNV_PROC, _glPrimitiveRestartIndexNV_, glPrimitiveRestartIndexNV);
#endif //GL_NV_primitive_restart

#ifndef GL_NV_query_resource
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_query_resource\n");
GL_GetFunc( PFN_GLQUERYRESOURCENV_PROC, _glQueryResourceNV_, glQueryResourceNV);
#endif //GL_NV_query_resource

#ifndef GL_NV_query_resource_tag
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_query_resource_tag\n");
GL_GetFunc( PFN_GLGENQUERYRESOURCETAGNV_PROC, _glGenQueryResourceTagNV_, glGenQueryResourceTagNV);
GL_GetFunc( PFN_GLDELETEQUERYRESOURCETAGNV_PROC, _glDeleteQueryResourceTagNV_, glDeleteQueryResourceTagNV);
GL_GetFunc( PFN_GLQUERYRESOURCETAGNV_PROC, _glQueryResourceTagNV_, glQueryResourceTagNV);
#endif //GL_NV_query_resource_tag

#ifndef GL_NV_register_combiners
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_register_combiners\n");
GL_GetFunc( PFN_GLCOMBINERPARAMETERFVNV_PROC, _glCombinerParameterfvNV_, glCombinerParameterfvNV);
GL_GetFunc( PFN_GLCOMBINERPARAMETERFNV_PROC, _glCombinerParameterfNV_, glCombinerParameterfNV);
GL_GetFunc( PFN_GLCOMBINERPARAMETERIVNV_PROC, _glCombinerParameterivNV_, glCombinerParameterivNV);
GL_GetFunc( PFN_GLCOMBINERPARAMETERINV_PROC, _glCombinerParameteriNV_, glCombinerParameteriNV);
GL_GetFunc( PFN_GLCOMBINERINPUTNV_PROC, _glCombinerInputNV_, glCombinerInputNV);
GL_GetFunc( PFN_GLCOMBINEROUTPUTNV_PROC, _glCombinerOutputNV_, glCombinerOutputNV);
GL_GetFunc( PFN_GLFINALCOMBINERINPUTNV_PROC, _glFinalCombinerInputNV_, glFinalCombinerInputNV);
GL_GetFunc( PFN_GLGETCOMBINERINPUTPARAMETERFVNV_PROC, _glGetCombinerInputParameterfvNV_, glGetCombinerInputParameterfvNV);
GL_GetFunc( PFN_GLGETCOMBINERINPUTPARAMETERIVNV_PROC, _glGetCombinerInputParameterivNV_, glGetCombinerInputParameterivNV);
GL_GetFunc( PFN_GLGETCOMBINEROUTPUTPARAMETERFVNV_PROC, _glGetCombinerOutputParameterfvNV_, glGetCombinerOutputParameterfvNV);
GL_GetFunc( PFN_GLGETCOMBINEROUTPUTPARAMETERIVNV_PROC, _glGetCombinerOutputParameterivNV_, glGetCombinerOutputParameterivNV);
GL_GetFunc( PFN_GLGETFINALCOMBINERINPUTPARAMETERFVNV_PROC, _glGetFinalCombinerInputParameterfvNV_, glGetFinalCombinerInputParameterfvNV);
GL_GetFunc( PFN_GLGETFINALCOMBINERINPUTPARAMETERIVNV_PROC, _glGetFinalCombinerInputParameterivNV_, glGetFinalCombinerInputParameterivNV);
#endif //GL_NV_register_combiners

#ifndef GL_NV_register_combiners2
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_register_combiners2\n");
GL_GetFunc( PFN_GLCOMBINERSTAGEPARAMETERFVNV_PROC, _glCombinerStageParameterfvNV_, glCombinerStageParameterfvNV);
GL_GetFunc( PFN_GLGETCOMBINERSTAGEPARAMETERFVNV_PROC, _glGetCombinerStageParameterfvNV_, glGetCombinerStageParameterfvNV);
#endif //GL_NV_register_combiners2

// GL_NV_robustness_video_memory_purge

// GL_NV_shader_storage_buffer_object

// GL_NV_tessellation_program5

// GL_NV_texgen_emboss

// GL_NV_texgen_reflection

// GL_NV_texture_compression_vtc

// GL_NV_texture_env_combine4

// GL_NV_texture_expand_normal

#ifndef GL_NV_texture_multisample
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_texture_multisample\n");
GL_GetFunc( PFN_GLTEXIMAGE2DMULTISAMPLECOVERAGENV_PROC, _glTexImage2DMultisampleCoverageNV_, glTexImage2DMultisampleCoverageNV);
GL_GetFunc( PFN_GLTEXIMAGE3DMULTISAMPLECOVERAGENV_PROC, _glTexImage3DMultisampleCoverageNV_, glTexImage3DMultisampleCoverageNV);
GL_GetFunc( PFN_GLTEXTUREIMAGE2DMULTISAMPLENV_PROC, _glTextureImage2DMultisampleNV_, glTextureImage2DMultisampleNV);
GL_GetFunc( PFN_GLTEXTUREIMAGE3DMULTISAMPLENV_PROC, _glTextureImage3DMultisampleNV_, glTextureImage3DMultisampleNV);
GL_GetFunc( PFN_GLTEXTUREIMAGE2DMULTISAMPLECOVERAGENV_PROC, _glTextureImage2DMultisampleCoverageNV_, glTextureImage2DMultisampleCoverageNV);
GL_GetFunc( PFN_GLTEXTUREIMAGE3DMULTISAMPLECOVERAGENV_PROC, _glTextureImage3DMultisampleCoverageNV_, glTextureImage3DMultisampleCoverageNV);
#endif //GL_NV_texture_multisample

// GL_NV_texture_rectangle

// GL_NV_texture_shader

// GL_NV_texture_shader2

// GL_NV_texture_shader3

#ifndef GL_NV_transform_feedback
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_transform_feedback\n");
GL_GetFunc( PFN_GLBEGINTRANSFORMFEEDBACKNV_PROC, _glBeginTransformFeedbackNV_, glBeginTransformFeedbackNV);
GL_GetFunc( PFN_GLENDTRANSFORMFEEDBACKNV_PROC, _glEndTransformFeedbackNV_, glEndTransformFeedbackNV);
GL_GetFunc( PFN_GLTRANSFORMFEEDBACKATTRIBSNV_PROC, _glTransformFeedbackAttribsNV_, glTransformFeedbackAttribsNV);
GL_GetFunc( PFN_GLBINDBUFFERRANGENV_PROC, _glBindBufferRangeNV_, glBindBufferRangeNV);
GL_GetFunc( PFN_GLBINDBUFFEROFFSETNV_PROC, _glBindBufferOffsetNV_, glBindBufferOffsetNV);
GL_GetFunc( PFN_GLBINDBUFFERBASENV_PROC, _glBindBufferBaseNV_, glBindBufferBaseNV);
GL_GetFunc( PFN_GLTRANSFORMFEEDBACKVARYINGSNV_PROC, _glTransformFeedbackVaryingsNV_, glTransformFeedbackVaryingsNV);
GL_GetFunc( PFN_GLACTIVEVARYINGNV_PROC, _glActiveVaryingNV_, glActiveVaryingNV);
GL_GetFunc( PFN_GLGETVARYINGLOCATIONNV_PROC, _glGetVaryingLocationNV_, glGetVaryingLocationNV);
GL_GetFunc( PFN_GLGETACTIVEVARYINGNV_PROC, _glGetActiveVaryingNV_, glGetActiveVaryingNV);
GL_GetFunc( PFN_GLGETTRANSFORMFEEDBACKVARYINGNV_PROC, _glGetTransformFeedbackVaryingNV_, glGetTransformFeedbackVaryingNV);
GL_GetFunc( PFN_GLTRANSFORMFEEDBACKSTREAMATTRIBSNV_PROC, _glTransformFeedbackStreamAttribsNV_, glTransformFeedbackStreamAttribsNV);
#endif //GL_NV_transform_feedback

#ifndef GL_NV_transform_feedback2
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_transform_feedback2\n");
GL_GetFunc( PFN_GLBINDTRANSFORMFEEDBACKNV_PROC, _glBindTransformFeedbackNV_, glBindTransformFeedbackNV);
GL_GetFunc( PFN_GLDELETETRANSFORMFEEDBACKSNV_PROC, _glDeleteTransformFeedbacksNV_, glDeleteTransformFeedbacksNV);
GL_GetFunc( PFN_GLGENTRANSFORMFEEDBACKSNV_PROC, _glGenTransformFeedbacksNV_, glGenTransformFeedbacksNV);
GL_GetFunc( PFN_GLISTRANSFORMFEEDBACKNV_PROC, _glIsTransformFeedbackNV_, glIsTransformFeedbackNV);
GL_GetFunc( PFN_GLPAUSETRANSFORMFEEDBACKNV_PROC, _glPauseTransformFeedbackNV_, glPauseTransformFeedbackNV);
GL_GetFunc( PFN_GLRESUMETRANSFORMFEEDBACKNV_PROC, _glResumeTransformFeedbackNV_, glResumeTransformFeedbackNV);
GL_GetFunc( PFN_GLDRAWTRANSFORMFEEDBACKNV_PROC, _glDrawTransformFeedbackNV_, glDrawTransformFeedbackNV);
#endif //GL_NV_transform_feedback2

#ifndef GL_NV_vdpau_interop
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_vdpau_interop\n");
GL_GetFunc( PFN_GLVDPAUINITNV_PROC, _glVDPAUInitNV_, glVDPAUInitNV);
GL_GetFunc( PFN_GLVDPAUFININV_PROC, _glVDPAUFiniNV_, glVDPAUFiniNV);
GL_GetFunc( PFN_GLVDPAUREGISTERVIDEOSURFACENV_PROC, _glVDPAURegisterVideoSurfaceNV_, glVDPAURegisterVideoSurfaceNV);
GL_GetFunc( PFN_GLVDPAUREGISTEROUTPUTSURFACENV_PROC, _glVDPAURegisterOutputSurfaceNV_, glVDPAURegisterOutputSurfaceNV);
GL_GetFunc( PFN_GLVDPAUISSURFACENV_PROC, _glVDPAUIsSurfaceNV_, glVDPAUIsSurfaceNV);
GL_GetFunc( PFN_GLVDPAUUNREGISTERSURFACENV_PROC, _glVDPAUUnregisterSurfaceNV_, glVDPAUUnregisterSurfaceNV);
GL_GetFunc( PFN_GLVDPAUGETSURFACEIVNV_PROC, _glVDPAUGetSurfaceivNV_, glVDPAUGetSurfaceivNV);
GL_GetFunc( PFN_GLVDPAUSURFACEACCESSNV_PROC, _glVDPAUSurfaceAccessNV_, glVDPAUSurfaceAccessNV);
GL_GetFunc( PFN_GLVDPAUMAPSURFACESNV_PROC, _glVDPAUMapSurfacesNV_, glVDPAUMapSurfacesNV);
GL_GetFunc( PFN_GLVDPAUUNMAPSURFACESNV_PROC, _glVDPAUUnmapSurfacesNV_, glVDPAUUnmapSurfacesNV);
#endif //GL_NV_vdpau_interop

#ifndef GL_NV_vdpau_interop2
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_vdpau_interop2\n");
GL_GetFunc( PFN_GLVDPAUREGISTERVIDEOSURFACEWITHPICTURESTRUCTURENV_PROC, _glVDPAURegisterVideoSurfaceWithPictureStructureNV_, glVDPAURegisterVideoSurfaceWithPictureStructureNV);
#endif //GL_NV_vdpau_interop2

#ifndef GL_NV_vertex_array_range
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_array_range\n");
GL_GetFunc( PFN_GLFLUSHVERTEXARRAYRANGENV_PROC, _glFlushVertexArrayRangeNV_, glFlushVertexArrayRangeNV);
GL_GetFunc( PFN_GLVERTEXARRAYRANGENV_PROC, _glVertexArrayRangeNV_, glVertexArrayRangeNV);
#endif //GL_NV_vertex_array_range

// GL_NV_vertex_array_range2

#ifndef GL_NV_vertex_program
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_program\n");
GL_GetFunc( PFN_GLAREPROGRAMSRESIDENTNV_PROC, _glAreProgramsResidentNV_, glAreProgramsResidentNV);
GL_GetFunc( PFN_GLBINDPROGRAMNV_PROC, _glBindProgramNV_, glBindProgramNV);
GL_GetFunc( PFN_GLDELETEPROGRAMSNV_PROC, _glDeleteProgramsNV_, glDeleteProgramsNV);
GL_GetFunc( PFN_GLEXECUTEPROGRAMNV_PROC, _glExecuteProgramNV_, glExecuteProgramNV);
GL_GetFunc( PFN_GLGENPROGRAMSNV_PROC, _glGenProgramsNV_, glGenProgramsNV);
GL_GetFunc( PFN_GLGETPROGRAMPARAMETERDVNV_PROC, _glGetProgramParameterdvNV_, glGetProgramParameterdvNV);
GL_GetFunc( PFN_GLGETPROGRAMPARAMETERFVNV_PROC, _glGetProgramParameterfvNV_, glGetProgramParameterfvNV);
GL_GetFunc( PFN_GLGETPROGRAMIVNV_PROC, _glGetProgramivNV_, glGetProgramivNV);
GL_GetFunc( PFN_GLGETPROGRAMSTRINGNV_PROC, _glGetProgramStringNV_, glGetProgramStringNV);
GL_GetFunc( PFN_GLGETTRACKMATRIXIVNV_PROC, _glGetTrackMatrixivNV_, glGetTrackMatrixivNV);
GL_GetFunc( PFN_GLGETVERTEXATTRIBDVNV_PROC, _glGetVertexAttribdvNV_, glGetVertexAttribdvNV);
GL_GetFunc( PFN_GLGETVERTEXATTRIBFVNV_PROC, _glGetVertexAttribfvNV_, glGetVertexAttribfvNV);
GL_GetFunc( PFN_GLGETVERTEXATTRIBIVNV_PROC, _glGetVertexAttribivNV_, glGetVertexAttribivNV);
GL_GetFunc( PFN_GLGETVERTEXATTRIBPOINTERVNV_PROC, _glGetVertexAttribPointervNV_, glGetVertexAttribPointervNV);
GL_GetFunc( PFN_GLISPROGRAMNV_PROC, _glIsProgramNV_, glIsProgramNV);
GL_GetFunc( PFN_GLLOADPROGRAMNV_PROC, _glLoadProgramNV_, glLoadProgramNV);
GL_GetFunc( PFN_GLPROGRAMPARAMETER4DNV_PROC, _glProgramParameter4dNV_, glProgramParameter4dNV);
GL_GetFunc( PFN_GLPROGRAMPARAMETER4DVNV_PROC, _glProgramParameter4dvNV_, glProgramParameter4dvNV);
GL_GetFunc( PFN_GLPROGRAMPARAMETER4FNV_PROC, _glProgramParameter4fNV_, glProgramParameter4fNV);
GL_GetFunc( PFN_GLPROGRAMPARAMETER4FVNV_PROC, _glProgramParameter4fvNV_, glProgramParameter4fvNV);
GL_GetFunc( PFN_GLPROGRAMPARAMETERS4DVNV_PROC, _glProgramParameters4dvNV_, glProgramParameters4dvNV);
GL_GetFunc( PFN_GLPROGRAMPARAMETERS4FVNV_PROC, _glProgramParameters4fvNV_, glProgramParameters4fvNV);
GL_GetFunc( PFN_GLREQUESTRESIDENTPROGRAMSNV_PROC, _glRequestResidentProgramsNV_, glRequestResidentProgramsNV);
GL_GetFunc( PFN_GLTRACKMATRIXNV_PROC, _glTrackMatrixNV_, glTrackMatrixNV);
GL_GetFunc( PFN_GLVERTEXATTRIBPOINTERNV_PROC, _glVertexAttribPointerNV_, glVertexAttribPointerNV);
GL_GetFunc( PFN_GLVERTEXATTRIB1DNV_PROC, _glVertexAttrib1dNV_, glVertexAttrib1dNV);
GL_GetFunc( PFN_GLVERTEXATTRIB1DVNV_PROC, _glVertexAttrib1dvNV_, glVertexAttrib1dvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB1FNV_PROC, _glVertexAttrib1fNV_, glVertexAttrib1fNV);
GL_GetFunc( PFN_GLVERTEXATTRIB1FVNV_PROC, _glVertexAttrib1fvNV_, glVertexAttrib1fvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB1SNV_PROC, _glVertexAttrib1sNV_, glVertexAttrib1sNV);
GL_GetFunc( PFN_GLVERTEXATTRIB1SVNV_PROC, _glVertexAttrib1svNV_, glVertexAttrib1svNV);
GL_GetFunc( PFN_GLVERTEXATTRIB2DNV_PROC, _glVertexAttrib2dNV_, glVertexAttrib2dNV);
GL_GetFunc( PFN_GLVERTEXATTRIB2DVNV_PROC, _glVertexAttrib2dvNV_, glVertexAttrib2dvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB2FNV_PROC, _glVertexAttrib2fNV_, glVertexAttrib2fNV);
GL_GetFunc( PFN_GLVERTEXATTRIB2FVNV_PROC, _glVertexAttrib2fvNV_, glVertexAttrib2fvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB2SNV_PROC, _glVertexAttrib2sNV_, glVertexAttrib2sNV);
GL_GetFunc( PFN_GLVERTEXATTRIB2SVNV_PROC, _glVertexAttrib2svNV_, glVertexAttrib2svNV);
GL_GetFunc( PFN_GLVERTEXATTRIB3DNV_PROC, _glVertexAttrib3dNV_, glVertexAttrib3dNV);
GL_GetFunc( PFN_GLVERTEXATTRIB3DVNV_PROC, _glVertexAttrib3dvNV_, glVertexAttrib3dvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB3FNV_PROC, _glVertexAttrib3fNV_, glVertexAttrib3fNV);
GL_GetFunc( PFN_GLVERTEXATTRIB3FVNV_PROC, _glVertexAttrib3fvNV_, glVertexAttrib3fvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB3SNV_PROC, _glVertexAttrib3sNV_, glVertexAttrib3sNV);
GL_GetFunc( PFN_GLVERTEXATTRIB3SVNV_PROC, _glVertexAttrib3svNV_, glVertexAttrib3svNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4DNV_PROC, _glVertexAttrib4dNV_, glVertexAttrib4dNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4DVNV_PROC, _glVertexAttrib4dvNV_, glVertexAttrib4dvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4FNV_PROC, _glVertexAttrib4fNV_, glVertexAttrib4fNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4FVNV_PROC, _glVertexAttrib4fvNV_, glVertexAttrib4fvNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4SNV_PROC, _glVertexAttrib4sNV_, glVertexAttrib4sNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4SVNV_PROC, _glVertexAttrib4svNV_, glVertexAttrib4svNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4UBNV_PROC, _glVertexAttrib4ubNV_, glVertexAttrib4ubNV);
GL_GetFunc( PFN_GLVERTEXATTRIB4UBVNV_PROC, _glVertexAttrib4ubvNV_, glVertexAttrib4ubvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS1DVNV_PROC, _glVertexAttribs1dvNV_, glVertexAttribs1dvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS1FVNV_PROC, _glVertexAttribs1fvNV_, glVertexAttribs1fvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS1SVNV_PROC, _glVertexAttribs1svNV_, glVertexAttribs1svNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS2DVNV_PROC, _glVertexAttribs2dvNV_, glVertexAttribs2dvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS2FVNV_PROC, _glVertexAttribs2fvNV_, glVertexAttribs2fvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS2SVNV_PROC, _glVertexAttribs2svNV_, glVertexAttribs2svNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS3DVNV_PROC, _glVertexAttribs3dvNV_, glVertexAttribs3dvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS3FVNV_PROC, _glVertexAttribs3fvNV_, glVertexAttribs3fvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS3SVNV_PROC, _glVertexAttribs3svNV_, glVertexAttribs3svNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS4DVNV_PROC, _glVertexAttribs4dvNV_, glVertexAttribs4dvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS4FVNV_PROC, _glVertexAttribs4fvNV_, glVertexAttribs4fvNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS4SVNV_PROC, _glVertexAttribs4svNV_, glVertexAttribs4svNV);
GL_GetFunc( PFN_GLVERTEXATTRIBS4UBVNV_PROC, _glVertexAttribs4ubvNV_, glVertexAttribs4ubvNV);
#endif //GL_NV_vertex_program

// GL_NV_vertex_program1_1

// GL_NV_vertex_program2

// GL_NV_vertex_program2_option

// GL_NV_vertex_program3

#ifndef GL_NV_vertex_program4
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_program4\n");
GL_GetFunc( PFN_GLVERTEXATTRIBI1IEXT_PROC, _glVertexAttribI1iEXT_, glVertexAttribI1iEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI2IEXT_PROC, _glVertexAttribI2iEXT_, glVertexAttribI2iEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI3IEXT_PROC, _glVertexAttribI3iEXT_, glVertexAttribI3iEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI4IEXT_PROC, _glVertexAttribI4iEXT_, glVertexAttribI4iEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI1UIEXT_PROC, _glVertexAttribI1uiEXT_, glVertexAttribI1uiEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI2UIEXT_PROC, _glVertexAttribI2uiEXT_, glVertexAttribI2uiEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI3UIEXT_PROC, _glVertexAttribI3uiEXT_, glVertexAttribI3uiEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI4UIEXT_PROC, _glVertexAttribI4uiEXT_, glVertexAttribI4uiEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI1IVEXT_PROC, _glVertexAttribI1ivEXT_, glVertexAttribI1ivEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI2IVEXT_PROC, _glVertexAttribI2ivEXT_, glVertexAttribI2ivEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI3IVEXT_PROC, _glVertexAttribI3ivEXT_, glVertexAttribI3ivEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI4IVEXT_PROC, _glVertexAttribI4ivEXT_, glVertexAttribI4ivEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI1UIVEXT_PROC, _glVertexAttribI1uivEXT_, glVertexAttribI1uivEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI2UIVEXT_PROC, _glVertexAttribI2uivEXT_, glVertexAttribI2uivEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI3UIVEXT_PROC, _glVertexAttribI3uivEXT_, glVertexAttribI3uivEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI4UIVEXT_PROC, _glVertexAttribI4uivEXT_, glVertexAttribI4uivEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI4BVEXT_PROC, _glVertexAttribI4bvEXT_, glVertexAttribI4bvEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI4SVEXT_PROC, _glVertexAttribI4svEXT_, glVertexAttribI4svEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI4UBVEXT_PROC, _glVertexAttribI4ubvEXT_, glVertexAttribI4ubvEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBI4USVEXT_PROC, _glVertexAttribI4usvEXT_, glVertexAttribI4usvEXT);
GL_GetFunc( PFN_GLVERTEXATTRIBIPOINTEREXT_PROC, _glVertexAttribIPointerEXT_, glVertexAttribIPointerEXT);
GL_GetFunc( PFN_GLGETVERTEXATTRIBIIVEXT_PROC, _glGetVertexAttribIivEXT_, glGetVertexAttribIivEXT);
GL_GetFunc( PFN_GLGETVERTEXATTRIBIUIVEXT_PROC, _glGetVertexAttribIuivEXT_, glGetVertexAttribIuivEXT);
#endif //GL_NV_vertex_program4

#ifndef GL_NV_video_capture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_NV_video_capture\n");
GL_GetFunc( PFN_GLBEGINVIDEOCAPTURENV_PROC, _glBeginVideoCaptureNV_, glBeginVideoCaptureNV);
GL_GetFunc( PFN_GLBINDVIDEOCAPTURESTREAMBUFFERNV_PROC, _glBindVideoCaptureStreamBufferNV_, glBindVideoCaptureStreamBufferNV);
GL_GetFunc( PFN_GLBINDVIDEOCAPTURESTREAMTEXTURENV_PROC, _glBindVideoCaptureStreamTextureNV_, glBindVideoCaptureStreamTextureNV);
GL_GetFunc( PFN_GLENDVIDEOCAPTURENV_PROC, _glEndVideoCaptureNV_, glEndVideoCaptureNV);
GL_GetFunc( PFN_GLGETVIDEOCAPTUREIVNV_PROC, _glGetVideoCaptureivNV_, glGetVideoCaptureivNV);
GL_GetFunc( PFN_GLGETVIDEOCAPTURESTREAMIVNV_PROC, _glGetVideoCaptureStreamivNV_, glGetVideoCaptureStreamivNV);
GL_GetFunc( PFN_GLGETVIDEOCAPTURESTREAMFVNV_PROC, _glGetVideoCaptureStreamfvNV_, glGetVideoCaptureStreamfvNV);
GL_GetFunc( PFN_GLGETVIDEOCAPTURESTREAMDVNV_PROC, _glGetVideoCaptureStreamdvNV_, glGetVideoCaptureStreamdvNV);
GL_GetFunc( PFN_GLVIDEOCAPTURENV_PROC, _glVideoCaptureNV_, glVideoCaptureNV);
GL_GetFunc( PFN_GLVIDEOCAPTURESTREAMPARAMETERIVNV_PROC, _glVideoCaptureStreamParameterivNV_, glVideoCaptureStreamParameterivNV);
GL_GetFunc( PFN_GLVIDEOCAPTURESTREAMPARAMETERFVNV_PROC, _glVideoCaptureStreamParameterfvNV_, glVideoCaptureStreamParameterfvNV);
GL_GetFunc( PFN_GLVIDEOCAPTURESTREAMPARAMETERDVNV_PROC, _glVideoCaptureStreamParameterdvNV_, glVideoCaptureStreamParameterdvNV);
#endif //GL_NV_video_capture

// GL_OML_interlace

// GL_OML_resample

// GL_OML_subsample

#ifndef GL_PGI_misc_hints
LOG_fprintf(LogGlGetFunctions_py, "\nGL_PGI_misc_hints\n");
GL_GetFunc( PFN_GLHINTPGI_PROC, _glHintPGI_, glHintPGI);
#endif //GL_PGI_misc_hints

// GL_PGI_vertex_hints

// GL_REND_screen_coordinates

// GL_S3_s3tc

#ifndef GL_SGIS_detail_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIS_detail_texture\n");
GL_GetFunc( PFN_GLDETAILTEXFUNCSGIS_PROC, _glDetailTexFuncSGIS_, glDetailTexFuncSGIS);
GL_GetFunc( PFN_GLGETDETAILTEXFUNCSGIS_PROC, _glGetDetailTexFuncSGIS_, glGetDetailTexFuncSGIS);
#endif //GL_SGIS_detail_texture

#ifndef GL_SGIS_fog_function
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIS_fog_function\n");
GL_GetFunc( PFN_GLFOGFUNCSGIS_PROC, _glFogFuncSGIS_, glFogFuncSGIS);
GL_GetFunc( PFN_GLGETFOGFUNCSGIS_PROC, _glGetFogFuncSGIS_, glGetFogFuncSGIS);
#endif //GL_SGIS_fog_function

// GL_SGIS_generate_mipmap

#ifndef GL_SGIS_multisample
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIS_multisample\n");
GL_GetFunc( PFN_GLSAMPLEMASKSGIS_PROC, _glSampleMaskSGIS_, glSampleMaskSGIS);
GL_GetFunc( PFN_GLSAMPLEPATTERNSGIS_PROC, _glSamplePatternSGIS_, glSamplePatternSGIS);
#endif //GL_SGIS_multisample

#ifndef GL_SGIS_pixel_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIS_pixel_texture\n");
GL_GetFunc( PFN_GLPIXELTEXGENPARAMETERISGIS_PROC, _glPixelTexGenParameteriSGIS_, glPixelTexGenParameteriSGIS);
GL_GetFunc( PFN_GLPIXELTEXGENPARAMETERIVSGIS_PROC, _glPixelTexGenParameterivSGIS_, glPixelTexGenParameterivSGIS);
GL_GetFunc( PFN_GLPIXELTEXGENPARAMETERFSGIS_PROC, _glPixelTexGenParameterfSGIS_, glPixelTexGenParameterfSGIS);
GL_GetFunc( PFN_GLPIXELTEXGENPARAMETERFVSGIS_PROC, _glPixelTexGenParameterfvSGIS_, glPixelTexGenParameterfvSGIS);
GL_GetFunc( PFN_GLGETPIXELTEXGENPARAMETERIVSGIS_PROC, _glGetPixelTexGenParameterivSGIS_, glGetPixelTexGenParameterivSGIS);
GL_GetFunc( PFN_GLGETPIXELTEXGENPARAMETERFVSGIS_PROC, _glGetPixelTexGenParameterfvSGIS_, glGetPixelTexGenParameterfvSGIS);
#endif //GL_SGIS_pixel_texture

// GL_SGIS_point_line_texgen

#ifndef GL_SGIS_point_parameters
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIS_point_parameters\n");
GL_GetFunc( PFN_GLPOINTPARAMETERFSGIS_PROC, _glPointParameterfSGIS_, glPointParameterfSGIS);
GL_GetFunc( PFN_GLPOINTPARAMETERFVSGIS_PROC, _glPointParameterfvSGIS_, glPointParameterfvSGIS);
#endif //GL_SGIS_point_parameters

#ifndef GL_SGIS_sharpen_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIS_sharpen_texture\n");
GL_GetFunc( PFN_GLSHARPENTEXFUNCSGIS_PROC, _glSharpenTexFuncSGIS_, glSharpenTexFuncSGIS);
GL_GetFunc( PFN_GLGETSHARPENTEXFUNCSGIS_PROC, _glGetSharpenTexFuncSGIS_, glGetSharpenTexFuncSGIS);
#endif //GL_SGIS_sharpen_texture

#ifndef GL_SGIS_texture4D
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIS_texture4D\n");
GL_GetFunc( PFN_GLTEXIMAGE4DSGIS_PROC, _glTexImage4DSGIS_, glTexImage4DSGIS);
GL_GetFunc( PFN_GLTEXSUBIMAGE4DSGIS_PROC, _glTexSubImage4DSGIS_, glTexSubImage4DSGIS);
#endif //GL_SGIS_texture4D

// GL_SGIS_texture_border_clamp

#ifndef GL_SGIS_texture_color_mask
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIS_texture_color_mask\n");
GL_GetFunc( PFN_GLTEXTURECOLORMASKSGIS_PROC, _glTextureColorMaskSGIS_, glTextureColorMaskSGIS);
#endif //GL_SGIS_texture_color_mask

// GL_SGIS_texture_edge_clamp

#ifndef GL_SGIS_texture_filter4
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIS_texture_filter4\n");
GL_GetFunc( PFN_GLGETTEXFILTERFUNCSGIS_PROC, _glGetTexFilterFuncSGIS_, glGetTexFilterFuncSGIS);
GL_GetFunc( PFN_GLTEXFILTERFUNCSGIS_PROC, _glTexFilterFuncSGIS_, glTexFilterFuncSGIS);
#endif //GL_SGIS_texture_filter4

// GL_SGIS_texture_lod

// GL_SGIS_texture_select

#ifndef GL_SGIX_async
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_async\n");
GL_GetFunc( PFN_GLASYNCMARKERSGIX_PROC, _glAsyncMarkerSGIX_, glAsyncMarkerSGIX);
GL_GetFunc( PFN_GLFINISHASYNCSGIX_PROC, _glFinishAsyncSGIX_, glFinishAsyncSGIX);
GL_GetFunc( PFN_GLPOLLASYNCSGIX_PROC, _glPollAsyncSGIX_, glPollAsyncSGIX);
GL_GetFunc( PFN_GLGENASYNCMARKERSSGIX_PROC, _glGenAsyncMarkersSGIX_, glGenAsyncMarkersSGIX);
GL_GetFunc( PFN_GLDELETEASYNCMARKERSSGIX_PROC, _glDeleteAsyncMarkersSGIX_, glDeleteAsyncMarkersSGIX);
GL_GetFunc( PFN_GLISASYNCMARKERSGIX_PROC, _glIsAsyncMarkerSGIX_, glIsAsyncMarkerSGIX);
#endif //GL_SGIX_async

// GL_SGIX_async_histogram

// GL_SGIX_async_pixel

// GL_SGIX_blend_alpha_minmax

// GL_SGIX_calligraphic_fragment

// GL_SGIX_clipmap

// GL_SGIX_convolution_accuracy

// GL_SGIX_depth_pass_instrument

// GL_SGIX_depth_texture

#ifndef GL_SGIX_flush_raster
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_flush_raster\n");
GL_GetFunc( PFN_GLFLUSHRASTERSGIX_PROC, _glFlushRasterSGIX_, glFlushRasterSGIX);
#endif //GL_SGIX_flush_raster

// GL_SGIX_fog_offset

#ifndef GL_SGIX_fragment_lighting
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_fragment_lighting\n");
GL_GetFunc( PFN_GLFRAGMENTCOLORMATERIALSGIX_PROC, _glFragmentColorMaterialSGIX_, glFragmentColorMaterialSGIX);
GL_GetFunc( PFN_GLFRAGMENTLIGHTFSGIX_PROC, _glFragmentLightfSGIX_, glFragmentLightfSGIX);
GL_GetFunc( PFN_GLFRAGMENTLIGHTFVSGIX_PROC, _glFragmentLightfvSGIX_, glFragmentLightfvSGIX);
GL_GetFunc( PFN_GLFRAGMENTLIGHTISGIX_PROC, _glFragmentLightiSGIX_, glFragmentLightiSGIX);
GL_GetFunc( PFN_GLFRAGMENTLIGHTIVSGIX_PROC, _glFragmentLightivSGIX_, glFragmentLightivSGIX);
GL_GetFunc( PFN_GLFRAGMENTLIGHTMODELFSGIX_PROC, _glFragmentLightModelfSGIX_, glFragmentLightModelfSGIX);
GL_GetFunc( PFN_GLFRAGMENTLIGHTMODELFVSGIX_PROC, _glFragmentLightModelfvSGIX_, glFragmentLightModelfvSGIX);
GL_GetFunc( PFN_GLFRAGMENTLIGHTMODELISGIX_PROC, _glFragmentLightModeliSGIX_, glFragmentLightModeliSGIX);
GL_GetFunc( PFN_GLFRAGMENTLIGHTMODELIVSGIX_PROC, _glFragmentLightModelivSGIX_, glFragmentLightModelivSGIX);
GL_GetFunc( PFN_GLFRAGMENTMATERIALFSGIX_PROC, _glFragmentMaterialfSGIX_, glFragmentMaterialfSGIX);
GL_GetFunc( PFN_GLFRAGMENTMATERIALFVSGIX_PROC, _glFragmentMaterialfvSGIX_, glFragmentMaterialfvSGIX);
GL_GetFunc( PFN_GLFRAGMENTMATERIALISGIX_PROC, _glFragmentMaterialiSGIX_, glFragmentMaterialiSGIX);
GL_GetFunc( PFN_GLFRAGMENTMATERIALIVSGIX_PROC, _glFragmentMaterialivSGIX_, glFragmentMaterialivSGIX);
GL_GetFunc( PFN_GLGETFRAGMENTLIGHTFVSGIX_PROC, _glGetFragmentLightfvSGIX_, glGetFragmentLightfvSGIX);
GL_GetFunc( PFN_GLGETFRAGMENTLIGHTIVSGIX_PROC, _glGetFragmentLightivSGIX_, glGetFragmentLightivSGIX);
GL_GetFunc( PFN_GLGETFRAGMENTMATERIALFVSGIX_PROC, _glGetFragmentMaterialfvSGIX_, glGetFragmentMaterialfvSGIX);
GL_GetFunc( PFN_GLGETFRAGMENTMATERIALIVSGIX_PROC, _glGetFragmentMaterialivSGIX_, glGetFragmentMaterialivSGIX);
GL_GetFunc( PFN_GLLIGHTENVISGIX_PROC, _glLightEnviSGIX_, glLightEnviSGIX);
#endif //GL_SGIX_fragment_lighting

#ifndef GL_SGIX_framezoom
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_framezoom\n");
GL_GetFunc( PFN_GLFRAMEZOOMSGIX_PROC, _glFrameZoomSGIX_, glFrameZoomSGIX);
#endif //GL_SGIX_framezoom

#ifndef GL_SGIX_igloo_interface
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_igloo_interface\n");
GL_GetFunc( PFN_GLIGLOOINTERFACESGIX_PROC, _glIglooInterfaceSGIX_, glIglooInterfaceSGIX);
#endif //GL_SGIX_igloo_interface

#ifndef GL_SGIX_instruments
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_instruments\n");
GL_GetFunc( PFN_GLGETINSTRUMENTSSGIX_PROC, _glGetInstrumentsSGIX_, glGetInstrumentsSGIX);
GL_GetFunc( PFN_GLINSTRUMENTSBUFFERSGIX_PROC, _glInstrumentsBufferSGIX_, glInstrumentsBufferSGIX);
GL_GetFunc( PFN_GLPOLLINSTRUMENTSSGIX_PROC, _glPollInstrumentsSGIX_, glPollInstrumentsSGIX);
GL_GetFunc( PFN_GLREADINSTRUMENTSSGIX_PROC, _glReadInstrumentsSGIX_, glReadInstrumentsSGIX);
GL_GetFunc( PFN_GLSTARTINSTRUMENTSSGIX_PROC, _glStartInstrumentsSGIX_, glStartInstrumentsSGIX);
GL_GetFunc( PFN_GLSTOPINSTRUMENTSSGIX_PROC, _glStopInstrumentsSGIX_, glStopInstrumentsSGIX);
#endif //GL_SGIX_instruments

// GL_SGIX_interlace

// GL_SGIX_ir_instrument1

#ifndef GL_SGIX_list_priority
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_list_priority\n");
GL_GetFunc( PFN_GLGETLISTPARAMETERFVSGIX_PROC, _glGetListParameterfvSGIX_, glGetListParameterfvSGIX);
GL_GetFunc( PFN_GLGETLISTPARAMETERIVSGIX_PROC, _glGetListParameterivSGIX_, glGetListParameterivSGIX);
GL_GetFunc( PFN_GLLISTPARAMETERFSGIX_PROC, _glListParameterfSGIX_, glListParameterfSGIX);
GL_GetFunc( PFN_GLLISTPARAMETERFVSGIX_PROC, _glListParameterfvSGIX_, glListParameterfvSGIX);
GL_GetFunc( PFN_GLLISTPARAMETERISGIX_PROC, _glListParameteriSGIX_, glListParameteriSGIX);
GL_GetFunc( PFN_GLLISTPARAMETERIVSGIX_PROC, _glListParameterivSGIX_, glListParameterivSGIX);
#endif //GL_SGIX_list_priority

#ifndef GL_SGIX_pixel_texture
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_pixel_texture\n");
GL_GetFunc( PFN_GLPIXELTEXGENSGIX_PROC, _glPixelTexGenSGIX_, glPixelTexGenSGIX);
#endif //GL_SGIX_pixel_texture

// GL_SGIX_pixel_tiles

#ifndef GL_SGIX_polynomial_ffd
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_polynomial_ffd\n");
GL_GetFunc( PFN_GLDEFORMATIONMAP3DSGIX_PROC, _glDeformationMap3dSGIX_, glDeformationMap3dSGIX);
GL_GetFunc( PFN_GLDEFORMATIONMAP3FSGIX_PROC, _glDeformationMap3fSGIX_, glDeformationMap3fSGIX);
GL_GetFunc( PFN_GLDEFORMSGIX_PROC, _glDeformSGIX_, glDeformSGIX);
GL_GetFunc( PFN_GLLOADIDENTITYDEFORMATIONMAPSGIX_PROC, _glLoadIdentityDeformationMapSGIX_, glLoadIdentityDeformationMapSGIX);
#endif //GL_SGIX_polynomial_ffd

#ifndef GL_SGIX_reference_plane
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_reference_plane\n");
GL_GetFunc( PFN_GLREFERENCEPLANESGIX_PROC, _glReferencePlaneSGIX_, glReferencePlaneSGIX);
#endif //GL_SGIX_reference_plane

// GL_SGIX_resample

// GL_SGIX_scalebias_hint

// GL_SGIX_shadow

// GL_SGIX_shadow_ambient

#ifndef GL_SGIX_sprite
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_sprite\n");
GL_GetFunc( PFN_GLSPRITEPARAMETERFSGIX_PROC, _glSpriteParameterfSGIX_, glSpriteParameterfSGIX);
GL_GetFunc( PFN_GLSPRITEPARAMETERFVSGIX_PROC, _glSpriteParameterfvSGIX_, glSpriteParameterfvSGIX);
GL_GetFunc( PFN_GLSPRITEPARAMETERISGIX_PROC, _glSpriteParameteriSGIX_, glSpriteParameteriSGIX);
GL_GetFunc( PFN_GLSPRITEPARAMETERIVSGIX_PROC, _glSpriteParameterivSGIX_, glSpriteParameterivSGIX);
#endif //GL_SGIX_sprite

// GL_SGIX_subsample

#ifndef GL_SGIX_tag_sample_buffer
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGIX_tag_sample_buffer\n");
GL_GetFunc( PFN_GLTAGSAMPLEBUFFERSGIX_PROC, _glTagSampleBufferSGIX_, glTagSampleBufferSGIX);
#endif //GL_SGIX_tag_sample_buffer

// GL_SGIX_texture_add_env

// GL_SGIX_texture_coordinate_clamp

// GL_SGIX_texture_lod_bias

// GL_SGIX_texture_multi_buffer

// GL_SGIX_texture_scale_bias

// GL_SGIX_vertex_preclip

// GL_SGIX_ycrcb

// GL_SGIX_ycrcb_subsample

// GL_SGIX_ycrcba

// GL_SGI_color_matrix

#ifndef GL_SGI_color_table
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SGI_color_table\n");
GL_GetFunc( PFN_GLCOLORTABLESGI_PROC, _glColorTableSGI_, glColorTableSGI);
GL_GetFunc( PFN_GLCOLORTABLEPARAMETERFVSGI_PROC, _glColorTableParameterfvSGI_, glColorTableParameterfvSGI);
GL_GetFunc( PFN_GLCOLORTABLEPARAMETERIVSGI_PROC, _glColorTableParameterivSGI_, glColorTableParameterivSGI);
GL_GetFunc( PFN_GLCOPYCOLORTABLESGI_PROC, _glCopyColorTableSGI_, glCopyColorTableSGI);
GL_GetFunc( PFN_GLGETCOLORTABLESGI_PROC, _glGetColorTableSGI_, glGetColorTableSGI);
GL_GetFunc( PFN_GLGETCOLORTABLEPARAMETERFVSGI_PROC, _glGetColorTableParameterfvSGI_, glGetColorTableParameterfvSGI);
GL_GetFunc( PFN_GLGETCOLORTABLEPARAMETERIVSGI_PROC, _glGetColorTableParameterivSGI_, glGetColorTableParameterivSGI);
#endif //GL_SGI_color_table

// GL_SGI_texture_color_table

#ifndef GL_SUNX_constant_data
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SUNX_constant_data\n");
GL_GetFunc( PFN_GLFINISHTEXTURESUNX_PROC, _glFinishTextureSUNX_, glFinishTextureSUNX);
#endif //GL_SUNX_constant_data

// GL_SUN_convolution_border_modes

#ifndef GL_SUN_global_alpha
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SUN_global_alpha\n");
GL_GetFunc( PFN_GLGLOBALALPHAFACTORBSUN_PROC, _glGlobalAlphaFactorbSUN_, glGlobalAlphaFactorbSUN);
GL_GetFunc( PFN_GLGLOBALALPHAFACTORSSUN_PROC, _glGlobalAlphaFactorsSUN_, glGlobalAlphaFactorsSUN);
GL_GetFunc( PFN_GLGLOBALALPHAFACTORISUN_PROC, _glGlobalAlphaFactoriSUN_, glGlobalAlphaFactoriSUN);
GL_GetFunc( PFN_GLGLOBALALPHAFACTORFSUN_PROC, _glGlobalAlphaFactorfSUN_, glGlobalAlphaFactorfSUN);
GL_GetFunc( PFN_GLGLOBALALPHAFACTORDSUN_PROC, _glGlobalAlphaFactordSUN_, glGlobalAlphaFactordSUN);
GL_GetFunc( PFN_GLGLOBALALPHAFACTORUBSUN_PROC, _glGlobalAlphaFactorubSUN_, glGlobalAlphaFactorubSUN);
GL_GetFunc( PFN_GLGLOBALALPHAFACTORUSSUN_PROC, _glGlobalAlphaFactorusSUN_, glGlobalAlphaFactorusSUN);
GL_GetFunc( PFN_GLGLOBALALPHAFACTORUISUN_PROC, _glGlobalAlphaFactoruiSUN_, glGlobalAlphaFactoruiSUN);
#endif //GL_SUN_global_alpha

#ifndef GL_SUN_mesh_array
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SUN_mesh_array\n");
GL_GetFunc( PFN_GLDRAWMESHARRAYSSUN_PROC, _glDrawMeshArraysSUN_, glDrawMeshArraysSUN);
#endif //GL_SUN_mesh_array

// GL_SUN_slice_accum

#ifndef GL_SUN_triangle_list
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SUN_triangle_list\n");
GL_GetFunc( PFN_GLREPLACEMENTCODEUISUN_PROC, _glReplacementCodeuiSUN_, glReplacementCodeuiSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUSSUN_PROC, _glReplacementCodeusSUN_, glReplacementCodeusSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUBSUN_PROC, _glReplacementCodeubSUN_, glReplacementCodeubSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUIVSUN_PROC, _glReplacementCodeuivSUN_, glReplacementCodeuivSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUSVSUN_PROC, _glReplacementCodeusvSUN_, glReplacementCodeusvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUBVSUN_PROC, _glReplacementCodeubvSUN_, glReplacementCodeubvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEPOINTERSUN_PROC, _glReplacementCodePointerSUN_, glReplacementCodePointerSUN);
#endif //GL_SUN_triangle_list

#ifndef GL_SUN_vertex
LOG_fprintf(LogGlGetFunctions_py, "\nGL_SUN_vertex\n");
GL_GetFunc( PFN_GLCOLOR4UBVERTEX2FSUN_PROC, _glColor4ubVertex2fSUN_, glColor4ubVertex2fSUN);
GL_GetFunc( PFN_GLCOLOR4UBVERTEX2FVSUN_PROC, _glColor4ubVertex2fvSUN_, glColor4ubVertex2fvSUN);
GL_GetFunc( PFN_GLCOLOR4UBVERTEX3FSUN_PROC, _glColor4ubVertex3fSUN_, glColor4ubVertex3fSUN);
GL_GetFunc( PFN_GLCOLOR4UBVERTEX3FVSUN_PROC, _glColor4ubVertex3fvSUN_, glColor4ubVertex3fvSUN);
GL_GetFunc( PFN_GLCOLOR3FVERTEX3FSUN_PROC, _glColor3fVertex3fSUN_, glColor3fVertex3fSUN);
GL_GetFunc( PFN_GLCOLOR3FVERTEX3FVSUN_PROC, _glColor3fVertex3fvSUN_, glColor3fVertex3fvSUN);
GL_GetFunc( PFN_GLNORMAL3FVERTEX3FSUN_PROC, _glNormal3fVertex3fSUN_, glNormal3fVertex3fSUN);
GL_GetFunc( PFN_GLNORMAL3FVERTEX3FVSUN_PROC, _glNormal3fVertex3fvSUN_, glNormal3fVertex3fvSUN);
GL_GetFunc( PFN_GLCOLOR4FNORMAL3FVERTEX3FSUN_PROC, _glColor4fNormal3fVertex3fSUN_, glColor4fNormal3fVertex3fSUN);
GL_GetFunc( PFN_GLCOLOR4FNORMAL3FVERTEX3FVSUN_PROC, _glColor4fNormal3fVertex3fvSUN_, glColor4fNormal3fVertex3fvSUN);
GL_GetFunc( PFN_GLTEXCOORD2FVERTEX3FSUN_PROC, _glTexCoord2fVertex3fSUN_, glTexCoord2fVertex3fSUN);
GL_GetFunc( PFN_GLTEXCOORD2FVERTEX3FVSUN_PROC, _glTexCoord2fVertex3fvSUN_, glTexCoord2fVertex3fvSUN);
GL_GetFunc( PFN_GLTEXCOORD4FVERTEX4FSUN_PROC, _glTexCoord4fVertex4fSUN_, glTexCoord4fVertex4fSUN);
GL_GetFunc( PFN_GLTEXCOORD4FVERTEX4FVSUN_PROC, _glTexCoord4fVertex4fvSUN_, glTexCoord4fVertex4fvSUN);
GL_GetFunc( PFN_GLTEXCOORD2FCOLOR4UBVERTEX3FSUN_PROC, _glTexCoord2fColor4ubVertex3fSUN_, glTexCoord2fColor4ubVertex3fSUN);
GL_GetFunc( PFN_GLTEXCOORD2FCOLOR4UBVERTEX3FVSUN_PROC, _glTexCoord2fColor4ubVertex3fvSUN_, glTexCoord2fColor4ubVertex3fvSUN);
GL_GetFunc( PFN_GLTEXCOORD2FCOLOR3FVERTEX3FSUN_PROC, _glTexCoord2fColor3fVertex3fSUN_, glTexCoord2fColor3fVertex3fSUN);
GL_GetFunc( PFN_GLTEXCOORD2FCOLOR3FVERTEX3FVSUN_PROC, _glTexCoord2fColor3fVertex3fvSUN_, glTexCoord2fColor3fVertex3fvSUN);
GL_GetFunc( PFN_GLTEXCOORD2FNORMAL3FVERTEX3FSUN_PROC, _glTexCoord2fNormal3fVertex3fSUN_, glTexCoord2fNormal3fVertex3fSUN);
GL_GetFunc( PFN_GLTEXCOORD2FNORMAL3FVERTEX3FVSUN_PROC, _glTexCoord2fNormal3fVertex3fvSUN_, glTexCoord2fNormal3fVertex3fvSUN);
GL_GetFunc( PFN_GLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUN_PROC, _glTexCoord2fColor4fNormal3fVertex3fSUN_, glTexCoord2fColor4fNormal3fVertex3fSUN);
GL_GetFunc( PFN_GLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUN_PROC, _glTexCoord2fColor4fNormal3fVertex3fvSUN_, glTexCoord2fColor4fNormal3fVertex3fvSUN);
GL_GetFunc( PFN_GLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUN_PROC, _glTexCoord4fColor4fNormal3fVertex4fSUN_, glTexCoord4fColor4fNormal3fVertex4fSUN);
GL_GetFunc( PFN_GLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUN_PROC, _glTexCoord4fColor4fNormal3fVertex4fvSUN_, glTexCoord4fColor4fNormal3fVertex4fvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUIVERTEX3FSUN_PROC, _glReplacementCodeuiVertex3fSUN_, glReplacementCodeuiVertex3fSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUIVERTEX3FVSUN_PROC, _glReplacementCodeuiVertex3fvSUN_, glReplacementCodeuiVertex3fvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUN_PROC, _glReplacementCodeuiColor4ubVertex3fSUN_, glReplacementCodeuiColor4ubVertex3fSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUN_PROC, _glReplacementCodeuiColor4ubVertex3fvSUN_, glReplacementCodeuiColor4ubVertex3fvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUICOLOR3FVERTEX3FSUN_PROC, _glReplacementCodeuiColor3fVertex3fSUN_, glReplacementCodeuiColor3fVertex3fSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUN_PROC, _glReplacementCodeuiColor3fVertex3fvSUN_, glReplacementCodeuiColor3fVertex3fvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUINORMAL3FVERTEX3FSUN_PROC, _glReplacementCodeuiNormal3fVertex3fSUN_, glReplacementCodeuiNormal3fVertex3fSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUN_PROC, _glReplacementCodeuiNormal3fVertex3fvSUN_, glReplacementCodeuiNormal3fVertex3fvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUN_PROC, _glReplacementCodeuiColor4fNormal3fVertex3fSUN_, glReplacementCodeuiColor4fNormal3fVertex3fSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUN_PROC, _glReplacementCodeuiColor4fNormal3fVertex3fvSUN_, glReplacementCodeuiColor4fNormal3fVertex3fvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUN_PROC, _glReplacementCodeuiTexCoord2fVertex3fSUN_, glReplacementCodeuiTexCoord2fVertex3fSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUN_PROC, _glReplacementCodeuiTexCoord2fVertex3fvSUN_, glReplacementCodeuiTexCoord2fVertex3fvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUN_PROC, _glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN_, glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUN_PROC, _glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN_, glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUN_PROC, _glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN_, glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN);
GL_GetFunc( PFN_GLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUN_PROC, _glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN_, glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN);
#endif //GL_SUN_vertex

// GL_WIN_phong_shading

// GL_WIN_specular_fog

