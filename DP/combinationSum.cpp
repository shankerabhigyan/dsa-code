// https://www.codingninjas.com/studio/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &num, int curr, int &tar, int &ways){ // recursive solution
    if(curr>=tar){
        if(curr==tar){
            ways++;
        }
        return;
    }

    for(auto x:num){
        solve(num,curr+x,tar,ways);
    }
    return;
}

/*int findWays(vector<int> &num,int tar){
    int ans;
    solve(num,0,tar,ans);
    return ans;
}*/

int findWaysMem(vector<int> &num,int &tar,int curr, vector<int> &dp){
    if(curr>=tar){
        if(curr==tar){
            return 1;
        }
        return 0;
    }

    if(dp[curr]!=0){
        return dp[curr];
    }

    for(auto x:num){
        dp[curr] += findWaysMem(num,tar,curr+x,dp);
    }
    return dp[curr];
}

int findWays(vector<int> &num, int tar){
    vector<int> dp(tar+1,0);
    int ans = findWaysMem(num,tar,0,dp);
    return ans;
}

int findWaysTab(vector<int> &num, int tar){
    vector<int> dp(tar+1,0);
    dp[0] = 1;
    for(int i=1;i<=tar;i++){
        for(auto n:num){
            if(i-n>=0){
                dp[i] += dp[i-n];
            }
        }
    }
    return dp[tar];
}

int main(){
    int n,tar;
    cin >> n >> tar;
    vector<int> num(n,-1);
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    cout << findWays(num,tar) << endl;
    return 0;
}