#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = grumpy.size();
    int baseSum = 0;
    for (int i = 0; i < n; i++) {
      if (!grumpy[i]) baseSum += customers[i];
    }
    int temp = 0;
    for (int i = 0; i < minutes; i++) {
      if (grumpy[i]) temp += customers[i];
    }

    int optim = temp;
    for (int r = minutes; r < n; r++) {
      int l = r - minutes;         
      if (grumpy[r]) temp += customers[r];
      if (grumpy[l]) temp -= customers[l];
      optim = max(optim, temp);
    }
    return baseSum + optim;
  }
};