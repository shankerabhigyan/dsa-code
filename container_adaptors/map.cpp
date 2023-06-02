#include <bits/stdc++.h>
using namespace std;
// stores data in the form of key value pairs, one-to-one mapping
int main(){
    map<int, string> m;
    m[1] = "abc";
    m[0] = "lmn";
    m[3] = "xyz";
    m.insert({2, "pqr"}); 
    // the complexity of insert is O(log(n)) 
    for (auto i : m){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

     
    return 0;
}