#include "../tool/helper.cpp"
using namespace std;

/*
description:
*/
// 19.27
class LRUCache {
private:
    int cap{0};
    list<pair<int,int>> seq;
    map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int c):cap(c){}
    void put(int key, int val) {
        auto it = mp.find(key);
        if(it == mp.end()){
            seq.push_front(make_pair(key, val));
            mp[key] = seq.begin();
            if(mp.size()==cap){
                mp.erase(seq.back().first);
                seq.pop_back();
            }
        }
        seq.splice(seq.begin(), seq, it->second);
        it->second->second = val;
    }
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()){
            return -1;
        }
        seq.splice(seq.begin(), seq, it->second);
        return it->second->second;
    }
};

class LRUCache2 {
  private:
    int cap{0};
    list<pair<int, int>> seq;
    map<int, list<pair<int, int>>::iterator> mp;

  public:
    LRUCache2(int c) : cap(c) {}
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        seq.splice(seq.begin(), seq, it->second);
        return it->second->second;
    }
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            seq.splice(seq.begin(), seq, it->second);
            it->second->second = value;
            return;
        }
        seq.push_front(make_pair(key, value));
        mp[key] = seq.begin();
        if (mp.size() > cap) {
            mp.erase(seq.back().first);
            seq.pop_back();
        }
    }
};

class LRUCache4 {
  public:
    /*
        用list标记顺序，头部是最近访问的节点
        用mp找到list节点，标记是否在其中
        空间复杂度O(N) 时间复杂度 O(logN)
        LFU 460
    */
    map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> seq;
    int cap;
    LRUCache4(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            seq.splice(seq.begin(), seq, it->second);  //把对应的iterator放到头部
            /**
             * 1 splice(target_container itreator_postion, from_container_itreator_toend);
             * 2 splice(target_container itreator_postion, from_container, from_itreator); //
             * 3 list::splice(target_contailer iteartor_postion, from_container, from_itera, end_itera);
             */
            return it->second->second;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            seq.splice(seq.begin(), seq, it->second);  //把对应的iterator放到头部
            it->second->second = value;
            return;
        }
        seq.push_front(make_pair(key, value));
        mp[key] = seq.begin();
        if (mp.size() > cap) {
            mp.erase(seq.back().first);
            seq.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 提示：

1 <= capacity <= 5
0 <= key <= 5
0 <= value <= 104
最多调用 3 * 10^4 次 get 和 put
*/

int main() {
    LRUCache2 lRUCache(2);
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
