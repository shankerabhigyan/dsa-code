#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	vector<Node*> neighbors;
	Node(){
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val){
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors){
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution{
	public:
	Node* cloneGraph(Node* node){
		if(node==NULL) return NULL;
		Node* head = new Node(node->val);
		stack<Node*> s;
		unordered_map<int, Node*> mp;
		mp[head->val] = head;
		for(Node* n: node->neighbors){
			Node* temp = new Node(n->val);
			mp[temp->val] = temp;
			s.push(temp);
			head->neighbors.push_back(temp);
		}
		
		while(!s.empty()){
			Node* temp = s.top();
			s.pop();
			for(Node* n: temp->neighbors){
				if(mp.find(n->val)!=mp.end()){
					temp->neighbors.push_back(mp[n->val]);
				}
				else{
					Node* neighbor = new Node(n->val);
					s.push(neighbor);
					mp[neighbor->val] = neighbor;
					temp->neighbors.push_back(neighbor);
				}
			}
		}
		return head;
	}
};

int main(){

	return 0;
}
