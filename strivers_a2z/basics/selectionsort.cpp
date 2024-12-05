#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        if(n<=1) return;

        for(int i=0;i<n-1;i++){
            int minimum = i;
            for(int j=i;j<n;j++){
                if(arr[j]<arr[minimum]){
                    minimum = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minimum];
            arr[minimum] = temp;
        }
    }
};