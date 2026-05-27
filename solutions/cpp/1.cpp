#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        int length = nums.size();
        std::unordered_map<int, int> book;
        std::vector<int> ans;
        for (int i = 0; i < length; i++)
        {
            auto it = book.find(target - nums[i]);
            if (it != book.end())
            {
                ans.push_back(it->second);
                ans.push_back(i);
                break;
            } else {
                book[nums[i]] = i;
            }
        }
        return ans;
    }
};

int main()
{
    std::vector<int> nums = {2, 7, 11, 5};
    int target = 9;
    Solution solution = Solution();
    std::vector<int> result = solution.twoSum(nums, target);
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}