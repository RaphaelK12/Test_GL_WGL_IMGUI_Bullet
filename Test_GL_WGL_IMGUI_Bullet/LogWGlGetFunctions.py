
WGL_VERSION_1_0
	00000000 : DescribePixelFormat
	00000000 : GetEnhMetaFilePixelFormat
	7A7C8150 : wglDescribeLayerPlane
	7A7C8280 : wglGetLayerPaletteEntries

WGL_ARB_buffer_region
	03815EC0 : wglCreateBufferRegionARB
	03815FB0 : wglDeleteBufferRegionARB
	03816040 : wglSaveBufferRegionARB
	038160D0 : wglRestoreBufferRegionARB

WGL_ARB_create_context
	03816990 : wglCreateContextAttribsARB

WGL_ARB_extensions_string
	03811320 : wglGetExtensionsStringARB

WGL_ARB_make_current_read
	03816160 : wglMakeContextCurrentARB
	03816540 : wglGetCurrentReadDCARB

WGL_ARB_pbuffer
	03814F50 : wglCreatePbufferARB
	03815480 : wglGetPbufferDCARB
	038154E0 : wglReleasePbufferDCARB
	03815560 : wglDestroyPbufferARB
	03815680 : wglQueryPbufferARB

WGL_ARB_pixel_format
	03813C30 : wglGetPixelFormatAttribivARB
	03814650 : wglGetPixelFormatAttribfvARB
	03814800 : wglChoosePixelFormatARB

WGL_ARB_render_texture
	03815CE0 : wglBindTexImageARB
	03815DD0 : wglReleaseTexImageARB
	03815AF0 : wglSetPbufferAttribARB

WGL_AMD_gpu_association
	03811690 : wglGetGPUIDsAMD
	03811740 : wglGetGPUInfoAMD
	03812290 : wglGetContextGPUIDAMD
	03811A00 : wglCreateAssociatedContextAMD
	03811BF0 : wglCreateAssociatedContextAttribsAMD
	03812090 : wglDeleteAssociatedContextAMD
	03811EC0 : wglMakeAssociatedContextCurrentAMD
	03812320 : wglGetCurrentAssociatedContextAMD
	03812470 : wglBlitContextFramebufferAMD

WGL_EXT_extensions_string
	03811330 : wglGetExtensionsStringEXT

WGL_EXT_swap_control
	03811340 : wglSwapIntervalEXT
	03811620 : wglGetSwapIntervalEXT

WGL_I3D_genlock
	03812900 : wglEnableGenlockI3D
	03812950 : wglDisableGenlockI3D
	03812A50 : wglIsEnabledGenlockI3D
	03812AC0 : wglGenlockSourceI3D
	03812CF0 : wglGetGenlockSourceI3D
	03812ED0 : wglGenlockSourceEdgeI3D
	03813090 : wglGetGenlockSourceEdgeI3D
	038131A0 : wglGenlockSampleRateI3D
	03813350 : wglGetGenlockSampleRateI3D
	03813430 : wglGenlockSourceDelayI3D
	03813710 : wglGetGenlockSourceDelayI3D
	038138F0 : wglQueryGenlockMaxSourceDelayI3D

WGL_NV_DX_interop
	03817600 : wglDXSetResourceShareHandleNV
	03817660 : wglDXOpenDeviceNV
	038176D0 : wglDXCloseDeviceNV
	03817720 : wglDXRegisterObjectNV
	03817790 : wglDXUnregisterObjectNV
	038177F0 : wglDXObjectAccessNV
	03817850 : wglDXLockObjectsNV
	038178B0 : wglDXUnlockObjectsNV

WGL_NV_swap_group
	03813A00 : wglJoinSwapGroupNV
	03813A60 : wglBindSwapBarrierNV
	03813AB0 : wglQuerySwapGroupNV
	03813B10 : wglQueryMaxSwapGroupsNV
	03813B30 : wglQueryFrameCountNV
	03813BB0 : wglResetFrameCountNV
