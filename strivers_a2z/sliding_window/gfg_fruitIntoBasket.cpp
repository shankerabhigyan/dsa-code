#include<bits/stdc++.h>
using namespace std;

class Solution{ // passed
    public:
    int totalFruits(vector<int>&arr){
        int n = arr.size();
        if(n<=2) return n;
        int l=0,r=0;
        while(arr[r]==arr[l] && r<n){
            r++;
        }
        pair<int,int> p = {arr[l],arr[r]};
        int maxi = r-l+1;
        while(r<n){
            if(arr[r]==p.first || arr[r]==p.second){
                maxi = max(maxi,r-l+1);
                pos[arr[r]] = r;
            }
            else{
                l = r-1;
                int x = arr[l];
                while(arr[l]==x){
                    l--;
                }
                l = l+1;
                p = {arr[l],arr[r]};
            }
            r++;
        }
        return maxi;
    }
};

class Solution2{
    public:
    int totalFruits(vector<int>&arr){
        int n = arr.size();
        int l=0, r=0, maxlen = 0;
        map<int,int> window;
        while(r<n){
            window[arr[r]]++;
            if(window.size()>2){
                l++;
                if(--window[arr[l]]==0) window.erase(arr[l]);
            }
            else{
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    vector<int> fruits(n);
    for(int i = 0; i < n; i++) {
        cin >> fruits[i];
    }
    cout <<  sol.totalFruits(fruits) << endl;

    return 0;
}