#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class MyQueue {
  public:
    stack<int> inqueue;
    stack<int> outqueue;
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        truetoinqueue();
        inqueue.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        truetooutqueue();
        int top = outqueue.top();
        outqueue.pop();
        return top;
    }

    int peek() {
        truetooutqueue();
        return outqueue.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return outqueue.empty() && inqueue.empty();
    }
    void truetoinqueue() {
        while (!outqueue.empty()) {
            int& tmp = outqueue.top();
            inqueue.push(tmp);
            outqueue.pop();
        }
    }
    void truetooutqueue() {
        while (!inqueue.empty()) {
            int& tmp = inqueue.top();
            outqueue.push(tmp);
            inqueue.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    Solution MyQueue;

    return 0;
}
