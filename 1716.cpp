#include <bits/stdc++.h>
using namespace std;
int totalMoney(int n) {
    int total = 0;
    int fullWeeks = n / 7;
    int remainingDays = n % 7;

    
    for (int week = 0; week < fullWeeks; ++week) {
        total += 7 * (week + 1) + (7 * 6) / 2;
    }

    for (int day = 0; day < remainingDays; ++day) {
        total += (fullWeeks + 1) + day;
    }

    return total;
}
int main() {
    int n=10;
    cout<<totalMoney(n)<<endl;
    return 0;
}