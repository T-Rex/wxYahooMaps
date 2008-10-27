/////////////////////////////////////////////////////////////////////////////
// Name:        wxYahooMapsCanvas.cpp
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     26/10/2008 19:37:38
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "wxYahooMapsCanvas.h"
#include <wx/dcbuffer.h>

////@begin XPM images
////@end XPM images


/*!
 * wxYahooMapsCanvas type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxYahooMapsCanvas, wxWindow )


/*!
 * wxYahooMapsCanvas event table definition
 */

BEGIN_EVENT_TABLE( wxYahooMapsCanvas, wxWindow )

////@begin wxYahooMapsCanvas event table entries
    EVT_SIZE( wxYahooMapsCanvas::OnSize )
    EVT_PAINT( wxYahooMapsCanvas::OnPaint )
    EVT_ERASE_BACKGROUND( wxYahooMapsCanvas::OnEraseBackground )

////@end wxYahooMapsCanvas event table entries
	EVT_SCROLLWIN_LINEUP( wxYahooMapsCanvas::OnScrollLineUp )
    EVT_SCROLLWIN_LINEDOWN( wxYahooMapsCanvas::OnScrollLineDown )
    EVT_SCROLLWIN_PAGEUP( wxYahooMapsCanvas::OnScrollPageUp )
    EVT_SCROLLWIN_PAGEDOWN( wxYahooMapsCanvas::OnScrollPageDown )
    EVT_SCROLLWIN_THUMBTRACK( wxYahooMapsCanvas::OnScrollThumbtrack )
    EVT_SCROLLWIN_THUMBRELEASE( wxYahooMapsCanvas::OnScrollThumbRelease )

END_EVENT_TABLE()


/*!
 * wxYahooMapsCanvas constructors
 */

wxYahooMapsCanvas::wxYahooMapsCanvas()
{
    Init();
}

wxYahooMapsCanvas::wxYahooMapsCanvas(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
{
    Init();
    Create(parent, id, pos, size, style);
}


/*!
 * wxYahooMapsCanvas creator
 */

bool wxYahooMapsCanvas::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
{
////@begin wxYahooMapsCanvas creation
    wxWindow::Create(parent, id, pos, size, style);
    CreateControls();
////@end wxYahooMapsCanvas creation
    return true;
}


/*!
 * wxYahooMapsCanvas destructor
 */

wxYahooMapsCanvas::~wxYahooMapsCanvas()
{
////@begin wxYahooMapsCanvas destruction
////@end wxYahooMapsCanvas destruction
}


/*!
 * Member initialisation
 */

void wxYahooMapsCanvas::Init()
{
////@begin wxYahooMapsCanvas member initialisation
////@end wxYahooMapsCanvas member initialisation
}


/*!
 * Control creation for wxYahooMapsCanvas
 */

void wxYahooMapsCanvas::CreateControls()
{    
////@begin wxYahooMapsCanvas content construction
    this->SetBackgroundColour(wxColour(192, 192, 192));
////@end wxYahooMapsCanvas content construction
}


/*!
 * Should we show tooltips?
 */

bool wxYahooMapsCanvas::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxYahooMapsCanvas::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxYahooMapsCanvas bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxYahooMapsCanvas bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxYahooMapsCanvas::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxYahooMapsCanvas icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxYahooMapsCanvas icon retrieval
}

void wxYahooMapsCanvas::SetMap(wxBitmap & value)
{
	m_Map = value;
	ReCreateScrollBars();
	Refresh();
}

void wxYahooMapsCanvas::ReCreateScrollBars()
{
	wxSize size = GetSize();
	wxSize scrollBarSize(
		wxMax(size.GetWidth(), m_Map.GetWidth()),
		wxMax(size.GetHeight(), m_Map.GetHeight()));
	SetScrollbar(wxHORIZONTAL, 
		(scrollBarSize.GetWidth()-size.GetWidth())/2, 
		size.GetWidth(), scrollBarSize.GetWidth());
	SetScrollbar(wxVERTICAL, 
		(scrollBarSize.GetHeight()-size.GetHeight())/2, 
		size.GetHeight(), scrollBarSize.GetHeight());
}

/*!
 * wxEVT_PAINT event handler for ID_WXYAHOOMAPSCANVAS
 */

void wxYahooMapsCanvas::OnPaint( wxPaintEvent& event )
{
	wxBufferedPaintDC dc(this);
	dc.SetBackground(wxBrush(GetBackgroundColour()));
	dc.Clear();
	if(m_Map.IsOk())
	{
		int x = (m_Map.GetWidth() > dc.GetSize().GetWidth()) ? 
			-GetScrollPos(wxHORIZONTAL) :
			(dc.GetSize().GetWidth()-m_Map.GetWidth()) / 2;
		int y = (m_Map.GetHeight() > dc.GetSize().GetHeight()) ? 
			-GetScrollPos(wxVERTICAL) :
			(dc.GetSize().GetHeight()-m_Map.GetHeight()) / 2;
		dc.DrawBitmap(m_Map, x, y);
	}
}


/*!
 * wxEVT_ERASE_BACKGROUND event handler for ID_WXYAHOOMAPSCANVAS
 */

void wxYahooMapsCanvas::OnEraseBackground( wxEraseEvent& event )
{
}


/*!
 * wxEVT_SIZE event handler for ID_WXYAHOOMAPSCANVAS
 */

void wxYahooMapsCanvas::OnSize( wxSizeEvent& event )
{
	ReCreateScrollBars();
	Refresh();
}

void wxYahooMapsCanvas::OnScrollLineUp( wxScrollWinEvent& event )
{
	SetScrollPos(event.GetOrientation(), GetScrollPos(event.GetOrientation()) - 10);
	Refresh();
}

void wxYahooMapsCanvas::OnScrollLineDown( wxScrollWinEvent& event )
{
	SetScrollPos(event.GetOrientation(), GetScrollPos(event.GetOrientation()) + 10);
	Refresh();
}

void wxYahooMapsCanvas::OnScrollPageUp( wxScrollWinEvent& event )
{
	SetScrollPos(event.GetOrientation(), 
		GetScrollPos(event.GetOrientation()) - GetScrollThumb(event.GetOrientation()));
	Refresh();
}

void wxYahooMapsCanvas::OnScrollPageDown( wxScrollWinEvent& event )
{
	SetScrollPos(event.GetOrientation(), 
		GetScrollPos(event.GetOrientation()) + GetScrollThumb(event.GetOrientation()));
	Refresh();
}

void wxYahooMapsCanvas::OnScrollThumbtrack( wxScrollWinEvent& event )
{
	SetScrollPos(event.GetOrientation(), event.GetPosition());
	Refresh();
}

void wxYahooMapsCanvas::OnScrollThumbRelease( wxScrollWinEvent& event )
{
	Refresh();
}

//void wxYahooMapsCanvas::Scroll(wxPoint pt)
//{
//	if(pt.x >= 0)
//		SetScrollPos(wxHORIZONTAL, pt.x);
//	if(pt.y >= 0)
//		SetScrollPos(wxVERTICAL, pt.y);
//	Refresh();
//}
