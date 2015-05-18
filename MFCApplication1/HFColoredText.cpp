// HFColoredText.cpp : implementation file
//

#include "stdafx.h"
#include "Webfetcher.h"
#include "HFColoredText.h"
#include "afxdialogex.h"


// HFColoredText dialog

IMPLEMENT_DYNAMIC(HFColoredText, CDialogEx)

HFColoredText::HFColoredText(CWnd* pParent /*=NULL*/)
	: CDialogEx(HFColoredText::IDD, pParent)
{

}

HFColoredText::~HFColoredText()
{
}

void HFColoredText::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HFColoredText, CDialogEx)
	//{{AFX_MSG_MAP(CMyStatic)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

HBRUSH HFColoredText::CtlColor(CDC* pDC, UINT nCtlColor)
{
	pDC->SetTextColor(RGB(255, 0, 0));
	return (HBRUSH)GetStockObject(NULL_BRUSH);
}

// HFColoredText message handlers
