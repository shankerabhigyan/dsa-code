#include<bits/stdc++.h>
using namespace std;

#define LI long int
#define VV vector<vector<int>>
#define V vector<int>

int getMinGenerator(VV &graph, LI k, int m){
    
}

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int n,m;
        cin >> n >> m;
        LI k;
        cin >> k;
        vector<vector<int>> graph(m,vector<int>(4));
        for auto vec:graph{
            for(int i=0;i<4;i++){
                cin >> vec[i];
            }
        }
        cout << getMinGenerator(vector<vector<int>> graph, k, m) << endl;
    }
    return 0;
}