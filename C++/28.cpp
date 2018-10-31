/*
思路：
    暴力，KMP
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.length(), l2 = needle.length();
        for (int i = 0; i <= l1 - l2; i++) {
            if (haystack.substr(i, l2) == needle)
                return i;
        }
        return -1;
    }
};