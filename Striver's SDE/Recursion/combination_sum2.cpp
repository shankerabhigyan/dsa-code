#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/

void combSum(vector<int>&v, int target, int i, vector<int> temp, vector<vector<int>>&ans){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(target<0 || i==v.size()){
        return;
    }

    for(int k=i;k<v.size();k++){
        if(k>i && v[k]==v[k-1]) {
            continue;
        }
        temp.push_back(v[k]);
        combSum(v,target-v[k],k+1,temp,ans);
        temp.pop_back();
    }
}

vector<vector<int>> getCombinationSum(vector<int>&candidates, int target){
    vector<int> temp;
    vector<vector<int>> ans;
    sort(candidates.begin(),candidates.end());
    combSum(candidates,target,0,temp,ans);
    return ans;
}