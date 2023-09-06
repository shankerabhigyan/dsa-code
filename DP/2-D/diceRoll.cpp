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
    
}

int main(){
    int n,k,target;
    cin >> n >> k >> target;
    cout << numWaysToTarget(n,k,target) << endl;
}