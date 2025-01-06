#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid){
        int temp_k=0;
        int temp_m;
        for(int &b:bloomDay){
            if(mid>=b){
                temp_k++;
            }
            else{
                temp_k=0;
            }
            if(temp_k==k){
                temp_m++;
                temp_k=0;
            }
        }
        return temp_m>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k>bloomDay.size()) return -1; // not possible
        int s=bloomDay[0],e=bloomDay[0];
        int n = bloomDay.size();
        for(int i=0;i<n;i++){
            s = min(s,bloomDay[i]);
            e = max(e,bloomDay[i]);
        }
        while(s<=e){
            int mid = s + (e-s)/2;
            bool verdict = isPossible(bloomDay, m, k, mid);
            if(verdict){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};

int main(){
    return 0;
}