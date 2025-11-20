#pragma once
#include <iostream>
#include <iomanip>
class clsScreen
{

protected:
	static void _DrawHeaderScreen(const std::string& Title, const std::string& SubTitle = "")
	{
		std::cout << "\t\t\t\t\t--------------------------------------" << std::endl;
		std::cout << "\t\t\t\t\t" << std::setw(25) << std::right << Title << std::endl << std::endl;
		if (!SubTitle.empty())
		std::cout << "\t\t\t\t\t" << std::setw(25) << std::right << SubTitle << std::endl;
		std::cout << "\t\t\t\t\t--------------------------------------" << std::endl << std::endl;
	}


};
