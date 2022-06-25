// Using List
// --------------
// In this question we have to keep track of the most least recently used item in the cache. I have designed the cache using
// list and map in C++.
// We do it by following the steps below :-

// When we access an item in the cache it moves to the front of the list as it is the most recently used item.
// When we want to remove an item we remove it from the last of the list as it is the least recently used item in the cache.
// When we insert an item we insert it into the front of the list as it is the most recently used item.
// The idea is to store the keys in the map and its corrosponding values into the list...
// Note : splice() function here takes the element at the m[key] and places it at the beginning of the list...

class LRUCache
{
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int size;
    LRUCache(int capacity)
    {
        size = capacity;
    }
    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }
    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }
        if (l.size() == size)
        {
            auto d_key = l.back().first;
            l.pop_back();
            m.erase(d_key);
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};