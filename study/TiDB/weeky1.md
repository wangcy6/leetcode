

### 任务
~~~
本地下载 TiDB，TiKV，PD 源代码，改写源码并编译部署以下环境：

1 TiDB
1 PD
3 TiKV
改写后：使得 TiDB 启动事务时，能打印出一个 “hello transaction” 的 日志
~~~

### 输出：
- 搭建输出
![select * from information_schema.cluster_info](https://i.loli.net/2020/08/15/974tcSm58WuoeC2.png)
- 修改代码，输出日志
![image.png](https://i.loli.net/2020/08/16/jSLJvU4OhBgsHlT.png)
![image.png](https://i.loli.net/2020/08/16/uNnlLsX6Tq83KA5.png)

![image.png](https://i.loli.net/2020/08/16/udTbjSv1m98XHfV.png)



>1. 一个普通2G内存云主机如何编译Tidb过程。机器配置太低，只启动一个Tikv

>2. 一个sql语句是如何执行的。

### 环境准备



| 软件   | 版本  | 备注                     |
| ------ | ----- | ------------------------ |
| Ubuntu | 18.04 | 1G内存不行改为2G，vpn    |
| go     | 1.15  | export GOPATH=/data/tidb |
| gcc    | 7.5.0 |                          |


![TiDB 整体架构](https://user-images.githubusercontent.com/5937331/90312675-dc92eb00-df38-11ea-89ea-df88785e0133.png)




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
make

遇到问题：
1. 腾讯云上直接下载代码超级慢慢，改为window下载



~~~

#### pd

~~~shell
git clone https://github.com/pingcap/pd
make
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
cp ./tikv/target/release/tikv-server /data/tidb/bin/

cp ./bin/tidb-server /data/tidb/bin/
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
cp ./bin/tidb-server /data/tidb/bin/
cd /data/tidb/bin/
nohup ./tidb-server --store=tikv \
                  --path="127.0.0.1:2379" \
                  --log-file=tidb.log 2>&1 &
```

- 步骤四，测试

```shell

mysql -h 127.0.0.1 -P 4000 -u root -D test

TiDB 启动事务时，能打印出一个 “hello transaction”的 日志
START TRANSACTION;
select "hello transaction" as strings into outfile './test.txt';

root@money:/data/tidb/bin# cat test.txt 
hello transaction

```

## 一个sql是如何执行的【任务：启动事务时候打印日志】

目录：

- 服务器如何接受客户端连接
- 如何从IO中读取sql
- 一个sql是如何执行的
- 事务部分

--------------------------------------------------------------------



![image](https://user-images.githubusercontent.com/5937331/90312522-be78bb00-df37-11ea-96fa-5931a847fe14.png)

![SQL 层执行过程](https://download.pingcap.com/images/blog-cn/tidb-source-code-reading-3/2.png)



![image](https://user-images.githubusercontent.com/5937331/90312699-0e0bb680-df39-11ea-9888-6fc0313a45cf.png)

#### 代码部分



一条 SQL 语句需要经过，语法解析–>合法性验证–>制定查询计划–>优化查询计划–>根据计划生成查询器–>执行并返回结果 等一系列流程。



这个主干对应于 TiDB 的下列包：

![image](https://user-images.githubusercontent.com/5937331/90312730-6347c800-df39-11ea-9d79-6f361e9ebd8f.png)





### ref

- TiDB 源码阅读系列文章

- http://129.28.165.167:1313/post/book/tiDB
