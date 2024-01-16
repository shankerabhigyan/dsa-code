#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&vec){
    priority_queue<int,vector<int>,greater<int>> pq;
    int size = 0;
    for(auto x:vec){
        for(auto i:x){
            pq.push(i);
            size++;
        }
    }
    vector<int> ans(size);
    for(int i=0;i<size;i++){
        ans[i] = pq.top();
        pq.pop();
    }
    return ans;
}

vector<int> mergeKSortedArraysOpt(vector<vector<int>> &vec, int k){ // Complexity: O(nlog(k)) time, since we are using a min heap of size k
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i=0;i<k;i++){
        pq.push({vec[i][0],i});
        vec[i].erase(vec[i].begin());
    }

    vector<int> ans;

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        int temp = p.second;
        if(vec[temp].size()>0){
            pq.push({vec[temp][0],temp});
            vec[temp].erase(vec[temp].begin());
        }
    }
    return ans;
}

int main(){
    int k;
    cin >> k;
    vector<vector<int>> vec(k);
    for(int i=0;i<k;i++){
        int t;
        cin >> t;
        for(int j=0;j<t;j++){
            int x;
            cin >> x;
            vec[i].push_back(x);
        }
    }
    return 0;
}