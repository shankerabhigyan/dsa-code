// https://leetcode.com/problems/koko-eating-bananas/description/

#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool canEat(vector<int>&piles, int m, int h){
//         long ans = 0;
//         for(int &p:piles){
//             ans += (p + m - 1) / m;
//             if(ans > h) return false;
//         }
//         return true;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         long total = 0;
//         int e = INT_MIN;
//         for(auto &p:piles){
//             e = max(e,p);
//             total+=p;
//         }
//         int s = max(1L, (total + h - 1) / h);
//         while(s<=e){
//             int m = s + (e-s)/2;
//             bool ce = canEat(piles,m,h);
//             if(ce){
//                 e = m-1;
//             }
//             else{
//                 s = s+1;
//             }
//         }
//         return s;
//     }
// };

class Solution {
public:
    long long calHours(vector<int> &piles, int k) {
        long long totalHours = 0;
        for (int &p : piles) {
            totalHours += (int)ceil(p / (double)k);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = piles[0];
        for (int &p : piles) high = max(high, p);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (calHours(piles, mid) > (long long)h) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};


int main(){
    Solution sol;
    vector<int> piles = {312884470};
    int h = 312884469;
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}