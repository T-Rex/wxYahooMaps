#include "wxYahooMapDownloadJob.h"

bool wxYahooMapDownloadJob::GetResponse(const wxString & address,
	wxMemoryOutputStream & xml_stream)
{
	do
	{
		wxURL url(address);
		if(url.GetError() != wxURL_NOERR) break;
		wxInputStream *in = url.GetInputStream();
		if(!in) break;
		bool res(false);
		if(in->IsOk())
		{
			int ch(0);
			in->Read(xml_stream);
			res = true;
		}
		wxDELETE(in);
		return res;
	}
	while(false);
	return false;
}

wxString wxYahooMapDownloadJob::GetImageURL(wxXmlNode * root)
{
	do
	{
		if(!root) break;
		for(wxXmlNode * node = root->GetChildren(); 
			node; node = node->GetNext())
		{
			if(node->GetType() == wxXML_TEXT_NODE)
			{
				return node->GetContent();
			}
		}
	}
	while(false);
	return wxEmptyString;
}

wxString wxYahooMapDownloadJob::GetErrorMessage(wxXmlNode * root)
{
	do
	{
		if(!root) break;
		for(wxXmlNode * node = root->GetChildren(); 
			node; node = node->GetNext())
		{
			if(node->GetName().Lower() == wxT("message"))
			{
				for(wxXmlNode * child = node->GetChildren(); 
					child; child = child->GetNext())
				{
					if(child->GetType() == wxXML_TEXT_NODE)
					{
						return child->GetContent();
					}
				}
			}
		}
	}
	while(false);
	return wxEmptyString;
}

bool wxYahooMapDownloadJob::DownloadImage(
		const wxString & url, wxBitmap & bitmap)
{
	do
	{
		wxMemoryOutputStream bmp_out_stream;
		if(!GetResponse(url, bmp_out_stream)) break;
		wxMemoryInputStream bmp_in_stream(bmp_out_stream);
		wxImage img(bmp_in_stream);
		if(!img.IsOk()) break;
		bitmap = wxBitmap(img);
		return true;
	}
	while(false);
	return false;
}

void wxYahooMapDownloadJob::Process()
{
	do
	{
		wxMemoryOutputStream xml_stream;
		if(!GetResponse(m_RequestURL, xml_stream)) 
		{
			Post(new wxYahooMapDownloadStatus(1, 
				_("Can't get response from Yahoo Maps service"), 
				NULL));
			break;
		}
		wxMemoryInputStream input_stream(xml_stream);
		wxXmlDocument doc(input_stream);
		if(!doc.IsOk()) 
		{
			Post(new wxYahooMapDownloadStatus(2, 
				_("Error loading XML response from Yahoo Maps service"), 
				NULL));
			break;
		}
		wxXmlNode * root = doc.GetRoot();
		if(!root) 
		{
			Post(new wxYahooMapDownloadStatus(3, 
				_("XML response from Yahoo Maps service does not have root"), 
				NULL));
			break;
		}
		if(root->GetName().Lower() == wxT("result"))
		{
			wxString imageURL = GetImageURL(root);
			if(imageURL.IsEmpty()) 
			{
				Post(new wxYahooMapDownloadStatus(4, 
					_("Can't obtain image URL from XML response"), 
					NULL));
				break;
			}
			wxBitmap * bmp = new wxBitmap;
			if(!DownloadImage(imageURL, *bmp))
			{
				wxDELETE(bmp);
				Post(new wxYahooMapDownloadStatus(5, 
					_("Error loading map image"), 
					NULL));
				break;
			}
			Post(new wxYahooMapDownloadStatus(0, wxEmptyString, bmp));
		}
		else if(root->GetName().Lower() == wxT("error"))
		{
			wxString message = GetErrorMessage(root);
			Post(new wxYahooMapDownloadStatus(6, message, NULL));
		}
	}
	while(false);
}