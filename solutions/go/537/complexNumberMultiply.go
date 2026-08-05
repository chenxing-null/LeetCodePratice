func parse(num string) (int, int) {
    i := strings.IndexByte(num, '+')
    real, _ := strconv.Atoi(num[:i]) // string to int
    imag, _ := strconv.Atoi(num[i + 1:len(num) - 1])
    return real, imag
}
func complexNumberMultiply(num1 string, num2 string) string {
    real1, imag1 := parse(num1)
    real2, imag2 := parse(num2)
    return fmt.Sprintf("%d+%di", real1 * real2 - imag1 * imag2, real1 * imag2 + real2 * imag1)
}