/*
 https://leetcode.cn/problems/3sum/?envType=study-plan-v2&envId=top-100-liked
 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
 注意：答案中不可以包含重复的三元组。
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int length = nums.size();
        std::vector<std::vector<int>> result;
        for (int i = 0; i < length - 2; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int target = -nums[i];
            if (target < 0)
            {
                break; // nums[k] ≥ nums[j] > nums[i] → if nums[i] > 0 then nums[j] + nums[k] > 0
            }
            int j = i + 1;
            int k = length - 1;
            int temp = nums[j] + nums[k];
            while (j < k)
            {
                temp = nums[j] + nums[k]; // 更新最新的三数和
                if (temp == target)
                {
                    std::vector<int> ans = {nums[i], nums[j], nums[k]};
                    result.push_back(ans);
                    while (j < k && j < length - 1 && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }
                    j++;
                    k--;
                } else if (temp > target)
                {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solution = Solution();
    std::vector<std::vector<int>> result = solution.threeSum(nums);
    for (const auto ans : result)
    {
        std::cout << "[";
        for (const auto num : ans)
        {
            std::cout << num << ", ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}