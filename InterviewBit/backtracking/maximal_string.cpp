#include<bits/stdc++.h>
using namespace std;

void backtrack(string A, int B, int i, string &ans){
    if(i==A.size()||B==0){
        if(A>ans) ans = A;
        return;
    }
    for(int k=i;k<A.size();k++){
        swap(A[k],A[i]);
        backtrack(A,B-(i!=k?1:0),i+1,ans);
        swap(A[k],A[i]);
    }
    return;
}

string maximalString(string A, int B){
    string ans = A;
    backtrack(A,B,0,ans);
    return ans;
}

int main(){
    string a; 
    int b;
    cin >> a >> b;
    string s = maximalString(a,b);
    cout << s << endl;
    return 0;
}