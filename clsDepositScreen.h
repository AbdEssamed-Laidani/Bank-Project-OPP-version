#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include <cctype>
class clsDepositScreen : protected clsScreen
{
	private:
		static void _ClearScreen()
		{
			std::system("cls");
		}
		static void _PrintClient(clsBankClient& Client)
		{
			std::cout << "Client Card:\n";
			std::cout << "-------------------------------\n";
			std::cout << "First Name: " << Client.GetFirstName() << std::endl;
			std::cout << "Last Name: " << Client.GetLastName() << std::endl;
			std::cout << "Full Name: " << Client.GetFullName() << std::endl;
			std::cout << "Account Number: " << Client.GetAccountNumber() << std::endl;
			std::cout << "Password: " << Client.GetPinCode() << std::endl;
			std::cout << "E-mail: " << Client.GetEmail() << std::endl;
			std::cout << "Phone: " << Client.GetPhone() << std::endl;
			std::cout << "Balance: " << Client.GetBalance() << std::endl;
			std::cout << "-------------------------------\n";
		}
		static void _DepositAmount()
		{
			clsScreen::_DrawHeaderScreen("\t      Deposit Amount Screen");
			std::string AccountNumber = clsInputValidate::ReadString("Enter account number: ");
			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				AccountNumber = clsInputValidate::ReadString("Account number not exist, r-enter account number: ");
			}
			clsBankClient Client = clsBankClient::Find(AccountNumber);
			_PrintClient(Client);
			double Amount = clsInputValidate::ReadPositiveDoubleNumber("Enter amount to deposit: ");
			if (toupper(clsInputValidate::ReadLetter("Are you sure you want to deposit [" + std::to_string(Amount) + "] to account number [" + AccountNumber + "]? [Y/N]: ")) == 'Y')
			{
				Client.DepositAmount(Amount);
				std::cout << "\n\nAmount deposited successfully :-)\n\n";
				std::cout << "New balance is: " << Client.GetBalance() << std::endl;
			}
			else
				return;
		}
public:
	static void ShowDepositScreen()
	{
			_DepositAmount();
	}
};

