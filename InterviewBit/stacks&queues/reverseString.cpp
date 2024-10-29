#include<bits/stdc++.h>
using namespace std;

string reverse(string s){
    stack<char> st;
    for(char ch:s){
        st.push(ch);
    }
    string ans = "";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << reverse(s) << endl;
    return 0;
}