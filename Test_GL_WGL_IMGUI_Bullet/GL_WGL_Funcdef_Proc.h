// Globals
#ifndef WGL_VERSION_1_0
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_VERSION_1_0\n");
WGL_GetFunc( PFN_DESCRIBEPIXELFORMAT_PROC, _DescribePixelFormat_, DescribePixelFormat);
WGL_GetFunc( PFN_GETENHMETAFILEPIXELFORMAT_PROC, _GetEnhMetaFilePixelFormat_, GetEnhMetaFilePixelFormat);
WGL_GetFunc( PFN_WGLDESCRIBELAYERPLANE_PROC, _wglDescribeLayerPlane_, wglDescribeLayerPlane);
WGL_GetFunc( PFN_WGLGETLAYERPALETTEENTRIES_PROC, _wglGetLayerPaletteEntries_, wglGetLayerPaletteEntries);
#endif //WGL_VERSION_1_0

#ifndef WGL_ARB_buffer_region
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_buffer_region\n");
WGL_GetFunc( PFN_WGLCREATEBUFFERREGIONARB_PROC, _wglCreateBufferRegionARB_, wglCreateBufferRegionARB);
WGL_GetFunc( PFN_WGLDELETEBUFFERREGIONARB_PROC, _wglDeleteBufferRegionARB_, wglDeleteBufferRegionARB);
WGL_GetFunc( PFN_WGLSAVEBUFFERREGIONARB_PROC, _wglSaveBufferRegionARB_, wglSaveBufferRegionARB);
WGL_GetFunc( PFN_WGLRESTOREBUFFERREGIONARB_PROC, _wglRestoreBufferRegionARB_, wglRestoreBufferRegionARB);
#endif //WGL_ARB_buffer_region

// WGL_ARB_context_flush_control

#ifndef WGL_ARB_create_context
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_create_context\n");
WGL_GetFunc( PFN_WGLCREATECONTEXTATTRIBSARB_PROC, _wglCreateContextAttribsARB_, wglCreateContextAttribsARB);
#endif //WGL_ARB_create_context

// WGL_ARB_create_context_no_error

// WGL_ARB_create_context_profile

// WGL_ARB_create_context_robustness

#ifndef WGL_ARB_extensions_string
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_extensions_string\n");
WGL_GetFunc( PFN_WGLGETEXTENSIONSSTRINGARB_PROC, _wglGetExtensionsStringARB_, wglGetExtensionsStringARB);
#endif //WGL_ARB_extensions_string

// WGL_ARB_framebuffer_sRGB

#ifndef WGL_ARB_make_current_read
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_make_current_read\n");
WGL_GetFunc( PFN_WGLMAKECONTEXTCURRENTARB_PROC, _wglMakeContextCurrentARB_, wglMakeContextCurrentARB);
WGL_GetFunc( PFN_WGLGETCURRENTREADDCARB_PROC, _wglGetCurrentReadDCARB_, wglGetCurrentReadDCARB);
#endif //WGL_ARB_make_current_read

// WGL_ARB_multisample

#ifndef WGL_ARB_pbuffer
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_pbuffer\n");
WGL_GetFunc( PFN_WGLCREATEPBUFFERARB_PROC, _wglCreatePbufferARB_, wglCreatePbufferARB);
WGL_GetFunc( PFN_WGLGETPBUFFERDCARB_PROC, _wglGetPbufferDCARB_, wglGetPbufferDCARB);
WGL_GetFunc( PFN_WGLRELEASEPBUFFERDCARB_PROC, _wglReleasePbufferDCARB_, wglReleasePbufferDCARB);
WGL_GetFunc( PFN_WGLDESTROYPBUFFERARB_PROC, _wglDestroyPbufferARB_, wglDestroyPbufferARB);
WGL_GetFunc( PFN_WGLQUERYPBUFFERARB_PROC, _wglQueryPbufferARB_, wglQueryPbufferARB);
#endif //WGL_ARB_pbuffer

