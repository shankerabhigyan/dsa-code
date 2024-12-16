#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size()&1) return false;
        stack<char> st;
        map<char,char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
        for(char ch:s){
            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else{
                if(st.empty() || mp[ch]!=st.top()) return false;
                else st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};