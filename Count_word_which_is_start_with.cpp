#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;
 

class TrieNode{

public:

    TrieNode *child[ALPHABET_SIZE];

    int noOfCount = 0;

    TrieNode(){

    int noOfCount = 0;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		child[i] = NULL;

    }


    bool containes(TrieNode * node , char c){
    	return child[c - 'a'] != NULL;
    }

    void put(char c , TrieNode * newNode){
    	child[c - 'a'] = newNode;
    }

    TrieNode * getNext(char c){
    	return child[c - 'a'];
    }


    void increaseCountOfNewCharacter(){

    	noOfCount++;
    }
   

    int getCountOfNewCharacter(){

    	return noOfCount;
    }

    bool setFlag(){
    	return true;
    }
};


void insert(TrieNode *root, string key)
{
    TrieNode *temp = root;
 
    for (int i = 0; i < key.size(); i++){

       if(!temp->containes(temp , key[i])){

	       	TrieNode * newNode = new TrieNode;
	       	temp->put(key[i] , newNode);
       }
       
      // count starting of each word
       temp->increaseCountOfNewCharacter();
       temp = temp->getNext(key[i]);
    }
    
    temp->setFlag();
}
 

int startWith(TrieNode * root , string key){

	TrieNode * temp = root;

	for(int i = 0; i < key.size(); i++){

		if(temp->containes(temp , key[i])){

            temp = temp->getNext(key[i]);
		}
		else{

			return 0;
		}	
	}

	return temp->getCountOfNewCharacter();
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif


// Taking Input

 TrieNode *root = new TrieNode;


insert(root , "pay");
insert(root , "attentions");
insert(root , "practice");
insert(root , "attend");



 cout << "Search : " << startWith(root ,"at") << endl;




     



   
}