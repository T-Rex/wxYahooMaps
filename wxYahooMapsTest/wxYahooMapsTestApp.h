/////////////////////////////////////////////////////////////////////////////
// Name:        wxYahooMapsTestApp.h
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     26/10/2008 18:53:21
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXYAHOOMAPSTESTAPP_H_
#define _WXYAHOOMAPSTESTAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "wxYahooMapsTestMainFrame.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * wxYahooMapsTestApp class declaration
 */

class wxYahooMapsTestApp: public wxApp
{    
    DECLARE_CLASS( wxYahooMapsTestApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    wxYahooMapsTestApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin wxYahooMapsTestApp event handler declarations

////@end wxYahooMapsTestApp event handler declarations

////@begin wxYahooMapsTestApp member function declarations

////@end wxYahooMapsTestApp member function declarations

////@begin wxYahooMapsTestApp member variables
////@end wxYahooMapsTestApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(wxYahooMapsTestApp)
////@end declare app

#endif
    // _WXYAHOOMAPSTESTAPP_H_
