#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> bestPrice(int n, vector<vector<int>>& price, int k, int q, vector<vector<int>>& queries) {
        unordered_map<int, int> compress;
        vector<int> allPoints;

        // Collect all points that are endpoints in the ranges
        for (auto& p : price) {
            allPoints.push_back(p[0]);
            allPoints.push_back(p[1] + 1); // Consider right end as exclusive
        }
        for (auto& q : queries) {
            allPoints.push_back(q[0]);
            allPoints.push_back(q[1] + 1); // Queries are inclusive, adjust to exclusive
        }

        sort(allPoints.begin(), allPoints.end());
        allPoints.erase(unique(allPoints.begin(), allPoints.end()), allPoints.end());

        int compressIndex = 0;
        for (int point : allPoints) {
            compress[point] = compressIndex++;
        }

        vector<int> frequency(compressIndex, 0);

        // Apply the difference array technique
        for (auto& p : price) {
            int start = compress[p[0]], end = compress[p[1] + 1];
            frequency[start]++;
            if (end < compressIndex) frequency[end]--;
        }

        // Accumulate to get the frequency of suggestions per price
        for (int i = 1; i < compressIndex; ++i) {
            frequency[i] += frequency[i - 1];
        }

        // Use another array to count best prices using the prefix sum technique
        vector<int> bestPrices(compressIndex, 0);
        bestPrices[0] = (frequency[0] >= k) ? 1 : 0;
        for (int i = 1; i < compressIndex; ++i) {
            bestPrices[i] = bestPrices[i - 1] + ((frequency[i] >= k) ? 1 : 0);
        }

        vector<int> results;
        results.reserve(q);
        for (auto& query : queries) {
            int start = compress[query[0]], end = compress[query[1] + 1] - 1;
            results.push_back(bestPrices[end] - (start > 0 ? bestPrices[start - 1] : 0));
        }

        return results;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<vector<int>> price1 = {{1,3}, {2,4}};
    int k1 = 2;
    int n1 = 2;
    vector<vector<int>> queries1 = {{1,4}};
    int q1 = 1;
    vector<int> output1 = solution.bestPrice(n1, price1, k1, q1, queries1);
    cout << "Output 1: ";
    for (int num : output1) cout << num << " ";
    cout << endl;

    // Test Case 2
    vector<vector<int>> price2 = {{1,3}, {3,5}, {2,6}};
    int k2 = 3;
    int n2 = 3;
    vector<vector<int>> queries2 = {{1,3}, {5,6}};
    int q2 = 2;
    vector<int> output2 = solution.bestPrice(n2, price2, k2, q2, queries2);
    cout << "Output 2: ";
    for (int num : output2) cout << num << " ";
    cout << endl;

    int n = 6;
    vector<vector<int>> price = {{2, 2}, {8, 9}, {5, 8}, {9, 9}, {3, 7}, {10, 10}};
    int k = 1;
    int q = 4;
    vector<vector<int>> queries = {{19, 20}, {8, 9}, {19, 20}, {4, 20}};

    vector<int> results = solution.bestPrice(n, price, k, q, queries);

    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}