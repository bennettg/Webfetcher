#pragma once

#include "stdafx.h"
#include "MFCApplication1Dlg.h"
using namespace std;


class Imagefetcher : Webfetcher {

public:
	virtual void downloadFromURL(CString, CString);
	string getExePath();
};