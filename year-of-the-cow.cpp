#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    int N;
    cin >> N;
    map<string, pair<string, int>> cows;
    
    map<string, int> years = {
        {"Ox", 1},
        {"Tiger", 2},
        {"Rabbit", 3},
        {"Dragon", 4},
        {"Snake", 5},
        {"Horse", 6},
        {"Goat", 7},
        {"Monkey", 8},
        {"Rooster", 9},
        {"Dog", 10},
        {"Pig", 11},
        {"Rat", 12}
    };
    
    cows["Bessie"] = {"Ox", 1};
    
    for (int i = 0; i < N; ++i) {
        
        string name, pos, year, other, trash;
        
        cin >> name >> trash >> trash >> pos >> year >> trash >> trash >> other;
        
        int position;
        
        if (pos == "previous") {
            
            position = years[cows[other].first] - years[year];
            
            if (position <= 0) {
                
                position += 12;
                
            }
            
            position = cows[other].second - position;
            
        }
        
        if (pos == "next") {
            
            position = years[year] - years[cows[other].first];
            
            if (position <= 0) {
                
                position += 12;
                
            }
            
            position = cows[other].second + position;
            
        }
        
        cows[name] = {year, position};
        
    }
    
    
    cout << abs(cows["Bessie"].second - cows["Elsie"].second) << "\n";

}
