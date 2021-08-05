#include <iostream>
#include <algorithm>
using namespace std;

class Account {
private:
	string accountNo;
	string accountName;
	double balance;
public:
	Account() : accountNo(""), accountName(""), balance(0.0){}
	Account(string accountNo, string accountName, double balance) : accountNo(accountNo), accountName(accountName), balance(balance){}
	string getAccountNo() const {return accountNo;}
	string getAccountName() const {return accountName;}
	double getBalance() const {return balance;}
	void setBalance (double _balance) {balance = _balance;}
	void setAccountNo(string _accountNo) {accountNo = _accountNo;}
	void display() const {
		cout << "Account no:\t" << accountNo << "\n";
		cout << "Account name:\t" << accountName << "\n";
		cout << "Account balance:\t" << balance << "\n";
	}
};

class CurrentAccount: public Account {
private:
	const static double serviceCharge;
	static int nextAccount;
	const static string accountPrefix;
	int nextAccountNo() const {return nextAccount;}
public:
	CurrentAccount() : Account() {++nextAccount;}
	CurrentAccount(string accountNo, string accountName, double balance) :  Account(accountPrefix + accountNo, accountName, balance){		++nextAccount;	}
	double getServiceCharge() const {return serviceCharge;	}
	void setAccountNo(string _accountNo) {Account::setAccountNo(accountPrefix + _accountNo);}
	void display() const {
		cout << "Account type:\t Current Account\n";
		Account::display();
	}
	~CurrentAccount() {--nextAccount;	}
};

const string CurrentAccount::accountPrefix = "100";
int CurrentAccount::nextAccount = 1;

class SavingsAccount: public Account {
private:
	const static string accountPrefix;
	static int nextAccount;
	double interestRate;
	double monthlyDepositAmount;
	int nextAccountNo() const {return nextAccount;}
public:
	SavingsAccount() : Account(), interestRate(0), monthlyDepositAmount(0) {++nextAccount;}
	SavingsAccount(string accountNo, string accountName, double balance, double interestRate, double monthlyDepositAmount) :  Account(accountPrefix + accountNo, accountName, balance), interestRate(interestRate), monthlyDepositAmount(monthlyDepositAmount){
		++nextAccount;
	}
	double getInterestRate() const {		return interestRate;	}
	double getMonthlyDepositAmount() const {		return monthlyDepositAmount;	}
	void setInterestRate(double _interestRate) {		interestRate = _interestRate;	}
	void setMonthlyDepositAmount(double _monthlyDepositAmount) {		monthlyDepositAmount = _monthlyDepositAmount;	}
	string getAccountPrefix() const {		return accountPrefix;	}
	void setAccountNo(string _accountNo) {		Account::setAccountNo(accountPrefix + _accountNo);	}
	void display() const {
		cout << "Account type:\t Savings Account\n";
		Account::display();
	}
	~SavingsAccount() {--nextAccount;}
};

const string SavingsAccount::accountPrefix = "200";
int SavingsAccount::nextAccount = 1;

class MonthlyDepositScheme: public Account {
private:
	const static string accountPrefix;
	static int nextAccount;
	double interestRate;
	double monthlyDepositAmount;
	int nextAccountNo() const {return nextAccount;}
public:
	MonthlyDepositScheme() : Account(), interestRate(0), monthlyDepositAmount(0){++nextAccount;}
	MonthlyDepositScheme(string accountNo, string accountName, double balance, double interestRate, double monthlyDepositAmount) :  Account(accountPrefix + accountNo, accountName, balance), interestRate(interestRate), monthlyDepositAmount(monthlyDepositAmount)	{		++nextAccount;	}
	double getInterestRate() const {			}
	double getMonthlyDepositAmount() const {		return monthlyDepositAmount;	}
	void setInterestRate(double _interestRate) {		interestRate = _interestRate;	}
	void setMonthlyDepositAmount(double _monthlyDepositAmount) {		monthlyDepositAmount = _monthlyDepositAmount;	}
	void setAccountNo(string _accountNo) {		Account::setAccountNo(accountPrefix + _accountNo);	}
	void display() const {
		cout << "Account type:\t Monthly Deposit Scheme\n";
		Account::display();
	}
	~MonthlyDepositScheme() {	--nextAccount;	}
};

const string MonthlyDepositScheme::accountPrefix = "300";
int MonthlyDepositScheme::nextAccount = 1;

