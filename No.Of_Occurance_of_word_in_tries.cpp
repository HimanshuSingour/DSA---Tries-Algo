#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// occurance of the word
 

class TrieNode{

public:

    TrieNode *child[ALPHABET_SIZE];
    int coutWordEnd = 0;
    int countPrefixs = 0;

    TrieNode(){

    int coutWordEnd = 0;
    int countPrefixs = 0;

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

    void increaseCountSiffex(){
    	coutWordEnd++;
    }

    void increateCountPreflex(){
    	countPrefixs++;
    }

    int getCountWordEnd(){

    	return coutWordEnd;
    }

    int getCountPrefexes(){

    	return countPrefixs;

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
       
       temp = temp->getNext(key[i]);
    }
    
    // count end of the each word 
    temp->increaseCountSiffex();
}
 


int countWOrdEqualTo(TrieNode *root, string key){
     TrieNode *temp = root;
 
    for (int i = 0; i < key.size(); i++){

        if (temp->containes(temp , key[i])){
        	 temp = temp->getNext(key[i]);
        }
        else{

        	return 0;
        }
       
    }
 
    return temp->getCountWordEnd();
}



int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif


// Taking Input

 TrieNode *root = new TrieNode;

 insert(root , "neha");
 insert(root , "neha");
 insert(root , "nelu");
 insert(root , "neha");
 insert(root , "neha");
 insert(root , "neha");
 insert(root , "nelu");
 insert(root , "neha");




 cout << "Search : " << countWOrdEqualTo(root ,"neha") << endl;




     



   
}