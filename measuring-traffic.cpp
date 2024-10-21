#include <iostream>
#include <bits/stdc++.h>

int main() {
    
    int N;
    std::cin >> N;
    
    std::string states[N];
    int lbs[N];
    int ubs[N];
    
    int lbstart;
    int ubstart;
    int lbend;
    int ubend;
    
    bool startcalc = false;
    
    for (int i = 0; i < 2 * N; ++i) {
        
        if (i < N) {
            
            std::cin >> states[i] >> lbs[i] >> ubs[i];
            
            if (states[i] == "none") {
                if (!startcalc) {
                    startcalc = true;
                    lbend = lbs[i];
                    ubend = ubs[i];
                }
                else {
                    lbend = std::max(lbend, lbs[i]);
                    ubend = std::min(ubend, ubs[i]);
                }
            }
            
            if (states[i] == "on" && startcalc) {
                
                lbend += lbs[i];
                ubend += ubs[i];
                
            }
            
            if (states[i] == "off" && startcalc) {
                
                lbend -= ubs[i];
                ubend -= lbs[i];
                
            }
            
        }
        else {
            
            if (states[(2 * N) - 1 - i] == "none") {
                if (startcalc) {
                    startcalc = false;
                    lbstart = lbs[(2 * N) - 1 - i];
                    ubstart = ubs[(2 * N) - 1 - i];
                }
                else {
                    lbstart = std::max(lbstart, lbs[(2 * N) - 1 - i]);
                    ubstart = std::min(ubstart, ubs[(2 * N) - 1 - i]);
                }
            }
            
            if (states[(2 * N) - 1 - i] == "on" && !startcalc) {
                
                lbstart -= ubs[(2 * N) - 1 - i];
                ubstart -= lbs[(2 * N) - 1 - i];
                
            }
            
            if (states[(2 * N) - 1 - i] == "off" && !startcalc) {
                
                lbstart += lbs[(2 * N) - 1 - i];
                ubstart += ubs[(2 * N) - 1 - i];
                
            } 
            
        }
        
    }
    
    if (lbstart < 0) {
        lbstart = 0;
    }
    if (ubstart < 0) {
        ubstart = 0;
    }
    if (lbend < 0) {
        lbend = 0;
    }
    if (ubend < 0) {
        ubend = 0;
    }
    
    std::cout << lbstart << " " << ubstart << "\n" << lbend << " " << ubend << "\n";
    
}
