#include<bits/stdc++.h>
using namespace std;

# define MOD 1000000007

int multiply(int a,int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD; // 1LL increases the range of int to long long before the final MOD operation
}

int add(int a,int b){
    return ((a%MOD)+(b%MOD))%MOD;
}

int countWays(int n, int k){ // plain Recursion
    if(n==1){
        return k;
    }
    if(n==2){
        return (k + k*(k-1)%MOD)%MOD;
    }
    return (k-1)*(countWays(n-1,k)+countWays(n-2,k)) %MOD;
}

int paint(int n, int k){ // using Tabulation
    vector<int> dp(n+1,0);
    dp[1] = k;
    dp[2] = add(k,multiply(k-1,k));
    for(int i=3;i<=n;i++){
        dp[i] = add(multiply(k-1,dp[i-1]),multiply(k-1,dp[i-2]));
    }
    return dp[n];
}

int paintOpt(int n, int k){
    if(n==1){
        return k;
    }
    int a = k;
    int b = add(k,multiply(k-1,k));
    int temp;
    for(int i=3;i<=n;i++){
        temp = add(multiply(k-1,b),multiply(k-1,a));
        a = b;
        b = temp;
    }
    return b;
}

//int paint(int n, int k)

int main(){
    int n,k;
    cin >> n >> k;
    cout << paint(n,k) << endl;
    return 0;
}