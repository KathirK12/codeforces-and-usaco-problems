#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int cows, characters, sum;
    string gene;
    bool sim = false;
    
    cin >> cows >> characters;
    
    map<int, vector<char>> spotty;
    map<int, vector<char>> plain;
    
    for (int i = 0; i < 2 * cows; ++i) {
        
        if (i < cows) {
        
            cin >> gene;
            
            for (int j = 0; j < characters; j++) {
                
                spotty[j].push_back(gene[j]);
                
            }
        
        }
        else {
            
            cin >> gene;
            
            for (int j = 0; j < characters; j++) {
                
                plain[j].push_back(gene[j]);
                
            }
            
        }
        
    }
    
    for (int i = 0; i < characters; i++) {
        
        for (int j = 0; j < cows; j++) {
            
            for (int k = 0; k < cows; k++) {
                
                if (spotty[i][j] == plain[i][k]) {
                    
                    sim = true;
                    break;
                    
                }
                
            }
            
            if (sim) {
                break;
            }
            
        }
        
        if (!sim) {
            
            sum++;
            
        }
        
        sim = false;
        
    }
    
    cout << sum;
    
}
