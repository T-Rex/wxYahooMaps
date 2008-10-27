#ifndef _WX_YAHOO_MAP_DOWNLOAD_JOB_H
#define _WX_YAHOO_MAP_DOWNLOAD_JOB_H

#include <wx/wx.h>
#include <wx/url.h>
#include <wx/mstream.h>
#include <wx/xml/xml.h>
#include <job.h>

class wxYahooMapDownloadStatus
{
	int m_ErrorCode;
	wxString m_ErrorMessage;
	wxBitmap * m_Bitmap;
public:
	wxYahooMapDownloadStatus(int errorCode, const wxString & message, wxBitmap * bitmap)
		: m_ErrorCode(errorCode), m_ErrorMessage(message), m_Bitmap(bitmap)
	{
	}
	~wxYahooMapDownloadStatus()
	{
		wxDELETE(m_Bitmap);
	}
	int GetErrorCode() {return m_ErrorCode;}
	const wxString & GetErrorMessage() {return m_ErrorMessage;}
	wxBitmap * GetBitmap() {return m_Bitmap;}
	void DetachBitmap() {m_Bitmap = NULL;}
};

class wxYahooMapDownloadJob : public Job
{
	wxString m_RequestURL;
	bool GetResponse(const wxString & address, 
		wxMemoryOutputStream & xml_stream);
	wxString GetImageURL(wxXmlNode * root);
	wxString GetErrorMessage(wxXmlNode * root);
	bool DownloadImage(const wxString & url, wxBitmap & bitmap);
public:
	wxYahooMapDownloadJob(wxEvtHandler * parent, const wxString & url)
		: Job(parent), m_RequestURL(url) {}

	void Process();
};

#endif
