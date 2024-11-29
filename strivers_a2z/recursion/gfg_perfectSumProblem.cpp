#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recurse(int temp, int i, vector<int>&arr, int &target, int &ans){
        if(temp==target) ans++; return;
        if(i==arr.size() || temp>target) return;

        recurse(temp + arr[i], i+1, arr, target, ans);
        recurse(temp, i+1, arr, target, ans);
        return;
    }
    int perfectSum(vector<int>& arr, int target) {
        int temp = 0;  
        int ans=0;
        recurse(temp, 0, arr, target, ans);
        return ans;
    }
};

int main(){

    return 0;
}