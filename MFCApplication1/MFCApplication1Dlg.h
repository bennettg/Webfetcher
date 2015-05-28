
// MFCApplication1Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Resource.h"

// CWebfetcherDlg dialog
class CWebfetcherDlg : public CDialogEx
{
// Construction
public:
	CWebfetcherDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeSearchEdit();
	afx_msg void OnBnClickedDButton();
	afx_msg void OnEnChangeNameEdit();
	CButton DownloadButton;
	CEdit UrlBox;
	CEdit NameBox;
	CStatic m_BmpStatic;
	CBitmap m_Bitmap;
	afx_msg void OnBnClickedHelpButton();
	afx_msg void OnBnClickedCheck1();
	CButton CheckboxDownloadImage;
};
