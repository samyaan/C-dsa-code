#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int min_max(int *arr, int n){
	
	int max=0;
	int min=arr[0];
	for(int i=0; i<n ;i++){
	if(arr[i]>max){
		max=arr[i];
	}

	if(arr[i]<min){
		min=arr[i];
	}

	}
	
	cout<<"Max: "<<max<<endl<<"MIN: "<<min<<endl;	
	return 0;
	
}

int main(){
	
	int n;

	cout<<"Enter N: ";
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	min_max(arr, n);
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
