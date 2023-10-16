#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&v, vector<vector<int>> &ans, vector<int> temp, int i){
    ans.push_back(temp);
    for(int id = i;id<v.size();id++){
        if(i!=id && v[id]==v[id-1]) continue;
        temp.push_back(v[id]);
        solve(v,ans,temp,id+1);
        temp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> v){
    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    vector<int> temp;
    solve(v,ans,temp,0);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<vector<int>> power = subsets(v);
    return 0;
}