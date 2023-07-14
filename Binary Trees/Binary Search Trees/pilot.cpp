#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    struct node* left,right;
    node(val):key(val),left(nullptr),right(nullptr){}
};