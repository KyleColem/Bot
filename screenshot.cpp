#include "Header.h"
#include <windows.h>
#include <string>
#include <tlhelp32.h>
#include <AclAPI.h>
#include "PostKey.h"
#include "InputClass.h"
#include <Winuser.h>

void CaptureScreen(HWND window, wchar_t *filename)
{
	//auto start = std::chrono::high_resolution_clock::now();

	//Получаем прямоугольную область экрана
	RECT windowRect;
	GetWindowRect(window, &windowRect);

	//Размеры битмэпа
	int bitmap_dx = windowRect.right - windowRect.left;
	int bitmap_dy = windowRect.bottom - windowRect.top;

	BITMAPINFOHEADER bmpInfoHeader;
	BITMAPFILEHEADER bmpFileHeader;
	//BITMAP* pBitmap;

	bmpFileHeader.bfType = 0x4d42;
	bmpFileHeader.bfSize = 0;
	bmpFileHeader.bfReserved1 = 0;
	bmpFileHeader.bfReserved2 = 0;
	bmpFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	bmpInfoHeader.biSize = sizeof(bmpInfoHeader);
	bmpInfoHeader.biWidth = bitmap_dx;
	bmpInfoHeader.biHeight = bitmap_dy;
	bmpInfoHeader.biPlanes = 1;
	bmpInfoHeader.biBitCount = 24;
	bmpInfoHeader.biCompression = BI_RGB;
	bmpInfoHeader.biSizeImage = bitmap_dx*bitmap_dy*3;
	bmpInfoHeader.biXPelsPerMeter = 0;
	bmpInfoHeader.biYPelsPerMeter = 0;
	bmpInfoHeader.biClrUsed = 0;
	bmpInfoHeader.biClrImportant = 0;

	BITMAPINFO info;
	info.bmiHeader = bmpInfoHeader;

	BYTE* memory;
	HDC winDC = GetWindowDC(window);
	HDC bmpDC = CreateCompatibleDC(winDC);
	//Создаем битмэп
	HBITMAP bitmap = CreateDIBSection(winDC, &info, DIB_RGB_COLORS, (void**)&memory, NULL, 0);
	SelectObject(bmpDC, bitmap);//Выбираем в контекст битмэп
	BitBlt(bmpDC, 0, 0, bitmap_dx, bitmap_dy, winDC, 0, 0, SRCCOPY);
	ReleaseDC(window, winDC);
	
	//auto finish = std::chrono::high_resolution_clock::now();
	//std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << std::endl;


	OPENFILENAME ofn;//Указатель на структуру с данными инициализации диалогового окна
	wchar_t strFilter[] = L"Файлы данных *.bmp\0";
	wchar_t strFileName[MAX_PATH] = L"";
	memset(&ofn, 0, sizeof(OPENFILENAME));//Обнуление ofn
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = window;
	ofn.lpstrFilter = strFilter;
	ofn.lpstrFile = filename;//Буфер для имени файла
	ofn.nMaxFile = MAX_PATH;//Размер файла
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_SHOWHELP | OFN_OVERWRITEPROMPT;
	wcscpy_s(strFileName, ofn.lpstrFile);
	//GetSaveFileNameA(&ofn); //MessageBox(hwnd,"Невозможно сохранить файл","О программе...",MB_ICONINFORMATION);
	HANDLE hFile = CreateFile(ofn.lpstrFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) return;
	DWORD dwWritten = 0;
	WriteFile(hFile, &bmpFileHeader, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
	WriteFile(hFile, &bmpInfoHeader, sizeof(BITMAPINFOHEADER), &dwWritten, NULL);
	WriteFile(hFile, memory, bmpInfoHeader.biSizeImage, &dwWritten, NULL);
	CloseHandle(hFile);
}



/*
int main(int argc, wchar_t* argv[])
{
	
	HWND window;
	//UINT msg;
	wchar_t *fileName = L"G:\\screenshot.bmp";
	window = FindWindow(NULL, L"World of Warcraft");
	//std::cout << window << std::endl;
	//CaptureScreen(window, fileName);
	PostKey keyboard;
	//Sleep(5000);
	//keyboard.PressKey(window, "ENTER");

	
	Sleep(5000);

	if (PostMessage(window, WM_KEYDOWN, 49, 131072) != 0) {
		std::cout << "error: " << GetLastError()<<std::endl;
	}
	Sleep(64);
	if (PostMessage(window, WM_KEYUP, 49, 3221356545) != 0) {
		std::cout << "error: " << GetLastError() << std::endl;
	}
	keyboard.PressKey(window, '1');
	return 0;
}

*/
