#include <bits/stdc++.h>
using namespace std;
class Bank {
private:
    vector<long long> balance;  
    bool isValidAccount(int account) {
        return account >= 1 && account <= (int)balance.size();
    }

public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    bool withdraw(int account, long long money) {
        if (!isValidAccount(account)) return false;
        if (balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValidAccount(account)) return false;
        balance[account - 1] += money;
        return true;
    }

    bool transfer(int account1, int account2, long long money) {
        if (!isValidAccount(account1) || !isValidAccount(account2)) return false;
        if (balance[account1 - 1] < money) return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
};
int main() {
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank bank(balance);
    cout << bank.withdraw(3, 10) << endl;  
    cout << bank.transfer(5, 1, 20) << endl;  
    cout << bank.deposit(5, 20) << endl;
    cout << bank.transfer(3, 4, 15) << endl;
    cout << bank.withdraw(10, 50) << endl;
    cout << bank.withdraw(5, 5) << endl;
    return 0;
}