package main

import (
	"log"
	"net/http"
	_ "net/http/pprof"
	"os"
	"time"
)

//net/http/pprof：采集 HTTP Server 的运行时数据进行分析
//runtime/pprof：采集程序（非 Server）的运行数据进行分析
//pprof 是用于可视化和分析性能分析数据的工具

var datas []string

func Add(str string) string {
	data := []byte(str)
	sData := string(data)
	datas = append(datas, sData)

	return sData
}

func ServeHTTP(w http.ResponseWriter, r *http.Request) {
	var path string //视频路径
	values := r.URL.Query()
	path = values.Get("path")

	video, err := os.Open(path)
	if err != nil {
		log.Info(err)
	}
	defer video.Close()

	http.ServeContent(w, r, "test.mp4", time.Now(), video)
}

//http://127.0.0.1:6060/watch?path="F:\watch\1.mp4"
func main() {
	//	go func() {
	//		for {
	//			log.Println(Add("https://github.com/EDDYCJY"))
	//		}
	//	}()

	http.HandleFunc("/watch", ServeHTTP)
	http.ListenAndServe("0.0.0.0:6060", nil)
}

//https://segmentfault.com/a/1190000016412013
//https://golang.org/pkg/net/http/pprof/