#ifndef WGL_ARB_pixel_format
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_pixel_format\n");
WGL_GetFunc( PFN_WGLGETPIXELFORMATATTRIBIVARB_PROC, _wglGetPixelFormatAttribivARB_, wglGetPixelFormatAttribivARB);
WGL_GetFunc( PFN_WGLGETPIXELFORMATATTRIBFVARB_PROC, _wglGetPixelFormatAttribfvARB_, wglGetPixelFormatAttribfvARB);
WGL_GetFunc( PFN_WGLCHOOSEPIXELFORMATARB_PROC, _wglChoosePixelFormatARB_, wglChoosePixelFormatARB);
#endif //WGL_ARB_pixel_format

// WGL_ARB_pixel_format_float

#ifndef WGL_ARB_render_texture
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_render_texture\n");
WGL_GetFunc( PFN_WGLBINDTEXIMAGEARB_PROC, _wglBindTexImageARB_, wglBindTexImageARB);
WGL_GetFunc( PFN_WGLRELEASETEXIMAGEARB_PROC, _wglReleaseTexImageARB_, wglReleaseTexImageARB);
WGL_GetFunc( PFN_WGLSETPBUFFERATTRIBARB_PROC, _wglSetPbufferAttribARB_, wglSetPbufferAttribARB);
#endif //WGL_ARB_render_texture

// WGL_ARB_robustness_application_isolation

// WGL_ARB_robustness_share_group_isolation

// WGL_3DFX_multisample

#ifndef WGL_3DL_stereo_control
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_3DL_stereo_control\n");
WGL_GetFunc( PFN_WGLSETSTEREOEMITTERSTATE3DL_PROC, _wglSetStereoEmitterState3DL_, wglSetStereoEmitterState3DL);
#endif //WGL_3DL_stereo_control

#ifndef WGL_AMD_gpu_association
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_AMD_gpu_association\n");
WGL_GetFunc( PFN_WGLGETGPUIDSAMD_PROC, _wglGetGPUIDsAMD_, wglGetGPUIDsAMD);
WGL_GetFunc( PFN_WGLGETGPUINFOAMD_PROC, _wglGetGPUInfoAMD_, wglGetGPUInfoAMD);
WGL_GetFunc( PFN_WGLGETCONTEXTGPUIDAMD_PROC, _wglGetContextGPUIDAMD_, wglGetContextGPUIDAMD);
WGL_GetFunc( PFN_WGLCREATEASSOCIATEDCONTEXTAMD_PROC, _wglCreateAssociatedContextAMD_, wglCreateAssociatedContextAMD);
WGL_GetFunc( PFN_WGLCREATEASSOCIATEDCONTEXTATTRIBSAMD_PROC, _wglCreateAssociatedContextAttribsAMD_, wglCreateAssociatedContextAttribsAMD);
WGL_GetFunc( PFN_WGLDELETEASSOCIATEDCONTEXTAMD_PROC, _wglDeleteAssociatedContextAMD_, wglDeleteAssociatedContextAMD);
WGL_GetFunc( PFN_WGLMAKEASSOCIATEDCONTEXTCURRENTAMD_PROC, _wglMakeAssociatedContextCurrentAMD_, wglMakeAssociatedContextCurrentAMD);
WGL_GetFunc( PFN_WGLGETCURRENTASSOCIATEDCONTEXTAMD_PROC, _wglGetCurrentAssociatedContextAMD_, wglGetCurrentAssociatedContextAMD);
WGL_GetFunc( PFN_WGLBLITCONTEXTFRAMEBUFFERAMD_PROC, _wglBlitContextFramebufferAMD_, wglBlitContextFramebufferAMD);
#endif //WGL_AMD_gpu_association

// WGL_ATI_pixel_format_float

// WGL_ATI_render_texture_rectangle

// WGL_EXT_colorspace

