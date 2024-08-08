#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int m, int n){
    if(i>=m || j>=n || i<0 || j<0){
        return false;
    }
    return true;
}

void addToGraph(int i, int j, vector<vector<int>> &adj, vector<vector<int>> &grid, int centerColor){
    int m = grid.size();
    int n = grid[0].size();
    if(isValid(i+1,j,m,n) && grid[i+1][j]==centerColor){
        adj[n*i + j].push_back(n*(i+1) + j);
        adj[n*(i+1) + j].push_back(n*i + j);
    }
    if(isValid(i,j+1,m,n) && grid[i][j+1]==centerColor){
        adj[n*i + j].push_back(n*(i) + j+1);
        adj[n*(i) + j+1].push_back(n*i + j);
    }
    if(isValid(i-1,j,m,n) && grid[i-1][j]==centerColor){
        adj[n*i + j].push_back(n*(i-1) + j);
        adj[n*(i-1) + j].push_back(n*i + j);
    }
    if(isValid(i,j-1,m,n) && grid[i][j-1]==centerColor){
        adj[n*i + j].push_back(n*(i) + j-1);
        adj[n*(i) + j-1].push_back(n*i + j);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int m = image.size();
    int n = image[0].size();
    int centerColor = image[sr][sc];
    vector<vector<int>> adj(m*n);
    if(color == centerColor){
        return image;
    }
    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            if(image[i][j] == centerColor){
                addToGraph(i,j,adj,image, centerColor);
            }
        }   
    }
   vector<int> visited(m*n, 0);
   queue<int> q;
   q.push(n*sr + sc);
   visited[n*sr + sc] = 1;
   while(!q.empty()){
        int front = q.front();
        q.pop();
        image[front/n][front%n] = color;
        for(int x:adj[front]){
            if(!visited[x]){
                q.push(x);
                visited[x] = 1;
            }
        }
   }
   return image;
}

// optimised solution
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int centercolor = image[sr][sc];
    if(centercolor == color){
        return image;
    }
    vector<int>visited(image.size()*image[0].size(),0);
    dfs(image, sr, sc, color, centercolor, visited);
    return image;
}

void dfs(vector<vector<int>> &image, int i, int j, int &color, int &centercolor, vector<int>&visited){
    if(i>=image.size() || j>=image[0].size() || i<0 || j<0 || image[i][j]!=centercolor || visited[image[0].size()*i+j]){
        return;
    }
    image[i][j] = color;
    visited[image[0].size()*i+j] = 1;

    dfs(image,i+1,j,color,centercolor, visited);
    dfs(image,i,j+1,color,centercolor, visited);
    dfs(image,i-1,j,color,centercolor, visited);
    dfs(image,i,j-1,color,centercolor, visited);
}

void print2DVector(vector<vector<int>> &v){
    for(auto x:v){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> ans = floodFill(image,sr,sc,color);
    print2DVector(ans);
    return 0;
}