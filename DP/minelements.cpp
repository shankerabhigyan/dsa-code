#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

int solve(vector<int> &num, int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(auto n:num){
        int ans = solve(num,x-n);
        if(ans!=INT_MAX){
            mini = min(mini, ans+1);
        }
    }
    return mini;
}

int minimumElements2(vector<int> &num, int x){
    int ans = solve(num,x);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}

int minimumElements(vector<int> &num, int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(auto n:num){
            if(i-n>=0 && dp[i-n]!=INT_MAX){
                dp[i] = min(dp[i],1+dp[i-n]);
            }
        }
    }
    if(dp[x]==INT_MAX){
        return -1;
    }
    return dp[x];
}

int main(){
    vector<int> num;
    int x;
    cin >> x;
    while(x!=-1){
        num.push_back(x);
        cin >> x;
    }
    cin >> x;
    cout << minimumElements(num,x)<<endl;
    return 0;
}