#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(vector<int>&arr, int i, int j){
        arr[i] = arr[i]+arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
    }
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        if(n<=1) return;

        for(int i=0;i<n;i++){
            int j = i;
            while(j>0 && arr[j-1]>arr[j]){
                swap(arr,j-1,j);
                j--;
            }
        }    
    }
};