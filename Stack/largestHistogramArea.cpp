// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Largest Rectangle in Histogram
#include<bits/stdc++.h>
using namespace std;

int sublargestRectangleArea(vector<int> v){ // brute force
    stack<int> s;
    int area = 0;
    bool flag = true;
    for(int i=0;i<v.size();i++){
        int x = v[i];
        int j=i+1;
        int count=1;
        while(j<v.size()){
            if(v[j]>x){
                count++;
                j++;
                flag = false;
            }
            else if(v[j]==x){
                count++;
                j++;
            }
            else{
                flag = false;
                break;
            }
        }
        j=i-1;
        while(j>=0){
            if(v[j]>x){
                count++;
                j--;
                flag = false;
            }
            else if(v[j]==x){
                count++;
                j--;
            }
            else{
                flag = false;
                break;
            }
        }
        area = max(area,count*x);
        if(flag){ 
            return area;
        }
        
    }
    return area;
}

vector<int> nextSmaller(vector<int>v, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr = v[i];
        while(s.top()!=-1 && v[s.top()] >=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


vector<int> prevSmaller(vector<int>v, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int curr = v[i];
        while(s.top()!=-1 && v[s.top()] >=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int optLargestRectangularArea(vector<int>v){
    stack<int>s;
    int area=INT_MIN;
    int len = v.size();
    vector<int> n(len);
    n = nextSmaller(v,len);

    vector<int> p(n);
    p = prevSmaller(v,len);

    for(int i=0; i<len; i++){
        if(n[i]==-1){
            n[i] = len;
        }
        int a = v[i];
        int b = n[i] - p[i] - 1;
        area = max(area, a*b);
    }
    return area;

}

int main(){
    vector<int> heights;
    int n,x;
    cin >> n;
    while(n>0){
        cin >> x;
        heights.push_back(x);
        n--;
    }

    cout << optLargestRectangularArea(heights) << endl;

    return 0;
}