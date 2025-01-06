// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& weights, int m, int days){
        int temp = 0;
        int n = weights.size();
        int i=0;
        for(int i=0;i<n;i++){
            temp+=weights[i];
            if(temp>m){
                days--;
                i--;
                temp=0;
            }
            if(days==0) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=1,e=accumulate(weights.begin(),weights.end(),0);
        while(s<=e){
            int m = s + (e-s)/2;
            bool res = isPossible(weights,m,days);
            if(res)e=m-1;
            else s=m+1;
        }
        return s;
    }
};

int main(){
    return 0;
}