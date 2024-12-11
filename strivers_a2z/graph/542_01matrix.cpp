#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) q.push({{i,j},0});
            }
        }

        vector<vector<int>> visited(n,vector<int>(m,0));

        while(!q.empty()){
            int xc = q.front().first.first;
            int yc = q.front().first.second;
            int d = q.front().second;
            q.pop();
            if(!visited[xc][yc]){
                visited[xc][yc] = 1;
                mat[xc][yc] = d;
                if(xc-1>=0 && mat[xc-1][yc]==1){
                    q.push({{xc-1,yc},d+1});
                }
                if(xc+1<n && mat[xc+1][yc]==1){
                    q.push({{xc+1,yc},d+1});
                }
                if(yc-1>=0 && mat[xc][yc-1]==1){
                    q.push({{xc,yc-1},d+1});
                }
                if(yc+1<m && mat[xc][yc+1]==1){
                    q.push({{xc,yc+1},d+1});
                }
            }
        }
        return mat;
    }
};

int main(){
    return 0;
}