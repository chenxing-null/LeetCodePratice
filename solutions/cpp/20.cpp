#include <iostream>
#include <stack>
#include <unordered_map>

std::unordered_map<char, char> pairs = {
    {')', '('},
    {']', '['},
    {'}', '{'}};

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> temp;
        for (char c : s)
        {
            if (pairs.contains(c))
            {
                if (temp.empty() || temp.top() != pairs[c])
                {
                    return false;
                } else {
                    temp.pop();
                }
            } else {
                temp.push(c);
            }
        }
        return temp.empty();
    }
};


int main()
{
    Solution solution = Solution();
    std::string s = "[]{}";
    bool result = solution.isValid(s);
    std::cout << result << std::endl;
    return 0;
}