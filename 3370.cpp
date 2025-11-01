#include <bits/stdc++.h>
using namespace std;
int smallestNumber(int n) {
    int x = 1;
    while (x < n) {
        x = (x << 1) | 1; 
    }
    return x;
}
int main() {
    int n= 5;
    cout << smallestNumber(n) << endl;
    return 0;
}