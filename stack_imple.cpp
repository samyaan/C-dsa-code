 #include<bits/stdc++.h>

struct stack{
	int top;
	int size;
	int *arr;
};


struct stack* push(struct stack* s, int val){
	if(s->top == s->size){
		printf("STACK FULL!!");
		return s;
	}
	else{
			s->top=s->top+1;
	s->arr[s->top]=val;
	return s;
	}

}

int pop(struct stack* s){
	if(s->top==-1){
		printf("STACK EMPTY!!");
	}
	else{
		int temp=s->arr[s->top];
	s->top--;
		return temp;
	}
	return 0;

}


void peak(struct stack* s,int pos){
	if(pos>s->top || pos<0){
		printf("Position donot Exist");
		
	}
	else{
		printf("%d",s->arr[pos]);
	}
}

void traversal(struct stack* s){
	for(int i=0;i<=s->top;i++){
		printf("%d ",s->arr[i]);
	}
}

int main(){
		struct stack* s=(struct stack*)malloc(sizeof(struct stack));
		int n,p;
		scanf("Enter Stack Size: %d",&n);
		s->top=-1;
		s->size=n;
		s->arr=(int*)malloc(n*sizeof(int));
		s=push(s,30);
		s=push(s,40);
		s=push(s,50);
		s=push(s,60);
		s=push(s,70);
		s=push(s,80);
		traversal(s);
		printf("\nTop: %d",s->top);
		p=pop(s);
		printf("\nPopped value: %d\n",p);
		traversal(s);
		p=pop(s);
		printf("\nPopped value: %d\n",p);
		traversal(s);
		peak(s,3);
		return 0;		
}
