// https://codeforces.com/contest/1942/problem/A
#include<bits/stdc++.h>
using namespace std;

vector<int> getJohnsAnswer(int n, int k){
    if(n==1){
        return {1};
    }
    else if(n==2){
        if(k==1){
            return {1,2};
        }
        else{
            return {1,1};
        }
    }
    else if(n>2){
        if(k==1){
            vector<int> ans(n);
            for(int i=0; i<n; i++){
                ans[i] = i+1;
            }
            return ans;
        }
        else if(k==n){
            return vector<int>(n, 1);
        }
        else{
            return {};
        }
    }
    return {};
}

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int n,k;
        cin >> n >> k;
        vector<int> ans = getJohnsAnswer(n, k);
        if (ans.size() == 0){
            cout << -1 << endl;
        }
        else{
            for(int i=0; i<ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}