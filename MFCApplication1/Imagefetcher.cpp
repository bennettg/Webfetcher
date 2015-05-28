#include "stdafx.h"
#include "MFCApplication1Dlg.h"

using namespace std;


/*======================================================================
'downloadFromURL' - Image downloader version

Accepts 2 strings, the web_address and the file_name which can either download
using each string or, can also contain more than one of each. For example,
http://google.com,http://mybestfriendssite.com
and file1.html,file2.html
This will instead convert them into a vector which will then be iterated
through in order to download and store each file.

This method specifically checks for image extension in the file names

Returns nothing
========================================================================*/

void Imagefetcher::downloadFromURL(CString web_address, CString file_name)
{
	string extensions[] = {"jpg","jpeg","bmp","png"};

	CT2CA pszWA(web_address.GetString());
	CT2CA pszFN(file_name.GetString());
	string putURL(pszWA);
	string putFN(pszFN);

	if (putURL == "" || putFN == "")
	{
		AfxMessageBox(_T(STR_ERR_ENTER_URL), MB_OK | MB_ICONINFORMATION);
		return;
	}

	//check for the delimiters: , to download multiple urls/files
	if (putURL.find(",") != string::npos && putFN.find(",") != string::npos)
	{
		auto urls = explode(putURL, ',');
		auto files = explode(putFN, ',');

		for (std::vector<string>::size_type i = 0; i != urls.size(); i++) {
			//check for a file extension 

			if (
				(files[i].substr(files[i].find_last_of(".") + 1) == extensions[0])
				||
				(files[i].substr(files[i].find_last_of(".") + 1) == extensions[1])
				||
				(files[i].substr(files[i].find_last_of(".") + 1) == extensions[2])
				||
				(files[i].substr(files[i].find_last_of(".") + 1) == extensions[3])
				) 
			{
				CString boxMessage = _T(STR_DOWNLOADED) + (CString)urls[i].c_str();
				AfxMessageBox(boxMessage.GetString(), MB_OK | MB_ICONINFORMATION);

				HRESULT hr = URLDownloadToFileA(NULL,
					(LPCSTR)urls[i].c_str(),
					(LPCSTR)files[i].c_str(),
					0,
					NULL);
			}
			else 
			{
				AfxMessageBox(_T("Please enter a file extension that matches the images you are downloading."), MB_OK | MB_ICONSTOP);
			}
		}
	}
	else
	{

		if (
			(putFN.substr(putFN.find_last_of(".") + 1) == extensions[0])
			||
			(putFN.substr(putFN.find_last_of(".") + 1) == extensions[1])
			||
			(putFN.substr(putFN.find_last_of(".") + 1) == extensions[2])
			||
			(putFN.substr(putFN.find_last_of(".") + 1) == extensions[3])
			)
		{
			CString boxMessage = _T(STR_DOWNLOADED) + web_address;
			AfxMessageBox(boxMessage.GetString(), MB_OK | MB_ICONINFORMATION);

			HRESULT hr = URLDownloadToFileA(NULL,
				(LPCSTR)putURL.c_str(),
				(LPCSTR)putFN.c_str(),
				0,
				NULL);
		}
		else
		{
			AfxMessageBox(_T("Please enter a file extension that matches the image you are downloading."), MB_OK | MB_ICONSTOP);
		}

	}

}
