// 剑指 Offer 50. 第一个只出现一次的字符
// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。


/*
    hash，T=O(n)，S=O(26)
    虽然字符串的长度比较长，但是字符有限，可以对字符进行hash统计
*/
class Solution {
public:
    struct ch {
        int cnt; // 出现次数
        int index; // 最后一次出现的下标，若只出现一次，则也是它们第一次出现的下标
    };

    char firstUniqChar(string s) {
        vector<ch> mp(26); // 用一个vector来模拟map
        for (int i = 0; i < s.size(); i++)
        {
            int tmp = s[i] - 'a';
            mp[tmp].cnt++; 
            mp[tmp].index = i;
        }

        int index = -1;
        for (int i = 0; i < 26; i++) // 只用遍历hash表而不用遍历整个字符串
        {
            if (mp[i].cnt == 1)
            {
                index = index < 0 ? mp[i].index : min(index, mp[i].index);
            }
        }
        return index < 0 ? ' ' : s[index];
    }
};