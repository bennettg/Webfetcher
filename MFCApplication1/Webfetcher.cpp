#include "stdafx.h"
#include "MFCApplication1Dlg.h"

using namespace std;

/*======================================================================
	'getExePath'

	This function is currently not being used due to technical difficulties with it.
	But it was intended to get the current executable path in order to better decide
	where downloaded files should be stored.

	Returns a string with the current path
========================================================================*/

string Webfetcher::getExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, (LPWSTR)buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0,pos);
}


/*======================================================================
	'downloadFromURL'
	
	Accepts 2 strings, the web_address and the file_name which can either download
	using each string or, can also contain more than one of each. For example, 
	http://google.com,http://mybestfriendssite.com
	and file1.html,file2.html
	This will instead convert them into a vector which will then be iterated
	through in order to download and store each file.

	Returns nothing 
========================================================================*/

void Webfetcher::downloadFromURL(CString web_address, CString file_name)
{

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

			CString boxMessage = _T(STR_DOWNLOADED) + (CString)urls[i].c_str();
			AfxMessageBox(boxMessage.GetString(), MB_OK | MB_ICONINFORMATION);

			HRESULT hr = URLDownloadToFileA(NULL,
				(LPCSTR)urls[i].c_str(),
				(LPCSTR)files[i].c_str(),
				0,
				NULL);
		}
	}
	else 
	{
		CString boxMessage = _T(STR_DOWNLOADED) + web_address;

		AfxMessageBox(boxMessage.GetString(), MB_OK | MB_ICONINFORMATION);

		HRESULT hr = URLDownloadToFileA(NULL,
			(LPCSTR)putURL.c_str(),
			(LPCSTR)putFN.c_str(),
			0,
			NULL);
	}

}
