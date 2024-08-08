#include <iostream>
#include <vector>
#include <unordered_map>

int countDisqualifiedPlayers(int N, int K, const std::vector<std::pair<int, int>>& playerRecords) {
    // This map holds another map that counts occurrences of each ball per player
    std::unordered_map<int, std::unordered_map<int, int>> ballCount;

    // Process each player record
    for (const auto& record : playerRecords) {
        int playerId = record.first;
        int ballNumber = record.second;
        ballCount[playerId][ballNumber]++;
    }

    // Now find out how many players are disqualified
    int disqualifiedCount = 0;
    for (const auto& player : ballCount) {
        bool disqualified = false;
        for (const auto& ball : player.second) {
            if (ball.second > K) {
                disqualified = true;
                break;
            }
        }
        if (disqualified) {
            disqualifiedCount++;
        }
    }

    return disqualifiedCount;
}

int main() {
    // Example 1:
    int N1 = 6;
    int K1 = 1;
    std::vector<std::pair<int, int>> records1 = {{5,2}, {3,6}, {5,4}, {2,8}, {5,4}, {5,4}};
    std::cout << "Example 1 - Number of disqualified players: " << countDisqualifiedPlayers(N1, K1, records1) << std::endl;

    // Example 2:
    int N2 = 8;
    int K2 = 0;
    std::vector<std::pair<int, int>> records2 = {{10,6}, {3,1}, {10,6}, {10,6}, {4,5}, {3,1}, {3,5}, {3,1}};
    std::cout << "Example 2 - Number of disqualified players: " << countDisqualifiedPlayers(N2, K2, records2) << std::endl;

    return 0;
}
