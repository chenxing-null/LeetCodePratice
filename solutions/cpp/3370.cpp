// C++20
#include <iostream>
#include <bit>
#include <cstdint>

class Solution
{
public:
    int smallestNumber(int n)
    {
        return (1 << (std::bit_width((uint32_t)n))) - 1; // bit_width(uintx_t n) 获得 n 的二进制位数 (=) bit_length()
    }
};

int main()
{
    int n = 5;
    Solution solution = Solution();
    int result = solution.smallestNumber(n);
    std::cout << result << std::endl;
    return 0;
}