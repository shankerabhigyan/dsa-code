#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n+2,INT_MAX);
        vector<int> curr(n+2,INT_MAX);

        for(int i=1;i<=n;i++){
            prev[i] = matrix[n-1][i-1];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=n;j++){
                curr[j] = min(prev[j-1],min(prev[j],prev[j+1])) + matrix[i][j-1]; 
            }
            prev = curr;
        }

        int ans = INT_MAX;
        for(auto el:prev){
            ans = min(el,ans);
        } 
        return ans;
    }
};

int main(){
    return 0;
}