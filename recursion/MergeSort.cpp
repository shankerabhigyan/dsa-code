#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2){
    vector<int> v;
    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else{
            v.push_back(v2[j]);
            j++;
        }        
    }
    while(i<v1.size()){
        v.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        v.push_back(v2[j]);
        j++;
    }
    return v;
}

vector<int> mergeSort(vector<int> v){
    int n = v.size();
    int mid = n/2;
    vector<int> v1(v.begin(), v.begin()+mid); // v1 = v[0...mid-1]
    vector<int> v2(v.begin()+mid, v.end()); // v2 = v[mid...n-1]

    if(n==1 || n==0){
        return v;
    }
    v1 = mergeSort(v1);
    v2 = mergeSort(v2);

    vector<int> v_merged = merge(v1, v2);
    return v_merged;
}

int main(){
    int x,n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> v;
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }

    vector<int> v_sorted = mergeSort(v);
    cout << "Sorted array: ";
    for(int i=0; i<v_sorted.size(); i++){
        cout << v_sorted[i] << " ";
    }
    cout << endl;

    return 0;
}