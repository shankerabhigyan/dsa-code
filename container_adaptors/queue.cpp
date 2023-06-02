// uses the first in first out (FIFO) principle.
#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <string> q;
    q.push("A");
    q.push("B");
    q.push("C");

    cout << "Front Element: " << q.front() << endl;
    cout << "Back Element: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    q.pop();
    cout << "Front Element: " << q.front() << endl;

    return 0;
}