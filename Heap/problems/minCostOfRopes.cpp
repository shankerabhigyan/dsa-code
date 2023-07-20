// There are given N ropes of different lengths, we need to connect these ropes into one rope.
// The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
// Given N size array arr[] contains the lengths of the ropes. 
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll minCost(ll arr[], ll n){
    for(int i=n/2-1;i>=0;i--){
        MinHeapify(arr,i,n);
    }
    

}

int main(){

    return 0;
}