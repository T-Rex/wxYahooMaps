/////////////////////////////////////////////////////////////////////////////
// Name:        wxYahooMapsTestMainFrame.cpp
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     26/10/2008 18:53:39
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

#include "wxYahooMapsTestMainFrame.h"
#include "wxYahooMapsCanvas.h"
#include "wxFPValidator.h"

////@begin XPM images
////@end XPM images


/*!
 * wxYahooMapsTestMainFrame type definition
 */

IMPLEMENT_CLASS( wxYahooMapsTestMainFrame, wxFrame )


/*!
 * wxYahooMapsTestMainFrame event table definition
 */

BEGIN_EVENT_TABLE( wxYahooMapsTestMainFrame, wxFrame )

////@begin wxYahooMapsTestMainFrame event table entries
    EVT_UPDATE_UI( ID_LATITUDE_TEXTCTRL, wxYahooMapsTestMainFrame::OnPOSITIONCTRLUpdate )

    EVT_UPDATE_UI( ID_LONGITUDE_TEXTCTRL, wxYahooMapsTestMainFrame::OnPOSITIONCTRLUpdate )

    EVT_BUTTON( ID_GO_BUTTON, wxYahooMapsTestMainFrame::OnGOBUTTONClick )

////@end wxYahooMapsTestMainFrame event table entries
EVT_YAHOO_MAP_STATUS(wxID_ANY, wxYahooMapsTestMainFrame::OnYahooMapStatus)

END_EVENT_TABLE()


/*!
 * wxYahooMapsTestMainFrame constructors
 */

wxYahooMapsTestMainFrame::wxYahooMapsTestMainFrame()
{
    Init();
}

wxYahooMapsTestMainFrame::wxYahooMapsTestMainFrame( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*!
 * wxYahooMapsTestMainFrame creator
 */

bool wxYahooMapsTestMainFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxYahooMapsTestMainFrame creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end wxYahooMapsTestMainFrame creation
    return true;
}


/*!
 * wxYahooMapsTestMainFrame destructor
 */

wxYahooMapsTestMainFrame::~wxYahooMapsTestMainFrame()
{
////@begin wxYahooMapsTestMainFrame destruction
////@end wxYahooMapsTestMainFrame destruction
	wxDELETE(m_YahooMap);
}


/*!
 * Member initialisation
 */

void wxYahooMapsTestMainFrame::Init()
{
////@begin wxYahooMapsTestMainFrame member initialisation
    m_AppID = wxT("<enter-your-app-id-here>");
    m_Latitude = 0;
    m_Longitude = 0;
    m_City = _("Washington");
    m_State = _("DC");
    m_ZIPCode = 0;
    m_ImageType = 0;
    m_ImageWidth = 620;
    m_ImageHeight = 500;
    m_ZoomLevel = 6;
    m_YahooMap = new wxYahooMap(this);
    m_UsePosition = false;
    m_UsePositionCheckBox = NULL;
    m_ImageTypeChoice = NULL;
    m_Canvas = NULL;
////@end wxYahooMapsTestMainFrame member initialisation
}


/*!
 * Control creation for wxYahooMapsTestMainFrame
 */

void wxYahooMapsTestMainFrame::CreateControls()
{
	SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY);
