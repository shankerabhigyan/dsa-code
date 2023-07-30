#include<bits/stdc++.h>
using namespace std;

template <typename T>

class graph{
    public:
    unordered_map<T, list<T>> adj;

    void insert(T x, T y, bool directed){
        adj[x].push_back(y);

        if(!directed){
            adj[y].push_back(x);
        }
    }

    void display(){ 
        for(auto x:adj){
            cout << x.first << " -> ";
            for(int y:x.second){
                cout << y << " ";          
            }
            cout << endl;
        }
    }
};

int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    graph<int> g;

    bool directed;
    cout << "Is the graph directed? (yes:1/ no:0): ";
    cin >> directed;

    cout << "Enter number of edges: ";
    int e;
    cin >> e;
    cout << "Enter edges: ";
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        g.insert(x,y,directed);
    }

    g.display();

    return 0;
}