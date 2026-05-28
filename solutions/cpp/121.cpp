/*
 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int premin = 10000; // 0 <= prices[i] <= 10000
        int ans = 0;
        for (auto price : prices)
        {
            if (price < premin)
            {
                premin = price;
            }
            ans = std::max(ans, price - premin);
        }
        return ans;
    }
};

int main()
{
    std::vector<int> prices = {7, 6, 4, 3, 1};
    Solution solution = Solution();
    int result = solution.maxProfit(prices);
    std::cout << result << std::endl;
    return 0;
}