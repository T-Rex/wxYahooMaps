#include "wxFPValidator.h"
#include <math.h>

wxFPValidator::wxFPValidator(double * valPtr)
{
	Initialize();
	m_pDouble = valPtr;	
}

wxFPValidator::wxFPValidator(int * valPtr)
{
	Initialize();
	m_pInt = valPtr;	
}

wxFPValidator::wxFPValidator(wxString * valPtr)
{
	Initialize();
	m_pString = valPtr;	
}

wxFPValidator::wxFPValidator(const wxFPValidator & validator)
: m_pDouble(validator.m_pDouble), m_pInt(validator.m_pInt), 
m_pString(validator.m_pString)
{
}

wxFPValidator::~wxFPValidator()
{
}

void wxFPValidator::Initialize()
{
	m_pDouble = NULL;
	m_pInt = NULL;
	m_pString = NULL;
}

wxValidator* wxFPValidator::Clone() const
{
	return new wxFPValidator(*this);
}

bool wxFPValidator::TransferFromWindow()
{
	if(!m_validatorWindow) 
	{
		return false;
	}
#if wxUSE_TEXTCTRL
    if (m_validatorWindow->IsKindOf(CLASSINFO(wxTextCtrl)) )
    {
        wxTextCtrl * pControl = (wxTextCtrl*) m_validatorWindow;
		if(m_pDouble)
		{
			return pControl->GetValue().ToDouble(m_pDouble);
		}
		else if(m_pInt)
		{
			double tmp;
			bool res = pControl->GetValue().ToDouble(&tmp);
			if(tmp >= INT_MIN && tmp <= INT_MAX && (fmod(tmp,1) == 0))
			{
				*m_pInt = (int)tmp;
			} else res = false;
			return res;
		}
		else if(m_pString)
		{
			wxString tmp = pControl->GetValue();
			if(!tmp.IsEmpty())
			{
				*m_pString = tmp;
				return true;
			}
			return false;
		}
	}
#endif
	return false;
}

bool wxFPValidator::TransferToWindow()
{	
	if(!m_validatorWindow) 
	{
		return false;
	}
#if wxUSE_TEXTCTRL
    if (m_validatorWindow->IsKindOf(CLASSINFO(wxTextCtrl)) )
    {
        wxTextCtrl * pControl = (wxTextCtrl*) m_validatorWindow;
		if(m_pDouble)
		{
			pControl->SetValue(wxString::Format(wxT("%1.2f"), *m_pDouble));
			return true;
		}
		else if(m_pInt)
		{
			pControl->SetValue(wxString::Format(wxT("%i"), *m_pInt));
			return true;
		}
		else if(m_pString)
		{
			pControl->SetValue(*m_pString);
			return true;
		}
	}
#endif
	return false;
}

bool wxFPValidator::Validate(wxWindow * parent)
{	
	if(!m_validatorWindow) 
	{
		return false;
	}
#if wxUSE_TEXTCTRL
    if (m_validatorWindow->IsKindOf(CLASSINFO(wxTextCtrl)) )
    {
        wxTextCtrl * pControl = (wxTextCtrl*) m_validatorWindow;		
		if(m_pDouble != NULL)
		{			
			return pControl->GetValue().ToDouble(m_pDouble);
		}
		else if(m_pInt != NULL)
		{
			double tmp;
			bool res = pControl->GetValue().ToDouble(&tmp);
			if(tmp >= INT_MIN && tmp <= INT_MAX && (fmod(tmp,1) == 0))
			{
				*m_pInt = (int)tmp;
			} else res = false;
			return res;
		}
		else if(m_pString != NULL)
		{
			return !pControl->GetValue().IsEmpty();
		}
	}
#endif	
	return false;
}
