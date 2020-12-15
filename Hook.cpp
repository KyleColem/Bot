#include "stdafx.h"
#include "Header.h"
//#define winHide
//#define cmdVisible
/*эти две дериктивы дл€ переключени€ кусков кода */

#define _CRT_SECURE_NO_WARNINGS




LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	KBDLLHOOKSTRUCT* msg = (KBDLLHOOKSTRUCT*)lParam;
	if (msg < 0) { return CallNextHookEx(NULL, nCode, wParam, lParam); }
	else{
		if(msg->flags & 0x00000010)
			msg->flags=msg->flags & 0x11111101;
		}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

BOOL setMyHook()
{
	if (hWndServer != false)
		return FALSE; // already hooked!
	hook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)KeyboardProc, NULL, 0);
	if (hook != NULL)
	{
		hWndServer = true;
		return hWndServer;
	}
	return FALSE; // failed to set hook
}

BOOL clearMyHook()
{
	if (hWndServer == false)
		return FALSE;
	BOOL unhooked = UnhookWindowsHookEx(hook);
	if (unhooked)
		hWndServer = false;
	return unhooked;
}


#ifdef winHide 
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	if (setMyHook()) {
		MSG msg;
		BOOL bRet;

		while (1)
		{
			bRet = GetMessage(&msg, NULL, 0, 0);

			if (bRet > 0) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else if (bRet < 0)// (bRet == -1 indicates an error.)
			{
				clearMyHook();
				break;
			}
			else  // (bRet == 0 indicates "exit program".)
			{
				
				clearMyHook();
				break;
			}
		}


		return msg.wParam;
	}

	return 0;
}
#endif

#ifdef cmdVisible
int  imain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	if (setMyHook()) {
		MSG msg;
		BOOL bRet;

		while (1)
		{
			bRet = GetMessage(&msg, NULL, 0, 0);



			if (bRet > 0) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else if (bRet < 0)// (bRet == -1 indicates an error.)
			{
				clearMyHook();
				break;
			}
			else  // (bRet == 0 indicates "exit program".)
			{
				
				clearMyHook();
				break;
			}
		}


		return msg.wParam;
	}

	return 0;
}
#endif