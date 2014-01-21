//Bring last n nodes in a singly linked list to the front.

#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
};


// Print contents of the list
void traverse(struct Node* head){
    struct Node *list = head;
    if(list == NULL)
        cout<<"List is empty";
    
    else{
        while(list){
            cout<<list->val<<",";
            list = list->next;
        }
    }
    cout<<endl;
}

struct Node* insertLast(struct Node* head, int data){
    struct Node* temp = new Node;
    struct Node* cur;
    temp->val = data;
    temp->next = NULL;
    
    if(head == NULL){
        head = temp;
        return head;
    }
    
    cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    
    cur->next = temp;
    return head;
        
}

struct Node* bringFront(struct Node* head, int num){
	struct Node* next;
	struct Node* cur;
	int k = 1;
	
	if(head == NULL){	
		cout<<"List is empty.";
		return NULL;
	}
	
	next = head;
	cur = head;
	
	while(k<=num){
		next = next->next;
		if(next == NULL){
			cout<<"Invalid value for num specified";
			return head;
		}
		k++;
	}
	
	while(next->next!=NULL){
		next = next->next;
		cur = cur->next;
	}
	
	
	next->next = head;
	head = cur->next;
	cur->next = NULL;
	
	return head;
}

int main() {
    // your code goes here
    struct Node *head;
    
    // Check insertion of elements.
    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertLast(head, 30);
    head = insertLast(head, 40);
    head = insertLast(head, 50);
    traverse(head);
    cout<<"All elements added."<<endl;
    head = bringFront(head,3);
    cout<<"Output is: "<<endl;
    traverse(head);
    
    return 0;
}