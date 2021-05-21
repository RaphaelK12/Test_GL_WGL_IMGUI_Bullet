
WGL_VERSION_1_0
	00000000 : DescribePixelFormat
	00000000 : GetEnhMetaFilePixelFormat
	77F28150 : wglDescribeLayerPlane
	77F28280 : wglGetLayerPaletteEntries

WGL_ARB_buffer_region
	7A805EC0 : wglCreateBufferRegionARB
	7A805FB0 : wglDeleteBufferRegionARB
	7A806040 : wglSaveBufferRegionARB
	7A8060D0 : wglRestoreBufferRegionARB

WGL_ARB_create_context
	7A806990 : wglCreateContextAttribsARB

WGL_ARB_extensions_string
	7A801320 : wglGetExtensionsStringARB

WGL_ARB_make_current_read
	7A806160 : wglMakeContextCurrentARB
	7A806540 : wglGetCurrentReadDCARB

WGL_ARB_pbuffer
	7A804F50 : wglCreatePbufferARB
	7A805480 : wglGetPbufferDCARB
	7A8054E0 : wglReleasePbufferDCARB
	7A805560 : wglDestroyPbufferARB
	7A805680 : wglQueryPbufferARB

WGL_ARB_pixel_format
	7A803C30 : wglGetPixelFormatAttribivARB
	7A804650 : wglGetPixelFormatAttribfvARB
	7A804800 : wglChoosePixelFormatARB

WGL_ARB_render_texture
	7A805CE0 : wglBindTexImageARB
	7A805DD0 : wglReleaseTexImageARB
	7A805AF0 : wglSetPbufferAttribARB

WGL_AMD_gpu_association
	7A801690 : wglGetGPUIDsAMD
	7A801740 : wglGetGPUInfoAMD
	7A802290 : wglGetContextGPUIDAMD
	7A801A00 : wglCreateAssociatedContextAMD
	7A801BF0 : wglCreateAssociatedContextAttribsAMD
	7A802090 : wglDeleteAssociatedContextAMD
	7A801EC0 : wglMakeAssociatedContextCurrentAMD
	7A802320 : wglGetCurrentAssociatedContextAMD
	7A802470 : wglBlitContextFramebufferAMD

WGL_EXT_extensions_string
	7A801330 : wglGetExtensionsStringEXT

WGL_EXT_swap_control
	7A801340 : wglSwapIntervalEXT
	7A801620 : wglGetSwapIntervalEXT

WGL_I3D_genlock
	7A802900 : wglEnableGenlockI3D
	7A802950 : wglDisableGenlockI3D
	7A802A50 : wglIsEnabledGenlockI3D
	7A802AC0 : wglGenlockSourceI3D
	7A802CF0 : wglGetGenlockSourceI3D
	7A802ED0 : wglGenlockSourceEdgeI3D
	7A803090 : wglGetGenlockSourceEdgeI3D
	7A8031A0 : wglGenlockSampleRateI3D
	7A803350 : wglGetGenlockSampleRateI3D
	7A803430 : wglGenlockSourceDelayI3D
	7A803710 : wglGetGenlockSourceDelayI3D
	7A8038F0 : wglQueryGenlockMaxSourceDelayI3D

WGL_NV_DX_interop
	7A807600 : wglDXSetResourceShareHandleNV
	7A807660 : wglDXOpenDeviceNV
	7A8076D0 : wglDXCloseDeviceNV
	7A807720 : wglDXRegisterObjectNV
	7A807790 : wglDXUnregisterObjectNV
	7A8077F0 : wglDXObjectAccessNV
	7A807850 : wglDXLockObjectsNV
	7A8078B0 : wglDXUnlockObjectsNV

WGL_NV_swap_group
	7A803A00 : wglJoinSwapGroupNV
	7A803A60 : wglBindSwapBarrierNV
	7A803AB0 : wglQuerySwapGroupNV
	7A803B10 : wglQueryMaxSwapGroupsNV
	7A803B30 : wglQueryFrameCountNV
	7A803BB0 : wglResetFrameCountNV
