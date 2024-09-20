#include<bits/stdc++.h>
using namespace std;

int sqrt(int A){
    if(A==0 || A==1) return A;
    int left = 1;
    int right = A;
    int ans = 0;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(mid*mid == A) return mid;
        if(mid*mid > A) right = mid-1;
        else{
            ans = mid;
            left = mid+1;
        } 
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << sqrt(n) << endl;
    return 0;
}