#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        if(n==1) return 0;
        vector<int>dp(n,-1);
        dp[n-1] = 0;
        dp[n-2] = abs(height[n-2]-height[n-1]);
        for(int i=n-3;i>=0;i--){
            dp[i] = min(abs(height[i]-height[i+1])+dp[i+1], abs(height[i]-height[i+2])+dp[i+2]);
        }
        return dp[0];
    }
};

int main(){
    return 0;
}