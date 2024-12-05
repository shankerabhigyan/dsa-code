#include <bits/stdc++.h>

using namespace std;

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode* next;
};

SinglyLinkedListNode* getNode(int data)
{
	SinglyLinkedListNode* newNode = new SinglyLinkedListNode;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void deleteGreaterNodes(SinglyLinkedListNode* head_ref, int x)
{
	SinglyLinkedListNode *temp = head_ref, *prev;

	if (temp != NULL && temp->data > x) {
		head_ref = temp->next; 
		free(temp); 
		temp = head_ref; 
	}

	while (temp != NULL) {

		while (temp != NULL && temp->data <= x) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL)
			return;

		prev->next = temp->next;
		delete temp; 
		temp = prev->next;
	}
}

void printList(SinglyLinkedListNode* head)
{
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}


int main()
{
	// Create list: 7->3->4->8->5->1
	SinglyLinkedListNode* head = getNode(7);
	head->next = getNode(3);
	head->next->next = getNode(4);
	head->next->next->next = getNode(8);
	head->next->next->next->next = getNode(5);
	head->next->next->next->next->next = getNode(1);

	int x = 6;

	cout << "Original List: ";
	printList(head);

	deleteGreaterNodes(head, x);

	cout << "\nModified List: ";
	printList(head);
    cout << endl;

	return 0;
}
