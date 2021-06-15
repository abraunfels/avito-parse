#include "Ads.h"



Ads::Ads()
{
}


Ads::~Ads()
{
	_ads.clear();
}

void Ads::push(const Ad & obj)
{
	_ads.push_back(obj);
}

std::wostream& operator<<(std::wostream& os, const Ads & obj)
{
	for (auto i = obj._ads.begin(); i < obj._ads.end(); ++i) os << *i << std::endl;
	return os;
}
void Ads::sort(const char ch)
{
	std::sort(_ads.begin(), _ads.end(), [](Ad a, Ad b) -> bool {
		if (a.get_price() < b.get_price()) return true;
		else return false;
	});
	if (ch == 'd')
		std::sort(_ads.begin(), _ads.end(), [](Ad a, Ad b) -> bool {
		if (a.get_price() > b.get_price()) return true;
		else return false;
	});
}

Ads Ads::filter_by_price(double low, double high) const
{
	Ads ads_n;
	for (std::vector<Ad>::const_iterator i = _ads.cbegin(); i < _ads.cend(); ++i)
		if ((i->get_price() <= high) && (i->get_price() >= low))
			ads_n.push(*i);
	ads_n.sort();
	return ads_n;
}
Ads Ads::filter_by_photo() const
{
	Ads ads_n;
	for (std::vector<Ad>::const_iterator i = _ads.cbegin(); i < _ads.cend(); ++i)
		if (i->has_photo())
			ads_n.push(*i);
	return ads_n;
}
size_t Ads::size() const
{
	return _ads.size();
}
Ads Ads::filter_by_word(const std::wstring & str) const
{
	Ads ads_n;
	for (std::vector<Ad>::const_iterator i = _ads.cbegin(); i < _ads.cend(); ++i)
		if (i->has_word(str))
			ads_n.push(*i);
	return ads_n;
}
Ads Ads::filter_en_letters() const
{
	Ads ads_n;
	for (std::vector<Ad>::const_iterator i = _ads.cbegin(); i < _ads.cend(); ++i)
		if (i->has_en())
			ads_n.push(*i);
	return ads_n;
}
///////////////////////////////////////////////////////
void filter_by_word(Ads & obj, const std::wstring & str)
{
	for (std::vector<Ad>::iterator i = obj._ads.begin(); i < obj._ads.end(); ++i)
		i->has_word(str);
}
void filter_en_letters(Ads & obj)
{
	for (std::vector<Ad>::iterator i = obj._ads.begin(); i < obj._ads.end(); ++i)
		i->has_en();
	
}
void filter_by_photo(Ads & obj)
{

	for (std::vector<Ad>::iterator i = obj._ads.begin(); i < obj._ads.end(); ++i)
		i->has_photo();
}
void filter_by_price(Ads & obj, double low, double high)
{
	obj.sort();
	for (std::vector<Ad>::iterator i = obj._ads.begin(); i < obj._ads.end(); ++i)
		i->change_by_price(low, high);
}