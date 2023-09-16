/*
Shopping and billing

In a shop with N counters, M people arrive for billing at different times denoted as timelil. Each person selects the counter with the shortest queue, based on the number of people already present. If a counter is empty, the person get immediate billing, otherwise, they join the queue.

For every person, output the time when they finish billing and leave the counter.

Notes

. It takes 1 unit of time for the counter to process a person's bill.

• The counter processes the next person immediately

after the current person leaves.

• The time is given in increasing order of arrival at the counters. In formal terms time[i] < time[i+1].

Function description

omplete the function solve. This function takes the following parameters and returns the required answer:

• N: Represents the number of counters ⚫M: Represents the number of persons

⚫ time: Represents an array containing the entry time of the people

nput format for custom testing

Note: Use this input format if you are testing against custom input or writing code in a language where we don't provide boilerplate code.

The first line contains N denoting the number of counters.

• The second line contains M denoting the number of persons.

. The third line contains an array time, indicating the entry time of the people.

Output format

Print a single line of M space-separated integers, denoting the exit times of the people.

*/

#include <bits/stdc++.h>

using namespace std;

struct Counter {
    int index;
    int queueLength;

    bool operator>(const Counter& other) const {
 
        return queueLength > other.queueLength;
    }
};

vector<int> shortestQueue(int N, const vector<int>& time) {
    vector<int> result;
    priority_queue<Counter, vector<Counter>, greater<Counter>> counters;

    for (int i = 0; i < N; ++i) {
        counters.push({i, 0});
    }

    for (int t : time) {
       
        Counter minCounter = counters.top();
        counters.pop();

        int finishTime = max(t, minCounter.queueLength) + 1;

    
        minCounter.queueLength = finishTime;

       
        counters.push(minCounter);

     
        result.push_back(finishTime);
    }

    return result;
}

int main() {
    int N;
    int M;
    cin>>N>>M;

    vector<int> time(M);
    for(int i=0;i<M;i++){
      cin>>time[i];
    } 
    vector<int> result = shortestQueue(N, time);


    for (int finishTime : result) {
        cout << finishTime << " ";
    }
    cout << endl;

    return 0;
}

