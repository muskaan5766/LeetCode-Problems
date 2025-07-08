class MyQueue {
public:
    stack<int> s1; // Queue
    MyQueue() {}

    void operation2(stack<int>& s1, int& f) {
        if (!s1.size()) {
            return;
        }

        int top = s1.top();
        s1.pop();

        if (!s1.size()) {
            f = top;
        }

        operation2(s1, f);

        // BT
        s1.push(top);
    }

    // 1
    void push(int x) { s1.push(x); }

    void operation(stack<int>& s1, int& front) {
        stack<int> s2;
        while (!s1.empty()) {
            int t = s1.top();
            s1.pop();

            if (s1.size()) {
                s2.push(t);
            } else {
                front = t;
            }
        }

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
 
    // 2
    int pop() {
        int front;
        operation(s1, front);
        return front;
    }

    int peek() {
        int f;
        operation2(s1, f);
        return f;
    }

    bool empty() { return s1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */