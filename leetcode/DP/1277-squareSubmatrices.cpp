#include<bits/stdc++.h>
using namespace std;

int kernel(int k, vector<vector<int>>& mat){
    int i = mat.size();
    int j = mat[0].size();
    int count = 0;
    for(int x=0;x<=i-k;x++){
        for(int y=0;y<=j-k;y++){
            int sum = 0;
            for(int a=x;a<=x+k-1;a++){
                for(int b=y;b<=y+k-1;b++){
                    sum+=mat[a][b];
                }
            }
            if(sum==k*k){
                count++;
            }
        }
    }
    return count;
}

int countSquares(vector<vector<int>>&mat){
    int i = mat.size();
    int j = mat[0].size();
    int count = 0;
    for(int k=1;k<=min(i,j);k++){
        count+=kernel(k, mat);
    }
    return count;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    cout << countSquares(mat) << endl;
    return 0;
}