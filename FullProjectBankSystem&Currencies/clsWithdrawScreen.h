#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:
	static string _ReadAccountNumber()
	{
		string AccNumber = "";

		cout << "\nPlease Entre Account Number: ";
		cin >> AccNumber;

		return AccNumber;
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
	static void WithdrawScreen()
	{
		_DrawActionHeaderScreen("\t  Withdraw Screen");

		string AccNumber = "";

		AccNumber = _ReadAccountNumber();

		while (!clsBankClient::isClientExist(AccNumber))
		{
			cout << "\nClient With [" << AccNumber << "] Does Not Exist.\n";
			AccNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "please Entre Withdraw Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > Client.Accountbalance)
		{
			cout << "Your Balance Less Than Amount, Please Entre Amount: ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		char Answer = 'N';

		cout << "\nAre You Sure You Want Perform This Transaction? Y/N: ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if(Client.Withdraw(Amount))
			{
				cout << "\nBalance Withdrawed Successfully!\n";
				cout << "\nNew Balance: " << Client.Accountbalance;
			}
			else
			{
				cout << "\nCannot Withdraw, Insuffecient Balance!";
				cout << "\nAmount To Withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.Accountbalance;
			}
		}
		else
			cout << "\nOperation Was Cancelled!!\n";

	}
};

