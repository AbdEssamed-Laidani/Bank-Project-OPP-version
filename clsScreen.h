#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "Global.h"
class clsScreen
{

protected:
	static void _DrawHeaderScreen(const std::string& Title, const std::string& SubTitle = "")
	{
		std::cout << "\t\t\t\t\t--------------------------------------" << std::endl;
		std::cout << "\t\t\t\t\t" << Title << std::endl << std::endl;
		if (!SubTitle.empty())
		std::cout << "\t\t\t\t\t" << SubTitle << std::endl;
		std::cout << "\t\t\t\t\t--------------------------------------" << std::endl << std::endl;
	}
	static void _ClearScreen()
	{
		system("cls");
	}

	static bool CheckPermitionRight(clsUser::enPermistions Permistion)
	{
		if (!CurrentUser.CheckAccessPermistion(Permistion))
		{
			_DrawHeaderScreen("Access Denide Contact Your Admin");
			return false;
		}
		else
			return true;
	}
};