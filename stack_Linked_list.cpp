#include<bits/stdc++.h>

struct node{
	int val;
	struct node* next;
};




int bottom(struct node*s){
	while(s->next!=NULL){
	s=s->next;
	}
	return s->val;
}


int isEmpty(struct node* s){
	if(s==NULL){
	
		return 1;
	}
	else{
		return 0;
	}
}


int isFull(struct node*s){
struct node *temp=(struct node*)malloc(sizeof(struct node));
if(temp==NULL){
	return 1;
}
else{
	return 0;
}	
}

struct node* push(struct node* s, int data){
	if(!isFull(s)){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	
	temp->val=data;
	temp->next=s;
	s=temp;
	return s;	
	}
	else{
	printf("STACK FULL");
	}
	return s;
	
}

struct node* pop(struct node* s){
	if(isEmpty){
		struct node* temp=s;
		printf("\nVALLUE: %d\n",s->val);
		s=s->next;
		free(temp);
	}
	return s;
}


void traversal(struct node* s){
	printf("\n");
	while(s!=NULL){
		printf("%d\t",s->val);
		s=s->next;
	}
}



int main(){
	struct node* head= (struct node*)malloc(sizeof(struct node));
	head->val=20;
	head->next=NULL;
	head=push(head,30);
	head=push(head,40);
	head=push(head,50);
	traversal(head);
	head=push(head,60);
	traversal(head);
	printf("\nTOP: %d\tBOTTOM: %d",head->val,bottom(head));
	head=pop(head);
	traversal(head);
	head=pop(head);
	traversal(head);
	
	return 0;
}
