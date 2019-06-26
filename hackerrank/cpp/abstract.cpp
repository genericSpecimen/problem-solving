#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

#include <list>
class LRUCache : public Cache {
public:
    std::list<int> keys; // --keys.end() is the LRU, keys.begin() is the MRU   
    LRUCache(int capacity) {
        this->cp = capacity;
    }
    
    void set(int key, int value) {
        auto it = std::find(keys.begin(), keys.end(), key);
        if(it != keys.end()) {
            // key already present, just update the value in the map and bring the key to the front of keys
            keys.erase(it);
            keys.push_front(key);
            mp[key] = new Node(key,value);
        } else {
            // key not present
            if(keys.size() < cp) {
                keys.push_front(key);
                mp[key] = new Node(key,value);
            } else {
                // remove the LRU key
                auto it = --keys.end();
                int key_to_remove = *it;
                keys.erase(it);
                mp.erase(key_to_remove);

                // add the new key at the front
                keys.push_front(key);
                mp[key] = new Node(key,value);
            }
        }
    }

    int get(int key) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            // cache hit
            // update the keys list
            auto it = std::find(keys.begin(), keys.end(), key);
            keys.erase(it);
            keys.push_front(key);
            return mp[key]->value;
        }
        else {
            // cache miss
            return -1;
        }
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
