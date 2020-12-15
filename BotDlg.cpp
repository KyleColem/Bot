

#include "stdafx.h"
#include "Bot.h"
#include "BotDlg.h"
#include "afxdialogex.h"

#include <windows.h>
#include <string>
#include <tlhelp32.h>
#include <AclAPI.h>
//#include "PostKey.h"
#include "InputClass.h"
#include <Winuser.h>
#include "Header.h"
#include "ScreenCaptureProcessorGDI.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DWORD FindProcIdExe(const std::wstring& processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!processName.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(processesSnapshot);
	return 0;
}

HWND FindWow() {
	return FindWindowW(NULL, L"World of Warcraft");
}


/*этот код нельз€ помещать в обработчики событий, иначе перестает работать. ѕќчему так происходит - непон€тно
  Ќадо будет протестировать SendInput, видимо он более низкоуровневый
  не работает до какого то странного момента
*/
//PostKey keyboard;

HWND window = FindWow();
InputClass a;
/**/
// CBotDlg dialog
CBotDlg::CBotDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BOT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBotDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CBotDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CBotDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CBotDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBotDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CBotDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CBotDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CBotDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CBotDlg message handlers

BOOL CBotDlg::OnInitDialog()
{
	//::setMyHook();
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBotDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBotDlg::OnBnClickedOk()
{
	
	
	//Sleep(2000);
	::SetForegroundWindow(window);
	a.PressKey(window, "1");
	//UINT msg; HWND_BROADCAST
	//wchar_t *fileName = L"D:\\screenshot.bmp";
	//void mainFunc();
	//std::cout << window << std::endl;
	//CaptureScreen(window, fileName);
	
	//CDialogEx::OnOK();
}


void CBotDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CBotDlg::OnBnClickedButton1()
{
	if (!hWndServer) {
		if (setMyHook()) hWndServer = true;
	}
	else clearMyHook();
}


void CBotDlg::OnBnClickedButton2()
{
	Sleep(2000);
	//SetForegroundWindow(window);
	a.PressKey(window, "2");
	// TODO: Add your control notification handler code here
}


void CBotDlg::OnBnClickedButton3()
{
	Sleep(2000);
	//::SetForegroundWindow(window);
	a.PressKey(window, "3");
	// TODO: Add your control notification handler code here
}


void CBotDlg::OnBnClickedButton4()
{
	Sleep(2000);
	//::SetForegroundWindow(window);
	a.PressKey(window, "4");
	// TODO: Add your control notification handler code here
}


void CBotDlg::OnBnClickedButton5()
{
	//keyboard.PressKey(HWND_BROADCAST, "5");
	/*

    The system restricts which processes can set the foreground window. A process can set the foreground window only if one of the following conditions is true:

        The process is the foreground process.
        The process was started by the foreground process.
        The process received the last input event.
        There is no foreground process.
        The foreground process is being debugged.
        The foreground is not locked (see LockSetForegroundWindow).
        The foreground lock time-out has expired (see SPI_GETFOREGROUNDLOCKTIMEOUT in SystemParametersInfo).
        No menus are active.

*/
	//::LockSetForegroundWindow(LSFW_UNLOCK);
	//::SetForegroundWindow(window);
	ScreenCaptureProcessorGDI capture;
	capture.init();

	Sleep(50);


	for (int i = 0; i < 60; i++)
	{
		capture.grabImage();
	}

	capture.release();
	// TODO: Add your control notification handler code here
}
