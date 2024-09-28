#include<bits/stdc++.h>
using namespace std;


vector<string> deserialize(string s){
    vector<string> ans;
    string temp = "";
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch!='~'){
            temp+=ch;
        }
        else{
            while (!temp.empty() && isdigit(temp.back())) {
                temp.pop_back();
            }
            ans.push_back(temp);
            temp = "";
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<string> vec = deserialize(s);
    for(auto v:vec){
        cout << v << " ";
    }
    cout << endl;
}