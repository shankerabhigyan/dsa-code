#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int MOD = 1e9 + 7;
    long long int recurse(int n, vector<long long int>&dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        dp[n] = (recurse(n-1,dp) + recurse(n-2,dp))%MOD;
        return dp[n];
    }
    long long int topDown(int n) { // memoization f(n) = f(n-1)+f(n-2)
        vector<long long int> dp(n+1,-1);
        return recurse(n,dp);
    }
    long long int bottomUp(int n) {
        long long int prev1 = 0;
        long long int prev2 = 1;
        long long int ans = 1;
        for(int i=2;i<=n;i++){
            ans = (prev1 + prev2)%MOD;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};


int main(){
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Top-Down approach result: " << sol.topDown(n) << endl;
    cout << "Bottom-Up approach result: " << sol.bottomUp(n) << endl;
    return 0;
}