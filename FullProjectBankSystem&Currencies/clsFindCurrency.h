#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencyExchange.h"

using namespace std;

class clsFindCurrency : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrencyExchange Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________________\n";
		cout << "\nCountry : " << Currency.Country();
		cout << "\nCode    : " << Currency.Code();
		cout << "\nName    : " << Currency.NameCurrency();
		cout << "\nRate(1$): " << Currency.Rate();
		cout << "\n___________________________\n";
	}
	static void _ShowResult(clsCurrencyExchange Currency)
	{
		if (!Currency.isEmpty())
		{
			cout << "\nCurrency Found:-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was Not Found:-(\n";
		}
	}

public:
	static void ShowFindCurrency()
	{
		_DrawActionHeaderScreen("\t Find Currency Screen");
		
		short Answer = 1;

		cout << "\nFind By: [1] Code or [2] Country? ";
		cin >> Answer;

		if (Answer == 1)
		{
			string CurrencyCode;

			cout << "\nPlease Entre Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();

			clsCurrencyExchange Currency = clsCurrencyExchange::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}

		else if (Answer == 2)
		{
			string CountryName;

			cout << "\nPlease Entre Country Name: ";
			CountryName = clsInputValidate::ReadString();

			clsCurrencyExchange Currency = clsCurrencyExchange::FindByCountry(CountryName);
			_ShowResult(Currency);
		}
	}
};

