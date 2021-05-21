// Globals

// Handles
DECLARE_HANDLE(HPBUFFERARB);
DECLARE_HANDLE(HPBUFFEREXT);
DECLARE_HANDLE(HGPUNV);
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
DECLARE_HANDLE(HPVIDEODEV);

// Typedefs
typedef struct _GPU_DEVICE * PGPU_DEVICE;

// Defines

#define WGL_WGLEXT_VERSION 20191029 
#ifndef WGL_VERSION_1_0

// Defines
#define WGL_FONT_LINES                    0 
#define WGL_FONT_POLYGONS                 1 
#define WGL_SWAP_MAIN_PLANE               0x00000001 
#define WGL_SWAP_OVERLAY1                 0x00000002 
#define WGL_SWAP_OVERLAY2                 0x00000004 
#define WGL_SWAP_OVERLAY3                 0x00000008 
#define WGL_SWAP_OVERLAY4                 0x00000010 
#define WGL_SWAP_OVERLAY5                 0x00000020 
#define WGL_SWAP_OVERLAY6                 0x00000040 
#define WGL_SWAP_OVERLAY7                 0x00000080 
#define WGL_SWAP_OVERLAY8                 0x00000100 
#define WGL_SWAP_OVERLAY9                 0x00000200 
#define WGL_SWAP_OVERLAY10                0x00000400 
#define WGL_SWAP_OVERLAY11                0x00000800 
#define WGL_SWAP_OVERLAY12                0x00001000 
#define WGL_SWAP_OVERLAY13                0x00002000 
#define WGL_SWAP_OVERLAY14                0x00004000 
#define WGL_SWAP_OVERLAY15                0x00008000 
#define WGL_SWAP_UNDERLAY1                0x00010000 
#define WGL_SWAP_UNDERLAY2                0x00020000 
#define WGL_SWAP_UNDERLAY3                0x00040000 
#define WGL_SWAP_UNDERLAY4                0x00080000 
#define WGL_SWAP_UNDERLAY5                0x00100000 
#define WGL_SWAP_UNDERLAY6                0x00200000 
#define WGL_SWAP_UNDERLAY7                0x00400000 
#define WGL_SWAP_UNDERLAY8                0x00800000 
#define WGL_SWAP_UNDERLAY9                0x01000000 
#define WGL_SWAP_UNDERLAY10               0x02000000 
#define WGL_SWAP_UNDERLAY11               0x04000000 
#define WGL_SWAP_UNDERLAY12               0x08000000 
#define WGL_SWAP_UNDERLAY13               0x10000000 
#define WGL_SWAP_UNDERLAY14               0x20000000 
#define WGL_SWAP_UNDERLAY15               0x40000000 

// functions typedefs
typedef int (APIENTRYP PFN_DESCRIBEPIXELFORMAT_PROC) (HDC hdc, int ipfd, UINT cjpfd, const PIXELFORMATDESCRIPTOR * ppfd);
typedef UINT (APIENTRYP PFN_GETENHMETAFILEPIXELFORMAT_PROC) (HENHMETAFILE hemf, const PIXELFORMATDESCRIPTOR * ppfd);
typedef BOOL (APIENTRYP PFN_WGLDESCRIBELAYERPLANE_PROC) (HDC hDc, int pixelFormat, int layerPlane, UINT nBytes, const LAYERPLANEDESCRIPTOR * plpd);
typedef int (APIENTRYP PFN_WGLGETLAYERPALETTEENTRIES_PROC) (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr);

// functions typedefs
WGL_FUNC_DEF PFN_DESCRIBEPIXELFORMAT_PROC _DescribePixelFormat_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_GETENHMETAFILEPIXELFORMAT_PROC _GetEnhMetaFilePixelFormat_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDESCRIBELAYERPLANE_PROC _wglDescribeLayerPlane_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETLAYERPALETTEENTRIES_PROC _wglGetLayerPaletteEntries_ WGL_FUNC_DEF2;

// functions inline wrap
inline int DescribePixelFormat (HDC hdc, int ipfd, UINT cjpfd, const PIXELFORMATDESCRIPTOR * ppfd) { return _DescribePixelFormat_(hdc, ipfd, cjpfd, ppfd); };
inline UINT GetEnhMetaFilePixelFormat (HENHMETAFILE hemf, const PIXELFORMATDESCRIPTOR * ppfd) { return _GetEnhMetaFilePixelFormat_(hemf, ppfd); };
inline BOOL wglDescribeLayerPlane (HDC hDc, int pixelFormat, int layerPlane, UINT nBytes, const LAYERPLANEDESCRIPTOR * plpd) { return _wglDescribeLayerPlane_(hDc, pixelFormat, layerPlane, nBytes, plpd); };
inline int wglGetLayerPaletteEntries (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr) { return _wglGetLayerPaletteEntries_(hdc, iLayerPlane, iStart, cEntries, pcr); };
#endif //WGL_VERSION_1_0

#ifndef WGL_ARB_buffer_region

// Defines
#define WGL_FRONT_COLOR_BUFFER_BIT_ARB    0x00000001 
#define WGL_BACK_COLOR_BUFFER_BIT_ARB     0x00000002 
#define WGL_DEPTH_BUFFER_BIT_ARB          0x00000004 
#define WGL_STENCIL_BUFFER_BIT_ARB        0x00000008 

// functions typedefs
typedef HANDLE (APIENTRYP PFN_WGLCREATEBUFFERREGIONARB_PROC) (HDC hDC, int iLayerPlane, UINT uType);
typedef VOID (APIENTRYP PFN_WGLDELETEBUFFERREGIONARB_PROC) (HANDLE hRegion);
typedef BOOL (APIENTRYP PFN_WGLSAVEBUFFERREGIONARB_PROC) (HANDLE hRegion, int x, int y, int width, int height);
typedef BOOL (APIENTRYP PFN_WGLRESTOREBUFFERREGIONARB_PROC) (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);

// functions typedefs
WGL_FUNC_DEF PFN_WGLCREATEBUFFERREGIONARB_PROC _wglCreateBufferRegionARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDELETEBUFFERREGIONARB_PROC _wglDeleteBufferRegionARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLSAVEBUFFERREGIONARB_PROC _wglSaveBufferRegionARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLRESTOREBUFFERREGIONARB_PROC _wglRestoreBufferRegionARB_ WGL_FUNC_DEF2;

// functions inline wrap
inline HANDLE wglCreateBufferRegionARB (HDC hDC, int iLayerPlane, UINT uType) { return _wglCreateBufferRegionARB_(hDC, iLayerPlane, uType); };
inline VOID wglDeleteBufferRegionARB (HANDLE hRegion) { return _wglDeleteBufferRegionARB_(hRegion); };
inline BOOL wglSaveBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height) { return _wglSaveBufferRegionARB_(hRegion, x, y, width, height); };
inline BOOL wglRestoreBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc) { return _wglRestoreBufferRegionARB_(hRegion, x, y, width, height, xSrc, ySrc); };
#endif //WGL_ARB_buffer_region

#ifndef WGL_ARB_context_flush_control

// Defines
#define WGL_CONTEXT_RELEASE_BEHAVIOR_ARB  0x2097 
#define WGL_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB 0 
#define WGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB 0x2098 
#endif //WGL_ARB_context_flush_control

#ifndef WGL_ARB_create_context

// Defines
#define WGL_CONTEXT_DEBUG_BIT_ARB         0x00000001 
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002 
#define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091 
#define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092 
#define WGL_CONTEXT_LAYER_PLANE_ARB       0x2093 
#define WGL_CONTEXT_FLAGS_ARB             0x2094 
#define ERROR_INVALID_VERSION_ARB         0x2095 

// functions typedefs
typedef HGLRC (APIENTRYP PFN_WGLCREATECONTEXTATTRIBSARB_PROC) (HDC hDC, HGLRC hShareContext, const int * attribList);

// functions typedefs
WGL_FUNC_DEF PFN_WGLCREATECONTEXTATTRIBSARB_PROC _wglCreateContextAttribsARB_ WGL_FUNC_DEF2;

// functions inline wrap
inline HGLRC wglCreateContextAttribsARB (HDC hDC, HGLRC hShareContext, const int * attribList) { return _wglCreateContextAttribsARB_(hDC, hShareContext, attribList); };
#endif //WGL_ARB_create_context

#ifndef WGL_ARB_create_context_no_error

// Defines
#define WGL_CONTEXT_OPENGL_NO_ERROR_ARB   0x31B3 
#endif //WGL_ARB_create_context_no_error

#ifndef WGL_ARB_create_context_profile

// Defines
#define WGL_CONTEXT_PROFILE_MASK_ARB      0x9126 
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB  0x00000001 
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002 
#define ERROR_INVALID_PROFILE_ARB         0x2096 
#endif //WGL_ARB_create_context_profile

#ifndef WGL_ARB_create_context_robustness

// Defines
#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB 0x00000004 
#define WGL_LOSE_CONTEXT_ON_RESET_ARB     0x8252 
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB 0x8256 
#define WGL_NO_RESET_NOTIFICATION_ARB     0x8261 
#endif //WGL_ARB_create_context_robustness

#ifndef WGL_ARB_extensions_string

// functions typedefs
typedef const char * (APIENTRYP PFN_WGLGETEXTENSIONSSTRINGARB_PROC) (HDC hdc);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETEXTENSIONSSTRINGARB_PROC _wglGetExtensionsStringARB_ WGL_FUNC_DEF2;

// functions inline wrap
inline const char * wglGetExtensionsStringARB (HDC hdc) { return _wglGetExtensionsStringARB_(hdc); };
#endif //WGL_ARB_extensions_string

