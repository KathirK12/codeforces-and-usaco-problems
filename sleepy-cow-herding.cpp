#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    
    ll cow1, cow2, cow3;
    
    cin >> cow1 >> cow2 >> cow3;
    
    if (cow1 + 1 == cow2 && cow2 + 1 == cow3) {
        
        cout << 0 << "\n" << 0 << "\n";
        return 0;
        
    } else if (cow1 + 2 == cow2 || cow2 + 2 == cow3) {
        
        cout << 1 << "\n";
        
    } else {
        
        cout << 2 << "\n";
        
    }
    
    cout << (max(cow2 - cow1, cow3 - cow2) - 1) << "\n";

}
