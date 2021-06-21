#pragma warning(disable:4018)
#include "pch.h"
#include "WindowsOpengl.h"
#include "resource.h"
#include "manager.h"
#include "Utils.h"

GLContextStruct ctx;

int bQuit = false;
float theta = 0;
char limit = 1;

pKeyMap keymap = new KeyMap;

Word word;

objeto* plane;
objeto* skyBox;
texto* txt;
GLuint hdrTextures[10];
cTimer t;

frameBuffer* fbo;

char szTitle[128] = "Test Opengl 01\0";

int main(int argc, char* argv[]) {
	t.setTimer("main");
	startOpengl();
	t.setTimer("startOpengl");

	vec3 pos(0, 4, 0);
	for (int i = 1; i < objType::objGrid; i ++) {
		word.addObj(objType(i), rotateZDeg(pos, 45.f*(i-1.f)), vec3(0, 0, 0), vec3(1), uivec3(40, 20, 10), "DiffSpecNormalDisp");
	}

	word.addObj(objType::objQuad, vec3(0,0,-1.1), vec3(0), vec3(40), uivec3(60, 60, 10), "DiffSpecNormalDisp");
	word.addObj(objType::objSkyBox, vec3(0, 0, 0), vec3(0, 0, 0), vec3(4), uivec3(10, 10, 10), "SphericalCubeMap");
	word.addObj(objType::objAxis, vec3(1, 0, 0), vec3(0, 0, 0), vec3(1), uivec3(10, 10, 10), "lineVertexColor");
	word.addObj(objType::objCapsule, vec3(7, 0, 0), vec3(0, 0, 0), vec3(1), uivec3(100, 100, 10), "DiffSpecNormalDisp");
	word.addObj(objType::objGrid, vec3(0, 0, 0), vec3(0, 0, 0), vec3(2), uivec3(10, 10, 10),"lineVertexColor");
	word.addObj(objType::objAxis, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1), uivec3(10, 10, 10), "lineVertexColor");
	//skyBox = new objeto(0, objType::objSkyBox, vec3(0, 0, 0), vec3(0, 0, 0), vec3(4), uivec3(10, 10, 10), "SphericalCubeMap.mat");
	plane = new objeto(0, objType::objQuad, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1), uivec3(50, 50, 10), "screen");
	plane->atach();

	txt = new texto("abcdefghijklmnopqrstuvwxyz ,.;/\\[]{}´`=+-_()!¹²³£¢¬@#$%¨&*'\"+-*/asdasdkhj	bfksdhgfgh	diasghfh hgfhjksdghfhj \ndhgadesfghadshfshg\nfsdfsd	asd\ndfsdfdsgdsgsdg)");
	t.setTimer("create objs");

	ShowWindow(ctx.hwnd, 1);
	MSG msg;
	t.setTimer("ShowWindow");

	while (!bQuit) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			/* handle or dispatch messages */
			if (msg.message == WM_QUIT) {
				bQuit = TRUE;
			}
			else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			t.setTimer("PeekMessage");
		}
		else {
			t.setTimer("wasted");
			ZeroMemory(keymap, sizeof(KeyMap));
			t.setTimer("ZeroMemory");
			processKeyPress(keymap);
			t.setTimer("processKeyPress");
			onRenderScene();
			t.setTimer("onRenderScene");
			glFinish();
			t.setTimer("glFinish");
			SwapBuffers(ctx.hdc);
			t.setTimer("SwapBuffers");
			t.setFrameEnd();
			float fps = t.getMedianFPS(60);
			sprintf(szTitle, "FPS: %2.2f - Test Opengl 01", fps);
			SetWindowText(ctx.hwnd, szTitle);
			if (limit) {
				float ms = 0;
				while ((ms = t.getFrameMS()) <= 13.0f)
					Sleep(1);
			}
			t.setTimer("sleeped");
			word.frame++;
			word.time += vec4(t.getFrameMS(), t.getFrameMS() / 10.f, t.getFrameMS() / 100.f, t.getFrameMS() / 1000.f);
			word.sintime = vec4(sin(word.time.x), sin(word.time.y), sin(word.time.z), sin(word.time.w));
			word.costime = vec4(cos(word.time.x), cos(word.time.y), cos(word.time.z), cos(word.time.w));
			t.setFrameStart();
			t.setTimer("setFrameStart");
		}
	}
	delete keymap;
	wglMakeCurrent(ctx.hdc, NULL);
	wglDeleteContext(ctx.hglrc);
	ReleaseDC(ctx.hwnd, ctx.hdc);
	DestroyWindow(ctx.hwnd);

	//system("pause");
	//return msg.wParam;
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	static int cxClient=1, cyClient=1, lcxClient=1, lcyClient=1, iDeltaPerLine = 120, iAccumDelta=0;
	ULONG ulScrollLines = 1;
	static int xres=1, yres=1;
	static int xWindow=0, yWindow=0;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rc;
	ZeroMemory(keymap, sizeof(KeyMap));

	switch (Message) {
		case WM_CREATE:
		{
			printf("WM_CREATE\n");
			break;
		}
		case WM_NULL:
		{
			printf("WM_NULL\n");
		}
		case WM_SIZE:
		{
			GetWindowRect(hwnd, &rc);
			onResize(LOWORD(lParam), HIWORD(lParam), wParam, lParam);
			break;
		}
		case WM_MOVE:
		{
			onMove(LOWORD(lParam), HIWORD(lParam), wParam, lParam);
			break;
		}
		case WM_MOUSEMOVE:
		{
			GetAsyncKeyState(VK_LBUTTON);
			GetAsyncKeyState(VK_MBUTTON);
			onMouseMove(LOWORD(lParam), HIWORD(lParam), wParam, lParam, LOWORD(lParam)- xWindow, HIWORD(lParam)- yWindow);
			xWindow = LOWORD(lParam), yWindow = HIWORD(lParam);
			break;
		}
		//case WM_LBUTTONDOWN:
		//{
		//	onMousePress(LOWORD(lParam), HIWORD(lParam), lParam, lParam, false, 1);
		//	return 0;
		//}
		//case WM_MBUTTONDOWN:
		//{
		//	onMousePress(LOWORD(lParam), HIWORD(lParam), lParam, lParam, false, 2);
		//	return 0;
		//}
		//case WM_RBUTTONDOWN:
		//{
		//	onMousePress(LOWORD(lParam), HIWORD(lParam), lParam, lParam, false, 3);
		//	return 0;
		//}
		//case WM_LBUTTONUP:
		//{
		//	onMousePress(LOWORD(lParam), HIWORD(lParam), lParam, lParam, true, 1);
		//	return 0;
		//}
		//case WM_MBUTTONUP:
		//{
		//	onMousePress(LOWORD(lParam), HIWORD(lParam), lParam, lParam, true, 2);
		//	return 0;
		//}
		//case WM_RBUTTONUP:
		//{
		//	onMousePress(LOWORD(lParam), HIWORD(lParam), lParam, lParam, true, 3);
		//	return 0;
		//}
		//case WM_KEYDOWN:
		//	if ((GetAsyncKeyState(VK_ESCAPE) & 0x01) && bRunning) {
		//		Stop();
		//	}
		//	break;
		//}
		//case WM_KEYDOWN:
		//{
		//	return 0;
		//	printf("WM_KEYDOWN\n");
		//	decodeKeyPress(wParam, wParam, lParam, keymap, Message);
		//}
		//case WM_KEYUP:
		//{
		//	return 0;
		//	printf("WM_KEYUP\n");
		//	decodeKeyPress(wParam, wParam, lParam, keymap, Message);
		//}
		////case WM_CHAR:
		////{
		////printf("WM_CHAR\n");
		////	pKeyMap keymap = new KeyMap;
		////	decodeKeyPress(wParam, wParam, lParam, keymap, Message);
		////	delete keymap;
		////	return 0;
		////}
		////case WM_DEADCHAR:
		////{
		////printf("WM_DEADCHAR\n");
		////	pKeyMap keymap = new KeyMap;
		////	decodeKeyPress(wParam, wParam, lParam, keymap, Message);
		////	delete keymap;
		////	return 0;
		////}
		//case WM_SYSKEYDOWN:
		//{
		//	return 0;
		//	printf("WM_SYSKEYDOWN\n");
		//	decodeKeyPress(wParam, wParam, lParam, keymap, Message);
		//}
		//case WM_SYSKEYUP:
		//{
		//	return 0;
		//	printf("WM_SYSKEYUP\n");
		//	decodeKeyPress(wParam, wParam, lParam, keymap, Message);
		//}
		//case WM_SYSCHAR:
		//{
		//	return 0;
		//	printf("WM_SYSCHAR\n");
		//	decodeKeyPress(wParam, wParam, lParam, keymap, Message);
		//}
		//case WM_SYSDEADCHAR:
		//{
		//	return 0;
		//	printf("WM_SYSDEADCHAR\n");
		//	decodeKeyPress(wParam, wParam, lParam, keymap, Message);
		//}
		case WM_MOUSEWHEEL:
		{
			if (iDeltaPerLine == 0)
				break;
			iAccumDelta += (short)HIWORD(wParam); // 120 or -120
			while (iAccumDelta >= iDeltaPerLine) {
				onMouseWhell(1, wParam, lParam);
				iAccumDelta -= iDeltaPerLine;
			}
			while (iAccumDelta <= -iDeltaPerLine) {
				onMouseWhell(-1, wParam, lParam);
				iAccumDelta += iDeltaPerLine;
			}
			break;
		}
		case WM_PAINT:
		{
			hdc = BeginPaint(hwnd, &ps);
			onPaint(&ps, wParam, lParam);
			EndPaint(hwnd, &ps);
			SwapBuffers(ctx.hdc);
			return 0;
		}
		case WM_SETTINGCHANGE:
		{
			printf("WM_SETTINGCHANGE\n");
			SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &ulScrollLines, 0);
			// ulScrollLines usually equals 3 or 0 (for no scrolling)
			// WHEEL_DELTA equals 120, so iDeltaPerLine will be 40
			if (ulScrollLines)
				iDeltaPerLine = WHEEL_DELTA / ulScrollLines;
			else
				iDeltaPerLine = 0;
			break;
		}
		case WM_CLOSE:
		{
			printf("WM_CLOSE\n");
			DestroyWindow(hwnd);
			break;
		}
		case WM_DESTROY:
		{
			printf("WM_DESTROY\n");
			PostQuitMessage(0);
			break;
		}
		case WM_COMMAND:
		{
			switch (LOWORD(wParam)) {
				case 0:
				{
					PostMessage(hwnd, WM_CLOSE, 0, 0);
					break;
				}
			}
			break;
		}
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int startOpengl() {

	ctx.sx = 696 + 16;
	ctx.sy = 696 + 39;
	//byte a[712- 696][735- 696]; //696:696 16,39
	ZeroMemory(&ctx.wc, sizeof(WNDCLASS));
	ctx.wc.hInstance = GetModuleHandle(NULL);
	ctx.wc.lpfnWndProc = WndProc;
	ctx.wc.lpszClassName = "TestOpengl_01";
	ctx.wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	ctx.wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.style = CS_HREDRAW | CS_VREDRAW;
	ctx.wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	if (0 == RegisterClass(&ctx.wc)) return GL_TRUE;
	/* create window */
	ctx.hwnd = CreateWindow("TestOpengl_01", szTitle,
							WS_OVERLAPPEDWINDOW,
							661, 0, ctx.sx, ctx.sy,
							NULL, NULL, NULL, NULL);

	/* get the device context */
	ctx.hdc = GetDC(ctx.hwnd);
	// WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL

	/* find pixel format */

	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 8;
	pfd.iLayerType = PFD_MAIN_PLANE;
	int visual = ChoosePixelFormat(ctx.hdc, &pfd);
	/* set the pixel format for the dc */
	//SetPixelFormat(ctx.hdc, visual, &pfd);
	SetPixelFormat(ctx.hdc, visual, &pfd); // it is a hack, so i know that this number 80 activate the 4x AntiAlias on my computer
	/* create rendering context */
	ctx.hglrc = wglCreateContext(ctx.hdc);
	wglMakeCurrent(ctx.hdc, ctx.hglrc);
	LoadOGL();
	LoadWGL();

	printf(wglGetExtensionsStringARB(ctx.hdc));

	int attributes[] = {
	  WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
	  WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
	  WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
	  WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
	  WGL_COLOR_BITS_ARB, 32,
	  WGL_DEPTH_BITS_ARB, 24,
	  WGL_STENCIL_BITS_ARB, 8,
	  WGL_SAMPLE_BUFFERS_ARB, 1, // Number of buffers (must be 1 at time of writing)
	  WGL_SAMPLES_ARB, 4,        // Number of samples
	  0
	};

	int attrib[] = { WGL_NUMBER_PIXEL_FORMATS_ARB };
	int nResults[1] = { 0 };
	int pixFmt = 1;
	wglGetPixelFormatAttribivARB(ctx.hdc, pixFmt, 0, 1, attrib, nResults);

	GLint pfAttribCount[] = { WGL_NUMBER_PIXEL_FORMATS_ARB };
	//GLint pfAttribList[] = { 
	//	WGL_DRAW_TO_WINDOW_ARB, 
	//	WGL_ACCELERATION_ARB,
	//	WGL_SUPPORT_OPENGL_ARB, 
	//	WGL_DOUBLE_BUFFER_ARB, 
	//	WGL_DEPTH_BITS_ARB, 
	//	WGL_STENCIL_BITS_ARB, 
	//	WGL_RED_BITS_ARB, 
	//	WGL_GREEN_BITS_ARB, 
	//	WGL_BLUE_BITS_ARB, 
	//	WGL_ALPHA_BITS_ARB 
	// };
	GLint pfAttribList[] = {
		//WGL_NUMBER_PIXEL_FORMATS_ARB,
		//WGL_SUPPORT_OPENGL_ARB,
		//WGL_DOUBLE_BUFFER_ARB,
		//WGL_DRAW_TO_WINDOW_ARB,
		//WGL_DRAW_TO_BITMAP_ARB,
		//WGL_ACCELERATION_ARB,
		//WGL_NUMBER_OVERLAYS_ARB,
		//WGL_NUMBER_UNDERLAYS_ARB,
		//WGL_TRANSPARENT_ARB,
		//WGL_STEREO_ARB,
		//WGL_COLOR_BITS_ARB,
		//WGL_RED_BITS_ARB,
		//WGL_RED_SHIFT_ARB,
		//WGL_GREEN_BITS_ARB,
		//WGL_GREEN_SHIFT_ARB,
		//WGL_BLUE_BITS_ARB,
		//WGL_BLUE_SHIFT_ARB,
		//WGL_ALPHA_BITS_ARB,
		//WGL_ALPHA_SHIFT_ARB,
		//WGL_ACCUM_BITS_ARB,
		//WGL_ACCUM_RED_BITS_ARB,
		//WGL_ACCUM_GREEN_BITS_ARB,
		//WGL_ACCUM_BLUE_BITS_ARB,
		//WGL_ACCUM_ALPHA_BITS_ARB,
		//WGL_DEPTH_BITS_ARB,
		//WGL_STENCIL_BITS_ARB,
		//WGL_SHARE_DEPTH_ARB,
		//WGL_SHARE_STENCIL_ARB,
		//WGL_SHARE_ACCUM_ARB,
		//WGL_PIXEL_TYPE_ARB,
		//WGL_TRANSPARENT_RED_VALUE_ARB,
		//WGL_TRANSPARENT_GREEN_VALUE_ARB,
		//WGL_TRANSPARENT_BLUE_VALUE_ARB,
		//WGL_TRANSPARENT_ALPHA_VALUE_ARB,
		//WGL_TRANSPARENT_INDEX_VALUE_ARB,
		//WGL_NEED_PALETTE_ARB,
		//WGL_NEED_SYSTEM_PALETTE_ARB,
		//WGL_SWAP_LAYER_BUFFERS_ARB,
		//WGL_SWAP_METHOD_ARB,
		//WGL_SUPPORT_GDI_ARB,
		//WGL_AUX_BUFFERS_ARB,
		//WGL_SAMPLES_ARB

			WGL_SUPPORT_OPENGL_ARB,
			WGL_SUPPORT_GDI_ARB,
			WGL_DOUBLE_BUFFER_ARB,
			WGL_DRAW_TO_WINDOW_ARB,
			WGL_DRAW_TO_BITMAP_ARB,
			WGL_SWAP_METHOD_ARB,
			WGL_PIXEL_TYPE_ARB,
			WGL_AUX_BUFFERS_ARB,
			WGL_COLOR_BITS_ARB,
			WGL_DEPTH_BITS_ARB,
			WGL_STENCIL_BITS_ARB,
			WGL_RED_BITS_ARB,
			WGL_GREEN_BITS_ARB,
			WGL_BLUE_BITS_ARB,
			WGL_ALPHA_BITS_ARB,
			WGL_ACCUM_BITS_ARB,
			WGL_ACCUM_RED_BITS_ARB,
			WGL_ACCUM_GREEN_BITS_ARB,
			WGL_ACCUM_BLUE_BITS_ARB,
			WGL_ACCUM_ALPHA_BITS_ARB,
			WGL_SAMPLES_ARB,
	};

	FILE* LogPixelFormat = fopen("LogPixelFormat.py", "wb");

	int nPixelFormatCount = 0;
	wglGetPixelFormatAttribivARB(ctx.hdc, 1, 0, 1, pfAttribCount, &nPixelFormatCount);
	for (int i = 1; i < nPixelFormatCount; i++) {
		GLint results[21];
		fprintf(LogPixelFormat, "\nPixel format %d details:\n", i);
		wglGetPixelFormatAttribivARB(ctx.hdc, i, 0, 21, pfAttribList, results);
		//printf(" Draw to Window = %x:\n", results[0]); 
		//printf(" HW Accelerated = %x:\n", results[1]); 
		//printf(" Supports OpenGL = %x:\n", results[2]); 
		//printf(" Double Buffered = %x:\n", results[3]); 
		//printf(" Depth Bits = %x:\n", results[4]); 
		//printf(" Stencil Bits = %x:\n", results[5]); 
		//printf(" Red Bits = %x:\n", results[6]); 
		//printf(" Green Bits = %x:\n", results[7]); 
		//printf(" Blue Bits = %x:\n", results[8]); 
		//printf(" Alpha Bits = %x:\n", results[9]);

		//fprintf(LogPixelFormat, " WGL_NUMBER_PIXEL_FORMATS_ARB = %x:\n", results[0]);
		fprintf(LogPixelFormat, " WGL_SUPPORT_OPENGL_ARB = %d:\n", results[0]);
		fprintf(LogPixelFormat, " WGL_SUPPORT_GDI_ARB = %d:\n", results[1]);
		fprintf(LogPixelFormat, " WGL_DOUBLE_BUFFER_ARB = %d:\n", results[2]);
		fprintf(LogPixelFormat, " WGL_DRAW_TO_WINDOW_ARB = %d:\n", results[3]);
		fprintf(LogPixelFormat, " WGL_DRAW_TO_BITMAP_ARB = %d:\n", results[4]);
		fprintf(LogPixelFormat, " WGL_SWAP_METHOD_ARB = 0x%x:\n", results[5]);
		fprintf(LogPixelFormat, " WGL_PIXEL_TYPE_ARB = 0x%x:\n", results[6]);
		fprintf(LogPixelFormat, " WGL_SAMPLES_ARB = %d:\n", results[20]);
		fprintf(LogPixelFormat, " WGL_AUX_BUFFERS_ARB = %d:\n", results[7]);
		fprintf(LogPixelFormat, " WGL_COLOR_BITS_ARB = %d:\n", results[8]);
		fprintf(LogPixelFormat, " WGL_DEPTH_BITS_ARB = %d:\n", results[9]);
		fprintf(LogPixelFormat, " WGL_STENCIL_BITS_ARB = %d:\n", results[10]);
		fprintf(LogPixelFormat, " WGL_RED_BITS_ARB = %d:\n", results[11]);
		fprintf(LogPixelFormat, " WGL_GREEN_BITS_ARB = %d:\n", results[12]);
		fprintf(LogPixelFormat, " WGL_BLUE_BITS_ARB = %d:\n", results[13]);
		fprintf(LogPixelFormat, " WGL_ALPHA_BITS_ARB = %d:\n", results[14]);
		fprintf(LogPixelFormat, " WGL_ACCUM_BITS_ARB = %d:\n", results[15]);
		fprintf(LogPixelFormat, " WGL_ACCUM_RED_BITS_ARB = %d:\n", results[16]);
		fprintf(LogPixelFormat, " WGL_ACCUM_GREEN_BITS_ARB = %d:\n", results[17]);
		fprintf(LogPixelFormat, " WGL_ACCUM_BLUE_BITS_ARB = %d:\n", results[18]);
		fprintf(LogPixelFormat, " WGL_ACCUM_ALPHA_BITS_ARB = %d:\n", results[19]);
		//fprintf(LogPixelFormat, " WGL_RED_SHIFT_ARB = %d:\n", results[12]);
		//fprintf(LogPixelFormat, " WGL_GREEN_SHIFT_ARB = %d:\n", results[14]);
		//fprintf(LogPixelFormat, " WGL_BLUE_SHIFT_ARB = %d:\n", results[16]);
		//fprintf(LogPixelFormat, " WGL_ALPHA_SHIFT_ARB = %d:\n", results[18]);
		//fprintf(LogPixelFormat, " WGL_ACCELERATION_ARB = %x:\n", results[5]);
		//fprintf(LogPixelFormat, " WGL_NUMBER_OVERLAYS_ARB = %x:\n", results[6]);
		//fprintf(LogPixelFormat, " WGL_NUMBER_UNDERLAYS_ARB = %x:\n", results[7]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_ARB = %x:\n", results[8]);
		//fprintf(LogPixelFormat, " WGL_STEREO_ARB = %x:\n", results[9]);
		//fprintf(LogPixelFormat, " WGL_SHARE_DEPTH_ARB = %x:\n", results[26]);
		//fprintf(LogPixelFormat, " WGL_SHARE_STENCIL_ARB = %x:\n", results[27]);
		//fprintf(LogPixelFormat, " WGL_SHARE_ACCUM_ARB = %x:\n", results[28]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_RED_VALUE_ARB = %x:\n", results[30]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_GREEN_VALUE_ARB = %x:\n", results[31]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_BLUE_VALUE_ARB = %x:\n", results[32]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_ALPHA_VALUE_ARB = %x:\n", results[33]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_INDEX_VALUE_ARB = %x:\n", results[34]);
		//fprintf(LogPixelFormat, " WGL_NEED_PALETTE_ARB = %x:\n", results[35]);
		//fprintf(LogPixelFormat, " WGL_NEED_SYSTEM_PALETTE_ARB = %x:\n", results[36]);
		//fprintf(LogPixelFormat, " WGL_SWAP_LAYER_BUFFERS_ARB = %x:\n", results[37]);
	}
	fprintf(LogPixelFormat, "\n\n\n\n");

	fclose(LogPixelFormat);

	fbo = new frameBuffer(1, uivec2(100, 60) * 10);
	return 1;
}

