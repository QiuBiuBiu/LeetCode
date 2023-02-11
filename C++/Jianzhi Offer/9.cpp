/*
剑指 Offer 09. 用两个栈实现队列
    用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
    分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
*/

class CQueue {
public:
    stack<int> sk1, sk2;
    CQueue() {
        sk1 = stack<int>();
        sk2 = stack<int>();
    }
    
    void appendTail(int value) {
        if (sk2.empty()) sk1.push(value);
        else 
        {
            while (!sk2.empty())
            {
                int val = sk2.top();
                sk1.push(val);
                sk2.pop();
            }
            sk1.push(value);
        }
    }
    
    int deleteHead() {
        while (!sk1.empty())
        {
            int val = sk1.top();
            sk2.push(val);
            sk1.pop();
        }

        if (sk2.empty()) return -1; // 弹出前做检查
        else
        {
            int val = sk2.top();
            sk2.pop();
            return val;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */