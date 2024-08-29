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

void backtrack(const vector<int>& V, int start, vector<int>& current, int target, vector<vector<int>>& results) {
    if (target == 0) {
        results.push_back(current);
        return;
    }

    for (int i = start; i < V.size() && V[i] <= target; i++) {
        current.push_back(V[i]);
        backtrack(V, i, current, target - V[i], results);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& V, int target) {
    vector<vector<int>> results;
    vector<int> current;
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    backtrack(V, 0, current, target, results);
    return results;
}

int main(){
    int n,b;
    cin >> n >> b;
    vector<int> V(n);
    for(int i=0;i<n;i++){
        cin >> V[i];
    }
    vector<vector<int>> ans = combinationSum(V,b);
    printVector(ans);
    return 0;
}