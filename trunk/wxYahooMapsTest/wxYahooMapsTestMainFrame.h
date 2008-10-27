/////////////////////////////////////////////////////////////////////////////
// Name:        wxYahooMapsTestMainFrame.h
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     26/10/2008 18:53:39
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXYAHOOMAPSTESTMAINFRAME_H_
#define _WXYAHOOMAPSTESTMAINFRAME_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/notebook.h"
#include "wx/gbsizer.h"
#include "wx/valgen.h"
#include "wx/spinctrl.h"
////@end includes
#include <wxYahooMap.h>

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
#define ID_WXYAHOOMAPSTESTMAINFRAME 10000
#define ID_MAIN_NOTEBOOK 10002
#define ID_LOCATION_PANEL 10001
#define ID_APP_ID_TEXTCTRL 10003
#define ID_USE_POSITION_CHECKBOX 10010
#define ID_LATITUDE_TEXTCTRL 10004
#define ID_LONGITUDE_TEXTCTRL 10005
#define ID_STREET_TEXTCTRL 10006
#define ID_CITY_TEXTCTRL 10007
#define ID_STATE_TEXTCTRL 10008
#define ID_ZIP_CODE_TEXTCTRL 10009
#define ID_IMAGE_PANEL 10012
#define ID_IMAGE_TYPE_CHOICE 10013
#define ID_IMAGE_WIDTH_SPINCTRL 10015
#define ID_IMAGE_HEIGHT_SPINCTRL 10016
#define ID_ZOOM_LEVEL_SLIDER 10014
#define ID_MAP_PANEL 10019
#define ID_CANVAS 10018
#define ID_GO_BUTTON 10011
#define SYMBOL_WXYAHOOMAPSTESTMAINFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXYAHOOMAPSTESTMAINFRAME_TITLE _("wxYahooMaps Test")
#define SYMBOL_WXYAHOOMAPSTESTMAINFRAME_IDNAME ID_WXYAHOOMAPSTESTMAINFRAME
#define SYMBOL_WXYAHOOMAPSTESTMAINFRAME_SIZE wxSize(400, 300)
#define SYMBOL_WXYAHOOMAPSTESTMAINFRAME_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxYahooMapsTestMainFrame class declaration
 */

class wxYahooMapsTestMainFrame: public wxFrame
{    
    DECLARE_CLASS( wxYahooMapsTestMainFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxYahooMapsTestMainFrame();
    wxYahooMapsTestMainFrame( wxWindow* parent, wxWindowID id = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_IDNAME, const wxString& caption = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_POSITION, const wxSize& size = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_SIZE, long style = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_IDNAME, const wxString& caption = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_POSITION, const wxSize& size = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_SIZE, long style = SYMBOL_WXYAHOOMAPSTESTMAINFRAME_STYLE );

    /// Destructor
    ~wxYahooMapsTestMainFrame();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxYahooMapsTestMainFrame event handler declarations

    /// wxEVT_UPDATE_UI event handler for ID_LATITUDE_TEXTCTRL
    void OnPOSITIONCTRLUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_GO_BUTTON
    void OnGOBUTTONClick( wxCommandEvent& event );

////@end wxYahooMapsTestMainFrame event handler declarations
	void OnYahooMapStatus(wxYahooMapStatusEvent & event);

////@begin wxYahooMapsTestMainFrame member function declarations

    wxString GetAppID() const { return m_AppID ; }
    void SetAppID(wxString value) { m_AppID = value ; }

    double GetLatitude() const { return m_Latitude ; }
    void SetLatitude(double value) { m_Latitude = value ; }

    double GetLongitude() const { return m_Longitude ; }
    void SetLongitude(double value) { m_Longitude = value ; }

    wxString GetStreet() const { return m_Street ; }
    void SetStreet(wxString value) { m_Street = value ; }

    wxString GetCity() const { return m_City ; }
    void SetCity(wxString value) { m_City = value ; }

    wxString GetState() const { return m_State ; }
    void SetState(wxString value) { m_State = value ; }

    int GetZIPCode() const { return m_ZIPCode ; }
    void SetZIPCode(int value) { m_ZIPCode = value ; }

    int GetImageType() const { return m_ImageType ; }
    void SetImageType(int value) { m_ImageType = value ; }

    int GetImageWidth() const { return m_ImageWidth ; }
    void SetImageWidth(int value) { m_ImageWidth = value ; }

    int GetImageHeight() const { return m_ImageHeight ; }
    void SetImageHeight(int value) { m_ImageHeight = value ; }

    int GetZoomLevel() const { return m_ZoomLevel ; }
    void SetZoomLevel(int value) { m_ZoomLevel = value ; }

    wxYahooMap * GetYahooMap() const { return m_YahooMap ; }
    void SetYahooMap(wxYahooMap * value) { m_YahooMap = value ; }

    bool GetUsePosition() const { return m_UsePosition ; }
    void SetUsePosition(bool value) { m_UsePosition = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxYahooMapsTestMainFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxYahooMapsTestMainFrame member variables
    wxCheckBox* m_UsePositionCheckBox;
    wxChoice* m_ImageTypeChoice;
    wxYahooMapsCanvas* m_Canvas;
    wxString m_AppID;
    double m_Latitude;
    double m_Longitude;
    wxString m_Street;
    wxString m_City;
    wxString m_State;
    int m_ZIPCode;
    int m_ImageType;
    int m_ImageWidth;
    int m_ImageHeight;
    int m_ZoomLevel;
    wxYahooMap * m_YahooMap;
    bool m_UsePosition;
////@end wxYahooMapsTestMainFrame member variables
};

#endif
    // _WXYAHOOMAPSTESTMAINFRAME_H_
