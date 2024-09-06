#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<char>> &v, unordered_map<int,vector<bool>> &game, int i, int j, bool &flag){
    if(i==9){
        cout << "l1" << endl;
        flag = true;
        return;
    }
    if(j==9 && i<9){
        cout << "l2" << endl;
        backtrack(v,game,i+1,0, flag);
        return;
    }
    if(v[i][j]=='.'){
        cout << " l3" << endl;
        for(int k=0;k<9;k++){
            if(!game[i][k] && !game[j+9][k] && !game[3*(i/3)+(j/3)+100][k]){
                v[i][j] = '1'+k;
                game[i][k] = true;
                game[j+9][k] = true;
                game[3*(i/3) + (j/3)+100][k] = true;
                backtrack(v,game,i,j+1,flag);
                if(flag) return;
                game[i][k] = false;
                game[j+9][k] = false;
                game[3*(i/3) +(j/3)+ 100][k] = false;
                v[i][j] = '.';
            }
        }
        return;
    }
    backtrack(v,game,i,j+1,flag);
    return;
}

void solveSudoku(vector<vector<char>> &v){
    unordered_map<int,vector<bool>> game;
    for(int i=0;i<18;i++){
        game[i] = vector<bool>(9,false);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            game[3*(i/3) + (j/3) + 100] = vector<bool>(9,false);
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(v[i][j]!='.'){
                game[i][(int)(v[i][j])-1] = true;
                game[j+9][(int)(v[i][j])-1] = true;
                game[3*(i/3) + (j/3) + 100][(int)(v[i][j])-1] = true;
            }
        }
    }
    bool flag = false;
    backtrack(v,game,0,0,flag);
}

int main(){
    int n = 9;
    vector<vector<char>> v(n,vector<char>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    solveSudoku(v);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}