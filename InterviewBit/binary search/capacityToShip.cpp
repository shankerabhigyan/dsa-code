#include<bits/stdc++.h>
using namespace std;

bool canShipWithinDays(const vector<int>& weights, int days, int capacity) {
    int daysNeeded = 1;
    int currentLoad = 0;
    
    for (int weight : weights) {
        if (currentLoad + weight > capacity) {
            daysNeeded++;
            currentLoad = weight;
        } else {
            currentLoad += weight;
        }
        
        if (daysNeeded > days) {
            return false;
        }
    }
    
    return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canShipWithinDays(weights, days, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main(){
    return 0;
}