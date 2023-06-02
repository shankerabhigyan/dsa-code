// Stack is gives the functionality of LIFO (Last in first out) 
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <string> s;
    s.push("A");
    s.push("B");
    s.push("C");

    cout << "Top Element: " << s.top() << endl;
    s.pop();
    cout << "Top Element: " << s.top() << endl;
    
    s.size(); // returns the size of the stack
    s.empty(); // returns true if stack is empty else false

    return 0;
}