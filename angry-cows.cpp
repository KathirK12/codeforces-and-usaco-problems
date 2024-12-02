#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    int N;
    cin >> N;
    vector<ll> haybales(N);
    vector<int> exploded(N);
    
    for (int i = 0; i < N; ++i) {
        
        cin >> haybales[i];
        
    }

    for (int i = 0; i < N; ++i) {
        
        vector<ll> bales = haybales;
        vector<ll> exploders = {haybales[i]};
        bales.erase(bales.begin() + i);
        bool explode = true;
        int t = 1;
        int explodeds = 1;
        
        while (explode) {
            
            vector<ll> nextexplode;
            
            for (int haybale : exploders) {
                
                for (int j = haybale - t; j < haybale; ++j) {
                    
                    if (find(bales.begin(), bales.end(), j) != bales.end()) {
                        
                        nextexplode.push_back(j);
                        int index = distance(bales.begin(), find(bales.begin(), bales.end(), j));
                        bales.erase(bales.begin() + index);
                        explodeds++;

                    }
                    
                }
                
                for (int j = haybale + t; j > haybale; --j) {
                    
                    if (find(bales.begin(), bales.end(), j) != bales.end()) {
                        
                        nextexplode.push_back(j);
                        int index = distance(bales.begin(), find(bales.begin(), bales.end(), j));
                        bales.erase(bales.begin() + index);
                        explodeds++;
                        
                    }
                    
                }
                
            }
            
            if (nextexplode.size() == 0) {
                
                exploded.push_back(explodeds);
                explode = false;
                
            }
            
            exploders = nextexplode;
            t++;
            
        }
        
    }

    cout << *max_element(exploded.begin(), exploded.end()) << "\n";

}
