#pragma once
#include "head.h"
#include "Ad.h"
#include "Ads.h"



std::wstring StringFromHTML(const std::wstring & filename)
{
	std::locale::global(std::locale(""));
	std::locale l_utf8(std::locale(), new std::codecvt_utf8<wchar_t, 0x10ffffUL, std::codecvt_mode::consume_header>);

	std::wifstream file;
	file.imbue(l_utf8);
	file.open(filename);
	if (!file)
	{
		std::cout << "Can't open the file";
		exit(EXIT_FAILURE);
	}

	file.seekg(0, std::ios::end);
	size_t length = file.tellg();
	file.seekg(0, std::ios::beg);
	std::wstring htmlBuffer(length, 0);
	file.read(&htmlBuffer[0], length);
	file.close();
	return htmlBuffer;
}

void parcer(const std::wstring htmlBuffer, Ads & ads)
{
	std::wstring const tag_beg = L"<h3 class=";
	std::wstring const tag_end = L"</a>";
	std::wstring const tag_div = L"</div>";
	std::wstring const tag_photo = L"photo\">";
	std::wstring const tag_url = L"href=\"";
	std::wstring const tag_title = L"title=";
	std::wstring const tag_rub = L"ру";
	std::wstring text;

	std::wstring names;
	std::wstring urls;
	std::wstring prices;
	double price;
	bool photo;

	boost::wregex wregex(tag_photo + L"(.*?)" + tag_div + L"(.*?)" + tag_beg + L"(.*?)" + tag_url + L"(.*?)" + tag_title + L"(.*?)^\(.*?)" + tag_end + L"(.*?)" + tag_div);
	for (boost::wsregex_iterator it(htmlBuffer.cbegin(), htmlBuffer.cend(), wregex); it != boost::wsregex_iterator(); ++it)
	{
		names = (*it)[6];
		urls = L"https:://avito.ru" + (*it)[4];
		prices = (*it)[7];
		boost::wsmatch res;
		boost::wregex poisk(L" [0-9]{1,10} [0-9]{1,10}");
		std::wstring text;
		if (boost::regex_search(prices, res, poisk)) {
			text = res[0];
			text.erase(text.find(' '), 1);
			text.erase(text.find(' '), 1);
			price = stoi(text);
		}
		else price = 0;
		if ((*it)[1].length() > 20) photo = 1;
		else photo = 0;
		ads.push(Ad(photo, urls, names, price));
	}
}
