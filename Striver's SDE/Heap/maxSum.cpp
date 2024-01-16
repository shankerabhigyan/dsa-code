#include<bits/stdc++.h>
using namespace std;

void MaxHeapify(vector<int> &arr, int i, int heapsize){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int maximum = i;

    if(l<heapsize && arr[l]>arr[maximum]){
        maximum = l;
    }
    if(r<heapsize && arr[r]>arr[maximum]){
        maximum = r;
    }

    if(maximum!=i){
        swap(arr[i],arr[maximum]);
        MaxHeapify(arr,maximum,heapsize);
    }
}

vector<int> solve(vector<int> &a, vector<int> &b, int c){
    int as = a.size();
    int bs = b.size();
    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>> pq;
    set<int,int> s;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
}

int main(){
    int as,bs;
    cin >> as >> bs;
    vector<int> a(as);
    vector<int> b(bs);
    
    int c;
    cin >> c;
    vector<int> ans = solve(a,b,c);
}