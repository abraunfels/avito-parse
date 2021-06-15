
#include "head.h"
#include "Ad.h"
#include "Ads.h"
#include "functions.h"

int main()
{
		std::wstring htmlBuffer=StringFromHTML(L"avito_n.html");
		Ads ads;
		Ads ads_n;
		parcer(htmlBuffer, ads);
		unsigned int n;
		do
		{
			std::wcout << L"Press:\n1 for sort from low to high;\n2 for sort from high to low;\n3 for filter by prices;\n";
			std::wcout << L"4 for filter by photo;\n5 for filter by english letters;\n6 filter by key words...\n";
		} while (!(std::wcin >> n));
		switch (n)
		{
			case 1:
				ads.sort();
				std::wcout << ads << std::endl << ads.size();
				break;
			case 2:
				ads.sort('d');
				std::wcout << ads << std::endl << ads.size();
				break;
			case 3:
				double a, b;
				std::wcout << "From: ";
				std::wcin >> a;
				std::wcout << "To";
				std::wcin >> b;
				ads_n = ads.filter_by_price(a, b);
				std::wcout << ads_n << std::endl << ads_n.size();
				break;
			case 4:
				ads_n = ads.filter_by_photo();
				std::wcout << ads_n << std::endl << ads_n.size();
				break;
			case 5:
				ads_n = ads.filter_en_letters();
				std::wcout << ads_n << std::endl << ads_n.size();
				break;
			case 6:
				std::wstring words;
				std::wcout << L"Key words: ";
				std::wcin >> words;
				ads_n = ads.filter_by_word(wordss);
				std::wcout << ads_n << std::endl << ads_n.size();
				break;

			/*case 1:
				ads.sort();
				std::wcout << ads << std::endl << ads.size();
				break;
			case 2:
				ads.sort('d');
				std::wcout << ads << std::endl << ads.size();
				break;
			case 3:
				double a, b;
				std::wcout << "From: ";
				std::wcin >> a;
				std::wcout << "To";
				std::wcin >> b;
				filter_by_price(ads, a, b);
				std::wcout << ads << std::endl << ads.size();
				break;
			case 4:
				filter_by_photo(ads);
				std::wcout << ads << std::endl << ads.size();
				break;
			case 5:
				filter_en_letters(ads);
				std::wcout << ads << std::endl << ads.size();
				break;
			case 6:
				std::wstring words;
				std::wcout << L"Key words: ";
				std::wcin >> words;
				filter_by_word(ads, wordss);
				std::wcout << ads << std::endl << ads.size();
				break;*/
			}
		_getch();
		return 0;
	}
