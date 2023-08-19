#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long int countDerangements(int n){ // using plain recursion
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    long long int ans = countDerangements(n-1) + countDerangements(n-2);
    ans = (n-1)*ans;
    return ans%MOD;
}


long long int countDerangementsDP(int n){
    vector<long long int> dp(n+1,0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= n; i++){
        dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
        dp[i] = dp[i] % MOD;
    }
    return dp[n];    
}

long long int countDerangementsDP_memOpt(int n){
    long long int a = 0;
    long long int b = 1;
    long long int temp;
    for(int i = 3; i <= n; i++){
        temp = (i-1)*(a+b);
        temp = temp % MOD;
        a = b;
        b = temp;
    }
    return b;
}


int main(){
    int n;
    cin >> n;
    cout << countDerangementsDP_memOpt(n) << endl;
    return 0;
}