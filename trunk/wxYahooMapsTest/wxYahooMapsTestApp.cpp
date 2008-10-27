/////////////////////////////////////////////////////////////////////////////
// Name:        wxYahooMapsTestApp.cpp
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     26/10/2008 18:53:21
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
#include <wx/socket.h>

#include "wxYahooMapsTestApp.h"

////@begin XPM images
////@end XPM images


/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( wxYahooMapsTestApp )
////@end implement app


/*!
 * wxYahooMapsTestApp type definition
 */

IMPLEMENT_CLASS( wxYahooMapsTestApp, wxApp )


/*!
 * wxYahooMapsTestApp event table definition
 */

BEGIN_EVENT_TABLE( wxYahooMapsTestApp, wxApp )

////@begin wxYahooMapsTestApp event table entries
////@end wxYahooMapsTestApp event table entries

END_EVENT_TABLE()


/*!
 * Constructor for wxYahooMapsTestApp
 */

wxYahooMapsTestApp::wxYahooMapsTestApp()
{
    Init();
}


/*!
 * Member initialisation
 */

void wxYahooMapsTestApp::Init()
{
////@begin wxYahooMapsTestApp member initialisation
////@end wxYahooMapsTestApp member initialisation
}

/*!
 * Initialisation for wxYahooMapsTestApp
 */

bool wxYahooMapsTestApp::OnInit()
{
	wxSocketBase::Initialize();
////@begin wxYahooMapsTestApp initialisation
	// Remove the comment markers above and below this block
	// to make permanent changes to the code.

#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	wxYahooMapsTestMainFrame* mainWindow = new wxYahooMapsTestMainFrame( NULL );
	mainWindow->Show(true);
////@end wxYahooMapsTestApp initialisation

    return true;
}


/*!
 * Cleanup for wxYahooMapsTestApp
 */

int wxYahooMapsTestApp::OnExit()
{    
	JobQueueSingleton::Release();
////@begin wxYahooMapsTestApp cleanup
	return wxApp::OnExit();
////@end wxYahooMapsTestApp cleanup
}

