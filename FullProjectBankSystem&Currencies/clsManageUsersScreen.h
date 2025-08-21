#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserInfoScreen.h"
#include "clsFindUserScreen.h"

using namespace std;


class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersMenu {
		eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
	};
	static short _ReadChooceUser()
	{
		short Chooce = 1;

		cout << setw(32) << left << "" << "\tChooce What Do You Want To Do? [1 To 6]: ";
		Chooce = clsInputValidate::ReadIntNumberBetween(1, 6, "\t\t\t\t\tChooce What Do You Want To Do? [1 To 6]: ");

		return Chooce;
	}


	static void _ShowListUserScreen()
	{
		clsListUsersScreen::ListUsersScreen();
	}
	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::AddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::DeleteUserScreen();
	}
	static void _ShowUpdateInfoUserScreen()
	{
		clsUpdateUserInfoScreen::UpdateUserInfoScreen();
	}
	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::FindUserScreen();
	}

	static void _GoBackToManagUsersMenu()
	{
		cout << "\n\nPress Any Key To Back To Manage User Menu...";
		system("pause>0");
		ManageUsersScreen();
	}

	static void _PerfromManageUserMenu(enManageUsersMenu _OptionUser)
	{
		switch (_OptionUser)
		{
		case enManageUsersMenu::eListUser:
			system("cls");
			_ShowListUserScreen();
			_GoBackToManagUsersMenu();
			break;
		case enManageUsersMenu::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManagUsersMenu();
			break;
		case enManageUsersMenu::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManagUsersMenu();
			break;
		case enManageUsersMenu::eUpdateUser:
			system("cls");
			_ShowUpdateInfoUserScreen();
			_GoBackToManagUsersMenu();
			break;
		case enManageUsersMenu::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManagUsersMenu();
			break;
		case enManageUsersMenu::eMainMenu:
		{
			//Do Nothing
		}

		}
	}

public:
	static void ManageUsersScreen()
	{
		
		if (!isCheckPermission(clsUser::enPermission::pManageUsers))
		{
			return; // this will exit the function and it will not continue
		}


		system("cls");
		_DrawActionHeaderScreen("\t  Manage Users Screen");

		cout << "\n\n\n";
		cout << setw(32) << left << "" << "\t==========================================\n\n";
		cout << setw(32) << left << "" << "\t\t    Manage Users Menue\n\n";
		cout << setw(32) << left << "" << "\t==========================================\n";
		cout << setw(32) << left << "" << "\t[1] List User.\n";
		cout << setw(32) << left << "" << "\t[2] Add New User.\n";
		cout << setw(32) << left << "" << "\t[3] Delete User.\n";
		cout << setw(32) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(32) << left << "" << "\t[5] Find User.\n";
		cout << setw(32) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(32) << left << "" << "\t==========================================\n";
		_PerfromManageUserMenu((enManageUsersMenu)_ReadChooceUser()); 
	}
};

