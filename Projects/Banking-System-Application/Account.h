#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:

    Account(string accNum, string holder, double initialBalance = 0.0);

    string getAccountNumber() const;
    string getAccountHolder() const;
    double getBalance() const;

    bool deposit(double amount);
    bool withdraw(double amount);
    void displayAccountInfo() const;
};

#endif