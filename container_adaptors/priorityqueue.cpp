#include <iostream>
#include <queue>
using namespace std;

void display(priority_queue <int> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void display(priority_queue <int, vector<int>, greater<int>> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    priority_queue <int> pq; // max heap, elements are sorted in descending order
    priority_queue <int, vector<int>, greater<int>> pq1; // min heap, elements are sorted in ascending order

    pq.push(10);
    pq.push(20);
    pq.push(15);

    pq1.push(10);
    pq1.push(20);
    pq1.push(15); 

    display(pq);
    display(pq1);

    return 0;
}