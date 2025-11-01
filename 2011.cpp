#include <bits/stdc++.h>
using namespace std;
int finalValueAfterOperations(vector<string>& operations) {
    int X = 0;
    for(string &op : operations) {
        (op[1] == '+') ? X++ : X--;
    }
    return X;
}
int main() {
    vector<string> operations = {"--X","X++","X++"};
    int result = finalValueAfterOperations(operations);
    cout << "Final Value: " << result << endl;
    return 0;
}