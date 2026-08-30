// https://leetcode.com/problems/string-compression/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int compress(vector<char>& chars) {
    int i=0, len=chars.size();
    while(i<len-1){
      j=i;
      while(chars[j+1]==chars[j]){
        j++;
      }
      if(j>i){
        char c = static_cast<char>(j-i+1);
        chars[i+1] = c;
        
      }
      else{

      }
    }
  }
};