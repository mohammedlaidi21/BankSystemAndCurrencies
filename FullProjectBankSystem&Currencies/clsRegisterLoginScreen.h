#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"


using namespace std;


class clsRegisterLoginScreen : protected clsScreen
{
private:
	static void _PrintRegisterLoginsUser(clsUser::stRegisterLogins RegisterLogins)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << RegisterLogins.Date;
		cout << "| " << setw(14) << left << RegisterLogins.UserName;
		cout << "| " << setw(10) << left << RegisterLogins.Password;
		cout << "| " << setw(8) << left << RegisterLogins.Permissions;
	}



public:
	static void RegisterLoginScreen()
	{

		if (!isCheckPermission(clsUser::enPermission::pRegisterLogin))
		{
			return;
		}


		vector <clsUser::stRegisterLogins> vRegisterLogins = clsUser::GetRegisterLoginsFromFile(); 
		string Title = "\t Register Login Screen.";
		string SubTitle = "\t   (" + to_string(vRegisterLogins.size()) + ") Record(s).";
		_DrawActionHeaderScreen(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_____________________________________________________________________________\n\n";
		cout << setw(8) << left << "" << "| " << setw(25) << left << "Date/Time";
		cout << "| " << setw(14) << left << "UserName";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(8) << left << "Permission";
		cout << setw(8) << left << "" << "\n\t_____________________________________________________________________________\n\n";
		
		if (vRegisterLogins.size() == 0)
			cout << "\n\t\t\t\t\tNo Register Available Logins In The System.\n";

		else
			for (clsUser::stRegisterLogins& RegLogins : vRegisterLogins)
			{
				_PrintRegisterLoginsUser(RegLogins);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_____________________________________________________________________________\n";

	}
};

