#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        int a,b,c;
        a = arr[n-1][0];
        b = arr[n-1][1];
        c = arr[n-1][2];
        for(int i=n-2;i>=0;i--){
            int maxbc = max(b,c);
            int maxac = max(a,c);
            int maxba = max(b,a);
            a = arr[i][0] + maxbc;
            b = arr[i][1] + maxac;
            c = arr[i][2] + maxba;
        }
        return max(a,max(b,c));
    }
};


int main(){
    return 0;
}