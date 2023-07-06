// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// find first negative integer in a window of size k
#include<bits/stdc++.h>
using namespace std;

vector<long long> firstNegativeInteger(long long int a[], long long int n,long long int k){
    deque<long long int> dq;
    vector<long long> ans;
    
    for(int i=0;i<k;i++){
        if(a[i]<0){
            dq.push_back(i);
        }
    }
    if(dq.size()>0){
        ans.push_back(a[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    for(int i=k;i<n;i++){
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        if(a[i]<0){
            dq.push_back(i);
        }

        if(dq.size()>0){
            ans.push_back(a[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main(){
    long long int n, k;
    cin >> n >> k;
    long long int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<long long> ans = firstNegativeInteger(a,n,k);
    
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}