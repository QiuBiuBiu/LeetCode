class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y, res = 0;
        while (z) {
            res ++;
            z = z & (z - 1);
        }
        return res;
    }
};