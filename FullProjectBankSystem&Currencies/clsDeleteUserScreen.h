#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{

private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card: ";
		cout << "\n_____________________________________";
		cout << "\nAccount Number: " << User.UserName;
		cout << "\nFirst Name    : " << User.firstname;
		cout << "\nLast Name     : " << User.lastname;
		cout << "\nFull Name     : " << User.FullName();
		cout << "\nEmail         : " << User.email;
		cout << "\nPhone         : " << User.phone;
		cout << "\nPassword      : " << User.Password;
		cout << "\nPermission    : " << User.Permission;
		cout << "\n_____________________________________";
	}




public:
	static void DeleteUserScreen()
	{
		_DrawActionHeaderScreen("\t Delete User Screen");
		string Username = "";

		cout << "\nPlease Entre Username: ";
		Username = clsInputValidate::ReadString();

		while (!clsUser::isUserExist(Username))
		{
			cout << "This User Not Found, Please Entre Again: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);
		_PrintUser(User);

		cout << "\nAre You Sure You Want Delete This User? Y/N: ";
		char Answer = 'Y';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully:-)\n";
				_PrintUser(User);
			}
			else
			{
				cout << "\nCannot Be Deleted Admin!!\n";
			}
		}

	}
};

