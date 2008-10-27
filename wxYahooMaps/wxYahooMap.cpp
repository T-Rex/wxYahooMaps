#include "wxYahooMap.h"
#include "wxYahooMapDownloadJob.h"

BEGIN_EVENT_TABLE(wxYahooMap, wxEvtHandler)
EVT_COMMAND(wxID_ANY, wxEVT_CMD_JOB_STATUS_VOID_PTR, wxYahooMap::OnDownloadJobStatus)
END_EVENT_TABLE()

wxYahooMap::wxYahooMap(wxEvtHandler * evtHandler, const wxString & appID)
: m_EvtHandler(evtHandler)
{
	Init(appID);
	m_JobQueue = new JobQueue;
	m_JobQueue->Start(5);
}

wxYahooMap::~wxYahooMap()
{
	m_JobQueue->Stop();
	wxDELETE(m_JobQueue);
}

void wxYahooMap::Init(const wxString & appID)
{
	m_AppID = appID;
	m_Position = wxRealPoint(0,0);
	m_Location = wxEmptyString;
	m_Street = wxEmptyString;
	m_City = wxEmptyString;
	m_State = wxEmptyString;
	m_ZIPCode = 0;
	m_ZoomLevel = 6;
	m_Radius = 0;
	m_ImageType = wxYM_IMAGE_TYPE_PNG;
	m_ImageSize = wxSize(620, 500);
}

void wxYahooMap::SetApplicationID(const wxString & value)
{
	m_AppID = value;
}

const wxString & wxYahooMap::GetApplicationID()
{
	return m_AppID;
}

void wxYahooMap::SetPosition(const wxRealPoint & value)
{
	m_Position = value;
}

const wxRealPoint & wxYahooMap::GetPosition()
{
	return m_Position;
}

void wxYahooMap::SetUsePosition(bool value)
{
	m_UsePosition = value;
}

bool wxYahooMap::GetUsePosition()
{
	return m_UsePosition;
}

void wxYahooMap::SetLocation(const wxString & value)
{
	m_Location = value;
}

const wxString & wxYahooMap::GetLocation()
{
	return m_Location;
}

void wxYahooMap::SetStreet(const wxString & value)
{
	m_Street = value;
}

const wxString & wxYahooMap::GetStreet()
{
	return m_Street;
}

void wxYahooMap::SetCity(const wxString & value)
{
	m_City = value;
}

const wxString & wxYahooMap::GetCity()
{
	return m_City;
}

void wxYahooMap::SetState(const wxString & value)
{
	m_State = value;
}

const wxString & wxYahooMap::GetState()
{
	return m_State;
}

void wxYahooMap::SetZIPCode(int value)
{
	m_ZIPCode = value;
}

int wxYahooMap::GetZIPCode()
{
	return m_ZIPCode;
}

void wxYahooMap::SetZoomLevel(int value)
{
	m_ZoomLevel = value;
}

int wxYahooMap::GetZoomLevel()
{
	return m_ZoomLevel;
}

void wxYahooMap::SetRadius(double value)
{
	m_Radius = value;
}

int wxYahooMap::GetRadius()
{
	return m_Radius;
}

void wxYahooMap::SetImageType(wxYahooMap::wxYahooMapImageType value)
{
	m_ImageType = value;
}

wxYahooMap::wxYahooMapImageType wxYahooMap::GetImageType()
{
	return m_ImageType;
}

void wxYahooMap::SetImageSize(const wxSize & value)
{
	m_ImageSize = value;
}

const wxSize & wxYahooMap::GetImageSize()
{
	return m_ImageSize;
}

