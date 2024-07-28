#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node *next, *bottom;
};
Node* head = NULL;
Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	Node* result;
	if (a->data < b->data) {
		result = a;
		result->bottom = merge(a->bottom, b);
	}
	else {
		result = b;
		result->bottom = merge(a, b->bottom);
	}
	result->next = NULL;
	return result;
}
Node* flatten(Node* root) {
	if (root == NULL || root->next == NULL) return root;
	root->next = flatten(root->next);
	root = merge(root, root->next);
	return root;
}
Node* push(Node* head_ref, int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	new_node->bottom = head_ref;
	head_ref = new_node;
	return head_ref;
}
void printList() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->bottom;
	}
	cout << endl;
}
int main() {
	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);
	head->next = push(head->next, 20);
	head->next = push(head->next, 10);
	head->next->next = push(head->next->next, 50);
	head->next->next = push(head->next->next, 22);
	head->next->next = push(head->next->next, 19);
	head->next->next->next = push(head->next->next->next, 45);
	head->next->next->next = push(head->next->next->next, 40);
	head->next->next->next = push(head->next->next->next, 35);
	head->next->next->next = push(head->next->next->next, 28);
	head = flatten(head);
	printList();
	return 0;
}
