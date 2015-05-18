#pragma once

#include "stdafx.h"
#include "MFCApplication1Dlg.h"
using namespace std;


class Webfetcher {

private:
	string url_address;

public:
	CURLcode getWebsite(string);
	void downloadFromURL(CString, CString);
	string getExePath();
};