#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void reverseString(vector<char>& s) {
    int x=0, y=s.size()-1;
    while(x<y){
      char t = s[x];
      s[x] = s[y];
      s[y]=t;
      x++;
      y--;
    }
  }
};

int main(){
  return 0;
}