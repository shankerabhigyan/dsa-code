#include<bits/stdc++.h>
using namespace std;

int braces(string s){
    stack<char> br;
    stack<char> op;
    bool flag = true;
    for(char ch:s){
        if(ch=='('){
            br.push(ch);
            flag=false;
        }
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            if(!flag){
                flag=true;
                op.push(ch);
            }
        }
        if(ch==')'){
            if(flag){
                br.pop();
                op.pop();
                if(op.size()==br.size()){
                    flag = false;
                }
                else{
                    flag=true;
                }
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    string s = "";
    cin >> s;
    cout << braces(s) << endl;
    return 0;
}