//Kasia niedawno poznała wszystkie literki w szkole.Z wielką pasją potrafiła całe dnie spędzać na pisaniu długich słów swoim ulubionym flamastrem.
//Pisała i pisała "tasiemce" tak długo, aż flamaster wypisał się.Kasia posmutniała.Z trudem, ale udało jej się uprosić swoją mamę, aby kupiła jej nowy pisak.
//Musiała jednak obiecać, że tym razem będzie bardziej oszczędna przy jego używaniu żeby wystarczył na dłużej.Kasia zaczęła zastanawiać się w jaki sposób będzie mogła zrealizować obietnicę daną mamie.
//
//Postanowiła, że aby zaoszczędzić wkład flamastra będzie wypisywała skróconą wersję wymyślanych wyrazów.
//Jeśli miała zamiar napisać więcej niż dwie takie same literki obok siebie w wyrazie, to teraz napisze literkę a następnie liczbę, określającą ilość wystąpień tej literki.
//
//Zadanie
//Twoim zadaniem jest dla zadanego wyrazu, który wymyśliła Kasia, podanie skróconej wersji tego wyrazu.
//
//Wejście
//W pierwszej linijce wejścia znajduje się liczba naturalna C, 1 ≤ C ≤ 50, oznaczająca ilość zestawów danych.
//W kolejnych C wierszach wejścia znajdują się zestawy danych.Każdy zestaw składa się z niepustego wyrazu złożonego z samych dużych liter alfabetu amerykańskiego.
//Długość wyrazu nie przekracza 200 znaków.
//
//Wyjście
//Dla każdego zestawu danych, dla zadanego wyrazu, na wyjściu powinna znaleźć się jego skrócona wersja.
//
//Przykład
//Dla danych wejściowych :
//4
//OPSS
//ABCDEF
//ABBCCCDDDDEEEEEFGGHIIJKKKL
//AAAAAAAAAABBBBBBBBBBBBBBBB
//
//prawidłowym rozwiązaniem jest:
//OPSS
//ABCDEF
//ABBC3D4E5FGGHIIJK3L
//A10B16

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int d, ile = 1;
	cin >> d;
	for (int i = 0; i < d; ++i)
	{
		cin >> s;
		for (int j = 0; j < (s.length() - 1); ++j)
		{
			if (j == s.length() - 2)
			{
				if (ile > 2)
				{
					s[(j - ile) + 2] = '1';
					s.replace(j - ile + 3, s.length() - j, s.substr(j + 1, s.length() - j));
					for (int a = 0; a < (ile - 2); ++a)
					{
						s.pop_back();
					}
					cout << s;
					j = ile - 2;
					ile = 1;
				}
				else ile = 1;
			}
			if (s[j] == s[j + 1])
			{
				ile++;
			}
			else
			{
				if (ile > 2)
				{
					s[(j - ile) + 2] = '1';
					s.replace(j - ile + 3, s.length() - j, s.substr(j + 1, s.length() - j));
					for (int a = 0; a < (ile - 3); ++a)
					{
						s.pop_back();
					}
					cout << s << endl;
					j = ile - 2;
					ile = 1;
				}
				else ile = 1;
			}
		}
	}
	

	//for (int i = 0; i < s.length(); ++i)
	//{
	//	cout << s.substr(i, s.length() - i) << endl;
	//}
	//cout << s.replace(1, 2, s.substr(2,2));
	/*for (int i = 0; i < s.length(); ++i)
	{
		cout << s.replace(i+3-ile, s.length()-i, s.substr(i+1, s.length()-i)) << endl;
		cout << s << endl;
	}*/

}
