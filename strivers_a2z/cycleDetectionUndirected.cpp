// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
#include<bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> adj[]){
    stack<int> st;
    vector<int> vis(V, 0);
    vector<int> parent(V,-1);
    for(int i=0;i<V;i++){
        if(vis[i]){
            continue;
        }
        else{
            st.push(i);
            vis[i] = 1;
            while(!st.empty()){
                int node = st.top();
                st.pop();
                for(int x:adj[node]){
                    if(!vis[x]){
                        parent[x] = node;
                        st.push(x);
                        vis[x] = 1;
                    }
                    else{
                        if(parent[node]!=x){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}