#ifndef WGL_ARB_framebuffer_sRGB

// Defines
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB  0x20A9 
#endif //WGL_ARB_framebuffer_sRGB

#ifndef WGL_ARB_make_current_read

// Defines
#define ERROR_INVALID_PIXEL_TYPE_ARB      0x2043 
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB 0x2054 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLMAKECONTEXTCURRENTARB_PROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
typedef HDC (APIENTRYP PFN_WGLGETCURRENTREADDCARB_PROC) (void);

// functions typedefs
WGL_FUNC_DEF PFN_WGLMAKECONTEXTCURRENTARB_PROC _wglMakeContextCurrentARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETCURRENTREADDCARB_PROC _wglGetCurrentReadDCARB_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglMakeContextCurrentARB (HDC hDrawDC, HDC hReadDC, HGLRC hglrc) { return _wglMakeContextCurrentARB_(hDrawDC, hReadDC, hglrc); };
inline HDC wglGetCurrentReadDCARB (void) { return _wglGetCurrentReadDCARB_(); };
#endif //WGL_ARB_make_current_read

#ifndef WGL_ARB_multisample

// Defines
#define WGL_SAMPLE_BUFFERS_ARB            0x2041 
#define WGL_SAMPLES_ARB                   0x2042 
#endif //WGL_ARB_multisample

#ifndef WGL_ARB_pbuffer

// Defines
#define WGL_DRAW_TO_PBUFFER_ARB           0x202D 
#define WGL_MAX_PBUFFER_PIXELS_ARB        0x202E 
#define WGL_MAX_PBUFFER_WIDTH_ARB         0x202F 
#define WGL_MAX_PBUFFER_HEIGHT_ARB        0x2030 
#define WGL_PBUFFER_LARGEST_ARB           0x2033 
#define WGL_PBUFFER_WIDTH_ARB             0x2034 
#define WGL_PBUFFER_HEIGHT_ARB            0x2035 
#define WGL_PBUFFER_LOST_ARB              0x2036 

// functions typedefs
typedef HPBUFFERARB (APIENTRYP PFN_WGLCREATEPBUFFERARB_PROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList);
typedef HDC (APIENTRYP PFN_WGLGETPBUFFERDCARB_PROC) (HPBUFFERARB hPbuffer);
typedef int (APIENTRYP PFN_WGLRELEASEPBUFFERDCARB_PROC) (HPBUFFERARB hPbuffer, HDC hDC);
typedef BOOL (APIENTRYP PFN_WGLDESTROYPBUFFERARB_PROC) (HPBUFFERARB hPbuffer);
typedef BOOL (APIENTRYP PFN_WGLQUERYPBUFFERARB_PROC) (HPBUFFERARB hPbuffer, int iAttribute, int * piValue);

// functions typedefs
WGL_FUNC_DEF PFN_WGLCREATEPBUFFERARB_PROC _wglCreatePbufferARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETPBUFFERDCARB_PROC _wglGetPbufferDCARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLRELEASEPBUFFERDCARB_PROC _wglReleasePbufferDCARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDESTROYPBUFFERARB_PROC _wglDestroyPbufferARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYPBUFFERARB_PROC _wglQueryPbufferARB_ WGL_FUNC_DEF2;

// functions inline wrap
inline HPBUFFERARB wglCreatePbufferARB (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList) { return _wglCreatePbufferARB_(hDC, iPixelFormat, iWidth, iHeight, piAttribList); };
inline HDC wglGetPbufferDCARB (HPBUFFERARB hPbuffer) { return _wglGetPbufferDCARB_(hPbuffer); };
inline int wglReleasePbufferDCARB (HPBUFFERARB hPbuffer, HDC hDC) { return _wglReleasePbufferDCARB_(hPbuffer, hDC); };
inline BOOL wglDestroyPbufferARB (HPBUFFERARB hPbuffer) { return _wglDestroyPbufferARB_(hPbuffer); };
inline BOOL wglQueryPbufferARB (HPBUFFERARB hPbuffer, int iAttribute, int * piValue) { return _wglQueryPbufferARB_(hPbuffer, iAttribute, piValue); };
#endif //WGL_ARB_pbuffer

#ifndef WGL_ARB_pixel_format

// Defines
#define WGL_NUMBER_PIXEL_FORMATS_ARB      0x2000 
#define WGL_DRAW_TO_WINDOW_ARB            0x2001 
#define WGL_DRAW_TO_BITMAP_ARB            0x2002 
#define WGL_ACCELERATION_ARB              0x2003 
#define WGL_NEED_PALETTE_ARB              0x2004 
#define WGL_NEED_SYSTEM_PALETTE_ARB       0x2005 
#define WGL_SWAP_LAYER_BUFFERS_ARB        0x2006 
#define WGL_SWAP_METHOD_ARB               0x2007 
#define WGL_NUMBER_OVERLAYS_ARB           0x2008 
#define WGL_NUMBER_UNDERLAYS_ARB          0x2009 
#define WGL_TRANSPARENT_ARB               0x200A 
#define WGL_TRANSPARENT_RED_VALUE_ARB     0x2037 
#define WGL_TRANSPARENT_GREEN_VALUE_ARB   0x2038 
#define WGL_TRANSPARENT_BLUE_VALUE_ARB    0x2039 
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB   0x203A 
#define WGL_TRANSPARENT_INDEX_VALUE_ARB   0x203B 
#define WGL_SHARE_DEPTH_ARB               0x200C 
#define WGL_SHARE_STENCIL_ARB             0x200D 
#define WGL_SHARE_ACCUM_ARB               0x200E 
#define WGL_SUPPORT_GDI_ARB               0x200F 
#define WGL_SUPPORT_OPENGL_ARB            0x2010 
#define WGL_DOUBLE_BUFFER_ARB             0x2011 
#define WGL_STEREO_ARB                    0x2012 
#define WGL_PIXEL_TYPE_ARB                0x2013 
#define WGL_COLOR_BITS_ARB                0x2014 
#define WGL_RED_BITS_ARB                  0x2015 
#define WGL_RED_SHIFT_ARB                 0x2016 
#define WGL_GREEN_BITS_ARB                0x2017 
#define WGL_GREEN_SHIFT_ARB               0x2018 
#define WGL_BLUE_BITS_ARB                 0x2019 
#define WGL_BLUE_SHIFT_ARB                0x201A 
#define WGL_ALPHA_BITS_ARB                0x201B 
#define WGL_ALPHA_SHIFT_ARB               0x201C 
#define WGL_ACCUM_BITS_ARB                0x201D 
#define WGL_ACCUM_RED_BITS_ARB            0x201E 
#define WGL_ACCUM_GREEN_BITS_ARB          0x201F 
#define WGL_ACCUM_BLUE_BITS_ARB           0x2020 
#define WGL_ACCUM_ALPHA_BITS_ARB          0x2021 
#define WGL_DEPTH_BITS_ARB                0x2022 
#define WGL_STENCIL_BITS_ARB              0x2023 
#define WGL_AUX_BUFFERS_ARB               0x2024 
#define WGL_NO_ACCELERATION_ARB           0x2025 
#define WGL_GENERIC_ACCELERATION_ARB      0x2026 
#define WGL_FULL_ACCELERATION_ARB         0x2027 
#define WGL_SWAP_EXCHANGE_ARB             0x2028 
#define WGL_SWAP_COPY_ARB                 0x2029 
#define WGL_SWAP_UNDEFINED_ARB            0x202A 
#define WGL_TYPE_RGBA_ARB                 0x202B 
#define WGL_TYPE_COLORINDEX_ARB           0x202C 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLGETPIXELFORMATATTRIBIVARB_PROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues);
typedef BOOL (APIENTRYP PFN_WGLGETPIXELFORMATATTRIBFVARB_PROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues);
typedef BOOL (APIENTRYP PFN_WGLCHOOSEPIXELFORMATARB_PROC) (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETPIXELFORMATATTRIBIVARB_PROC _wglGetPixelFormatAttribivARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETPIXELFORMATATTRIBFVARB_PROC _wglGetPixelFormatAttribfvARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLCHOOSEPIXELFORMATARB_PROC _wglChoosePixelFormatARB_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglGetPixelFormatAttribivARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues) { return _wglGetPixelFormatAttribivARB_(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues); };
inline BOOL wglGetPixelFormatAttribfvARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues) { return _wglGetPixelFormatAttribfvARB_(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues); };
inline BOOL wglChoosePixelFormatARB (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats) { return _wglChoosePixelFormatARB_(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats); };
#endif //WGL_ARB_pixel_format

#ifndef WGL_ARB_pixel_format_float

// Defines
#define WGL_TYPE_RGBA_FLOAT_ARB           0x21A0 
#endif //WGL_ARB_pixel_format_float

#ifndef WGL_ARB_render_texture

