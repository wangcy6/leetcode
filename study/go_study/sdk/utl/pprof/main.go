package main

import "net/http"
import _ "net/http/pprof" //  初始化pprof
import "fmt"

func main() {
	// do something

	fmt.Println(http.ListenAndServe("localhost:6060", nil)) //启动http服务器

}
