class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);

        if(q.empty()){
            return;
        }

        for(int i=0; i<q.size() - 1; i++){
            int frontElement = q.front();
            q.pop();
            
            q.push(frontElement);
        }
    }
    
    int pop() {
        int frontElement = q.front();

        q.pop();

        return frontElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */