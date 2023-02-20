// 剑指 Offer 38. 字符串的排列
// 输入一个字符串，打印出该字符串中字符的所有排列。


/*
    1）回溯法，T=O(n!)
*/
class Solution {
public:
    map<string, int> mp;
    vector<string> res;
    vector<string> permutation(string s) {
        vector<int> vis(s.size(), 0); // 用vis记录s[i]有没有被使用过
        dfs("", vis, s);
        return res;
    }
    void dfs(string str, vector<int>& vis, string& s)
    {
        if (str.size() == s.size())
        {
            if (mp.find(str) == mp.end())
            {
                mp[str] = 1;
                res.push_back(str);
            }
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (vis[i] == 0)
                {
                    vis[i] = 1;
                    dfs(str + s[i], vis, s);
                    vis[i] = 0; // 回溯
                }
            }
        }
    }
};

/*
    2）剑指offer上提供的递归回溯法，T=O(n!)
*/
class Solution {
public:
    map<string, int> mp;
    vector<string> res;
    vector<string> permutation(string s) {
        dfs(0, s);
        return res;
    }
    void dfs(int k, string s)
    {
        if (k == s.size() && mp.find(s) == mp.end())
        {
            mp[s] = 1;
            res.push_back(s);
        }
        else
        {
            for (int i = k; i < s.size(); i++)
            {
                swap(s[i], s[k]);
                dfs(k + 1, s);
                swap(s[i], s[k]);
            }
        }
    }
};


/*
    3）回溯法，利用set去重，T=O(n!)
*/
class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        dfs(0, s);
        return res;
    }
    void dfs(int k, string s)
    {
        if (k == s.size())
        {
            res.push_back(s);
        }
        else
        {
            set<char> st;
            for (int i = k; i < s.size(); i++)
            {
                if (st.find(s[i]) != st.end()) continue;
                st.insert(s[i]);
                swap(s[i], s[k]);
                dfs(k + 1, s);
                swap(s[i], s[k]);
            }
        }
    }
};