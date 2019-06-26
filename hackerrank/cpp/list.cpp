#include <iostream>
#include <list>
#include <algorithm>
#include <map>

class LRUCache {
public:
    int capacity;
    std::list<int> cache;
    std::map<int, std::list<int>::iterator> mp;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void set(int key, int value) {
        //cache.push_back(value);
        //mp[key] = (--cache.end());
        if(cache.size() == capacity) {
            // erase the least recently used entry
            int a = *cache.end();
            cache.pop_back();
            auto it = mp.find(a);
            if(it != mp.end()) mp.erase(it);
        } else {
            cache.push_front(value);
            mp[key] = cache.begin();
        }
    }
    int get(int key) {
        if(mp.find(key) != mp.end()) return *(mp[key]);
        else return -1;
    }
};

int main() {
   int n, capacity,i;
   std::cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      std::string command;
      std::cin >> command;
      if(command == "get") {
         int key;
         std::cin >> key;
         std::cout << l.get(key) << std::endl;
      } 
      else if(command == "set") {
         int key, value;
         std::cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}