// WGL_EXT_create_context_es2_profile

// WGL_EXT_create_context_es_profile

// WGL_EXT_depth_float

#ifndef WGL_EXT_display_color_table
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_display_color_table\n");
WGL_GetFunc( PFN_WGLCREATEDISPLAYCOLORTABLEEXT_PROC, _wglCreateDisplayColorTableEXT_, wglCreateDisplayColorTableEXT);
WGL_GetFunc( PFN_WGLLOADDISPLAYCOLORTABLEEXT_PROC, _wglLoadDisplayColorTableEXT_, wglLoadDisplayColorTableEXT);
WGL_GetFunc( PFN_WGLBINDDISPLAYCOLORTABLEEXT_PROC, _wglBindDisplayColorTableEXT_, wglBindDisplayColorTableEXT);
WGL_GetFunc( PFN_WGLDESTROYDISPLAYCOLORTABLEEXT_PROC, _wglDestroyDisplayColorTableEXT_, wglDestroyDisplayColorTableEXT);
#endif //WGL_EXT_display_color_table

#ifndef WGL_EXT_extensions_string
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_extensions_string\n");
WGL_GetFunc( PFN_WGLGETEXTENSIONSSTRINGEXT_PROC, _wglGetExtensionsStringEXT_, wglGetExtensionsStringEXT);
#endif //WGL_EXT_extensions_string

// WGL_EXT_framebuffer_sRGB

#ifndef WGL_EXT_make_current_read
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_make_current_read\n");
WGL_GetFunc( PFN_WGLMAKECONTEXTCURRENTEXT_PROC, _wglMakeContextCurrentEXT_, wglMakeContextCurrentEXT);
WGL_GetFunc( PFN_WGLGETCURRENTREADDCEXT_PROC, _wglGetCurrentReadDCEXT_, wglGetCurrentReadDCEXT);
#endif //WGL_EXT_make_current_read

// WGL_EXT_multisample

#ifndef WGL_EXT_pbuffer
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_pbuffer\n");
WGL_GetFunc( PFN_WGLCREATEPBUFFEREXT_PROC, _wglCreatePbufferEXT_, wglCreatePbufferEXT);
WGL_GetFunc( PFN_WGLGETPBUFFERDCEXT_PROC, _wglGetPbufferDCEXT_, wglGetPbufferDCEXT);
WGL_GetFunc( PFN_WGLRELEASEPBUFFERDCEXT_PROC, _wglReleasePbufferDCEXT_, wglReleasePbufferDCEXT);
WGL_GetFunc( PFN_WGLDESTROYPBUFFEREXT_PROC, _wglDestroyPbufferEXT_, wglDestroyPbufferEXT);
WGL_GetFunc( PFN_WGLQUERYPBUFFEREXT_PROC, _wglQueryPbufferEXT_, wglQueryPbufferEXT);
#endif //WGL_EXT_pbuffer

#ifndef WGL_EXT_pixel_format
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_pixel_format\n");
WGL_GetFunc( PFN_WGLGETPIXELFORMATATTRIBIVEXT_PROC, _wglGetPixelFormatAttribivEXT_, wglGetPixelFormatAttribivEXT);
WGL_GetFunc( PFN_WGLGETPIXELFORMATATTRIBFVEXT_PROC, _wglGetPixelFormatAttribfvEXT_, wglGetPixelFormatAttribfvEXT);
WGL_GetFunc( PFN_WGLCHOOSEPIXELFORMATEXT_PROC, _wglChoosePixelFormatEXT_, wglChoosePixelFormatEXT);
#endif //WGL_EXT_pixel_format

// WGL_EXT_pixel_format_packed_float

#ifndef WGL_EXT_swap_control
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_swap_control\n");
WGL_GetFunc( PFN_WGLSWAPINTERVALEXT_PROC, _wglSwapIntervalEXT_, wglSwapIntervalEXT);
WGL_GetFunc( PFN_WGLGETSWAPINTERVALEXT_PROC, _wglGetSwapIntervalEXT_, wglGetSwapIntervalEXT);
#endif //WGL_EXT_swap_control

