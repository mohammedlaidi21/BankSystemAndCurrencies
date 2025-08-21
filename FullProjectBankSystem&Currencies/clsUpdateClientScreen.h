#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:
	static void _ReadInfoClient(clsBankClient& Client)
	{
		cout << "Entre First Name     : ";
		Client.firstname = clsInputValidate::ReadString();

		cout << "Entre Last Name      : ";
		Client.lastname = clsInputValidate::ReadString();

		cout << "Entre Email          : ";
		Client.email = clsInputValidate::ReadString();

		cout << "Entre Phone          : ";
		Client.phone = clsInputValidate::ReadString();

		cout << "Entre Pin Code       : ";
		Client.Pincode = clsInputValidate::ReadString();

		cout << "Entre Account Balance: ";
		Client.Accountbalance = clsInputValidate::ReadDblNumber();
	}
	static void _PrintClient(clsBankClient Client)
	{
		cout << "Info Client:\n";
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
	static void UpdateClientScreen()
	{

		if (!isCheckPermission(clsUser::enPermission::pUpdateClient))
		{
			return; // this will exit the function and it will not continue
		}

		_DrawActionHeaderScreen("\tUpdate Client Screen");

		string AccNumber = "";

		cout << "Please Entre Account Number Client You Want Update: ";
		AccNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExist(AccNumber))
		{
			cout << "This Account Number Not Found,Please  Entre Again: ";
			AccNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccNumber);
		_PrintClient(Client);

		char Answer = 'Y';

		cout << "\nAre You Sure You Want Updated This Client? Y/N: ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate Info Client: \n";

			cout << "____________________________\n";
			_ReadInfoClient(Client);
			cout << "____________________________\n";

			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::svSuccessedObject:
				cout << "\n\nClient Updated Successfully:-)\n\n";
				_PrintClient(Client);
				break;
			case clsBankClient::svFaildEmptyObject:
				cout << "\nError!!Client Was Not Saved Because is Empty:-(\n";
				break;
			}

		}

		

	}
};

