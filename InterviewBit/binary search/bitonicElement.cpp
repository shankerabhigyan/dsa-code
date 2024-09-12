#include<bits/stdc++.h>
using namespace std;

int findInBitonic(std::vector<int>& A, int B) {
    int n = A.size();
    
    // Find the peak element
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] > A[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    int peak = left;
    
    // Binary search in the increasing part
    left = 0;
    right = peak;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == B) return mid;
        if (A[mid] < B) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // Binary search in the decreasing part
    left = peak;
    right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == B) return mid;
        if (A[mid] > B) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Element not found
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int B;
    cin >> B;

    cout << findInBiotonic(A,B) << endl;

    return 0;
}