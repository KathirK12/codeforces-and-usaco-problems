#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> costs;
map<ll, ll> ranges;
vector<array<ll, 4>> acs;
vector<vector<ll>> subsets;

void gensubs(int n, vector<ll> subset) {
    
    if (n >= acs.size()) {
        
        subsets.push_back(subset);
        
    } else {
        
        gensubs(n + 1, subset);
        subset.push_back(n);
        gensubs(n + 1, subset);
        subset.pop_back();
        
    }
    
}

int main() {

    int N, M;
    
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        
        int start, end, lower;
        
        cin >> start >> end >> lower;
        
        for (int j = start; j <= end; ++j) {
            
            ranges[j] = lower;
            
        }
        
    }
    
    for (int i = 0; i < M; ++i) {
        
        int start, end, lower, cost;
        
        cin >> start >> end >> lower >> cost;
        
        acs.push_back({start, end, lower, cost});
        
    }
    
    gensubs(0, {});
    
    for (auto subset : subsets) {
        
        map<ll, ll> rangesLeft = ranges;
        ll cost = 0;
        
        for (int acindex : subset) {
            
            array<ll, 4> ac = acs[acindex];
            
            cost += ac[3];
            
            for (int i = ac[0]; i <= ac[1]; ++i) {
                
                if (rangesLeft.find(i) != rangesLeft.end()) {
                    
                    rangesLeft[i] -= ac[2];
                    
                }
                
            }
            
            map<ll, ll> rl2 = rangesLeft;
            
            for (auto range : rangesLeft) {
                
                if (range.second <= 0) {
                    
                    rl2.erase(range.first);
                    
                }
                
            }
            
            rangesLeft = rl2;
            
        }
        
        if (rangesLeft.size() <= 0) {
            
            costs.push_back(cost);
            
        }
        
    }
    
    cout << *min_element(costs.begin(), costs.end()) << "\n";
    
}
