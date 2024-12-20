#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    int diff(vector<vector<int>>& heights, int &x, int &y, int &X, int &Y){
        return abs(heights[x][y]-heights[X][Y]);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(rows,vector<int>(cols,INT_MAX));
        
        pq.push({0,{0,0}});
        effort[0][0]=0;
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!pq.empty()){
            auto [eff, coord] = pq.top();
            auto [x,y] = coord;
            pq.pop();
            for(int i=0;i<4;i++){
                int X = x + dx[i];
                int Y = y + dy[i];
                if(X>=0 && Y>=0 && X<rows && Y<cols && max(eff,diff(heights,x,y,X,Y))<effort[X][Y]){
                    pq.push({max(eff,diff(heights,x,y,X,Y)),{X,Y}});
                    effort[X][Y] = max(eff,diff(heights,x,y,X,Y));
                }
            }

        }
        return effort[rows-1][cols-1];
    }
};