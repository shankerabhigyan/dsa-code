// https://leetcode.com/problems/pascals-triangle/description/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows){
    vector<vector<int>> ans;
    for(int i=1;i<=numRows;i++){
        vector<int>temp;
        if(i==1){
            temp.push_back(1);
        }
        else if(i==2){
            temp.push_back(1);
            temp.push_back(1);
        }
        else{
            temp.push_back(1);
            for(int j=1;j<i-1;j++){
                temp.push_back(ans[i-2][j-1]+ans[i-2][j]);
            }
            temp.push_back(1);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    int numRows=5;
    vector<vector<int>> ans = generate(numRows);
    return 0;
}