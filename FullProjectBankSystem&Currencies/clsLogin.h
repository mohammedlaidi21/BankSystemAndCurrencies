#pragma once
#include <iostream>
#include "clsMainMenu.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsUtility.h"
#include "Global.h"

using namespace std;


class clsLogin : protected clsScreen
{
private:
	static bool _Login()
	{
		string Username, Password;
		bool FaildLogin = false;
		short Counter = 0;

		do
		{
			if (FaildLogin)
			{
				Counter++;
				cout << "\nInvalid Username/Password: ";
				cout << "\nYou have " << (3 - Counter) << " Trial(s) To Login.\n";
			}

			if (Counter == 3)
			{
				cout << "\nYou Are Loocked After 3 Failds To Login.\n\n";
				return false;
			}

			cout << "\nPlease Entre Username: ";
			Username = clsInputValidate::ReadString();
			cout << "Please Entre Password : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username, Password);

			FaildLogin = CurrentUser.isEmpty();

		} while (FaildLogin);
		
		CurrentUser.RegisterLoginsToFile();
		clsMainMenu::ShowMainMenueScreen();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawActionHeaderScreen("\t     Login Screen");
		return _Login();

	}
};

