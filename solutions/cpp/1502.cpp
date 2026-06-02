/*
 给你一个数字数组 arr 。
 如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。
 如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    bool canMakeArithmeticProgression(std::vector<int> &arr)
    {
        int maxelement = arr[0];
        int minelement = arr[0];
        int length = arr.size();
        for (int i = 1; i < length; i++) {
            maxelement = std::max(maxelement, arr[i]);
            minelement = std::min(minelement, arr[i]);
        }
        int diff = (maxelement - minelement) / (length - 1); // 这里可能因为数据类型原因导致小数部分被掩盖 [1, 2, 4] diff = 1
        if (minelement + diff * (length - 1) != maxelement) {
            return false;
        }
        std::unordered_set<int> temp = std::unordered_set(arr.begin(), arr.end());
        for (int i = 1; i < length - 1; i++) {
            if (!temp.contains(minelement + i * diff)) { // C++20
                return false;
            }
        }
        return true;
    }
};

int main()
{
    std::vector<int> arr = {3, 5, 1};
    Solution solution = Solution();
    bool result = solution.canMakeArithmeticProgression(arr);
    std::cout << result << std::endl;
    return 0;
}