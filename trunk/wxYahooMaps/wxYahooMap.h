#ifndef _WX_YAHOO_MAP_H
#define _WX_YAHOO_MAP_H

#include <wx/wx.h>
#include <wx/gdicmn.h>
#include <jobqueue.h>
#include "wxYahooMapStatusEvent.h"

class wxYahooMap : wxEvtHandler
{
public:
	enum wxYahooMapImageType
	{
		wxYM_IMAGE_TYPE_PNG = wxBITMAP_TYPE_PNG,
		wxYM_IMAGE_TYPE_GIF = wxBITMAP_TYPE_GIF
	};

	wxYahooMap(wxEvtHandler * evtHandler, const wxString & appID = wxEmptyString);
	~wxYahooMap();

	void SetApplicationID(const wxString & value);
	const wxString & GetApplicationID();

	void SetPosition(const wxRealPoint & value);
	const wxRealPoint & GetPosition();

	void SetUsePosition(bool value);
	bool GetUsePosition();

	void SetLocation(const wxString & value);
	const wxString & GetLocation();

	void SetStreet(const wxString & value);
	const wxString & GetStreet();

	void SetCity(const wxString & value);
	const wxString & GetCity();

	void SetState(const wxString & value);
	const wxString & GetState();

	void SetZIPCode(int value);
	int GetZIPCode();

	void SetZoomLevel(int value);
	int GetZoomLevel();

	void SetRadius(double value);
	int GetRadius();

	void SetImageType(wxYahooMapImageType value);
	wxYahooMapImageType GetImageType();

	void SetImageSize(const wxSize & value);
	const wxSize & GetImageSize();

	void StartDownloading();

	static wxYahooMapImageType IntToYahooMapImageType(int value);
private:
	void Init(const wxString & appID);
	wxString BuildURL();
	
	wxEvtHandler * m_EvtHandler;
	wxString m_AppID;
	wxRealPoint m_Position;
	bool m_UsePosition;
	wxString m_Location;
	wxString m_Street;
	wxString m_City;
	wxString m_State;
	int m_ZIPCode;
	int m_ZoomLevel;
	double m_Radius;
	wxYahooMapImageType m_ImageType;
	wxSize m_ImageSize;
	JobQueue * m_JobQueue;
	DECLARE_EVENT_TABLE()
	void OnDownloadJobStatus(wxCommandEvent & event);
};

#endif
