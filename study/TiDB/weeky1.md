



### 环境准备



| 软件   | 版本  | 备注                     |
| ------ | ----- | ------------------------ |
| Ubuntu | 7.3.0 | 1G内存不行改为2G         |
| go     | 1.15  | export GOPATH=/data/tidb |
|        |       |                          |







###  编译步骤

#### go

~~~shell
#根目录
export GOROOT=/root/local/go
#bin目录
export GOBIN=$GOROOT/bin
#工作目录
export GOPATH=/data/tidb //设置工程目录
export PATH=$PATH:$GOBIN //添加可执行程序

go version
go version go1.15 linux/amd64
~~~





####  tidb

~~~shell

mkdir -p /data/tidb/src/github.com/pingcap

cd /data/tidb/src/github.com/pingcap

git clone https://github.com/pingcap/tidb
cd tidb

遇到问题：
1. 腾讯云上直接下载代码超级慢慢，改为window下载



~~~

#### pd

~~~shell
git clone https://github.com/pingcap/pd
~~~



#### tikv

~~~shell
git clone https://github.com/pingcap/tikv 
~~~





#### mysql

~~~

~~~



#### 启动

~~~shell
cp pd-server tikv-server  tidb-server /data/tidb/bin
~~~









### ref



- http://129.28.165.167:1313/post/book/tiDB