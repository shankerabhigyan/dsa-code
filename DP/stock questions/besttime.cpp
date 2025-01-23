// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&prices){
    int n = prices.size();
    int bid = INT_MAX;
    int returns = 0;
    for(int i=1;i<n;i++){
        bid = min(bid,prices[i-1]);
        returns = max(returns,prices[i]-bid);
    }
    return returns;
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(auto p:prices){
        cin >> p;
    }
    cout << maxProfit(prices) << endl;
    return 0;
}