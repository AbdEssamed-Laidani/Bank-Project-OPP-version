#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;

void ReadClientInfo(clsBankClient &Client)
{

		Client.SetFirstName(clsInputValidate::ReadString("Enter your first name: "));
		Client.SetLastName(clsInputValidate::ReadString("Enter your last name: "));
		Client.SetEmail(clsInputValidate::ReadString("Enter your email: "));
		Client.SetPhone(clsInputValidate::ReadString("Enter your phone number: "));
		Client.SetPinCode(clsInputValidate::ReadString("Enter your pincode: "));
		Client.SetBalance(clsInputValidate::ReadPositiveDoubleNumber("Enter your balance: "));

}
void UpdateClient()
{
	string AccountNumber = clsInputValidate::ReadString("Enter you account number: ");
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		AccountNumber = clsInputValidate::ReadString("Account with number[" + AccountNumber + "] doesn't exist, chose another one: ");
	}
	system("cls");
	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.print();
	ReadClientInfo(Client1);
	clsBankClient::enSaveResult SaveResult = Client1.save();
	switch (SaveResult)
	{
	case clsBankClient::enSaveResult::svFailedEmpty:
		cout << "\n\nsave falied empty object :-(\n\n";
		break;
	case clsBankClient::enSaveResult::svSucceded:
		cout << "\n\nsave succeded :-)\n\n";
	}
	Client1.print();

}
void AddNew()
{
	string AccountNumber = clsInputValidate::ReadString("Enter account number: ");
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
		cout << "\n\nsave failed empty object :-(\n\n";
		break;
	case clsBankClient::enSaveResult::svFaiedExist:
		cout << "\n\nsave failed account already exist :-(\n\n";
		break;
	case clsBankClient::enSaveResult::svSucceded:
		cout << "\n\nsave succeded :-)\n\n";
		break;
	}
	NewClient.print();

}
void DeleteClient()
{
	string AccountNumber = clsInputValidate::ReadString("Enter account number: ");
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		AccountNumber = clsInputValidate::ReadString("Account number not exist, r-enter account number: ");
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	if (toupper(clsInputValidate::ReadLetter("Are you sure you want to delete client with number [" + AccountNumber + "]? [Y/N]: ")) == 'Y')
	{
		if (Client.Delete(AccountNumber))
		{
			cout << "Delete succeded !";
			Client.print();
		}
	}
	else
		return;
}
void PrintHeader(int ClientNumber)
{
	cout << "                                        Client List (" << ClientNumber << ")                                 " << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << left << setw(15) << " Account Number" << right << " |" << left << setw(25) << " Client Name" << right << " |" << left << setw(15) << " Phone" << right << " |" << left << setw(30) << " Email" << right << " |" << left << setw(15) << " Pin code" << right << " |" << left << setw(15) << " Balance" << right << "|" << endl;;
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void PrintClientDataLine(clsBankClient& ClientData)
{
	cout << "| " << left << setw(15) << ClientData.GetAccountNumber() << right << "| " << left << setw(25) << ClientData.GetFullName() << right << "| " << left << setw(15) << ClientData.GetPhone() << right << "| " << left << setw(30) << ClientData.GetEmail() << right << "| " << left << setw(14) << ClientData.GetPinCode() << right << " |" << left << setw(15) << ClientData.GetBalance() << right << "|" << endl;

}
void ShowClientList()
{
	vector <clsBankClient> vClient = clsBankClient::GetClientsList();
	PrintHeader((int)vClient.size());
	for (clsBankClient & C : vClient)
	{
		PrintClientDataLine(C);
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void PrintClientRecordBalanceLine(clsBankClient& Client)
{
	cout << "|" << left << setw(35) << Client.GetAccountNumber() << right << " |" << left << setw(35) << Client.GetFullName() << right << " |" << left << setw(35) << Client.GetBalance() << right << "|" << endl;;

}

void ShowTotalBalances()
{
	vector <clsBankClient> vClient = clsBankClient::GetClientsList();
	double total = clsBankClient::GetTotalBalances();
	cout << "                                             Client List (" << vClient.size() << ")                                 " << endl << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << left << setw(35) << " Account Number" << right << " |" << left << setw(35) << " Client Name" << right << " |" << left << setw(35) << " Balance" << right << "|" << endl;;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	for (clsBankClient& C : vClient)
	{
		PrintClientRecordBalanceLine(C);
	}
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                             Total Balance = " << total << endl;
	cout << "                                      (" << clsUtil::numberToWords((int)total) << ")\n\n";

}

int main()
{

	ShowTotalBalances();
	
	return 0;
}