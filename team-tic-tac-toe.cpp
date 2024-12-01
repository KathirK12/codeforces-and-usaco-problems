#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    vector<string> board(3);
    vector<map<char, int>> rows(3);
    vector<map<char, int>> columns(3);
    vector<map<char, int>> diags(2);
    map<vector<char>, int> tw;
    map<vector<char>, int> ow;
    
    cin >> board[0] >> board[1] >> board[2];
    
    for (int i = 0; i < 3; i++) {
        
        string row = board[i];
        
        rows[i][row[0]]++;
        rows[i][row[1]]++;
        rows[i][row[2]]++;
        
        columns[0][row[0]]++;
        columns[1][row[1]]++;
        columns[2][row[2]]++;
        
        diags[0][row[i]]++;
        diags[1][row[2 - i]]++;
        
    }
    
    for (auto row : rows) {
        
        int size = row.size();
        vector<char> keys;
        
        for (auto thing : row) {
            
            keys.push_back(thing.first);
            
        }
        
        sort(keys.begin(), keys.end());
        
        if (size == 1) {
            
            ow[keys]++;
            
        }
        
        if (size == 2) {
            
            tw[keys]++;
            
        }
        
    }
    
    for (auto column : columns) {
        
        int size = column.size();
        vector<char> keys;
        
        for (auto thing : column) {
            
            keys.push_back(thing.first);
            
        }
        
        sort(keys.begin(), keys.end());
        
        if (size == 1) {
            
            ow[keys]++;
            
        }
        
        if (size == 2) {
            
            tw[keys]++;
            
        }
        
    }
    
    for (auto diag : diags) {
        
        int size = diag.size();
        vector<char> keys;
        
        for (auto thing : diag) {
            
            keys.push_back(thing.first);
            
        }
        
        sort(keys.begin(), keys.end());
        
        if (size == 1) {
            
            ow[keys]++;
            
        }
        
        if (size == 2) {
            
            tw[keys]++;
            
        }
        
    }
    
    cout << ow.size() << "\n" << tw.size() << "\n";

}
