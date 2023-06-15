#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, int f=0, int s=1){
    if(n == 1){
        return f;
    }
    return fibonacci(n-1, s, f+s); 
}

int main(){
    int n;
    cin >> n;
    int digit = fibonacci(n);
    cout << "The " << n << "th fibonacci number is " << digit << endl;
    return 0;
}