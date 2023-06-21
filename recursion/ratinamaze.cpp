// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<bits/stdc++.h>
using namespace std;

void pathFinder(vector<string> &ans, vector<vector<int>> maze, int pr, int pc, string temp, vector<vector<int>> visited){
    if(pr==maze.size()-2 && pc==maze[0].size()-2){
        ans.push_back(temp);
        return;
    }

    if(pr<0 || pc<0 || pr>=maze.size()-1 || pc>=maze[0].size()-1 || maze[pr][pc]==0){
        return;
    }


    visited[pr][pc]=1;
    //cout << "pr: " << pr << " pc: " << pc << endl;
    if(maze[pr+1][pc]==1 && visited[pr+1][pc]==0){
        temp+="D";
        pathFinder(ans,maze,pr+1,pc,temp,visited);
        temp.pop_back();
    }
    if(maze[pr][pc+1]==1 && visited[pr][pc+1]==0){
        temp+="R";
        pathFinder(ans,maze,pr,pc+1,temp,visited);
        temp.pop_back();
    }
    if(maze[pr-1][pc]==1 && visited[pr-1][pc]==0){
        temp+="U";
        pathFinder(ans,maze,pr-1,pc,temp,visited);
        temp.pop_back();
    }
    if(maze[pr][pc-1]==1 && visited[pr][pc-1]==0){
        temp+="L";
        pathFinder(ans,maze,pr,pc-1,temp,visited);
        temp.pop_back();
    }
}

int main(){
    cout << "Enter rows and columns : ";
    int a,b;
    cin >> a >> b;
    vector<vector<int>> v(a+2,vector<int>(b+2,0));
    cout << "Enter maze elements : ";
    for(int r=1;r<a+1;r++){
        for(int c=1;c<b+1;c++){
            cin >> v[r][c];
        }
    } 
    cout << "<--> Padded Maze <--> " << endl;
    for(int r=0;r<v.size();r++){
        for(int c=0;c<v[0].size();c++){
            cout << v[r][c] << " ";
        }
        cout<<endl;
    } 
    cout << "-------------------" << endl;

    vector<string> ans;
    string temp="";
    vector<vector<int>> visited(a+2,vector<int>(b+2,0)); // initially all are unvisited (0)
    pathFinder(ans,v,1,1,temp,visited);
    
    if(ans.size()==0){
        cout << "No paths found!" << endl;
        return 0;
    }
    
    cout << "Paths are: " << endl;
    for(auto s:ans){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}