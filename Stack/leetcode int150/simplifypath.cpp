// https://leetcode.com/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150
#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path){
    stack<string> st;
    for(int i=0;i<path.length();i++){
        if(path[i]=='/'){
            continue;
        }
        if(path[i]=='.'){
            if(path[i+1]=='.'){
                if(i+2<path.k && path[i+2]!='/'){
                    string dir = "";
                    while(i<path.length() && path[i]!='/'){
                        dir += path[i];
                        i++;
                    }
                    st.push(dir);
                    continue;
                }
                if(!st.empty()){
                    st.pop();
                }
                i++;
            }
        }
        else{
            string dir = "";
            while(i<path.length() && path[i]!='/'){
                dir += path[i];
                i++;
            }
            st.push(dir);
        }
    }
    string ans = "";
    while(!st.empty()){
        ans = "/" + st.top() + ans;
        st.pop();
    }
    if(ans==""){
        return "/";
    }
    return ans;
}

int main(){
    string path;
    cin >> path;
    cout << simplifyPath(path) << endl;
    return 0;
}