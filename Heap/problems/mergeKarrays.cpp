// https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays1(vector<vector<int>> &arrs, int k){ // O(nlog(n)) time, O(n) space
    priority_queue<int, vector<int>, greater<int>> h;
    int size=0;
    for(auto x:arrs){
        for(auto i:x){
            h.push(i);
            size++;
        }
    }

    vector<int> v(size);
    for(int i=0;i<size;i--){
        v[i] = h.top();
        h.pop();
    }
    return v;
}

vector<int> mergeKSortedArrays2(vector<vector<int>> &arrs, int k){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> h;
    for(int i=0;i<k;i++){
        h.push({arrs[i][0],i});
        arrs[i].erase(arrs[i].begin());
    }

    vector<int> ans;
    while(!h.empty()){
        int i = h.top().second
        ans.push_back(h.top().first);
        h.pop();
        if(arrs[i].size()>0){
            h.push({arrs[i][0],i});
            arrs[i].erase(arrs[i].begin());
        }
    }
    return ans;
}
// O(nlog(k)) time, O(k) space
// still takes 3ms extra on leetcode than mergeKSortedArrays1 since we are using a pair instead of int which takes more space
// and hence more time to copy

int main(){

}