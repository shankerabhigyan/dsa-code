#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        stack<pair<int,int>> st;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    ans++;
                    if(i==0 || i==m-1 || j==0 || j==n-1) st.push({i,j});
                }
            }
        }

        while(!st.empty()){
            pair<int,int> p = st.top();
            st.pop();
            int x = p.first;
            int y = p.second;
            if(!visited[x][y]){
                visited[x][y] = true;
                ans--;
                if(x>0 && grid[x-1][y]) st.push({x-1,y});
                if(y>0 && grid[x][y-1]) st.push({x,y-1});
                if(x+1<m && grid[x+1][y]) st.push({x+1,y});
                if(y+1<n && grid[x][y+1]) st.push({x,y+1});
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}