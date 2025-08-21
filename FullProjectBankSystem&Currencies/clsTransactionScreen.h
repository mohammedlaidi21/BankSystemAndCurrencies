#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainMenu.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionScreen : protected clsScreen
{
private:
	enum _enTransactionOption {
		eDepositBalance = 1, eWithdrawBalance = 2, eTotalBalances = 3,
		eTransfer = 4, eTransferLog = 5, eMainMenue = 6
	};

	static short ReadChooceOptions()
	{
		short Chooce = 1;

		cout << setw(37) << left << "" << "\tChooce What Do You Want To Do? [1 To 6]: ";
		Chooce = clsInputValidate::ReadIntNumberBetween(1, 6, "\t\t\t\t\tWhat Do You Want To Do? [1 To 6]: ");

		return Chooce;
	}

	static void _GoBackToTransactionMenueScreen()
	{
		cout << "\n\nPress Any Key To Go To Transaction Menu Screen...";
		system("Pause>0");
		TransactionScreen();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::DepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::WithdrawScreen();
	}
	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::TotalBalancesScreen();
	}
	static void _ShowTransferScreen()
	{
		clsTransferScreen::TransferScreen();
	}
	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::TransferLogScreen();
	}


	static void _PerformTransactionMenu(_enTransactionOption Option)
	{
		switch (Option)
		{
		case _enTransactionOption::eDepositBalance:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenueScreen();
			break;
		case _enTransactionOption::eWithdrawBalance:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenueScreen();
			break;
		case _enTransactionOption::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenueScreen();
			break;
		case _enTransactionOption::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenueScreen();
		case _enTransactionOption::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenueScreen();
		case _enTransactionOption::eMainMenue:
			//do nothing here the main screen will handle it :-) ;
			break;
		}
	}

public:
	static void TransactionScreen()
	{
		if (!isCheckPermission(clsUser::enPermission::pTransaction))
		{
			return;// this will exit the function and it will not continue
		}
		system("cls");
		_DrawActionHeaderScreen("\t   Transaction Screen");

		cout << setw(37) << left << "" << "\t=======================================\n\n";
		cout << setw(37) << left << "" << "\t\tTransaction Menu Screen\n\n";
		cout << setw(37) << left << "" << "\t=======================================\n";
		cout << setw(37) << left << "" << "\t[1] Depisit Balance.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw Balance.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "\t=======================================\n";
		_PerformTransactionMenu((_enTransactionOption)ReadChooceOptions());
	}
};

