#include<bits/stdc++.h>
using namespace std;

int solve(int x, int&m, int&k){
    if(x<m) return 0;
    else{
        int h = (x-k)/2;
        return 1 + solve(h,m,k) + solve(x-k-h,m,k);
    }
}

int compute(string s, int n, int m, int k){
    vector<pair<int,int>> p;
    int i=0;
    while(i<n){
        if(s[i]=='1') i++;
        else{
            int x = 0;
            while(s[i]=='0' && i<n){
                i++;
                x+=1;
            }
            if(x>=m){
                p.push_back(x);
            }
        }
    }
    int ans = 0;
    for(int x:p){
        ans+=solve(x,m,k);
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        cout << compute(s,n,m,k) << endl;
    }
    return 0;
}