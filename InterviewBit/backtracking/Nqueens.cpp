#include<bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/nqueens/

vector<vector<int>> markBoard(vector<vector<int>> grid, int i, int j){
    int n = grid[0].size();
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(x+y==i+j){
                grid[x][y]=1;
                continue;
            }
            if(x-y==i-j){
                grid[x][y]=1;
                continue;
            }
            if(y==j){
                grid[x][y]=1;
                continue;
            }
        }
    }
    return grid;
}

void backtrack(vector<vector<int>> grid, int idx, int &n, vector<string> curr,vector<vector<string>> &ans){
    if(idx==n){
        ans.push_back(curr);
    }
    else{
        for(int i=0; i<n; i++){
            if(grid[idx][i]==0){
                string s;
                s += string(i,'.');
                s += "Q";
                s += string(n-i-1,'.');
                curr.push_back(s);
                vector<vector<int>> newGrid = markBoard(grid,idx,i);
                backtrack(newGrid, idx+1, n, curr, ans);
                curr.pop_back();
            }
        }
        return;
    }
}

vector<vector<string>> getnqueens(int n){
    vector<vector<int>> grid(n, vector<int>(n,0));
    vector<vector<string>> ans;
    backtrack(grid,0,n,{},ans);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<string>> nqueens = getnqueens(n);
    for(auto v:nqueens){
        for(string e:v){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}