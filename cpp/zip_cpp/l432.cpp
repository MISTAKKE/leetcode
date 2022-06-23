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
        vector<string> vec{};
        int cnt{0};
        Node* prev{nullptr};
        Node* next{nullptr};
        Node(int c) : cnt(c) {}
    };
    map<string, Node*> mp;
    Node* head;
    AllOne() {
        head = new Node(0);
    }
    ~AllOne() {
        while (head != nullptr) {
            Node* t = head->next;
            delete head;
            head = t;
        }
    }
    void inc(string key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            // 1. key以前不存在
            // 1.1 cnt==0 为空
            if (head->next == nullptr || head->next->cnt != 1) {
                Node* = t new Node(1);
                t->next = head->next;
                if (head->next != nullptr) {
                    head->next->prev = t;
                }
                head->next = t;
                t->prev = head;
            }
            // 1.2 cnt==0 不为空
            head->next->vec.push_back(key);
            mp[key] = head->next;
            return;
        }
        else {
            // 2. key以前存在
            int key = it->first;
            Node* t = it->second;
        }
    }
    void dec(string key) {}
    string getMaxKey() {
        return "";
    }
    string getMinKey() {
        return "";
    }
};

// 2 maps
class AllOne1 {
  public:
    map<string, int> mp;
    map<int, list<string>> freq;
    AllOne() {}

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
    obj->inc("123");
    obj->inc("123");
    obj->inc("456");
    obj->inc("456");
    obj->inc("456");
    obj->dec("456");
    obj->dec("456");
    obj->dec("456");
    cout << obj->getMaxKey() << endl;
    cout << obj->getMinKey() << endl;
    // for (auto c : obj->freq) {
    //     cout << "cnt:" << c.first << " size:" << c.second.size() << endl;
    // }
    return 0;
}
