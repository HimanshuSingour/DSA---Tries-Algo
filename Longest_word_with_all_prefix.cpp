#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;
 

class TrieNode{

public:

    TrieNode *child[ALPHABET_SIZE];

    TrieNode(){

	for (int i = 0; i < ALPHABET_SIZE; i++)
		child[i] = NULL;

    }
   

    // Functions
    bool containes(TrieNode * node , char c){
    	return child[c - 'a'] != NULL;
    }

    void put(char c , TrieNode * newNode){
    	child[c - 'a'] = newNode;
    }

    TrieNode * getNext(char c){
    	return child[c - 'a'];
    }


    bool setFlag(){
    	return true;
    }

    bool findword(TrieNode * root , string word){

   
	   TrieNode * temp = root;

	   for(int i = 0; i < word.size(); i++){

	   	  if(temp->containes(temp , word[i])){
	   	  	
	   	  	 temp = temp->getNext(word[i]);

	   	  	 if(temp->setFlag() == false){

	   	  	 	return false;
	   	  	 }
	   	  }

	   	  else{

	   	  	return false;
	   	  }
	   }

	   return true;
}

};


void insert(TrieNode *root, string word)
{
    TrieNode *temp = root;
 
    for (int i = 0; i < word.size(); i++){

       if(!temp->containes(temp , word[i])){

	       	TrieNode * newNode = new TrieNode;
	       	temp->put(word[i] , newNode);
       }
       
       temp = temp->getNext(word[i]);
    }
    
    temp->setFlag();
}


string complet(vector<string> & str){

	string longest = "";

	TrieNode *root = new TrieNode;

	for(auto word : str){
		insert(root , word);
	}

	for(auto i : str){
		if(root->findword(root , i)){

			if(i.size() > longest.size()){

				longest = i;  
			}
			else if(i.size() == longest.size() && i < longest){
				longest = i;
			}
		}
	}

	if(longest == "" )return "no";
	return longest;
}
 

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin); 

	freopen("outputf.in" , "w" , stdout);
	#endif


// Taking Input


vector<string> str;
str.push_back("w");
str.push_back("wo");
str.push_back("wor");
str.push_back("wow");
str.push_back("work");


cout << complet(str);



   
}