#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    int W, H, x1, y1, x2, y2, w, h, y, x;
    
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
        
        y = min(h - y1, y2 - (H - h));
        x = min(w - x1, x2 - (W - w));
        
        if (y < 0) {
            y = 0;
        }
        if (x < 0) {
            x = 0;
        }
        
        if (!((y2 + y) <= H && (y1 - y) >= 0)) {
            y = -1;
        }
        
        if (!((x2 + x) <= W && (x1 - x) >= 0)) {
            x = -1;
        }
        
        if (x >= 0 && y >= 0) {
            
            cout << min(x, y) << "\n";
            
        }
        else {
            
            cout << max(x, y) << "\n";
            
        }
        
    }
    
    
}
