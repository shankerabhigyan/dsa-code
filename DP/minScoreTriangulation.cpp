#include<bits/stdc++.h>
using namespace std;

int getminScoreTriangulation(vector<int> &vertices, int i, int j){ // plain recursion
    if(i+1>=j){
        return 0;
    }
    int ans = INT_MAX;
    for(int k=i+1;k<j;k++){
        ans = min(ans,getminScoreTriangulation(vertices,i,k)+getminScoreTriangulation(vertices,k,j)+(vertices[i]*vertices[j]*vertices[k]) );
    }
    return ans;
}

// memoization
int getminScoreTriangulationMem(vector<int>&vertices, int i, int j, vector<vector<int>> &dp){
    if(i+1>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans  = INT_MAX;
    for(int k=i+1;k<j;k++){
        ans = min(ans, vertices[i]*vertices[j]*vertices[k] + getminScoreTriangulationMem(vertices,i,k,dp) + getminScoreTriangulationMem(vertices,k,j,dp));
    }
    return dp[i][j] = ans;
}

int minScoreTriangulation(vector<int> &vertices){
    int n = vertices.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int ans = getminScoreTriangulationMem(vertices,0,n-1,dp);
    return ans;
}

int minScoreTriangulationTab(vector<int> &vertices){
    int n = vertices.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i+2;j<n;j++){
            int ans = INT_MAX;
            for(int k=i+1;k<j;k++){
                ans = min(ans, dp[i][k]+dp[k][j]+(vertices[i]*vertices[j]*vertices[k]));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}

int main(){
    vector<int> vertices;
    int x;
    cin >> x;
    while(x!=-1){
        vertices.push_back(x);
        cin >> x;
    }
    cout << minScoreTriangulationTab(vertices) << endl;
    return 0;
}