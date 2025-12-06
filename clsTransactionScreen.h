#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clstotalBalancesScreen.h"
class clsTransactionScreen : protected clsScreen
{

private:
	enum enTransactionsMenu { Deposit = 1, Withdraw, TotalBalances, MainMenu };
	static short _ReadTransactionMenuOption()
	{
		return clsInputValidate::ReadPositiveNumberInRange("Choose an option [1-4]: ", 1, 4);
	}
	static void _ClearScreen()
	{
		std::system("cls");
	}
	static void _GoBackToTransactionScreen()
	{
		std::cout << "Press any key to go back to Transaction screen...";
		system("pause>0");
		ShowTransactionScreen();	
	}
	static void _DepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void _WithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawSreen();
	}
	static void _TotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _PerformTransactionMenuOption(enTransactionsMenu TransactionMenuOption)
	{

			switch (TransactionMenuOption)
			{
			case Deposit:
				_ClearScreen();
				_DepositScreen();
				_GoBackToTransactionScreen();
				break;
			case Withdraw:
				_ClearScreen();
				_WithdrawScreen();
				_GoBackToTransactionScreen();
				break;
			case TotalBalances:
				_ClearScreen();
				_TotalBalancesScreen();
				_GoBackToTransactionScreen();
				break;
			case MainMenu:
				break;
			default:
				break;
			}
	}
public:

	static void ShowTransactionScreen()
	{
		_ClearScreen();
		clsScreen::_DrawHeaderScreen("\t   Transaction menu");
		std::cout << "\t\t\t\t\t======================================" << std::endl;
		std::cout << "\t\t\t\t\t        Welcome to Bank System       " << std::endl;
		std::cout << "\t\t\t\t\t======================================" << std::endl;
		std::cout << "\t\t\t\t\t[1] Deposit" << std::endl;
		std::cout << "\t\t\t\t\t[2] Withdraw" << std::endl;
		std::cout << "\t\t\t\t\t[3] Total Balances" << std::endl;
		std::cout << "\t\t\t\t\t[4] Main Menu" << std::endl;
		std::cout << "\t\t\t\t\t======================================" << std::endl;
		std::cout << "\t\t\t\t\t"; _PerformTransactionMenuOption((enTransactionsMenu)_ReadTransactionMenuOption());
	}

};

