#include<bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/palindrome-partitioning/
/*
Palindrome partitioning.
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",

Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]

*/

bool isPalindrome(string &s){
    if(s.size()==0) return false;
    int i=0, j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void backtrack(string &s, string curr, vector<string> currvec, int i, vector<vector<string>> &ans){
    if(i==s.size()){
        if(isPalindrome(curr)){
            currvec.push_back(curr);
            ans.push_back(currvec);
        }
        return;
    }
    else{
        curr = curr + s[i];
        if(isPalindrome(curr)){
            currvec.push_back(curr);
            backtrack(s,"",currvec,i+1,ans);
            currvec.pop_back();
            backtrack(s,curr,currvec,i+1,ans);
            return;
        }
        else{
            backtrack(s,curr,currvec,i+1,ans);
            return;
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    backtrack(s,"",{},0,ans);
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<vector<string>> ans = partition(s);
    for(auto v:ans){
        for(auto st:v){
            cout << st << " ";
        }
        cout << endl;
    }
    return 0;
}