#pragma once


// CHelpDialog dialog

class CHelpDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CHelpDialog)

public:
	CHelpDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CHelpDialog();

// Dialog Data
	enum { IDD = IDD_HELP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
