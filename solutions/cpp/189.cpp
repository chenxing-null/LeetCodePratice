/*
 循环右移操作
 [1, 2, 3, 4, 5, 6, 7] >> 3 = [5, 6, 7, 1, 2, 3, 4]
 reverse([A | B]) = [reverse(B) | reverse(A)]
*/
#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    void rotate(std::vector<int> &nums, int k) {
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution solution = Solution();
    solution.rotate(nums, k);
    for (int x : nums) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}