void processKeyPress(pKeyMap keymap) {
	keymap->lshift = GetKeyState(VK_LSHIFT) & 0x8000 ? 1 : 0;
	keymap->rshift = GetKeyState(VK_RSHIFT) & 0x8000 ? 1 : 0;
	keymap->lctrl = GetAsyncKeyState(VK_LCONTROL) & 0x8000 ? 1 : 0;
	keymap->rctrl = GetAsyncKeyState(VK_RCONTROL) & 0x8000 ? 1 : 0;
	keymap->lalt = GetAsyncKeyState(VK_LMENU) & 0x8000 ? 1 : 0;
	keymap->ralt = GetAsyncKeyState(VK_RMENU) & 0x8000 ? 1 : 0;
	keymap->alt = keymap->lalt & 0x8000 ? 1 : 0 || keymap->ralt & 0x8000 ? 1 : 0 || GetAsyncKeyState(VK_MENU) & 0x8000 ? 1 : 0;

	keymap->space = GetAsyncKeyState(VK_SPACE);
	keymap->win = GetAsyncKeyState(VK_LWIN) || GetAsyncKeyState(VK_RWIN);
	keymap->capsl = GetAsyncKeyState(VK_CAPITAL);
	keymap->numl = GetAsyncKeyState(VK_NUMLOCK);
	keymap->scroll = GetAsyncKeyState(VK_SCROLL);
	keymap->up = 0;
	keymap->down = 0;

	WPARAM wParam = 0;

	if (GetAsyncKeyState(VK_DELETE)) {
		cls();
	}
	if (GetAsyncKeyState(VK_SUBTRACT)) {
		activecamera->fov -= 0.01f;
		//activecamera->fov = clamp(activecamera->fov - 0.01f, 0.0001f, 3.14f);

	}
	if (GetAsyncKeyState(VK_ADD)) {
		activecamera->fov += 0.01f;
		//activecamera->fov = clamp(activecamera->fov + 0.01f, 0.0001f, 3.14f);
	}
	if (GetAsyncKeyState(VK_UP)) {
		activecamera->grot.y -= 0.05f;
		//activecamera->rotate(vec3(0,0.05f,0));
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		activecamera->grot.y += 0.05f;
		//activecamera->rotate(vec3(0, -0.05f, 0));
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		activecamera->grot.x += 0.05f;
		//activecamera->rotate(vec3(0, 0, 0.05f));
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		activecamera->grot.x -= 0.05f;
		//activecamera->rotate(vec3(0, 0, -0.05f));
	}
		activecamera->calcMatrix();
	if (GetAsyncKeyState(0x51)) { // Q
		//torus->grot.y  -= 0.05f;
		//esfera->grot.y -= 0.05f;
		//torus->grot.w  -= 0.05f;
		//esfera->grot.w -= 0.05f;
	}
	if (GetAsyncKeyState(0x45)) { // E		 
		//torus->grot.y  += 0.05f;
		//esfera->grot.y += 0.05f;
		//torus->grot.w  += 0.05f;
		//esfera->grot.w += 0.05f;
	}
	if (GetAsyncKeyState(0x52)) { // R
		//torus->grot  = vec4(0, 0, 0.00000001f, 0.0003333);
		//esfera->grot = vec4(0, 0, 0.00000001f, 0.000333);
	}
	if (GetAsyncKeyState(0x57)) { // W
		//torus->grot.x  += 0.05f;
		//esfera->grot.x += 0.05f;
		//torus->grot.w  += 0.05f;
		//esfera->grot.w += 0.05f;
		if (keymap->lshift || keymap->rshift)
			activecamera->moveF(16 * 4);
		else if (keymap->lctrl || keymap->rctrl)
			activecamera->moveF(16 / 4);
		else
			activecamera->moveF(16);
	}
	if (GetAsyncKeyState(0x53)) { // S		 
		//torus->grot.x  -= 0.05f;
		//esfera->grot.x -= 0.05f;
		//torus->grot.w  -= 0.05f;
		//esfera->grot.w -= 0.05f;
		if (keymap->lshift || keymap->rshift)
			activecamera->moveB(16 * 4);
		else if (keymap->lctrl || keymap->rctrl)
			activecamera->moveB(16 / 4);
		else
			activecamera->moveB(16);
	}
	if (GetAsyncKeyState(0x41)) { // A		  
		//torus->grot.z   += 0.05f;
		//esfera->grot.z  += 0.05f;
		//torus->grot.w   += 0.05f;
		//esfera->grot.w  += 0.05f;
		if (keymap->lshift || keymap->rshift)
			activecamera->moveL(16 * 4);
		else if (keymap->lctrl || keymap->rctrl)
			activecamera->moveL(16 / 4);
		else
			activecamera->moveL(16);
	}
	if (GetAsyncKeyState(0x44)) { // D		  
		//torus->grot.z  -= 0.05f;
		//esfera->grot.z -= 0.05f;
		//torus->grot.w  -= 0.05f;
		//esfera->grot.w -= 0.05f;
		if (keymap->lshift || keymap->rshift)
			activecamera->moveR(16 * 4);
		else if (keymap->lctrl || keymap->rctrl)
			activecamera->moveR(16 / 4);
		else
			activecamera->moveR(16);
	}
	if (GetAsyncKeyState(VK_SPACE)) {
		//torus->malhas[0]->mMaterial->detach();
		//esfera->malhas[0]->mMaterial->detach();
		//torus->malhas[0]->mMaterial = new material("default");
		//esfera->malhas[0]->mMaterial = new material("default");
		//torus->malhas[0]->mMaterial->read(torus->malhas[0]->mMaterial->mName);
		//cube->malhas[0]->mMaterial->read(torus->malhas[0]->mMaterial->mName);
		//esfera->malhas[0]->mMaterial->read(esfera->malhas[0]->mMaterial->mName);
		//grid->malhas[0]->mMaterial->read(grid->malhas[0]->mMaterial->mName);
		//axis->malhas[0]->mMaterial->read(axis->malhas[0]->mMaterial->mName);
		//plane->malhas[0]->mMaterial->mData->mShader->readSrcFromFilenames();
		word.refreshShaders();
		printf("Material Reloaded\n\n");
	}
}

