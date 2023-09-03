#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

int maxSumOfStack(vector<vector<int>> &cuboids){
    int n = cuboids.size();
    for(int i=0;i<n;i++){
        sort(cuboids[i].begin(),cuboids[i].end());
    }
    sort(cuboids.begin(),cuboids.end(),[](vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            if(a[1]==b[1]){
                return a[2]>b[2];
            }
            return a[1]>b[1];
        }
        return a[0]>b[0];
    });
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        dp[i] = cuboids[i][2];
    }
    for(int i=1;i<n;i++){ // LIS of height
        for(int j=0;j<i;j++){
            if(cuboids[j][0]>=cuboids[i][0] && cuboids[j][1]>=cuboids[i][1] && cuboids[j][2]>=cuboids[i][2]){
                dp[i] = max(dp[i],dp[j]+cuboids[i][2]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}

int main(){
    return 0;
}