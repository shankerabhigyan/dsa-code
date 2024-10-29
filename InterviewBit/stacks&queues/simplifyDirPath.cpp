#include<bits/stdc++.h>
using namespace std;

string balancePath(string s){
    if(s.length()==1) return s;

    stack<string> dir;
    string curr_dir = "";
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(curr_dir=="" && ch=='/'){
            curr_dir+=ch;
        }
        else if(ch=='.'){
            if(i+1<s.length() && s[i+1]=='.'){
                if(dir.empty()){
                    continue;
                }
                dir.pop();
            }
        }
        else if(ch=='/' && curr_dir=="/") continue;
        else if(ch=='/'){
            dir.push(curr_dir);
            curr_dir = "/";
        }
        else{
            curr_dir+=ch;
        }
    }
    if(curr_dir!="" && curr_dir!="/") dir.push(curr_dir);
    if(dir.empty()){
        return "/";
    }
    string ans="";
    while(!dir.empty()){
        ans=dir.top()+ans;
        dir.pop();
    }
    return ans;
}

string balancePathVec(string s) {
    if(s.length()==1) return s;

    vector<string> dir;  // Changed from stack to vector
    string curr_dir = "";
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(curr_dir=="" && ch=='/'){
            curr_dir+=ch;
        }
        else if(ch=='.'){
            if(i+1<s.length() && s[i+1]=='.'){
                if(dir.empty()){
                    continue;
                }
                dir.pop_back();  // Changed from pop() to pop_back()
            }
        }
        else if(ch=='/' && curr_dir=="/") continue;
        else if(ch=='/'){
            dir.push_back(curr_dir);  // Changed from push() to push_back()
            curr_dir = "/";
        }
        else{
            curr_dir+=ch;
        }
    }
    if(curr_dir!="" && curr_dir!="/") dir.push_back(curr_dir);  // Changed from push() to push_back()
    if(dir.empty()){
        return "/";
    }
    string ans="";
    // Changed stack iteration to vector iteration in reverse
    for(int i = dir.size()-1; i >= 0; i--) {
        ans = dir[i] + ans;
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << balancePath(s) << endl;
    return 0;
}