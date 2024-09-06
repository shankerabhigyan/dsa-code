#include<bits/stdc++.h>
using namespace std;

void backtrack(string curr, int open, int close, vector<string>&ans){
    if(open==0){
        while(close>0){
            curr+=')';
            close--;
        }
        ans.push_back(curr);
        return;
    }
    else{
        backtrack(curr+'(', open-1, close, ans);
        if(close>open){
            backtrack(curr+')', open, close-1,ans);
        }
        return;
    }
}

vector<string> generateParentheses(int a){
    vector<string> ans;
    backtrack("",a,a,ans);
    return ans;
}

int main(){
    int a;
    cin >> a;
    vector<string> parantheses = generateParentheses(a);
    for(auto x:parantheses){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}