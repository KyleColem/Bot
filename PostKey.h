#include <windows.h>
#include "Header.h"


class PostKey
{
public:
	PostKey();
	~PostKey();
	bool PressKey(HWND win, char* ch);
	bool PressKey(HWND win, char ch);
	bool PressKey(DWORD win, char* ch);
	bool PressKey(DWORD win, char ch);
private:
	keyStruct *arrayKey;
	int FindCode(char *str);
	void RSleep();

};

