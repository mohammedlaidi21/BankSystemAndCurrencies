#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtility.h"

using namespace std;

class clsListUsersScreen : protected clsScreen
{

private:
	static void _PrintUserInfo(clsUser User)
	{
		cout << setw(8) << left << "" << "|" << setw(14) << left << User.UserName;
		cout << "|" << setw(20) << left << User.FullName();
		cout << "|" << setw(22) << left << User.email;
		cout << "|" << setw(15) << left << User.phone;
		cout << "|" << setw(13) << left << User.Password;
		cout << "|" << setw(10) << left << User.Permission;
	}

public:
	static void ListUsersScreen()
	{
		vector<clsUser> vUsers = clsUser::GetAllUsers();
		string title = "\t List Users Screen";
		string SubTitle = " \t     (" + to_string(vUsers.size()) + ")Clients.";
		_DrawActionHeaderScreen(title, SubTitle);

		cout << setw(8) << left << "" << "\n\n\t_______________________________________________________________";
		cout << "______________________________________________\n\n";

		cout << setw(8) << left << "" << "|" << setw(14) << left << "User Name";
		cout << "|" << setw(20) << left << "Full Name";
		cout << "|" << setw(22) << left << "Email";
		cout << "|" << setw(15) << left << "Phone";
		cout << "|" << setw(13) << left << "PassWord";
		cout << "|" << setw(10) << left << "Permission";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
		cout << "______________________________________________\n\n";

		if (vUsers.size() == 0)
			cout << "\n\t\t\t\t\tNo Users available In The system!!\n";

		else
			for (clsUser& U : vUsers)
			{
				_PrintUserInfo(U);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
		cout << "______________________________________________\n";


	}
};

