#include<bits/stdc++.h>
using namespace std;

int minLightsToActivate(vector<int> &V, int b){
    int n = V.size();
    int lastlit = -1;
    int curr = 0;
    int ans = 0;

    while(lastlit<n-1){
        bool found = false;
        int best_light = -1;
        for(int i=max(0,curr-b+1);i<=min(n-1,curr+b-1);i++){
            if(V[i]==1 && i+b-1>lastlit){
                best_light = i;
            }
        }

        if(best_light==-1) return -1;
        else{
            ans++;
            lastlit = best_light + b -1;
            curr = lastlit+1;
        }
    }
    return ans;
}

int main(){
    int n,b;
    cin >> n >> b;
    vector<int> V(n);
    for(int i=0;i<n;i++){
        cin >> V[i];
    }
    cout << minLightsToActivate(V,b) << endl;
    return 0;
}