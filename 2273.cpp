#include <bits/stdc++.h>
using namespace std;
vector<string> removeAnagrams(vector<string>& words) {
    if (words.empty()) return {};

    vector<string> result;
    result.push_back(words[0]);

    for (int i = 1; i < words.size(); ++i) {
        string prev = result.back();
        string curr = words[i];

        sort(prev.begin(), prev.end());
        sort(curr.begin(), curr.end());

        if (prev != curr) { 
            result.push_back(words[i]);
        }
    }

    return result;
}
int main() {
    vector<string> words = {"abba", "baba", "bbaa", "cd", "dc"};
    vector<string> result = removeAnagrams(words);
    for (const string& word : result) {
        cout << word << " ";
    }
    return 0;
}