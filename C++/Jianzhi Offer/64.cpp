// 剑指 Offer 64. 求1+2+…+n

/*
    1）利用静态成员变量和构造函数求解
*/

class Solution {
public:
    Solution() {
        k += 1;
        sum += k;
    }
    int sumNums(int n) {
        clear();    // leetcode多测试样例，会导致sumNums()会被多次调用，因此需要在每次调用前把静态成员变量置零

        vector<Solution> res(n);
        return sum;
    }
    void clear() {
        sum = k = 0;
    }
    static int k;
    static int sum;
};

int Solution::k = 0;
int Solution::sum = 0;


/*
    2）逻辑运算符的短路效应+递归
*/
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1)); // 当n=0时，&&运算符的左边为false，因此右边不会计算
        return n;
    }
};