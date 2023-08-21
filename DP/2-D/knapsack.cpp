#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// recursive solution, suboptimal, gives TLE
int solve(vector<int> &weight, vector<int> &value, int w, int val, int &n, int &maxWeight,vector<int> visited){
    if(w==maxWeight){
        return val;
    }
    if(w>maxWeight){
        return INT_MIN;
    }
    int ans = INT_MIN;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i] = 1;
            int x = solve(weight,value,w+weight[i],val+value[i],n,maxWeight,visited);
            visited[i] = 0;
            if(x==INT_MIN){
                x = val;
            }
            ans = max(ans,x);
            flag = true;
        }
    }
    if(!flag){ // if all the elements are visited then return the current value
        return val;
    }
    return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<int> visited(n,0);
    int ans = solve(weight,value,0,0,n,maxWeight,visited);
    if(ans==INT_MIN){
        return 0;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> weight(n,0);
    vector<int> value(n,0);
    for(int i=0;i<n;i++){
        cin >> weight[i];
    }
    for(int i=0;i<n;i++){
        cin >> value[i];
    }
    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weight,value,n,maxWeight) << endl;
    return 0;
}