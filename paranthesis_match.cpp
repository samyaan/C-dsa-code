#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct stack1{
	int size;
	char top;
	char *arr;
};



char pop(struct stack1* s){
	char val=s->arr[s->top];
	s->top--;
	cout<<"POPPED: "<<val<<endl;
	return val;
	
}

void travers(struct stack1* s){
	for(int i=0;i<s->size;i++){
		cout<<s->arr[i];
	}
}

void push(struct stack1* s, char val){
	s->top++;
	s->arr[s->top]=val;
	cout<<"Pushed: "<<s->arr[s->top]<<endl;
}

bool paraCheck(struct stack1* s, string exp){
	for(int i=0;i<s->size;i++){
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[' )
			push(s,exp[i]);
		else if(exp[i]==')'){
			if(s->arr[s->top]=='(')
				pop(s);
			else
				push(s,')');
		}
		else if(exp[i]=='}'){
			if(s->arr[s->top]=='{')
				pop(s);
			else
				push(s,'}');
		}
		else if(exp[i]==']'){
			if(s->arr[s->top]=='[')
				pop(s);
			else
				push(s,'[');
		}
	}
	if(s->top<0)
		return true;
	else
		return false;
}

int main(){
	
struct stack1* s=(struct stack1*)malloc(sizeof(struct stack1));
string exp;
cout<<"Enter The Expression:\t";
getline(cin,exp);

s->size=exp.length();
s->arr=(char*)malloc(s->size*sizeof(char));
s->top=-1;

bool val=paraCheck(s,exp);
if(val)
	cout<<"\nParanthesis Matched!";
else
	cout<<"\nParanthesis UnMatched!";


return 0;
	
}
