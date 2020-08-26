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
		log.Println(err)
	}
	defer video.Close()

	http.ServeContent(w, r, "test.mp4", time.Now(), video)
}

//http://10.112.177.66:6060/mp4?path=/home/gadmin/data/0822/0822.mp4
//http://127.0.0.1:6060/ts?path=F:\watch\1.mp4
func main() {
	//	go func() {
	//		for {
	//			log.Println(Add("https://github.com/EDDYCJY"))
	//		}
	//	}()

	http.HandleFunc("/mp4", ServeHTTP)
	http.ListenAndServe("0.0.0.0:6060", nil)
}

//https://segmentfault.com/a/1190000016412013
//https://golang.org/pkg/net/http/pprof/
//https://www.teaspect.com/detail/5462?pn=2
//https://hls-js-dev.netlify.app/demo/
//https://www.teaspect.com/detail/5462?pn=2