void onRenderScene() {
	glEnable(GL_CULL_FACE);
	glDisable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	//glEnable(GL_MULTISAMPLE_ARB);
	//glDisable(GL_MULTISAMPLE_ARB);
	glClearColor(0.2f, 0.2f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	fbo->bind();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);

	glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
	glBindTexture(GL_TEXTURE_2D, hdrTextures[0]);
	glLineWidth(1.f);


	glLineWidth(1.0f);
	//glLineWidth(2.0f);
	glDepthFunc(GL_LEQUAL);
	word.draw();
	//glDisable(GL_DEPTH_WRITEMASK);
	//glDepthMask(0);
	//skyBox->draw();
	//glEnable(GL_DEPTH_WRITEMASK);
	//glDepthMask(1);

	fbo->unbind();
	activecamera->aspect = max(float(ctx.sx), 1.0f) / max(float(ctx.sy), 1.0f);
	activecamera->calcMatrix();
	glEnable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, fbo->textures[0]);
	//if (plane->malhas[0]->mMaterial->mData->mTextures[0]->mData)
	//	plane->malhas[0]->mMaterial->mData->mTextures[0]->mData->globj = fbo->textures[0];
	//else {
	//	plane->malhas[0]->mMaterial->mData->mTextures[0]->mData = new TextureData;
	//	plane->malhas[0]->mMaterial->mData->mTextures[0]->mData->globj = fbo->textures[0];
	//}
	plane->draw();
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("time", word.time);
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("frame", word.frame);
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("sintime", word.sintime);
	plane->malhas[0]->mMaterial->mData->mShader->setUniform("costime", word.costime);
}

