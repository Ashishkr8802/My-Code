class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size() - 1;
        while(size) {
            int element = q.front();
            q.pop();
            q.push(element);
            size--;
        }
        int toDelete = q.front();
        q.pop();
        return toDelete;
    }
    
    int top() {
        int size = q.size()-1;
        while(size){
            int element = q.front();q.pop();
            q.push(element);
            size--;
        }
        int toDelete = q.front();q.pop();
        q.push(toDelete);
        return toDelete;
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