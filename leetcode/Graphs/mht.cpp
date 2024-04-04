#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges){
        if(n==0){
            return {};
        }
        if(n==1){
            return {0};
        }
        vector<int> degrees(n, 0);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(vector<int> edge : edges){
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degrees[i]==1){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.clear();
            for(int i=0;i<q.size();i++){
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(int neighbor : adj[curr]){
                    degrees[neighbor]--;
                    if(degrees[neighbor]==1){
                        q.push(neighbor);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    int n,m;
    cin>>n;
    cin>>m;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    
    Solution obj;
    vector<int> ans = obj.findMinHeightTrees(n, edges);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}