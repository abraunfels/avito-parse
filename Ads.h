#pragma once
#include "head.h"
#include "Ad.h"


class Ads
{
private:
	std::vector <Ad> _ads;
public:
	Ads();
	void push(const Ad &);
	~Ads();
	friend std::wostream& operator<<(std::wostream& os, const Ads & obj);
	void sort(const char ch = 'u');
	Ads filter_by_price(double low, double high) const;
	Ads filter_by_photo() const;
	size_t size() const;
	Ads filter_by_word(const std::wstring &) const;
	Ads filter_en_letters() const;
	friend void filter_by_word(Ads & obj, const std::wstring &);
	friend void filter_en_letters(Ads & obj);
	friend void filter_by_photo(Ads & obj);
	friend void filter_by_price(Ads & obj, double low, double high);
};
	
