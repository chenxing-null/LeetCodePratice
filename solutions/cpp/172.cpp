#include <iostream>
#include <algorithm>

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        int p = 5;
        while (n >= p)
        {
            int temp = n / p;
            p *= 5;
            ans += temp;
        }
        return ans;
    }
};

int main()
{
    int n = 100;
    Solution solution = Solution();
    std::cout << "My ans:" << solution.trailingZeroes(n) << std::endl;
    int temp = 1;
    for (int i = 1; i <= n; i++)
    {
        temp *= i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (j % 5 == 0 && j != 0)
        {
            ans++;
            j /= 5;
        }
    }
        std::cout << "Stand ans:" << ans << std::endl;
    return 0;
}