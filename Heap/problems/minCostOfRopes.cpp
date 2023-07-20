// There are given N ropes of different lengths, we need to connect these ropes into one rope.
// The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
// Given N size array arr[] contains the lengths of the ropes. 
#include<bits/stdc++.h>
using namespace std;

#define ll long long

void MinHeapify(ll arr[], ll i, ll n){
    ll left = 2*i + 1;
    ll right = 2*i + 2;
    ll minimum = i;
    if(left<n && arr[left]<arr[minimum]){
        minimum = left;
    }
    if(right<n && arr[right]<arr[minimum]){
        minimum = right;
    }
    if(minimum!=i){
        swap(arr[minimum],arr[i]);
        MinHeapify(arr,minimum,n);
    }
}

void printarr(ll arr[],ll n){
    for(ll i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

ll minCost(ll arr[], ll n){
    if(n==1){
        return 0;
    }
    for(ll i=n/2-1;i>=0;i--){
        MinHeapify(arr,i,n);
    }
    stack<ll> s;
    while(arr[0]!=LONG_LONG_MAX){
        ll el = arr[0];
        arr[0] = LONG_LONG_MAX;
        MinHeapify(arr,0,n);
        if(arr[0]==LONG_LONG_MAX){
            break;
        }
        el += arr[0];
        arr[0] = el;
        MinHeapify(arr,0,n);
        s.push(el);
        //cout << s.top()<< endl;
        printarr(arr,n);
    }
    ll cost = 0;
    while(!s.empty()){
        cost+=s.top();
        s.pop();
    }
    return cost;
}

int main(){
    ll arr[] = {4,3,2,6};
    ll n = 4;
    cout << minCost(arr, n) << endl;
    return 0;
}