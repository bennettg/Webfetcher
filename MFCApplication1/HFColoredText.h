#pragma once


// HFColoredText dialog

class HFColoredText : public CDialogEx
{
	DECLARE_DYNAMIC(HFColoredText)

public:
	HFColoredText(CWnd* pParent = NULL);   // standard constructor
	virtual ~HFColoredText();

// Dialog Data
	enum { IDD = IDD_HELP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);

	DECLARE_MESSAGE_MAP()
};