// Defines
#define WGL_BIND_TO_TEXTURE_RGB_ARB       0x2070 
#define WGL_BIND_TO_TEXTURE_RGBA_ARB      0x2071 
#define WGL_TEXTURE_FORMAT_ARB            0x2072 
#define WGL_TEXTURE_TARGET_ARB            0x2073 
#define WGL_MIPMAP_TEXTURE_ARB            0x2074 
#define WGL_TEXTURE_RGB_ARB               0x2075 
#define WGL_TEXTURE_RGBA_ARB              0x2076 
#define WGL_NO_TEXTURE_ARB                0x2077 
#define WGL_TEXTURE_CUBE_MAP_ARB          0x2078 
#define WGL_TEXTURE_1D_ARB                0x2079 
#define WGL_TEXTURE_2D_ARB                0x207A 
#define WGL_MIPMAP_LEVEL_ARB              0x207B 
#define WGL_CUBE_MAP_FACE_ARB             0x207C 
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x207D 
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x207E 
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x207F 
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x2080 
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x2081 
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x2082 
#define WGL_FRONT_LEFT_ARB                0x2083 
#define WGL_FRONT_RIGHT_ARB               0x2084 
#define WGL_BACK_LEFT_ARB                 0x2085 
#define WGL_BACK_RIGHT_ARB                0x2086 
#define WGL_AUX0_ARB                      0x2087 
#define WGL_AUX1_ARB                      0x2088 
#define WGL_AUX2_ARB                      0x2089 
#define WGL_AUX3_ARB                      0x208A 
#define WGL_AUX4_ARB                      0x208B 
#define WGL_AUX5_ARB                      0x208C 
#define WGL_AUX6_ARB                      0x208D 
#define WGL_AUX7_ARB                      0x208E 
#define WGL_AUX8_ARB                      0x208F 
#define WGL_AUX9_ARB                      0x2090 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLBINDTEXIMAGEARB_PROC) (HPBUFFERARB hPbuffer, int iBuffer);
typedef BOOL (APIENTRYP PFN_WGLRELEASETEXIMAGEARB_PROC) (HPBUFFERARB hPbuffer, int iBuffer);
typedef BOOL (APIENTRYP PFN_WGLSETPBUFFERATTRIBARB_PROC) (HPBUFFERARB hPbuffer, const int * piAttribList);

// functions typedefs
WGL_FUNC_DEF PFN_WGLBINDTEXIMAGEARB_PROC _wglBindTexImageARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLRELEASETEXIMAGEARB_PROC _wglReleaseTexImageARB_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLSETPBUFFERATTRIBARB_PROC _wglSetPbufferAttribARB_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglBindTexImageARB (HPBUFFERARB hPbuffer, int iBuffer) { return _wglBindTexImageARB_(hPbuffer, iBuffer); };
inline BOOL wglReleaseTexImageARB (HPBUFFERARB hPbuffer, int iBuffer) { return _wglReleaseTexImageARB_(hPbuffer, iBuffer); };
inline BOOL wglSetPbufferAttribARB (HPBUFFERARB hPbuffer, const int * piAttribList) { return _wglSetPbufferAttribARB_(hPbuffer, piAttribList); };
#endif //WGL_ARB_render_texture

#ifndef WGL_ARB_robustness_application_isolation

// Defines
#define WGL_CONTEXT_RESET_ISOLATION_BIT_ARB 0x00000008 
#endif //WGL_ARB_robustness_application_isolation

// WGL_ARB_robustness_share_group_isolation

#ifndef WGL_3DFX_multisample

// Defines
#define WGL_SAMPLE_BUFFERS_3DFX           0x2060 
#define WGL_SAMPLES_3DFX                  0x2061 
#endif //WGL_3DFX_multisample

#ifndef WGL_3DL_stereo_control

// Defines
#define WGL_STEREO_EMITTER_ENABLE_3DL     0x2055 
#define WGL_STEREO_EMITTER_DISABLE_3DL    0x2056 
#define WGL_STEREO_POLARITY_NORMAL_3DL    0x2057 
#define WGL_STEREO_POLARITY_INVERT_3DL    0x2058 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLSETSTEREOEMITTERSTATE3DL_PROC) (HDC hDC, UINT uState);

// functions typedefs
WGL_FUNC_DEF PFN_WGLSETSTEREOEMITTERSTATE3DL_PROC _wglSetStereoEmitterState3DL_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglSetStereoEmitterState3DL (HDC hDC, UINT uState) { return _wglSetStereoEmitterState3DL_(hDC, uState); };
#endif //WGL_3DL_stereo_control

#ifndef WGL_AMD_gpu_association

// Defines
#define WGL_GPU_VENDOR_AMD                0x1F00 
#define WGL_GPU_RENDERER_STRING_AMD       0x1F01 
#define WGL_GPU_OPENGL_VERSION_STRING_AMD 0x1F02 
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD   0x21A2 
#define WGL_GPU_RAM_AMD                   0x21A3 
#define WGL_GPU_CLOCK_AMD                 0x21A4 
#define WGL_GPU_NUM_PIPES_AMD             0x21A5 
#define WGL_GPU_NUM_SIMD_AMD              0x21A6 
#define WGL_GPU_NUM_RB_AMD                0x21A7 
#define WGL_GPU_NUM_SPI_AMD               0x21A8 

