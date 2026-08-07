#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        int preMax =0;
        int sufMax = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                preMax = std::max(preMax, height[left]); // 先更新较小的高度，避免相减时出现负数的情况
                ans += preMax - height[left];
                // std::cout << "i = " << left << ", " << preMax - height[left] << std::endl;
                left++;
            }
            else
            {
                sufMax = std::max(sufMax, height[right]);
                ans += sufMax - height[right];
                // std::cout << "i = " << right << ", " << preMax - height[left] << std::endl;
                right--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution = Solution();
    std::vector<int> height = {4, 2, 0, 3, 2, 5}; // ans = 9
    int ans = solution.trap(height);
    std::cout << ans << std::endl;
    return 0;
}