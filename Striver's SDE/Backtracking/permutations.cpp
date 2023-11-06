#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums ,vector<vector<int>> &p, vector<int> temp, vector<bool> visited){
    if(nums.size()==0){
        p.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i]) continue;
        temp.push_back(nums[i]);
        visited[i] = true;
        solve(nums,p,temp,visited);
        temp.pop_back();
        visited[i]=false;
    }
}

void backtracking(vector<int> nums, int i, vector<vector<int>> &p){
    if(i==nums.size()){
        p.push_back(nums);
        return;
    }

    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        backtracking(nums,i+1,p);
        swap(nums[i],nums[j]);
    }
}

vector<vector<int>> permute(vector<int>&nums){
    vector<vector<int>> p;
    vector<int> temp;
    vector<bool> visited(nums.size(),false);
    solve(nums,p,temp,visited);
    return p;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<vector<int>> p = permute(nums);
    for(auto x:p){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}