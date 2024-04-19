// https://leetcode.com/problems/longest-palindromic-substring/description/
#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &st, int s, int e, vector<vector<bool>> &dp){
    if(s>e){
        return true;
    }
    if(dp[s][e]==false){
        return false;
    }
    dp[s][e] = checkPalindrome(st,s+1,e-1,dp) && st[s]==st[e];
    return dp[s][e];
}

string getLongestPalindrome(string st){
    int n=st.length();
    int window = n-1;
    vector<vector<bool>> dp(n,vector<bool>(n,true));
    while(window>0){
        int s = 0, e = s+window;
        while(e<n){
            if(checkPalindrome(st, s, e,dp)){
                return st.substr(s,e-s+1);
            }
            s++;
            e++;
        }
        window--;
    }
    return st.substr(0,1);
}

int main(){
    string s;
    cin >> s;
    cout << getLongestPalindrome(s) << endl;
    return 0;
}