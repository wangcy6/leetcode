// lock.go
package main

import (
	"fmt"
	"runtime"
	"sync"
)

var (
	count int32
	wg    sync.WaitGroup //WaitGroup总共有三个方法：Add(delta int),Done(),Wait(),简单的说一下这三个方法的作用:Add:添加或者减少等待goroutine的数量,Done:相当于Add(-1),Wait:执行阻塞，直到所有的WaitGrou数量变成0
)

func sCount() {
	defer wg.Done()
	for i := 0; i < 2; i++ {
		value := count
		runtime.Gosched() //把cpu让出来，让另一个goroutine跑
		value++
		count = value
	}
}

func test() {
	wg.Add(2)
	go sCount()
	go sCount()
	wg.Wait()
	fmt.Println(count)
}
func main() {

	test()
	a := 1
	var wg sync.WaitGroup

	wg.Add(2)
	go func() { //goroutine1
		defer wg.Done()
		a = a + 1
	}()

	go func() { //goroutine2
		defer wg.Done()
		if a == 1 {
			runtime.Gosched()
			fmt.Println("a==", a)
		}
	}()

	runtime.Gosched()
	wg.Wait()

	//////////

}
