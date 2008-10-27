#ifndef _WX_YAHOO_MAP_STATUS_EVENT_H
#define _WX_YAHOO_MAP_STATUS_EVENT_H

#include <wx/wx.h>

class wxYahooMapStatusEvent : public wxCommandEvent
{
	DECLARE_DYNAMIC_CLASS(wxYahooMapStatusEvent)
public:
	wxYahooMapStatusEvent(wxEventType eventType = wxEVT_NULL, int id = 0);
	~wxYahooMapStatusEvent();

	wxEvent * Clone(void) const;

	wxBitmap * GetBitmap();
};

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EXPORTED_EVENT_TYPE(WXDLLEXPORT, wxEVT_YAHOO_MAP_STATUS, wxNewId())
END_DECLARE_EVENT_TYPES()

typedef void (wxEvtHandler::*wxYahooMapStatusEventFunction)(wxYahooMapStatusEvent & event);

#define EVT_YAHOO_MAP_STATUS(id, fn) \
	DECLARE_EVENT_TABLE_ENTRY( wxEVT_YAHOO_MAP_STATUS, id, -1, (wxObjectEventFunction) (wxEventFunction) wxStaticCastEvent( wxYahooMapStatusEventFunction, & fn ), (wxObject *) NULL ),

#endif