// WGL_EXT_swap_control_tear

#ifndef WGL_I3D_digital_video_control
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_digital_video_control\n");
WGL_GetFunc( PFN_WGLGETDIGITALVIDEOPARAMETERSI3D_PROC, _wglGetDigitalVideoParametersI3D_, wglGetDigitalVideoParametersI3D);
WGL_GetFunc( PFN_WGLSETDIGITALVIDEOPARAMETERSI3D_PROC, _wglSetDigitalVideoParametersI3D_, wglSetDigitalVideoParametersI3D);
#endif //WGL_I3D_digital_video_control

#ifndef WGL_I3D_gamma
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_gamma\n");
WGL_GetFunc( PFN_WGLGETGAMMATABLEPARAMETERSI3D_PROC, _wglGetGammaTableParametersI3D_, wglGetGammaTableParametersI3D);
WGL_GetFunc( PFN_WGLSETGAMMATABLEPARAMETERSI3D_PROC, _wglSetGammaTableParametersI3D_, wglSetGammaTableParametersI3D);
WGL_GetFunc( PFN_WGLGETGAMMATABLEI3D_PROC, _wglGetGammaTableI3D_, wglGetGammaTableI3D);
WGL_GetFunc( PFN_WGLSETGAMMATABLEI3D_PROC, _wglSetGammaTableI3D_, wglSetGammaTableI3D);
#endif //WGL_I3D_gamma

#ifndef WGL_I3D_genlock
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_genlock\n");
WGL_GetFunc( PFN_WGLENABLEGENLOCKI3D_PROC, _wglEnableGenlockI3D_, wglEnableGenlockI3D);
WGL_GetFunc( PFN_WGLDISABLEGENLOCKI3D_PROC, _wglDisableGenlockI3D_, wglDisableGenlockI3D);
WGL_GetFunc( PFN_WGLISENABLEDGENLOCKI3D_PROC, _wglIsEnabledGenlockI3D_, wglIsEnabledGenlockI3D);
WGL_GetFunc( PFN_WGLGENLOCKSOURCEI3D_PROC, _wglGenlockSourceI3D_, wglGenlockSourceI3D);
WGL_GetFunc( PFN_WGLGETGENLOCKSOURCEI3D_PROC, _wglGetGenlockSourceI3D_, wglGetGenlockSourceI3D);
WGL_GetFunc( PFN_WGLGENLOCKSOURCEEDGEI3D_PROC, _wglGenlockSourceEdgeI3D_, wglGenlockSourceEdgeI3D);
WGL_GetFunc( PFN_WGLGETGENLOCKSOURCEEDGEI3D_PROC, _wglGetGenlockSourceEdgeI3D_, wglGetGenlockSourceEdgeI3D);
WGL_GetFunc( PFN_WGLGENLOCKSAMPLERATEI3D_PROC, _wglGenlockSampleRateI3D_, wglGenlockSampleRateI3D);
WGL_GetFunc( PFN_WGLGETGENLOCKSAMPLERATEI3D_PROC, _wglGetGenlockSampleRateI3D_, wglGetGenlockSampleRateI3D);
WGL_GetFunc( PFN_WGLGENLOCKSOURCEDELAYI3D_PROC, _wglGenlockSourceDelayI3D_, wglGenlockSourceDelayI3D);
WGL_GetFunc( PFN_WGLGETGENLOCKSOURCEDELAYI3D_PROC, _wglGetGenlockSourceDelayI3D_, wglGetGenlockSourceDelayI3D);
WGL_GetFunc( PFN_WGLQUERYGENLOCKMAXSOURCEDELAYI3D_PROC, _wglQueryGenlockMaxSourceDelayI3D_, wglQueryGenlockMaxSourceDelayI3D);
#endif //WGL_I3D_genlock

