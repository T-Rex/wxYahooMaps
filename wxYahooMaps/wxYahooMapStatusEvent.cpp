#include "wxYahooMapStatusEvent.h"

IMPLEMENT_DYNAMIC_CLASS(wxYahooMapStatusEvent, wxCommandEvent)

DEFINE_EVENT_TYPE( wxEVT_YAHOO_MAP_STATUS )

wxYahooMapStatusEvent::wxYahooMapStatusEvent(wxEventType eventType, int id)
: wxCommandEvent(eventType, id)
{
}

wxYahooMapStatusEvent::~wxYahooMapStatusEvent()
{
}

wxEvent * wxYahooMapStatusEvent::Clone(void) const 
{
	return new wxYahooMapStatusEvent(*this); 
}

wxBitmap * wxYahooMapStatusEvent::GetBitmap()
{
	return (wxBitmap *)GetClientData();
}
