#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

private:

	static short _ReadPermission()
	{
		short Permission = 0;
		char Answer = 'n';

		cout << "\nDo You Want To Give Access To All? Y/N: ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Permission = -1;
			return Permission;
		}

			cout << "\nDo You Want To Give Access To\n";

			cout << "Show List Client? Y/N: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::pListClient;
			}

			cout << "Show Add New Client? Y/N: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::pAddNewClient;
			}

			cout << "Show Delete Client? Y/N: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::pDeleteClient;
			}

			cout << "Show Update Client Info? Y/N: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::pUpdateClient;
			}

			cout << "Show Find Client? Y/N: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::pFindClient;
			}

			cout << "Show Transaction? Y/N: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::pTransaction;
			}

			cout << "Show Manage User? Y/N: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::pManageUsers;
			}

			cout << "Show Register Logins? Y/N: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::pRegisterLogin;
			}

		return Permission;
	}

	static void _ReadNewClientInfo(clsUser& User)
	{
		cout << "Please Entre First Name: ";
		User.firstname = clsInputValidate::ReadString();

		cout << "Please Entre Last Name : ";
		User.lastname = clsInputValidate::ReadString();

		cout << "Please Entre Email     : ";
		User.email = clsInputValidate::ReadString();

		cout << "Please Entre Phone     : ";
		User.phone = clsInputValidate::ReadString();

		cout << "Please Entre Password  : ";
		User.Password = clsInputValidate::ReadString();

		User.Permission = _ReadPermission();
	}

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
		cout << "\nPersmission   : " << User.Permission;
		cout << "\n_____________________________________";
	}


public:
	static void AddNewUserScreen()
	{

		_DrawActionHeaderScreen("\t Add New Client Screen");

		string Username = "";

		cout << "Please Entre Username: ";
		Username = clsInputValidate::ReadString();

		while (clsUser::isUserExist(Username))
		{
			cout << "\nUser Already Exist, Please Entre Again: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::GetaddNewUser(Username);
		_ReadNewClientInfo(User);

		clsUser::enSaveResult SaveResult;
		SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResult::svSuccessed:
		{
			cout << "\n\nClient Added Successfully:-)\n";
			_PrintUser(User);
			break;
		}
		case clsUser::enSaveResult::svFaildEmpty:
			cout << "\n\nError!!Not Save This User Because it's Empty:-(\n";
			break;
		case clsUser::enSaveResult::svFaildUsername:
			cout << "\n\nError!!Not Save This User Because it's Already Exist:-(\n";
			break;
		}

	}
};

