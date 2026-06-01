/*
 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 返回容器可以储存的最大水量。
 说明：你不能倾斜容器。
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int length = height.size();
        int left = 0;
        int right = length - 1;
        int area = std::min(height[left], height[right]) * (right - left);
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                left++;
                area = std::max(area, std::min(height[left], height[right]) * (right - left));
            } else {
                right--;
                area = std::max(area, std::min(height[left], height[right]) * (right - left));
            }
        }
        return area;
    }
};

int main()
{
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution = Solution();
    int result = solution.maxArea(height);
    std::cout << result << std::endl;
    return 0;
}