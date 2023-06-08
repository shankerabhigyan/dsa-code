#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/spiral-matrix/description/

vector<int> spiralPrint(vector<vector<int>> arr){
    int n=arr.size();
    int m=arr[0].size();
    int rs=0, cs=0, re=n-1,ce=m-1, count=0;
    vector<int> spiral;
    tot = n*m;
    while(count<tot){
        for(int i=cs;i<=ce;i++){
            cout << arr[rs][i] << " ";
            spiral.push_back(arr[rs][i]);
            count++;
        }
        rs++;
        if (rs>re){
            break;
        }
        if (count>=tot){
                break;
        }

        for(int i=rs;i<=re;i++){
            cout << arr[i][ce] << " ";
            spiral.push_back(arr[i][ce]);
            count++;
        }
        ce--;
        if (count>=tot){
                break;
        }
        for(int i=ce;i>=cs;i--){
            cout << arr[re][i] << " ";
            spiral.push_back(arr[re][i]);
            count++;
        }
        re--;
        if (count>=tot){
                break;
        }
        for(int i=re;i>=rs;i--){
            cout << arr[i][cs] << " ";
            spiral.push_back(arr[i][cs]);
            count++;
        }
        cs++;
    }
    cout << endl;
    return spiral;
    // the complexity of this function is O(n*m)
}

int main(){
    int n,m;
    cout << "Enter the number of rows and columns : " << endl;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    /* else 
     vector<vector<int>> arr;
     arr.resize(n);
     for (int i=0;i<n;i++){
         arr[i].resize(m);
     }*/
    cout << "Enter "<<(n*m)<< " elements of the array : " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    cout << "The elements of the array are : " << endl;
    for (auto i:arr){ // i is a vector of integers
        for(auto j:i){ // j is an integer
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "The spiral print is : ";
    spiral = spiralPrint(arr,n,m);
}   