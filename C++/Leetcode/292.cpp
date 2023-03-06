// 292. Nim 游戏


/*
    博弈论
*/
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};