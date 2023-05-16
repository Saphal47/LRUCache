#include <bits/stdc++.h>
using namespace std;
 
//Node to store the data (doubly LL) 
class Node{
    public:
    string key;
    int val;

    Node(string key,int val){
        this->key=key;
        this->val=val;
    }
};


//LRU cache DS
class LRUCache{
    public:
        int maxSize;
        list<Node> l;
        unordered_map<string,list<Node>::iterator> mp;

    LRUCache(int maxSize){
        this->maxSize = maxSize;
    }

    //Three operations
    void insert(string key,int val){

    }

    //getValue
    int getValue(string key){

    }

    string getMostRecentKey(){
        
    }

};


int main(){
    
    return 0;
}