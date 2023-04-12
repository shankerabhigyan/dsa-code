//find out the largest prime factor of a x
#include <iostream>
using namespace std;

int isPrime(int n){
    bool isPrime = 1;
    // from 2 to square root of n
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

int PrimeFactors(int n){
    //create linked list ll of prime factors of n
    //ll = new LinkedList();

    // from 2 to square root of n
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            if (isPrime(i)){
                cout << i << endl;
            }
        }
    }
    return true;
}

int main(){
    int n=0;
    cin >> n;
    cout<< isPrime(n) << endl;
    /*if (isPrime(n)){
        cout << n << endl;
    }
    PrimeFactors(n); */
    return 0;
}