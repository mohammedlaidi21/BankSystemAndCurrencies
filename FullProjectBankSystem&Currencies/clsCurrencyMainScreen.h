#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateRate.h"
#include "clsCurrencyCalculator.h"

using namespace std;

class clsCurrencyMainScreen : protected clsScreen
{
private:
	enum _enCurrencyExchange {
		eListCurrencies = 1, eFindCurrency = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenu = 5
	};


	static short _ReadChooceCurrency()
	{
		short Chooce = 1;

		cout << setw(37) << left << "" << "\tChooce What Do You Want To Do? [1 To 5]: ";
		Chooce = clsInputValidate::ReadIntNumberBetween(1, 5, 
			"\t\t\t\t\tChooce What Do You Want To Do? [1 To 5]: ");

		return Chooce;
	}

	static void _ShowListCurrenciesScreen()
	{
		/*cout << "\nList Currencies Will Be Here...\n";*/
		clsListCurrenciesScreen::ListCurrenciesScreen();
	}
	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Will Be Here...\n";
		clsFindCurrency::ShowFindCurrency();
	}
	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate Rate Currency Will Be Here...\n";
		clsUpdateRate::UpdateCurrencyRate();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCalculator Currency Will Be Here...\n";
			clsCurrencyCalculator::CurrencyCalculatorScreen();
	}
	static void _GoBackToCurrencyMenu()
	{
		cout << "\nPress Any Key To Go Back To Currency Menu...";
		system("pause>0");
		ShowCurrencyMainScreen();
	}



	static void _PerfromCurrencyExchange(_enCurrencyExchange Currency)
	{
		switch (Currency)
		{
		case _enCurrencyExchange::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case _enCurrencyExchange::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case _enCurrencyExchange::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case _enCurrencyExchange::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case _enCurrencyExchange::eMainMenu:
		{
			//Do Nothing here the main screen will be handle it -:);
			//+ You Can Not Adding Break Because This is Last Case;
		}
		}
	}

public:
	static void ShowCurrencyMainScreen()
	{
		system("cls");
		_DrawActionHeaderScreen("   Currency exchange Main Screen");

		cout << setw(37) << left << "" << "\t========================================\n\n";
		cout << setw(37) << left << "" << "\t\t   Currency Exchange Menu.\n\n";
		cout << setw(37) << left << "" << "\t========================================\n";
		cout << setw(37) << left << "" << "\t [1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t [2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t [3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t [4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t [5] Main Menu.\n";
		cout << setw(37) << left << "" << "\t========================================\n";
		_PerfromCurrencyExchange((_enCurrencyExchange)_ReadChooceCurrency());
	}
};

