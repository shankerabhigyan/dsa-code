#include <iostream>
#include <vector>
#include <algorithm>

bool isValid(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i + 1] % arr[i] == 0) {
            return false;
        }
    }
    return true;
}

void permuteArray(std::vector<int>& arr, int start) {
    if (start == arr.size()) {
        if (isValid(arr)) {
            for (int num : arr) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        return;
    }

    for (int i = start; i < arr.size(); ++i) {
        std::swap(arr[start], arr[i]);
        permuteArray(arr, start + 1);
        std::swap(arr[start], arr[i]);
    }
}

int main() {
    int n;
    std::cout << "Enter the length of the array: ";
    std::cin >> n;

    // Creating an array containing numbers from 1 to n
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    // Permute the array and output all permutations satisfying the condition
    permuteArray(arr, 0);

    return 0;
}
