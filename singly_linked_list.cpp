#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;

	Node(int x){
		data=x;
		next=NULL;
	}
};

void Display(Node *head){
	if(head==NULL){
		cout<<"List is Empty\n";
		return;
	}
	Node *ptr=head;
	while(ptr){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<"\n";
}

Node *Insert_at_Tail(Node* head,int x){
	if(head==NULL) {
		head=new Node(x);
		return head;
	}
	Node *temp=new Node(x);
	Node *ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
	return head;
}

Node *Insert_at_Head(Node* head,int x){
	if(head==NULL) {
		head=new Node(x);
		return head;
	}
	Node *temp=new Node(x);
	
	temp->next=head;
	head=temp;
	return head;
}

// we are using Node *&head here because we need to change the head of main function
//so we can access the head ,if we don't want to use this we will need to return head
//Node **head and Node *&head are same in the former we use *head for address
void Delete_Head(Node *&head){
	if(head==NULL){
		cout<<"List is Empty\n";
		return ;
	}
	/*if(head->next==NULL){
		head=NULL;
	}*/

	Node *ptr=head;
	head=head->next;
	delete(ptr);
}

//when we declare as Node **head we need to pass the address of head as an argument 

void Delete_Tail(Node **head){
	if(*head==NULL){
		cout<<"list is Empty\n";
		return;
	}
	Node *ptr=*head;
	if(ptr->next==NULL){
		*head=NULL;
		delete(ptr);
		return;
	}

	while(ptr->next->next!=NULL){
		ptr=ptr->next;
	}
	Node *temp=ptr->next;
	ptr->next=NULL;
	delete(temp);

}

int main(){
	Node *head=NULL;
	head=Insert_at_Head(head,5);

	//head=Insert_at_Tail(head,30);
	//Display(head);
	//head=Insert_at_Head(head,20);
	//head=Insert_at_Head(head,10);
	//head=Insert_at_Tail(head,40);
	Display(head);
	Delete_Head(head);
	Display(head);
	Delete_Tail(&head);
	Display(head);
	
	
}
