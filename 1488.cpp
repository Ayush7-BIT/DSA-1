#include <bits/stdc++.h>
using namespace std;
vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();
    vector<int> ans(n, 1); 
    unordered_map<int, int> fullLake;
    set<int> dryDays;  

    for (int i = 0; i < n; ++i) {
        if (rains[i] == 0) {
            dryDays.insert(i);  
        } else {
            int lake = rains[i];
            ans[i] = -1; 
            if (fullLake.count(lake)) {
                auto it = dryDays.lower_bound(fullLake[lake]);
                if (it == dryDays.end()) {
                    return {}; 
                }
                ans[*it] = lake; 
                dryDays.erase(it); 
            }
            fullLake[lake] = i;  
        }
    }
    return ans;
}
int main() {
    vector<int> rains={1,2,0,0,2,1};
    vector<int> ans=avoidFlood(rains);
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}