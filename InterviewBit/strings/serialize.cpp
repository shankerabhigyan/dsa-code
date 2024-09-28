#include<bits/stdc++.h>
using namespace std;

string serialize(vector<string> &s){
    string result;
    for (const string &str : s) {
        result += str + to_string(str.size()) + "~";
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    cout << serialize(s) << endl;
    return 0;
}