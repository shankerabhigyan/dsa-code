// https://www.codingninjas.com/studio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

void traverse(string path, vector<string> &ans, vector<vector<int>> &maze, int i, int j, int n, map<pair<int,int>,bool> m ){
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return;
    }

    if(m[{i,j}]){
        return;
    }

    //cout << path << endl;

    m[{i,j}] = true;

    if(i+1<n && maze[i+1][j]==1){
        traverse(path+'D', ans, maze, i+1, j,n, m);
    }

    if(j-1>=0 && maze[i][j-1]==1){
        traverse(path+'L',ans,maze,i,j-1,n,m);
    }

    if(j+1<n && maze[i][j+1]==1){
        traverse(path+'R',ans,maze,i,j+1,n,m);
    }
    if(i-1>=0 && maze[i-1][j]==1){
        traverse(path+'U', ans, maze, i-1,j,n,m);
    }

}

vector<string> searchMaze(vector<vector<int>> &maze, int n){
    vector<string> ans;
    if(maze[0][0]==0){
        return ans;
    }
    int i=0,j=0;
    map<pair<int,int>,bool> m;
    string path = "";
    traverse(path, ans, maze, i, j, n, m);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> maze;
    //cout << "Enter maze" <<  endl;
    for(int i=0;i<n;i++){
        vector<int> temp;
        int x;
        for(int j=0;j<n;j++){
            cin >> x;
            temp.push_back(x);
        }
        maze.push_back(temp);
    }

    vector<string> ans = searchMaze(maze,n);

    for(auto s:ans){
        cout << s << endl;
    }

    return 0;
}