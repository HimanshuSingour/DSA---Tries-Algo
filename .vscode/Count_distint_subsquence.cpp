#include<bits/stdc++.h>
using namespace std;

const int ALPHABET = 26;

class TrieNode{
 
public:
      
    TrieNode * alpha[ALPHABET];

	TrieNode(){

	 	for(int i = 0; i < 26; i++){
	 		alpha[i] = NULL;
	 	}
	}

	bool contains(TrieNode * temp , char c){
	 	return alpha[c - 'a'] != NULL;
	}

	void put(TrieNode * newNode , char c){
	 	alpha[c - 'a'] = newNode;
	}

	TrieNode* getNext(char c){
		return alpha[c - 'a'];

	}

	bool setFlag(){
		return true;
	}

};

int solve(string str , TrieNode * root){


	int c = 0;

	for(int i = 0; i < str.size(); i++){
       
       for(int j = i; j < str.size(); j++){

       	   if(!temp->contains(temp , str[i])){
              
              TrieNode * newNode = new TrieNode;
              c++;
              temp->put(newNode , str[i]);
              
       	   }

       	   temp = temp->getNext(str[i]);
       }
	}

	return c;
	
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 

	freopen("outputf.in" , "w" , stdout);
	#endif


// Taking Input

 
  TrieNode * root = new TrieNode;

	string str = "xyz";

	cout << solve(str , root);



}