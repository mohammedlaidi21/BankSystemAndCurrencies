#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;


class clsTransferLogScreen : protected clsScreen
{

private:
	static void _PrintListTransfertRecord(clsBankClient::stTransferLog RecordTransferLog)
	{
		cout << setw(8) << left << "" << "| " << setw(22) << left << RecordTransferLog.Date;
		cout << "| " << setw(8) << left << RecordTransferLog.SourceAccountNumber;
		cout << "| " << setw(8) << left << RecordTransferLog.DestinationAccountNumber;
		cout << "| " << setw(12) << left << RecordTransferLog.Amount;
		cout << "| " << setw(14) << left << RecordTransferLog.SourceBalance;
		cout << "| " << setw(14) << left << RecordTransferLog.DestinationBalance;
		cout << "| " << setw(10) << left << RecordTransferLog.UserName;
	}


public:
	static void TransferLogScreen()
	{
		vector<clsBankClient::stTransferLog> vListTransferLogS = 
			clsBankClient::GetTransferLogRecordFromFile();

		string Title = "\t  Transfer Log Screen";
		string SubTitle = "\t    (" + to_string(vListTransferLogS.size()) + ") Record(s).";

		_DrawActionHeaderScreen(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_________________________________________________________";
		cout << "_________________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << setw(22) << left << "Date/Time";
		cout << "| " << setw(8) << left << "S.Acc";
		cout << "| " << setw(8) << left << "D.Acc";
		cout << "| " << setw(12) << left << "Amount";
		cout << "| " << setw(14) << left << "S.Balance";
		cout << "| " << setw(14) << left << "D.Balance";
		cout << "| " << setw(10) << left << "User";

		cout << setw(8) << left << "" << "\n\t_________________________________________________________";
		cout << "_________________________________________________\n\n";

		if (vListTransferLogS.size() == 0)
			cout << "\nt\t\t\t\tNo Transfers Available In The System!\n";

		else
			for (clsBankClient::stTransferLog& RecordTr : vListTransferLogS)
			{
				_PrintListTransfertRecord(RecordTr);
				cout << endl;
			}
		
		cout << setw(8) << left << "" << "\n\t_________________________________________________________";
		cout << "_________________________________________________\n\n";

	}
};

