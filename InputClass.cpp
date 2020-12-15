#include "InputClass.h"
#include <random>
#include <ctime>

InputClass::InputClass()
{
	arrayKey = new keyStruct[71];
	arrayKey[0].scanCode = 1; arrayKey[0].charCode = 27; arrayKey[0].keystr = "esc";
	arrayKey[1].scanCode = 59; arrayKey[1].charCode = 112; arrayKey[1].keystr = "F1";
	arrayKey[2].scanCode = 60; arrayKey[2].charCode = 113; arrayKey[2].keystr = "F2";
	arrayKey[3].scanCode = 61; arrayKey[3].charCode = 114; arrayKey[3].keystr = "F3";
	arrayKey[4].scanCode = 62; arrayKey[4].charCode = 115; arrayKey[4].keystr = "F4";
	arrayKey[5].scanCode = 63; arrayKey[5].charCode = 116; arrayKey[5].keystr = "F5";
	arrayKey[6].scanCode = 64; arrayKey[6].charCode = 117; arrayKey[6].keystr = "F6";
	arrayKey[7].scanCode = 65; arrayKey[7].charCode = 118; arrayKey[7].keystr = "F7";
	arrayKey[8].scanCode = 66; arrayKey[8].charCode = 119; arrayKey[8].keystr = "F8";
	arrayKey[9].scanCode = 67; arrayKey[9].charCode = 120; arrayKey[9].keystr = "F9";
	arrayKey[10].scanCode = 68; arrayKey[10].charCode = 121; arrayKey[10].keystr = "F10";
	arrayKey[11].scanCode = 87; arrayKey[11].charCode = 122; arrayKey[11].keystr = "F11";
	arrayKey[12].scanCode = 88; arrayKey[12].charCode = 123; arrayKey[12].keystr = "F12";
	arrayKey[13].scanCode = 41; arrayKey[13].charCode = 192; arrayKey[13].keystr = "`";
	arrayKey[14].scanCode = 2; arrayKey[14].charCode = 49; arrayKey[14].keystr = "1";
	arrayKey[15].scanCode = 3; arrayKey[15].charCode = 50; arrayKey[15].keystr = "2";
	arrayKey[16].scanCode = 4; arrayKey[16].charCode = 51; arrayKey[16].keystr = "3";
	arrayKey[17].scanCode = 5; arrayKey[17].charCode = 52; arrayKey[17].keystr = "4";
	arrayKey[18].scanCode = 6; arrayKey[18].charCode = 53; arrayKey[18].keystr = "5";
	arrayKey[19].scanCode = 7; arrayKey[19].charCode = 54; arrayKey[19].keystr = "6";
	arrayKey[20].scanCode = 8; arrayKey[20].charCode = 55; arrayKey[20].keystr = "7";
	arrayKey[21].scanCode = 9; arrayKey[21].charCode = 56; arrayKey[21].keystr = "8";
	arrayKey[22].scanCode = 10; arrayKey[22].charCode = 57; arrayKey[22].keystr = "9";
	arrayKey[23].scanCode = 11; arrayKey[23].charCode = 48; arrayKey[23].keystr = "0";
	arrayKey[24].scanCode = 12; arrayKey[24].charCode = 189; arrayKey[24].keystr = "-";
	arrayKey[25].scanCode = 13; arrayKey[25].charCode = 187; arrayKey[25].keystr = "=";
	arrayKey[26].scanCode = 43; arrayKey[26].charCode = 220; arrayKey[26].keystr = "\\";
	arrayKey[27].scanCode = 14; arrayKey[27].charCode = 8; arrayKey[27].keystr = "BS";
	arrayKey[28].scanCode = 15; arrayKey[28].charCode = 9; arrayKey[28].keystr = "TAB";
	arrayKey[29].scanCode = 16; arrayKey[29].charCode = 81; arrayKey[29].keystr = "Q";
	arrayKey[30].scanCode = 17; arrayKey[30].charCode = 87; arrayKey[30].keystr = "W";
	arrayKey[31].scanCode = 18; arrayKey[31].charCode = 69; arrayKey[31].keystr = "E";
	arrayKey[32].scanCode = 19; arrayKey[32].charCode = 82; arrayKey[32].keystr = "R";
	arrayKey[33].scanCode = 20; arrayKey[33].charCode = 84; arrayKey[33].keystr = "T";
	arrayKey[34].scanCode = 21; arrayKey[34].charCode = 89; arrayKey[34].keystr = "Y";
	arrayKey[35].scanCode = 22; arrayKey[35].charCode = 85; arrayKey[35].keystr = "U";
	arrayKey[36].scanCode = 23; arrayKey[36].charCode = 73; arrayKey[36].keystr = "I";
	arrayKey[37].scanCode = 24; arrayKey[37].charCode = 79; arrayKey[37].keystr = "O";
	arrayKey[38].scanCode = 25; arrayKey[38].charCode = 80; arrayKey[38].keystr = "P";
	arrayKey[39].scanCode = 26; arrayKey[39].charCode = 219; arrayKey[39].keystr = "[";
	arrayKey[40].scanCode = 27; arrayKey[40].charCode = 221; arrayKey[40].keystr = "]";
	arrayKey[41].scanCode = 28; arrayKey[41].charCode = 13; arrayKey[41].keystr = "ENTER";
	arrayKey[42].scanCode = 30; arrayKey[42].charCode = 65; arrayKey[42].keystr = "A";
	arrayKey[43].scanCode = 31; arrayKey[43].charCode = 83; arrayKey[43].keystr = "S";
	arrayKey[44].scanCode = 32; arrayKey[44].charCode = 68; arrayKey[44].keystr = "D";
	arrayKey[45].scanCode = 33; arrayKey[45].charCode = 70; arrayKey[45].keystr = "F";
	arrayKey[46].scanCode = 34; arrayKey[46].charCode = 71; arrayKey[46].keystr = "G";
	arrayKey[47].scanCode = 35; arrayKey[47].charCode = 72; arrayKey[47].keystr = "H";
	arrayKey[48].scanCode = 36; arrayKey[48].charCode = 74; arrayKey[48].keystr = "J";
	arrayKey[49].scanCode = 37; arrayKey[49].charCode = 75; arrayKey[49].keystr = "K";
	arrayKey[50].scanCode = 38; arrayKey[50].charCode = 76; arrayKey[50].keystr = "L";
	arrayKey[51].scanCode = 39; arrayKey[51].charCode = 186; arrayKey[51].keystr = ";";
	arrayKey[52].scanCode = 40; arrayKey[52].charCode = 222; arrayKey[52].keystr = "'";
	arrayKey[53].scanCode = 42; arrayKey[53].charCode = 160; arrayKey[53].keystr = "SHIFT";
	arrayKey[54].scanCode = 44; arrayKey[54].charCode = 90; arrayKey[54].keystr = "Z";
	arrayKey[55].scanCode = 45; arrayKey[55].charCode = 88; arrayKey[55].keystr = "X";
	arrayKey[56].scanCode = 46; arrayKey[56].charCode = 67; arrayKey[56].keystr = "C";
	arrayKey[57].scanCode = 47; arrayKey[57].charCode = 86; arrayKey[57].keystr = "V";
	arrayKey[58].scanCode = 48; arrayKey[58].charCode = 66; arrayKey[58].keystr = "B";
	arrayKey[59].scanCode = 49; arrayKey[59].charCode = 78; arrayKey[59].keystr = "N";
	arrayKey[60].scanCode = 50; arrayKey[60].charCode = 77; arrayKey[60].keystr = "M";
	arrayKey[61].scanCode = 51; arrayKey[61].charCode = 188; arrayKey[61].keystr = ",";
	arrayKey[62].scanCode = 52; arrayKey[62].charCode = 190; arrayKey[62].keystr = ".";
	arrayKey[63].scanCode = 53; arrayKey[63].charCode = 191; arrayKey[63].keystr = "/";
	arrayKey[64].scanCode = 29; arrayKey[64].charCode = 162; arrayKey[64].keystr = "CTRL";
	arrayKey[65].scanCode = 56; arrayKey[65].charCode = 164; arrayKey[65].keystr = "LALT";
	arrayKey[66].scanCode = 57; arrayKey[66].charCode = 32; arrayKey[66].keystr = " ";
	arrayKey[67].scanCode = 75; arrayKey[67].charCode = 37; arrayKey[67].keystr = "LEFT";
	arrayKey[68].scanCode = 72; arrayKey[68].charCode = 38; arrayKey[68].keystr = "UP";
	arrayKey[69].scanCode = 77; arrayKey[69].charCode = 39; arrayKey[69].keystr = "RIGHT";
	arrayKey[70].scanCode = 80; arrayKey[70].charCode = 40; arrayKey[70].keystr = "DOWN";

	pInputs.ki.dwExtraInfo = 0;
	pInputs.ki.dwFlags = 0;
	pInputs.ki.time = 0;
	pInputs.ki.wScan = 0;
	pInputs.ki.wVk = 0;
	pInputs.type = INPUT_KEYBOARD;

	cbSize = sizeof(tagINPUT);
}

InputClass::~InputClass()
{
	delete[] arrayKey;
}

bool InputClass::PressKey(HWND win, char* ch) {
	//HWND window = FindWindowW(NULL, L"World of Warcraft");
	int i = FindCode(ch);
	if (i >= 0 && i < 71) {
		pInputs.ki.wScan = arrayKey[i].scanCode;
		pInputs.ki.wVk = arrayKey[i].charCode;
		pInputs.ki.dwFlags = 0;
		//SetActiveWindow(window);
		SendInput(1, &pInputs, cbSize);//нажатие клавиши
		RSleep();
		pInputs.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &pInputs, cbSize);//отпускание клавиши
		return true;
	}
	else return false;
}

int InputClass::FindCode(char *str) {
	/*перебор массива в поиске нужной строки, выдает ее индекс. размерность массива захардкожена*/
	int i = 0;
	do {
		if (strcmp(arrayKey[i].keystr, str) == 0) { return i; }
		else i++;
	} while (i<71);
	return -1;
}

void InputClass::RSleep() {
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> uid(30, 350);
	Sleep(uid(gen));
}