#ifndef WGL_I3D_image_buffer
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_image_buffer\n");
WGL_GetFunc( PFN_WGLCREATEIMAGEBUFFERI3D_PROC, _wglCreateImageBufferI3D_, wglCreateImageBufferI3D);
WGL_GetFunc( PFN_WGLDESTROYIMAGEBUFFERI3D_PROC, _wglDestroyImageBufferI3D_, wglDestroyImageBufferI3D);
WGL_GetFunc( PFN_WGLASSOCIATEIMAGEBUFFEREVENTSI3D_PROC, _wglAssociateImageBufferEventsI3D_, wglAssociateImageBufferEventsI3D);
WGL_GetFunc( PFN_WGLRELEASEIMAGEBUFFEREVENTSI3D_PROC, _wglReleaseImageBufferEventsI3D_, wglReleaseImageBufferEventsI3D);
#endif //WGL_I3D_image_buffer

#ifndef WGL_I3D_swap_frame_lock
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_swap_frame_lock\n");
WGL_GetFunc( PFN_WGLENABLEFRAMELOCKI3D_PROC, _wglEnableFrameLockI3D_, wglEnableFrameLockI3D);
WGL_GetFunc( PFN_WGLDISABLEFRAMELOCKI3D_PROC, _wglDisableFrameLockI3D_, wglDisableFrameLockI3D);
WGL_GetFunc( PFN_WGLISENABLEDFRAMELOCKI3D_PROC, _wglIsEnabledFrameLockI3D_, wglIsEnabledFrameLockI3D);
WGL_GetFunc( PFN_WGLQUERYFRAMELOCKMASTERI3D_PROC, _wglQueryFrameLockMasterI3D_, wglQueryFrameLockMasterI3D);
#endif //WGL_I3D_swap_frame_lock

#ifndef WGL_I3D_swap_frame_usage
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_swap_frame_usage\n");
WGL_GetFunc( PFN_WGLGETFRAMEUSAGEI3D_PROC, _wglGetFrameUsageI3D_, wglGetFrameUsageI3D);
WGL_GetFunc( PFN_WGLBEGINFRAMETRACKINGI3D_PROC, _wglBeginFrameTrackingI3D_, wglBeginFrameTrackingI3D);
WGL_GetFunc( PFN_WGLENDFRAMETRACKINGI3D_PROC, _wglEndFrameTrackingI3D_, wglEndFrameTrackingI3D);
WGL_GetFunc( PFN_WGLQUERYFRAMETRACKINGI3D_PROC, _wglQueryFrameTrackingI3D_, wglQueryFrameTrackingI3D);
#endif //WGL_I3D_swap_frame_usage

#ifndef WGL_NV_DX_interop
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_NV_DX_interop\n");
WGL_GetFunc( PFN_WGLDXSETRESOURCESHAREHANDLENV_PROC, _wglDXSetResourceShareHandleNV_, wglDXSetResourceShareHandleNV);
WGL_GetFunc( PFN_WGLDXOPENDEVICENV_PROC, _wglDXOpenDeviceNV_, wglDXOpenDeviceNV);
WGL_GetFunc( PFN_WGLDXCLOSEDEVICENV_PROC, _wglDXCloseDeviceNV_, wglDXCloseDeviceNV);
WGL_GetFunc( PFN_WGLDXREGISTEROBJECTNV_PROC, _wglDXRegisterObjectNV_, wglDXRegisterObjectNV);
WGL_GetFunc( PFN_WGLDXUNREGISTEROBJECTNV_PROC, _wglDXUnregisterObjectNV_, wglDXUnregisterObjectNV);
WGL_GetFunc( PFN_WGLDXOBJECTACCESSNV_PROC, _wglDXObjectAccessNV_, wglDXObjectAccessNV);
WGL_GetFunc( PFN_WGLDXLOCKOBJECTSNV_PROC, _wglDXLockObjectsNV_, wglDXLockObjectsNV);
WGL_GetFunc( PFN_WGLDXUNLOCKOBJECTSNV_PROC, _wglDXUnlockObjectsNV_, wglDXUnlockObjectsNV);
#endif //WGL_NV_DX_interop

