#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> visited(n,vector<int>(m,0));
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            if(!visited[p.first][p.second]){
                int xc = p.first;
                int yc = p.second;
                visited[xc][yc] = 1;
                image[xc][yc] = color;
                if(xc-1>=0 && image[xc-1][yc]==x){
                    q.push({xc-1,yc});
                }
                if(xc+1<n && image[xc+1][yc]==x){
                    q.push({xc+1,yc});
                }
                if(yc-1>=0 && image[xc][yc-1]==x){
                    q.push({xc,yc-1});
                }
                if(yc+1<m && image[xc][yc+1]==x){
                    q.push({xc,yc+1});
                }
            }
        }
        return image;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}