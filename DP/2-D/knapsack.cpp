#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://www.youtube.com/watch?v=xdPv2SZJLVI&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=121&ab_channel=CodeHelp-byBabbar

// recursive solution
int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
    if(index==0){
        if(weight[index]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    int include = 0;
    if(weight[index]<=capacity){
        include = value[index] + solve(weight,value,index-1,capacity-weight[index]);
    }
    int exclude = solve(weight,value,index-1,capacity);
    int ans = max(include,exclude);
    return ans;
}

// memoization
int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
    if(index==0){
        if(weight[index]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }
    int include = 0;
    if(weight[index]<=capacity){
        include = value[index] + solveMem(weight,value,index-1,capacity-weight[index],dp);
    }
    int exclude = solveMem(weight,value,index-1,capacity,dp);
    dp[index][capacity] = max(include,exclude);
    return dp[index][capacity]; 
}

// Tabulation
int solveTab(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    int capacity = maxWeight;
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=capacity;w++){
            int include = 0;
            if(weight[i]<=w){
                include = value[i] + dp[i-1][w-weight[i]];
            }
            int exclude = dp[i-1][w];
            dp[i][w] = max(include,exclude);
        }
    }
    return dp[n-1][capacity];
}

// space optimisation
int solveOpt(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<int> curr(maxWeight+1,0);
    vector<int> prev(maxWeight+1,0);
    int capacity = maxWeight;
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            prev[w] = value[0];
        }
        else{
            prev[w] = 0;
        }
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=capacity;w++){
            int include = 0;
            if(weight[i]<=w){
                include = value[i] + prev[w-weight[i]];
            }
            int exclude = prev[w];
            curr[w] = max(include,exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}

// further optimisation
int solveOpt2(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<int> curr(maxWeight+1,0);
    int capacity = maxWeight;
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            curr[w] = value[0];
        }
        else{
            curr[w] = 0;
        }
    }
    for(int i=1;i<n;i++){
        for(int w=capacity;w>=0;w--){
            int include = 0;
            if(weight[i]<=w){
                include = value[i] + curr[w-weight[i]];
            }
            int exclude = curr[w];
            curr[w] = max(include,exclude);
        }
    }
    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    int ans = solveMem(weight,value,n-1,maxWeight,dp);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> weight(n,0);
    vector<int> value(n,0);
    for(int i=0;i<n;i++){
        cin >> weight[i];
    }
    for(int i=0;i<n;i++){
        cin >> value[i];
    }
    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weight,value,n,maxWeight) << endl;
    return 0;
}