// WGL_NV_DX_interop2

#ifndef WGL_NV_copy_image
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_NV_copy_image\n");
WGL_GetFunc( PFN_WGLCOPYIMAGESUBDATANV_PROC, _wglCopyImageSubDataNV_, wglCopyImageSubDataNV);
#endif //WGL_NV_copy_image

#ifndef WGL_NV_delay_before_swap
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_NV_delay_before_swap\n");
WGL_GetFunc( PFN_WGLDELAYBEFORESWAPNV_PROC, _wglDelayBeforeSwapNV_, wglDelayBeforeSwapNV);
#endif //WGL_NV_delay_before_swap

// WGL_NV_float_buffer

#ifndef WGL_NV_gpu_affinity
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_NV_gpu_affinity\n");
WGL_GetFunc( PFN_WGLENUMGPUSNV_PROC, _wglEnumGpusNV_, wglEnumGpusNV);
WGL_GetFunc( PFN_WGLENUMGPUDEVICESNV_PROC, _wglEnumGpuDevicesNV_, wglEnumGpuDevicesNV);
WGL_GetFunc( PFN_WGLCREATEAFFINITYDCNV_PROC, _wglCreateAffinityDCNV_, wglCreateAffinityDCNV);
WGL_GetFunc( PFN_WGLENUMGPUSFROMAFFINITYDCNV_PROC, _wglEnumGpusFromAffinityDCNV_, wglEnumGpusFromAffinityDCNV);
WGL_GetFunc( PFN_WGLDELETEDCNV_PROC, _wglDeleteDCNV_, wglDeleteDCNV);
#endif //WGL_NV_gpu_affinity

// WGL_NV_multigpu_context

// WGL_NV_multisample_coverage

#ifndef WGL_NV_present_video
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_NV_present_video\n");
WGL_GetFunc( PFN_WGLENUMERATEVIDEODEVICESNV_PROC, _wglEnumerateVideoDevicesNV_, wglEnumerateVideoDevicesNV);
WGL_GetFunc( PFN_WGLBINDVIDEODEVICENV_PROC, _wglBindVideoDeviceNV_, wglBindVideoDeviceNV);
WGL_GetFunc( PFN_WGLQUERYCURRENTCONTEXTNV_PROC, _wglQueryCurrentContextNV_, wglQueryCurrentContextNV);
#endif //WGL_NV_present_video

// WGL_NV_render_depth_texture

// WGL_NV_render_texture_rectangle

#ifndef WGL_NV_swap_group
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_NV_swap_group\n");
WGL_GetFunc( PFN_WGLJOINSWAPGROUPNV_PROC, _wglJoinSwapGroupNV_, wglJoinSwapGroupNV);
WGL_GetFunc( PFN_WGLBINDSWAPBARRIERNV_PROC, _wglBindSwapBarrierNV_, wglBindSwapBarrierNV);
WGL_GetFunc( PFN_WGLQUERYSWAPGROUPNV_PROC, _wglQuerySwapGroupNV_, wglQuerySwapGroupNV);
WGL_GetFunc( PFN_WGLQUERYMAXSWAPGROUPSNV_PROC, _wglQueryMaxSwapGroupsNV_, wglQueryMaxSwapGroupsNV);
WGL_GetFunc( PFN_WGLQUERYFRAMECOUNTNV_PROC, _wglQueryFrameCountNV_, wglQueryFrameCountNV);
WGL_GetFunc( PFN_WGLRESETFRAMECOUNTNV_PROC, _wglResetFrameCountNV_, wglResetFrameCountNV);
#endif //WGL_NV_swap_group

