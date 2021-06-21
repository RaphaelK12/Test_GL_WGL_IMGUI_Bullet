
WGL_VERSION_1_0
	00000000 : DescribePixelFormat
	00000000 : GetEnhMetaFilePixelFormat
	57FAAEE0 : wglDescribeLayerPlane
	57FAB010 : wglGetLayerPaletteEntries

WGL_ARB_buffer_region
	56245EC0 : wglCreateBufferRegionARB
	56245FB0 : wglDeleteBufferRegionARB
	56246040 : wglSaveBufferRegionARB
	562460D0 : wglRestoreBufferRegionARB

WGL_ARB_create_context
	56246990 : wglCreateContextAttribsARB

WGL_ARB_extensions_string
	56241320 : wglGetExtensionsStringARB

WGL_ARB_make_current_read
	56246160 : wglMakeContextCurrentARB
	56246540 : wglGetCurrentReadDCARB

WGL_ARB_pbuffer
	56244F50 : wglCreatePbufferARB
	56245480 : wglGetPbufferDCARB
	562454E0 : wglReleasePbufferDCARB
	56245560 : wglDestroyPbufferARB
	56245680 : wglQueryPbufferARB

WGL_ARB_pixel_format
	56243C30 : wglGetPixelFormatAttribivARB
	56244650 : wglGetPixelFormatAttribfvARB
	56244800 : wglChoosePixelFormatARB

WGL_ARB_render_texture
	56245CE0 : wglBindTexImageARB
	56245DD0 : wglReleaseTexImageARB
	56245AF0 : wglSetPbufferAttribARB

WGL_AMD_gpu_association
	56241690 : wglGetGPUIDsAMD
	56241740 : wglGetGPUInfoAMD
	56242290 : wglGetContextGPUIDAMD
	56241A00 : wglCreateAssociatedContextAMD
	56241BF0 : wglCreateAssociatedContextAttribsAMD
	56242090 : wglDeleteAssociatedContextAMD
	56241EC0 : wglMakeAssociatedContextCurrentAMD
	56242320 : wglGetCurrentAssociatedContextAMD
	56242470 : wglBlitContextFramebufferAMD

WGL_EXT_extensions_string
	56241330 : wglGetExtensionsStringEXT

WGL_EXT_swap_control
	56241340 : wglSwapIntervalEXT
	56241620 : wglGetSwapIntervalEXT

WGL_I3D_genlock
	56242900 : wglEnableGenlockI3D
	56242950 : wglDisableGenlockI3D
	56242A50 : wglIsEnabledGenlockI3D
	56242AC0 : wglGenlockSourceI3D
	56242CF0 : wglGetGenlockSourceI3D
	56242ED0 : wglGenlockSourceEdgeI3D
	56243090 : wglGetGenlockSourceEdgeI3D
	562431A0 : wglGenlockSampleRateI3D
	56243350 : wglGetGenlockSampleRateI3D
	56243430 : wglGenlockSourceDelayI3D
	56243710 : wglGetGenlockSourceDelayI3D
	562438F0 : wglQueryGenlockMaxSourceDelayI3D

WGL_NV_DX_interop
	56247600 : wglDXSetResourceShareHandleNV
	56247660 : wglDXOpenDeviceNV
	562476D0 : wglDXCloseDeviceNV
	56247720 : wglDXRegisterObjectNV
	56247790 : wglDXUnregisterObjectNV
	562477F0 : wglDXObjectAccessNV
	56247850 : wglDXLockObjectsNV
	562478B0 : wglDXUnlockObjectsNV

WGL_NV_swap_group
	56243A00 : wglJoinSwapGroupNV
	56243A60 : wglBindSwapBarrierNV
	56243AB0 : wglQuerySwapGroupNV
	56243B10 : wglQueryMaxSwapGroupsNV
	56243B30 : wglQueryFrameCountNV
	56243BB0 : wglResetFrameCountNV
