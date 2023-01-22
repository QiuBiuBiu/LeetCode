// 剑指 Offer 40. 最小的k个数
// 详解：https://github.com/QiuBiuBiu/Note/blob/main/Algorithm/Jianzhi%20Offer/README.md#40%E6%9C%80%E5%B0%8F%E7%9A%84k%E4%B8%AA%E6%95%B0

/*
    1) STL, 最大堆，T=O(nlogk)
*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, less<int> > q; // 最大堆
        vector<int> res;
        if (k == 0) return res;

        for (auto a : arr)
        {
            if (q.size() < k) q.push(a); // size小于k，直接放入堆中
            else
            {
                if (a < q.top()) // 当新元素比堆顶元素小，则将堆顶元素(堆中的最大值)弹出，将新元素放入堆中
                {
                    q.pop();
                    q.push(a);
                }
            }
        }
        
        while (!q.empty()) 
        {
            res.push_back(q.top());
            q.pop();
        }

        return res;
    }
};

/*
    2) STL, 红黑树，T=O(nlogk)
*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        multiset<int, greater<int> > s; // set按从大到小的顺序排列
        vector<int> res;
        if (k == 0) return res;

        for (auto a : arr)
        {
            if (s.size() < k) s.insert(a);
            else
            {
                if (a < *s.begin()) // set里的第一个元素即最大值
                {
                    s.erase(s.begin());
                    s.insert(a);
                }
            }
        }
        
        for (auto it = s.begin(); it != s.end(); it++)
        {
            res.push_back(*it);
        }
        return res;
    }
};

/*
    3) 基于快排的partition函数，T=O(n)
*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k);
        if (k == 0) return res;

        int start = 0, end = arr.size() - 1;
        int index = partition(arr, start, end);

        while (index != k - 1)
        {
            if (index > k - 1)
            {
                end = index - 1;
            }
            else
            {
                start = index + 1;
            }
            index = partition(arr, start, end);
        }

        for (int i = 0; i < k; i++)
            res[i] = arr[i];
        return res;
    }

    int partition(vector<int>& arr, int start, int end)
    {
        int random_index = (rand() % (end - start + 1)) + start; // 快排算法中这里是随机选择[start, end]中的一个
        swap(arr[random_index], arr[end]);
        int index = start - 1;
        for (int i = start; i < end; i++)
        {
            if (arr[i] < arr[end])
            {
                ++index;
                if (index != i)
                    swap(arr[index], arr[i]);
            }
        }
        ++index;
        swap(arr[index], arr[end]);
        return index;
    }
};