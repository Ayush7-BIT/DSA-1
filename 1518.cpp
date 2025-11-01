#include <bits/stdc++.h>
using namespace std;
int numWaterBottles(int numBottles, int numExchange) {
    int result = numBottles; 
    int empty = numBottles;  

    while (empty >= numExchange) {
        int newBottles = empty / numExchange;   
        result += newBottles;                   
        empty = empty % numExchange + newBottles; 
    }
    return result;
}
int main() {
    int numBottles = 9, numExchange = 3;
    cout << numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}