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
        this->maxSize = maxSize>1 ? maxSize : 1;
    }

    //Three operations
    void insert(string key,int val){

        //2 cases
        if(mp.count(key) != 0){
            //exists so replace the value in list
            auto it = m[key] //address
            it->val = val;
        }
        else{
            //not present
            //check cache full or not, yes remove LRU item
            if(l.size ==maxSize){
                Node last = l.back();
                m.erase(last.key); //remove from the hashmap
                l.pop_back();//remove the last ele from list
            }

            Node n(key,val);
            l.push_front(n);
            mp[key] = l.begin(); //l.begin() gives address of the new node
        }


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