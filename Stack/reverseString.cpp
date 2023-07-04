#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    stack<char> s;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    string ans = "";
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout << ans << endl;

    return 0;
}