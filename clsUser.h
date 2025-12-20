#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsString.h"


class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode, AddNewMode };
	enMode _Mode;
	std::string _UserName;
	std::string _Password;
	bool _MarkedForDeleted = false;
	int _Permisstions;

	static clsUser _ConvertLineToUserObject(const std::string &Line,const std::string &Delimiter)
	{
		std::vector <std::string> vUser;
		vUser = clsString::SplitText(Line, Delimiter);
		return clsUser(enMode::UpdateMode, vUser.at(0), vUser.at(1), vUser.at(2), vUser.at(3),
			vUser.at(4), vUser.at(5), stoi(vUser.at(6)));
	}
    static std::string _ConvertUserObjectToLine(clsUser& User,const std::string &Delimiter)
	{
		std::string Record;
		Record += User.GetFirstName() + Delimiter;
		Record += User.GetLastName() + Delimiter;
		Record += User.GetEmail() + Delimiter;
		Record += User.GetPhone() + Delimiter;
		Record += User.GetUsername() + Delimiter;
		Record += User.GetPassword() + Delimiter;
		Record += std::to_string(User.GetPermistions());
		return Record;
	}
	static std::vector <clsUser> _LoadUserDataFromFile()
	{
		std::fstream MyFile;
		std::vector <clsUser> vUsers;
		MyFile.open("Users.txt", std::ios::in);
		if (MyFile.is_open())
		{
			std::string Line;
			while (std::getline(MyFile, Line))
			{
				vUsers.push_back(_ConvertLineToUserObject(Line, " #//# "));
			}
			MyFile.close();
		}
		else
		{
			std::cout << "couldn't open the file!\n";
		}
		return vUsers;
	}
	static clsUser _GetEmptyObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	void _SaveUsersDataToFile(std::vector <clsUser> &vUsers)
	{
		std::fstream MyFile;
		MyFile.open("Users.txt", std::ios::out);
		if (MyFile.is_open())
		{
			for (clsUser& U : vUsers)
			{
				if(!U.MarkedForDeleted())
				MyFile << _ConvertUserObjectToLine(U, " #//# ") << std::endl;
			}
			MyFile.close();
		}
		else
		{
			std::cout << "couldn't open the file!\n";
		}
	}
	void _Update()
	{
		std::vector <clsUser> vUsers = _LoadUserDataFromFile();
		for (clsUser& U : vUsers)
		{
			if (GetUsername() == U.GetUsername())
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}
	void _AddUserToFile(const std::string &UserDataLine)
	{
		std::fstream MyFile;
		MyFile.open("Users.txt", std::ios::app);
		if (MyFile.is_open())
		{
			MyFile << UserDataLine << std::endl;
		}
		else
		{
			std::cout << "couldn't open the file!\n";
		}

	}
	void _AddNewUser()
	{
		_AddUserToFile(_ConvertUserObjectToLine(*this, " #//# "));
	}
public:

	enum enPermistions {
		All = -1, pList = 1, pAdd = 2,
		pDelete = 4, pUpdate = 8, pFind = 16,
		pTransactions = 32, pManage = 64
	};


	clsUser(enMode Mode, const std::string& FirstName, const std::string& LastName,
		const std::string& Email, const std::string& Phone,const std::string &UserName,
		const std::string &Password, int Permisstions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permisstions = Permisstions;
	}
	bool MarkedForDeleted()
	{
		return _MarkedForDeleted;
	}
	void SetMakedForDeleted(bool Delete)
	{
		_MarkedForDeleted = Delete;
	}
	std::string GetUsername()
	{
		return _UserName;
	}
	void SetUserName(const std::string& UserName)
	{
		_UserName = UserName;
	}
	std::string GetPassword()
	{
		return _Password;
	}
	void SetPassword(const std::string& Password)
	{
		_Password = Password;
	}
	int GetPermistions()
	{
		return _Permisstions;
	}
	void SetPermisstion(int Permisstions)
	{
		_Permisstions = Permisstions;
	}
	bool isEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
	bool Delete()
	{
		std::vector <clsUser> vUsers = _LoadUserDataFromFile();
		for (clsUser& U : vUsers)
		{
			if (U.GetUsername() == _UserName)
			{
				U.SetMakedForDeleted(true);
				break;
			}
		}
		*this = _GetEmptyObject();
		_SaveUsersDataToFile(vUsers);
		return true;
	}
	static clsUser Find(std::string UserName)
	{
		std::fstream MyFile("Users.txt", std::ios::in);

		if (MyFile.is_open())
		{
			std::string Line;
			while (std::getline(MyFile, Line))
			{
				clsUser user = _ConvertLineToUserObject(Line, " #//# ");
				if (user.GetUsername() == UserName)
				{
					MyFile.close();
					return user;
				}
			}
		}
		else
		{
			std::cout << "couldn't open the file!\n";
		}
		return _GetEmptyObject();
	}
	static clsUser Find(const std::string& UserName,const std::string& Password)
	{
		std::fstream MyFile("Users.txt", std::ios::in);

		if (MyFile.is_open())
		{
			std::string Line;
			while (std::getline(MyFile, Line))
			{
				clsUser user = _ConvertLineToUserObject(Line, " #//# ");
				if (user.GetUsername() == UserName && user.GetPassword() == Password)
				{
					MyFile.close();
					return user;
				}
			}
		}
		else
		{
			std::cout << "couldn't open the file!\n";
		}
		return _GetEmptyObject();
	}
	static bool isUserExist(const std::string& UserName)
	{
		clsUser User = Find(UserName);
		return !User.isEmpty();
	}
	static std::vector <clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}
	static clsUser GetAddNewUserObject(const std::string &UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}
	enum enSaveResult { svSucceded = 1, svFailedEmpty, svFailedExist };
    enSaveResult save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (isEmpty())
				return enSaveResult::svFailedEmpty;
			break;
		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSucceded;
			break;
		case enMode::AddNewMode:
			if (isUserExist(GetUsername()))
				return enSaveResult::svFailedExist;
			else
			{
				_AddNewUser();
				_Mode = UpdateMode;
				return enSaveResult::svSucceded;
			}
			break;
		default:
			break;

		}
		return enSaveResult::svSucceded;
	}

	bool CheckAccessPermistion(enPermistions Permistion)
	{
		if (((this->_Permisstions & Permistion) == Permistion) || (Permistion == enPermistions::All))
			return true;
		else
			return false;
	}
};