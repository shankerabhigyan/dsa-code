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

void backtrack(vector<int> &V, vector<int> v, int i, vector<vector<int>> &ans){
    if(i==V.size()){
        ans.push_back(v);
    }
    else{
        backtrack(V,v,i+1,ans);
        v.push_back(V[i]);
        backtrack(V,v,i+1,ans);
    }
}

vector<vector<int>> subsets(vector<int> &V){
    vector<vector<int>> ans;
    backtrack(V,{},0,ans);
    return ans;
}

vector<vector<int>> bitmasking(vector<int> &V){
    int n = V.size();
    vector<vector<int>> ans;
    for (int mask = 0; mask < (1<<n); mask++) {
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            if (mask & (1<<i))
                temp.push_back(V[i]);
        }
        sort(temp.begin(), temp.end());
        ans.push_back(temp);
    }
    // sort(ans.begin(), ans.end());
    return ans; 
}

int main(){
    int n;
    cin >> n;
    vector<int> V(n);
    for(int i=0;i<n;i++){
        cin >> V[i];
    }
    vector<vector<int>> ans = bitmasking(V);
    printVector(ans);
    return 0;
}