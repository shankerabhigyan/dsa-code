#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/nth-fibonacci-number_74156?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// top down approach
int fib1(int n, vector<int> &dp){ // TC:O(n) | SC:O(n)
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    
    dp[n] = fib1(n-1,dp) + fib1(n-2,dp);
    return dp[n];
}

// bottom up approach
int fib2(int n){ // TC:O(n) | SC:O(1)
    vector<int> dp(n+1,-1);
    dp[1] = 1;
    dp[0] = 0;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// space optimisation
int fib3(int n){ // TC:O(n) | SC:O(1)
    if(n==0){
        return n;
    }
    int prev1 = 0;
    int prev2 = 1;
    int curr;
    for(int i=2;i<=n;i++){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

int fibonacci(int n){
    vector<int> dp(n+1,-1);
    //return fib1(n,dp);
    //return fib2(n);
    return fib3(n);
}


int main(){
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;;
    return 0;
}