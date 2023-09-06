// https://leetcode.com/problems/partition-equal-subset-sum/
#include<bits/stdc++.h>
using namespace std;

int sum(vector<int>&argh){
    int sum = 0;
    for(int i=0;i<argh.size();i++){
        sum += argh[i];
    }
    return sum;
}

bool solveMemo(vector<int>&argh,int s,int index,vector<vector<int>> &dp){
    if(s==0){
        return true;
    }
    if(index>=argh.size()){
        return false;
    }
    if(dp[index][s]!=-1){
        return dp[index][s];
    }
    if(s>=argh[index]){
        return dp[index][s] = solveMemo(argh,s-argh[index],index+1,dp) || solveMemo(argh,s,index+1,dp);
    }
    return dp[index][s] = solveMemo(argh,s,index+1,dp);
}

bool canPartition(vector<int>&argh){
    int s = sum(argh);
    if(s%2!=0){ // if sum is odd, then it can't be partitioned into two equal subsets
        return false;
    }
    vector<vector<int>> dp(argh.size(),vector<int>(s+1,-1));
    return solveMemo(argh,s/2,0,dp);
}

bool canPartitionTab(vector<int>&argh){
    int s = sum(argh);
    if(s%2!=0){ // if sum is odd, then it can't be partitioned into two equal subsets
        return false;
    }
    s = s/2;
    vector<vector<bool>> dp(argh.size()+1,vector<bool>(s+1,false));
    for(int i=0;i<=argh.size();i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=argh.size();i++){
        for(int j=1;j<=s;j++){
            if(j>=argh[i-1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-argh[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[argh.size()][s];
}

int main(){
    int n;
    cin >> n;
    vector<int>argh(n,0);
    for(int i=0;i<n;i++){
        cin >> argh[i];
    }
    cout << canPartition(argh) << endl;
    return 0;
}