#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ll N, K;
    cin >> N >> K;
    
    vector<ll> days(N);
    cin >> days[0];
    
    ll daystreak = 1;
    ll price = 0;
    
    for (ll i = 1; i < N; i++) {
        
        cin >> days[i];
        
        if (days[i] - 1 == days[i - 1]) {
            
            daystreak++;
            
        } else if (days[i] - days[i - 1] - 1 < K) { 
            
            daystreak += days[i] - days[i - 1];
            
            
        } else {
            
            price += daystreak + K;
            daystreak = 1;
            
        }
        
    }
    
    price += daystreak + K;
    
    cout << price << "\n";

}
