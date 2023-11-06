#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> place(vector<vector<int>> map, int i, int j, int &n){
    map[i][j] = 1;

    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(x==i || y==j){
                map[x][y] = 1;
            }
            else if((x-y)==(i-j)){
                map[x][y] = 1;
            }
            else if((x+y)==(i+j)){
                map[x][y] = 1;
            }
        }
    }
    return map;
}

void solve(vector<vector<int>> map, vector<vector<string>> &ans, vector<string> temp, int i, int &n){
    if(i==n){
        ans.push_back(temp);
        return;
    }

    for(int j=0;j<n;j++){
        if(map[i][j]==1) continue;

        // placing @ i,j
        vector<vector<int>> newmap = place(map,i,j,n);
        string s="";
        for(int t=0;t<n;t++){
            s+=".";
        }
        s[j]='Q';
        temp.push_back(s);
        solve(newmap,ans,temp,i+1,n);
        temp.pop_back();
    }
}

vector<vector<string>> NQueens(int n){
    vector<vector<int>> map(n,vector<int>(n,0));
    vector<vector<string>> ans;
    vector<string> temp;
    solve(map,ans,temp,0,n);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<string>> ans = NQueens(n);
    for(auto v:ans){
        for(auto s:v){
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}