void onRenderScene2() {
	glEnable(GL_MULTISAMPLE_ARB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(theta, 0.5f, -1.5f, 0.0f);
	//glBegin (GL_TRIANGLES);
	//	glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (0.0f, 1.0f, 1.0f);
	//	glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (0.87f, -0.5f, -0.5f);
	//	glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (-0.87f, -0.5f, -0.5f);
	//glEnd ();
	glPopMatrix();
	glDisable(GL_DEPTH_TEST);
	drawText("abcdefghijklmnopqrstuvwxyz\n", vec2(-1.f, 1.f), vec2(1.f, 1.f), vec4(1.f, 1.f, 1.f, 1.f), vec2(0.f, 0.f));
	glEnable(GL_DEPTH_TEST);

	theta -= 0.1f;

}

void onResize(int x, int y, WPARAM wParam, LPARAM lParam) {
	activecamera->aspect = max(float(x), 1.0f) / max(float(y), 1.0f);
	printf("aspect:%f\n", activecamera->aspect);
	ctx.sx = x;
	ctx.sy = y;
	fbo->resize(uivec2(x,y)/**1.25f*/);
	glViewport(0, 0, x, y);
	onRenderScene();
	SwapBuffers(ctx.hdc);
	printf("WM_SIZE: %i:%i\n", x, y);
}

void onMove(int x, int y, WPARAM wParam, LPARAM lParam) {
	//printf("WM_MOVE\n");
}

void onPaint(PAINTSTRUCT* rc, WPARAM wParam, LPARAM lParam) {
	//printf("WM_PAINT\n");
	onRenderScene();
}

void onMouseWhell(int val, WPARAM wParam, LPARAM lParam) {
	if (val > 0) {
		activecamera->fov += 0.01f;
	}
	else if (val < 0) {
		activecamera->fov -= 0.01f;
	}
	activecamera->calcMatrix();
	//printf("WM_MOUSEWHEEL %f\n", activecamera->fov);
}

void onMouseMove(int xWindow, int yWindow, WPARAM wParam, LPARAM lParam, int x, int y) {
	//printf("mousemove: x=%i y=%i w=%i l=%i\n", x, y, wParam, lParam);
	if (GetAsyncKeyState(VK_LBUTTON)) {
		activecamera->grot.y -= y * 0.008f * (pow(activecamera->fov / F_PI, 2.f) + 0.0001f);
		activecamera->grot.y -= y * 0.008f * (pow(activecamera->fov / F_PI, 2.f) + 0.0001f);
		activecamera->grot.x += x * 0.008f * (pow(activecamera->fov / F_PI, 2.f) + 0.0001f);
		activecamera->grot.x += x * 0.008f * (pow(activecamera->fov / F_PI, 2.f) + 0.0001f);
		//printf("fov = %f\n",activecamera->fov);
		//activecamera->rotate(vec3(0, 0, -y * 0.005f));
		//activecamera->rotate(vec3(x * 0.005f, 0, 0));
	}
	if (GetAsyncKeyState(VK_MBUTTON)) {
		activecamera->fov -= x * 0.005f + y * 0.005f;
	}
}

void onComand(int cmd, WPARAM wParam, LPARAM lParam) {
	printf("WM_COMMAND\n");
}

void onMousePress(int x, int y, WPARAM wParam, LPARAM lParam, int up, int n) {

}

void cls() {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	// Get the number of character cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// Fill the entire screen with blanks.
	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
									(TCHAR)' ',      // Character to write to the buffer
									dwConSize,       // Number of cells to write
									coordScreen,     // Coordinates of first cell
									&cCharsWritten)) // Receive number of characters written
	{
		return;
	}
	// Get the current text attribute.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}
	// Set the buffer's attributes accordingly.
	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
									csbi.wAttributes, // Character attributes to use
									dwConSize,        // Number of cells to set attribute
									coordScreen,      // Coordinates of first cell
									&cCharsWritten))  // Receive number of characters written
	{
		return;
	}
	// Put the cursor at its home coordinates.
	SetConsoleCursorPosition(hConsole, coordScreen);
}


























