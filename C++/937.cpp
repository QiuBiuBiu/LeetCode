/*
思路：
	就是写一个排序，cmp返回的参数还是没搞懂什么意思……
*/
class Solution {
public:
    static bool cmp(string A, string B) {
        string a = A.substr(A.find(' ') + 1);
        string b = B.substr(B.find(' ') + 1);
        if(isdigit(a[0]))
            return false;
        else if(isdigit(b[0]))
            return true;
        return a < b;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};