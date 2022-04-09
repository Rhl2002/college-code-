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

void Delete_Node(Node *&head,int x){
	if(head==NULL){
		cout<<"List is Empty\n";
		return ;
	}
	Node *temp=head,*ptr=head;
	temp=temp->next;
	if(ptr->data==x){
		head=ptr->next;
		delete(ptr);
		return;	
	}
	while( temp){

		if(temp->data==x ){
			ptr->next=temp->next;
			delete(temp);
			return;
		}
		temp=temp->next;
		ptr=ptr->next;
	}
}

Node* Reverse(Node *head){
	if(head==NULL){
		return NULL;
	}
	Node *temp1,*temp2,*temp3; //three pointer algorithm
	temp1=head;
	temp2=NULL;
	temp3=NULL;
	while(temp1){
		temp3=temp2;//pointing to previous node
		temp2=temp1; //pointing to node to be reversed
		temp1=temp1->next; //iterating list
		temp2->next=temp3; //pointing current node to previous node
	}
	head=temp2;
	return head;
}
int main(){
	Node *head=NULL;
	head=Insert_at_Head(head,25);

	head=Insert_at_Tail(head,30);

	head=Insert_at_Head(head,20);
	head=Insert_at_Head(head,10);
	head=Insert_at_Tail(head,40);
	Display(head);
	head=Reverse(head);
	Display(head);
}

