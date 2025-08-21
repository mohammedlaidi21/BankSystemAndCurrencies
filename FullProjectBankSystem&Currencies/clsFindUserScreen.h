#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
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
	static void FindUserScreen()
	{
		_DrawActionHeaderScreen("\t Find User Screen");

		string Username = "";
		cout << "\nPlease Entre User Name: ";
		Username = clsInputValidate::ReadString();


		while (!clsUser::isUserExist(Username))
		{
			cout << "\nThis User is Not Found, Please Entre Again: ";
			Username = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(Username);


		if (!User.isEmpty())
		{
			cout << "\nUser Found:-): \n";
		}
		else
		{
			cout << "\nUser Was Not Found:-(\n";
		}
		
		_PrintUser(User);

	}
};

