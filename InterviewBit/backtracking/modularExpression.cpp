#include<bits/stdc++.h>
using namespace std;

int mulMod(int a, int b, int mod) {
    long long res = 0;
    a = a % mod;
    while (b > 0) {
        if (b & 1) // If b is odd, add the current a to the result
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1; // Divide b by 2
    }
    return (int) res;
}

int modex(int a, int b, int c) {
    if (b == 0) return 1; // Base case
    if (b % 2 == 0) {
        int half = modex(a, b / 2, c);
        return mulMod(half, half, c); // Use mulMod to avoid overflow
    } else {
        int p1 = (a % c + c) % c; // Ensure p1 is non-negative
        int p2 = modex(a, b - 1, c);
        return mulMod(p1, p2, c); // Use mulMod to avoid overflow
    }
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << modex(a,b,c) << endl;
    return 0;
}