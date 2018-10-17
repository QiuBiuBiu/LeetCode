/*
思路： 贪心
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        int l = 0, r = height.size() - 1, ans = 0;
        int water = min(height[l], height[r]);
        while(l < r){
            int tmp = min(height[l], height[r]);
			// 计算蓄水量
            if(tmp < water)
                ans += water - tmp;
            else
                water = tmp;
			// 贪心
            if(height[l] > height[r]) 
                r--;
            else
                l++;
        }
        return ans;
    }
};