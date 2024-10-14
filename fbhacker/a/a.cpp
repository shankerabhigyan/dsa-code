#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("subsonic_subway_input.txt"); 
    ofstream outputFile("sonic_output_main.txt"); //

    if (!inputFile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    int T;
    inputFile >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N;
        inputFile >> N;
        
        double maxMinSpeed = 0;
        double minMaxSpeed = 1e9;
        
        for (int i = 1; i <= N; ++i) {
            int Ai, Bi;
            inputFile >> Ai >> Bi;
            
            double minSpeed = (double)i / Bi;
            double maxSpeed = (double)i / Ai;
            
            maxMinSpeed = max(maxMinSpeed, minSpeed);
            minMaxSpeed = min(minMaxSpeed, maxSpeed);
        }
        
        outputFile << "Case #" << t << ": ";
        if (maxMinSpeed <= minMaxSpeed) {
            outputFile << fixed << setprecision(6) << maxMinSpeed << "\n";
        } else {
            outputFile << -1 << "\n";
        }
    }
    
    inputFile.close();
    outputFile.close();

    return 0;
}
