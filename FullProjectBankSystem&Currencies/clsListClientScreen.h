#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"


using namespace std;

class clsListClientScreen : protected clsScreen
{
private:
	static void _PrintAllClientList(clsBankClient Cl)
	{
		cout << setw(8) << left << "" << "|" << setw(16) << left << Cl.AccountNumber();
		cout << "|" << setw(25) << left << Cl.FullName();
		cout << "|" << setw(22) << left << Cl.email;
		cout << "|" << setw(12) << left << Cl.phone;
		cout << "|" << setw(11) << left << Cl.Pincode;
		cout << "|" << setw(10) << left << Cl.Accountbalance;
	}

public:

	static void ClientlistScreen()
	{

		if (!isCheckPermission(clsUser::enPermission::pListClient))
		{
			return; // this will exit the function and it will not continue
		}


		vector<clsBankClient> vClients = clsBankClient::GetListClient();

		string Title = "\t   List Client Screen";
		string SubTitle = "\t     (" + to_string(vClients.size()) + ") Client(s).";

		_DrawActionHeaderScreen(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_____________________________________________________________________";
		cout << "_______________________________\n\n";
		cout << setw(8) << left << "" << "|" << setw(16) << left << "Account Number";
		cout << left << "|" << setw(25) << "Name";
		cout << left << "|" << setw(22) << "Email";
		cout << left << "|" << setw(12) << "Phone";
		cout << left << "|" << setw(11) << "Pin Code";
		cout << left << "|" << setw(10) << "Balances";
		cout << setw(8) << left << "" << "\n\t_____________________________________________________________________";
		cout << "_______________________________\n\n";

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\t\tNo Clients Available In The System\n";
		}
		else
			for (clsBankClient& Cl : vClients)
			{
				_PrintAllClientList(Cl);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_____________________________________________________________________";
		cout << "_______________________________\n\n";
	}
};

