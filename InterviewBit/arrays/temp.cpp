#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        vector<vector<int>> dpMin(N, vector<int>(M, INT_MAX));
        vector<vector<int>> dpMax(N, vector<int>(M, INT_MIN));
        vector<vector<int>> cost(N, vector<int>(M, INT_MAX));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
                if (j == 0) {
                    dpMin[i][j] = dpMax[i][j] = A[i][j];
                    cost[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < M; j++) {
            for (int i = 0; i < N; i++) {
                for (int k = 0; k < N; k++) {
                    int newMin = min(dpMin[k][j-1], A[i][j]);
                    int newMax = max(dpMax[k][j-1], A[i][j]);
                    int newCost = newMax - newMin;
                    if (newCost < cost[i][j]) {
                        cost[i][j] = newCost;
                        dpMin[i][j] = newMin;
                        dpMax[i][j] = newMax;
                    }
                }
            }
        }

        int minCost = INT_MAX;
        for (int i = 0; i < N; i++) {
            minCost = min(minCost, cost[i][M-1]);
        }

        cout << minCost << endl;
    }

    return 0;
}
