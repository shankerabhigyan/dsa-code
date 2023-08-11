#include<bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent, int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node] = findParent(parent,parent[node]); // path compression
}

void unionSet(vector<int> &parent, vector<int> &rank, int a, int b){
    a = findParent(parent,a);
    b = findParent(parent,b);
    if(rank[a]<rank[b]){
        parent[a] = b;
    } 
    else if(rank[a]>rank[b]){
        parent[b] = a;
    } 
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int hasCycle(vector<vector<int>> &edges, int n){
    vector<int> parent(n,0);
    vector<int> rank(n,0);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(auto e:edges){
        int a = e[0];
        int b = e[1];
        int w = e[2];
        if(findParent(parent,a)!=findParent(parent,b)){
            unionSet(parent,rank,a,b);
        }
        else {
            return 1;
        }
    }
    return 0;
}