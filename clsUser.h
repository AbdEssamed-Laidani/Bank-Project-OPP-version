#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsInputValidate.h"
#include "clsPerson.h"


class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode, AddNew };
	bool _MarkedForDeleted = false;
	int _Permistion;


public:

	clsUser(const std::string& FirstName, const std::string& LastName,
		const std::string& Email, const std::string& Phone,const int &Permistion)
		:clsPerson(FirstName, LastName, Email, Phone)
	{

	}


};

