#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	//data declaration
	int books, lib, days;
	cin>>books>>lib>>days;
	vector<int> book_score;
	vector< vector < int > > lib_dets; 
	vector<vector<int> > book_name;
	vector<vector<int > > result;
	vector<vector<int> >book_scan;
	int temp;
	int signup_count=0;
	int process_check=0;
	
	//input process
	for(int i=0;i<books;i++){
		cin>>temp;
		book_score.push_back(temp);
	}
	
	for(int j=0;j<lib;j++){
		vector<int> det;
		vector<int> temp;
		int b,sp,sh;
		cin>>b>>sp>>sh;
		det.push_back(b);
		det.push_back(sp);
		det.push_back(sh);
		lib_dets.push_back(det);
		
		for(int k=0;k<lib_dets[j][0];k++){
			int var;
			cin>>var;
			temp.push_back(var);
		}
		book_name.push_back(temp);
	}
	/*
	//Input verification:
	 cout<<"Books: "<<books<<" Library: "<<lib<<" Days: "<<days;
	 cout<<endl;
	 for(int i=0;i<book_score.size();i++){
	 	cout<<"Score of book "<<i<<" is: "<<book_score[i]<<endl;
	 }
	 cout<<"Library details:"<<endl;
	 for(int i=0;i<lib_dets.size();i++){
	 		cout<<"Library: "<<i<<endl;
	 		cout<<"Number of Books: "<<lib_dets[i][0]<<endl;
	 		cout<<"Time taken in signup Process: "<<lib_dets[i][1]<<endl;
	 		cout<<"Number of book library can ship in a day: "<<lib_dets[i][2]<<endl;
	 		cout<<"Books in Library : "<<book_name[i].size()<<endl;
	 		for(int j=0;j<book_name[i].size();j++){
	 			cout<<book_name[i][j]<<" ";
			 }
		 cout<<endl;
	 }
	 */
	 
	 //output generation
	 	int days_left=days;
	 	for(int i=0;i<lib_dets.size();i++){
	 		vector<int> l2;
	 		if(process_check<=days){
	 		int book_scanned=0;
	 		if(lib_dets[i][1]<days_left){
	 			signup_count++; //  var1
	 			if(signup_count==1){
	 				process_check=lib_dets[i][1]-1;	
				 }
				 else{
				 	process_check=process_check+lib_dets[i][1];
				 }
				 days_left=days_left-process_check;
				 if((days_left*lib_dets[i][2]) > lib_dets[i][0]){
				 	book_scanned=lib_dets[i][0];
				 }
				 else{
				 	book_scanned=days_left*lib_dets[i][2];
				 }
				 l2.push_back(i);
				 l2.push_back(book_scanned);
				 result.push_back(l2);
				
			 }
			 else{
			 	continue;
			 }
		}
	 }
	 
	 
	 //printing Output
	 
	 cout<<signup_count<<endl; //number of signups
	 for(int i=0;i<result.size();i++){
	 	for(int j=0;j<2;j++){
	 		cout<<result[i][j]<<" "; //library number and books scanned
		 }
		 cout<<endl;
		 for(int k=0;k<result[i][1];k++){
		 	cout<<book_name[result[i][0]][k]<<" "; //book number
		 }
		 cout<<endl;
	 }

	 
	 
}
