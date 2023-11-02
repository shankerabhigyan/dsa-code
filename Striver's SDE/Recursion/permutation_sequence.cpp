#include<bits/stdc++.h>
using namespace std;

/*
if(n==1){
        ans.push_back(v[0]);
        return;
    }
*/

string permute(int n,int k){
    vector<int> v(n);
    int fact = 1;
    for(int i=1;i<n;i++){
        fact = fact * i;
        v[i-1] = i;cd ..
    }
    v[n-1] = n;
    string ans = "";
    k = k-1;
    while(true){
        int x = k/fact;
        ans = ans + to_string(v[x]);
        v.erase(v.begin()+x);
        if(v.size()==0) break;
        k = k%fact;
        fact = fact/v.size();
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    string ans = permute(n,k);
    cout << ans << endl;
    return 0;
}