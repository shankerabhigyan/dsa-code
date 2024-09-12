#include<bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/rotated-array/

int findMin(const vector<int>&A){
    int n = A.size();
    int s = 0;
    int e = n-1;
    
    if(A[s]<=A[e]) return A[s];

    while(s<e){
        int mid = s + (e-s)/2;
        if(A[mid]>A[mid+1]){
            return A[mid+1];
        }
        if(A[mid]<A[mid-1]){
            return A[mid];
        }
        if(A[s]<A[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return A[s];
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    cout << findMin(A) << endl;
}