#include <iostream>
#include <string>
using namespace std;
class Bank{
	public:
		void deposit(int amt){
			cout<<"Depositing Rs."<<amt<<" in cash"<<endl;
		}
		
		void deposit(double amt){
			cout<<"Depositing Rs."<<amt<<" via digital payment"<<endl;
		}
		
		void deposit(string UPI_ID,float amt){
			cout<<"Depositing Rs."<<amt<<" Using UPI ("<<UPI_ID<<")"<<endl<<endl;
		}	
};

class Account {
	private:
	    int accountNumber;
	    float balance;
	public:
		Account(int acc_no,float init_bal){
			accountNumber=acc_no;
			balance=init_bal;
		}
		
		void Display(){
			cout<<"Account No:"<<accountNumber<<endl;
			cout<<"Balance:"<<balance<<endl<<endl;
		}
		
		void operator+(Account &acc){
			float TransferAmt;
			cout<<"Account "<<accountNumber<< " Balance : Rs.."<<balance<<endl;
			cout<<"Account "<<acc.accountNumber<< " Balance : Rs.."<<acc.balance<<endl<<endl;
			cout<<"Enter the amount to transfer from Account "<<accountNumber<<" to Account "<<acc.accountNumber<<":";
			cin>>TransferAmt;
			cout<<endl<<endl;
			if(balance>=TransferAmt){
				balance=balance-TransferAmt;
				acc.balance=acc.balance+TransferAmt;
				cout<<"Transferring Rs."<<TransferAmt<<" From Account "<<accountNumber<<" To Account "<<acc.accountNumber<<endl;
				cout<<"New Account "<<accountNumber<<" Balance :Rs."<<balance<<endl;
				cout<<"New Account "<<acc.accountNumber<<" Balance :Rs."<<acc.balance<<endl<<endl;
			}
		}
		
		void operator-(float WithdrawAmt) {
			if(balance>=WithdrawAmt)
			{
				balance=balance-WithdrawAmt;
				cout<<"Withdrawing Rs."<<WithdrawAmt<<" from Account "<<accountNumber<<endl;
				cout<<"Remaining Balance : "<<balance<<endl;
			}	
	}
};

int main(){
	Bank b1;
	b1.deposit(5000);
	b1.deposit(1500.75);
	b1.deposit("gpay@upi",2500);
	
	Account a1(1,10000);
	Account a2(2,5000);
	
	a1+a2;
	a1-2000;
	
}
