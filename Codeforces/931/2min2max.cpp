/*
Given an array a of n elements, find the maximum value of the expression:

|ai−aj|+|aj−ak|+|ak−al|+|al−ai|
where i, j, k, and l are four distinct indices of the array a, with 1≤i,j,k,l≤n.

Here |x| denotes the absolute value of x.
*/

#include<bits/stdc++.h>
using namespace std;

int getMaximum(vector<int>a){
    sort(a.begin(),a.end());
    pair<int,int> p1 = {a[0],a[1]};
    pair<int,int> p2 = {a[a.size()-2],a[a.size()-1]};
    return abs(p1.first-p2.first)+abs(p2.first-p1.second)+abs(p1.second-p2.second)+abs(p2.second-p1.first);
}

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << getMaximum(a) << endl;
    }
    return 0;
}