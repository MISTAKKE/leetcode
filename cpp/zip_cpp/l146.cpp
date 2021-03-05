#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class LRUCache
{
/*
    两个数组，data记录数字，-1是不存在  非-1是存在
    sequence是时间值，用于标记新旧，越大约新
*/
public:
    vector<int> data;
    vector<int> sequence;
    int cap;
    int time;
    int nowsize;
    LRUCache(int capacity)
    {
        data.resize(3001, -1);
        sequence.resize(3001, -1);
        cap = capacity;
        time = 0;
        nowsize = 0;
    }
    int get(int key)
    {
        if (data[key] == -1)
            return -1;
        sequence[key] = ++time;
        return data[key];
    }

    void put(int key, int value)
    {
        if (nowsize == cap && data[key] == -1)
        {
            int minval = 300000;
            int mini = 3000;
            for (int i = 0; i <= 3000; ++i)
            {
                if (data[i] != -1)
                {
                    if (sequence[i] < minval)
                    {
                        mini = i;
                        minval = sequence[i];
                    }
                }
            }
            data[mini] = -1;
            sequence[mini] = -1;
            data[key] = value;
            sequence[key] = ++time;
        }
        else
        {
            if (data[key] == -1)
                nowsize += 1;
            data[key] = value;
            sequence[key] = ++time;
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

int main()
{

    LRUCache lRUCache(2);
    lRUCache.put(1, 1);              // 缓存是 {1=1}
    lRUCache.put(2, 2);              // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) << endl; // 返回 1
    lRUCache.put(3, 3);              // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2) << endl; // 返回 -1 (未找到)
    lRUCache.put(4, 4);              // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1) << endl; // 返回 -1 (未找到)
    cout << lRUCache.get(3) << endl; // 返回 3
    cout << lRUCache.get(4) << endl; // 返回 4

    return 0;
}
