#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(rows,vector<int>(cols,INT_MAX));
            
    }
};