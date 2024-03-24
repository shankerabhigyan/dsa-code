#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>&nums, int n, int k){
    unordered_map<int, int> mp;
    vector<int> ans;
    mp[nums[0]] = 0;
    for(int i=1;i<n;i++){
        if(mp.find(k-nums[i])!=mp.end()){
            ans.push_back(mp[k-nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]] = i;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;
    vector<int> ans = twoSum(nums,n, k);
    for(int i=0; i<2; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}