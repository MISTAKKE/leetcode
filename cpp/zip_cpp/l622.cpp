#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class MyCircularQueue
{
private:
    vector<int> data;
    int start;
    int end;
    int cap;

public:
    MyCircularQueue(int k)
    {
        cap = k + 1;
        start = 0;
        end = 0;
        data.resize(cap);
    }

    bool enQueue(int value)
    {
        //cout<<"enQueue  start:"<<start<<" end:"<<end<<" value:"<<value<<endl;
        if (isFull())
            return false;
        end = (end + 1) % cap;
        data[end] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        start = (start + 1) % cap;
        return true;
    }

    int Front()
    {
        //cout<<"Front  start:"<<start<<" end:"<<end<<" value:"<<data[(start + 1) % cap]<<endl;
        if (isEmpty())
            return -1;
        return data[(start + 1) % cap];
    }

    int Rear()
    {
        //cout<<"Rear  start:"<<start<<" end:"<<end<<" value:"<<data[end]<<endl;
        if (isEmpty())
            return -1;
        return data[end];
    }

    bool isEmpty()
    {
        if (start == end)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((end + cap - start) % cap == cap - 1)
            return true;
        return false;
    }
};

int main()
{
    MyCircularQueue circularQueue(3);
    cout << circularQueue.enQueue(1) << endl;
    cout << circularQueue.enQueue(2) << endl;
    cout << circularQueue.enQueue(3) << endl;
    cout << circularQueue.enQueue(4) << endl;
    cout << circularQueue.Rear() << endl;
    cout << circularQueue.isFull() << endl;
    cout << circularQueue.deQueue() << endl;
    cout << circularQueue.enQueue(4) << endl;
    cout << circularQueue.Rear() << endl;

    return 0;
}


// circularQueue.enQueue(1);  // 返回 true
// circularQueue.enQueue(2);  // 返回 true
// circularQueue.enQueue(3);  // 返回 true
// circularQueue.enQueue(4);  // 返回 false，队列已满
// circularQueue.Rear();  // 返回 3
// circularQueue.isFull();  // 返回 true
// circularQueue.deQueue();  // 返回 true
// circularQueue.enQueue(4);  // 返回 true
// circularQueue.Rear();  // 返回 4
