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

	
	static bool _Login()
	{
		bool LoginFaild = false;
		short TrailsCounter;
		
		std::string Username, Password, Title = "\t   Login";

		
			TrailsCounter = 3;
			clsScreen::_ClearScreen();
			clsScreen::_DrawHeaderScreen(Title);

			do
			{
				Username = clsInputValidate::ReadString("Enter username: ");
				Password = clsInputValidate::ReadString("Enter password: ");
				CurrentUser = clsUser::Find(Username, Password);
				LoginFaild = CurrentUser.isEmpty();

				if (LoginFaild)
				{
					clsScreen::_ClearScreen();
					clsScreen::_DrawHeaderScreen(Title);

					TrailsCounter--;

					if (TrailsCounter == 0)
					{
						std::cout << "You are locked after " << 3 << " faild trails\n";
						return false;
					}
					std::cout << "Incorrect username or password!\n";
					std::cout << "You have " << TrailsCounter << " trails to login\n";


				}
			} while (LoginFaild && (TrailsCounter > 0));

			CurrentUser.RegisterLogin();
				clsMainScreen::ShowMainScreen();

				return true;
		
	}

public:
	
		static bool ShowLoginScreen()
		{

				return _Login();	
		}
	
};

