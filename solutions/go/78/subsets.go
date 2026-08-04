func subsets(nums []int) [][]int {
    var length int = len(nums)
    var ans [][]int
    path := make([]int, 0)
    var dfs func(int)
    dfs = func(i int) {
        if i == length {
            temp := make([]int, len(path))
            copy(temp, path)
            ans = append(ans, temp)
            return
        }
        dfs(i + 1) // 该位置的数字不选
        path = append(path, nums[i]) // 选
        dfs(i + 1)
        path = path[:len(path) - 1] // 恢复现场 --> 回溯的重点，当一条路走到底的时候，要将现场进行恢复
    }
    dfs(0)
    return ans
}