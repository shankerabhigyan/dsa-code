#include<bits/stdc++.h>
using namespace std;

int power(int a, int b){
    // BASE CASE
    //assert (b>=0);
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    // ******
    // RECURSION RELATION
    int x = power(a,b/2);
    if(b%2==0){
        return x * x ;
    }
    if(b%2==1){
        return x * x * a ;
    }
    return 0;
}

int main(){
    int a,b;
    cout<< "Enter base and power : ";
    cin >> a >> b;
    cout << a << "^" << b <<  " = " << power(a,b) << endl;

}