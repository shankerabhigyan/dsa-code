#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int m, int n){
    if(i>=m || j>=n){
        return false;
    }
    return true;
}

void addToGraph(int i, int j, vector<vector<int>> &adj, vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    if(isValid(i+1,j,m,n) && grid[i+1][j]!=0){
        adj[n*i + j].push_back(n*(i+1) + j);
        adj[n*(i+1) + j].push_back(n*i + j);
    }
    if(isValid(i,j+1,m,n) && grid[i][j+1]!=0){
        adj[n*i + j].push_back(n*(i) + j+1);
        adj[n*(i) + j+1].push_back(n*i + j);
    }
}

void print2DVector(vector<vector<int>> &v){
    for(auto x:v){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }
}

void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int orangesRotting(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> adj(m*n);
    vector<int> visited(m*n,0);
    queue<int> rotten;
    int oranges = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                continue; // no need to add to graph
            }
            oranges++;
            addToGraph(i,j,adj,grid);
            if(grid[i][j]==2){
                rotten.push(n*i + j);
                visited[n*i + j] = 1;
            }
        }
    }
    if(rotten.empty()){
        if(oranges==0){
            return 0;
        }
        return -1;
    }
    // bfs - queue per pass - 1 minute passes
    int count=0, minutes=0;
    while(!rotten.empty()){
        int s = rotten.size();
        printQueue(rotten);
        count+=s;
        for(int i=0;i<s;i++){
            int front = rotten.front();
            rotten.pop();
            for(int x:adj[front]){
                if(!visited[x]){
                    visited[x] = 1;
                    rotten.push(x);
                }
            }
        }
        minutes++;
    }
    if(count == oranges){
        return minutes-1;
    }
    return -1;
}

int orangesRottingStriver(vector<vector<int>> &grid){
    
}

int main(){
    vector<vector<int>> grid1 = {{0,2,2}};
    cout << orangesRotting(grid1) << endl;
    return 0;
}

