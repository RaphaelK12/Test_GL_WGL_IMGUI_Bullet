#pragma once

void decodeKeyPress(WPARAM key, WPARAM wParam, LPARAM lParam, pKeyMap keymap, UINT Message) {
	//char a[1000];
//printf("%i %i %i %i; %i %i %i %i %i; %i %i %i %i %i %i %i; \n", LOWORD (lParam), HIWORD (lParam),LOWORD (wParam), HIWORD (wParam), HIWORD (lParam)&0x01000000, HIWORD (lParam)&0x02000000, HIWORD (lParam)&0x04000000, HIWORD (lParam)&0x08000000, HIWORD (lParam)&0x10000000, GetKeyState (VK_SHIFT), GetKeyState (VK_LSHIFT), GetKeyState (VK_RSHIFT), GetKeyState (VK_LCONTROL), GetKeyState (VK_RCONTROL), GetKeyState (VK_LMENU), GetKeyState (VK_RMENU));
	//HIWORD (lParam)&0x02000000, HIWORD (lParam)&0x04000000, HIWORD (lParam)&0x08000000, HIWORD (lParam)&0x10000000);
//SetWindowTextA(hwnd, a);
	//keymap->up = (lParam & 0x80000000) >> 31;
	//keymap->down = !(lParam & 0x80000000) >> 31;
	//keymap->lalt = GetAsyncKeyState(VK_LMENU);
	//keymap->ralt = GetAsyncKeyState(VK_RMENU);
	//keymap->lctrl = GetAsyncKeyState(VK_LCONTROL);
	//keymap->lctrl = GetAsyncKeyState(VK_RCONTROL);
	//keymap->lshift = GetAsyncKeyState(VK_LSHIFT);
	//keymap->rshift = GetAsyncKeyState(VK_RSHIFT);
	////keymap->capsl = GetAsyncKeyState(VK_LMENU);
	////keymap->lalt = GetAsyncKeyState(VK_LMENU);
	return;
	if (wParam >= 0x30 && wParam <= 0x39)	// ASCII 0 - 9
		printf("* %c ", (int)wParam);
	else if (wParam >= 0x41 && wParam <= 0x5A)	// ASCII A - Z
		printf("* %c ", (int)wParam);
	else if (wParam >= 0x60 && wParam <= 0x69)	// NUMPAD 0 - 0
		printf("* NUMPAD %c ", (int)wParam - 0x30);
	else if (wParam >= 0x70 && wParam <= 0x87)	// NUMPAD 0 - 0
		printf("* F%llx ", (ulong)wParam - 0x6F);
	else
		switch (wParam) {
			case  VK_LBUTTON:	printf("VK_LBUTTON                      ");	break;
			case  VK_RBUTTON:	printf("VK_RBUTTON                      ");	break;
			case  VK_CANCEL:	printf("VK_CANCEL                       ");	break;
			case  VK_MBUTTON:	printf("VK_MBUTTON                      ");	break;
			case  VK_XBUTTON1:	printf("VK_XBUTTON1                     ");	break;
			case  VK_XBUTTON2:	printf("VK_XBUTTON2                     ");	break;
			case  VK_BACK:	printf("VK_BACK                         ");	break;
			case  VK_TAB:	printf("VK_TAB                          ");	break;
			case  VK_CLEAR:	printf("VK_CLEAR                        ");	break;
			case  VK_RETURN:	printf("VK_RETURN                       ");	break;
			case  VK_SHIFT:	printf("VK_SHIFT                        ");	break;
			case  VK_CONTROL:	printf("VK_CONTROL                      ");	break;
			case  VK_MENU:	printf("VK_MENU                         ");	break;
			case  VK_PAUSE:	printf("VK_PAUSE                        ");	break;
			case  VK_CAPITAL:	printf("VK_CAPITAL                      ");	break;
			case  VK_KANA:	printf("VK_KANA,VK_HANGEUL,VK_HANGUL    ");	break;
			case  VK_JUNJA:	printf("VK_JUNJA                        ");	break;
			case  VK_FINAL:	printf("VK_FINAL                        ");	break;
			case  VK_HANJA:	printf("VK_HANJA,VK_KANJI               ");	break;
			case  VK_ESCAPE:	printf("VK_ESCAPE                       ");	break;
			case  VK_CONVERT:	printf("VK_CONVERT                      ");	break;
			case  VK_NONCONVERT:	printf("VK_NONCONVERT                   ");	break;
			case  VK_ACCEPT:	printf("VK_ACCEPT                       ");	break;
			case  VK_MODECHANGE:	printf("VK_MODECHANGE                   ");	break;
			case  VK_SPACE:	printf("VK_SPACE                        ");	break;
			case  VK_PRIOR:	printf("VK_PRIOR                        ");	break;
			case  VK_NEXT:	printf("VK_NEXT                         ");	break;
			case  VK_END:	printf("VK_END                          ");	break;
			case  VK_HOME:	printf("VK_HOME                         ");	break;
			case  VK_LEFT:	printf("VK_LEFT                         ");	break;
			case  VK_UP:	printf("VK_UP                           ");	break;
			case  VK_RIGHT:	printf("VK_RIGHT                        ");	break;
			case  VK_DOWN:	printf("VK_DOWN                         ");	break;
			case  VK_SELECT:	printf("VK_SELECT                       ");	break;
			case  VK_PRINT:	printf("VK_PRINT                        ");	break;
			case  VK_EXECUTE:	printf("VK_EXECUTE                      ");	break;
			case  VK_SNAPSHOT:	printf("VK_SNAPSHOT                     ");	break;
			case  VK_INSERT:	printf("VK_INSERT                       ");	break;
			case  VK_DELETE:	printf("VK_DELETE                       ");	break;
			case  VK_HELP:	printf("VK_HELP                         ");	break;
			case  VK_LWIN:	printf("VK_LWIN                         ");	break;
			case  VK_RWIN:	printf("VK_RWIN                         ");	break;
			case  VK_APPS:	printf("VK_APPS                         ");	break;
			case  VK_SLEEP:	printf("VK_SLEEP                        ");	break;
			case  VK_MULTIPLY:	printf("VK_MULTIPLY                     ");	break;
			case  VK_ADD:	printf("VK_ADD                          ");	break;
			case  VK_SEPARATOR:	printf("VK_SEPARATOR                    ");	break;
			case  VK_SUBTRACT:	printf("VK_SUBTRACT                     ");	break;
			case  VK_DECIMAL:	printf("VK_DECIMAL                      ");	break;
			case  VK_DIVIDE:	printf("VK_DIVIDE                       ");	break;
			case  VK_NAVIGATION_VIEW:	printf("VK_NAVIGATION_VIEW              ");	break;
			case  VK_NAVIGATION_MENU:	printf("VK_NAVIGATION_MENU              ");	break;
			case  VK_NAVIGATION_UP:	printf("VK_NAVIGATION_UP                ");	break;
			case  VK_NAVIGATION_DOWN:	printf("VK_NAVIGATION_DOWN              ");	break;
			case  VK_NAVIGATION_LEFT:	printf("VK_NAVIGATION_LEFT              ");	break;
			case  VK_NAVIGATION_RIGHT:	printf("VK_NAVIGATION_RIGHT             ");	break;
			case  VK_NAVIGATION_ACCEPT:	printf("VK_NAVIGATION_ACCEPT            ");	break;
			case  VK_NAVIGATION_CANCEL:	printf("VK_NAVIGATION_CANCEL            ");	break;
			case  VK_NUMLOCK:	printf("VK_NUMLOCK                      ");	break;
			case  VK_SCROLL:	printf("VK_SCROLL                       ");	break;
			case  VK_OEM_NEC_EQUAL:	printf("VK_OEM_NEC_EQUAL,VK_OEM_FJ_JISHO");	break;
			case  VK_OEM_FJ_MASSHOU:	printf("VK_OEM_FJ_MASSHOU               ");	break;
			case  VK_OEM_FJ_TOUROKU:	printf("VK_OEM_FJ_TOUROKU               ");	break;
			case  VK_OEM_FJ_LOYA:	printf("VK_OEM_FJ_LOYA                  ");	break;
			case  VK_OEM_FJ_ROYA:	printf("VK_OEM_FJ_ROYA                  ");	break;
			case  VK_LSHIFT:	printf("VK_LSHIFT                       ");	break;
			case  VK_RSHIFT:	printf("VK_RSHIFT                       ");	break;
			case  VK_LCONTROL:	printf("VK_LCONTROL                     ");	break;
			case  VK_RCONTROL:	printf("VK_RCONTROL                     ");	break;
			case  VK_LMENU:	printf("VK_LMENU                        ");	break;
			case  VK_RMENU:	printf("VK_RMENU                        ");	break;
			case  VK_BROWSER_BACK:	printf("VK_BROWSER_BACK                 ");	break;
			case  VK_BROWSER_FORWARD:	printf("VK_BROWSER_FORWARD              ");	break;
			case  VK_BROWSER_REFRESH:	printf("VK_BROWSER_REFRESH              ");	break;
			case  VK_BROWSER_STOP:	printf("VK_BROWSER_STOP                 ");	break;
			case  VK_BROWSER_SEARCH:	printf("VK_BROWSER_SEARCH               ");	break;
			case  VK_BROWSER_FAVORITES:	printf("VK_BROWSER_FAVORITES            ");	break;
			case  VK_BROWSER_HOME:	printf("VK_BROWSER_HOME                 ");	break;
			case  VK_VOLUME_MUTE:	printf("VK_VOLUME_MUTE                  ");	break;
			case  VK_VOLUME_DOWN:	printf("VK_VOLUME_DOWN                  ");	break;
			case  VK_VOLUME_UP:	printf("VK_VOLUME_UP                    ");	break;
			case  VK_MEDIA_NEXT_TRACK:	printf("VK_MEDIA_NEXT_TRACK             ");	break;
			case  VK_MEDIA_PREV_TRACK:	printf("VK_MEDIA_PREV_TRACK             ");	break;
			case  VK_MEDIA_STOP:	printf("VK_MEDIA_STOP                   ");	break;
			case  VK_MEDIA_PLAY_PAUSE:	printf("VK_MEDIA_PLAY_PAUSE             ");	break;
			case  VK_LAUNCH_MAIL:	printf("VK_LAUNCH_MAIL                  ");	break;
			case  VK_LAUNCH_MEDIA_SELECT:	printf("VK_LAUNCH_MEDIA_SELECT          ");	break;
			case  VK_LAUNCH_APP1:	printf("VK_LAUNCH_APP1                  ");	break;
			case  VK_LAUNCH_APP2:	printf("VK_LAUNCH_APP2                  ");	break;
			case  VK_OEM_1:	printf("VK_OEM_1                        ");	break;
			case  VK_OEM_PLUS:	printf("VK_OEM_PLUS                     ");	break;
			case  VK_OEM_COMMA:	printf("VK_OEM_COMMA                    ");	break;
			case  VK_OEM_MINUS:	printf("VK_OEM_MINUS                    ");	break;
			case  VK_OEM_PERIOD:	printf("VK_OEM_PERIOD                   ");	break;
			case  VK_OEM_2:	printf("VK_OEM_2                        ");	break;
			case  VK_OEM_3:	printf("VK_OEM_3                        ");	break;
			case  0xC1:	printf("VK_/ VK_DIVIDE                  ");	break;
			case  VK_GAMEPAD_A:	printf("VK_GAMEPAD_A                    ");	break;
			case  VK_GAMEPAD_B:	printf("VK_GAMEPAD_B                    ");	break;
			case  VK_GAMEPAD_X:	printf("VK_GAMEPAD_X                    ");	break;
			case  VK_GAMEPAD_Y:	printf("VK_GAMEPAD_Y                    ");	break;
			case  VK_GAMEPAD_RIGHT_SHOULDER:	printf("VK_GAMEPAD_RIGHT_SHOULDER       ");	break;
			case  VK_GAMEPAD_LEFT_SHOULDER:	printf("VK_GAMEPAD_LEFT_SHOULDER        ");	break;
			case  VK_GAMEPAD_LEFT_TRIGGER:	printf("VK_GAMEPAD_LEFT_TRIGGER         ");	break;
			case  VK_GAMEPAD_RIGHT_TRIGGER:	printf("VK_GAMEPAD_RIGHT_TRIGGER        ");	break;
			case  VK_GAMEPAD_DPAD_UP:	printf("VK_GAMEPAD_DPAD_UP              ");	break;
			case  VK_GAMEPAD_DPAD_DOWN:	printf("VK_GAMEPAD_DPAD_DOWN            ");	break;
			case  VK_GAMEPAD_DPAD_LEFT:	printf("VK_GAMEPAD_DPAD_LEFT            ");	break;
			case  VK_GAMEPAD_DPAD_RIGHT:	printf("VK_GAMEPAD_DPAD_RIGHT           ");	break;
			case  VK_GAMEPAD_MENU:	printf("VK_GAMEPAD_MENU                 ");	break;
			case  VK_GAMEPAD_VIEW:	printf("VK_GAMEPAD_VIEW                 ");	break;
			case  VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON:	printf("VK_GAMEPAD_LEFT_THUMBSTICK_BUTTO");	break;
			case  VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON:	printf("VK_GAMEPAD_RIGHT_THUMBSTICK_BUTT");	break;
			case  VK_GAMEPAD_LEFT_THUMBSTICK_UP:	printf("VK_GAMEPAD_LEFT_THUMBSTICK_UP   ");	break;
			case  VK_GAMEPAD_LEFT_THUMBSTICK_DOWN:	printf("VK_GAMEPAD_LEFT_THUMBSTICK_DOWN ");	break;
			case  VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT:	printf("VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT");	break;
			case  VK_GAMEPAD_LEFT_THUMBSTICK_LEFT:	printf("VK_GAMEPAD_LEFT_THUMBSTICK_LEFT ");	break;
			case  VK_GAMEPAD_RIGHT_THUMBSTICK_UP:	printf("VK_GAMEPAD_RIGHT_THUMBSTICK_UP  ");	break;
			case  VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN:	printf("VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN");	break;
			case  VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT:	printf("VK_GAMEPAD_RIGHT_THUMBSTICK_RIGH");	break;
			case  VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT:	printf("VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT");	break;
			case  VK_OEM_4:	printf("VK_OEM_4                        ");	break;
			case  VK_OEM_5:	printf("VK_OEM_5                        ");	break;
			case  VK_OEM_6:	printf("VK_OEM_6                        ");	break;
			case  VK_OEM_7:	printf("VK_OEM_7                        ");	break;
			case  VK_OEM_8:	printf("VK_OEM_8                        ");	break;
			case  VK_OEM_AX:	printf("VK_OEM_AX                       ");	break;
			case  VK_OEM_102:	printf("VK_OEM_102                      ");	break;
			case  VK_ICO_HELP:	printf("VK_ICO_HELP                     ");	break;
			case  VK_ICO_00:	printf("VK_ICO_00                       ");	break;
			case  VK_PROCESSKEY:	printf("VK_PROCESSKEY                   ");	break;
			case  VK_ICO_CLEAR:	printf("VK_ICO_CLEAR                    ");	break;
			case  VK_PACKET:	printf("VK_PACKET                       ");	break;
			case  VK_OEM_RESET:	printf("VK_OEM_RESET                    ");	break;
			case  VK_OEM_JUMP:	printf("VK_OEM_JUMP                     ");	break;
			case  VK_OEM_PA1:	printf("VK_OEM_PA1                      ");	break;
			case  VK_OEM_PA2:	printf("VK_OEM_PA2                      ");	break;
			case  VK_OEM_PA3:	printf("VK_OEM_PA3                      ");	break;
			case  VK_OEM_WSCTRL:	printf("VK_OEM_WSCTRL                   ");	break;
			case  VK_OEM_CUSEL:	printf("VK_OEM_CUSEL                    ");	break;
			case  VK_OEM_ATTN:	printf("VK_OEM_ATTN                     ");	break;
			case  VK_OEM_FINISH:	printf("VK_OEM_FINISH                   ");	break;
			case  VK_OEM_COPY:	printf("VK_OEM_COPY                     ");	break;
			case  VK_OEM_AUTO:	printf("VK_OEM_AUTO                     ");	break;
			case  VK_OEM_ENLW:	printf("VK_OEM_ENLW                     ");	break;
			case  VK_OEM_BACKTAB:	printf("VK_OEM_BACKTAB                  ");	break;
			case  VK_ATTN:	printf("VK_ATTN                         ");	break;
			case  VK_CRSEL:	printf("VK_CRSEL                        ");	break;
			case  VK_EXSEL:	printf("VK_EXSEL                        ");	break;
			case  VK_EREOF:	printf("VK_EREOF                        ");	break;
			case  VK_PLAY:	printf("VK_PLAY                         ");	break;
			case  VK_ZOOM:	printf("VK_ZOOM                         ");	break;
			case  VK_NONAME:	printf("VK_NONAME                       ");	break;
			case  VK_PA1:	printf("VK_PA1                          ");	break;
			case  VK_OEM_CLEAR:	printf("VK_OEM_CLEAR                    ");	break;

			default:
				printf("???????????"); break;
		}

	printf("UP:%llx pDown:%llx alt:%llx rep:%lli scOEM:%llx extended:%llx 0x%llx 0x%llx ",
		   (slong)(lParam >> 31) & 0x1,
		   (slong)(lParam >> 30) & 0x1,
		   (slong)(lParam >> 29) & 0x1,
		   (slong)lParam & 0xffff,
		   (slong)(lParam >> 16) & 0xff,
		   (slong)(lParam >> 24) & 0x1,
		   (slong)lParam,
		   (ulong)wParam);
	//printf("%c", lParam);
	//printf(" '");
	printf("%c", (uint)wParam);
	printf("' ");
	printf("L: %i%i%i%i %i%i%i%i:%i%i%i%i %i%i%i%i  %i%i%i%i %i%i%i%i:%i%i%i%i %i%i%i%i"
		   //"    W: %i%i%i%i %i%i%i%i:%i%i%i%i %i%i%i%i  %i%i%i%i %i%i%i%i:%i%i%i%i %i%i%i%i"
		   "\n\n",
		   (uint)(lParam >> 31) & 0x1, (uint)(lParam >> 30) & 0x1, (uint)(lParam >> 29) & 0x1, (uint)(lParam >> 28) & 0x1,
		   (uint)(lParam >> 27) & 0x1, (uint)(lParam >> 26) & 0x1, (uint)(lParam >> 25) & 0x1, (uint)(lParam >> 24) & 0x1,

		   (uint)(lParam >> 23) & 0x1, (uint)(lParam >> 22) & 0x1, (uint)(lParam >> 21) & 0x1, (uint)(lParam >> 20) & 0x1,
		   (uint)(lParam >> 19) & 0x1, (uint)(lParam >> 18) & 0x1, (uint)(lParam >> 17) & 0x1, (uint)(lParam >> 16) & 0x1,

		   (uint)(lParam >> 15) & 0x1, (uint)(lParam >> 14) & 0x1, (uint)(lParam >> 13) & 0x1, (uint)(lParam >> 12) & 0x1,
		   (uint)(lParam >> 11) & 0x1, (uint)(lParam >> 10) & 0x1, (uint)(lParam >> 9) & 0x1, (uint)(lParam >> 8) & 0x1,

		   (uint)(lParam >> 7) & 0x1, (uint)(lParam >> 6) & 0x1, (uint)(lParam >> 5) & 0x1, (uint)(lParam >> 4) & 0x1,
		   (uint)(lParam >> 3) & 0x1, (uint)(lParam >> 2) & 0x1, (uint)(lParam >> 1) & 0x1, (uint)(lParam >> 0) & 0x1);

	//(lParam & 0x01000000) >> 24, (lParam & 0x02000000) >> 25, (lParam & 0x04000000) >> 26, (lParam & 0x08000000) >> 27,
	//(lParam & 0x10000000) >> 28, (lParam & 0x20000000) >> 29, (lParam & 0x00000000) >> 30, (lParam & 0x80000000) >> 31, // 0x20000000 = alt


	 //(wParam & 0x80000000) >> 31, (wParam & 0x40000000) >> 30, (wParam & 0x20000000) >> 29, (wParam & 0x10000000) >> 28, 
	 //(wParam & 0x08000000) >> 27, (wParam & 0x04000000) >> 26, (wParam & 0x02000000) >> 25, (wParam & 0x01000000) >> 24, 

	 //(wParam & 0x00800000) >> 23, (wParam & 0x00400000) >> 22, (wParam & 0x00200000) >> 21, (wParam & 0x00100000) >> 20, 
	 //(wParam & 0x00080000) >> 19, (wParam & 0x00040000) >> 18, (wParam & 0x00020000) >> 17, (wParam & 0x00010000) >> 16, 

	 //(wParam & 0x00008000) >> 15, (wParam & 0x00004000) >> 14, (wParam & 0x00002000) >> 13, (wParam & 0x00001000) >> 12, 
	 //(wParam & 0x00000800) >> 11, (wParam & 0x00000400) >> 10, (wParam & 0x00000200) >> 9,  (wParam & 0x00000100) >> 8,  

	 //(wParam & 0x00000080) >> 7,  (wParam & 0x00000040) >> 6,  (wParam & 0x00000020) >> 5,  (wParam & 0x00000010) >> 4,   // 0x00000040 = ctrl
	 //(wParam & 0x00000008) >> 3,  (wParam & 0x00000004) >> 2,  (wParam & 0x00000002) >> 1,  (wParam & 0x00000001) >> 0 ); // 0x00000020 = shift



	//(lParam >> 0) & 0x1, (lParam >> 1) & 0x1, (lParam >> 2) & 0x1, (lParam >> 3) & 0x1,
	//(lParam >> 4) & 0x1, (lParam >> 5) & 0x1, (lParam >> 6) & 0x1, (lParam >> 7) & 0x1,
	//(lParam >> 8) & 0x1, (lParam >> 9) & 0x1, (lParam >> 10) & 0x1, (lParam >> 11) & 0x1,
	//(lParam >> 12) & 0x1, (lParam >> 13) & 0x1, (lParam >> 14) & 0x1, (lParam >> 15) & 0x1,
	//(lParam >> 16) & 0x1, (lParam >> 17) & 0x1, (lParam >> 18) & 0x1, (lParam >> 19) & 0x1,
	//(lParam >> 20) & 0x1, (lParam >> 21) & 0x1, (lParam >> 22) & 0x1, (lParam >> 23) & 0x1,
	//(lParam >> 24) & 0x1, (lParam >> 25) & 0x1, (lParam >> 26) & 0x1, (lParam >> 27) & 0x1,
	//(lParam >> 28) & 0x1, (lParam >> 29) & 0x1, (lParam >> 30) & 0x1, (lParam >> 31) & 0x1);

	//(lParam & 0x01000000) >> 24, (lParam & 0x02000000) >> 25, (lParam & 0x04000000) >> 26, (lParam & 0x08000000) >> 27,
	//(lParam & 0x10000000) >> 28, (lParam & 0x20000000) >> 29, (lParam & 0x00000000) >> 30, (lParam & 0x80000000) >> 31, // 0x20000000 = alt

	//(wParam & 0x00000001) >> 0, (wParam & 0x00000002) >> 1, (wParam & 0x00000004) >> 2, (wParam & 0x00000008) >> 3, // 0x00000020 = shift
	//(wParam & 0x00000010) >> 4, (wParam & 0x00000020) >> 5, (wParam & 0x00000040) >> 6, (wParam & 0x00000080) >> 7, // 0x00000040 = ctrl
	//(wParam & 0x00000100) >> 8, (wParam & 0x00000200) >> 9, (wParam & 0x00000400) >> 10, (wParam & 0x00000800) >> 11,
	//(wParam & 0x00001000) >> 12, (wParam & 0x00002000) >> 13, (wParam & 0x00004000) >> 14, (wParam & 0x00008000) >> 15,
	//(wParam & 0x00010000) >> 16, (wParam & 0x00020000) >> 17, (wParam & 0x00040000) >> 18, (wParam & 0x00080000) >> 19,
	//(wParam & 0x00100000) >> 20, (wParam & 0x00200000) >> 21, (wParam & 0x00400000) >> 22, (wParam & 0x00800000) >> 23,
	//(wParam & 0x01000000) >> 24, (wParam & 0x02000000) >> 25, (wParam & 0x04000000) >> 26, (wParam & 0x08000000) >> 27,
	//(wParam & 0x10000000) >> 28, (wParam & 0x20000000) >> 29, (wParam & 0x40000000) >> 30, (wParam & 0x80000000) >> 31);

//onKeyPress(wParam, wParam, lParam, keymap, Message);
}


