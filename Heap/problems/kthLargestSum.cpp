// https://www.codingninjas.com/studio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

int kthLargestSum(vector<int> &v, int k){ // O(n^2log(k)) time, O(k) space
    priority_queue<int, vector<int>, greater<int>> h;
    for(int i=0;i<k;i++){
        h.push(INT_MIN);
    }
    int x = 0;
    while(x<v.size()){
        int sum=0;
        for(int i=x;i<v.size();i++){
            sum+=v[i];
            if(sum>h.top()){
                h.pop();
                h.push(sum);
            }
        }
        x++;
    }
    return h.top();
}

int main(){
    vector<int> v = {1,-2,3,-4,5};
    cout << kthLargestSum(v,2) << endl;
    
}