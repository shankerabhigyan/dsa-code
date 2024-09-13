#include<bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int>> &A, int B){
    int n = A.size();
    int m = A[0].size();
    int start = 0;
    int end = n*m - 1;
    while(start<=end){
        int mid = start + (end-start)/2;
        int i = mid/m;
        int j = mid%m;
        int el = A[i][j];
        if(B==el){
            return 1;
        }
        if(B>el){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return 0;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> A(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }
    int B;
    cin >> B;
    cout << searchMatrix(A,B) << endl;
    return 0;
}