#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<string> combinations;
    
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    
    do {
        
        combinations.push_back(str);
        
    } while (next_permutation(str.begin(), str.end()));
    
    cout << combinations.size() << "\n";
    for (string pstr : combinations) {
        
        cout << pstr << "\n";
        
    }

}
