// 剑指 Offer 30. 包含min函数的栈

/*
    单调栈
    使用一个辅助栈skm，使得到栈sk中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
    栈skm记录栈sk中的最小值情况：
    1）当新压入的值大于skm中记录的最小值时，skm压入最小值
    2）否则skm压入当前新的最小值
*/


class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> sk;
    stack<int> skm;
    MinStack() {
        sk = stack<int>();
        skm = stack<int>();
    }
    
    void push(int x) {
        sk.push(x);
        if (!skm.empty())
        {
            if (x > skm.top()) skm.push(skm.top());
            else skm.push(x);
        }
        else skm.push(x);
    }
    
    void pop() {
        sk.pop();
        skm.pop();
    }
    
    int top() {
        return sk.top();
    }
    
    int min() {
        return skm.top();
    }
};