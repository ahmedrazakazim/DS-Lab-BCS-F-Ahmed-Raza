#include <iostream>

using namespace std;

class BankAccount
{
private:
    static int count;
    int ID;
    int balance;

public:
    // default
    BankAccount()
    {
        balance = 0;
        count++;
        ID = count;
    }
    // parameterized
    BankAccount(int amount)
    {
        balance = amount;
        count++;
        ID = count;
    }
    // copy
    BankAccount(const BankAccount &obj)
    {
        this->balance = obj.balance;
        count++;
        ID = count;
    }
    void displayBalance()
    {
        cout << "The balance of account " << this->ID << " is: $" << balance << endl;
    }
    void deductBalance(int deduction)
    {
        this->balance = balance - deduction;
    }
};
int BankAccount::count = 0;

int main()
{
    BankAccount account1;
    account1.displayBalance();

    BankAccount account2(1000);
    account2.displayBalance();

    BankAccount account3(account2);
    account3.displayBalance();
    account3.deductBalance(200);
    account3.displayBalance();
    account2.displayBalance();
    return 0;
}
