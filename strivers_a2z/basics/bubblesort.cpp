#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(vector<int>&arr, int i, int j){
        arr[i] = arr[i]+arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
    }
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        if(n<=1) return;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<i;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr,j,j+1);
                }
            }
        }
    }
};