#include <bits/stdc++.h>
using namespace std;

int main(){
    int i=7, j=3;
    if(i>>2>j<<2){
        j = j >> 2;
    }
    else{
        i = i << 2;
    }
    cout << i << " " << j << endl;
    return 0;
}