#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    /*cout << arr << endl;
    cout << &arr[0] << endl;
    cout << &arr << endl;
    cout << *arr << endl;
    cout << *(arr+1) << endl;
    */
    int *p = &arr[0];
    
    //int i = 4;
    //cout << i[arr] << endl; 
    //cout << *(i+arr) << endl;

    /*cout << sizeof(arr) << endl;
    cout << sizeof(&arr) << endl;
    cout << sizeof(arr[0]) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(*p) << endl;
    */

    """
    Pointers in Character Arrays 
    """
    char ch[6] = "abcde";
    cout << ch << endl; //abcde
    cout << &ch << endl; // address of the string
    char *c = &ch[0];  // abcde
    cout << c << endl;


    return 0;   
}