#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop(); 
    }
    cout << endl;
}

void InsertAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int el = s.top();
    s.pop();
    InsertAtBottom(s,x);
    s.push(el);
    return;
    
}

void Reverse(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    // recursive relation
    int n = s.top();
    s.pop();
    Reverse(s);

    // function
    InsertAtBottom(s,n);
    return;
}

int main(){
    stack <int> s;
    int n;
    cin >> n;
    while(n-->0){
        int x;
        cin >> x;
        s.push(x);
    }
    print(s);
    Reverse(s);
    print(s);
    return 0;
}