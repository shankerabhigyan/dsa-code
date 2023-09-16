#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-palindromic-subsequence/

int longestCommonSubsequenceOpt(string s){
    string text1 = s;
    string text2 = s;
    text2 = string(text2.rbegin(),text2.rend());
    int n = text1.length();
    int m = text2.length();
    vector<int> dp(m+1,0);
    for(int i=1;i<=n;i++){
        int prev = 0;
        for(int j=1;j<=m;j++){
            int temp = dp[j];
            if(text1[i-1]==text2[j-1]){
                dp[j] = 1 + prev;
            }
            else{
                dp[j] = max(dp[j],dp[j-1]);
            }
            prev = temp;
        }
    }
    return dp[m];
}

int main(){
    string text1,text2;
    cin >> text1 >> text2;
    cout << longestCommonSubsequence(text1,text2) <<  endl;
   