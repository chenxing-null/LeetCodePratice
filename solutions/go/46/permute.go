func permute(nums []int) [][]int {
    var ans [][]int
    var length int = len(nums)
    path := make([]int, length)
    onPath := make([]bool, length)
    var dfs func(int)
    dfs = func(i int) {
        if i == length {
            temp := make([]int, length)
            copy(temp, path)
            ans = append(ans, temp)
            return
        }
        for j, on := range onPath {
            if !on {
                path[i] = nums[j]
                onPath[j] = true
                dfs(i + 1)
                onPath[j] = false
            }
        }
    }
    dfs(0)
    return ans
}