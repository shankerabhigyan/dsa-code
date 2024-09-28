#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> s){
    if(s.size()==0) return "";
    if(s.size()==1) return s[0];

    string match = s[0];
    for(int i=1;i<s.size();i++){
        string temp = "";
        for(int k=0;k<s[i].length() && k<match.length();k++){
            if(s[i][k]==match[k]){
                temp+=match[k];
            }
            else{
                break;
            }
        }
        if(temp=="") return temp;
        else match = temp;
    }
    return match;
}

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    cout << longestCommonPrefix(s) << endl;
}