// functions typedefs
typedef UINT (APIENTRYP PFN_WGLGETGPUIDSAMD_PROC) (UINT maxCount, UINT * ids);
typedef INT (APIENTRYP PFN_WGLGETGPUINFOAMD_PROC) (UINT id, INT property, GLenum dataType, UINT size, void * data);
typedef UINT (APIENTRYP PFN_WGLGETCONTEXTGPUIDAMD_PROC) (HGLRC hglrc);
typedef HGLRC (APIENTRYP PFN_WGLCREATEASSOCIATEDCONTEXTAMD_PROC) (UINT id);
typedef HGLRC (APIENTRYP PFN_WGLCREATEASSOCIATEDCONTEXTATTRIBSAMD_PROC) (UINT id, HGLRC hShareContext, const int * attribList);
typedef BOOL (APIENTRYP PFN_WGLDELETEASSOCIATEDCONTEXTAMD_PROC) (HGLRC hglrc);
typedef BOOL (APIENTRYP PFN_WGLMAKEASSOCIATEDCONTEXTCURRENTAMD_PROC) (HGLRC hglrc);
typedef HGLRC (APIENTRYP PFN_WGLGETCURRENTASSOCIATEDCONTEXTAMD_PROC) (void);
typedef VOID (APIENTRYP PFN_WGLBLITCONTEXTFRAMEBUFFERAMD_PROC) (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETGPUIDSAMD_PROC _wglGetGPUIDsAMD_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETGPUINFOAMD_PROC _wglGetGPUInfoAMD_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETCONTEXTGPUIDAMD_PROC _wglGetContextGPUIDAMD_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLCREATEASSOCIATEDCONTEXTAMD_PROC _wglCreateAssociatedContextAMD_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLCREATEASSOCIATEDCONTEXTATTRIBSAMD_PROC _wglCreateAssociatedContextAttribsAMD_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDELETEASSOCIATEDCONTEXTAMD_PROC _wglDeleteAssociatedContextAMD_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLMAKEASSOCIATEDCONTEXTCURRENTAMD_PROC _wglMakeAssociatedContextCurrentAMD_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETCURRENTASSOCIATEDCONTEXTAMD_PROC _wglGetCurrentAssociatedContextAMD_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLBLITCONTEXTFRAMEBUFFERAMD_PROC _wglBlitContextFramebufferAMD_ WGL_FUNC_DEF2;

// functions inline wrap
inline UINT wglGetGPUIDsAMD (UINT maxCount, UINT * ids) { return _wglGetGPUIDsAMD_(maxCount, ids); };
inline INT wglGetGPUInfoAMD (UINT id, INT property, GLenum dataType, UINT size, void * data) { return _wglGetGPUInfoAMD_(id, property, dataType, size, data); };
inline UINT wglGetContextGPUIDAMD (HGLRC hglrc) { return _wglGetContextGPUIDAMD_(hglrc); };
inline HGLRC wglCreateAssociatedContextAMD (UINT id) { return _wglCreateAssociatedContextAMD_(id); };
inline HGLRC wglCreateAssociatedContextAttribsAMD (UINT id, HGLRC hShareContext, const int * attribList) { return _wglCreateAssociatedContextAttribsAMD_(id, hShareContext, attribList); };
inline BOOL wglDeleteAssociatedContextAMD (HGLRC hglrc) { return _wglDeleteAssociatedContextAMD_(hglrc); };
inline BOOL wglMakeAssociatedContextCurrentAMD (HGLRC hglrc) { return _wglMakeAssociatedContextCurrentAMD_(hglrc); };
inline HGLRC wglGetCurrentAssociatedContextAMD (void) { return _wglGetCurrentAssociatedContextAMD_(); };
inline VOID wglBlitContextFramebufferAMD (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { return _wglBlitContextFramebufferAMD_(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); };
#endif //WGL_AMD_gpu_association

#ifndef WGL_ATI_pixel_format_float

// Defines
#define WGL_TYPE_RGBA_FLOAT_ATI           0x21A0 
#endif //WGL_ATI_pixel_format_float

#ifndef WGL_ATI_render_texture_rectangle

// Defines
#define WGL_TEXTURE_RECTANGLE_ATI         0x21A5 
#endif //WGL_ATI_render_texture_rectangle

#ifndef WGL_EXT_colorspace

// Defines
#define WGL_COLORSPACE_EXT                0x309D 
#define WGL_COLORSPACE_SRGB_EXT           0x3089 
#define WGL_COLORSPACE_LINEAR_EXT         0x308A 
#endif //WGL_EXT_colorspace

#ifndef WGL_EXT_create_context_es2_profile

// Defines
#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT   0x00000004 
#endif //WGL_EXT_create_context_es2_profile

#ifndef WGL_EXT_create_context_es_profile

// Defines
#define WGL_CONTEXT_ES_PROFILE_BIT_EXT    0x00000004 
#endif //WGL_EXT_create_context_es_profile

#ifndef WGL_EXT_depth_float

// Defines
#define WGL_DEPTH_FLOAT_EXT               0x2040 
#endif //WGL_EXT_depth_float

#ifndef WGL_EXT_display_color_table

// functions typedefs
typedef GLboolean (APIENTRYP PFN_WGLCREATEDISPLAYCOLORTABLEEXT_PROC) (GLushort id);
typedef GLboolean (APIENTRYP PFN_WGLLOADDISPLAYCOLORTABLEEXT_PROC) (const GLushort * table, GLuint length);
typedef GLboolean (APIENTRYP PFN_WGLBINDDISPLAYCOLORTABLEEXT_PROC) (GLushort id);
typedef VOID (APIENTRYP PFN_WGLDESTROYDISPLAYCOLORTABLEEXT_PROC) (GLushort id);

// functions typedefs
WGL_FUNC_DEF PFN_WGLCREATEDISPLAYCOLORTABLEEXT_PROC _wglCreateDisplayColorTableEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLLOADDISPLAYCOLORTABLEEXT_PROC _wglLoadDisplayColorTableEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLBINDDISPLAYCOLORTABLEEXT_PROC _wglBindDisplayColorTableEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDESTROYDISPLAYCOLORTABLEEXT_PROC _wglDestroyDisplayColorTableEXT_ WGL_FUNC_DEF2;

// functions inline wrap
inline GLboolean wglCreateDisplayColorTableEXT (GLushort id) { return _wglCreateDisplayColorTableEXT_(id); };
inline GLboolean wglLoadDisplayColorTableEXT (const GLushort * table, GLuint length) { return _wglLoadDisplayColorTableEXT_(table, length); };
inline GLboolean wglBindDisplayColorTableEXT (GLushort id) { return _wglBindDisplayColorTableEXT_(id); };
inline VOID wglDestroyDisplayColorTableEXT (GLushort id) { return _wglDestroyDisplayColorTableEXT_(id); };
#endif //WGL_EXT_display_color_table

#ifndef WGL_EXT_extensions_string

// functions typedefs
typedef const char * (APIENTRYP PFN_WGLGETEXTENSIONSSTRINGEXT_PROC) (void);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETEXTENSIONSSTRINGEXT_PROC _wglGetExtensionsStringEXT_ WGL_FUNC_DEF2;

// functions inline wrap
inline const char * wglGetExtensionsStringEXT (void) { return _wglGetExtensionsStringEXT_(); };
#endif //WGL_EXT_extensions_string

#ifndef WGL_EXT_framebuffer_sRGB

// Defines
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT  0x20A9 
#endif //WGL_EXT_framebuffer_sRGB

#ifndef WGL_EXT_make_current_read

// Defines
#define ERROR_INVALID_PIXEL_TYPE_EXT      0x2043 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLMAKECONTEXTCURRENTEXT_PROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
typedef HDC (APIENTRYP PFN_WGLGETCURRENTREADDCEXT_PROC) (void);

// functions typedefs
WGL_FUNC_DEF PFN_WGLMAKECONTEXTCURRENTEXT_PROC _wglMakeContextCurrentEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETCURRENTREADDCEXT_PROC _wglGetCurrentReadDCEXT_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglMakeContextCurrentEXT (HDC hDrawDC, HDC hReadDC, HGLRC hglrc) { return _wglMakeContextCurrentEXT_(hDrawDC, hReadDC, hglrc); };
inline HDC wglGetCurrentReadDCEXT (void) { return _wglGetCurrentReadDCEXT_(); };
#endif //WGL_EXT_make_current_read

#ifndef WGL_EXT_multisample

// Defines
#define WGL_SAMPLE_BUFFERS_EXT            0x2041 
#define WGL_SAMPLES_EXT                   0x2042 
#endif //WGL_EXT_multisample

#ifndef WGL_EXT_pbuffer

// Defines
#define WGL_DRAW_TO_PBUFFER_EXT           0x202D 
#define WGL_MAX_PBUFFER_PIXELS_EXT        0x202E 
#define WGL_MAX_PBUFFER_WIDTH_EXT         0x202F 
#define WGL_MAX_PBUFFER_HEIGHT_EXT        0x2030 
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT     0x2031 
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT    0x2032 
#define WGL_PBUFFER_LARGEST_EXT           0x2033 
#define WGL_PBUFFER_WIDTH_EXT             0x2034 
#define WGL_PBUFFER_HEIGHT_EXT            0x2035 

// functions typedefs
typedef HPBUFFEREXT (APIENTRYP PFN_WGLCREATEPBUFFEREXT_PROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList);
typedef HDC (APIENTRYP PFN_WGLGETPBUFFERDCEXT_PROC) (HPBUFFEREXT hPbuffer);
typedef int (APIENTRYP PFN_WGLRELEASEPBUFFERDCEXT_PROC) (HPBUFFEREXT hPbuffer, HDC hDC);
typedef BOOL (APIENTRYP PFN_WGLDESTROYPBUFFEREXT_PROC) (HPBUFFEREXT hPbuffer);
typedef BOOL (APIENTRYP PFN_WGLQUERYPBUFFEREXT_PROC) (HPBUFFEREXT hPbuffer, int iAttribute, int * piValue);

// functions typedefs
WGL_FUNC_DEF PFN_WGLCREATEPBUFFEREXT_PROC _wglCreatePbufferEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETPBUFFERDCEXT_PROC _wglGetPbufferDCEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLRELEASEPBUFFERDCEXT_PROC _wglReleasePbufferDCEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDESTROYPBUFFEREXT_PROC _wglDestroyPbufferEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYPBUFFEREXT_PROC _wglQueryPbufferEXT_ WGL_FUNC_DEF2;

// functions inline wrap
inline HPBUFFEREXT wglCreatePbufferEXT (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList) { return _wglCreatePbufferEXT_(hDC, iPixelFormat, iWidth, iHeight, piAttribList); };
inline HDC wglGetPbufferDCEXT (HPBUFFEREXT hPbuffer) { return _wglGetPbufferDCEXT_(hPbuffer); };
inline int wglReleasePbufferDCEXT (HPBUFFEREXT hPbuffer, HDC hDC) { return _wglReleasePbufferDCEXT_(hPbuffer, hDC); };
inline BOOL wglDestroyPbufferEXT (HPBUFFEREXT hPbuffer) { return _wglDestroyPbufferEXT_(hPbuffer); };
inline BOOL wglQueryPbufferEXT (HPBUFFEREXT hPbuffer, int iAttribute, int * piValue) { return _wglQueryPbufferEXT_(hPbuffer, iAttribute, piValue); };
#endif //WGL_EXT_pbuffer

#ifndef WGL_EXT_pixel_format

// Defines
#define WGL_NUMBER_PIXEL_FORMATS_EXT      0x2000 
#define WGL_DRAW_TO_WINDOW_EXT            0x2001 
#define WGL_DRAW_TO_BITMAP_EXT            0x2002 
#define WGL_ACCELERATION_EXT              0x2003 
#define WGL_NEED_PALETTE_EXT              0x2004 
#define WGL_NEED_SYSTEM_PALETTE_EXT       0x2005 
#define WGL_SWAP_LAYER_BUFFERS_EXT        0x2006 
#define WGL_SWAP_METHOD_EXT               0x2007 
#define WGL_NUMBER_OVERLAYS_EXT           0x2008 
#define WGL_NUMBER_UNDERLAYS_EXT          0x2009 
#define WGL_TRANSPARENT_EXT               0x200A 
#define WGL_TRANSPARENT_VALUE_EXT         0x200B 
#define WGL_SHARE_DEPTH_EXT               0x200C 
#define WGL_SHARE_STENCIL_EXT             0x200D 
#define WGL_SHARE_ACCUM_EXT               0x200E 
#define WGL_SUPPORT_GDI_EXT               0x200F 
#define WGL_SUPPORT_OPENGL_EXT            0x2010 
#define WGL_DOUBLE_BUFFER_EXT             0x2011 
#define WGL_STEREO_EXT                    0x2012 
#define WGL_PIXEL_TYPE_EXT                0x2013 
#define WGL_COLOR_BITS_EXT                0x2014 
#define WGL_RED_BITS_EXT                  0x2015 
#define WGL_RED_SHIFT_EXT                 0x2016 
#define WGL_GREEN_BITS_EXT                0x2017 
#define WGL_GREEN_SHIFT_EXT               0x2018 
#define WGL_BLUE_BITS_EXT                 0x2019 
#define WGL_BLUE_SHIFT_EXT                0x201A 
#define WGL_ALPHA_BITS_EXT                0x201B 
#define WGL_ALPHA_SHIFT_EXT               0x201C 
#define WGL_ACCUM_BITS_EXT                0x201D 
#define WGL_ACCUM_RED_BITS_EXT            0x201E 
#define WGL_ACCUM_GREEN_BITS_EXT          0x201F 
#define WGL_ACCUM_BLUE_BITS_EXT           0x2020 
#define WGL_ACCUM_ALPHA_BITS_EXT          0x2021 
#define WGL_DEPTH_BITS_EXT                0x2022 
#define WGL_STENCIL_BITS_EXT              0x2023 
#define WGL_AUX_BUFFERS_EXT               0x2024 
#define WGL_NO_ACCELERATION_EXT           0x2025 
#define WGL_GENERIC_ACCELERATION_EXT      0x2026 
#define WGL_FULL_ACCELERATION_EXT         0x2027 
#define WGL_SWAP_EXCHANGE_EXT             0x2028 
#define WGL_SWAP_COPY_EXT                 0x2029 
#define WGL_SWAP_UNDEFINED_EXT            0x202A 
#define WGL_TYPE_RGBA_EXT                 0x202B 
#define WGL_TYPE_COLORINDEX_EXT           0x202C 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLGETPIXELFORMATATTRIBIVEXT_PROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, int * piValues);
typedef BOOL (APIENTRYP PFN_WGLGETPIXELFORMATATTRIBFVEXT_PROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, FLOAT * pfValues);
typedef BOOL (APIENTRYP PFN_WGLCHOOSEPIXELFORMATEXT_PROC) (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETPIXELFORMATATTRIBIVEXT_PROC _wglGetPixelFormatAttribivEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETPIXELFORMATATTRIBFVEXT_PROC _wglGetPixelFormatAttribfvEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLCHOOSEPIXELFORMATEXT_PROC _wglChoosePixelFormatEXT_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglGetPixelFormatAttribivEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, int * piValues) { return _wglGetPixelFormatAttribivEXT_(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues); };
inline BOOL wglGetPixelFormatAttribfvEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, FLOAT * pfValues) { return _wglGetPixelFormatAttribfvEXT_(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues); };
inline BOOL wglChoosePixelFormatEXT (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats) { return _wglChoosePixelFormatEXT_(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats); };
#endif //WGL_EXT_pixel_format

#ifndef WGL_EXT_pixel_format_packed_float

// Defines
#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT  0x20A8 
#endif //WGL_EXT_pixel_format_packed_float

#ifndef WGL_EXT_swap_control

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLSWAPINTERVALEXT_PROC) (int interval);
typedef int (APIENTRYP PFN_WGLGETSWAPINTERVALEXT_PROC) (void);

