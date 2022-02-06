#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  // Bottom 2 line make io Fast
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("C:/Users/hp/OneDrive/Desktop/450/input_data/e_elaborate.in.txt","r",stdin);
  freopen("e_output.txt","w",stdout);
  int T_C=0;
  cin>>T_C;
  vector<string> ingredients;
  vector< vector<int > > like;
  vector< vector<int > > dislike;
  string temp;
  bool found = false;
  int found_at=0 , total_ingredients=0;
  int like_count=0 , dislike_count=0;
  for(int i=0;i<T_C;i++){
    cin>>like_count;
    vector <int> v1;
    for(int j=0;j<like_count;j++){
      cin>>temp;
      // cout<<"temp is : "<<temp<<endl;
      
      
      // To check if the in gredient was seenbefore
      for(int q=0;q<total_ingredients;q++){
        if(temp==ingredients.at(q)){
          found_at=q;
          found=true;
        }
      }
      
      // to add new ingredient option in ingrgedient list
      if(found==false){
        ingredients.push_back(temp);
        total_ingredients+=1;
        found_at = ingredients.size() - 1;
        // cout<< "Total Ingrediemnts till now : "<<total_ingredients << endl;
      }
      // cout<<"found at : "<<found_at <<endl;
      v1.push_back(found_at);
      found = false;
    }
    like.push_back(v1); 
    
    // FOR  Dislike of customers
    cin>>dislike_count;
    vector <int> v2;
    for(int j=0;j<dislike_count;j++){
      cin>>temp;
      // cout<<"temp is : "<<temp<<endl;
      
      // To check if the ingredient was seenbefore
      for(int q=0;q<total_ingredients;q++){
        if(temp==ingredients.at(q)){
          found_at=q;
          found=true;
        }
      }
      
      // to add new ingredient option in ingrgedient list
      if(found==false){
        ingredients.push_back(temp);
        total_ingredients+=1;
        found_at = ingredients.size() - 1;
        // cout<< "Total Ingrediemnts till now : "<<total_ingredients << endl;
      }
      // cout<<"found at : "<<found_at <<endl;
      v2.push_back(found_at);
      found = false;
    }
    dislike.push_back(v2);
  }
  
  
  
  // cout<< "All ingredients below "<<endl;
  // for(int k=0;k<total_ingredients;k++){
  //   cout<<"Ingredient "<<k<< " is "<<ingredients[k]<<endl;
  // }

  // cout<< "Now all Likes"<<endl;
  // for (int i = 0; i < like.size(); i++) {
  // for (int j = 0; j < like[i].size(); j++)
  //   cout << like[i][j] << " ";
  //   cout << endl;
  // }
  // cout<< "Now All Dislikes"<<endl;
  // for (int i = 0; i < dislike.size(); i++) {
  // for (int j = 0; j < dislike[i].size(); j++)
  //   cout << dislike[i][j] << " ";
  //   cout << endl;
  // }    
  
  
  vector<int> total_liking(total_ingredients,0);
  vector<int> total_disliking(total_ingredients,0);
  int temporary;
  for (int i = 0; i < like.size(); i++) {
    for (int j = 0; j < like[i].size(); j++){
      temporary = like[i][j];
      // cout<<"Like of "<<j<<" is incresed ";
      total_liking[temporary]+=1;
    }
  }
  for (int i = 0; i < dislike.size(); i++) {
    for (int j = 0; j < dislike[i].size(); j++){
      temporary = dislike[i][j];
      // cout<<"Like of "<<j<<" is incresed ";
      total_disliking[temporary]+=1;
    }
  }
  
  // for (int i = 0; i < total_liking.size(); i++) {
  //   cout<<"Total Liking for ingredient "<<i<<" is "<<total_liking[i]<<endl;
  // }
  // for (int i = 0; i < total_disliking.size(); i++) {
  //   cout<<"Total Disliking for ingredient "<<i<<" is "<<total_disliking[i]<<endl;
  // }
  
  vector<int> menu;
  for (int i=0; i<total_disliking.size();i++){
    if(total_liking[i]>total_disliking[i]){
      menu.push_back(i);
    }
  }
  cout<<menu.size()<<" ";
  for (int j=0;j<menu.size();j++){
    cout<< ingredients[menu[j]] << " ";
  }
}


