#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
class clsBankClient:public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	std::string _AccountNumber;
	std::string _PinCode;
	double _Balance;
	bool _MarkForDelete = false;
	static clsBankClient _ConvertLineToClientObject(const std::string &Line,std::string Delimiter = " #//# ")
	{
		std::vector <std::string> vClient = clsString::SplitText(Line, Delimiter);
		return clsBankClient(enMode::UpdateMode, vClient.at(0), vClient.at(1), vClient.at(2),
			vClient.at(3), vClient.at(4), vClient.at(5), stod(vClient.at(6)));
	}
	static clsBankClient _GetEmptyClientObejct()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static std::vector <clsBankClient> _LoadDataFromFile()
	{
		std::string DataLine = "";
		std::vector <clsBankClient> vClient;
		std::fstream MyFile("Client.txt", std::ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, DataLine))
			{
				vClient.push_back(_ConvertLineToClientObject(DataLine));
			}
			MyFile.close();
		}
		return vClient;
	}
	std::string _ConvertObjectToLine(clsBankClient& Client,std::string Delimiter=" #//# ")
	{
		std::string Line = "";
		Line += Client.GetFirstName() + Delimiter;
		Line += Client.GetLastName() + Delimiter;
		Line += Client.GetPhone() + Delimiter;
		Line += Client.GetEmail() + Delimiter;
		Line += Client.GetAccountNumber() + Delimiter;
		Line += Client.GetPinCode() + Delimiter;
		Line += std::to_string(Client.GetBalance());
		return Line;
	}
	void _SaveVectorToFile(std::vector <clsBankClient> &vClient)
	{
		std::fstream MyFile("Client.txt", std::ios::out);
		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClient)
			{
				if(!C._MarkForDelete)
				MyFile << _ConvertObjectToLine(C) << std::endl;
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		std::vector <clsBankClient> vClient = _LoadDataFromFile();
		for (clsBankClient& C : vClient)
		{
			if (GetAccountNumber() == C.GetAccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveVectorToFile(vClient);
	}
	void _AddLineToFile(const std::string &Line)
	{
		std::fstream MyFile("Client.txt", std::ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << std::endl;
		}
	}
	void _AddNew()
	{
		_AddLineToFile(_ConvertObjectToLine(*this));
	}
public:
	clsBankClient(enMode Mode, const std::string& FirstName, const std::string& LastName, const std::string& Phone, const std::string& Email, const std::string& AccountNumber, const std::string& PinCode, const double& Balance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_AccountNumber = AccountNumber;
		_Balance = Balance;
		_PinCode = PinCode;
		_Mode = Mode;
	}
	std::string GetAccountNumber()
	{
		return _AccountNumber;
	}
	void SetBalance(const double& Balance)
	{
		_Balance = Balance;
	}
	double GetBalance()
	{
		return _Balance;
	}
	void SetPinCode(const std::string& PinCode)
	{
		_PinCode = PinCode;
	}
	std::string GetPinCode()
	{
		return _PinCode;
	}
	std::string GetFullName()
	{
		return GetFirstName() + " " + GetLastName();
	}
	bool isEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(const std::string &AccountNumber)
	{
		std::vector <clsBankClient> vClient;
		std::string Line;
		std::fstream MyFile("Client.txt", std::ios::in);
		while (getline(MyFile, Line))
		{
			clsBankClient Client = _ConvertLineToClientObject(Line);
			
			if (Client.GetAccountNumber() == AccountNumber)
			{
				return Client;
			}
			vClient.push_back(Client);
		}
		MyFile.close();

		return _GetEmptyClientObejct();
	}
	static clsBankClient Find(const std::string& AccountNumber, const std::string& PinCode)
	{
		std::vector <clsBankClient> vClient;
		std::string Line;
		std::fstream MyFile("Client.txt", std::ios::in);
		while (getline(MyFile, Line))
		{
			clsBankClient Client = _ConvertLineToClientObject(Line);
			if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
			{
				return Client;
			}
			vClient.push_back(Client);
		}
		MyFile.close();
		return _GetEmptyClientObejct();
	}
	static bool IsClientExist(const std::string &AccountNumber)
	{
		clsBankClient client = client.Find(AccountNumber);
		return !client.isEmpty();
	}
	

	enum enSaveResult { svFailedEmpty = 0, svSucceded = 1, svFaiedExist = 3 };

	static clsBankClient GetNewClientObject(std::string AccountNumber)
	{

		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	
	enSaveResult save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if(isEmpty())
			return enSaveResult::svFailedEmpty;
			break;
		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSucceded;
			break;
		case enMode::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber))
				return enSaveResult::svFaiedExist;
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceded;
			}
			break;
		default:
			break;
		}
		return enSaveResult::svFailedEmpty;
	}
	bool Delete(const std::string &AccountNumbeer)
	{
		std::vector <clsBankClient> vClient = _LoadDataFromFile();
		for (clsBankClient& C : vClient)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}
		*this = _GetEmptyClientObejct();
		_SaveVectorToFile(vClient);
		return true;
	}
	static std::vector <clsBankClient> GetClientsList()
	{
		return _LoadDataFromFile();
	}

	static double GetTotalBalances()
	{
		std::vector <clsBankClient> vClient = _LoadDataFromFile();

		double total = 0;
		for (clsBankClient& i : vClient)
		{
			total = total + i.GetBalance();
		}
		return total;
	}
    void DepositAmount(double Amount)
	{
		_Balance += Amount;
		save();
	}
	void WithDrawAmount(double Amount)
	{
		DepositAmount(-1 * Amount);
	}
	
};

