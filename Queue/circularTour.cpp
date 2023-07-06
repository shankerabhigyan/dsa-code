// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

#include<bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
    petrolPump(): petrol(0),distance(0){}
    petrolPump(int a, int b): petrol(a), distance(b) {}
};

int tour(petrolPump p[], int n){
    queue<int> iq;
    int front = 0, rear = 0, balance = 0;
}

int main(){
    int n;
    cin >> n;
    petrolPump p[n];
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        p[i].petrol = a;
        p[i].distance = b;
    }
    int start = tour(p,n);
    cout << start << endl; 
    return 0;
}