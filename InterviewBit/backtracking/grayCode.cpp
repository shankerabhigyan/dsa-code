#include<bits/stdc++.h>
using namespace std;

vector<int> generateGrayCode(int n) {
    int totalCodes = 1 << n;
    vector<int> grayCodes;
    
    for (int i = 0; i < totalCodes; ++i) {
        grayCodes.push_back(i ^ (i >> 1));
    }
    
    return grayCodes;
}

void printGrayCodes(const vector<int>& codes) {
    cout << "[";
    for (size_t i = 0; i < codes.size(); ++i) {
        cout << codes[i];
        if (i != codes.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int n;
    cout << "Enter the number of bits for Gray codes: ";
    cin >> n;

    if (n < 1 || n > 16) {
        cout << "Number of bits must be between 1 and 16." << endl;
        return 1;
    }

    vector<int> grayCodes = generateGrayCode(n);
    printGrayCodes(grayCodes);

    return 0;
}
