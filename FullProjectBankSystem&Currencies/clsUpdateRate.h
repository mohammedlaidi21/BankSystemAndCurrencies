#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencyExchange.h"

using namespace std;


class clsUpdateRate : protected clsScreen
{

private:
	static float _ReadNewRate()
	{
		float Rate = 0;

		cout << "\nEntre New Rate: ";
		Rate = clsInputValidate::ReadDblNumber();

		return Rate;
	}
	static void _PrintCurrencyCard(clsCurrencyExchange Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n____________________________\n";
		cout << "\nCountry   : " << Currency.Country();
		cout << "\nCode      : " << Currency.Code();
		cout << "\nName      : " << Currency.NameCurrency();
		cout << "\nRate($) = : " << Currency.Rate();
		cout << "\n____________________________\n";
	}


public:
	static void UpdateCurrencyRate()
	{
		_DrawActionHeaderScreen("\t Update Currency Rate");

		string CurrencyCode = "";

		cout << "\nPlease Entre Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrencyExchange::isCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code Not Exist, Pleas Entre Again: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrencyExchange Currency = clsCurrencyExchange::FindByCode(CurrencyCode);
		_PrintCurrencyCard(Currency);

		char Answer = 'n';

		cout << "\nAre You Sure You Want To Update Rate of This Currency? Y/N: ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\nUpdate Currency Rate:";
			cout << "\n________________________________\n";

			Currency.UpdateRate(_ReadNewRate());

			cout << "\n________________________________\n";

			cout << "\nCurrency Rate Updated Successfully:-)\n";
			_PrintCurrencyCard(Currency);
		}

	}
};

