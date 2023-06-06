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
        if(ch[i]!=ch[len-1-i]){
            pal = false;
            break;
        }
    }
    return pal;
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