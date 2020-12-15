
// BotDlg.h : header file
//

#pragma once


// CBotDlg dialog
class CBotDlg : public CDialogEx
{
// Construction
public:
	CBotDlg(CWnd* pParent = NULL);	// standard constructor
	BYTE m[4];
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
