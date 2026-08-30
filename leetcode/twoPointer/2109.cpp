// https://leetcode.com/problems/adding-spaces-to-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string addSpaces(string s, vector<int>& spaces) {
    int len = s.size(), x=0, i=0, ss=spaces.size();
    string news="";
    while(x<len){
      if(i<ss && x==spaces[i]){
        news += " ";
        i++;
      }
      else{
        news += s[x];
        x++;
      }
    }
    return news;
  }
};