wxYahooMap::wxYahooMapImageType wxYahooMap::IntToYahooMapImageType(int value)
{
	switch(value)
	{
	case 0:
	case wxYM_IMAGE_TYPE_PNG:
		return wxYM_IMAGE_TYPE_PNG;
	case 1:
	case wxYM_IMAGE_TYPE_GIF:
		return wxYM_IMAGE_TYPE_GIF;
	default:
		wxFAIL_MSG(wxString::Format(
			_("Image Type %i is not supported by wxYahooMaps"), 
			value).GetData()); 
		break;
	}
	return wxYM_IMAGE_TYPE_PNG;
}
wxString wxYahooMap::BuildURL()
{
	do
	{
		if(m_AppID.IsEmpty()) break;
		wxString res = wxT("http://local.yahooapis.com/MapsService/V1/mapImage?");
		wxArrayString params;
		params.Add(wxString::Format(wxT("appid=%s"), m_AppID.GetData()));
		if(m_UsePosition)
		{
			params.Add(wxString::Format(wxT("latitude=%f"), m_Position.y));
			params.Add(wxString::Format(wxT("longitude=%f"), m_Position.x));
		}
		if(!m_Location.IsEmpty())
		{
			params.Add(wxString::Format(wxT("location=%s"), m_Location.GetData()));
		}
		if(!m_Street.IsEmpty())
		{
			params.Add(wxString::Format(wxT("street=%s"), m_Street.GetData()));
		}
		if(!m_City.IsEmpty())
		{
			params.Add(wxString::Format(wxT("city=%s"), m_City.GetData()));
		}
		if(!m_State.IsEmpty())
		{
			params.Add(wxString::Format(wxT("state=%s"), m_State.GetData()));
		}
		if(m_ZIPCode != 0)
		{
			params.Add(wxString::Format(wxT("zip=%i"), m_ZIPCode));
		}
		if(m_ZoomLevel != 0)
		{
			params.Add(wxString::Format(wxT("zoom=%i"), m_ZoomLevel));
		}
		wxString str;
		switch(m_ImageType)
		{
		case wxYM_IMAGE_TYPE_PNG:
			str = wxT("png");
			break;
		case wxYM_IMAGE_TYPE_GIF:
			str = wxT("gif");
			break;
		default:
			wxFAIL_MSG(wxString::Format(
				_("Image Type %i is not supported by wxYahooMaps"),
				(int)m_ImageType).GetData());
			break;
		}
		if(str.IsEmpty()) break;
		params.Add(wxString::Format(wxT("image_type=%s"), str.GetData()));
		if(m_ImageSize.GetWidth() != 0)
		{
			params.Add(wxString::Format(wxT("image_width=%i"), m_ImageSize.GetWidth()));
		}
		if(m_ImageSize.GetHeight() != 0)
		{
			params.Add(wxString::Format(wxT("image_height=%i"), m_ImageSize.GetHeight()));
		}
		if(m_Radius != 0)
		{
			params.Add(wxString::Format(wxT("radius=%f"), m_ZoomLevel));
		}
		for(size_t i = 0; i < params.Count(); i++)
		{
			if(i) res += wxT("&");
			res += params[i];
		}
		return res;
	}
	while(false);
	return wxEmptyString;
}

void wxYahooMap::StartDownloading()
{
	do
	{
		wxString url = BuildURL();
		if(url.IsEmpty()) break;
		wxYahooMapDownloadJob * newJob = new wxYahooMapDownloadJob(this, url);
		m_JobQueue->PushJob(newJob);
	}
	while(false);
}

void wxYahooMap::OnDownloadJobStatus(wxCommandEvent & event)
{
	do
	{
		wxYahooMapDownloadStatus * status = 
			(wxYahooMapDownloadStatus *)event.GetClientData();
		if(!status) break;
		wxYahooMapStatusEvent evt(wxEVT_YAHOO_MAP_STATUS, wxID_ANY);
		evt.SetInt(status->GetErrorCode());
		evt.SetString(status->GetErrorMessage());
		wxBitmap * bmp = status->GetBitmap();
		if(bmp)
		{
			evt.SetClientData(status->GetBitmap());
			status->DetachBitmap();
		}
		m_EvtHandler->AddPendingEvent(evt);
		wxDELETE(status);
	}
	while(false);
}
