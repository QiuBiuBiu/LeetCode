/*
思路： 贪心。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int i = 0, j = height.size() - 1; i < j; ){
            if(height[i] < height[j]){
                ans = max(ans, height[i] * (j - i));
                i++;
            }
            else{
                ans = max(ans, height[j] * (j - i));
                j--;
            }
        }
        return ans;
    }
};