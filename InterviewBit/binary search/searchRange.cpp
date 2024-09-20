#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& A, int x, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == x) return mid;
        else if (A[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

vector<int> searchSubset(const vector<int>& a, int left, int right, int B) {
    if (left > right) return {-1, -1};
    
    int index = binarySearch(a, B, left, right);
    if (index == -1) return {-1, -1};
    
    vector<int> leftResult = searchSubset(a, left, index - 1, B);
    vector<int> rightResult = searchSubset(a, index + 1, right, B);
    
    int newLeft = (leftResult[0] == -1) ? index : leftResult[0];
    int newRight = (rightResult[1] == -1) ? index : rightResult[1];
    
    return {newLeft, newRight};
}

vector<int> searchRange(const vector<int>& A, int B) {
    return searchSubset(A, 0, A.size() - 1, B);
}

int main() {
    int n, B;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cout << "Enter the target value: ";
    cin >> B;

    vector<int> result = searchRange(A, B);
    cout << "Range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}