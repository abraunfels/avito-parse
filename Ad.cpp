#include "Ad.h"

std::wostream& operator<<(std::wostream& os, const Ad & obj)
{
	if (obj._visible)
	{
		os << obj._title << std::endl << obj._url << std::endl << obj._price << L"руб.\n" << L"Photos? ";
		os << std::boolalpha;
		os << obj._photo << std::endl;
		return os;
	}
	os << "-";
	return os;
}

double Ad::get_price() const
{
	return _price;
}
bool Ad::has_photo() const
{
	bool flag = false;
	if (_photo) flag = true;
	return flag;
}
bool Ad::has_word(const std::wstring & str) const
{
	bool flag = false;
	if (_title.find(str) != std::wstring::npos) flag = true;
	return flag;
}
bool Ad::has_en() const
{
	bool flag = false;
	boost::wsmatch res;
	boost::wregex poisk(L"[a-zA-z]");
	if (boost::regex_search(_title, res, poisk)) flag = true;
	return flag;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void Ad::has_photo()
{
	_visible = false;
	if (_photo) _visible = true;
}
void Ad::has_word(const std::wstring & str) 
{
	_visible = false;
	if (_title.find(str) != std::string::npos) _visible = true;
}
void Ad::has_en() 
{
	_visible = false;
	boost::wsmatch res;
	boost::wregex poisk(L"[a-zA-z]");
	if (boost::regex_search(_title, res, poisk)) _visible = true;
}
///////////////////////////////////////////////////////
void Ad::change_by_price(double low, double high)
{
	_visible = false;
	if ((_price >= low) && (_price <= high)) _visible = true;
}