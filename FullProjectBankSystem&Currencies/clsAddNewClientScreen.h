#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;


class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadNewClient(clsBankClient& NewClient)
	{
		
		cout << "Entre First Name     : ";
		NewClient.firstname = clsInputValidate::ReadString();

		cout << "Entre Last Name      : ";
		NewClient.lastname = clsInputValidate::ReadString();

		cout << "Entre Email          : ";
		NewClient.email = clsInputValidate::ReadString();

		cout << "Entre Phone          : ";
		NewClient.phone = clsInputValidate::ReadString();

		cout << "Entre Pin code       : ";
		NewClient.Pincode = clsInputValidate::ReadString();

		cout << "Entre Account Balance: ";
		NewClient.Accountbalance = clsInputValidate::ReadDblNumber();
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

	static void AddNewClientScreen()
	{

		if (!isCheckPermission(clsUser::enPermission::pAddNewClient))
		{
			return; // this will exit the function and it will not continue
		}

		_DrawActionHeaderScreen("\tAdd New Client Screen");
		string AccNumber = "";

		cout << "\nEntre Account Number : ";
		AccNumber = clsInputValidate::ReadString();

		while (clsBankClient::isClientExist(AccNumber))
		{
			cout << "This Account Already Exist, Entre Again: ";
			AccNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccNumber);
		_ReadNewClient(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svSuccessedObject:
			cout << "\nClient Added Successfully-:)\n\n";
			_PrintClient(NewClient);
			break;
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError!!Not Save This Account Because is Empty!";
			break;
		case clsBankClient::svFaildAccountNumberExists:
			cout << "\nError!!Not Save This Account Because is Already Exist!";
			break;
		}

	}
};

