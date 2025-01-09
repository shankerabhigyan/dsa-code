#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rw = matrix.size();
        int col = matrix[0].size();
        int s = 0;
        int e = rw*col - 1;
        while(s<=e){
            int m = s + (e-s)/2;
            int mr = m/col;
            int mc = m%col;
            if(matrix[mr][mc]==target) return true;
            if(matrix[mr][mc]<target) s=m+1;
            else e=m-1;
        }
        return false;
    }
};

int main(){
    return 0;
}