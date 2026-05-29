/*
 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

// C++20
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        int ans = 0;
        std::unordered_set<int> book;
        for (const auto x : nums)
        {
            book.insert(x); // set 插入元素
        }
        for (const auto x : book)
        {
            if (book.contains(x - 1)) // bool 类型返回值的 set 查找函数
            {
                continue;
            } else {
                int y = x + 1;
                while (book.contains(y))
                {
                    y++;
                }
                ans = std::max(ans, y - x);
            }
        }
        return ans;
    }
};

int main()
{
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution solution = Solution();
    int result = solution.longestConsecutive(nums);
    std::cout << result << std::endl;
    return 0;
}