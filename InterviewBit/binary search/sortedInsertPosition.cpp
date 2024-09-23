#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& A, int x, int left, int right) {
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (A[mid] == x) return mid;
        else if (A[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return mid;
}

int searchInsert(vector<int> &A, int B){
    return binarySearch(A,B,0,A.size()-1);
}