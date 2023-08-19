// https://www.codingninjas.com/studio/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

int cutrod(int n, int &x, int &y, int &z, vector<int> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int a=INT_MIN,b=INT_MIN,c=INT_MIN;
    if(n>=x) a = cutrod(n-x,x,y,z,dp);
    if(n>=y) b = cutrod(n-y,x,y,z,dp);
    if(n>=z) c = cutrod(n-z,x,y,z,dp);
    return dp[n] = 1+max(a,max(b,c));
}

int maxSegments(int n, int &x, int &y, int &z){
    vector<int> dp(n+1,-1);
    int ans = cutrod(n,x,y,z,dp);
    if(ans<0) return 0;
    return ans;
}

int main(){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    cout << maxSegments(n,x,y,z)<<endl;
    return 0;
}