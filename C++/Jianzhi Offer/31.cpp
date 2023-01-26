// 剑指 Offer 31. 栈的压入、弹出序列

/*
    模拟题，
    遍历pushed数组，将其放入栈中，然后尝试用栈来模拟popped序列
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sk;
        int i = 0;
        for (const auto& num : pushed)
        {
            sk.push(num);
            while (!sk.empty() && sk.top() == popped[i])
            {
                sk.pop();
                i++;
            }
        }
        return sk.empty();
    }
};