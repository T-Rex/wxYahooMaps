#ifndef _WX_FP_VALIDATOR_H
#define _WX_FP_VALIDATOR_H

#include <wx/wx.h>
#include <wx/validate.h>

class wxFPValidator : public wxValidator
{
protected:
	double * m_pDouble;
	int * m_pInt;
	wxString * m_pString;
	void Initialize();
public:	
	wxFPValidator(double * valPtr);
	wxFPValidator(int * valPtr);
	wxFPValidator(wxString * valPtr);
	wxFPValidator(const wxFPValidator & validator);
	~wxFPValidator();
	virtual wxValidator* Clone() const;
	virtual bool TransferFromWindow();
	virtual bool TransferToWindow();
	virtual bool Validate(wxWindow * parent);
};

#endif
