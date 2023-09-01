// https://leetcode.com/problems/reducing-dishes/
#include<bits/stdc++.h>
using namespace std;

int solve(priority_queue<int,vector<int>,greater<int>> pq, int time){ // memory limit exceeds
    if(pq.size()==0){
        return 0;
    }
    int top = pq.top();
    pq.pop();
    int include = time * top + solve(pq,time+1);
    int exclude = solve(pq,time);
    return max(include,exclude);
}

int solve2(vector<int> &satisfaction, int i, int time,vector<vector<int>>&dp){
    if(i==satisfaction.size()){
        return 0;
    }
    if(dp[i][time]!=INT_MIN){
        return dp[i][time];
    }
    int include = time*satisfaction[i] + solve2(satisfaction,i+1,time+1,dp);
    int exclude = solve2(satisfaction,i+1,time,dp);
    return dp[i][time] = max(include,exclude);
}

int maxSatisfaction(vector<int> satisfaction){ 
    sort(satisfaction.begin(),satisfaction.end());
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MIN));
    return solve2(satisfaction,0,1,dp);
}

int maxSatisfactionTab(vector<int> &satisfaction){// TC & SC = O(n^2)
    int n = satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int time=i;time>=0;time--){
            int include = dp[i+1][time+1] + (time+1)*satisfaction[i];
            int exclude = dp[i+1][time];
            dp[i][time] = max(include,exclude);
        }
    }
    return dp[0][0];
}

int maxSatisfactionOpt(vector<int> &satisfaction){
    int n = satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    vector<int> next(n+1,0);
    vector<int> curr(n+1,0);
    for(int i=n-1;i>=0;i--){
        for(int time=i;time>=0;time--){
            int include = next[time+1] + satisfaction[i]*time+1;
            int exclude = next[time];
            curr[time] = max(include,exclude);
        }
        next = curr;
    }
    return next[0];
}

//  todo : implement further space optimisation similar to 0/1 knapsack

int main(){
    int n;
    cin >> n;
    vector<int> satisfaction(n);
    for(int i=0;i<n;i++){
        cin >> satisfaction[i];
    }
    cout << maxSatisfaction(satisfaction) << endl;
    return 0;
}