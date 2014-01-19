// Reverse Linked list

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

struct Node*reverse(struct Node* head){
	struct Node* prev = NULL;
	struct Node* temp;
	
	while(head!=NULL){
		temp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
	}
	
	return prev;
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
	cout<<"All elements added."<<endl;
	traverse(head);
	
	cout<<"After reversing the list is:"<<endl;
	head = reverse(head);
	traverse(head);
  
    return 0;
}