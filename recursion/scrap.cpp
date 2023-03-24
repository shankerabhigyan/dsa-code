#include<iostream>
using namespace std;

int factorial(int n){
    //basecase
    if (n == 0){
        return 1;
    }
    //recursive case
    int x = factorial(n-1);
    return n * x;
}

int main(){
    int n;
    cin >> n;

    int answer = factorial(n);
    cout << answer << endl;
    return 0;
}