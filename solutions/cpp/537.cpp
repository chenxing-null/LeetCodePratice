#include <iostream>
#include <string>

class Solution
{
public:
    std::string complexNumberMultiply(std::string num1, std::string num2)
    {
        int a, b, c, d;
        parse(num1, a, b);
        parse(num2, c, d);
        return std::to_string(a * c - b * d) + "+" + std::to_string(a * d + b * c) + "i";
    }

private:
    void parse(const std::string &num, int &real, int &imag)
    {
        int i = num.find('+');
        real = stoi(num.substr(0, i));
        imag = stoi(num.substr(i + 1, num.size() - i - 2));
    }
};

int main() {
    std::string num1 = "1+-1i";
    std::string num2 = "1+-1i";
    Solution solution = Solution();
    std::string ans = solution.complexNumberMultiply(num1, num2);
    std::cout << ans << std::endl;
    return 0;
}