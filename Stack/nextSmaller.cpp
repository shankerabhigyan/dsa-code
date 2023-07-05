// return the next smaller element for each element in the stack
#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop(); 
    }
    cout << endl;
}

int findSmaller(stack<int>s, int x){
    int n = s.top();
    if(n<x){
        return n;
    }
    s.pop();
    return findSmaller(s,x);
    
}

void nextSmaller(stack<int>&s, stack<int>&ans){
    if(s.empty()){
        s.push(-1);
        return;
    }
    int x = s.top();
    s.pop();
    nextSmaller(s,ans);
    //print(s);
    int n = findSmaller(s,x);
    ans.push(n);
    s.push(x);
    return;
}

int main(){
    stack<int> s;
    int n;
    cin >> n;
    while(n>0){
        int x;
        cin >> x;
        s.push(x);
        n--;
    }
    stack<int> ans;
    nextSmaller(s,ans);
    print(ans);
    return 0;
}