// functions typedefs
WGL_FUNC_DEF PFN_WGLSWAPINTERVALEXT_PROC _wglSwapIntervalEXT_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETSWAPINTERVALEXT_PROC _wglGetSwapIntervalEXT_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglSwapIntervalEXT (int interval) { return _wglSwapIntervalEXT_(interval); };
inline int wglGetSwapIntervalEXT (void) { return _wglGetSwapIntervalEXT_(); };
#endif //WGL_EXT_swap_control

// WGL_EXT_swap_control_tear

#ifndef WGL_I3D_digital_video_control

// Defines
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D 0x2050 
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D 0x2051 
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D 0x2052 
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D 0x2053 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLGETDIGITALVIDEOPARAMETERSI3D_PROC) (HDC hDC, int iAttribute, int * piValue);
typedef BOOL (APIENTRYP PFN_WGLSETDIGITALVIDEOPARAMETERSI3D_PROC) (HDC hDC, int iAttribute, const int * piValue);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETDIGITALVIDEOPARAMETERSI3D_PROC _wglGetDigitalVideoParametersI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLSETDIGITALVIDEOPARAMETERSI3D_PROC _wglSetDigitalVideoParametersI3D_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglGetDigitalVideoParametersI3D (HDC hDC, int iAttribute, int * piValue) { return _wglGetDigitalVideoParametersI3D_(hDC, iAttribute, piValue); };
inline BOOL wglSetDigitalVideoParametersI3D (HDC hDC, int iAttribute, const int * piValue) { return _wglSetDigitalVideoParametersI3D_(hDC, iAttribute, piValue); };
#endif //WGL_I3D_digital_video_control

#ifndef WGL_I3D_gamma

// Defines
#define WGL_GAMMA_TABLE_SIZE_I3D          0x204E 
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D     0x204F 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLGETGAMMATABLEPARAMETERSI3D_PROC) (HDC hDC, int iAttribute, int * piValue);
typedef BOOL (APIENTRYP PFN_WGLSETGAMMATABLEPARAMETERSI3D_PROC) (HDC hDC, int iAttribute, const int * piValue);
typedef BOOL (APIENTRYP PFN_WGLGETGAMMATABLEI3D_PROC) (HDC hDC, int iEntries, USHORT * puRed, USHORT * puGreen, USHORT * puBlue);
typedef BOOL (APIENTRYP PFN_WGLSETGAMMATABLEI3D_PROC) (HDC hDC, int iEntries, const USHORT * puRed, const USHORT * puGreen, const USHORT * puBlue);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETGAMMATABLEPARAMETERSI3D_PROC _wglGetGammaTableParametersI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLSETGAMMATABLEPARAMETERSI3D_PROC _wglSetGammaTableParametersI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETGAMMATABLEI3D_PROC _wglGetGammaTableI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLSETGAMMATABLEI3D_PROC _wglSetGammaTableI3D_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglGetGammaTableParametersI3D (HDC hDC, int iAttribute, int * piValue) { return _wglGetGammaTableParametersI3D_(hDC, iAttribute, piValue); };
inline BOOL wglSetGammaTableParametersI3D (HDC hDC, int iAttribute, const int * piValue) { return _wglSetGammaTableParametersI3D_(hDC, iAttribute, piValue); };
inline BOOL wglGetGammaTableI3D (HDC hDC, int iEntries, USHORT * puRed, USHORT * puGreen, USHORT * puBlue) { return _wglGetGammaTableI3D_(hDC, iEntries, puRed, puGreen, puBlue); };
inline BOOL wglSetGammaTableI3D (HDC hDC, int iEntries, const USHORT * puRed, const USHORT * puGreen, const USHORT * puBlue) { return _wglSetGammaTableI3D_(hDC, iEntries, puRed, puGreen, puBlue); };
#endif //WGL_I3D_gamma

#ifndef WGL_I3D_genlock

// Defines
#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D  0x2044 
#define WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D 0x2045 
#define WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D 0x2046 
#define WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D 0x2047 
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D 0x2048 
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D 0x2049 
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D 0x204A 
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D 0x204B 
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D  0x204C 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLENABLEGENLOCKI3D_PROC) (HDC hDC);
typedef BOOL (APIENTRYP PFN_WGLDISABLEGENLOCKI3D_PROC) (HDC hDC);
typedef BOOL (APIENTRYP PFN_WGLISENABLEDGENLOCKI3D_PROC) (HDC hDC, BOOL * pFlag);
typedef BOOL (APIENTRYP PFN_WGLGENLOCKSOURCEI3D_PROC) (HDC hDC, UINT uSource);
typedef BOOL (APIENTRYP PFN_WGLGETGENLOCKSOURCEI3D_PROC) (HDC hDC, UINT * uSource);
typedef BOOL (APIENTRYP PFN_WGLGENLOCKSOURCEEDGEI3D_PROC) (HDC hDC, UINT uEdge);
typedef BOOL (APIENTRYP PFN_WGLGETGENLOCKSOURCEEDGEI3D_PROC) (HDC hDC, UINT * uEdge);
typedef BOOL (APIENTRYP PFN_WGLGENLOCKSAMPLERATEI3D_PROC) (HDC hDC, UINT uRate);
typedef BOOL (APIENTRYP PFN_WGLGETGENLOCKSAMPLERATEI3D_PROC) (HDC hDC, UINT * uRate);
typedef BOOL (APIENTRYP PFN_WGLGENLOCKSOURCEDELAYI3D_PROC) (HDC hDC, UINT uDelay);
typedef BOOL (APIENTRYP PFN_WGLGETGENLOCKSOURCEDELAYI3D_PROC) (HDC hDC, UINT * uDelay);
typedef BOOL (APIENTRYP PFN_WGLQUERYGENLOCKMAXSOURCEDELAYI3D_PROC) (HDC hDC, UINT * uMaxLineDelay, UINT * uMaxPixelDelay);

// functions typedefs
WGL_FUNC_DEF PFN_WGLENABLEGENLOCKI3D_PROC _wglEnableGenlockI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDISABLEGENLOCKI3D_PROC _wglDisableGenlockI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLISENABLEDGENLOCKI3D_PROC _wglIsEnabledGenlockI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGENLOCKSOURCEI3D_PROC _wglGenlockSourceI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETGENLOCKSOURCEI3D_PROC _wglGetGenlockSourceI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGENLOCKSOURCEEDGEI3D_PROC _wglGenlockSourceEdgeI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETGENLOCKSOURCEEDGEI3D_PROC _wglGetGenlockSourceEdgeI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGENLOCKSAMPLERATEI3D_PROC _wglGenlockSampleRateI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETGENLOCKSAMPLERATEI3D_PROC _wglGetGenlockSampleRateI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGENLOCKSOURCEDELAYI3D_PROC _wglGenlockSourceDelayI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETGENLOCKSOURCEDELAYI3D_PROC _wglGetGenlockSourceDelayI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYGENLOCKMAXSOURCEDELAYI3D_PROC _wglQueryGenlockMaxSourceDelayI3D_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglEnableGenlockI3D (HDC hDC) { return _wglEnableGenlockI3D_(hDC); };
inline BOOL wglDisableGenlockI3D (HDC hDC) { return _wglDisableGenlockI3D_(hDC); };
inline BOOL wglIsEnabledGenlockI3D (HDC hDC, BOOL * pFlag) { return _wglIsEnabledGenlockI3D_(hDC, pFlag); };
inline BOOL wglGenlockSourceI3D (HDC hDC, UINT uSource) { return _wglGenlockSourceI3D_(hDC, uSource); };
inline BOOL wglGetGenlockSourceI3D (HDC hDC, UINT * uSource) { return _wglGetGenlockSourceI3D_(hDC, uSource); };
inline BOOL wglGenlockSourceEdgeI3D (HDC hDC, UINT uEdge) { return _wglGenlockSourceEdgeI3D_(hDC, uEdge); };
inline BOOL wglGetGenlockSourceEdgeI3D (HDC hDC, UINT * uEdge) { return _wglGetGenlockSourceEdgeI3D_(hDC, uEdge); };
inline BOOL wglGenlockSampleRateI3D (HDC hDC, UINT uRate) { return _wglGenlockSampleRateI3D_(hDC, uRate); };
inline BOOL wglGetGenlockSampleRateI3D (HDC hDC, UINT * uRate) { return _wglGetGenlockSampleRateI3D_(hDC, uRate); };
inline BOOL wglGenlockSourceDelayI3D (HDC hDC, UINT uDelay) { return _wglGenlockSourceDelayI3D_(hDC, uDelay); };
inline BOOL wglGetGenlockSourceDelayI3D (HDC hDC, UINT * uDelay) { return _wglGetGenlockSourceDelayI3D_(hDC, uDelay); };
inline BOOL wglQueryGenlockMaxSourceDelayI3D (HDC hDC, UINT * uMaxLineDelay, UINT * uMaxPixelDelay) { return _wglQueryGenlockMaxSourceDelayI3D_(hDC, uMaxLineDelay, uMaxPixelDelay); };
#endif //WGL_I3D_genlock

