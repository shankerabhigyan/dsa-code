#include<bits/stdc++.h>
using namespace std;

int woodCutter(vector<int> &A, int B){
    int low = 0;
    int high = *max_element(A.begin(),A.end());

    while(low<=high){
        int mid = low + (high-low)/2;
        long long woodcut = calculatewoodcut(A,mid);
        if(woodcut==B){
            return mid;
        }
        if(woodcut>=B){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}

long long calculatewoodcut(vector<int>&A, int mid){
    long long total = 0;
    for(int tree:A){
        total += max(0,tree-height);
    }
    return total;
}

int main(){
    int n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int B;
    cin >> B;
    cout << woodCutter(A,B) << endl
    return 0;
}