////@begin wxYahooMapsTestMainFrame content construction
    wxYahooMapsTestMainFrame* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer2);

    wxNotebook* itemNotebook3 = new wxNotebook( itemFrame1, ID_MAIN_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxNB_DEFAULT );

    wxPanel* itemPanel4 = new wxPanel( itemNotebook3, ID_LOCATION_PANEL, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxGridBagSizer* itemGridBagSizer5 = new wxGridBagSizer(0, 0);
    itemGridBagSizer5->AddGrowableCol(1);
    itemGridBagSizer5->SetEmptyCellSize(wxSize(10, 20));
    itemPanel4->SetSizer(itemGridBagSizer5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemPanel4, wxID_STATIC, _("App ID:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemStaticText6, wxGBPosition(0, 0), wxGBSpan(1, 1), wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl7 = new wxTextCtrl( itemPanel4, ID_APP_ID_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemTextCtrl7, wxGBPosition(0, 1), wxGBSpan(1, 1), wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_UsePositionCheckBox = new wxCheckBox( itemPanel4, ID_USE_POSITION_CHECKBOX, _("Use coordinates"), wxDefaultPosition, wxDefaultSize, 0 );
    m_UsePositionCheckBox->SetValue(false);
    itemGridBagSizer5->Add(m_UsePositionCheckBox, wxGBPosition(1, 1), wxGBSpan(1, 1), wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText9 = new wxStaticText( itemPanel4, wxID_STATIC, _("Latitude:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemStaticText9, wxGBPosition(2, 0), wxGBSpan(1, 1), wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl10 = new wxTextCtrl( itemPanel4, ID_LATITUDE_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemTextCtrl10, wxGBPosition(2, 1), wxGBSpan(1, 1), wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText11 = new wxStaticText( itemPanel4, wxID_STATIC, _("Longitude:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemStaticText11, wxGBPosition(3, 0), wxGBSpan(1, 1), wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl12 = new wxTextCtrl( itemPanel4, ID_LONGITUDE_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemTextCtrl12, wxGBPosition(3, 1), wxGBSpan(1, 1), wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText13 = new wxStaticText( itemPanel4, wxID_STATIC, _("Street:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemStaticText13, wxGBPosition(4, 0), wxGBSpan(1, 1), wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl14 = new wxTextCtrl( itemPanel4, ID_STREET_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemTextCtrl14, wxGBPosition(4, 1), wxGBSpan(1, 1), wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText15 = new wxStaticText( itemPanel4, wxID_STATIC, _("ZIP:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemStaticText15, wxGBPosition(7, 0), wxGBSpan(1, 1), wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl16 = new wxTextCtrl( itemPanel4, ID_CITY_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemTextCtrl16, wxGBPosition(5, 1), wxGBSpan(1, 1), wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText17 = new wxStaticText( itemPanel4, wxID_STATIC, _("City:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemStaticText17, wxGBPosition(5, 0), wxGBSpan(1, 1), wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl18 = new wxTextCtrl( itemPanel4, ID_STATE_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemTextCtrl18, wxGBPosition(6, 1), wxGBSpan(1, 1), wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText19 = new wxStaticText( itemPanel4, wxID_STATIC, _("State:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemStaticText19, wxGBPosition(6, 0), wxGBSpan(1, 1), wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl20 = new wxTextCtrl( itemPanel4, ID_ZIP_CODE_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer5->Add(itemTextCtrl20, wxGBPosition(7, 1), wxGBSpan(1, 1), wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook3->AddPage(itemPanel4, _("Location"));

    wxPanel* itemPanel21 = new wxPanel( itemNotebook3, ID_IMAGE_PANEL, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxFlexGridSizer* itemFlexGridSizer22 = new wxFlexGridSizer(2, 2, 0, 0);
    itemFlexGridSizer22->AddGrowableCol(1);
    itemPanel21->SetSizer(itemFlexGridSizer22);

    wxStaticText* itemStaticText23 = new wxStaticText( itemPanel21, wxID_STATIC, _("Image type:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer22->Add(itemStaticText23, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_ImageTypeChoiceStrings;
    m_ImageTypeChoiceStrings.Add(_("PNG"));
    m_ImageTypeChoiceStrings.Add(_("GIF"));
    m_ImageTypeChoice = new wxChoice( itemPanel21, ID_IMAGE_TYPE_CHOICE, wxDefaultPosition, wxDefaultSize, m_ImageTypeChoiceStrings, 0 );
    m_ImageTypeChoice->SetStringSelection(_("0"));
    itemFlexGridSizer22->Add(m_ImageTypeChoice, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText25 = new wxStaticText( itemPanel21, wxID_STATIC, _("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer22->Add(itemStaticText25, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxSpinCtrl* itemSpinCtrl26 = new wxSpinCtrl( itemPanel21, ID_IMAGE_WIDTH_SPINCTRL, _T("10"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 10, 1024, 10 );
    itemFlexGridSizer22->Add(itemSpinCtrl26, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText27 = new wxStaticText( itemPanel21, wxID_STATIC, _("Height:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer22->Add(itemStaticText27, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxSpinCtrl* itemSpinCtrl28 = new wxSpinCtrl( itemPanel21, ID_IMAGE_HEIGHT_SPINCTRL, _T("10"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 10, 1024, 10 );
    itemFlexGridSizer22->Add(itemSpinCtrl28, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText29 = new wxStaticText( itemPanel21, wxID_STATIC, _("Zoom level:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer22->Add(itemStaticText29, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxSlider* itemSlider30 = new wxSlider( itemPanel21, ID_ZOOM_LEVEL_SLIDER, 6, 1, 12, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_AUTOTICKS|wxSL_LABELS );
    itemFlexGridSizer22->Add(itemSlider30, 0, wxALIGN_CENTER_HORIZONTAL|wxGROW|wxALL, 5);

    itemNotebook3->AddPage(itemPanel21, _("Image"));

    wxPanel* itemPanel31 = new wxPanel( itemNotebook3, ID_MAP_PANEL, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer32 = new wxBoxSizer(wxVERTICAL);
    itemPanel31->SetSizer(itemBoxSizer32);

    m_Canvas = new wxYahooMapsCanvas( itemPanel31, ID_CANVAS, wxDefaultPosition, wxSize(100, 100), wxSIMPLE_BORDER );
    itemBoxSizer32->Add(m_Canvas, 1, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    wxButton* itemButton34 = new wxButton( itemPanel31, ID_GO_BUTTON, _("Show"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer32->Add(itemButton34, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    itemNotebook3->AddPage(itemPanel31, _("Map"));

    itemBoxSizer2->Add(itemNotebook3, 1, wxGROW, 0);

    // Set validators
    itemTextCtrl7->SetValidator( wxGenericValidator(& m_AppID) );
    m_UsePositionCheckBox->SetValidator( wxGenericValidator(& m_UsePosition) );
    itemTextCtrl10->SetValidator( wxFPValidator(& m_Latitude) );
    itemTextCtrl12->SetValidator( wxFPValidator(& m_Longitude) );
    itemTextCtrl14->SetValidator( wxGenericValidator(& m_Street) );
    itemTextCtrl16->SetValidator( wxGenericValidator(& m_City) );
    itemTextCtrl18->SetValidator( wxGenericValidator(& m_State) );
    itemTextCtrl20->SetValidator( wxGenericValidator(& m_ZIPCode) );
    m_ImageTypeChoice->SetValidator( wxGenericValidator(& m_ImageType) );
    itemSpinCtrl26->SetValidator( wxGenericValidator(& m_ImageWidth) );
    itemSpinCtrl28->SetValidator( wxGenericValidator(& m_ImageHeight) );
    itemSlider30->SetValidator( wxGenericValidator(& m_ZoomLevel) );
////@end wxYahooMapsTestMainFrame content construction
    TransferDataToWindow();
}


/*!
 * Should we show tooltips?
 */

bool wxYahooMapsTestMainFrame::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap wxYahooMapsTestMainFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxYahooMapsTestMainFrame bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxYahooMapsTestMainFrame bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxYahooMapsTestMainFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxYahooMapsTestMainFrame icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxYahooMapsTestMainFrame icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_GO_BUTTON
 */

void wxYahooMapsTestMainFrame::OnGOBUTTONClick( wxCommandEvent& event )
{
	TransferDataFromWindow();
	m_YahooMap->SetApplicationID(m_AppID);
	m_YahooMap->SetUsePosition(m_UsePosition);
	m_YahooMap->SetPosition(wxRealPoint(m_Longitude, m_Latitude));
	m_YahooMap->SetStreet(m_Street);
	m_YahooMap->SetCity(m_City);
	m_YahooMap->SetState(m_State);
	m_YahooMap->SetZIPCode(m_ZIPCode);
	m_YahooMap->SetImageType(wxYahooMap::IntToYahooMapImageType(m_ImageType));
	m_YahooMap->SetImageSize(wxSize(m_ImageWidth, m_ImageHeight));
	m_YahooMap->SetZoomLevel(m_ZoomLevel);
	m_YahooMap->StartDownloading();
}

void wxYahooMapsTestMainFrame::OnYahooMapStatus(wxYahooMapStatusEvent & event)
{
	if(event.GetInt() == 0)
	{
		wxBitmap * bmp = event.GetBitmap();
		if(bmp)
		{
			srand(time(NULL));
			//bmp->SaveFile(wxString::Format(wxT("map%i.png"), rand()), m_YahooMap->GetImageType());
			m_Canvas->SetMap(*bmp);
			wxDELETE(bmp);
		}
	}
	else
	{
		wxMessageBox(event.GetString());
	}
}

/*!
 * wxEVT_UPDATE_UI event handler for ID_LATITUDE_TEXTCTRL
 */

void wxYahooMapsTestMainFrame::OnPOSITIONCTRLUpdate( wxUpdateUIEvent& event )
{
	event.Enable(m_UsePositionCheckBox->GetValue());
}

