// getNarcissisticNumbers.go
package main

import (
	"fmt"
	"math"
)

//找出所有的n位十进制水仙花数
//确定查找的范围(找出n位的最大值与最小值)
//n=1 0-9 n=2 10-99  n=3 100 -999
//遍历每个数，判断为水仙花数，添加到数组中
func getNarcissisticNumbers(n int) []int {

	min := math.Pow10(n - 1)
	max := math.Pow10(n)
	fmt.Println(min, max)
	return nil

}

//8. 旋转字符串
//https://wizardforcel.gitbooks.io/the-art-of-programming-by-july/content/01.01.html

};
func main() {
	fmt.Println(getNarcissisticNumbers(2))
}
