#include<bits/stdc++.h>
using namespace std;

# define MOD 1000000007

int solve(string A){
    if(A.length()==1) return 0;
    int right = A.length() - 1;
    int vowels = 0, consonants = 0;
    static const unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    if(vowel.find(A[right]) != vowel.end()){
        vowels++;
    }
    else{
        consonants++;
    }
    right--;
    int count = 0;
    while(right>=0){
        if(vowel.find(A[right]) != vowel.end()){
            count += consonants;
            vowels++;
        }
        else{
            count += vowels;
            consonants++;
        }
        right--;
    }
    return count%MOD;
}

int main(){
    string s;
    cin >> s;
    cout << solve(s) <<  endl;
    return 0;
}