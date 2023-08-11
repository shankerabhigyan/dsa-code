// https://www.codingninjas.com/studio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

#include<bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent, int node){ // O(1)
    if(parent[node]==node){
        return node;
    }
    return parent[node] = findParent(parent,parent[node]); // path compression
}

void unionSet(vector<int> &parent, vector<int> &rank, int a, int b){ // O(1)
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

int kruskalsMST(vector<vector<int> &edges, int n){ // O(nlogn)
    vector<int> parent(n,0);
    vector<int> rank(n,0);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    sort(edges.begin(),edges.end(),[](vector<int> &a, vector<int> &b){ // O(nlogn)
        return a[2]<b[2];
    }); // sort edges by weight
    int ans = 0;
    int v = 0;
    for(auto e:edges){
        int a = e[0];
        int b = e[1];
        int w = e[2];
        if(findParent(parent,a)!=findParent(parent,b)){
            unionSet(parent,rank,a,b);
            ans += w;
            v++;
        }
        if(v==n-1){
            break;
        }
    }
    return ans;
}