#ifndef WGL_I3D_image_buffer

// Defines
#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D   0x00000001 
#define WGL_IMAGE_BUFFER_LOCK_I3D         0x00000002 

// functions typedefs
typedef LPVOID (APIENTRYP PFN_WGLCREATEIMAGEBUFFERI3D_PROC) (HDC hDC, DWORD dwSize, UINT uFlags);
typedef BOOL (APIENTRYP PFN_WGLDESTROYIMAGEBUFFERI3D_PROC) (HDC hDC, LPVOID pAddress);
typedef BOOL (APIENTRYP PFN_WGLASSOCIATEIMAGEBUFFEREVENTSI3D_PROC) (HDC hDC, const HANDLE * pEvent, const LPVOID * pAddress, const DWORD * pSize, UINT count);
typedef BOOL (APIENTRYP PFN_WGLRELEASEIMAGEBUFFEREVENTSI3D_PROC) (HDC hDC, const LPVOID * pAddress, UINT count);

// functions typedefs
WGL_FUNC_DEF PFN_WGLCREATEIMAGEBUFFERI3D_PROC _wglCreateImageBufferI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDESTROYIMAGEBUFFERI3D_PROC _wglDestroyImageBufferI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLASSOCIATEIMAGEBUFFEREVENTSI3D_PROC _wglAssociateImageBufferEventsI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLRELEASEIMAGEBUFFEREVENTSI3D_PROC _wglReleaseImageBufferEventsI3D_ WGL_FUNC_DEF2;

// functions inline wrap
inline LPVOID wglCreateImageBufferI3D (HDC hDC, DWORD dwSize, UINT uFlags) { return _wglCreateImageBufferI3D_(hDC, dwSize, uFlags); };
inline BOOL wglDestroyImageBufferI3D (HDC hDC, LPVOID pAddress) { return _wglDestroyImageBufferI3D_(hDC, pAddress); };
inline BOOL wglAssociateImageBufferEventsI3D (HDC hDC, const HANDLE * pEvent, const LPVOID * pAddress, const DWORD * pSize, UINT count) { return _wglAssociateImageBufferEventsI3D_(hDC, pEvent, pAddress, pSize, count); };
inline BOOL wglReleaseImageBufferEventsI3D (HDC hDC, const LPVOID * pAddress, UINT count) { return _wglReleaseImageBufferEventsI3D_(hDC, pAddress, count); };
#endif //WGL_I3D_image_buffer

#ifndef WGL_I3D_swap_frame_lock

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLENABLEFRAMELOCKI3D_PROC) (void);
typedef BOOL (APIENTRYP PFN_WGLDISABLEFRAMELOCKI3D_PROC) (void);
typedef BOOL (APIENTRYP PFN_WGLISENABLEDFRAMELOCKI3D_PROC) (BOOL * pFlag);
typedef BOOL (APIENTRYP PFN_WGLQUERYFRAMELOCKMASTERI3D_PROC) (BOOL * pFlag);

// functions typedefs
WGL_FUNC_DEF PFN_WGLENABLEFRAMELOCKI3D_PROC _wglEnableFrameLockI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDISABLEFRAMELOCKI3D_PROC _wglDisableFrameLockI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLISENABLEDFRAMELOCKI3D_PROC _wglIsEnabledFrameLockI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYFRAMELOCKMASTERI3D_PROC _wglQueryFrameLockMasterI3D_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglEnableFrameLockI3D (void) { return _wglEnableFrameLockI3D_(); };
inline BOOL wglDisableFrameLockI3D (void) { return _wglDisableFrameLockI3D_(); };
inline BOOL wglIsEnabledFrameLockI3D (BOOL * pFlag) { return _wglIsEnabledFrameLockI3D_(pFlag); };
inline BOOL wglQueryFrameLockMasterI3D (BOOL * pFlag) { return _wglQueryFrameLockMasterI3D_(pFlag); };
#endif //WGL_I3D_swap_frame_lock

#ifndef WGL_I3D_swap_frame_usage

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLGETFRAMEUSAGEI3D_PROC) (float * pUsage);
typedef BOOL (APIENTRYP PFN_WGLBEGINFRAMETRACKINGI3D_PROC) (void);
typedef BOOL (APIENTRYP PFN_WGLENDFRAMETRACKINGI3D_PROC) (void);
typedef BOOL (APIENTRYP PFN_WGLQUERYFRAMETRACKINGI3D_PROC) (DWORD * pFrameCount, DWORD * pMissedFrames, float * pLastMissedUsage);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETFRAMEUSAGEI3D_PROC _wglGetFrameUsageI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLBEGINFRAMETRACKINGI3D_PROC _wglBeginFrameTrackingI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLENDFRAMETRACKINGI3D_PROC _wglEndFrameTrackingI3D_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYFRAMETRACKINGI3D_PROC _wglQueryFrameTrackingI3D_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglGetFrameUsageI3D (float * pUsage) { return _wglGetFrameUsageI3D_(pUsage); };
inline BOOL wglBeginFrameTrackingI3D (void) { return _wglBeginFrameTrackingI3D_(); };
inline BOOL wglEndFrameTrackingI3D (void) { return _wglEndFrameTrackingI3D_(); };
inline BOOL wglQueryFrameTrackingI3D (DWORD * pFrameCount, DWORD * pMissedFrames, float * pLastMissedUsage) { return _wglQueryFrameTrackingI3D_(pFrameCount, pMissedFrames, pLastMissedUsage); };
#endif //WGL_I3D_swap_frame_usage

#ifndef WGL_NV_DX_interop

// Defines
#define WGL_ACCESS_READ_ONLY_NV           0x00000000 
#define WGL_ACCESS_READ_WRITE_NV          0x00000001 
#define WGL_ACCESS_WRITE_DISCARD_NV       0x00000002 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLDXSETRESOURCESHAREHANDLENV_PROC) (void * dxObject, HANDLE shareHandle);
typedef HANDLE (APIENTRYP PFN_WGLDXOPENDEVICENV_PROC) (void * dxDevice);
typedef BOOL (APIENTRYP PFN_WGLDXCLOSEDEVICENV_PROC) (HANDLE hDevice);
typedef HANDLE (APIENTRYP PFN_WGLDXREGISTEROBJECTNV_PROC) (HANDLE hDevice, void * dxObject, GLuint name, GLenum type, GLenum access);
typedef BOOL (APIENTRYP PFN_WGLDXUNREGISTEROBJECTNV_PROC) (HANDLE hDevice, HANDLE hObject);
typedef BOOL (APIENTRYP PFN_WGLDXOBJECTACCESSNV_PROC) (HANDLE hObject, GLenum access);
typedef BOOL (APIENTRYP PFN_WGLDXLOCKOBJECTSNV_PROC) (HANDLE hDevice, GLint count, HANDLE * hObjects);
typedef BOOL (APIENTRYP PFN_WGLDXUNLOCKOBJECTSNV_PROC) (HANDLE hDevice, GLint count, HANDLE * hObjects);

// functions typedefs
WGL_FUNC_DEF PFN_WGLDXSETRESOURCESHAREHANDLENV_PROC _wglDXSetResourceShareHandleNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDXOPENDEVICENV_PROC _wglDXOpenDeviceNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDXCLOSEDEVICENV_PROC _wglDXCloseDeviceNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDXREGISTEROBJECTNV_PROC _wglDXRegisterObjectNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDXUNREGISTEROBJECTNV_PROC _wglDXUnregisterObjectNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDXOBJECTACCESSNV_PROC _wglDXObjectAccessNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDXLOCKOBJECTSNV_PROC _wglDXLockObjectsNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDXUNLOCKOBJECTSNV_PROC _wglDXUnlockObjectsNV_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglDXSetResourceShareHandleNV (void * dxObject, HANDLE shareHandle) { return _wglDXSetResourceShareHandleNV_(dxObject, shareHandle); };
inline HANDLE wglDXOpenDeviceNV (void * dxDevice) { return _wglDXOpenDeviceNV_(dxDevice); };
inline BOOL wglDXCloseDeviceNV (HANDLE hDevice) { return _wglDXCloseDeviceNV_(hDevice); };
inline HANDLE wglDXRegisterObjectNV (HANDLE hDevice, void * dxObject, GLuint name, GLenum type, GLenum access) { return _wglDXRegisterObjectNV_(hDevice, dxObject, name, type, access); };
inline BOOL wglDXUnregisterObjectNV (HANDLE hDevice, HANDLE hObject) { return _wglDXUnregisterObjectNV_(hDevice, hObject); };
inline BOOL wglDXObjectAccessNV (HANDLE hObject, GLenum access) { return _wglDXObjectAccessNV_(hObject, access); };
inline BOOL wglDXLockObjectsNV (HANDLE hDevice, GLint count, HANDLE * hObjects) { return _wglDXLockObjectsNV_(hDevice, count, hObjects); };
inline BOOL wglDXUnlockObjectsNV (HANDLE hDevice, GLint count, HANDLE * hObjects) { return _wglDXUnlockObjectsNV_(hDevice, count, hObjects); };
#endif //WGL_NV_DX_interop

