#include "../tool/helper.cpp"
using namespace std;

/*
description:
1. set 标记节点顺序
2. map 找到节点
*/
// 23.45
class LFUCache {
  public:
    class Node {
        int key;
        int val;
        int cnt;
        Node(int k, int v) : key(k), val(v), cnt(1) {}
    };
    int cap{0};
    int minval{1};
    LFUCache(int c) : cap(c) {}
    unordered_map<int, list<Node>> freq;
    unordered_map<int, list<Node>::iterator> mp;
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }

        return it->second->val;
    }
    void put(int key, int value) {}
};
//再写一次
class LFUCache3 {
  public:
    class Node {
      public:
        int key;
        int val;
        int cnt;
        Node(int k, int v) : key(k), val(v), cnt(1) {}
    };
    int cap{0};
    int mincnt{0};
    unordered_map<int, list<Node>> freq;          // cnt: list<node>
    unordered_map<int, list<Node>::iterator> mp;  // key: *node
    LFUCache3(int c) : cap(c) {}
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        //将下一层的node 移动到上一层
        freq[it->second->cnt + 1].splice(freq[it->second->cnt + 1].begin(), freq[it->second->cnt], it->second);
        //维护最小的cnt
        if (mincnt == it->second->cnt && freq[it->second->cnt].size() == 0) {
            mincnt += 1;
        }
        it->second->cnt += 1;
        return it->second->val;
    }
    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        auto it = mp.find(key);
        if (it == mp.end()) {
            if (cap == mp.size()) {
                mp.erase(freq[mincnt].back().key);
                freq[mincnt].pop_back();
            }
            Node node(key, value);
            mincnt = 1;
            freq[mincnt].insert(freq[mincnt].begin(), node);
            mp[key] = freq[mincnt].begin();
        }
        else {
            //将下一层的node 移动到上一层
            freq[it->second->cnt + 1].splice(freq[it->second->cnt + 1].begin(), freq[it->second->cnt], it->second);
            //维护最小的cnt
            if (mincnt == it->second->cnt && freq[it->second->cnt].size() == 0) {
                mincnt += 1;
            }
            mp[key]->cnt += 1;
            mp[key]->val = value;
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
    LFUCache LFUCache(10);
    vector<vector<int>> vec = {
        {10, 13}, {3, 17}, {6, 11}, {10, 5}, {9, 10},  {13},    {2, 19}, {2},     {3},     {5, 25},  {8},     {9, 22},
        {5, 5},   {1, 30}, {11},    {9, 12}, {7},      {5},     {8},     {9},     {4, 30}, {9, 3},   {9},     {10},
        {10},     {6, 14}, {3, 1},  {3},     {10, 11}, {8},     {2, 14}, {1},     {5},     {4},      {11, 4}, {12, 24},
        {5, 18},  {13},    {7, 23}, {8},     {12},     {3, 27}, {2, 12}, {5},     {2, 9},  {13, 4},  {8, 18}, {1, 7},
        {6},      {9, 29}, {8, 21}, {5},     {6, 30},  {1, 12}, {10},    {4, 15}, {7, 22}, {11, 26}, {8, 17}, {9, 29},
    };

    // vector<vector<int>> vec = {
    //     {10, 13}, {3, 17}, {6, 11},  {10, 5},  {9, 10}, {13},    {2, 19},  {2},      {3},      {5, 25}, {8},
    //     {9, 22},  {5, 5},  {1, 30},  {11},     {9, 12}, {7},     {5},      {8},      {9},      {4, 30}, {9, 3},
    //     {9},      {10},    {10},     {6, 14},  {3, 1},  {3},     {10, 11}, {8},      {2, 14},  {1},     {5},
    //     {4},      {11, 4}, {12, 24}, {5, 18},  {13},    {7, 23}, {8},      {12},     {3, 27},  {2, 12}, {5},
    //     {2, 9},   {13, 4}, {8, 18},  {1, 7},   {6},     {9, 29}, {8, 21},  {5},      {6, 30},  {1, 12}, {10},
    //     {4, 15},  {7, 22}, {11, 26}, {8, 17},  {9, 29}, {5},     {3, 4},   {11, 30}, {12},     {4, 29}, {3},
    //     {9},      {6},     {3, 4},   {1},      {10},    {3, 29}, {10, 28}, {1, 20},  {11, 13}, {3},     {3, 12},
    //     {3, 8},   {10, 9}, {3, 26},  {8},      {7},     {5},     {13, 17}, {2, 27},  {11, 15}, {12},    {9, 19},
    //     {2, 15},  {3, 16}, {1},      {12, 17}, {9, 1},  {6, 19}, {4},      {5},      {5},      {8, 1},  {11, 7},
    //     {5, 2},   {9, 28}, {1},      {2, 2},   {7, 4},  {4, 22}, {7, 24},  {9, 26},  {13, 28}, {11, 26}};
    int cnt = 0;
    for (auto c : vec) {
        if (c.size() == 2) {
            LFUCache.put(c[0], c[1]);
        }
        else {
            cout << "cnt:" << ++cnt << " key:" << c[0] << " val:" << LFUCache.get(c[0]) << endl;
        }
    }
    // LFUCache LFUCache(3);
    // LFUCache.put(1, 1);
    // LFUCache.put(2, 2);
    // LFUCache.put(3, 3);
    // LFUCache.put(4, 4);
    // cout << LFUCache.get(4) << endl;
    // cout << LFUCache.get(3) << endl;
    // cout << LFUCache.get(2) << endl;
    // cout << LFUCache.get(1) << endl;
    // // 4 3 2 -1

    // LFUCache LFUCache(2);
    // LFUCache.put(1, 1);               // 缓存是 {2=2 1}
    // LFUCache.put(2, 2);               // 缓存是 {1=1 1, 2=2 1}
    // cout << LFUCache.get(1) << endl;  // 返回 2 {2=2 2, 1=1 1}
    // LFUCache.put(3, 3);               // 缓存是 {2=2 3, 1=1 2, 3=3 1}
    // cout << LFUCache.get(2) << endl;  // 返回 2 {2=2 2, 1=1 1}
    // cout << LFUCache.get(3) << endl;  // 返回 2 {2=2 2, 1=1 1}
    // LFUCache.put(4, 4);               // 该操作会使得关键字 3 作废，缓存是 {2=2 3, 1=1 2, 4=4 1}
    // cout << LFUCache.get(1) << endl;  // 返回 -1 (未找到)
    // cout << LFUCache.get(3) << endl;  // 返回 2 缓存是{2=2 4, 1=1 2, 4=4 1}
    // cout << LFUCache.get(4) << endl;  // 返回 4 缓存是{2=2 4, 1=1 3, 4=4 2}

    // LFUCache LFUCache(3);
    // LFUCache.put(2, 2);               // 缓存是 {2=2 1}
    // LFUCache.put(1, 1);               // 缓存是 {1=1 1, 2=2 1}
    // cout << LFUCache.get(2) << endl;  // 返回 2 {2=2 2, 1=1 1}
    // cout << LFUCache.get(1) << endl;  // 返回 1 {1=1 2, 2=2 2}
    // cout << LFUCache.get(2) << endl;  // 返回 2 {2=2 3, 1=1 2}
    // LFUCache.put(3, 3);               // 缓存是 {2=2 3, 1=1 2, 3=3 1}
    // LFUCache.put(4, 4);               // 该操作会使得关键字 3 作废，缓存是 {2=2 3, 1=1 2, 4=4 1}
    // cout << LFUCache.get(3) << endl;  // 返回 -1 (未找到)
    // cout << LFUCache.get(2) << endl;  // 返回 2 缓存是{2=2 4, 1=1 2, 4=4 1}
    // cout << LFUCache.get(1) << endl;  // 返回 1 缓存是{2=2 4, 1=1 3, 4=4 1}
    // cout << LFUCache.get(4) << endl;  // 返回 4 缓存是{2=2 4, 1=1 3, 4=4 2}
    return 0;
}
