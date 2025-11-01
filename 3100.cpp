#include <bits/stdc++.h>
using namespace std;
int maxBottlesDrunk(int numBottles, int numExchange) {
    int result = numBottles; 
    int empty = numBottles; 
    
    while (empty >= numExchange) {

        empty -= numExchange;
        numExchange++; 
        result++;      
        empty++;       
    }
    
    return result;
}
int main() {
    int numBottles = 9;
    int numExchange = 3;
    cout << maxBottlesDrunk(numBottles, numExchange) << endl;
    return 0;
}