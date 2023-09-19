// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1
#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int n, int k){
    vector<int> ans(2,0);
    sort(candies.begin(),candies.end());
    int i=0;j=n-1;
    while(i<=j){
        ans[0]+=candies[i];
        j=j-k;
        i++;
    }
    i=0;j=n-1;
    while(i<=j){
        ans[1]+=candies[j];
        i+=k;
        j--;
    }
    return ans;
}