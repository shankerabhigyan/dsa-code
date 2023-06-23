#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    void print(){
        cout<<"Class A"<<endl;
    }
    
    void print(string name){
        cout<<"Hey " << name << endl;
    }

    int print(string name, int n){
        cout<<"Hey " << name << endl;
        return n;
    }
};

class B{
    public:
    int a=10;
    int b=1;

    
    int operator+(B &obj){
        int v1 = this->a + obj.a;
        int v2 = this->b + obj.b;
        return v1+v2;
    }
};

int main(){
    
    // function overloading =>
    
    /*A a;
    a.print();
    a.print("Abhigyan");
    cout<<a.print("Abhigyan", 10)<<endl;
    */

    /*
    **     Operator overloading    ** 
    cannot overload operators { . , :: , ?: , sizeof() , .* , .->*}
    */

    B b1;
    b1.a = 100;
    b1.b = 200;

    B b2;
    b2.a = 1000;
    b2.b = 2000;
    
    cout<<b1+b2<<endl;

    return 0;
}