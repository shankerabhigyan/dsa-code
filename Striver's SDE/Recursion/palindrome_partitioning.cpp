#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning/

bool check_palindrome(string str, int s, int e){
    while(s<=e){
        if(str[s]!=str[e]) return false;
        s++;
        e--;
    }
    return true;
}

void partition(string str, vector<string> temp, int s, int e, vector<vector<string>>&ans){
    if(s>e){
        ans.push_back(temp);
        return;
    }
    for(int i=s;i<=e;i++){
        if(check_palindrome(str,s,i)){
            temp.push_back(str.substr(s,i-s+1));
            partition(str,temp,i+1,e,ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> getPalindromePartition(string str){
    vector<string> temp;
    vector<vector<string>> ans;
    partition(str,temp,0,str.size()-1,ans);
    return ans;
}

int main(){
    string str;
    str = "acb";
    cout << str.substr(2,1) << endl;
    return 0;
}