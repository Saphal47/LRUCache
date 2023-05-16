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
            auto it = mp[key]; //address
            it->val = val;
        }
        else{
            //not present
            //check cache full or not, yes remove LRU item
            if(l.size() ==maxSize){
                Node last = l.back();
                mp.erase(last.key); //remove from the hashmap
                l.pop_back();//remove the last ele from list
            }

            Node n(key,val);
            l.push_front(n);
            mp[key] = l.begin(); //l.begin() gives address of the new node
        }


    }

    //getValue
    int* getValue(string key){

        //check if key is present 
        if(mp.count(key) != 0){
            //get address from the hashmap
            auto it = mp[key];
            //Now this node should come to top as used most recently

            int value = it->val;
            l.push_front(*it);
            l.erase(it);

            //update addresss
            mp[key] = l.begin();
            return &l.begin()->val;
        }

        //in Cache key may be absent so return NULL 
        return NULL;

    }

    string getMostRecentKey(){
        //head of LL
        return l.front().key;
    }

};


int main(){
    
    LRUCache lru(3);
    lru.insert("mango",10);
    lru.insert("apple",30);
    lru.insert("guava",70);

    cout<<lru.getMostRecentKey()<<endl;

    lru.insert("mango",40);
    cout<<lru.getMostRecentKey()<<endl;

    int *order = lru.getValue("mango");
    if(order != NULL){
        cout<<"Mango: "<<*order<<endl;
    }

    lru.insert("banana",20);
    cout<<lru.getMostRecentKey()<<endl;

    if(lru.getValue("apple")==NULL){
        cout<<"Apple DNE";
    }
    if(lru.getValue("guava")==NULL){
        cout<<"Guava DNE";
    }
    if(lru.getValue("banana")==NULL){
        cout<<"Banana DNE";
    }
    if(lru.getValue("mango")==NULL){
        cout<<"Mango DNE";
    }

    return 0;
}