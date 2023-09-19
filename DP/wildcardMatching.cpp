// https://leetcode.com/problems/wildcard-matching/
#include<bits/stdc++.h>
using namespace std;

bool isMatching(string&s, string&p, int i, int j, vector<vector<int>> &dp){
    // base cases
    if(i<0 && j<0){
        return true;
    }
    if(i>=0 && j<0){
        return false;
    }
    if(i<0 && j>=0){
        for(int k=0;k<=j;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // match cases
    if(p[j]=='?' || s[i]==p[j]){
        return dp[i][j]=isMatching(s,p,i-1,j-1,dp);
    }
    if(p[j]=='*'){
        return dp[i][j]=(isMatching(s,p,i-1,j,dp) || isMatching(s,p,i,j-1,dp));
    }
    return dp[i][j]=false;
}

// for 1-based indexing solution refer to my LC submission : https://leetcode.com/problems/wildcard-matching/submissions/1053767254/

bool wildCard(string s, string p){
    vector<vector<int>> dp(s.length(),vector<int>(p.length(),-1));
    return isMatching(s,p,s.length()-1,p.length()-1,dp);
}

int main(){
    string s,p;
    cin >> s >> p;
    cout << wildCard(s,p) << endl;
    return 0;
}