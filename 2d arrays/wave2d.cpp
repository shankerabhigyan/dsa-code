#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int n, int m){ // complexity O(n*m)
    vector<int> wave;
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                wave.push_back(arr[j][i]);
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                wave.push_back(arr[j][i]);
            }
        }
    }
    return wave; 
}

int main(){
    vector <vector<int>> arr;
    int n,m;
    cout << "Enter the number of rows and columns : " << endl;
    cin >> n >> m;
    arr.resize(n);
    for (int i=0;i<n;i++){
        arr[i].resize(m);
    }
    cout << "Enter "<<(n*m)<< " elements of the array : " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    cout << "The elements of the array are : " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The wav print is : ";
    vector<int> wave=wavePrint(arr,n,m);
    for(auto i:wave){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}