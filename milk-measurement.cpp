#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N;
    cin >> N;
    
    map<string, int> cows;
    map<int, pair<string, int>> days;
    
    int maxoutput, changes;
    changes = 0;
    vector<string> today;
    vector<string> yesterday;
    
    cows["Bessie"] = 7;
    cows["Elsie"] = 7;
    cows["Mildred"] = 7;
    
    for (int i = 0; i < N; ++i) {
        
        int x, z;
        string y;
        cin >> x >> y >> z;
        
        days[x] = {y, z};
        
    }
    
    for (const auto& day : days) {
        
        cows[day.second.first] += day.second.second;
        
        maxoutput = max(cows["Bessie"], max(cows["Elsie"], cows["Mildred"]));
        
        for (const auto& cow : cows) {
            
            if (cow.second == maxoutput) {
                
                today.push_back(cow.first);
                
            }
            
        }
        
        sort(today.begin(), today.end());
        sort(yesterday.begin(), yesterday.end());
        
        if (today != yesterday) {
            changes++;
        }
        
        yesterday = today;
        today.clear();
        
    }
    
    std::cout << changes << "\n";
    
}
