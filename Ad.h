#pragma once
#include "head.h"
class Ad
{
private:
	std::wstring _title;
	std::wstring _url;
	double _price;
	bool _photo;
	bool _visible;
public:
	Ad(bool photo, std::wstring & url, std::wstring title, double price, bool flag = true): _photo(photo), _url(url), _title(title), _price(price), _visible(flag) {}
	friend std::wostream& operator<<(std::wostream& os, const Ad &);
	double get_price() const;
	bool has_photo() const;
	bool has_word(const std::wstring &) const;
	bool has_en() const;
	/////////////////////////////////////
	void has_photo();
	void has_word(const std::wstring &);
	void has_en();
	/////////////////////////////////////
	void change_by_price(double, double);
};



