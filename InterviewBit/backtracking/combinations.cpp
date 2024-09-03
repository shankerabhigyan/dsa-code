#include<bits/stdc++.h>
using namespace std;
void printVector(const vector<vector<int>>& vec) {
    for (auto innerVec : vec) {
        for (int num : innerVec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void backtrack(int i, vector<int> v, int &n, int &k, vector<vector<int>> &ans){
    if(i>n || v.size()==k){
        if(v.size()==k){
            ans.push_back(v);
        }
        return;
    }
    else{
        v.push_back(i);
        backtrack(i+1,v,n,k,ans);
        v.pop_back();
        backtrack(i+1,v,n,k,ans);
    }
}

vector<vector<int>> combine(int n ,int k){
    vector<vector<int>> ans;
    backtrack(1,{},n,k,ans);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> comb = combine(n,k);
    printVector(comb);
    return 0;
}