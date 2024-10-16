#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        
        int n, k;
        cin >> n >> k;
        
        int a[n];
        map<int, int> goodmap;
        
        for (int j = 0; j < n; j++) {
            
            cin >> a[j];
            goodmap[a[j]]++;
            
        }
        
        vector<int> goodnums;
        
        for (auto j : goodmap) {
            
            if (j.second >= k) {
                
                goodnums.push_back(j.first);
                
            }
            
        }
        
        if (goodnums.size() == 0) {
            
            cout << "-1" << "\n";
            
        }
        else {
        
            sort(goodnums.begin(), goodnums.end());
            
            int len, lend, rend, templ;
            
            len = 0;
            lend = goodnums[0];
            rend = goodnums[0];
            templ = goodnums[0];
            
            for (int j = 1; j < goodnums.size(); j++) {
                
                if (goodnums[j] - 1 == goodnums[j - 1]) {
                    
                    if (goodnums[j] - templ > len) {
                        
                        lend = templ;
                        rend = goodnums[j];
                        len = goodnums[j] - templ;
                        
                    }
                    
                }
                else {
                    
                    templ = goodnums[j];
                    
                }
                
            }
            
            std::cout << lend << " " << rend << "\n";
        
        }
        
    }
    
}
