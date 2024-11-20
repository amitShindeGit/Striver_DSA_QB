class MyStack {
private:
    queue<int> first;  // Main queue
    queue<int> second; // Helper queue
public:
    MyStack() {}

    void push(int x) {
        second.push(x);

        while (!first.empty()) {
            second.push(first.front());
            first.pop();
        }

        queue<int> tempQ = first;
        first = second;
        second = tempQ;
    }

    int pop() {
        int frontElement = first.front();
        first.pop();
        return frontElement;
    }

    int top() {return first.front();}

    bool empty() {return first.empty();}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */