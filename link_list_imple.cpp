#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct node{

int value;
struct node* next;
	
};


struct node* insertAtbeg(struct node* ptr, int val){
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->value=val;
	temp->next=ptr;
	return temp;
}


struct node* insertAtend(struct node* ptr, int val){
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	struct node* p= (struct node*)malloc(sizeof(struct node));
	p=ptr;
	temp->value=val;
	while(ptr->next!= NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->next=NULL;
	return p;
}

struct node* deleteFirst(struct node* ptr){
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp=ptr;
	ptr=ptr->next;
	free(temp);
	return ptr;
	
}

struct node* deleteLast(struct node* ptr){
	struct node* p= (struct node*)malloc(sizeof(struct node));
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	p=ptr;

	while(ptr->next!= NULL){
		temp=ptr;
		ptr=ptr->next;
		
	}
	temp->next=NULL;
	free(ptr);
	return p;
	
}


struct node* deleteatX(struct node* ptr, int k){
	struct node* p= (struct node*)malloc(sizeof(struct node));
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	p=ptr;
	int count=0;
	while(count<k-1){
		ptr=ptr->next;
		count++;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	free(temp);
	return p;
	
}

struct node* insertAtX(struct node* ptr, int val, int pos){
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	struct node* p= (struct node*)malloc(sizeof(struct node));
	p=ptr;
	int count=0;
	temp->value=val;
	if(pos==0){
		ptr=insertAtbeg(ptr,val);
		return ptr;
	}
	else{
	while(count!= pos-1){
		ptr=ptr->next;
			count++;
	}
	temp->next=ptr->next;
	ptr->next=temp;

	}
	return p;	
}


void traversal(struct node* ptr){
	
	while(ptr!= NULL){
		printf("%d ",ptr->value);
		ptr=ptr->next;
	}
	cout<<endl;
}

int main(){
	struct node* head;
	head=(struct node*)malloc(sizeof(struct node));
	head->value=10;
	head->next=NULL;
	int x;
	traversal(head);
	scanf("%d", &x);
	
	head=insertAtend(head,x);
	traversal(head);
	head=insertAtend(head,34);
	traversal(head);
	head=insertAtend(head,90);
	traversal(head);
	head=insertAtend(head,11);
	traversal(head);
	head=insertAtX(head,222,2);
	traversal(head);
	head=deleteFirst(head);
	traversal(head);
	head=deleteLast(head);
	traversal(head);
	head=insertAtbeg(head,36);
	traversal(head);
	head=deleteatX(head,2);
	traversal(head);
	
	return 0;
}
