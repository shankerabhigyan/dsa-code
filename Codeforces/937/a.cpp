// https://codeforces.com/contest/1950/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a<b && b<c){
            cout<<"STAIR";
        }
        else if(a<b && b>c){
            cout << "PEAK";
        }
        else{
            cout << "NONE";
        }
        cout << endl;
    }
    return 0;
}