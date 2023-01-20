// 面试题45. 把数组排成最小的数

/*
    1）内置排序 + 自定义优先级，T=O(nlog)
*/

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> numsStr;
        for (auto num : nums)
        {
            numsStr.push_back(to_string(num));
        }

        sort(numsStr.begin(), numsStr.end(), [](const string& a, const string& b){
            return a + b < b + a;
        });

        string res;
        for (auto num : numsStr)
        {
            res += num;
        }
        return res;
    }
};

/*
    Todo:
    2）手写排序 + 自定义优先级，T=O(nlog)
*/
