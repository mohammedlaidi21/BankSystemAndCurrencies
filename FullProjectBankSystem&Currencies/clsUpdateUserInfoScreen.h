#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateUserInfoScreen : protected clsScreen
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

	static short _ReadPermissionUser()
	{
		short Permission = 0;

		char Answer = 'Y';

		cout << "\nAre You Want To Access To All? Y/N: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			return Permission = -1;
		}

		cout << "\nAre You Want To Access To: ";

		cout << "\nShow Client List? Y/N: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUser::pListClient;
		}

		cout << "\nShow Add New Client? Y/N: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUser::pAddNewClient;
		}

		cout << "\nShow Delete Client? Y/N: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUser::pDeleteClient;
		}

		cout << "\nShow Update Info Client? Y/N: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUser::pUpdateClient;
		}

		cout << "\nShow Find Client? Y/N: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUser::pFindClient;
		}

		cout << "\nShow Transaction? Y/N: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUser::pTransaction;
		}

		cout << "\nShow Manage Users? Y/N: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUser::pManageUsers;
		}

		cout << "\nShow Register Logins? Y/N: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permission += clsUser::pRegisterLogin;
		}

		return Permission;
	}

	static void _ReadInfoUser(clsUser& User)
	{
		cout << "Entre First Name: ";
		User.firstname = clsInputValidate::ReadString();

		cout << "Entre Last Name : ";
		User.lastname = clsInputValidate::ReadString();

		cout << "Entre Email     : ";
		User.email = clsInputValidate::ReadString();

		cout << "Entre Phone     : ";
		User.phone = clsInputValidate::ReadString();

		cout << "Entre Password  : ";
		User.Password = clsInputValidate::ReadString();

		User.Permission = _ReadPermissionUser();
	}


public:
	static void UpdateUserInfoScreen()
	{
		_DrawActionHeaderScreen("\t Update User Screen");

		string UserName = "";

		cout << "Please Entre AccNumber: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::isUserExist(UserName))
		{
			cout << "This User is Not Found, Please Entre Again: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
		cout << "\nAre You Sure You Want Update This User? Y/N: ";
		char Answer = 'Y';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\nUpdate User Info: ";
			cout << "\n__________________________\n";

			_ReadInfoUser(User);
			cout << "__________________________\n";

			clsUser::enSaveResult SaveResult;
			SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::svSuccessed:
			{
				cout << "\nUser Updated Successfully:-)\n";
				_PrintUser(User);
				break;
			}
			case clsUser::svFaildEmpty:
				cout << "\nError Not Save This User Because It's Empty:-(\n";
				break;
			}
		}
		


	}

};

