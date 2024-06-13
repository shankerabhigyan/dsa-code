#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>&heights){
    int n = heights.size();
    for(int i=0;i<n;i++){
        if(heights[i]>0){
            return false;
        }
    }
    return true;
}

void print(vector<int>&heights){
    int n = heights.size();
    for(int i=0;i<n;i++){
        cout << heights[i] << " ";
    }
    cout << endl;
}


// BRUTE FORCE
int trap(vector<int>&heights){
    int water = 0;
    int n = heights.size();
    int count = 0;
    bool storage = false;
    while(!check(heights)){
        for(int i=0;i<n;i++){
            if(heights[i]>0 && !storage){
                storage = true;
                heights[i] = heights[i] - 1;
            }
            else if(storage && heights[i]==0){
                count++;
            }
            else if(storage && heights[i]>0){
                water+=count;
                count = 0;
                heights[i] = heights[i] - 1;
            }
            else{ 
                continue;
            }
        }
        // cout << endl << water << endl;
        // print(heights);
        count = 0;
        storage = false;
    }
    return water;
}

int trapDP(vector<int>&heights){
    
}

int main(){
    int n;
    cin >> n;
    vector<int> heights(n,0);
    for(int i=0;i<n;i++){
        cin >> heights[i];
    }
    cout << trap(heights) << endl;
    return 0;
}