#include<bits/stdc++.h>
#include<iostream>
using namespace std;


struct stack_new{
	int top;
	int size;
	char *arr;
};

char pop(struct stack_new *s){
	char ch;
	ch=s->arr[s->top];
	s->top--;
	return ch;
}

struct stack_new* push(struct stack_new *s,char ch ){
	s->top++;
	s->arr[s->top]=ch;
	return s;
}


int pre(char ch){
	if(ch=='/' || ch=='*')
		return 3;
	if(ch=='+' || ch=='-')
		return 2;
	else
		return 1;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}

string conversion(string infix){
	struct stack_new* s=(struct stack_new*)malloc(sizeof(struct stack_new));
	char *postfix=(char*)malloc(s->size*sizeof(char));
	s->top=-1;
	s->size=infix.length();
	s->arr=(char*)malloc(s->size*sizeof(char));
	int i=0,j=0;
	while(infix[i]!='\0'){
		if(!IsOperator(infix[i])){
			postfix[j]=infix[i];
		
			j++;
			i++;
		}
		else{
			if(pre(infix[i])>pre(s->arr[s->top])){
				s=push(s,infix[i]);
				i++;
			}
			else{
			
				postfix[j]=pop(s);
			
				j++;
			}
		}
	}
	while(s->top>=0){
	
		postfix[j]=pop(s);
	
		j++;
	}

		return postfix;
	
}


int main(){
	string infix;
	getline(cin,infix);
	string postfix;
	postfix=conversion(infix);
	int i=0;
	for(i=0;i<infix.length();i++){
		cout<<postfix[i];
	}
	
	return 0;
	
}
