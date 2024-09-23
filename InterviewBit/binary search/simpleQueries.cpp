#include<bits/stdc++.h>
using namespace std;


const int MOD = 1e9 + 7;

void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int productOfDivisors(int n) {
    long long product = 1;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            product = (product * i) % MOD;
            if (i != n / i) {
                product = (product * (n / i)) % MOD;
            }
        }
    }
    return product%MOD;
}

void fillArray(vector<int>& arr, vector<int>& A, int start, int idx, int currentMax) {
    if (idx == A.size()) {
        return;
    }
    
    currentMax = max(currentMax, A[idx]);
    arr.push_back(currentMax);
    fillArray(arr, A, start, idx + 1, currentMax);
}

void findAllSubarraysMax(vector<int>& arr, vector<int>& A) {
    for (int start = 0; start < A.size(); ++start) {
        fillArray(arr, A, start, start, INT_MIN);
    }
}

vector<int> solve(vector<int> &A, vector<int>&B) {
    vector<int> arr;
    findAllSubarraysMax(arr, A);

    vector<int> modifiedArr(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        modifiedArr[i] = productOfDivisors(arr[i]);
    }
    sort(modifiedArr.begin(), modifiedArr.end(), [](int a, int b) {
        return a > b;
    });
    vector<int> ans;
    for(auto x:B){
        ans.push_back(modifiedArr[x-1]);
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the number of elements in vector A: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of vector A: ";
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int m;
    cout << "Enter the number of elements in vector B: ";
    cin >> m;

    vector<int> B(m);
    cout << "Enter the elements of vector B: ";
    for(int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    vector<int> ans = solve(A, B);
    printVector(ans);
    return 0;
}