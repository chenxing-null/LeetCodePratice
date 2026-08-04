func findMissingElements(nums []int) []int {
    ans := make([]int, 0)
    var mx int = slices.Max(nums)
    var mn int = slices.Min(nums)
    record := make(map[int]bool)
    for _, val := range nums {
        record[val] = true
    }
    for i := mn; i < mx; i++ {
        if !record[i] {
            ans = append(ans, i)
        }
    }
    return ans
}