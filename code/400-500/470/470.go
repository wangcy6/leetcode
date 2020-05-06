// 470
package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 10; i++ {
		a := rand.Intn(7)
		b := rand.Intn(7)
		fmt.Println(a + b) // 生成一组[0,9]范围内的整数作为随机数
	}

}
