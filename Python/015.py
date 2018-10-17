class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        target = 0
        l = sorted(nums)
        lens = len(l)
        i = 0
        ans = []
        while i < lens - 2:
            if i == 0 or l[i] != l[i - 1]:
                j = i + 1
                k = lens - 1
                while j < k:
                    tot = l[i] + l[j] + l[k]
                    if tot > target:
                        k -= 1
                    elif tot < target:
                        j += 1
                    else:
                        ans.append([l[i], l[j], l[k]])
                        j += 1
                        k -= 1
                        while j < k and l[j] == l[j - 1]:
                            j += 1
                        while k > j and l[k] == l[k + 1]:
                            k -= 1
            i += 1
        return ans


if __name__ == '__main__':
    # print(Solution().threeSum([-1, 0, 1, 2, -1, -4]))
    # print(Solution().threeSum([-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0]))
    print(Solution().threeSum([0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]))