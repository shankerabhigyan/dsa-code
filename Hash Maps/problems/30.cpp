#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

  void find(string &s, unordered_map<string,int>&hash, vector<int>&ans, int i, int &len, int &x){
    if(i>=s.length()){
      if(hash.empty()) ans.push_back(i-x*len);
      return;
    }

    string word = s.substr(i,len);

    if(hash[word]){
      if(hash[word]==1){
       hash.erase(word);
       find(s,hash,ans,i+len,len,x);
       hash.insert({word,1});
      }
      else{
        hash[word]-=1;
        find(s,hash,ans,i+len,len,x);
        hash[word]+=1;
      }
    }

    find(s,hash,ans,i+1,len,x);

  }

  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string,int>hash;
    for(auto &w:words){
      if(!hash[w]) hash.insert({w,0});
      hash[w] = hash[w] + 1;
    }
    int len = words[0].length();
    int x = words.size();
    vector<int> ans;
    find(s,hash,ans,0,len,x);
    return ans;
  }
};