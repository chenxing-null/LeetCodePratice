/*
 给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
*/

// 埃氏筛 O(n log log n)
#include <iostream>
#include <vector>

class Solution
{
public:
    int countPrimes(int n)
    {
        std::vector<bool> isPrime(n, true); // 用于标记该状态是否为素数
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                // 因为比 i 小的所有数字都进行了尝试，没有此时 i 的因子
                ans++;
            }
            // 将 i 在 2 ~ n 范围内的倍数都标记为 false
            // 从 i**2 开始即可，因为 2 * i, 3 * i ... 都已经在 i = 2, i = 3 的时候标记过了
            // 只需要表示 i * i, i * (i + 1)
            for (long long j = (long long)i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        return ans;
    }
};

int main()
{
    int n = 10;
    Solution solution = Solution();
    int result = solution.countPrimes(n);
    std::cout << result << std::endl;
    return 0;
}