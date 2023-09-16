#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&prices, int fee){
    int n = prices.size();
    int cash = 0;
    int hold = -prices[0];
    for(int i=1;i<n;i++){
        cash = max(cash,hold+prices[i]-fee);
        hold = max(hold,cash-prices[i]);
    }
    return cash;
}
// explanation -- 
// here we have 2 states, cash and hold
// cash is the maximum profit we can make if we have no stock in hand
// hold is the maximum profit we can make if we have a stock in hand
// we start with hold = -prices[0] because we have to buy the stock at the first day
// and cash = 0 because we have no stock in hand
// now we iterate over the prices array
// at each day we have 2 options, either we can sell the stock or we can buy the stock
// if we sell the stock, we will get cash = max(cash,hold+prices[i]-fee)
// if we buy the stock, we will get hold = max(hold,cash-prices[i])
// we take the maximum of the two options because we want to maximize our profit
// at the end we return cash because we want to maximize our profit and we can only sell the stock at the last day
// so we return cash