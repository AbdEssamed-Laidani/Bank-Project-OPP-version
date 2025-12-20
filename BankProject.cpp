#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "clsLoginScreen.h"
using namespace std;


int main()
{
	while(true)
	clsLoginScreen::ShowLoginScreen();
	
	return 0;
}