#include <bits/stdc++.h>
using namespace std;

map<int, int> b1;
map<int, int> b2;
vector<int> ways;

void rec (int n, int b1gallons, map<int, int> barn1, map<int, int> barn2) {
    
    if (n == 4) {
        
        if (find(ways.begin(), ways.end(), b1gallons) == ways.end()) {
            
            ways.push_back(b1gallons);
            
        }
        
    } else {
        
        if (n % 2 == 0) {
            
            for (auto bucket : barn1) {
                
                map<int, int> b1c = barn1;
                map<int, int> b2c = barn2;
                int b1g = b1gallons;
                
                b1g -= bucket.first;
                b2c[bucket.first]++;
                bucket.second--;
                if (bucket.second <= 0) {
                    
                    b1c.erase(bucket.first);
                    
                }
                
                rec(n + 1, b1g, b1c, b2c);
                
            }
            
        } else {
            
            for (auto bucket : barn2) {
                
                map<int, int> b1c = barn1;
                map<int, int> b2c = barn2;
                int b1g = b1gallons;
                
                b1g += bucket.first;
                b1c[bucket.first]++;
                bucket.second--;
                if (bucket.second <= 0) {
                    
                    b2c.erase(bucket.first);
                    
                }
                
                rec(n + 1, b1g, b1c, b2c);
                
            }
            
        }
        
    }
    
}

int main() {

    for (int i = 0; i < 10; i++) {
        
        int x;
        cin >> x;
        
        b1[x]++;
        
    }
    
    for (int i = 0; i < 10; i++) {
        
        int x;
        cin >> x;
        
        b2[x]++;
        
    }
    
    rec(0, 1000, b1, b2);
    
    cout << ways.size() << "\n";
    
}
