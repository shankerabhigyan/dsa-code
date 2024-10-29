#include<bits/stdc++.h>
using namespace std;

int isValid(string s){
    stack<char> st;
    for(char ch:s){
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(st.size()==0) return 0;
            if(ch==')'){
                if(st.top()!='(') return 0;
                st.pop();
            }
            if(ch=='}'){
                if(st.top()!='{') return 0;
                st.pop();
            }
            if(ch==']'){
                if(st.top()!='[') return 0;
                st.pop();
            }
        }
    }
    if(st.size()!=0) return 0;
    return 1;
}

int main(){
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}