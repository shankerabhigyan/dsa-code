// https://leetcode.com/problems/unique-binary-search-trees/
#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp){
    if(n<=1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += solve(i-1,dp) * solve(n-i,dp);
    }
    return dp[n] = ans;
}

int numBST(int n){
    int ans = 0;
    vector<int> dp(n+1,-1);
    for(int i=1;i<=n;i++){
        //vector<int> dp(n+1,-1);
        ans += solve(i-1,dp) * solve(n-i,dp);
    }
    return ans;
}

int numBSTTab(int n){
    vector<int> dp(n+1);
    dp[1] = dp[0] = 1;
    for(int i=2;i<=n;i++){
        int ans = 0;
        for(int j=1;j<=i;j++){
            ans += dp[j-1] * dp[i-j];
        }
        dp[i] = ans;
    }
    return dp[n];
}

// solving using Catalan Numbers
int Catalan(int n){
    long long int ans = 1;
    for(int i=1;i<=n;i++){
        ans *= (n+i);
        ans /= i;
    }
    return int(ans/(n+1));
}

int main(){
    int n;
    cin >> n;
    cout << Catalan(n) << endl;
    return 0;
}