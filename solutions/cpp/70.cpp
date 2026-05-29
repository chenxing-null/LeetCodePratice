#include <iostream>
#include <array>

/*
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 1 <= n <= 45
*/

class Solution
{
public:
    int climbStairs(int n)
    {
        std::array<long long, 2> memory{1, 2};
        if (n <= 2)
        {
            return static_cast<int>(memory[n - 1]); // static_cast<type> 安全的显式类型转换
        } else {
            for (int i = 2; i < n; i++)
            {
                long long temp = memory[0] + memory[1];
                memory[0] = memory[1];
                memory[1] = temp;
            }
        }
        return static_cast<int>(memory[1]);
    }
};

int main()
{
    int n = 6;
    Solution solution = Solution();
    int result = solution.climbStairs(n);
    std::cout << result << std::endl;
    return 0;
}