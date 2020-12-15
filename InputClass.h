#pragma once
#include <windows.h>
#include "Header.h"

class InputClass
{
public:
	InputClass();
	~InputClass();
	bool PressKey(HWND win, char* ch);
	
private:
	UINT    cInputs;
	tagINPUT pInputs;
	int     cbSize;
	

	keyStruct *arrayKey;
	int FindCode(char *str);
	void RSleep();
};

