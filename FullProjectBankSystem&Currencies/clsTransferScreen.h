#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;


class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintCardClient(clsBankClient Client)
	{
		cout << "\nClient Card: ";
		cout << "\n_______________________________";
		cout << "\nFull Name     : " << Client.FullName();
		cout << "\nAccount Number: " << Client.AccountNumber();
		cout << "\nBalance       : " << Client.Accountbalance;
		cout << "\n_______________________________\n";

	}

	static string _ReadAccountNumber(string Message)
	{
		string AccNumber;

		cout << Message;
		AccNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExist(AccNumber))
		{
			cout << "\nClient Not Found, Please Entre Again: ";
			AccNumber = clsInputValidate::ReadString();
		}
		return AccNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount;
		cout << "\nEntre Transfer Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.Accountbalance)
		{
			cout << "\nAmount Exceeds The Available Balance, Entre Another Amount: ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		return Amount;
	}

public:

	static void TransferScreen()
	{
		_DrawActionHeaderScreen("\t   Transfer Screen");
		clsBankClient SourceClient =
			clsBankClient::Find(_ReadAccountNumber("\nPlease Entre Account Number To Transfer From: "));
		_PrintCardClient(SourceClient);

		clsBankClient DestinationClient =
			clsBankClient::Find(_ReadAccountNumber("\nPlease Entre Account Number To Transfer To: "));
		while (SourceClient.AccountNumber() == DestinationClient.AccountNumber())
		{
			cout << "\nThis Client it's Transfer From,";
			   DestinationClient =
				clsBankClient::Find(_ReadAccountNumber("\nPlease Entre Account Number To Transfer To: "));
		}
		_PrintCardClient(DestinationClient);

		

		double Amount = _ReadAmount(SourceClient);


		char Answer = 'n';

		cout << "\nAre You Sure You Want Perform This operation? Y/N: ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully:-)\n";
				
			}
			else
			{
				cout << "\nTransfer Faild\n";
			}
		}
		_PrintCardClient(SourceClient);
		_PrintCardClient(DestinationClient);
	}
	
};

