//https://www.geeksforgeeks.org/lru-cache-implementation/
//这个是别人的答案
class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    HIPII cache;
    LI used;
    int _capacity;
};

/* We can use stl container list as a double 
   ended queue to store the cache keys, with 
   the descending time of reference from front 
   to back and a set container to check presence 
   of a key. But to fetch the address of the key 
   in the list using find(), it takes O(N) time. 
    This can be optimized by storing a reference 
    (iterator) to each key in a hash map. */
#include <bits/stdc++.h> 
using namespace std; 
  
class LRUCache 
{ 
    // store keys of cache 
    list<int> dq; 
  
    // store references of key in cache 
    unordered_map<int, list<int>::iterator> ma; 
    int csize; //maximum capacity of cache 
  
public: 
    LRUCache(int); 
    void refer(int); 
    void display(); 
}; 
  
LRUCache::LRUCache(int n) 
{ 
    csize = n; 
} 
  
/* Refers key x with in the LRU cache */
void LRUCache::refer(int x) 
{ 
    // not present in cache 
    if (ma.find(x) == ma.end()) 
    { 
        // cache is full 
        if (dq.size() == csize) 
        { 
            //delete least recently used element 
            int last = dq.back(); 
            dq.pop_back(); 
            ma.erase(last); 
        } 
    } 
  
    // present in cache 
    else
        dq.erase(ma[x]); 
  
    // update reference 
    dq.push_front(x); 
    ma[x] = dq.begin(); 
} 
  
// display contents of cache 
void LRUCache::display() 
{ 
    for (auto it = dq.begin(); it != dq.end(); 
                                        it++) 
        cout << (*it) << " "; 
  
    cout << endl; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    LRUCache ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
  
    return 0; 
} 
// This code is contributed by Satish Srinivas 