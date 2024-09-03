#include<bits/stdc++.h>
using namespace std;

pair<int,int> factorial(int n, int k){
    int factorial=1;
    for(int i=1;i<=n;i++){
        factorial*=i;
        if(factorial>k){
            return {factorial,i};
        }
    }
    return {factorial,n};
}

string getPermutation(int A, int B){
    int p,x;
    B=B-1;
    pair<int,int> pa = factorial(A,B);
    p = pa.first;
    x = pa.second;
    vector<string> ans;
    vector<string> s1,s2;
    for(int i=1;i<=A-x;i++){
        s2.push_back(to_string(i));
    }
    for(int i=A-x+1;i<=A;i++){
        s1.push_back(to_string(i));
    }
    while(B%p!=0){
        p = p/(x--);
        int a = B/p;
        B = B%p;
        ans.push_back(s1[a]);
        s1.erase(s1.begin()+a);
    }
    string ss = "";
    for(auto t:s2){
        ss+=t;
    }
    for(auto t:ans){
        ss+=t;
    }
    for(auto t:s1){
        ss+=t;
    }
    return ss;
}

int main(){
    int a, b;
    cin >> a >> b;
    string s = getPermutation(a,b);
    cout << s << endl;
    return 0;
}