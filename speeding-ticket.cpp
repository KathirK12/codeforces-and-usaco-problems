#include <iostream>
#include <bits/stdc++.h>

int main() {
    
    int N, M;
    
    std::cin >> N >> M;
    
    int nsegs[N];
    int nspeeds[N];
    int msegs[M];
    int mspeeds[M];
    
    int sum = 0;
    int nextsum;
    
    int cowsegment = 0;
    int cowspeed = 0;
    int roadspeed = 0;
    int speeddiff;
    int speedover = 0;
    
    for (int i = 0; i < N + M; ++i) {
        
        if (i >= N) {
            
            msegs[i - N] = sum - 100;
            std::cin >> nextsum >> mspeeds[i - N];
            sum += nextsum;
            
        }
        else {
            
            nsegs[i] = sum;
            std::cin >> nextsum >> nspeeds[i];
            sum += nextsum;
            
        }
        
    }
    
    for (int i = 1; i <= 100; ++i) {
        
        for(int j = 0; j < N; ++j) {
            
            if (i > nsegs[j]) {
                
                roadspeed = nspeeds[j];
                
                
            }
            
        }
        
        for (int j = 0; j < M; ++j) {
            
            if (i > msegs[j]) {
                
                cowsegment = msegs[j];
                cowspeed = mspeeds[j];
                
            }
            
        }
        
        if (cowspeed > roadspeed && cowspeed - roadspeed > speedover) {
            
            speedover = cowspeed - roadspeed;
            
        }
        
    }
    
    std::cout << speedover << "\n";
    
}
