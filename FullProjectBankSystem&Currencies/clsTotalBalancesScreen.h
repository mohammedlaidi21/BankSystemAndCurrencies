#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtility.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{


private:

	static void _PrintAllClient(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "\t|" << setw(18) << left << Client.AccountNumber();
		cout << "|" << setw(22) << left << Client.FullName();
		cout << "|" << setw(10) << left << Client.Accountbalance;
	}

public:
	static void TotalBalancesScreen()
	{
		vector <clsBankClient> vClient = clsBankClient::GetListClient();


		string Title = "\t  Total Balances Screen";
		string SubTitle = "\t\t(" + to_string(vClient.size()) + ") Clients";

		_DrawActionHeaderScreen(Title, SubTitle);

		cout << setw(25) << left << "" << "\t___________________________________________________________\n\n";
		cout << setw(25) << left << "" << "\t|" << setw(18) << left << "Account Number";
		cout << "|" << setw(22) << left << "Client Name";
		cout << "|" << setw(10) << left << "Balances\n";
		cout << setw(25) << left << "" << "\t___________________________________________________________\n";

		double TotalBalances = clsBankClient::TotalBalances();

		if (vClient.size() == 0)
			cout << "\n\t\t\t\t\tNo Client Available In The System!!!\n";

		else
			for (clsBankClient& Cl : vClient)
			{
				_PrintAllClient(Cl);
				cout << endl;
			}

		cout << setw(25) << left << "" << "\t___________________________________________________________\n";
		

		cout << "\n\n\t\t\t\t\t\tTotal Balances: " << TotalBalances << endl;
		cout << "\t\t\t\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ")\n";
	}
};

