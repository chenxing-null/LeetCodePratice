/*
 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int can = nums[0]; // 初始能够到达的最远位置
        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            if (i > can)
            {
                break;
            } else {
                can = std::max(can, i + nums[i]);
            }
        }
        return can >= length - 1;
    }
};

int main()
{
    std::vector<int> nums = {3, 2, 1, 0, 4};
    Solution solution = Solution();
    bool result = solution.canJump(nums);
    std::cout << result << std::endl;
    return 0;
}