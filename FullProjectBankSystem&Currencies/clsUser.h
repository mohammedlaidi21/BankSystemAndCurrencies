#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtility.h"
#include "Global.h"

using namespace std;

class clsUser : public clsPerson
{

private:

	enum enMode { enEmptyMode = 0, enUpdateMode = 1, eAddNewMode = 2 };
	enMode _Mode;
	string _Username;
	string _Password;
	short _Permission;

	bool _MarkForDelete = false;

	static clsUser _ConvertLineToObject(string Line, string separator = "#//#")
	{
		vector<string> vStrings;
		vStrings = clsString::Split(Line, separator);

		return clsUser(enMode::enUpdateMode, vStrings[0], vStrings[1], vStrings[2], vStrings[3],
			vStrings[4], clsUtil::DecryptText(vStrings[5]), stoi(vStrings[6]));
	}
	static string _ConvertObjectToLine(clsUser User, string Separator = "#//#")
	{
		string Str = "";

		Str += User.UserName + Separator;
		Str += User.firstname + Separator;
		Str += User.lastname + Separator;
		Str += User.email + Separator;
		Str += User.phone + Separator;
		Str += clsUtil::EncryptText(User.Password) + Separator;
		Str += to_string(User.Permission);

		return Str;
	}

	string _PrepareLoginRecord(string Separator = "#//#")
	{
		string Record = "";

		Record += clsDate::GetDateLocalTimeString() + Separator;
		Record += UserName + Separator;
		Record += clsUtil::EncryptText(Password)+Separator;
		Record += to_string(Permission);

		return Record;
	}

	struct stRegisterLogins;
	static stRegisterLogins _ConvertLineToRegisterRecord(string line, string separator = "#//#")  
	{
		stRegisterLogins RegisterLogins;

		vector<string> vStrings = clsString::Split(line, separator);

		RegisterLogins.Date = vStrings[0];
		RegisterLogins.UserName = vStrings[1];
		RegisterLogins.Password = clsUtil::DecryptText(vStrings[2]);
		RegisterLogins.Permissions = stoi(vStrings[3]);

		return RegisterLogins;
	}
	
	static clsUser _GetEmtyUser()
	{
		return clsUser(enMode::enEmptyMode, "", "", "", "", "", "", 0);
	}
	
	static vector<clsUser> _LoadDataFromFile()
	{
		fstream MyFile;
		vector <clsUser> vUsers;

		MyFile.open("Users.txt", ios::in);//ReadMode

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsUser User = _ConvertLineToObject(line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}
	static void _SaveDataToFile(vector<clsUser>& vUsers)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string line;

			for (clsUser& Us : vUsers)
			{
				if (Us._MarkForDelete == false)
				{
					line = _ConvertObjectToLine(Us);
					MyFile << line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsUser> vUsers = _LoadDataFromFile();

		for (clsUser& Us : vUsers)
		{
			if (Us.UserName == _Username)
			{
				Us = *this;
				break;
			}
		}
		_SaveDataToFile(vUsers);
	}

	void _AddDataLine(string line)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << line << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLine(_ConvertObjectToLine(*this));
	}

public:

	enum enPermission {
		pAll = -1, pListClient = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransaction = 32, pManageUsers = 64, pRegisterLogin = 128
	};

	struct stRegisterLogins
	{
		string Date;
		string UserName;
		string Password;
		short Permissions;
	};


	clsUser(enMode Mode, string Username, string firstName, string lastName, string email,
		string phone, string password, short permission) : clsPerson(firstName, lastName, email, phone)

	{
		this->_Mode = Mode;
		this->_Username = Username;
		this->_Password = password;
		this->_Permission = permission;
	};

	bool isEmpty()
	{
		return (_Mode == enMode::enEmptyMode);
	}

	//Getters & Setters
	void setUserName(string Username)
	{
		_Username = Username;
	}
	string getUserName()
	{
		return _Username;
	}

	__declspec(property(get = getUserName, put = setUserName)) string UserName;

	void setPassword(string Password)
	{
		_Password = Password;
	}
	string getPassword()
	{
		return _Password;
	}

	__declspec(property(get = getPassword, put = setPassword)) string Password;

	void setPermission(short per)
	{
		_Permission = per;
	}
	short getPermission()
	{
		return _Permission;
	}

	__declspec(property(get = getPermission, put = setPermission)) short Permission;


	bool getMarkForDelete()
	{
		return _MarkForDelete;
	}

	/*void Print()
	{
		cout << "\nUser Card: ";
		cout << "\n_____________________________________";
		cout << "\nAccount Number: " << _Username;
		cout << "\nFirst Name    : " << firstname;
		cout << "\nLast Name     : " << lastname;
		cout << "\nFull Name     : " << FullName();
		cout << "\nEmail         : " << email;
		cout << "\nPhone         : " << phone;
		cout << "\nPassword      : " << _Password;
		cout << "\n_____________________________________";


	}*/

	static clsUser Find(string userName)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsUser User = _ConvertLineToObject(line);
			
				if (User.UserName == userName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmtyUser();
	}
	static clsUser Find(string userName, string Password)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsUser User = _ConvertLineToObject(line);

				if (User.UserName == userName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}
		return _GetEmtyUser();
	}

	enum enSaveResult {svFaildEmpty = 0, svSuccessed = 1, svFaildUsername = 2};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::enEmptyMode:
		{
			if (isEmpty())
			{
				return enSaveResult::svFaildEmpty;
				break;
			}
		}
		case enMode::enUpdateMode:
		{
			_Update();
			return enSaveResult::svSuccessed;
			break;
		}
		case enMode::eAddNewMode:
		{
			if (clsUser::isUserExist(_Username))
			{
				return enSaveResult::svFaildUsername;
			}
			else
			{
				_AddNew();

				_Mode = enMode::enUpdateMode;
				return enSaveResult::svSuccessed;
			}
			break;
		}
		}
	}

	static vector<clsUser> GetAllUsers()
	{
		return _LoadDataFromFile();
	}
	static clsUser GetaddNewUser(string UserName)
	{
		return clsUser(enMode::eAddNewMode, UserName, "", "", "", "", "", 0);
	}

	bool Delete()
	{
		vector <clsUser> vUsers = _LoadDataFromFile();

		for (clsUser& Us : vUsers)
		{
			if (Us.UserName == "Admin")
				return false;

			if (Us.UserName == _Username)
			{
				Us._MarkForDelete = true;
				break;
			}
		}

		_SaveDataToFile(vUsers);
		*this = _GetEmtyUser();
		return true;
	}

	static bool isUserExist(string Username)
	{
		clsUser User = clsUser::Find(Username);

		return (!User.isEmpty());
	}

	bool isPermissionUser(enPermission Permission)
	{
		if (this->Permission == enPermission::pAll)
			return true;

		if ((this->Permission & Permission) == Permission)
			return true;

		else
			return false;
	}

	void RegisterLoginsToFile()
	{
		string DataLine = _PrepareLoginRecord();
		fstream MyFile;

		MyFile.open("LogFile.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}

	}

	static vector<stRegisterLogins> GetRegisterLoginsFromFile()
	{
		fstream MyFile;
		vector <stRegisterLogins> vRegisterLogins;

		MyFile.open("LogFile.txt", ios::in);

		if (MyFile.is_open())
		{
			stRegisterLogins RegisterRecord;
			string line;

			while (getline(MyFile, line))
			{
				RegisterRecord = _ConvertLineToRegisterRecord(line);
				vRegisterLogins.push_back(RegisterRecord);
			}

			MyFile.close();
		}
		return vRegisterLogins;
	}
};

