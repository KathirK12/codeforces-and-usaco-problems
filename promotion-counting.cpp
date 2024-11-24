#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    
    array<ll, 3> before;
    array<ll, 3> after;
    array<ll, 3> promotions;
    
    ll b1, b2;
    
    cin >> b1 >> b2;
    
    for (int i = 0; i < 3; i++) {
        
        cin >> before[i] >> after[i];
        
    }
    
    promotions[2] = after[2] - before[2];
    promotions[1] = after[1] + promotions[2] - before[1];
    promotions[0] = after[0] + promotions[1] - before[0];
    
    cout << promotions[0] << "\n" << promotions[1] << "\n" << promotions[2] << "\n";
    
}
