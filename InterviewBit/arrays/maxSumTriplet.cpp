#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&A){
    int n = A.size();
    int max_sum = 0;
    vector<int> max_suffix(n,0);
    max_suffix[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--){
        max_suffix[i] = max(max_suffix[i+1],A[i]);
    }
    
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    cout << solve(A) << endl;
    return 0;
}