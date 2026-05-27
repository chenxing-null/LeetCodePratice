#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& str : strs)
        {
            std::string key = str;
            std::sort(key.begin(), key.end());
            groups[key].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        for (auto& [key, group] : groups)
        {
            result.push_back(std::move(group)); // std::move(group) 转移所有权，避免拷贝，提高性能
        }
        return result;
    }
};

int main()
{
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution = Solution();
    std::vector<std::vector<std::string>> result = solution.groupAnagrams(strs);
    for (const auto& group : result)
    {
        std::cout << "[";
        for (const auto& s : group)
        {
            std::cout << s << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}