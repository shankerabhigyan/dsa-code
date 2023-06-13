// modular exponentiation
// a^b mod m
#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int a, int b, int m){
    int x=1;
    while(b>0){
        if(b&1){ // if b is odd
            res = (1LL * (res) *(a)%m )%m;
        }
        a = (1LL * (a)%m * (a)%m)%m;
        b = b>>1;
    }
    return x;
}

int main(){
    int a,b,m;
    cout << "Enter a, b and m" << endl;
    cin >> a >> b >> m;
}