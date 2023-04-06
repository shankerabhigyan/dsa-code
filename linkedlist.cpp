// linked list data structure
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    public:
        Node * head;
        LinkedList(){
            head = NULL;
        }
        void insert(int data){
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = head;
            head = new_node;
        }
        void print(){
            Node* temp = head;
            while (temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};