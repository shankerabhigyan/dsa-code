#include<bits/stdc++.h>
using namespace std;

int minimumEditDistanceMem(string &w1, string &w2, int i, int j, vector<vector<int>>&dp){
    if(i==w1.length()){
        return w2.length()-j;
    }
    if(j==w2.length()){
        return w1.length()-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(w1[i]==w2[j]){
        return dp[i][j] = minimumEditDistanceMem(w1,w2,i+1,j+1,dp);
    }
    else{
        int insert = 1 + minimumEditDistanceMem(w1,w2,i,j+1,dp);
        int remove = 1 + minimumEditDistanceMem(w1,w2,i+1,j,dp);
        int replace = 1 + minimumEditDistanceMem(w1,w2,i+1,j+1,dp);
        return dp[i][j] = min(insert,min(remove,replace));
    }
}

int minimumEditDistance(string &w1, string &w2){
    vector<vector<int>> dp(w1.length(),vector<int>(w2.length(),-1));
    return minimumEditDistanceMem(w1,w2,0,0,dp);
}

int main(){
    string w1,w2;
    cin >> w1 >> w2;
    cout << minimumEditDistance(w1,w2) << endl;
    return 0;
}