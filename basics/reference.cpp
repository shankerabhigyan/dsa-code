#include<bits/stdc++.h>
using namespace std;

int main(){
    int i = 10;
    int& ref = i;
    ref++;
    cout << i << endl;  

    return 0;
}