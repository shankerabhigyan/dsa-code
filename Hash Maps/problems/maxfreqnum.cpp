// https://www.codingninjas.com/studio/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &arr, int n){
    unordered_map<int,int> m;
    int max = 0;
    int ans;
    for(int i=0;i<n;i++){
        int t = ++m[arr[i]];
        if(t>max){
            max = t;
        }
    }
    for(auto x:arr){
        if(m[x]==max){
            return x;
        }
    }
    return -1;
}

int main(){
    vector<int> v = {1,2,3,1,2,2};

    cout << maxFrequency(v,v.size()) << endl;

    return 0;   
}