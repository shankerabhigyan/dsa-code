#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B){
    if(A.size()==1) return A[0]<=B?1:0;
    if(B<A[0]) return 0;
    if(B>A[A.size()-1]) return A.size();
    int left = 0;
    int right = A.size()-1;
    while(left<right){
        int mid = left + (right-left)/2;
        if(A[mid]==B){
            while(mid<A.size()-1 && A[mid]==B){
                mid++;
            }
            return mid+1;
        }
        if(A[mid]>B && A[mid-1]<=B){
            return mid;
        }
        if(A[mid+1]>B && A[mid]<=B){
            return mid+1;
        }
        if(A[mid]>B){
            // our point of interest lies to the left
            right = mid-1;
        }
        if(A[mid]<B){
            // vice versa
            left = mid+1;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    int B;
    cin >> B;
    cout << solve(A) << endl;
    return 0;
}