// WGL_NV_DX_interop2

#ifndef WGL_NV_copy_image

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLCOPYIMAGESUBDATANV_PROC) (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);

// functions typedefs
WGL_FUNC_DEF PFN_WGLCOPYIMAGESUBDATANV_PROC _wglCopyImageSubDataNV_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglCopyImageSubDataNV (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) { return _wglCopyImageSubDataNV_(hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth); };
#endif //WGL_NV_copy_image

#ifndef WGL_NV_delay_before_swap

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLDELAYBEFORESWAPNV_PROC) (HDC hDC, GLfloat seconds);

// functions typedefs
WGL_FUNC_DEF PFN_WGLDELAYBEFORESWAPNV_PROC _wglDelayBeforeSwapNV_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglDelayBeforeSwapNV (HDC hDC, GLfloat seconds) { return _wglDelayBeforeSwapNV_(hDC, seconds); };
#endif //WGL_NV_delay_before_swap

#ifndef WGL_NV_float_buffer

// Defines
#define WGL_FLOAT_COMPONENTS_NV           0x20B0 
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV 0x20B1 
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV 0x20B2 
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV 0x20B3 
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV 0x20B4 
#define WGL_TEXTURE_FLOAT_R_NV            0x20B5 
#define WGL_TEXTURE_FLOAT_RG_NV           0x20B6 
#define WGL_TEXTURE_FLOAT_RGB_NV          0x20B7 
#define WGL_TEXTURE_FLOAT_RGBA_NV         0x20B8 
#endif //WGL_NV_float_buffer

#ifndef WGL_NV_gpu_affinity

// Structs
struct _GPU_DEVICE { DWORD cb; CHAR DeviceName[32]; CHAR DeviceString[128]; DWORD Flags; RECT rcVirtualScreen;};

// Defines
#define ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV 0x20D0 
#define ERROR_MISSING_AFFINITY_MASK_NV    0x20D1 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLENUMGPUSNV_PROC) (UINT iGpuIndex, HGPUNV * phGpu);
typedef BOOL (APIENTRYP PFN_WGLENUMGPUDEVICESNV_PROC) (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
typedef HDC (APIENTRYP PFN_WGLCREATEAFFINITYDCNV_PROC) (const HGPUNV * phGpuList);
typedef BOOL (APIENTRYP PFN_WGLENUMGPUSFROMAFFINITYDCNV_PROC) (HDC hAffinityDC, UINT iGpuIndex, HGPUNV * hGpu);
typedef BOOL (APIENTRYP PFN_WGLDELETEDCNV_PROC) (HDC hdc);

// functions typedefs
WGL_FUNC_DEF PFN_WGLENUMGPUSNV_PROC _wglEnumGpusNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLENUMGPUDEVICESNV_PROC _wglEnumGpuDevicesNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLCREATEAFFINITYDCNV_PROC _wglCreateAffinityDCNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLENUMGPUSFROMAFFINITYDCNV_PROC _wglEnumGpusFromAffinityDCNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLDELETEDCNV_PROC _wglDeleteDCNV_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglEnumGpusNV (UINT iGpuIndex, HGPUNV * phGpu) { return _wglEnumGpusNV_(iGpuIndex, phGpu); };
inline BOOL wglEnumGpuDevicesNV (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice) { return _wglEnumGpuDevicesNV_(hGpu, iDeviceIndex, lpGpuDevice); };
inline HDC wglCreateAffinityDCNV (const HGPUNV * phGpuList) { return _wglCreateAffinityDCNV_(phGpuList); };
inline BOOL wglEnumGpusFromAffinityDCNV (HDC hAffinityDC, UINT iGpuIndex, HGPUNV * hGpu) { return _wglEnumGpusFromAffinityDCNV_(hAffinityDC, iGpuIndex, hGpu); };
inline BOOL wglDeleteDCNV (HDC hdc) { return _wglDeleteDCNV_(hdc); };
#endif //WGL_NV_gpu_affinity

#ifndef WGL_NV_multigpu_context

// Defines
#define WGL_CONTEXT_MULTIGPU_ATTRIB_NV    0x20AA 
#define WGL_CONTEXT_MULTIGPU_ATTRIB_SINGLE_NV 0x20AB 
#define WGL_CONTEXT_MULTIGPU_ATTRIB_AFR_NV 0x20AC 
#define WGL_CONTEXT_MULTIGPU_ATTRIB_MULTICAST_NV 0x20AD 
#define WGL_CONTEXT_MULTIGPU_ATTRIB_MULTI_DISPLAY_MULTICAST_NV 0x20AE 
#endif //WGL_NV_multigpu_context

#ifndef WGL_NV_multisample_coverage

// Defines
#define WGL_COVERAGE_SAMPLES_NV           0x2042 
#define WGL_COLOR_SAMPLES_NV              0x20B9 
#endif //WGL_NV_multisample_coverage

#ifndef WGL_NV_present_video

// Defines
#define WGL_NUM_VIDEO_SLOTS_NV            0x20F0 

// functions typedefs
typedef int (APIENTRYP PFN_WGLENUMERATEVIDEODEVICESNV_PROC) (HDC hDc, HVIDEOOUTPUTDEVICENV * phDeviceList);
typedef BOOL (APIENTRYP PFN_WGLBINDVIDEODEVICENV_PROC) (HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int * piAttribList);
typedef BOOL (APIENTRYP PFN_WGLQUERYCURRENTCONTEXTNV_PROC) (int iAttribute, int * piValue);

// functions typedefs
WGL_FUNC_DEF PFN_WGLENUMERATEVIDEODEVICESNV_PROC _wglEnumerateVideoDevicesNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLBINDVIDEODEVICENV_PROC _wglBindVideoDeviceNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYCURRENTCONTEXTNV_PROC _wglQueryCurrentContextNV_ WGL_FUNC_DEF2;

// functions inline wrap
inline int wglEnumerateVideoDevicesNV (HDC hDc, HVIDEOOUTPUTDEVICENV * phDeviceList) { return _wglEnumerateVideoDevicesNV_(hDc, phDeviceList); };
inline BOOL wglBindVideoDeviceNV (HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int * piAttribList) { return _wglBindVideoDeviceNV_(hDc, uVideoSlot, hVideoDevice, piAttribList); };
inline BOOL wglQueryCurrentContextNV (int iAttribute, int * piValue) { return _wglQueryCurrentContextNV_(iAttribute, piValue); };
#endif //WGL_NV_present_video

#ifndef WGL_NV_render_depth_texture

// Defines
#define WGL_BIND_TO_TEXTURE_DEPTH_NV      0x20A3 
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV 0x20A4 
#define WGL_DEPTH_TEXTURE_FORMAT_NV       0x20A5 
#define WGL_TEXTURE_DEPTH_COMPONENT_NV    0x20A6 
#define WGL_DEPTH_COMPONENT_NV            0x20A7 
#endif //WGL_NV_render_depth_texture

#ifndef WGL_NV_render_texture_rectangle

// Defines
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV 0x20A0 
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV 0x20A1 
#define WGL_TEXTURE_RECTANGLE_NV          0x20A2 
#endif //WGL_NV_render_texture_rectangle

#ifndef WGL_NV_swap_group

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLJOINSWAPGROUPNV_PROC) (HDC hDC, GLuint group);
typedef BOOL (APIENTRYP PFN_WGLBINDSWAPBARRIERNV_PROC) (GLuint group, GLuint barrier);
typedef BOOL (APIENTRYP PFN_WGLQUERYSWAPGROUPNV_PROC) (HDC hDC, GLuint * group, GLuint * barrier);
typedef BOOL (APIENTRYP PFN_WGLQUERYMAXSWAPGROUPSNV_PROC) (HDC hDC, GLuint * maxGroups, GLuint * maxBarriers);
typedef BOOL (APIENTRYP PFN_WGLQUERYFRAMECOUNTNV_PROC) (HDC hDC, GLuint * count);
typedef BOOL (APIENTRYP PFN_WGLRESETFRAMECOUNTNV_PROC) (HDC hDC);

// functions typedefs
WGL_FUNC_DEF PFN_WGLJOINSWAPGROUPNV_PROC _wglJoinSwapGroupNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLBINDSWAPBARRIERNV_PROC _wglBindSwapBarrierNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYSWAPGROUPNV_PROC _wglQuerySwapGroupNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYMAXSWAPGROUPSNV_PROC _wglQueryMaxSwapGroupsNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYFRAMECOUNTNV_PROC _wglQueryFrameCountNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLRESETFRAMECOUNTNV_PROC _wglResetFrameCountNV_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglJoinSwapGroupNV (HDC hDC, GLuint group) { return _wglJoinSwapGroupNV_(hDC, group); };
inline BOOL wglBindSwapBarrierNV (GLuint group, GLuint barrier) { return _wglBindSwapBarrierNV_(group, barrier); };
inline BOOL wglQuerySwapGroupNV (HDC hDC, GLuint * group, GLuint * barrier) { return _wglQuerySwapGroupNV_(hDC, group, barrier); };
inline BOOL wglQueryMaxSwapGroupsNV (HDC hDC, GLuint * maxGroups, GLuint * maxBarriers) { return _wglQueryMaxSwapGroupsNV_(hDC, maxGroups, maxBarriers); };
inline BOOL wglQueryFrameCountNV (HDC hDC, GLuint * count) { return _wglQueryFrameCountNV_(hDC, count); };
inline BOOL wglResetFrameCountNV (HDC hDC) { return _wglResetFrameCountNV_(hDC); };
#endif //WGL_NV_swap_group

