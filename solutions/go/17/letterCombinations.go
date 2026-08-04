var KEYBOARD []string = []string {
    "", // 0
    "", // 1
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
}

func letterCombinations(digits string) []string {
    var length int = len(digits)
    var ans []string
    path := make([]byte, length)
    var dfs func(int)
    dfs = func(i int) {
        if i == length {
            ans = append(ans, string(path))
            // 不需要 copy，因为string(path)就完成了添加的答案不再是path的指针
            return
        }
        for _, c := range KEYBOARD[digits[i] - '0'] {
            path[i] = byte(c)
            dfs(i + 1)
        }
    }
    dfs(0)
    return ans
}