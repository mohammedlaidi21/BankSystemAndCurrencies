#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDepositScreen : protected clsScreen
{
private:
	static string _ReadAccountNumber()
	{
		string accNumber = "";

		cout << "\nPlease Entre Account Number: ";
		cin >> accNumber;

		return accNumber;
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
	static void DepositScreen()
	{
		_DrawActionHeaderScreen("\t   Deposit Screen");

		string AccountNumber = "";

		AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::isClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] Does Not Exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;

		cout << "\nPlease Entre Deposit Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		/*while (Amount > Client.Accountbalance)
		{
			cout << "Your Balance Less Than Deposit, Please Entre Balance:  ";
			Amount = clsInputValidate::ReadDblNumber();
		}*/

		char answer = 'Y';

		cout << "\nAre You Sure You Want To Perform This Transaction? Y/N: ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			Client.Deposit(Amount);
			cout << "\n\nAmount Deposited Successfully: ";
			cout << "\nNew Balance is: " << Client.Accountbalance;
		}
		else
			cout << "\nOperation Was Cancelled.\n";
	}
};

