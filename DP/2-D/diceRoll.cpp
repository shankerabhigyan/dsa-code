#include<bits/stdc++.h>
using namespace std;

# define MOD 1000000007

int rollit(int n, int k, int rem, int index, vector<vector<int>> &dp){
    if(rem<0 || index>n){
        return 0;
    }
    if(rem==0){
        if(index==n){
            return 1;
        }
        return 0;
    }
    if(dp[rem][index]!=-1){
        return dp[rem][index];
    }
    int ways = 0;
    for(int i=1;i<=k && i<=rem;i++){
        ways = (ways + rollit(n,k,rem-i,index+1,dp))%MOD;
    }
    return dp[rem][index] = ways%MOD;
}

int numWaysToTarget(int n,int k, int target){
    vector<vector<int>> dp(target+1,vector<int>(n+1,-1));
    return rollit(n,k,target,0,dp);
}

int numWaysToTargetTab(int n, int k, int target){
    vector<vector<int>> dp(target+1,vector<int>(n+1,0));
    dp[0][n] = 1;
    for(int rem=1;rem<=target;rem++){
        for(int index=n-1;index>=0;index--){
            for(int i=1;i<=k && i<=rem;i++){
                dp[rem][index] = (dp[rem][index] + dp[rem-i][index+1])%MOD;
            }
        }
    }
    return dp[target][0];
}

int numWaysToTargetOpt(int n, int k, int target){
    vector<int> dp(target+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        vector<int> temp(target+1,0);
        for(int rem=1;rem<=target;rem++){
            for(int j=1;j<=k && j<=rem;j++){
                temp[rem] = (temp[rem] + dp[rem-j])%MOD;
            }
        }
        dp = temp;
    }
    return dp[target];
}

int main(){
    int n,k,target;
    cin >> n >> k >> target;
    cout << numWaysToTarget(n,k,target) << endl;
}