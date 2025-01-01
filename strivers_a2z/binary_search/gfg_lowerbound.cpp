#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?

class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        int s=0,e=arr.size()-1;
        int ans = -1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(arr[m]==k)return m;
            if(arr[m]<k){
                ans = m;
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}