#include<bits/stdc++.h>
using namespace std;

void reverseString(char ch[], int len){
    char k=' ';
    for(int i=0;i<len/2;i++){
        k = ch[i];
        ch[i] = ch[len-1-i];
        ch[len-1-i] = k;
    }
    cout << ch << endl;
}

int Length(char ch[]){
    int count=0;
    for(int i=0; ch[i]!='\0'; i++){
        count++;
    }
    return count;
}

bool isPalindrome(vector <char> ch){
    int len = ch.size();
    bool pal = true;
    for(int i=0;i<len/2;i++){
        if(tolower(ch[i]) != tolower(ch[len-1-i])){
            pal = false;
            break;
        }
    }
    // this considers all the characters in the string including special characters like @#$%?^& etc.
    // to skip these, introduce end and start vars and check if they are alphabets or not
    // the following function is for the same, it checks for alphabets only in a sentence/word
    return pal;
}

bool isValidPalindrome(vector <char> ch){
    int s=0, e=ch.size()-1;
    while(s<=e){
        
    }
}

int main(){
    /*char name[20];
    cin >> name;
    //cout << name << endl;
    int len = Length(name);
    reverseString(name, len);*/

    vector<char> v;
    int size;
    
    string s;
    cin>>s;
    char c;
    for(int i=0;i<s.size();i++){
        c = s[i];
        v.push_back(c);
    }
    
    cout << isPalindrome(v) << endl;

    return 0;
}