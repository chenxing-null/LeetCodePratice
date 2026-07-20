#include <iostream>
#include <vector>

class Solution
{
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int length = m * n;
        k = k % length;
        if (k == 0) {
            return grid;
        }
        /*
         if gcd(a, m) = 1 then k * a + b (k = 0, 1, ..., m - 1) can traverse Z(m)
         else gcd(a, m) = d then:
             The sequence decomposes into d cycles.
             Each cycle: start + t * a (mod m), t = 0, 1, ..., m/d - 1
             Cycle starts: 0, 1, 2, ..., d-1
             Each cycle covers exactly one residue class modulo d.
             Total elements covered: d * (m/d) = m
        */
        /*
         Eg:
         if m * n = 12, k = 4
            0 -> 4 -> 8 -> 0 (Ring 1)
            1 -> 5 -> 9 -> 1 (Ring 2)
            2 -> 6 -> 10 -> 2 (Ring 3)
            3 -> 7 -> 11 -> 3 (Ring 4)
        */
        int d = gcd(length, k);
        /*
         old grid[i][j] --> one dim index(old) = i * n + j
         one dim index(new) = i * n + j + k (mod m * n)
         row(new) = index(new) / n, column(new) = index(new) % n
        */
        for (int start = 0; start < d; start++) {
            int cur = start;
            int pre = grid[cur / n][cur % n];
            do {
                int next = (cur + k) % length;
                int temp = grid[next / n][next % n];
                grid[next / n][next % n] = pre;
                pre = temp;
                cur = next;
            } while (cur != start);
        }
        return grid;
    }
};

int main()
{
    Solution solution = Solution();
    std::vector<std::vector<int>> grid = {{3, 8, 1, 9},
                                          {19, 7, 2, 5},
                                          {4, 6, 11, 10},
                                          {12, 0, 21, 13}
                                        };
    int k = 4;
    std::vector<std::vector<int>> ans = solution.shiftGrid(grid, k);
    for (auto row : ans) {
        for (auto x : row) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}