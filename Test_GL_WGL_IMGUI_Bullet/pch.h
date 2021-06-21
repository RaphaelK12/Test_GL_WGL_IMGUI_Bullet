#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#define _USE_MATH_DEFINES 1
#include "targetver.h"
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <WinBase.h>
// #include <minwindef.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <tuple>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <iostream>
#include <limits.h>
#include <tchar.h>
#include <stdlib.h>

#include "ReferenceConunter.h"

using std::vector;
using std::string;

#include "json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

#include "VectorsGLM.h"

#include "..\..\Imagem004\Imagem004\Imagem004.h"
#include "..\..\Imagem004\Imagem004\Loaders.h"

//#include <gl/GL.h>
//#include "core+ext.h"
//#include "GLgetFunctions.h"

#define _avoid_unessessary_include_defines 1
#if _avoid_unessessary_include_defines
	#define GL_3DFX_tbuffer 1
	#define GL_AMD_framebuffer_multisample_advanced 1
	#define GL_APPLE_element_array 1
	#define GL_APPLE_fence 1
	#define GL_APPLE_flush_buffer_range 1
	#define GL_APPLE_object_purgeable 1
	#define GL_APPLE_vertex_array_object 1
	#define GL_APPLE_vertex_array_range 1
	#define GL_APPLE_vertex_program_evaluators 1
	#define GL_ARB_ES3_2_compatibility 1
	#define GL_ARB_cl_event 1
	#define GL_ARB_compute_variable_group_size 1
	#define GL_ARB_gl_spirv 1
	#define GL_ARB_gpu_shader_int64 1
	#define GL_ARB_matrix_palette 1
	#define GL_ARB_parallel_shader_compile 1
	#define GL_ARB_sample_locations 1
	#define GL_ARB_shading_language_include 1
	#define GL_ARB_vertex_blend 1
	#define GL_ATI_element_array 1
	#define GL_ATI_map_object_buffer 1
	#define GL_ATI_pn_triangles 1
	#define GL_ATI_vertex_array_object 1
	#define GL_ATI_vertex_attrib_array_object 1
	#define GL_ATI_vertex_streams 1
	#define GL_EXT_EGL_image_storage 1
	#define GL_EXT_color_subtable 1
	#define GL_EXT_convolution 1
	#define GL_EXT_coordinate_frame 1
	#define GL_EXT_cull_vertex 1
	#define GL_EXT_debug_label 1
	#define GL_EXT_debug_marker 1
	#define GL_EXT_external_buffer 1
	#define GL_EXT_index_func 1
	#define GL_EXT_index_material 1
	#define GL_EXT_light_texture 1
	#define GL_EXT_memory_object 1
	#define GL_EXT_memory_object_fd 1
	#define GL_EXT_memory_object_win32 1
	#define GL_EXT_multisample 1
	#define GL_EXT_pixel_transform 1
	#define GL_EXT_polygon_offset 1
	#define GL_EXT_raster_multisample 1
	#define GL_EXT_semaphore 1
	#define GL_EXT_semaphore_fd 1
	#define GL_EXT_semaphore_win32 1
	#define GL_EXT_separate_shader_objects 1
	#define GL_EXT_shader_framebuffer_fetch_non_coherent 1
	#define GL_EXT_stencil_clear_tag 1
	#define GL_EXT_stencil_two_side 1
	#define GL_EXT_texture_perturb_normal 1
	#define GL_EXT_vertex_weighting 1
	#define GL_EXT_win32_keyed_mutex 1
	#define GL_EXT_window_rectangles 1
	#define GL_EXT_x11_sync_object 1
	#define GL_GREMEDY_frame_terminator 1
	#define GL_GREMEDY_string_marker 1
	#define GL_HP_image_transform 1
	#define GL_IBM_multimode_draw_arrays 1
	#define GL_IBM_static_data 1
	#define GL_IBM_vertex_array_lists 1
	#define GL_INGR_blend_func_separate 1
	#define GL_INTEL_framebuffer_CMAA 1
	#define GL_INTEL_map_texture 1
	#define GL_INTEL_parallel_arrays 1
	#define GL_INTEL_performance_query 1
	#define GL_KHR_blend_equation_advanced 1
	#define GL_KHR_parallel_shader_compile 1
	#define GL_MESA_framebuffer_flip_y 1
	#define GL_MESA_resize_buffers 1
	#define GL_MESA_window_pos 1
	#define GL_NVX_conditional_render 1
	#define GL_NVX_gpu_multicast2 1
	#define GL_NVX_linked_gpu_multicast 1
	#define GL_NVX_progress_fence 1
	#define GL_NV_alpha_to_coverage_dither_control 1
	#define GL_NV_bindless_multi_draw_indirect 1
	#define GL_NV_bindless_multi_draw_indirect_count 1
	#define GL_NV_bindless_texture 1
	#define GL_NV_blend_equation_advanced 1
	#define GL_NV_clip_space_w_scaling 1
	#define GL_NV_command_list 1
	#define GL_NV_conservative_raster 1
	#define GL_NV_conservative_raster_dilate 1
	#define GL_NV_conservative_raster_pre_snap_triangles 1
	#define GL_NV_draw_texture 1
	#define GL_NV_draw_vulkan_image 1
	#define GL_NV_evaluators 1
	#define GL_NV_fence 1
	#define GL_NV_fragment_coverage_to_color 1
	#define GL_NV_fragment_program 1
	#define GL_NV_framebuffer_mixed_samples 1
	#define GL_NV_framebuffer_multisample_coverage 1
	#define GL_NV_gpu_multicast 1
	#define GL_NV_gpu_program4 1
	#define GL_NV_gpu_program5 1
	#define GL_NV_internalformat_sample_query 1
	#define GL_NV_memory_attachment 1
	#define GL_NV_mesh_shader 1
	#define GL_NV_occlusion_query 1
	#define GL_NV_parameter_buffer_object 1
	#define GL_NV_path_rendering 1
	#define GL_NV_pixel_data_range 1
	#define GL_NV_point_sprite 1
	#define GL_NV_present_video 1
	#define GL_NV_query_resource 1
	#define GL_NV_query_resource_tag 1
	#define GL_NV_register_combiners 1
	#define GL_NV_register_combiners2 1
	#define GL_NV_sample_locations 1
	#define GL_NV_scissor_exclusive 1
	#define GL_NV_shader_buffer_load 1
	#define GL_NV_shading_rate_image 1
	#define GL_NV_texture_multisample 1
	#define GL_NV_transform_feedback 1
	#define GL_NV_transform_feedback2 1
	#define GL_NV_vdpau_interop 1
	#define GL_NV_vdpau_interop2 1
	#define GL_NV_vertex_array_range 1
	#define GL_NV_vertex_attrib_integer_64bit 1
	#define GL_NV_vertex_buffer_unified_memory 1
	#define GL_NV_vertex_program 1
	#define GL_NV_video_capture 1
	#define GL_NV_viewport_swizzle 1
	#define GL_OES_byte_coordinates 1
	#define GL_OES_fixed_point 1
	#define GL_OES_query_matrix 1
	#define GL_OES_single_precision 1
	#define GL_OVR_multiview 1
	#define GL_PGI_misc_hints 1
	#define GL_SGIS_detail_texture 1
	#define GL_SGIS_fog_function 1
	#define GL_SGIS_multisample 1
	#define GL_SGIS_pixel_texture 1
	#define GL_SGIS_point_parameters 1
	#define GL_SGIS_sharpen_texture 1
	#define GL_SGIS_texture4D 1
	#define GL_SGIS_texture_color_mask 1
	#define GL_SGIS_texture_filter4 1
	#define GL_SGIX_async 1
	#define GL_SGIX_flush_raster 1
	#define GL_SGIX_fragment_lighting 1
	#define GL_SGIX_framezoom 1
	#define GL_SGIX_igloo_interface 1
	#define GL_SGIX_instruments 1
	#define GL_SGIX_list_priority 1
	#define GL_SGIX_pixel_texture 1
	#define GL_SGIX_polynomial_ffd 1
	#define GL_SGIX_reference_plane 1
	#define GL_SGIX_sprite 1
	#define GL_SGIX_tag_sample_buffer 1
	#define GL_SGI_color_table 1
	#define GL_SUNX_constant_data 1
	#define GL_SUN_global_alpha 1
	#define GL_SUN_mesh_array 1
	#define GL_SUN_triangle_list 1
	#define GL_SUN_vertex 1

	#define WGL_3DL_stereo_control 1
	#define WGL_EXT_display_color_table 1
	#define WGL_EXT_make_current_read 1
	#define WGL_EXT_pbuffer 1
	#define WGL_EXT_pixel_format 1
	#define WGL_I3D_digital_video_control 1
	#define WGL_I3D_gamma 1
	#define WGL_I3D_image_buffer 1
	#define WGL_I3D_swap_frame_lock 1
	#define WGL_I3D_swap_frame_usage 1
	#define WGL_NV_copy_image 1
	#define WGL_NV_delay_before_swap 1
	#define WGL_NV_gpu_affinity 1
	#define WGL_NV_present_video 1
	#define WGL_NV_vertex_array_range 1
	#define WGL_NV_video_capture 1
	#define WGL_NV_video_output 1
	#define WGL_OML_sync_control 1
#endif
#include "khrplatform.h"
#include "GL_GET_FUNCTIONS.h"
#include "WGL_GET_FUNCTIONS.h"

#define GLFW_INCLUDE_NONE

#include "glfw/include/GLFW/glfw3.h"


//#include "wgl+wglext.h"
//#include "WGlGetFunctions.h"

struct matrix_block {
	mat4     M;
	mat4     V;
	mat4     P;
	mat4     MV;
	mat4     MVP;
};

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "Imagem004.lib")
#pragma comment(lib, "glfw.lib")


