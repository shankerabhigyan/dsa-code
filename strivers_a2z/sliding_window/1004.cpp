#include<bits/stdc++.h>
using namespace std;

class Solution2{
public:
    int longestOnes(vector<int>&nums, int k){
        int l=0,r=0,n=nums.size();
        int temp=k;
        int ans = 0;
        while(r<n){
            if(!nums[r]){
                temp--;
            }
            while(temp<0){
                if(nums[l]==0){
                    temp++;
                }
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

// BEST APPROACH

class Solution{
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0, n = nums.size();
        while(j<n){
            if(nums[j]==0){
                k--;
            }
            if(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            j++;
        }
        return j-i;
    }
};

int main(){
    Solution sol;
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    int result = sol.longestOnes(nums, k);
    cout << result << endl;
    return 0;
}