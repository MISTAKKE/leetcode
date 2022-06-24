#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class AllOne {
  public:
    class Node {
      public:
        set<string> vec{};
        int cnt{0};
        Node* prev{nullptr};
        Node* next{nullptr};
        Node(int c) : cnt(c) {}
    };
    map<string, Node*> mp;
    Node* head;
    AllOne() {
        head = new Node(0);
        head->next = head;
        head->prev = head;
    }
    ~AllOne() {
        Node* t = head->next;
        while (t != head) {
            Node* temp = t->next;
            delete t;
            t = temp;
        }
        delete head;
    }
    void inc(string key) {
        auto it = mp.find(key);
        Node* now = head;
        if (it != mp.end()) {
            now = it->second;
        }
        // 在now后增加新的(可能加节点)
        if (now->next == head || now->next->cnt != now->cnt + 1) {
            Node* t = new Node(now->cnt + 1);
            t->next = now->next;
            now->next->prev = t;
            now->next = t;
            t->prev = now;
        }
        now->next->vec.insert(key);
        mp[key] = now->next;
        // 删除旧的(可能删节点)
        if (now->cnt != 0) {
            now->vec.erase(key);
            if (now->vec.size() == 0) {
                now->prev->next = now->next;
                now->next->prev = now->prev;
                delete now;
            }
        }
    }
    void dec(string key) {
        Node* now = mp[key];
        //在now前新增一个(可能加节点 如果当前cnt==1就不加)
        if ((now->prev == head || now->prev->cnt != now->cnt - 1) && now->cnt != 1) {
            Node* t = new Node(now->cnt - 1);
            now->prev->next = t;
            t->prev = now->prev;
            now->prev = t;
            t->next = now;
        }
        if (now->cnt != 1) {
            now->prev->vec.insert(key);
            mp[key] = now->prev;
        }
        else {
            mp.erase(key);
        }
        //删除旧的(可能删)
        now->vec.erase(key);
        if (now->vec.size() == 0) {
            now->prev->next = now->next;
            now->next->prev = now->prev;
            delete now;
        }
    }
    string getMaxKey() {
        if (head->prev != head) {
            return *(head->prev->vec.begin());
        }
        return "";
    }
    string getMinKey() {
        if (head->next != head) {
            return *(head->next->vec.begin());
        }
        return "";
    }
};

// 2 maps
class AllOne1 {
  public:
    map<string, int> mp;
    map<int, list<string>> freq;
    AllOne1() {}

    void inc(string key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            mp[key] = 1;
        }
        else {
            mp[key] += 1;
        }
        auto it2 = freq.find(mp[key]);
        if (it2 == freq.end()) {
            freq[mp[key]] = list<string>{key};
        }
        else {
            freq[mp[key]].push_back(key);
        }
        if (mp[key] > 1) {
            freq[mp[key] - 1].remove(key);
            if (freq[mp[key] - 1].size() == 0) {
                freq.erase(mp[key] - 1);
            }
        }
    }

    void dec(string key) {
        freq[mp[key]].remove(key);
        if (freq[mp[key]].size() == 0) {
            freq.erase(mp[key]);
        }
        mp[key] -= 1;
        if (mp[key] == 0) {
            return;
        }
        auto it2 = freq.find(mp[key]);
        if (it2 == freq.end()) {
            freq[mp[key]] = list<string>{key};
        }
        else {
            freq[mp[key]].push_back(key);
        }
    }

    string getMaxKey() {
        if (freq.size() == 0) {
            return "";
        }
        return freq.rbegin()->second.front();
    }

    string getMinKey() {
        if (freq.size() == 0) {
            return "";
        }
        return freq.begin()->second.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    AllOne* obj = new AllOne();
    obj->inc("hello");
    obj->inc("hello");
    cout << obj->getMaxKey() << endl;
    cout << obj->getMinKey() << endl;

    obj->inc("leet");
    cout << obj->getMaxKey() << endl;
    cout << obj->getMinKey() << endl;

    // case1
    //  for (auto c : obj->freq) {
    //      cout << "cnt:" << c.first << " size:" << c.second.size() << endl;
    //  }

    // case2
    AllOne::Node* t = obj->head;
    cout << "cnt:" << t->cnt << " size:" << t->vec.size() << endl;
    t = t->next;
    while (t != obj->head) {
        cout << "cnt:" << t->cnt << " size:" << t->vec.size() << endl;
        t = t->next;
    }
    return 0;
}