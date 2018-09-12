class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        i, l, lens, ans = 0, sorted(nums), len(nums), []
        while i < lens - 3:
            if i == 0 or l[i] != l[i - 1]:
                j = i + 1
                while j < lens - 2:
                    if j == i + 1 or l[j] != l[j - 1]:
                        k, p = j + 1, lens - 1
                        while k < p:
                            tot = l[i] + l[j] + l[k] + l[p]
                            if tot > target:
                                p -= 1
                            elif tot < target:
                                k += 1
                            else:
                                ans.append([l[i], l[j], l[k], l[p]])
                                k, p = k + 1, p - 1
                                while k < p and l[k] == l[k - 1]:
                                    k += 1
                                while p > k and l[p] == l[p + 1]:
                                    p -= 1
                    j += 1
            i += 1
        return ans


if __name__ == '__main__':
    print(Solution().fourSum([-1,0,-5,-2,-2,-4,0,1,-2], -9))