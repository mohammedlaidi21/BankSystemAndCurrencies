#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h"

using namespace std;

class clsCurrencyExchange
{
private:

	enum _enMode { EmptyMode = 0, UpdateMode = 1 };

	_enMode _Mode;
	string _CodeCurrency;
	string _NameCurrency;
	string _CountryCurrency;
	double _Rate;

	static clsCurrencyExchange _ConvertLineToObject(string Line, string Seperator = "#//#")
	{
		vector<string>vCurencies = 
			clsString::Split(Line, Seperator);

		return clsCurrencyExchange(_enMode::UpdateMode, vCurencies[0], vCurencies[1],
			vCurencies[2], stod(vCurencies[3]));
	}
	static string _ConvertObjectToLine(clsCurrencyExchange Currency, string Separator = "#//#")
	{
		string CurrencyRecord = "";

		CurrencyRecord += Currency.Country() + Separator;
		CurrencyRecord += Currency.Code() + Separator;
		CurrencyRecord += Currency.NameCurrency() + Separator;
		CurrencyRecord += to_string(Currency.Rate());

		return CurrencyRecord;
	}

	static clsCurrencyExchange _GetEmptyCurrency()
	{
		return clsCurrencyExchange(_enMode::EmptyMode, "", "", "", 0);
	}

	static vector<clsCurrencyExchange> _LoadDataCurrencyFromFile()
	{
		vector<clsCurrencyExchange> vCurrenyExchange;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsCurrencyExchange Currency = _ConvertLineToObject(line);
				vCurrenyExchange.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrenyExchange;
	}
	static void _SaveDataCurrencyToFile(vector<clsCurrencyExchange> vCurrenciesExchange)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string line;

			for (clsCurrencyExchange& Curr : vCurrenciesExchange)
			{
				line = _ConvertObjectToLine(Curr);
				MyFile << line << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsCurrencyExchange> _vCurrenciesExchange;
		_vCurrenciesExchange = _LoadDataCurrencyFromFile();

		for (clsCurrencyExchange& Curr : _vCurrenciesExchange)
		{
			if (Curr.Code() == Code())
			{
				Curr = *this;
				break;
			}
		}
		_SaveDataCurrencyToFile(_vCurrenciesExchange);
	}


public:
	clsCurrencyExchange(_enMode mode, string country, string code, string nameCurrency, double rate)
	{
		this->_Mode = mode;
		this->_CountryCurrency = country;
		this->_CodeCurrency = code;
		this->_NameCurrency = nameCurrency;
		this->_Rate = rate;
	}

	bool isEmpty()
	{
		return (_Mode == _enMode::EmptyMode);
	}

	string Code()
	{
		return _CodeCurrency;
	}

	string NameCurrency()
	{
		return _NameCurrency;
	}

	string Country()
	{
		return _CountryCurrency;
	}

	double Rate()
	{
		return _Rate;
	}
	void UpdateRate(double newRate)
	{
		_Rate = newRate;
		_Update();
	}
	
	static clsCurrencyExchange FindByCode(string CodeCurrency)
	{
		CodeCurrency = clsString::UpperAllString(CodeCurrency);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsCurrencyExchange Currency =
					_ConvertLineToObject(line);

				if (Currency.Code() == CodeCurrency)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrency();
	}
	static clsCurrencyExchange FindByCountry(string CountryCurrecy)
	{
		CountryCurrecy = clsString::UpperAllString(CountryCurrecy);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsCurrencyExchange Currency =
					_ConvertLineToObject(line);

				if (clsString::UpperAllString(Currency.Country()) == CountryCurrecy)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrency();
	}

	static vector<clsCurrencyExchange> GetDataCurrenciesExchange()
	{
		return _LoadDataCurrencyFromFile();
	}

	static bool isCurrencyExist(string CodeCurrency)
	{
		clsCurrencyExchange Currency =
			clsCurrencyExchange::FindByCode(CodeCurrency);
		return (!Currency.isEmpty());
	}

	float ConvertToDollar(float Amount)
	{
		return (float)(Amount / Rate());
	}
	
	float ConvertToOtherCurrency(float Amount, clsCurrencyExchange CurrencyTo)
	{
		float ExchangeToUSD = ConvertToDollar(Amount);

		if (CurrencyTo.Code() == "USD")
		{
			return ExchangeToUSD;
		}

		return (float)(ExchangeToUSD * CurrencyTo.Rate());
	}
};

