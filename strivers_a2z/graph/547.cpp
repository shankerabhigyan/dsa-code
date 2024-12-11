#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>&visited, int i){
        visited[i] = 1;
        int size = isConnected.size();
        for(int x=0;x<size;x++){
            if(isConnected[i][x] && !visited[x]){
                dfs(isConnected, visited, x);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int num = 0, i=0;
        int size = isConnected.size();
        vector<int> visited(size,0);
        while(i<size){
            if(visited[i]) i++;
            else {
                dfs(isConnected, visited, i);
                num++;
            }
        }
        return num;
    }
};