// https://leetcode.com/problems/valid-parentheses/
// {} : balanced
// }{ : unbalanced
#include<bits/stdc++.h>
using namespace std;

bool isValid(string str){
    stack <char> s;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        else if(ch==')'){
            if(s.empty() || s.top()!='('){
                return false;
            }
            s.pop();
        }
        else if(ch=='}'){
            if(s.empty() || s.top()!='{'){
                return false;
            }
            s.pop();
        }
        else if(ch==']'){
            if(s.empty() || s.top()!='['){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){

    string s;
    cin>>s;
    if(isValid(s)){
        cout<<"Balanced";
    }
    else{
        cout<<"Unbalanced";
    }

}