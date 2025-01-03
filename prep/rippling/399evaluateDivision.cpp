// https://leetcode.com/problems/evaluate-division/description/
// https://www.youtube.com/watch?v=Uei1fwDoyKk

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dfs(string curr, string end, unordered_map<string,unordered_map<string,double>> &graph, unordered_set<string>&vis){
        if(graph.find(curr)==graph.end()) return -1.0;
        if(curr==end) return 1.0;

        vis.insert(curr);

        for(auto &[next,value]:graph[curr]){
            if(vis.find(next)==vis.end()){
                double result = dfs(next,end,graph,vis);
                if(result!=-1) return value*result;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;

        for(int i=0;i<values.size();i++){
            string ch1 = equations[i][0];
            string ch2 = equations[i][1];
            double value = values[i];
            graph[ch1][ch2] = value;
            graph[ch2][ch1] = 1.0/value;
        }
        
        vector<double> results;
        for(const auto& query:queries){
            string start = query[0];
            string end = query[1];

            unordered_set<string> vis;
            double result = dfs(start,end,graph,vis);
            results.push_back(result);
        }
        return results;
    }
};

int main(){
    return 0;
}