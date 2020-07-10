package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	condition := false // 条件不满足

	var mu sync.Mutex
	cond := sync.NewCond(&mu) // 创建一个Cond

	//让协程去创造条件
	go func() {
		mu.Lock()
		condition = true // 改写条件
		time.Sleep(3 * time.Second)
		cond.Signal() // 发送通知：条件ok
		mu.Unlock()
	}()

	mu.Lock()

	// 检查条件是否满足，避免虚假通知，同时避免 Signal 提前于 Wait 执行。
	for !condition { // 如果Signal提前执行了，那么此处就是false了

		// 等待条件满足的通知，如果虚假通知，则继续循环等待
		cond.Wait() // 等待时 mu 处于解锁状态，唤醒时重新锁定。 (阻塞当前线程)

	}
	fmt.Println("条件满足，开始后续动作...")
	mu.Unlock()

}
