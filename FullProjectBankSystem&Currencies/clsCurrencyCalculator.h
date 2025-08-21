#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencyExchange.h"

using namespace std;


class clsCurrencyCalculator : protected clsScreen
{
private:
	static float _ReadAmount()
	{
		float Amount = 0;

		cout << "\nPlease Entre Amount To Exchange: ";
		Amount = clsInputValidate::ReadDblNumber();

		return Amount;
	}
		
	static void _PrintCardCurrency(clsCurrencyExchange Curr, string Text = "")
	{
		cout << "\n" << Text;
		cout << "\n___________________________";
		cout << "\nCountry   : " << Curr.Country();
		cout << "\nCode      : " << Curr.Code();
		cout << "\nName      : " << Curr.NameCurrency();
		cout << "\nRate($) = : " << Curr.Rate();
		cout << "\n___________________________\n\n";
	}

	static clsCurrencyExchange _GetCurrency(string Message)
	{
		string CurrencyCode = "";

		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrencyExchange::isCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code Not Found, Entre Again: ";
			CurrencyCode = clsInputValidate::ReadString();
		};

		clsCurrencyExchange Currency = clsCurrencyExchange::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCurrencyCalculation(float Amount, clsCurrencyExchange CurrencyFrom, clsCurrencyExchange CurrencyTo)
	{
		float CurrencyToUSD = CurrencyFrom.ConvertToDollar(Amount);

		_PrintCardCurrency(CurrencyFrom, "Convert From: ");

		cout << Amount << " " << CurrencyFrom.Code() << " = " << CurrencyToUSD << " USD";

		if (CurrencyTo.Code() == "USD")
		{
			return;
		}

		float ExchangeToOtherCurrency 
			= CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		cout << "\n\nConverting From USD To:";

		_PrintCardCurrency(CurrencyTo, "To: ");

		cout << Amount << " " << CurrencyFrom.Code() << " = " << ExchangeToOtherCurrency << " " << CurrencyTo.Code();
	}


public:
	static void CurrencyCalculatorScreen()
	{
		char Answer = 'y';

		while (Answer == 'Y' || Answer == 'y')
		{
			system("cls");
			_DrawActionHeaderScreen("\tCurrency Calculator Screen");

			clsCurrencyExchange CurrencyFrom = _GetCurrency("\nPlease Entre Currency1 Code: ");
			clsCurrencyExchange CurrencyTo = _GetCurrency("\nPlease Entre Currency2 Code: ");

			float Amount = _ReadAmount();

			_PrintCurrencyCalculation(Amount, CurrencyFrom, CurrencyTo);


			cout << "\n\nAre You Want To Perform Another Calculation? Y/N: ";
			cin >> Answer;
		}
	}
};

