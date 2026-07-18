#include <iostream>
#include <vector>
#include <algorithm>

/*
class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        int length = nums.size();
        std::vector<int> dp(length);
        dp[0] = nums[0];
        if (length == 1)
        {
            return dp[length - 1];
        }
        dp[1] = std::max(nums[0], nums[1]);
        if (length == 2)
        {
            return dp[length - 1];
        }
        for (int i = 2; i < length; i++)
        {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[length - 1];
    }
};
*/

// Key point: To maximize the profit, there will be no case where two consecutive houses are both not selected
class Solution
{
public:
    int rob(std::vector<int> &nums) {
        size_t length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return std::max(nums[0], nums[1]);
        } else {
            int first = nums[0];
            int second = std::max(nums[0], nums[1]);
            for (int i = 2; i < length; i++) {
                int temp = std::max(first + nums[i], second);
                first = second;
                second = temp;
            }
            return second;
        }
    }
};

int main()
{
    Solution solution = Solution();
    std::vector<int> nums = {2, 7, 9, 3, 1};
    int result = solution.rob(nums);
    std::cout << result << std::endl;
    return 0;
}