#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

// brute force B-S
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rw = matrix.size();
        int col = matrix[0].size();
        int k = 0;
        int s=0,e=col-1;
        while(k<rw){
            if(s>e){
                s=0,e=col-1;
                k++;
                continue;
            }
            int m = s + (e-s)/2;
            int mid = matrix[k][m];
            if(mid==target) return true;
            if(mid>target) e=m-1;
            else s=m+1;
        }      
        return false;
    }
};

// optimised

class Solution { // O(n+m)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rw = matrix.size();
        int col = matrix[0].size();
        pair<int,int> m = {0,col-1};
        while(m.first<rw && m.second>=0){
            int curr = matrix[m.first][m.second]; 
            if(curr==target) return true;
            if(target>curr) m.first++;
            else m.second--;
        }
        return false;
    }
};



int main(){
    return 0;
}