#include<bits/stdc++.h>
using namespace std;

// #facebook

class Solution {
private:
  bool isPalindrome(string& s, int x, int y, bool del){
    if(x>=y) return true;

    if(s[x]!=s[y]){
      if(del)return false;
      else{
        return isPalindrome(s,x+1,y,1) || isPalindrome(s,x,y-1,1);
      }
    }
    else{
      return isPalindrome(s,x+1,y-1,del);
    }
  }
public:
  bool validPalindrome(string s) {
    return isPalindrome(s,0,s.length()-1,0);
  }
};

int main(){
  return 0;
}