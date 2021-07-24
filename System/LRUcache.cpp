#include <bits/stdc++.h>
using namespace std;

class LRUcache {
  int capacity;
  list<int> recent;
  unordered_map<int, int> cache;
  unordered_map<int, list<int>::iterator> pos;

  void use(int key) {
    if(pos.find(key) != pos.end()) {
      recent.erase(pos[key]);
    } else if(recent.size() >= capacity) {
      int old = recent.back();
      recent.pop_back();
      cache.erase(old);
      pos.erase(old);
    }
    recent.push_front(key);
    pos[key] = recent.begin();
  }

public:
  LRUcache(int n): capacity(n) {}

  int get(int key) {
    if(cache.find(key) != cache.end()) {
      use(key);
      return cache[key];
    }
    return -1;
  }

  void put(int key, int value) {
    use(key);
    cache[key] = value;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  LRUcache ca(4); 
  
  ca.refer(1); 
  ca.refer(2); 
  ca.refer(3); 
  ca.refer(1); 
  ca.refer(4); 
  ca.refer(5); 
  ca.display();
  return 0;
}