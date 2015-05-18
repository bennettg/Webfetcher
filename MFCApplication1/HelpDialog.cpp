// HelpDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Webfetcher.h"
#include "HelpDialog.h"
#include "afxdialogex.h"


// CHelpDialog dialog

IMPLEMENT_DYNAMIC(CHelpDialog, CDialogEx)

CHelpDialog::CHelpDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHelpDialog::IDD, pParent)
{

}

CHelpDialog::~CHelpDialog()
{
}

void CHelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHelpDialog, CDialogEx)
END_MESSAGE_MAP()


// CHelpDialog message handlers
