#include<bits/stdc++.h>
using namespace std;


 

class TrieNode{

public:

    TrieNode *child[ALPHABET_SIZE];
    bool isLast;

    TrieNode(){
        isLast = false;

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

    void setFlag(){
    	isLast = true;
    }

};


void insert(TrieNode *root, string key)
{
    TrieNode *temp = root;
 
    for (int i = 0; i < key.length(); i++)
    {
       if(!temp->containes(temp , key[i])){

	       	TrieNode * newNode = new TrieNode;
	       	temp->put(key[i] , newNode);
       }

       temp = temp->getNext(key[i]);
    }

    temp->setFlag();
}
 
 
bool search(TrieNode *root, string key)
{
     TrieNode *temp = root;
 
    for (int i = 0; i < key.length(); i++)
    {

        if (!temp->containes(temp , key[i]))
            return false;
 
        temp = temp->getNext(key[i]);
    }
 
    return (temp->isLast);
}


bool startWith(TrieNode * root , string key){

	TrieNode * temp = root;

	for(int i = 0; i < key.size(); i++){

		if(temp->containes(temp , key[i])){

            temp = temp->getNext(key[i]);
		}
		else{

			return false;
		}	
	}

	return true;
}



 

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif


// Taking Input


 TrieNode *root = new TrieNode;

 insert(root , "Himash");
 insert(root , "Hellow");
 insert(root , "Himsdc");


 cout << "Search : " << search(root ,"Himash") << endl;
 cout << "Start with :" << startWith(root , "H") << endl;


 cout << countWithEqualToWords(root , "Himsdc") << endl;




     



   
}