#include <algorithm>

class Solution
{
public:
    int maxProduct(int n)
    {
        int first = 0;
        int second = 0;
        while (n != 0)
        {
            int cur = n % 10;
            if (cur > second)
            {
                second = cur;
            }
            if (second > first)
            {
                std::swap(first, second);
            }
            n /= 10;
        }
        return first * second;
    }
};