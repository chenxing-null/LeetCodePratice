/*
 给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。
 每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：
 0 <= j <= nums[i] 且
 i + j < n
 返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int ans = 0; // 记录跳跃次数
        int can = 0; // 记录当前能到达的最远的位置
        int cur = 0; // 记录当前的位置
        int length = nums.size();
        while (can < length - 1)
        {
            int temp = can; // 记录下一次跳跃能够到达的最远距离
            for (int i = cur; i <= can; i++)
            {
                temp = std::max(temp, i + nums[i]);
            }
            can = temp;
            ans++;
        }
        return ans;
    }
};

int main()
{
    std::vector<int> nums = {2, 3, 1, 1, 4};
    Solution solution = Solution();
    int result = solution.jump(nums);
    std::cout << result << std::endl;
    return 0;
}

/*
 不是在无路可走的那个位置造桥，而是当发现无路可走的时候，时光倒流到能跳到最远点的那个位置造桥。换句话说，在无路可走之前，我们只是在默默地收集信息。当发现无路可走的时候，才从收集到的信息中，选择最远点造桥。所建造的这座桥的左端点（起跳位置）可能在我们当前走的这座桥的中间。
*/