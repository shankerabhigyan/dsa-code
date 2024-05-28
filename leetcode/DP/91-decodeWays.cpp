// https://leetcode.com/problems/decode-ways/description/
#include<bits/stdc++.h>
using namespace std;

void print(vector<string> ans){
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;
}

bool isValid(string s){
    if (s.size()==1){
        return s[0]!='0';
    }
    if(s.size()==2){
        return s[0]!='0' && stoi(s)<=26;  
    }
    else{
        return false;
    }
}

int recurse(string s, map<pair<int,bool>,int> &dp){
    if(s.size()==0){
        return 1;
    }
    if(s.size()==1){
        return 1;
    }
    if(dp.find({s.size(), true})!=dp.end()){
        return dp[{s.size(), true}];
    }
    else{
        // take 1 digit
        int ans1 = 1 * recurse(s.substr(1, s.size()-1),dp);
        // take 2 digits
        if(isValid(s.substr(0, 2))){
            int ans2 = 1 * recurse(s.substr(2, s.size()-2),dp);
            dp[{s.size(), true}] = ans1 + ans2;
            return ans1 + ans2;
        }
        else{
            dp[{s.size(), true}] = ans1;
            return ans1;
        }
    }
}

int numDecodings(string s){
    if(s[0]=='0'){
        return 0;
    }
    // check for 0s, all 0 digits should be preceded by either 1 or 2 else return 0
    for(int i=1; i<s.size(); i++){
        if(s[i]=='0'){
            if(i==0 || (s[i-1]!='1' && s[i-1]!='2')){
                return 0;
            }
            // if(s[i+1]=='0'){
            //     return 0;
            // }
        }
    }
    // now remove all the two digit numbers ending with 0, 
    // and break the strings into substring befor and after the 2 digit number
    vector<string> temp;
    int count = 1;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            s.erase(i-1, 2);
            i = i-2;
            temp.push_back(s.substr(0, i+1));
            s = s.substr(i+1, s.size()-i-1);
            i=0;
        }
    }
    temp.push_back(s);
    print(temp);
    // now we have all the strings without 0s, now we can start counting the number of ways
    for (auto i: temp){
        map<pair<int,bool>,int> dp;
        count = count * recurse(i,dp);
    }
    return count;
}

int numDecodingsTab(string s){
    // tabulation
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[n] = 1;
    for(int i=n-1; i>=0; i--){
        if(s[i]!='0'){
            dp[i] = dp[i+1];
        }
        if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
            dp[i] += dp[i+2];
        }
    }
    return dp[0];
}

int main(){
    string s;
    cin >> s;
    cout <<  numDecodings(s) << endl;
    return 0;
}