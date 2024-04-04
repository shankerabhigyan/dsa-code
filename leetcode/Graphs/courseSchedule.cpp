// https://leetcode.com/problems/course-schedule/description/
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> getAdjList(vector<vector<int>> edges){
    unordered_map<int,vector<int>> adjList;
    for(auto edge:edges){
        adjList[edge[0]].push_back(edge[1]);
    }
    return adjList;
}

class Solution{
    public:
    unordered_map<int,vector<int>> getAdjList(vector<vector<int>> edges){
        unordered_map<int,vector<int>> adjList;
        for(auto edge:edges){
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
        if(prerequisites.size()==0){
            return true;
        }
        unordered_map<int,vector<int>> adjList = getAdjList(prerequisites); 
        unordered_map<int,bool> visited(numCourses,false);
        queue<int> q;
        q.push(0);
        for(int i=0;i<numCourses;i++){
            while(!q.empty()){
                
            }
        }
    }
};


int main(){
    return 0;
}