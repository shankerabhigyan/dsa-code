// https://leetcode.com/problems/kth-missing-positive-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0,e=arr.size()-1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(arr[m]-m-1<k) s=m+1;
            else e=m-1;
        }
        return e+1+k;
    }
};

int main(){
    return 0;
}