#ifndef WGL_NV_vertex_array_range
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_NV_vertex_array_range\n");
WGL_GetFunc( PFN_WGLALLOCATEMEMORYNV_PROC, _wglAllocateMemoryNV_, wglAllocateMemoryNV);
WGL_GetFunc( PFN_WGLFREEMEMORYNV_PROC, _wglFreeMemoryNV_, wglFreeMemoryNV);
#endif //WGL_NV_vertex_array_range

#ifndef WGL_NV_video_capture
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_NV_video_capture\n");
WGL_GetFunc( PFN_WGLBINDVIDEOCAPTUREDEVICENV_PROC, _wglBindVideoCaptureDeviceNV_, wglBindVideoCaptureDeviceNV);
WGL_GetFunc( PFN_WGLENUMERATEVIDEOCAPTUREDEVICESNV_PROC, _wglEnumerateVideoCaptureDevicesNV_, wglEnumerateVideoCaptureDevicesNV);
WGL_GetFunc( PFN_WGLLOCKVIDEOCAPTUREDEVICENV_PROC, _wglLockVideoCaptureDeviceNV_, wglLockVideoCaptureDeviceNV);
WGL_GetFunc( PFN_WGLQUERYVIDEOCAPTUREDEVICENV_PROC, _wglQueryVideoCaptureDeviceNV_, wglQueryVideoCaptureDeviceNV);
WGL_GetFunc( PFN_WGLRELEASEVIDEOCAPTUREDEVICENV_PROC, _wglReleaseVideoCaptureDeviceNV_, wglReleaseVideoCaptureDeviceNV);
#endif //WGL_NV_video_capture

#ifndef WGL_NV_video_output
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_NV_video_output\n");
WGL_GetFunc( PFN_WGLGETVIDEODEVICENV_PROC, _wglGetVideoDeviceNV_, wglGetVideoDeviceNV);
WGL_GetFunc( PFN_WGLRELEASEVIDEODEVICENV_PROC, _wglReleaseVideoDeviceNV_, wglReleaseVideoDeviceNV);
WGL_GetFunc( PFN_WGLBINDVIDEOIMAGENV_PROC, _wglBindVideoImageNV_, wglBindVideoImageNV);
WGL_GetFunc( PFN_WGLRELEASEVIDEOIMAGENV_PROC, _wglReleaseVideoImageNV_, wglReleaseVideoImageNV);
WGL_GetFunc( PFN_WGLSENDPBUFFERTOVIDEONV_PROC, _wglSendPbufferToVideoNV_, wglSendPbufferToVideoNV);
WGL_GetFunc( PFN_WGLGETVIDEOINFONV_PROC, _wglGetVideoInfoNV_, wglGetVideoInfoNV);
#endif //WGL_NV_video_output

#ifndef WGL_OML_sync_control
LOG_fprintf(LogWGlGetFunctions_py, "\nWGL_OML_sync_control\n");
WGL_GetFunc( PFN_WGLGETSYNCVALUESOML_PROC, _wglGetSyncValuesOML_, wglGetSyncValuesOML);
WGL_GetFunc( PFN_WGLGETMSCRATEOML_PROC, _wglGetMscRateOML_, wglGetMscRateOML);
WGL_GetFunc( PFN_WGLSWAPBUFFERSMSCOML_PROC, _wglSwapBuffersMscOML_, wglSwapBuffersMscOML);
WGL_GetFunc( PFN_WGLSWAPLAYERBUFFERSMSCOML_PROC, _wglSwapLayerBuffersMscOML_, wglSwapLayerBuffersMscOML);
WGL_GetFunc( PFN_WGLWAITFORMSCOML_PROC, _wglWaitForMscOML_, wglWaitForMscOML);
WGL_GetFunc( PFN_WGLWAITFORSBCOML_PROC, _wglWaitForSbcOML_, wglWaitForSbcOML);
#endif //WGL_OML_sync_control

