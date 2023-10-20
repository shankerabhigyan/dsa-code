#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum/

void combSum(vector<int>&v, int target, int i, vector<int> temp, vector<vector<int>>&ans){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(target<0){
        return;
    }

    for(int k=i;k<v.size();k++){
        if(v[k]<=target){
            temp.push_back(v[k]);
            combSum(v,target-v[k],k,temp,ans);
            temp.pop_back();
        }
    }
}

vector<vector<int>> getCombinationSum(vector<int>&candidates, int target){
    vector<int> temp;
    vector<vector<int>> ans;
    combSum(candidates,target,0,temp,ans);
    return ans;
}