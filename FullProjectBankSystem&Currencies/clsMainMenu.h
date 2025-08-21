#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListClientScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsRegisterLoginScreen.h"
#include"clsCurrencyMainScreen.h"
#include "Global.h"


using namespace std;


class clsMainMenu : protected clsScreen
{
private:
	enum _enChooceUser {
		eListClient = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eTransaction = 6, eManageUsers = 7, eRegisterLogin = 8,
		eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadChooceClient()
	{
		short chooce = 1;
		cout << setw(37) << left << "" << "\tChooce What Do You want To Do? [1 To 10]: ";
		chooce = clsInputValidate::ReadIntNumberBetween(1, 10, 
			"\t\t\t\t\tEntre Chooce Between [1 To 10]: ");

		return chooce;
	}

	static void _ShowListClientScreen()
	{	
		clsListClientScreen::ClientlistScreen();
	}
	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::AddNewClientScreen();
	}
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::DeleteClientScreen();
	}
	static void _ShowUpdateInfoClientScreen()
	{
		clsUpdateClientScreen::UpdateClientScreen();
	}
	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::FindClientScreen();
	}
	static void _ShowTransactionScreen()
	{
		clsTransactionScreen::TransactionScreen();
	}
	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ManageUsersScreen();
	}
	static void _ShowRegisterLoginScreen()
	{
		clsRegisterLoginScreen::RegisterLoginScreen();
	}
	static void _CurrencyMainScreen()
	{
		clsCurrencyMainScreen::ShowCurrencyMainScreen();
	}
	static void _Logout()
	{
		//clsLogoutScreen::ShowLogoutScreen(); ==> Error!!!!!
		CurrentUser = clsUser::Find("", "");
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\n\n\tPress Any Key To Go Back To Main Menu...";
		system("pause>0");
		ShowMainMenueScreen();
	}

	static void _PerFromChooceClient(_enChooceUser _ChooceUser)
	{
		switch (_ChooceUser)
		{
		case _enChooceUser::eListClient:
			system("cls");
			_ShowListClientScreen();
			_GoBackToMainMenu();
			break;
		case _enChooceUser::eAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		case _enChooceUser::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		case _enChooceUser::eUpdateClient:
			system("cls");
			_ShowUpdateInfoClientScreen();
			_GoBackToMainMenu();
			break;
		case _enChooceUser::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		case _enChooceUser::eTransaction:
			system("cls");
			_ShowTransactionScreen();
			_GoBackToMainMenu();
			break;
		case _enChooceUser::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		case _enChooceUser::eRegisterLogin:
			system("cls");
			_ShowRegisterLoginScreen();
			_GoBackToMainMenu();
		case _enChooceUser::eCurrencyExchange:
			system("cls");
			_CurrencyMainScreen();
			_GoBackToMainMenu();
		case _enChooceUser::eExit:
			system("cls");
			_Logout();
			break;
		}
	}
public:

	static void ShowMainMenueScreen()
	{
	
		system("cls");
		_DrawActionHeaderScreen("\t\tMain Screen");
		cout << setw(37) << left << "" << "\t=====================================\n\n";
		cout << setw(37) << left << "" << "\t\t  Main Menue Screen\n\n";
		cout << setw(37) << left << "" << "\t=====================================\n";
		cout << setw(37) << left << "" << "\t[1] Show List Client.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Info Client.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transaction.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Register Logins.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "\t=====================================\n";
		_PerFromChooceClient((_enChooceUser)_ReadChooceClient());
	}




};

