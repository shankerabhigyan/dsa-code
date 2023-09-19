//  https://leetcode.com/problems/maximal-rectangle/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
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

int largestRectangleArea(vector<int>& v) {
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

int getMaximalRectangle(vector<vector<char>> &matrix){
    int m = matrix[0].size();
    int n = matrix.size();
    vector<int> v(m,0);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='1'){
                v[j]++;
            }
            else{
                v[j] = 0;
            }
        }
        ans = max(ans,largestRectangleArea(v));
    }
    return ans;
}

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<char>> matrix(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> matrix[i][j];
        }
    }

    cout << getMaximalRectangle(matrix) << endl;
    
    return 0;
}