#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#define MOD 1000000007
int countDistinctWays(int n){
    if(n==0 || n==1){
        return 1;
    }
    int p1 = 1;
    int p2 = 2;
    for(int i=3;i<=n;i++){
        int curr = (p1%MOD + p2%MOD)%MOD;
        p1 = p2;
        p2 = curr;
    }
    return p2;
}

int main(){
    int n;
    cin >> n;
    cout << countDistinctWays(n) << endl;
    return 0;
}