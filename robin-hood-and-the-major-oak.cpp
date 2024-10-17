#include <iostream>
#include <bits/stdc++.h>
using namespace std;

std::string find(int num) {
    
    int state = num % 2;
    
    if (state == 0) {
        return "YES";
    }
    else {
        return "NO";
    }
    
}

int main() {

    int t;
    int n;
    int k;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        
        cin >> n >> k;
        
        if (find(k) == "YES") {
            
            cout << find(k/2) << "\n";
            
        }
        else {
            
            if (find((k-1)/2) == "NO") {
                cout << find(n+1) << "\n";
            }
            else {
                cout << find(n) << "\n";
            }
            
        }
            
        
    }

}
