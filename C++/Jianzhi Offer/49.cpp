// 剑指 Offer 49. 丑数

/*
    动态规划

    分析：
    在leetcode 263中 (https://leetcode.cn/problems/ugly-number/description/)，我们已有T=O(logn)的算法来判断一个数是不是丑数。
    但是当我们想知道第n个丑数时，假设它为N，那么从1~N当中的每一个数我们都需要判断是否是丑数，T=O(NlogN)，注意这里是N而不是n，且N比想象得要大很多，这个复杂度并不能让我们完成这道题。

    思路：
    当我们已知第一个丑数为1时，那么第二个丑数可以由1*2，1*3，1*5推导出来，即后面的丑数可以由前面的丑数乘以2,3或者5算出来，接下来考虑下面的问题：
    1）如何保证后面的丑数是按从小到大的顺序推导出来的？
    2）会不会存在一个丑数可以由a*2，b*3以及c*5中的两到三个共同推出？
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> f(n + 1); // dp数组记录所有丑数
        f[1] = 1;
        int k = 1, ka = 1, kb = 1, kc = 1;
        map<int, int> mp;
        mp[1] = 1;
        while (k < n)
        {
            int a = f[ka] * 2, b = f[kb] * 3, c = f[kc] * 5; // 用ka,kb,kc三个指针来标记一个丑数，该丑数我们还未通过用它乘以系数推导计算后面的丑数
            int tmp = min(min(a, b), c); // 新的最小的丑数一定来自a,b或者c
            if (mp.find(tmp) == mp.end())
            {
                mp[tmp] = 1; // 标记该丑数已被记录过
                f[++k] = min(min(a, b), c);
            }
            if (f[k] == a) ka++; // 移动指针
            else if (f[k] == b) kb++;
            else kc++;
        }
        return f[n]; 
    }
};

// 进一步优化
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> f(n + 1);
        f[1] = 1;
        int k = 1, ka = 1, kb = 1, kc = 1;
        while (k < n)
        {
            int a = f[ka] * 2, b = f[kb] * 3, c = f[kc] * 5;
            f[++k] = min(min(a, b), c);
            if (f[k] == a) ka++; // 去掉else if即可省略掉map。即满足2)的条件时，我们都移动它们的指针
            if (f[k] == b) kb++;
            if (f[k] == c) kc++;
        }
        return f[n]; 
    }
};

