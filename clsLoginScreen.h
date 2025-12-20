#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsMainScreen.h"
class clsLoginScreen : protected clsScreen
{
private:

	static void _Login()
	{
		bool LoginFaild = false;
		std::string Username, Password, Title = "\t   Login";
		clsScreen::_ClearScreen();
		clsScreen::_DrawHeaderScreen(Title);

		do
		{
			if (LoginFaild)
			{
				clsScreen::_ClearScreen();
				clsScreen::_DrawHeaderScreen(Title);
				std::cout << "Incorrect username or password!\n";
			}
			Username = clsInputValidate::ReadString("Enter username: ");
			Password = clsInputValidate::ReadString("Enter password: ");
			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.isEmpty();
		} while (LoginFaild);
		clsMainScreen::ShowMainScreen();
	}

public:
	static void ShowLoginScreen()
	{
		_Login();
	}

};

