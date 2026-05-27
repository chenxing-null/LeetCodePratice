#include <iostream>
#include <vector>
#include <utility>

/*
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int length = nums.size();
        int i = 0; // 遍历数组，寻找非零元素
        int j = 0; // 最左侧的 0 元素的下标位置，下一次非零元素的位置
        for (int i = 0; i < length; i++)
        {
            if (nums[i] != 0)
            {
                std::swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main()
{
    std::vector<int> nums = {0, 1, 0, 3, 12};
    Solution solution = Solution();
    solution.moveZeroes(nums);
    std::cout << "[";
    for (auto x : nums)
    {
        std::cout << x << " ";
    }
    std::cout << "]" << std::endl;
    return 0;
}