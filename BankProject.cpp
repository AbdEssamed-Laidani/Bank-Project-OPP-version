#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
using namespace std;




//void PrintHeader(int ClientNumber)
//{
//	cout << "                                        Client List (" << ClientNumber << ")                                 " << endl;
//	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
//	cout << "|" << left << setw(15) << " Account Number" << right << " |" << left << setw(25) << " Client Name" << right << " |" << left << setw(15) << " Phone" << right << " |" << left << setw(30) << " Email" << right << " |" << left << setw(15) << " Pin code" << right << " |" << left << setw(15) << " Balance" << right << "|" << endl;;
//	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
//}
//void PrintClientDataLine(clsBankClient& ClientData)
//{
//	cout << "| " << left << setw(15) << ClientData.GetAccountNumber() << right << "| " << left << setw(25) << ClientData.GetFullName() << right << "| " << left << setw(15) << ClientData.GetPhone() << right << "| " << left << setw(30) << ClientData.GetEmail() << right << "| " << left << setw(14) << ClientData.GetPinCode() << right << " |" << left << setw(15) << ClientData.GetBalance() << right << "|" << endl;
//
//}
//void ShowClientList()
//{
//	vector <clsBankClient> vClient = clsBankClient::GetClientsList();
//	PrintHeader((int)vClient.size());
//	for (clsBankClient & C : vClient)
//	{
//		PrintClientDataLine(C);
//	}
//	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
//}
//void PrintClientRecordBalanceLine(clsBankClient& Client)
//{
//	cout << "|" << left << setw(35) << Client.GetAccountNumber() << right << " |" << left << setw(35) << Client.GetFullName() << right << " |" << left << setw(35) << Client.GetBalance() << right << "|" << endl;;
//
//}
//
//void ShowTotalBalances()
//{
//	vector <clsBankClient> vClient = clsBankClient::GetClientsList();
//	double total = clsBankClient::GetTotalBalances();
//	cout << "                                             Client List (" << vClient.size() << ")                                 " << endl << endl;
//	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
//	cout << "|" << left << setw(35) << " Account Number" << right << " |" << left << setw(35) << " Client Name" << right << " |" << left << setw(35) << " Balance" << right << "|" << endl;;
//	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
//	for (clsBankClient& C : vClient)
//	{
//		PrintClientRecordBalanceLine(C);
//	}
//	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
//	cout << "                                             Total Balance = " << total << endl;
//	cout << "                                      (" << clsUtil::numberToWords((int)total) << ")\n\n";
//
//}

int main()
{
	clsMainScreen::ShowMainScreen();

	
	return 0;
}