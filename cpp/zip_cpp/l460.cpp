#include "../tool/helper.cpp"
using namespace std;

/*
description:
1. set 标记节点顺序
2. map 找到节点
*/
class LFUCache {
  public:
    class Node {
      public:
        int key;
        int val;
        int cnt;
        Node(int k, int v, int t) : key(k), val(v), cnt(1) {}
    };
    int cap{0};
    int time{0};
    int mincnt{0};
    unordered_map<int, list<Node>> freq;
    unordered_map<int, list<Node>::iterator> mp;
    LFUCache(int c) : cap(c) {}
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        freq[it->second->cnt].erase(it->second);
        if (freq.find(++(it->second->cnt)) != freq.end()) {
            freq[it->second->cnt].push_back(it->second);
        }
        else {
            // freq[it->second->cnt] = list<Node>(it->second);
        }
        return it->second->val;
    }
    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        auto it = mp.find(key);
        if (it == mp.end()) {
            auto first = freq.begin();
        }
    }
};

/*
description:
1. set 标记节点顺序
2. map 找到节点
*/
class LFUCache2 {
  public:
    class Node {
      public:
        int key;
        int val;
        int time;
        int cnt;
        Node(int k, int v, int t) : key(k), val(v), time(t), cnt(1){};
        bool operator<(const Node& node) const {
            return cnt == node.cnt ? time < node.time : cnt < node.cnt;
        }
        Node(){};
    };
    int cap{0};
    int time{0};
    set<Node> s;
    unordered_map<int, Node> mp;

    LFUCache2(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        s.erase(it->second);
        it->second.time = ++time;
        it->second.cnt += 1;
        s.insert(it->second);
        return it->second.val;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        auto it = mp.find(key);
        if (it != mp.end()) {
            s.erase(it->second);
            it->second.val = value;
            it->second.time = ++time;
            it->second.cnt += 1;
            s.insert(it->second);
        }
        else {
            if (mp.size() == cap) {
                mp.erase(s.begin()->key);
                s.erase(s.begin());
            }
            Node node(key, value, ++time);
            mp[key] = node;
            s.insert(node);
        }
    }
};

/*

 old:new 2:2 3:3 4:4


description:
1. list 标记节点顺序
2. map 找到节点
*/
class LFUCache1 {
  public:
    class Node {
      public:
        int key;
        int val;
        int cnt;
        Node(int k, int v) {
            key = k;
            val = v;
            cnt = 0;
        }
    };
    list<Node> seq;
    map<int, list<Node>::iterator> mp;
    int cap;
    LFUCache1(int capacity) {
        cap = capacity;
    }

    void updatepostion(int key) {
        //把key的位置add
        mp[key]->cnt += 1;
        list<Node>::iterator dest = seq.begin();
        while (dest != seq.end() && dest->cnt > mp[key]->cnt) {
            dest = next(dest, 1);
        }
        seq.splice(dest, seq, mp[key]);
    }
    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            updatepostion(key);
            return mp[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            updatepostion(key);
            mp[key]->val = value;
        }
        else {
            if (seq.size() == cap) {
                if (cap == 0)
                    return;
                mp.erase(seq.back().key);
                seq.pop_back();
            }
            seq.push_back(Node(key, value));
            mp[key] = next(seq.begin(), seq.size() - 1);

            updatepostion(key);
        }
    }
};

int main() {
    LFUCache LFUCache(3);
    LFUCache.put(2, 2);               // 缓存是 {2=2 1, 1=1 1}
    LFUCache.put(1, 1);               // 缓存是 {1=1 1}
    cout << LFUCache.get(2) << endl;  // 返回 1 缓存是 {1=1 2, 2=2 1}
    cout << LFUCache.get(1) << endl;  // 返回 1 缓存是 {1=1 2, 2=2 1}
    cout << LFUCache.get(2) << endl;  // 返回 -1 (未找到)
    LFUCache.put(3, 3);               // 该操作会使得关键字 2 作废，缓存是 {1=1 2, 3=3 1}
    LFUCache.put(4, 4);               // 该操作会使得关键字 1 作废，缓存是 {1=1 2, 4=4 1}
    cout << LFUCache.get(3) << endl;  // 返回 -1 (未找到)
    cout << LFUCache.get(2) << endl;  // 返回 -1 (未找到)
    cout << LFUCache.get(1) << endl;  // 返回 1 {1=1 3, 4=4 1}
    cout << LFUCache.get(4) << endl;  // 返回 4 {1=1 3, 4=4 2}
    // LFUCache.put(0, 0);
    // LFUCache.put(1, 0);
    // cout << LFUCache.get(0) << endl;
    return 0;
}
