#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"

using namespace std;
string FileClient = "Clients.txt";

class clsBankClient : public clsPerson
{
private:
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;

	enum enMode
	{
		emptyMode = 0, updateMode = 1, AddMode = 2
	};
	enMode _Mode;

	static clsBankClient _ConvertLineToObject(string Line, string Separator = "#//#")
	{
		vector<string> vStrings;
			vStrings = clsString::Split(Line, Separator);

		if (vStrings.size() != 7)
			return _EmptyObjectClient();

		return clsBankClient(enMode::updateMode, vStrings[0], vStrings[1], vStrings[2], vStrings[3], 
			vStrings[4], vStrings[5], stod(vStrings[6]));
	}
	static string _ConvertObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string Cl = "";

		Cl += Client.AccountNumber() + Separator;
		Cl += Client.firstname + Separator;
		Cl += Client.lastname + Separator;
		Cl += Client.email + Separator;
		Cl += Client.phone + Separator;
		Cl += Client.Pincode + Separator;
		Cl += to_string(Client.Accountbalance);

		return Cl;
	}
	static clsBankClient _EmptyObjectClient()
	{
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadDataFileToVector()
	{
		fstream MyFile;
		vector <clsBankClient> vClients;
		MyFile.open(FileClient, ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsBankClient Client = _ConvertLineToObject(line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	static void _SaveDataVectorToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;

		MyFile.open(FileClient, ios::out); //Write Mode

		if (MyFile.is_open())
		{
			string line;

			for (clsBankClient& Cl : vClients)
			{
				if (!Cl.isEmpty())
				{
					if (Cl.MarkForDelete() == false)
					{
						line = _ConvertObjectToLine(Cl);
						MyFile << line << endl;
					}
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadDataFileToVector();

		for (clsBankClient& Cl : _vClients)
		{
			if (Cl.AccountNumber() == AccountNumber())
			{
				Cl = *this;
				break;
			}
		}
		_SaveDataVectorToFile(_vClients);
	}

	void _AddDataLineToFile(string Line)
	{
		fstream Myfile;

		Myfile.open(FileClient, ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << Line << endl;

			Myfile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertObjectToLine(*this));
	}

	string _PrepareTransferRecord(clsBankClient DestinationClient,double Amount,string UserName, string Separator = "#//#")
	{
		string TransferLogRecord;

		TransferLogRecord += clsDate::GetDateLocalTimeString() + Separator;
		TransferLogRecord += AccountNumber() + Separator;
		TransferLogRecord += DestinationClient.AccountNumber() + Separator;
		TransferLogRecord += to_string(Amount) + Separator;
		TransferLogRecord += to_string(Accountbalance) + Separator;
		TransferLogRecord += to_string(DestinationClient.Accountbalance) + Separator;
		TransferLogRecord += UserName;

		return TransferLogRecord;
	}

	void _CreateTransferLogToFile(clsBankClient DestinationClient, double Amount, string UserName)
	{
		fstream MyFile;

		MyFile.open("TansferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			string line;
			line = _PrepareTransferRecord(DestinationClient, Amount, UserName);
			MyFile << line << endl;

			MyFile.close();
		}
	}

	struct stTransferLog;
	static stTransferLog _ConvertLineToTransferLogRecord(string Line, string separator = "#//#")
	{
		stTransferLog transferLogRecord;

		vector<string> vStrings = clsString::Split(Line, separator);

		transferLogRecord.Date = vStrings[0];
		transferLogRecord.SourceAccountNumber = vStrings[1];
		transferLogRecord.DestinationAccountNumber = vStrings[2];
		transferLogRecord.Amount = stod(vStrings[3]);
		transferLogRecord.SourceBalance = stod(vStrings[4]);
		transferLogRecord.DestinationBalance = stod(vStrings[5]);
		transferLogRecord.UserName = vStrings[6];

		return transferLogRecord;
	}

public:
	clsBankClient(enMode Mode, string AccountNumber, string FirstName, string LastName, string Email, string Phone, string PinCode, double AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		this->_Mode = Mode;
		this->_AccountNumber = AccountNumber;
		this->_PinCode = PinCode;
		this->_AccountBalance = AccountBalance;
	};

	struct stTransferLog
	{
		string Date;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		double Amount;
		double SourceBalance;
		double DestinationBalance;
		string UserName;
	};

	bool isEmpty()
	{
		return (_Mode == enMode::emptyMode);
	}

	//Getters & Setters
	string AccountNumber()
	{
		return _AccountNumber;
	}

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}

	void setPinCode(string pinCode)
	{
		_PinCode = pinCode;
	}
	string PinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = PinCode, put = setPinCode)) string Pincode;

	void setAccountBalance(double accountBalance)
	{
		_AccountBalance = accountBalance;
	}
	double AccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = AccountBalance, put = setAccountBalance)) double Accountbalance;

	/*void Print()
	{
		cout << "Info Client:\n";
		cout << "___________________________\n";
		cout << "\nAccount Number : " << _AccountNumber;
		cout << "\nFirst Name     : " << FirstName();
		cout << "\nLast Name      : " << LastName();
		cout << "\nFull Name      : " << FullName();
		cout << "\nEmail          : " << Email();
		cout << "\nPhone          : " << Phone();
		cout << "\nPin Code       : " << _PinCode;
		cout << "\nAccount Balance: " << _AccountBalance;
		cout << "\n___________________________\n";
	}*/

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open(FileClient, ios::in);//ReadMode

		if (MyFile.is_open())
		{
			string line;

			while(getline(MyFile, line))
			{
				clsBankClient Client = _ConvertLineToObject(line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _EmptyObjectClient();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open(FileClient, ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsBankClient Client = _ConvertLineToObject(line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode() == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _EmptyObjectClient();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSuccessedObject = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::emptyMode:
		{
			if (isEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::updateMode:
		{
			_Update();
			return enSaveResults::svSuccessedObject;
			break;
		}
		case enMode::AddMode:
		{
			if (clsBankClient::isClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::updateMode;
				return enSaveResults::svSuccessedObject;
			}
			break;
		}
		}
	}
	static clsBankClient GetAddNewClientObject(string AccNumber)
	{
			return clsBankClient(enMode::AddMode, AccNumber, "", "", "", "", "", 0);
	}

	static bool isClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.isEmpty());
	}

	bool Delete()
	{
		vector <clsBankClient> vClients;
		vClients = _LoadDataFileToVector();

		for (clsBankClient& Cl : vClients)
		{
			if (Cl.AccountNumber() == _AccountNumber)
			{
				Cl._MarkForDelete = true;
				break;
			}
		}
		_SaveDataVectorToFile(vClients);

		*this = _EmptyObjectClient();
		return true;
	}

		short NumberClient = 0;

	 static vector <clsBankClient> GetListClient()
	 {
		 return _LoadDataFileToVector();
	 }

	 static double TotalBalances()
	 {
		 double TotBalances = 0;
		 vector<clsBankClient> vClients = _LoadDataFileToVector();

		 for (clsBankClient& Cl : vClients)
		 {
			 TotBalances += Cl.Accountbalance;
		 }
		 return TotBalances;
	 }

	 void Deposit(double Amount)
	 {
		 Accountbalance += Amount;
		 Save();
	 }

	 bool Withdraw(double Amount)
	 {
		 if (Amount > Accountbalance)
		 {
			 return false;
		 }
		 else
		 {
			 Accountbalance -= Amount;
			 Save();
		 }
	 }


	 bool Transfer(double Amount, clsBankClient& DestinationClient, string UserName)
	 {
		 if (Amount > Accountbalance)
		 {
			 return false;
		 }

		 Withdraw(Amount);
		 DestinationClient.Deposit(Amount);
		 _CreateTransferLogToFile(DestinationClient, Amount, UserName);
		 return true;
	 }

	 static vector<stTransferLog> GetTransferLogRecordFromFile()
	 {
		 vector<stTransferLog> vTransferLogs;

		 fstream MyFile;
		 MyFile.open("TansferLog.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string line;
			 stTransferLog TransferLogRecord;
			 while (getline(MyFile, line))
			 {
			     TransferLogRecord = _ConvertLineToTransferLogRecord(line);
				 vTransferLogs.push_back(TransferLogRecord);
			 }
			 MyFile.close();
		 }
		 return vTransferLogs;
	 }

};