void onKeyPress(int key, WPARAM wParam, LPARAM lParam, pKeyMap keymap, UINT Message) {
	if (Message == WM_KEYDOWN)
		switch (key) {
			case VK_SUBTRACT:
			{
				activecamera->fov -= 0.01f;
				break;
			}
			case VK_ADD:
			{
				activecamera->fov += 0.01f;
				break;
			}
			case VK_UP:
			{
				activecamera->grot.x += 0.05f;
				break;
			}
			case VK_DOWN:
			{
				activecamera->grot.x -= 0.05f;
				break;
			}
			case VK_LEFT:
			{
				activecamera->grot.y = -0.05f;
				break;
			}
			case VK_RIGHT:
			{
				activecamera->grot.y -= 0.05f;
				break;
			}
			case 0x51:
			{ // Q
				//torus->grot.y  -= 0.05f;
				//esfera->grot.y -=0.05f;
				//torus->grot.w  -= 0.05f;
				//esfera->grot.w -=0.05f;
				break;
			}
			case 0x45:
			{ // E		 
				//torus->grot.y = +0.05f;
				//esfera->grot.y = +0.05f;
				//torus->grot.w = +0.05f;
				//esfera->grot.w = +0.05f;
				break;
			}
			case 0x52:
			{ // R
				//torus->grot = vec4(0, 0, 0.00000001f, 0.0003333);
				//esfera->grot = vec4(0, 0, 0.00000001f, 0.000333);
				break;
			}
			case 0x57:
			{ // W
				//torus->grot.x += 0.05f ;
				//esfera->grot.x += +0.05f;
				//torus->grot.w += 0.05f ;
				//esfera->grot.w += +0.05f;
				break;
			}
			case 0x53:
			{ // S		 
				//torus->grot.x  -= 0.05f;
				//esfera->grot.x -= 0.05f;
				//torus->grot.w  -= 0.05f;
				//esfera->grot.w -= 0.05f;
				break;
			}
			case 0x41:
			{ // A		  			   
				//torus->grot.z  += 0.05f;
				//esfera->grot.z += 0.05f;
				//torus->grot.w  += 0.05f;
				//esfera->grot.w += 0.05f;
				break;
			}
			case 0x44:
			{ // D		  			   
				//torus->grot.z  -= 0.05f;
				//esfera->grot.z -= 0.05f;
				//torus->grot.w  -= 0.05f;
				//esfera->grot.w -= 0.05f;
				break;
			}
			case VK_SPACE:
			{
				//torus->malhas[0]->mMaterial->detach();
				//esfera->malhas[0]->mMaterial->detach();
				//torus->malhas[0]->mMaterial->read(torus->malhas[0]->mMaterial->mName);
				//esfera->malhas[0]->mMaterial->read(esfera->malhas[0]->mMaterial->mName);
				printf("Material Reloaded\n\n");
				break;
			}
			default:
			{
				break;
			}
		}
}
inline void printAsciiTable() {
	FILE* ASSItable = fopen("ASSItable.py", "wb");
	char c = 0;
	for (char i = 0; i < 16; i++) {
		for (char j = 0; j < 16; j++) {
			fprintf(ASSItable, "%x: ''%c''			", c, c);
			c++;
		}
		fprintf(ASSItable, "\r\n");
	}
	fclose(ASSItable);

}
