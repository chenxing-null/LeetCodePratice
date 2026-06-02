/*
 给你两种类别的游乐园项目：陆地游乐设施 和 水上游乐设施。
 陆地游乐设施
 landStartTime[i] – 第 i 个陆地游乐设施最早可以开始的时间。
 landDuration[i] – 第 i 个陆地游乐设施持续的时间。
 水上游乐设施
 waterStartTime[j] – 第 j 个水上游乐设施最早可以开始的时间。
 waterDuration[j] – 第 j 个水上游乐设施持续的时间。
 一位游客必须从 每个 类别中体验 恰好一个 游乐设施，顺序 不限 。
 游乐设施可以在其开放时间开始，或 之后任意时间 开始。
 如果一个游乐设施在时间 t 开始，它将在时间 t + duration 结束。
 完成一个游乐设施后，游客可以立即乘坐另一个（如果它已经开放），或者等待它开放。
 返回游客完成这两个游乐设施的 最早可能时间 。
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int earliestFinishTime(std::vector<int> &landStartTime, std::vector<int> &landDuration, std::vector<int> &waterStartTime, std::vector<int> &waterDuration)
    {
        int ans = 3000;
        int landlength = landStartTime.size();
        int waterlength = waterStartTime.size();
        int landlast = 2000;
        int waterlast = 2000;
        // 先进行陆地游乐设施
        for (int i = 0; i < landlength; i++) {
            landlast = std::min(landlast, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < waterlength; i++) {
            if (waterStartTime[i] >= landlast) {
                ans = std::min(ans, waterStartTime[i] + waterDuration[i]);
            } else {
                ans = std::min(ans, landlast + waterDuration[i]);
            }
        }
        // 先进行水上游乐设施
        for (int i = 0; i < waterlength; i++) {
            waterlast = std::min(waterlast, waterStartTime[i] + waterDuration[i]);
        }
        for (int i = 0; i < landlength; i++) {
            if (landStartTime[i] >= waterlast) {
                ans = std::min(ans, landStartTime[i] + landDuration[i]);
            } else {
                ans = std::min(ans, waterlast + landDuration[i]);
            }
        }
        return ans;
    }
};

int main()
{
    std::vector<int> landStartTime = {2, 8};
    std::vector<int> landDuration = {4, 1};
    std::vector<int> waterStartTime = {6};
    std::vector<int> waterDuration = {3};
    Solution solution = Solution();
    int result = solution.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    std::cout << result << std::endl;
    return 0;
}