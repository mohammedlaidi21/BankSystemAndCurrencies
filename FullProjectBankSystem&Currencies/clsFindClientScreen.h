#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;


class clsFindClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\nClient Info Card:\n";
		cout << "___________________________\n";
		cout << "\nAccount Number : " << Client.AccountNumber();
		cout << "\nFirst Name     : " << Client.firstname;
		cout << "\nLast Name      : " << Client.lastname;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.email;
		cout << "\nPhone          : " << Client.phone;
		cout << "\nPin Code       : " << Client.Pincode;
		cout << "\nAccount Balance: " << Client.Accountbalance;
		cout << "\n___________________________\n";
	}


public:
	static void FindClientScreen()
	{
		if (!isCheckPermission(clsUser::pFindClient))
		{
			return; // this will exit the function and it will not continue
		}

		_DrawActionHeaderScreen("\tFind Client Screen");

		string AccNumber = "";

		cout << "\nPlease Entre Account Number: ";
		AccNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExist(AccNumber))
		{
			cout << "This Account Not Found, Entre Another One: ";
			AccNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccNumber);

		if (!Client.isEmpty())
		{
			cout << "\nClient Found:-)\n";
		}
		else
		{
			cout << "\nClient Was Not Found:-(\n";
		}

		_PrintClient(Client);
	}
};

