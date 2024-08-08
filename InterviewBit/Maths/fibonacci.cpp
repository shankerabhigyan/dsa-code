#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<vector<int>> matmul(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> result(2,vector<int>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                result[i][j] = (result[i][j] + 1LL * a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return result;
}

vector<vector<int>> SolveMatrix(vector<vector<int>> base, int exp){
    vector<vector<int>> result = {{1,0},{0,1}};
    while(exp>0){
        if(exp%2==1){
            result = matmul(result,base);
        }
        base = matmul(base,base);
        exp/=2;
    }
    return result;
}

int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    vector<vector<int>> base = {{1,1},{1,0}};
    vector<vector<int>> result = SolveMatrix(base,n-1);
    return result[0][0];   
}

int main(){
    return 0;
}