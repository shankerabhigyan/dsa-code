#include<bits/stdc++.h>
using namespace std;

bool check(char ch){
    return isalnum(ch);
}

int isPalindrome(string A){
    for(auto &ch : A) ch = tolower(ch);
    if(A.length() == 1) return 1;
    int left = 0;
    int right = A.length()-1;
    while(left<right){
        if(!isalnum(A[left])){
            left++;
            continue;
        }
        if(!isalnum(A[right])){
            right--;
            continue;
        }
        if(A[left]!=A[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main(){
    string A;
    cin >> A;
    cout << isPalindrome(A) << endl;
    return 0;
}