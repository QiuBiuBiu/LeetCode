// 264. 丑数 II
// 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
// 丑数 就是只包含质因数 2、3 和/或 5 的正整数。


/*
    由前至后，T=O(n)
    当我们已知第一个丑数为1时，那么第二个丑数可以由1*2，1*3，1*5推导出来，即后面的丑数可以由前面的丑数乘以2,3或者5算出来，接下来考虑下面的问题：
    1）如何保证后面的丑数是按从小到大的顺序推导出来的？
    2）会不会存在一个丑数可以由a*2，b*3以及c*5中的两到三个共同推出？
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 1, b = 1, c = 1;
        vector<int> f(n + 1);
        f[1] = 1;
        int k = 1;
        while (k < n)
        {
            int newUgly = min(f[a] * 2, min(f[b] * 3, f[c] * 5));
            if (newUgly == f[a] * 2) ++a;
            if (newUgly == f[b] * 3) ++b;
            if (newUgly == f[c] * 5) ++c;
            f[++k] = newUgly;
        }
        return f[n];
    }
};

/*
    最小堆，T=O(nlogn)
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> heap;
        unordered_set<long long> st;
        vector<long long> factors {2, 3, 5};
        heap.push(1);
        int num = heap.top();
        for (int i = 1; i < n; i++)
        {
            for (const auto& factor : factors)
            {
                long long newUgly = factor * num;
                if (st.find(newUgly) == st.end()) // 堆中元素可能有重复，用set来去重
                {
                    st.insert(newUgly);
                    heap.push(newUgly);
                }
            }
            heap.pop();
            num = heap.top(); // 从堆中取出一个元素O(logn)
        }
        return num;
    }
};