#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, sum, intavg;
    double avg;
    cin >> N;
    
    int nums[N];
    
    for (int i = 0; i < N; i++) {
        
        cin >> nums[i];
        
    }
    
    for (int i = 0; i < N; i++) {
        
        for (int j = i; j < N; j++) {
            
            for (int k = i; k <= j; k++) {
                avg += nums[k];
            }
            
            avg /= ((j - i) + 1);
            
            intavg = avg;
                
            if (intavg == avg) {
                   
                for (int k = i; k <= j; k++) {
                    if (nums[k] == intavg) {
                        sum++;
                        break;
                    }
                }
                    
            }
            
            avg = 0;
            
        }
        
    }
    
    cout << sum << "\n";
    
}
