#include<bits/stdc++.h>
using namespace std;

string firstHalfSmallestPalindrome(string A){
    int size = A.size();
    bool all9s = true;
    for(int i=0; i<size; i++){
        if(A[i] != '9'){
            all9s = false;
            break;
        }
    }
    if(all9s){
        return "1" + string(size-1, '0') + "1";
    }
    string firstHalf = A.substr(0, (size+1)/2);
    string mirrored =  firstHalf + string(firstHalf.rbegin() + size%2, firstHalf.rend());
    if(mirrored > A){
        return mirrored;
    }

    // if mirrored is smaller than A that means we need to increment the first half
    int i = (size+1)/2 - 1;
    while(i >= 0 && firstHalf[i] == '9'){
        firstHalf[i] = '0';
        i--;
    }
    if(i >= 0){
        firstHalf[i]++;
    }
    else{
        firstHalf = "1" + string(size-1, '0');
    }
    return firstHalf + string(firstHalf.rbegin() + size%2, firstHalf.rend());
}


int main(){
    return 0;
}
