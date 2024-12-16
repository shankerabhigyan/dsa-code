#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isEdge(int &i, int &j, int &m, int &n){
        if(i==0 || j==0 || i==m-1 || j==n-1) return true;
        return false;
    }

    void dfs(vector<vector<char>> &board, pair<int,int> p, vector<vector<bool>> &visited){
        int i = p.first;
        int j = p.second;
        if(visited[i][j]) return;
        visited[i][j]=true;
        if(i>0 && board[i-1][j]=='O'){
            dfs(board,{i-1,j},visited);
        }
        if(j>0 && board[i][j-1]=='O'){
            dfs(board,{i,j-1},visited);
        }
        if(i+1<board.size() && board[i+1][j]=='O'){
            dfs(board,{i+1,j},visited);
        }
        if(j+1<board[0].size() && board[i][j+1]=='O'){
            dfs(board,{i,j+1},visited);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> v;
        vector<pair<int,int>> os;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    visited[i][j]=false;
                    os.push_back({i,j});
                    if(isEdge(i,j,m,n)) v.push_back({i,j});
                }
            }
        }
        for(auto p:v){
            if(!visited[p.first][p.second]) dfs(board,p,visited);
        }

        for(auto p:os){
            if(!visited[p.first][p.second]) board[p.first][p.second]='X';
        }
    }
};


int main(){
    return 0;
}