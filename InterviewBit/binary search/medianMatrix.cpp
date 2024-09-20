#include<bits/stdc++.h>
using namespace std;

int getIndex(vector<int>&v, int x){
    int left = 0;
    int right = v.size()-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(x==v[mid]) return mid;
        if(x>v[mid]) {
            left = mid + 1; 
        }
        else{
            right = mid - 1; 
        }
    }
    return left;
}

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int findMedian(vector<vector<int>> &A){
    int r = A.size();
    int c = A[0].size();
    int medianIndex = (r * c) / 2;
    
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < r; i++) {
        minVal = std::min(minVal, A[i][0]);
        maxVal = std::max(maxVal, A[i][c-1]);
    }
    
    while (minVal <= maxVal) {
        int midVal = minVal + (maxVal - minVal) / 2;
        int count = 0;
        
        for (int i = 0; i < r; i++) {
            count += std::upper_bound(A[i].begin(), A[i].end(), midVal) - A[i].begin();
        }
        
        if (count <= medianIndex) {
            minVal = midVal + 1;
        } else {
            maxVal = midVal - 1;
        }
    }
    
    return minVal;
}

int main(){
    int r, c;
    cout << "Enter the number of rows: ";
    cin >> r;
    cout << "Enter the number of columns: ";
    cin >> c;

    vector<vector<int>> matrix(r, vector<int>(c));
    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    int median = findMedian(matrix);
    cout << "The median of the matrix is: " << median << endl;
    return 0;
}
