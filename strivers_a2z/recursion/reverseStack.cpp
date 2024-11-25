#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void rev(stack<int>&st, int i, int &max){
        if(i==max) return;
        int t = st.top();
        st.pop();
        int x = st.top();
        st.pop();
        st.push(t);
        rev(st,i+1,max);
        st.push(x);
        return;
    }
    void Reverse(stack<int> &st){
        for(int i=st.size();i>0;i--){
            rev(st,1,i);
        }
        return;
    }
};