class LoanAccount: public Account {
private:
	const static string accountPrefix;
	static int nextAccount;
	double interestRate;
	double monthlyDepositAmount;
	int nextAccountNo() const {		return nextAccount;	}
public:
	LoanAccount() : Account(), interestRate(0), monthlyDepositAmount(0){++nextAccount;}
	LoanAccount(string accountNo, string accountName, double balance, double interestRate, double monthlyDepositAmount) :  Account(accountPrefix + accountNo, accountName, balance), interestRate(interestRate), monthlyDepositAmount(monthlyDepositAmount)	{		++nextAccount;	}
	double getInterestRate() const {		return interestRate;	}
	double getMonthlyDepositAmount() const {			}
	void setInterestRate(double _interestRate) {			}
	void setMonthlyDepositAmount(double _monthlyDepositAmount) {monthlyDepositAmount = _monthlyDepositAmount;}
	void setAccountNo(string _accountNo) {			}
	void display() const {
		cout << "Account type:\t Loan Account\n";
		Account::display();
	}
	~LoanAccount() {--nextAccount;}
};

const string LoanAccount::accountPrefix = "900";
int LoanAccount::nextAccount = 1;

class TwoYearMDS: public MonthlyDepositScheme {
private:
	double maximumInterest;
public:
	TwoYearMDS() : MonthlyDepositScheme(), maximumInterest(0)	{}
	TwoYearMDS(string accountNo, string accountName, double balance, double interestRate, double monthlyDepositAmount, double maximumInterest) : MonthlyDepositScheme(accountNo, accountName, balance, interestRate, monthlyDepositAmount), maximumInterest(maximumInterest) 	{}
	double getMaximumInterest() const {	return maximumInterest;	}
	void setMaximumInterest(double _maximumInterest) {maximumInterest = _maximumInterest;	}
	void display() const {
		cout << "Scheme:\t Two Year\n";
		MonthlyDepositScheme::display();
	}
};

class FiveYearMDS: public MonthlyDepositScheme {
private:
	double maximumInterest;
public:
	FiveYearMDS() : MonthlyDepositScheme(), maximumInterest(0)	{}
	FiveYearMDS(string accountNo, string accountName, double balance, double interestRate, double monthlyDepositAmount, double maximumInterest) : MonthlyDepositScheme(accountNo, accountName, balance, interestRate, monthlyDepositAmount), maximumInterest(maximumInterest) 	{}
	double getMaximumInterest() const {return maximumInterest;	}
	void setMaximumInterest(double _maximumInterest) {		maximumInterest = _maximumInterest;	}
	void display() const {
		cout << "Scheme:\t Five Year\n";
		MonthlyDepositScheme::display();
	}
};

class InitialDepositMDS: public MonthlyDepositScheme {
private:
	double maximumInterest;
	double initialDepositAmount;
public:
	InitialDepositMDS() : MonthlyDepositScheme(), maximumInterest(0), initialDepositAmount(0)	{}
	InitialDepositMDS(string accountNo, string accountName, double balance, double interestRate, double monthlyDepositAmount, double maximumInterest, double initialDepositAmount) : MonthlyDepositScheme(accountNo, accountName, balance, interestRate, monthlyDepositAmount), maximumInterest(maximumInterest), initialDepositAmount(initialDepositAmount) 	{}
	double getMaximumInterest() const {		return maximumInterest;	}
	void setMaximumInterest(double _maximumInterest) {	maximumInterest = _maximumInterest;	}
	double getinitialDepositAmount() const {	return initialDepositAmount;	}
	void setInitialDepositAmount(double _initialDepositAmount) {			}
	void display() const {
		cout << "Scheme:\t Initial Deposit\n";
		MonthlyDepositScheme::display();
	}
};

int main()
{
	CurrentAccount CA("32", "CA", 100);
	SavingsAccount SA("33", "SA", 200, 10, 5);
	MonthlyDepositScheme MDS("34", "MDS", 250, 10, 9);
	LoanAccount LA("35", "LA", 350, 2, 10);
	TwoYearMDS TYM("36", "TYM", 250, 1, 2, 3);
	FiveYearMDS FYM("37", "FYM", 257, 1, 2, 3);
	InitialDepositMDS ID("38", "ID", 400, 1, 2, 3, 4);
	CA.display();
	cout<<""<<endl;
	SA.display();
	cout<<""<<endl;
	MDS.display();
	cout<<""<<endl;
	LA.display();
	cout<<""<<endl;
	TYM.display();
	cout<<""<<endl;
	FYM.display();
	cout<<""<<endl;
	ID.display();
}
