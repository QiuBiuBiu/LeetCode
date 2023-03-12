// 155. 最小栈


/*
    单调栈
    见 剑指 Offer 30
*/
class MinStack {
public:
    stack<int> sk;
    stack<int> skm;
    MinStack() {
        sk = stack<int>();
        skm = stack<int>();
    }
    
    void push(int val) {
        sk.push(val);
        if (skm.empty() || skm.top() > val) skm.push(val);
        else skm.push(skm.top());
    }
    
    void pop() {
        sk.pop();
        skm.pop();
    }
    
    int top() {
        if (!sk.empty()) return sk.top();
        else return -1;
    }
    
    int getMin() {
        if (!skm.empty()) return skm.top();
        else return -1;
    }
};