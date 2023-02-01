/*
思路： 维护两个数组，
	一个从左到右遍历求当前i之前所有数的累乘数组l，
	一个从右到左遍历求当前i之后所有数的累乘数组r，
	两个数组相乘即为所求。
	用tmp保存累乘值可实现原地计算，节省空间复杂度
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> s;
        for(int i = 0; i < nums.size(); i++){ //从左到右即可得到累乘数组l
            if(i == 0)
                s.push_back(1);
            else
                s.push_back(nums[i - 1] * s[i - 1]);
        }
        int tmp = 1;
        for(int i = nums.size() - 2; i >= 0; i--){ // 从右到左即可得到累乘数组r
            tmp *= nums[i + 1];
            s[i] = tmp * s[i]; //相乘即为所求
        }
        return s;
    }
};