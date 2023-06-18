#include<bits/stdc++.h>
using namespace std;

char* reverseString(char* ch, int n){
    if(n==1){
        char* ch1 = new char[1];
        ch1[0] = ch[0];
        return ch1; 
    }
    char* ch1 = new char[n];
    ch1[n-1] = ch[0];
    char* ch2 = reverseString(ch+1,n-1);
    for(int i=0;i<n-1;i++){
        ch1[i] = ch2[i];
    }
    return ch1;
    
}

int main(){
    int n;
    cout << "Enter size of string : ";
    cin >> n;
    char* ch = new char[n];
    cout << "Enter string : ";
    cin >> ch;

    cout << "Reversed string : ";
    cout << reverseString(ch,n) << endl;

    return 0;
}