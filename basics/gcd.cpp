// using euclid's algorithm
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int a,b;
    cout << "Enter the two numbers : " << endl;
    cin >> a >> b;
    int ans = gcd(a,b);
    cout << "GCD of " << a << " and " << b << " is : " << ans << endl;
}