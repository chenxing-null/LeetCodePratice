/*
 一家商店正在打折销售糖果。每购买 两个 糖果，商店会 免费 送一个糖果。
 免费送的糖果唯一的限制是：它的价格需要小于等于购买的两个糖果价格的 较小值 。
 比方说，总共有 4 个糖果，价格分别为 1 ，2 ，3 和 4 ，一位顾客买了价格为 2 和 3 的糖果，那么他可以免费获得价格为 1 的糖果，但不能获得价格为 4 的糖果。
 给你一个下标从 0 开始的整数数组 cost ，其中 cost[i] 表示第 i 个糖果的价格，请你返回获得 所有 糖果的 最小 总开销。
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(const int a, const int b)
{
    return a > b; // 降序
}

class Solution
{
public:
    int minimumCost(std::vector<int> &cost)
    {
        int ans = 0;
        std::sort(cost.begin(), cost.end(), cmp);
        int length = cost.size();
        for (int i = 0; i < length; i++)
        {
            if (i % 3 != 2)
            {
                ans += cost[i];
            }
        }
        return ans;
    }
};

int main()
{
    std::vector<int> cost = {1, 2, 3};
    Solution solution = Solution();
    int result = solution.minimumCost(cost);
    std::cout << result << std::endl;
    return 0;
}