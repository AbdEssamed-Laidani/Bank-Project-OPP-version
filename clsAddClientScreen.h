#pragma once
#include <iostream>
#include "clsBankClient.h"
#include <vector>
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsAddClientScreen :protected clsScreen
{
private:
	static void ReadClientInfo(clsBankClient& Client)
	{

		Client.SetFirstName(clsInputValidate::ReadString("\tEnter your first name: "));
		Client.SetLastName(clsInputValidate::ReadString("\tEnter your last name: "));
		Client.SetEmail(clsInputValidate::ReadString("\tEnter your email: "));
		Client.SetPhone(clsInputValidate::ReadString("\tEnter your phone number: "));
		Client.SetPinCode(clsInputValidate::ReadString("\tEnter your pincode: "));
		Client.SetBalance(clsInputValidate::ReadPositiveDoubleNumber("\tEnter your balance: "));

	}

public:

	static void AddNew()
	{
		clsScreen::_DrawHeaderScreen("\t     Add New Client");
		std::string AccountNumber = clsInputValidate::ReadString("\tEnter account number: ");
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			AccountNumber = clsInputValidate::ReadString("Acccount already exist choose another one: ");
		}
		clsBankClient NewClient = clsBankClient::GetNewClientObject(AccountNumber);
		ReadClientInfo(NewClient);
		clsBankClient::enSaveResult SaveResult = NewClient.save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResult::svFailedEmpty:
			std::cout << "\n\nsave failed empty object :-(\n\n";
			break;
		case clsBankClient::enSaveResult::svFaiedExist:
			std::cout << "\n\nsave failed account already exist :-(\n\n";
			break;
		case clsBankClient::enSaveResult::svSucceded:
			std::cout << "\n\nsave succeded :-)\n\n";
			break;
		}
		NewClient.print();
	}

};

