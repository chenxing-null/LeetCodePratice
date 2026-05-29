#include <iostream>
#include <algorithm>
#include <vector>

/*
 给你一个整数数组 nums 。
 请你将 nums 中每一个元素都替换为它的各个数位之 和 。
 请你返回替换所有元素以后 nums 中的 最小 元素。
 1 <= nums.length <= 100
 1 <= nums[i] <= 104
*/

class Solution {
public:
    int minElement(std::vector<int>& nums) {
        int ans = 27;
        for (const auto x : nums)
        {
            int xx = x; // 将 x 从 nums 中复制出来，避免原数组被修改
            int temp = 0;
            while (xx != 0)
            {
                temp += xx % 10;
                xx /= 10;
            }
            ans = std::min(ans, temp);
        }
        return ans;
    }
};

int main()
{
    std::vector<int> nums = {10, 12, 13, 14};
    Solution solution = Solution();
    int result = solution.minElement(nums);
    std::cout << result << std::endl;
    return 0;
}