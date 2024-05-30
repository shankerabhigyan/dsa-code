#include<bits/stdc++.h>
using namespace std;

bool recurse(string str, vector<string>&wordDict, int s, vector<int>&dp){
    if(s==str.length()){
        return true;
    }
    if(dp[s]!=-1){
        return dp[s];
    }
    for(int e=s; e<str.length();e++){
        string temp = str.substr(s, e-s+1);
        if(find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end()){
            if(recurse(str, wordDict, e+1,dp)){
                dp[s] = 1;
                return true;
            }
        }
    }
    dp[s] = 0;
    return false;    
}

bool wordBreak(string &str, vector<string>&wordDict){
    bool ans;
    vector<int> dp(str.length(), -1);
    ans = recurse(str, wordDict, 0,dp);
    return ans;
}

bool wordBreakTab(string &str, vector<string>&wordDict){
    vector<int>dp(str.length()+1, 0);
    int n = str.length();
    dp[n] = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            string temp = str.substr(i, j-i+1);
            if(find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end() && dp[j+1]){
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[0];
}

int main(){
    string s;
    vector<string> wordDict;
    cin>>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        wordDict.push_back(temp);
    }
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}