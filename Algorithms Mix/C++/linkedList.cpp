/* Program to illustrate linked list.
1. insert at beginning
2. insert at end
3. delete at beginning
4. delete at end
5. insert at specified position
6. delete at specified position
7. search for a specific data element
8. traverse the list
*/

#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
};

struct Node* insertFirst(struct Node *head, int data){
    struct Node *temp = new Node;
    temp->val = data;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        return head;
    }
    temp->next=head;
    
    return temp;;    
}


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

struct Node* insertPosition(struct Node* head, int data, int pos){
	int i = 0;
	struct Node* temp = new Node;
	struct Node* cur;
	struct Node* prev;
	temp->val = data;
	temp->next = NULL;
	
	if(head==NULL || pos == 1){
		head = temp;
		cout<<"Can insert at only at 1 by default.";
		return head;
	}
	
	prev = NULL;
	cur = head;
	while(++i<pos && cur!=NULL){
		prev = cur;
		cur = cur->next;
	}
	prev->next = temp;
	temp->next = cur;
	
	return head;
}

struct Node* deleteFirst(struct Node* head){
    struct Node* temp;
    if(head == NULL){
        cout<<"Empty list. Nothing to delete.";
        return NULL;
    }
    
    temp = head->next;
    free(head);
    return temp;
}


struct Node* deleteLast(struct Node*head){
    struct Node* cur;
    struct Node* prev;
    
    if(head == NULL){
        cout<<"Empty list. Nothing to delete.";
        return NULL;
    }
    
    prev = NULL;
    cur = head;
    while(cur->next!=NULL){
        prev = cur;
        cur = cur->next;
    }
    
    prev->next = NULL;
    free(cur);
    return head;
}

struct Node* deletePosition(struct Node *head, int pos){
	struct Node* prev;
	struct Node* cur;
	struct Node* temp;
	int i = 0;
	
	if(head == NULL){
		cout<<"List is empty.";
		return NULL;
	}
	
	if(pos == 1){
		cur = head->next;
		free(head);
		return cur;
	}
	
	prev = NULL;
	cur = head;
	while(++i<pos && cur!=NULL){
		prev = cur;
		cur = cur->next;
	}
	
	temp = cur;
	prev->next = cur->next;
	cout<<"Item deleted is "<<temp->val<<endl;
	free(temp);
	
	return head;
}

int searchItem(struct Node *head, int item){
	struct Node* cur;
	int i = 0;

	
	if(head == NULL){
		cout<<"List is empty.";
	}
	
	cur = head;
	while(cur!=NULL){
		i++;
		if(item == cur->val){
			cout<<"Item is present at "<<i<<" location.";
			return i;
		}		
		cur = cur->next;	
	}
	return 0;
}

int main() {
    // your code goes here
    struct Node *head;
    
    // Check insertion of elements.    
    head = insertFirst(head, 5);
    head = insertFirst(head, 3);
    head = insertLast(head, 10);
    traverse(head);
    cout<<"All elements added."<<endl;
    
    // Check deletion.
    /*head = deleteFirst(head);
    //head = deleteLast(head);
    traverse(head);
    cout<<"All elements deleted.";
    */
    
    // Searching for element. Return position of element if present.
    if(searchItem(head, 5)==0)
    	cout<<"Item (5) is not present."<<endl;
    if(searchItem(head, 15)==0)
    	cout<<"Item (15) is not present."<<endl;
    
    // Insert data at specified position.
    head = insertPosition(head, 15, 3);
    head = insertPosition(head, 4, 2);
    traverse(head);
    
    // Delete at specified position.
    head = deletePosition(head, 2);
    traverse(head);
    return 0;
}