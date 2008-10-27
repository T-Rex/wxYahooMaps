/////////////////////////////////////////////////////////////////////////////
// Name:        wxYahooMapsCanvas.h
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     26/10/2008 19:37:38
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXYAHOOMAPSCANVAS_H_
#define _WXYAHOOMAPSCANVAS_H_


/*!
 * Includes
 */

////@begin includes
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxYahooMapsCanvas;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXYAHOOMAPSCANVAS 10017
#define SYMBOL_WXYAHOOMAPSCANVAS_STYLE wxSIMPLE_BORDER
#define SYMBOL_WXYAHOOMAPSCANVAS_IDNAME ID_WXYAHOOMAPSCANVAS
#define SYMBOL_WXYAHOOMAPSCANVAS_SIZE wxSize(100, 100)
#define SYMBOL_WXYAHOOMAPSCANVAS_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxYahooMapsCanvas class declaration
 */

class wxYahooMapsCanvas: public wxWindow
{    
    DECLARE_DYNAMIC_CLASS( wxYahooMapsCanvas )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxYahooMapsCanvas();
    wxYahooMapsCanvas(wxWindow* parent, wxWindowID id = ID_WXYAHOOMAPSCANVAS, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(100, 100), long style = wxSIMPLE_BORDER);

    /// Creation
    bool Create(wxWindow* parent, wxWindowID id = ID_WXYAHOOMAPSCANVAS, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(100, 100), long style = wxSIMPLE_BORDER);

    /// Destructor
    ~wxYahooMapsCanvas();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxYahooMapsCanvas event handler declarations

    /// wxEVT_SIZE event handler for ID_WXYAHOOMAPSCANVAS
    void OnSize( wxSizeEvent& event );

    /// wxEVT_PAINT event handler for ID_WXYAHOOMAPSCANVAS
    void OnPaint( wxPaintEvent& event );

    /// wxEVT_ERASE_BACKGROUND event handler for ID_WXYAHOOMAPSCANVAS
    void OnEraseBackground( wxEraseEvent& event );

////@end wxYahooMapsCanvas event handler declarations
	void OnScrollLineUp( wxScrollWinEvent& event );
    void OnScrollLineDown( wxScrollWinEvent& event );
    void OnScrollPageUp( wxScrollWinEvent& event );
    void OnScrollPageDown( wxScrollWinEvent& event );
    void OnScrollThumbtrack( wxScrollWinEvent& event );
    void OnScrollThumbRelease( wxScrollWinEvent& event );

////@begin wxYahooMapsCanvas member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxYahooMapsCanvas member function declarations
	void SetMap(wxBitmap & value);
	void ReCreateScrollBars();

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxYahooMapsCanvas member variables
////@end wxYahooMapsCanvas member variables
	wxBitmap m_Map;
};

#endif
    // _WXYAHOOMAPSCANVAS_H_
