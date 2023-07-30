// https://www.codingninjas.com/studio/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

bool checkBoard(map<int,int> fd, map<int,int> bd, map<int,int> col, int i, int j, int n){
    if(fd[i+j] == 1 || bd[n-1+i-j] == 1 || col[j] == 1){
        return false;
    }
    return true;
}

void traverse(int row, int n, vector<int> p, vector<vector<int>> &ans, map<int,int> fd, map<int,int> bd, map<int,int> col){
    if(row == n){
        ans.push_back(p);
    }
    for(int c=0;c<n;c++){
        if(checkBoard(fd,bd,col,row,c,n)){
            //cout << row << " " << c << endl;
            p.push_back(c);
            fd[row+c] = 1;
            bd[n-1+row-c] = 1;
            col[c] = 1;
            traverse(row+1,n,p,ans,fd,bd,col);
            p.pop_back();
            fd[row+c] = 0;
            bd[n-1+row-c] = 0;
            col[c] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> ans;
    vector<int> p;
    map<int,int> fd;
    map<int,int> bd;
    map<int,int> col;
    traverse(0,n,p,ans,fd,bd,col);
    // a vector inside ans represents the position of queen in each row
    vector<vector<int>> res;
    int size = n*n;
    for(auto x:ans){
        vector<int> temp(size,0);
        int f = 0;
        for(auto y:x){
            temp[f*n+y] = 1;
            f++;
        }
        res.push_back(temp);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v = nQueens(n);
    for(auto x:v){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}