#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<vector<int>>&env, int prev, int curr, vector<vector<int>>&dp){
    if(curr = env.size()){
        return 0;
    }

    if(dp[prev+1][curr]!=-1){
        return dp[prev+1][curr];
    }
    
    int include = 0;
    if(prev==-1 || (env[curr][0]>env[prev][0] && env[curr][1]>env[prev][1])){
        include = 1 + solveMem(env,curr,curr+1,dp);
    }

    int exclude = solveMem(env,prev,curr+1,dp);
    return dp[prev+1][curr] = max(include,exclude);
}

int maxEnvelopes(vector<vector<int>> &env){
    sort(env.begin(),env.end(),[](vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    });
    int n = env.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solveMem(env,-1,0,dp);
}

int maxEnvelopesTab(vector<vector<int>> &env){
    int n = env.size();
    sort(env.begin(),env.end(),[](vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    });
    vector<int> dp(env.size()+1,0);
    for(int i=n-1;i>=0;i--){
        int include = 0;
        for(int j=i+1;j<n;j++){
            if(env[j][0]>env[i][0] && env[j][1]>env[i][1]){
                include = max(include,dp[j]);
            }
        }
        dp[i] = 1 + include;
    }
    return *max_element(dp.begin(),dp.end());
}

int maxEnvelopesBSTab(vector<vector<int>> &env){
    int n = env.size();
    sort(env.begin(),env.end(),[](vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    });
    vector<int> dp;
    for(int i=0;i<n;i++){
        auto it = lower_bound(dp.begin(),dp.end(),env[i][1]);
        if(it==dp.end()){
            dp.push_back(env[i][1]);
        }
        else{
            *it = env[i][1];
        }
    }
    return dp.size();
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> env(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin >> env[i][0] >> env[i][1];
    }
    cout << maxEnvelopesBSTab(env) << endl;
    return 0;
}