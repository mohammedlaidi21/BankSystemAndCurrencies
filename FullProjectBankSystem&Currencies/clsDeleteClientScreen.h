#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h"
#include "clsBankClient.h"


using namespace std;


class clsDeleteClientScreen:protected clsScreen 
{

private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nInfo Client:\n";
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
	static void DeleteClientScreen()
	{

		if (!isCheckPermission(clsUser::enPermission::pDeleteClient))
		{
			return; // this will exit the function and it will not continue
		}

		_DrawActionHeaderScreen("\t  Delete Client Screen");
		string AccNumber = "";

		cout << "\nEntre Account Number Client You Want Delete: ";
		AccNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExist(AccNumber))
		{
			cout << "This Account Number Not Found, Entre Again: ";
			AccNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccNumber);
		_PrintClient(Client);

		char Answer = 'N';
		cout << "\nAre You Sure You Want Delete This client? Y/N: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully-:)\n";
				_PrintClient(Client);
			}
			else
				cout << "\nError!!Client Was Not Deleted:-(";
		}
		

	}
};

