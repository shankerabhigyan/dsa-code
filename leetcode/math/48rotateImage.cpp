#include<bits/stdc++.h>
using namespace std;

#define FOR(i, j, a, b) for(int i = 0; i < a; i++) for(int j = 0; j < b; j++)

void transpose(vector<vector<int>>&mat){
    int n = mat.size();
    FOR(i, j, n, n) {
        if (i < j) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        transpose(mat);
        int n = mat.size();
        FOR(i,j,n,n/2){
            swap(mat[i][j],mat[i][n-j-1]);
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    sol.rotate(matrix);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}