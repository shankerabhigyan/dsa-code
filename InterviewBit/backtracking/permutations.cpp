#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> backtrack(vector<int> V){
    if(V.size()==1){
        return {{V[0]}};
    }
    else{
        vector<vector<int>> ans;
        for(int i=0;i<V.size();i++){
            int x = V[i];
            vector<int> newV = V;
            auto it = find(newV.begin(),newV.end(),x);
            newV.erase(it);
            vector<vector<int>> y = backtrack(newV);
            for(auto v:y){
                v.push_back(x);
                ans.push_back(v);
            }
        }
        return ans;
    }
}

void printVector(const vector<vector<int>>& vec) {
    for (auto innerVec : vec) {
        for (int num : innerVec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> permute(vector<int>&V){
    vector<vector<int>> ans = backtrack(V);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> V(n);
    for(int i=0;i<n;i++){
        cin >> V[i];
    }
    vector<vector<int>> ans = permute(V);
    printVector(ans);
    return 0;
}