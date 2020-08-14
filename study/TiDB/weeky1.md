



### 环境准备



| 软件   | 版本  | 备注                     |
| ------ | ----- | ------------------------ |
| Ubuntu | 18.04 | 1G内存不行改为2G         |
| go     | 1.15  | export GOPATH=/data/tidb |
| gcc    | 7.5.0 |                          |







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



#### TiKV 

>TiKV 是一个分布式事务型的键值数据库，提供了满足 ACID 约束的分布式事务接口，并且通过 [Raft 协议](https://raft.github.io/raft.pdf) 保证了多副本数据一致性以及高可用,TiKV 参考 Spanner 设计了 multi raft-group 的副本机制 https://raft.github.io/

~~~shell

apt-get install -y cargo gcc-multilib
curl https://sh.rustup.rs -sSf | sh -s

git clone https://github.com/pingcap/tikv 


TiKV的Makefile中
release:
	cargo build --no-default-features --release --features "${ENABLE_FEATURES}"
改为

release:
	env RUSTFLAGS=-Ztime-passes cargo build --no-default-features --release --features "${ENABLE_FEATURES}"
可以打印详细时间

SYSTEM_ALLOC=1 make release //去掉jemalloc，https://github.com/tikv/tikv/pull/6211 
RUST_BACKTRACE=1 make build //gcc版本不对 https://github.com/tikv/tikv/issues/8153

~~~

- 遇到的问题

~~~
Makefile:388: recipe for target 'src/jemalloc.o' failed
make[1]: Leaving directory '/data/tidb/src/github.com/pingcap/tikv/target/debug/build/tikv-jemalloc-sys-78bb871ae33d0d9d/out/build'

--- stderr

cc1: out of memory allocating 412392 bytes after a total of 87506944 bytes
make[1]: *** [src/jemalloc.o] Error 1
make[1]: *** Waiting for unfinished jobs..


l" "-ldl" "-lutil"
  = note: 
          /usr/bin/ld: out of memory allocating 362368 bytes after a total of 850800640 bytes
          collect2: error: ld returned 1 exit status
          

error: aborting due to previous error

error: could not compile `cmd`.

To learn more, run the command again with --verbose.
warning: build failed, waiting for other jobs to finish...
error: build failed
https://github.com/tikv/tikv/issues/8153
~~~



FQA

- [raft 协议中， 候选人角色能参与投票吗](https://xie.infoq.cn/article/0a8c579d8110b2025b536f79e)

#### mysql

~~~

~~~



#### 启动

~~~shell
cp pd-server tikv-server  tidb-server /data/tidb/bin
~~~









### ref



- http://129.28.165.167:1313/post/book/tiDB