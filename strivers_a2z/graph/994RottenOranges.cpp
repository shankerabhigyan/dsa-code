#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/rotting-oranges/description/

// ROTTEN ORANGES

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int count1 = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
                if(grid[i][j]==1) count1++;
            }   
        }
        int ans = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            int x = p.first.first;
            int y = p.first.second;
            q.pop();
            if(!visited[x][y]){
                visited[x][y] = 1;
                if(grid[x][y]==1) count1--;
                int t = p.second;
                ans = max(ans,t);
                if(x-1>=0 && !visited[x-1][y] && grid[x-1][y]==1){
                    q.push({{x-1,y},t+1});
                }
                if(y-1>=0 && !visited[x][y-1] && grid[x][y-1]==1){
                    q.push({{x,y-1},t+1});
                }
                if(x+1<n && !visited[x+1][y] && grid[x+1][y]==1){
                    q.push({{x+1,y},t+1});
                }
                if(y+1<m &&  !visited[x][y+1] && grid[x][y+1]==1){
                    q.push({{x,y+1},t+1});
                }
            }
        }
        if(count1>0) return -1;
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };
    
    Solution sol;
    int result = sol.orangesRotting(grid);
    cout << result << endl;
    
    return 0;
}