func maxArea(height []int) int {
    var length int = len(height)
    var left int = 0
    var right int = length - 1
    var area = min(height[left], height[right]) * (right - left)
    for left < right {
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
        var temp int = min(height[left], height[right]) * (right - left)
        area = max(area, temp)
    }
    return area
}