func trap(height []int) int {
    var length int = len(height)
    preMax := make([]int, length)
    sufMax := make([]int, length)
    preMax[0] = height[0]
    sufMax[length - 1] = height[length - 1]
    for i := 1; i < length; i++ {
        preMax[i] = max(preMax[i - 1], height[i])
    }
    for i := length - 2; i > -1; i-- {
        sufMax[i] = max(sufMax[i + 1], height[i])
    }
    var ans int = 0
    for i := 1; i < length - 1; i++ {
        ans += min(preMax[i], sufMax[i]) - height[i]
    }
    return ans
}