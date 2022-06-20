#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class LRUCache {
  public:
    list<pair<int, int>> freq;
    map<int, list<pair<int, int>>::iterator> mp;
    int cap{0};
    LRUCache(int c) : cap(c) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        freq.splice(freq.begin(), freq, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        auto it = mp.find(key);
        if (it != mp.end()) {
            //找到了 1 删除 list 2 重置mp
            freq.erase(it->second);
        }
        else if (cap == mp.size()) {
            // 1删除back  2重置mp
            mp.erase(freq.back().first);
            freq.pop_back();
        }
        freq.push_front(make_pair(key, value));
        mp[key] = freq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);               // 缓存是 {1=1}
    lRUCache.put(2, 2);               // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) << endl;  // 返回 1
    lRUCache.put(3, 3);               // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2) << endl;  // 返回 -1 (未找到)
    lRUCache.put(4, 4);               // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1) << endl;  // 返回 -1 (未找到)
    cout << lRUCache.get(3) << endl;  // 返回 3
    cout << lRUCache.get(4) << endl;  // 返回 4

    return 0;
}
