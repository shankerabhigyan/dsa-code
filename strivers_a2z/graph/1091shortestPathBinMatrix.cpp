// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         // src = 0,0 | end = n-1,n-1
//         int n = grid.size();
//         if(grid[0][0]) return -1;
//         priority_queue< pair<int, pair<int,int>>, vector< pair<int, pair<int,int>>>, greater< pair<int, pair<int,int>>>>pq;
//         // {distance from src, {x,y}}
//         vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
//         pq.push({1,{0,0}});
//         while(!pq.empty()){
//             auto top = pq.top();
//             pq.pop();
//             int dist = top.first;
//             int x = top.second.first;
//             int y = top.second.second;
//             distance[x][y] = min(distance[x][y],dist);
//             if(x+1<n && grid[x+1][y]==0){
//                 if(dist+1<distance[x+1][y]){
//                     pq.push({dist+1,{x+1,y}});
//                 }
//             }
//             if(y+1<n && grid[x][y+1]==0){
//                 if(dist+1<distance[x][y+1]){
//                     pq.push({dist+1,{x,y+1}});
//                 }
//             }
//             if(x+1<n && y+1<n && grid[x+1][y+1]==0){
//                 if(dist+1<distance[x+1][y+1]){
//                     pq.push({dist+1,{x+1,y+1}});
//                 }
//             }
//             if(x>0 && grid[x-1][y]==0){
//                 if(dist+1<distance[x-1][y]){
//                     pq.push({dist+1,{x-1,y}});
//                 }
//             }
//             if(y>0 && grid[x][y-1]==0){
//                 if(dist+1<distance[x][y-1]){
//                     pq.push({dist+1,{x,y-1}});
//                 }
//             }
//             if(x>0 && y>0 && grid[x-1][y-1]==0){
//                 if(dist+1<distance[x-1][y-1]){
//                     pq.push({dist+1,{x-1,y-1}});
//                 }
//             }
//             if(x>0 && y+1<n && grid[x-1][y+1]==0){
//                 if(dist+1<distance[x-1][y+1]){
//                     pq.push({dist+1,{x-1,y+1}});
//                 }
//             }
//             if(x+1<n && y>0 && grid[x+1][y-1]==0){
//                 if(dist+1<distance[x+1][y-1]){
//                     pq.push({dist+1,{x+1,y-1}});
//                 }
//             }
//         }
//         return distance[n-1][n-1]==INT_MAX? -1:distance[n-1][n-1];
//     }
// };

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (n == 0 || grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
        
        //also serves as visited array
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        
        priority_queue<pair<int, pair<int,int>>, 
                      vector<pair<int, pair<int,int>>>, 
                      greater<pair<int, pair<int,int>>>> pq;
        
        pq.push({1, {0, 0}});
        distance[0][0] = 1;
        
        while (!pq.empty()) {
            auto [dist, coord] = pq.top();
            auto [x, y] = coord;
            pq.pop();
            
            // Early exit if we reached target
            if (x == n-1 && y == n-1) return dist;
            
            // If we found a longer path to this cell, skip
            if (dist > distance[x][y]) continue;
            
            // Check all 8 directions
            for (int i = 0; i < 8; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && 
                    grid[newX][newY] == 0 && dist + 1 < distance[newX][newY]) {
                    distance[newX][newY] = dist + 1;
                    pq.push({dist + 1, {newX, newY}});  
                }
            }
        }
        
        return -1;
    }
};

int main(){
    int n;
    cout << "Enter the size of the grid: ";
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the grid elements (0 or 1):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.shortestPathBinaryMatrix(grid);
    cout << "The shortest path length is: " << result << endl;

    return 0;
}