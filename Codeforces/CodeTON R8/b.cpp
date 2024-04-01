#include<bits/stdc++.h>
using namespace std;


vector<int> getPermutation(vector<int> &a){
    int n = a.size();
    vector<int> p(n);
    int x = a[0];
    if(x<0){
        p[0] = -1 * x;
    }
    else{ // x=1
        p[0] = 0;
    }
    p[n-1] = n-a[n-1];
}

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        vector<int> p = getPermutation(a);
    }
    return 0;
}