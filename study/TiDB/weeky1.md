

 

> 这里主要介绍，一个普通2G内存云主机如何编译Tidb过程。

### 环境准备



| 软件   | 版本  | 备注                     |
| ------ | ----- | ------------------------ |
| Ubuntu | 18.04 | 1G内存不行改为2G，vpn    |
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

Finished release [optimized] target(s) in 85m 22s //编译85分钟

~~~





FQA

- [raft 协议中， 候选人角色能参与投票吗](https://xie.infoq.cn/article/0a8c579d8110b2025b536f79e)

#### mysql

~~~shell

~~~



#### 启动

~~~shell
cd /data/tidb/src/github.com/pingcap
cp ./pd/bin/pd-server  /data/tidb/bin/
cp ./tidb/bin/tidb-server /data/tidb/bin
cp ./tikv/target/release/tikv-server /data/tidb/bin/
~~~



- 步骤一，启动 PD

```
nohup pd-server --data-dir=pd \
                --log-file=./pd.log 2>&1 &
```

- 步骤二，启动 TiKV

```shell
nohup tikv-server --pd="127.0.0.1:2379" \
                  --data-dir=tikv \
                  --log-file=tikv.log 2>&1 &
```

- 步骤三，启动 TiDB

```
nohup tidb-server --store=tikv \
                  --path="127.0.0.1:2379" \
                  --log-file=tidb.log 2>&1 &
```

- 步骤四，TiDB 启动事务时，能打印出一个 “hello transaction” 的 日志:

```shell
mysql -h 127.0.0.1 -P 4000 -u root -D test

TiDB 启动事务时，能打印出一个 “hello transaction” 的 日志
START TRANSACTION;
select "hello transaction" as strings into outfile './test.txt';

root@money:/data/tidb/bin# cat test.txt 
hello transaction
```





### ref



- http://129.28.165.167:1313/post/book/tiDB