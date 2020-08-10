/* 
    banking system
    arfy slowy
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

class account
{
    int acno;
    char name[50];
    int deposit;
    char type;
    
    public:
        void create_account();
        void show_account() const;
        void modify();
        void dep(int);
        void draw(int);
        void report() const;
        int retacno() const;
        int retdeposit() const;
        char rettype() const;
};

void account::create_account()
{
    cout<<"Enter acount Number : "; cin>>acno;
    cout<<"Enter the name of the account : "; cin.ignore();
    cin.getline(name,50);
    cout<<"Enter type of account (C/S) : "; cin>>type;
    type=toupper(type);
    cout<<"Enter initial amount ( more than 500 for saving and more than 1000 for curren t) : ";
    cin>>deposit;

    cout<<"-----------------------"<<endl;
    cout<<"account detail"<<endl;
    cout<<"Account Number : "<<acno<<endl;
    cout<<"Account Name : "<<name<<endl;
    cout<<"Account type : "<<type<<endl;
    cout<<"start amount : $"<<deposit<<endl;
    cout<<"status       : Succes created "<<endl;
    cout<<"-----------------------"<<endl;
}
void account::show_account() const
{

    cout<<"-----------------------"<<endl;
    cout<<"account detail"<<endl;
    cout<<"Account Number : "<<acno<<endl;
    cout<<"Account Name : "<<name<<endl;
    cout<<"Account type : "<<type<<endl;
    cout<<"start amount : $"<<deposit<<endl;
    cout<<"status       : Succes created "<<endl;
    cout<<"-----------------------"<<endl;
}
void account::modify()
{
    cout<<"Account number : "<<acno;
    cout<<"Modify account name : "; cin.ignore(); cin.getline(name,50);
    cout<<"Modify type of account ( C / S) : "; cin>>type;
    type=toupper(type);
    cout<<"Modify Balance amount : "; cin>>deposit;
}
void account::dep(int x)
{
    deposit += x;
}
void account::draw(int x)
{
    deposit -= x;
}
void account::report() const
{
    cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}
int account::retacno() const
{
    return acno;
}
int account::retdeposit() const
{
    return deposit;
}
char account::rettype() const
{
    return type;
}

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int , int);
void intro();

int main()
{
    char ch;
    int num;
    intro();

    do
    {
        system("clear"); //system("cls"); //for windows user
        cout<<"\t 01. new accout "<<endl;
        cout<<"\t 02. deposit amount "<<endl;
        cout<<"\t 03. withdraw amount "<<endl;
        cout<<"\t 04. balance enquiry "<<endl;
        cout<<"\t 05. all account list "<<endl;
        cout<<"\t 06. close an account "<<endl;
        cout<<"\t 07. modify an account "<<endl;
        cout<<"\t 08. exit "<<endl;
        cout<<"Option (1-8) : "; cin>>ch;
        switch(ch)
        {
            case '1':
                write_account();
            break;
            case '2':
                cout<<"\t Enter the account number : "; cin>>num;
                deposit_withdraw(num, 1);
            break;
            case '3':
                cout<<"\t Enter the accout number : "; cin>>num;
                deposit_withdraw(num, 2);
            break;
            case '4':
                cout<<"\t Enter the account number : "; cin>>num;
                display_sp(num);
            break;
            case '5':
                display_all();
            break;
            case '6':
                cout<<"\t Enter the account number : "; cin>>num;
                delete_account(num);
            break;
            case '7':
                cout<<"Enter the account number : "; cin>>num;
                modify_account(num);
            break;
            case '8':
                cout<<" \t exit the program "<<endl;
            break;
            default: cout<<"\a";
        }
        cin.ignore();
        cin.get();
    }
    while(ch !='8');
    return 0;
}

void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary|ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if(!inFile)
    {
        cout<<"file could not be open press any key"<<endl;
        return;
    }
    cout<<"balance details"<<endl;
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
        if(ac.retacno() == n)
        {
            ac.show_account();
            flag = true;
        }
    }
    inFile.close();
    if(flag == false)
        cout<<"\t account number does not exist "<<endl;
}

void modify_account(int n)
{
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"file could not be open ";
        return;
    }
    while(!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
        {
            ac.show_account();
            cout<<"\t Enter the new details of account "<<endl;
            ac.modify();
            int pos = (-1)*static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
            cout<<"\t Record update";
            found=true;
        }
    }
    File.close();
    if(found == false)
        cout<<"\t record not found ";
}


void delete_account(int n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat", ios::binary);
    if(!inFile)
    {
        cout<<"\t file could not be open press any key";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0, ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
        if(ac.retacno() != n)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
    cout<<"\t record deleted";
}

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

void intro()
{
    cout<<"\t bank "<<endl;
    cout<<"\t majusee "<<endl;
    cin.get();
}


