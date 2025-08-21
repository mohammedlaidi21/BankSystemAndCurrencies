#pragma once
#include <iostream>
#include "clsInterfaceCommunication.h"

using namespace std;

class clsPerson : public clsInterfaceCommunication
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson(string firstName, string lastName, string email, string phone)
	{
		this->_FirstName = firstName;
		this->_LastName = lastName;
		this->_Email = email;
		this->_Phone = phone;
	};
	clsPerson()
	{

	}

	//Getters & Setters
	void setFirstName(string Firstname)
	{
		_FirstName = Firstname;
	}
	string FirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = FirstName, put = setFirstName)) string firstname;

	void setLastName(string Lastname)
	{
		_LastName = Lastname;
	}
	string LastName()
	{
		return _LastName;
	}

	__declspec(property(get = LastName, put = setLastName)) string lastname;

	void setEmail(string Email)
	{
		_Email = Email;
	}
	string Email()
	{
		return _Email;
	}

	__declspec(property(get = Email, put = setEmail)) string email;


	void setPhone(string Phone)
	{
		_Phone = Phone;
	}
	string Phone()
	{
		return _Phone;
	}

	__declspec(property(get = Phone, put = setPhone)) string phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void Print()
	{
		cout << "Info Person:\n";
		cout << "___________________________\n";
		cout << "\nFirst Name: " << _FirstName;
		cout << "\nLast Name : " << _LastName;
		cout << "\nFull Name : " << FullName();
		cout << "\nEmail     : " << _Email;
		cout << "\nPhone     : " << _Phone;
		cout << "\n___________________________\n";
	}

	

	void SendFax(string Title, string Subject)
	{

	}

	void SendEmail(string Title, string Subject)
	{

	}

	void SendSMS(string Title, string Subject)
	{

	}
};