#ifndef WGL_NV_vertex_array_range

// functions typedefs
typedef void * (APIENTRYP PFN_WGLALLOCATEMEMORYNV_PROC) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
typedef void (APIENTRYP PFN_WGLFREEMEMORYNV_PROC) (void * pointer);

// functions typedefs
WGL_FUNC_DEF PFN_WGLALLOCATEMEMORYNV_PROC _wglAllocateMemoryNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLFREEMEMORYNV_PROC _wglFreeMemoryNV_ WGL_FUNC_DEF2;

// functions inline wrap
inline void * wglAllocateMemoryNV (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority) { return _wglAllocateMemoryNV_(size, readfreq, writefreq, priority); };
inline void wglFreeMemoryNV (void * pointer) { return _wglFreeMemoryNV_(pointer); };
#endif //WGL_NV_vertex_array_range

#ifndef WGL_NV_video_capture

// Defines
#define WGL_UNIQUE_ID_NV                  0x20CE 
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV    0x20CF 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLBINDVIDEOCAPTUREDEVICENV_PROC) (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
typedef UINT (APIENTRYP PFN_WGLENUMERATEVIDEOCAPTUREDEVICESNV_PROC) (HDC hDc, HVIDEOINPUTDEVICENV * phDeviceList);
typedef BOOL (APIENTRYP PFN_WGLLOCKVIDEOCAPTUREDEVICENV_PROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
typedef BOOL (APIENTRYP PFN_WGLQUERYVIDEOCAPTUREDEVICENV_PROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int * piValue);
typedef BOOL (APIENTRYP PFN_WGLRELEASEVIDEOCAPTUREDEVICENV_PROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);

// functions typedefs
WGL_FUNC_DEF PFN_WGLBINDVIDEOCAPTUREDEVICENV_PROC _wglBindVideoCaptureDeviceNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLENUMERATEVIDEOCAPTUREDEVICESNV_PROC _wglEnumerateVideoCaptureDevicesNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLLOCKVIDEOCAPTUREDEVICENV_PROC _wglLockVideoCaptureDeviceNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLQUERYVIDEOCAPTUREDEVICENV_PROC _wglQueryVideoCaptureDeviceNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLRELEASEVIDEOCAPTUREDEVICENV_PROC _wglReleaseVideoCaptureDeviceNV_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglBindVideoCaptureDeviceNV (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice) { return _wglBindVideoCaptureDeviceNV_(uVideoSlot, hDevice); };
inline UINT wglEnumerateVideoCaptureDevicesNV (HDC hDc, HVIDEOINPUTDEVICENV * phDeviceList) { return _wglEnumerateVideoCaptureDevicesNV_(hDc, phDeviceList); };
inline BOOL wglLockVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice) { return _wglLockVideoCaptureDeviceNV_(hDc, hDevice); };
inline BOOL wglQueryVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int * piValue) { return _wglQueryVideoCaptureDeviceNV_(hDc, hDevice, iAttribute, piValue); };
inline BOOL wglReleaseVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice) { return _wglReleaseVideoCaptureDeviceNV_(hDc, hDevice); };
#endif //WGL_NV_video_capture

#ifndef WGL_NV_video_output

// Defines
#define WGL_BIND_TO_VIDEO_RGB_NV          0x20C0 
#define WGL_BIND_TO_VIDEO_RGBA_NV         0x20C1 
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV 0x20C2 
#define WGL_VIDEO_OUT_COLOR_NV            0x20C3 
#define WGL_VIDEO_OUT_ALPHA_NV            0x20C4 
#define WGL_VIDEO_OUT_DEPTH_NV            0x20C5 
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV  0x20C6 
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV  0x20C7 
#define WGL_VIDEO_OUT_FRAME               0x20C8 
#define WGL_VIDEO_OUT_FIELD_1             0x20C9 
#define WGL_VIDEO_OUT_FIELD_2             0x20CA 
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2  0x20CB 
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1  0x20CC 

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLGETVIDEODEVICENV_PROC) (HDC hDC, int numDevices, HPVIDEODEV * hVideoDevice);
typedef BOOL (APIENTRYP PFN_WGLRELEASEVIDEODEVICENV_PROC) (HPVIDEODEV hVideoDevice);
typedef BOOL (APIENTRYP PFN_WGLBINDVIDEOIMAGENV_PROC) (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
typedef BOOL (APIENTRYP PFN_WGLRELEASEVIDEOIMAGENV_PROC) (HPBUFFERARB hPbuffer, int iVideoBuffer);
typedef BOOL (APIENTRYP PFN_WGLSENDPBUFFERTOVIDEONV_PROC) (HPBUFFERARB hPbuffer, int iBufferType, unsigned long * pulCounterPbuffer, BOOL bBlock);
typedef BOOL (APIENTRYP PFN_WGLGETVIDEOINFONV_PROC) (HPVIDEODEV hpVideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETVIDEODEVICENV_PROC _wglGetVideoDeviceNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLRELEASEVIDEODEVICENV_PROC _wglReleaseVideoDeviceNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLBINDVIDEOIMAGENV_PROC _wglBindVideoImageNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLRELEASEVIDEOIMAGENV_PROC _wglReleaseVideoImageNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLSENDPBUFFERTOVIDEONV_PROC _wglSendPbufferToVideoNV_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETVIDEOINFONV_PROC _wglGetVideoInfoNV_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglGetVideoDeviceNV (HDC hDC, int numDevices, HPVIDEODEV * hVideoDevice) { return _wglGetVideoDeviceNV_(hDC, numDevices, hVideoDevice); };
inline BOOL wglReleaseVideoDeviceNV (HPVIDEODEV hVideoDevice) { return _wglReleaseVideoDeviceNV_(hVideoDevice); };
inline BOOL wglBindVideoImageNV (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer) { return _wglBindVideoImageNV_(hVideoDevice, hPbuffer, iVideoBuffer); };
inline BOOL wglReleaseVideoImageNV (HPBUFFERARB hPbuffer, int iVideoBuffer) { return _wglReleaseVideoImageNV_(hPbuffer, iVideoBuffer); };
inline BOOL wglSendPbufferToVideoNV (HPBUFFERARB hPbuffer, int iBufferType, unsigned long * pulCounterPbuffer, BOOL bBlock) { return _wglSendPbufferToVideoNV_(hPbuffer, iBufferType, pulCounterPbuffer, bBlock); };
inline BOOL wglGetVideoInfoNV (HPVIDEODEV hpVideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo) { return _wglGetVideoInfoNV_(hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo); };
#endif //WGL_NV_video_output

#ifndef WGL_OML_sync_control

// functions typedefs
typedef BOOL (APIENTRYP PFN_WGLGETSYNCVALUESOML_PROC) (HDC hdc, INT64 * ust, INT64 * msc, INT64 * sbc);
typedef BOOL (APIENTRYP PFN_WGLGETMSCRATEOML_PROC) (HDC hdc, INT32 * numerator, INT32 * denominator);
typedef INT64 (APIENTRYP PFN_WGLSWAPBUFFERSMSCOML_PROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef INT64 (APIENTRYP PFN_WGLSWAPLAYERBUFFERSMSCOML_PROC) (HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef BOOL (APIENTRYP PFN_WGLWAITFORMSCOML_PROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 * ust, INT64 * msc, INT64 * sbc);
typedef BOOL (APIENTRYP PFN_WGLWAITFORSBCOML_PROC) (HDC hdc, INT64 target_sbc, INT64 * ust, INT64 * msc, INT64 * sbc);

// functions typedefs
WGL_FUNC_DEF PFN_WGLGETSYNCVALUESOML_PROC _wglGetSyncValuesOML_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLGETMSCRATEOML_PROC _wglGetMscRateOML_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLSWAPBUFFERSMSCOML_PROC _wglSwapBuffersMscOML_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLSWAPLAYERBUFFERSMSCOML_PROC _wglSwapLayerBuffersMscOML_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLWAITFORMSCOML_PROC _wglWaitForMscOML_ WGL_FUNC_DEF2;
WGL_FUNC_DEF PFN_WGLWAITFORSBCOML_PROC _wglWaitForSbcOML_ WGL_FUNC_DEF2;

// functions inline wrap
inline BOOL wglGetSyncValuesOML (HDC hdc, INT64 * ust, INT64 * msc, INT64 * sbc) { return _wglGetSyncValuesOML_(hdc, ust, msc, sbc); };
inline BOOL wglGetMscRateOML (HDC hdc, INT32 * numerator, INT32 * denominator) { return _wglGetMscRateOML_(hdc, numerator, denominator); };
inline INT64 wglSwapBuffersMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder) { return _wglSwapBuffersMscOML_(hdc, target_msc, divisor, remainder); };
inline INT64 wglSwapLayerBuffersMscOML (HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder) { return _wglSwapLayerBuffersMscOML_(hdc, fuPlanes, target_msc, divisor, remainder); };
inline BOOL wglWaitForMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 * ust, INT64 * msc, INT64 * sbc) { return _wglWaitForMscOML_(hdc, target_msc, divisor, remainder, ust, msc, sbc); };
inline BOOL wglWaitForSbcOML (HDC hdc, INT64 target_sbc, INT64 * ust, INT64 * msc, INT64 * sbc) { return _wglWaitForSbcOML_(hdc, target_sbc, ust, msc, sbc); };
#endif //WGL_OML_sync_control

