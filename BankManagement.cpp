#include <iostream>
#include <string>
using namespace std;

void createAccount();
void deposit();
void withdrawal();
void inquiry();
void displayOptions();
void validateInput();
void Accounts_summary();

bool verify_acct_number(int num);

int Acct_num[100];
string Acct_name[100];
string address[100];
double balance[100];
double amount;
int acct_counter = 0;

int user_num;

int main()
{
	displayOptions();
	return 0;
} // End of the Main Method

bool verify_acct_number(int num)
{
	bool found = false;
	
	for(int i=0; i<acct_counter; i++)
	{
		if(num == Acct_num[i])
		{
			found = true;
			break;
		}
		else
		{
			found = false;
		}
	}
	return found;
}

void validateInput(char ch)
{
	if(ch=='c' || ch=='C')
	{
		createAccount();
	}
		
	else if(ch=='d' || ch=='D')
	{
		deposit();
	}
	
	else if(ch=='i' || ch=='I')
	{
		inquiry();
	}
	
	else if(ch=='v' || ch=='V')
	{
		Accounts_summary();
	}
	
	else
	{
		cout<<"Invalid Entry!!!"<<endl;
	}
	displayOptions();
} // End of Validate Inputs

void displayOptions()
{
	char choice;
	cout<<"PLEASE SELECT ONE OF THE FOLLOWING OPTIONS"<<endl;
	cout<<"C: TO CREATE\nD: TO DEPOSIT\nW: TO WITHDRAW\nI: TO MAKE INQUIRY\nV: TO VIEW ACCOUNTS SUMMARY"<<endl;
	cin>>choice;
	
	validateInput(choice); 
} // End of Display Options Method

void deposit()
{
	cout<<"ACCOUNT NUMBER VERIFIED"<<endl;
	cout<<"ENTER ACCOUNT NUMBER"<<endl;
	cin>>user_num;
	
	if(verify_acct_number(user_num)==true)
	{
		cout<<"ENTER DEPOSIT AMOUNT"<<endl;
		cin>>amount;
		balance[user_num - 30000] = balance[user_num - 30000] + amount;
		
		cout<<"YOU HAVE DEPOSITED "<<amount<< " INTO " <<Acct_num[user_num - 30000]<<" "<<balance[user_num - 30000]<<endl;
		displayOptions();
	}
	else
	{
		cout<<"INVALID ACCOUNT NUMBER, PLEASE TRY AGAIN"<<endl;
		displayOptions();
	}
} // End of Deposit Method


void withdrawal()
{
	cout<<"ENTER ACCOUNT NUMBER"<<endl;
	cin>>user_num;
	
	if(verify_acct_number(user_num) == true)
	{
		cout<<"ACCOUNT NUMBER VERIFIED"<<endl;
		cout<<"ENTER AMOUNT TO WITHDRAW"<<endl;
		cin>>amount;
		
		if(balance[user_num-30000] >=amount)
		{
			balance[user_num-30000] = balance[user_num - 30000] - amount;
			cout<<amount<<" HAS BEEN DEPOSITED, YOUR NEW BALANCE IS "<<balance[user_num-30000]<<endl;
			displayOptions();
		}
		
		else
		{
			cout<<"INSUFFICIENT FUNDS"<<endl;
			displayOptions();
		}
	}
	
	else
	{
		cout<<"INVALID ACCOUNT NUMBER, PLEASE TRY AGAIN"<<endl;
		displayOptions();
	}
} // End of Withdraw Method


void inquiry()
{
	cout<<"ENTER THE ACCOUNT NUMBER"<<endl;
	cin>>user_num;
	
	if(verify_acct_number(user_num) == true)
	{
		cout<<Acct_num[user_num - 30000]<<" "<<Acct_name[user_num - 30000]<< " "<<address[user_num - 30000] <<" "<<balance[user_num-30000]<<endl;
		displayOptions();
	}
	
	else
	{
		cout<<"INVALID ACCOUNT NUMBER"<<endl;
		displayOptions();
	}
}// End of Inquiry method

void createAccount()
{
	cout<<"ENTER ACCOUNT NAME"<<endl;
	getline(cin, Acct_name[acct_counter]);
	getline(cin, Acct_name[acct_counter]);
	
	cout<<"ENTER ACCOUNT HOLDER'S ADDRESS'"<<endl;
	getline(cin, address[acct_counter]);
	
	cout<<"ENTER OPENING AMOUNT"<<endl;
	cin>>balance[acct_counter];
	
	Acct_num[acct_counter] = 30000 + acct_counter;
	
	cout<<"ACCOUNT CREATED, ACCOUNT NUMBER IS: "<<Acct_num[acct_counter]<<endl;
	
	acct_counter = acct_counter+1;
	displayOptions();
	
} // End of Create Account Method

void Accounts_summary()
{
	for(int i=0; i<acct_counter; i++)
	{
	cout<<Acct_num[i]<<"   "<<Acct_name[i]<<"   "<<address[i]<<"   "<<balance[i]<<endl<<endl;
	}	
}// End of Account Summary
