class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = sorted(nums)
        i = 0
        lens = len(l)
        closest = float("inf")
        ans = float("inf")
        while i < lens:
            c = l[i]
            j, k = i + 1, lens - 1
            while j < k:
                tot = l[i] + l[j] + l[k]
                if tot < target:
                    j += 1
                elif tot > target:
                    k -= 1
                else:
                    j, k = j + 1, k - 1
                dis = abs(target - tot)
                if closest > dis and closest != 0:
                    closest = dis
                    ans = tot
            i += 1
        return ans


if __name__ == '__main__':
    print(Solution().threeSumClosest([-1, 2, 1, -4], 1))