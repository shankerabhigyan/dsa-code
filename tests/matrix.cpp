#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &v){
    // include rows not containing -1 in any column
    vector<vector<int>> ans;
    for(int i=0;i<v.size();i++){
        bool flag = true;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==-1){
                flag = false;
                break;
            }
        }
        if(flag) ans.push_back(v[i]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    vector<vector<int>> ans = solve(v);
    cout << endl << "Rows not containing -1 : " << endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}