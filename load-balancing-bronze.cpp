#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, B, tr, tl, br, bl, minm;
    cin >> N >> B;
    minm = N;
    
    vector<int> cowxs(N);
    vector<int> cowys(N);
    
    vector<int> xfence(N);
    vector<int> yfence(N);
    
    for (int i = 0; i < N; ++i) {
        
        cin >> cowxs[i] >> cowys[i];
        
        xfence[i] = cowxs[i] - 1;
        yfence[i] = cowys[i] - 1;
        
    }
    
    for (int x = 0; x < N; ++x) {
        
        for (int y = 0; y < N; ++y) {
            
            tr = 0;
            tl = 0;
            br = 0;
            bl = 0;
            
            for (int c = 0; c < N; ++c) {
                
                if (cowxs[c] < xfence[x] && cowys[c] > yfence[y]) {
                    
                    tl += 1;
                    
                }
                else if (cowxs[c] > xfence[x] && cowys[c] > yfence[y]) {
                    
                    tr += 1;
                    
                }
                else if (cowxs[c] < xfence[x] && cowys[c] < yfence[y]) {
                    
                    bl += 1;
                    
                }
                else {
                    
                    br += 1;
                    
                }
                
            }
            
            minm = min(minm, max({tl, tr, bl, br}));
            
        }
        
    }
    
    cout << minm << "\n";
    
}
