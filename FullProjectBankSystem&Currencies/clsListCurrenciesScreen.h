#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrencyExchange.h"

using namespace std;

class clsListCurrenciesScreen : protected clsScreen
{
private:
	static void _PrintListCurrencies(clsCurrencyExchange Curr)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Curr.Country();
		cout << "| " << setw(10) << left << Curr.Code();
		cout << "| " << setw(30) << left << Curr.NameCurrency();
		cout << "| " << setw(14) << left << Curr.Rate();
	}




public:
	static void ListCurrenciesScreen()
	{
		vector<clsCurrencyExchange> vCurrencies;
		vCurrencies = clsCurrencyExchange::GetDataCurrenciesExchange();

		string Title = "\t List Currencies Screen.";
		string Subtitle = "\t   (" + to_string(vCurrencies.size()) + ")Currencies.";
		_DrawActionHeaderScreen(Title, Subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________";
		cout << "_________________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << setw(10) << left << "Code";
		cout << "| " << setw(30) << left << "Name";
		cout << "| " << setw(14) << left << "Rate/($)";

		cout << setw(8) << left << "" << "\n\t_______________________________________________";
		cout << "_________________________________________________\n\n";

		if (vCurrencies.size() == 0)
			cout << "\t\t\t\t\t    No Currency Available In The System.!!";


		for (clsCurrencyExchange& Curr : vCurrencies)
		{
			_PrintListCurrencies(Curr);
			cout << endl;
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________";
		cout << "_________________________________________________\n";
	}
};

