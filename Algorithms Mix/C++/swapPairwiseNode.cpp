// Program to swap nodes in linked list pair wise.
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
            cout<<list->val<<" ";
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

struct Node* swap(struct Node* head){
	struct Node* temp = NULL;
	struct Node* cur;
	struct Node* next;
	
	cur = head;
	next = cur->next;
	
	// Empty list.
	if(head == NULL){
		cout<<"List is empty. \n";
		return NULL;
	}
	
	// Only one element in the list.
	if(next == NULL){
		return cur;
	}
	
	// If two elements in the list.
	else if(next->next == NULL){
		cur->next = NULL;
		next->next = cur;
		return next;
	}
	
	
	else{
		head = next;
		while(cur!=NULL){
			
			if(next == NULL)
				break;
				
			if(next->next == NULL)
				break;		
			
			cur->next = next->next;
			next->next = cur;
			
		
			if(temp == NULL)
				temp = cur;
	
			else{
				temp->next = next;
				temp = cur;
			}	
		
			cur = cur->next;
			next = cur->next;
		

		}
		return head;
	}
}

int main() {
    // your code goes here
    struct Node *head;
    
    // Check insertion of elements.
    head = insertLast(head, 1);
    head = insertLast(head, 2);
    head = insertLast(head, 3);
    head = insertLast(head, 4);
    head = insertLast(head, 5);
    head = insertLast(head, 6);
    
    cout<<"The list is: ";
    traverse(head);
    
    cout<<"After swapping elements, the list is: ";
    head = swap(head);
    traverse(head);
    return 0;
}