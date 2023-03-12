// 剑指 Offer 59 - II. 队列的最大值


/*
    单调队列
    使用一个辅助队列dq，使得队列q的函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)
    主要思路源自于59_1.cpp和30.cpp，这里不做过多介绍。
*/

class MaxQueue {
public:
    queue<int> q;
    deque<int> dq;
    MaxQueue() {

    }
    
    int max_value() {
        if (q.empty()) return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        int cnt = 0;
        while (!dq.empty() && dq.back() < value) // 参照单调队列的设计，用当前滑动窗口的最大值替代较小值
        {
            dq.pop_back();
            cnt++;
        }
        dq.push_back(value);
        while (cnt--) dq.push_back(value); // 一开始的做法是用最大值来替代队列里的较小值，会使得dq中的元素和q中的一致，没有index“失效”判断机制来减少dq中元素的存储
    }
    
    int pop_front() {
        if (q.empty()) return -1;

        dq.pop_front();
        int val = q.front();
        q.pop();
        return val;
    }
};

/*
    进一步优化时间复杂度
*/
class MaxQueue {
public:
    struct data {
        int val;
        int idx;
        data(int value, int index) : val(value), idx(index) {}
    };
    int push_index; // 增加index帮助判断是否某个val已经被移除了滑动窗口
    int pop_index;
    queue<int> q;
    deque<data> dq;
    MaxQueue() {
        push_index = pop_index = 0;
    }
    
    int max_value() {
        if (q.empty()) return -1;
        return dq.front().val;
    }
    
    void push_back(int value) {
        q.push(value);

        push_index++;

        data tmp = data(value, push_index);
        while (!dq.empty() && dq.back().val < value) // 减少了dq需要存储的元素，可能的最大值只存储一次
        {
            dq.pop_back();
        }
        dq.push_back(tmp);
    }
    
    int pop_front() {
        if (q.empty()) return -1;

        pop_index++;

        while (!dq.empty() && dq.front().idx <= pop_index) dq.pop_front(); // 用index来移除"失效"元素

        int val = q.front();
        q.pop();
        return val;
    }
};