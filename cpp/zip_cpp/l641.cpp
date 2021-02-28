#include "../tool/helper.cpp"
using namespace std;

/*
description:

MyCircularDeque(k)：构造函数,双端队列的大小为k。
insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
isEmpty()：检查双端队列是否为空。
isFull()：检查双端队列是否满了。

所有值的范围为 [1, 1000]
操作次数的范围为 [1, 1000]
请不要使用内置的双端队列库。
*/

//Class Solution
class MyCircularDeque
{
public:
    vector<int> data;
    int cap;
    int start;
    int end;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        cap = k + 1;
        start = 0;
        end = 0;
        data.resize(cap);
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        end = (end + 1) % cap;
        data[end] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;
        data[start] = value;
        start = (start - 1 + cap) % cap;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        end = (end - 1 + cap) % cap;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        start = (start + 1) % cap;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (isEmpty())
            return -1;
        return data[end];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (isEmpty())
            return -1;
        return data[(start + 1) % cap];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        if (start == end)
            return true;
        return false;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        if ((end + cap - start) % cap == cap - 1)
            return true;
        return false;
    }
};

int main()
{
    MyCircularDeque circularDeque(3);             // 设置容量大小为3
    cout << circularDeque.insertLast(1) << endl;  // 返回 true
    cout << circularDeque.insertLast(2) << endl;  // 返回 true
    cout << circularDeque.insertFront(3) << endl; // 返回 true
    cout << circularDeque.insertFront(4) << endl; // 已经满了，返回 false
    cout << circularDeque.getRear() << endl;      // 返回 2
    cout << circularDeque.isFull() << endl;       // 返回 true
    cout << circularDeque.deleteLast() << endl;   // 返回 true
    cout << circularDeque.insertFront(4) << endl; // 返回 true
    cout << circularDeque.getFront() << endl;     // 返回 4

    return 0;
}

// [ "MyCircularDeque", "insertFront", "insertLast", "getFront", "insertLast", "getFront", "insertFront", "getRear", "getFront", "getFront", "deleteLast", "getRear" ]
//     [[5], [7], [0], [], [3], [], [9], [], [], [], [], []]

//     [null, true, true, 0, true, 0, true, 3, 9, 9, true, 0] 预期结果：
//         [null, true, true, 7, true, 7, true, 3, 9, 9, true, 0]

//     size = 5

//     insertFront 7 insertLast 0 get getFront 0