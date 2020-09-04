

### 准备

1. 使用tiup 部署集群

~~~shell
cd /data/tidb/tiup
tiup cluster deploy tidb-test v4.0.0 ./topology1.yaml --user root -p ##部署
tiup cluster list ##查询

tiup cluster display tidb-test  ##查询
tiup cluster start tidb-test ##启动
tiup cluster start tidb-test  -R pd ## 单独启动
tiup cluster stop tidb-test


cd /data/tidb/tiup/tidb-deploy/tidb-4000/bin


## 对之前部署tidb-test集群进行参数 
tiup cluster edit-config  tidb-test
tiup cluster reload  tidb-test

# TiDB 集群可以在不中断线上服务的情况下进行扩容和缩容。
## 执行扩容命令  https://docs.pingcap.com/zh/tidb/dev/scale-tidb-using-tiup
tiup cluster scale-out tidb-test scale-out.yaml
ssh-keygen //设置 SSH 通过密钥登录

## 缩容 TiDB/PD/TiKV 节点 
画外音：配置太低，需要缩容

tiup cluster display  tidb-test
tiup cluster scale-in tidb-test --node 127.0.0.1:4001
提示：Scaled cluster `tidb-test` in successfully
查看 /data/tidb/tiup/tidb-deploy 目录 tidb-4001 已经被删除

https://asktug.com/t/topic/36950
~~~



2. 编译源码

~~~shell

### tidb
git clone https://github.com/pingcap/tidb.git
cd /data/tidb/src/github.com/pingcap/tidb
make

./tidb-server -V 
Release Version: v4.0.0-beta.2-949-g3f38fa5d0-dirty
Edition: Community
Git Commit Hash: 3f38fa5d02b618666efce714be129b1afacd582d
Git Branch: master

小王提问：
c++ 编译有 -g 调试模式，方便gdb调试,goalng deubg如何设置呢？

https://github.com/pingcap/tidb/blob/master/Makefile


~~~

3. 替换

~~~shell
###  Text file busy
cp /data/tidb/src/github.com/pingcap/tidb/bin/tidb-server  /data/tidb/tiup/tidb-deploy/tidb-4000/bin/tidb-server 

tiup cluster stop tidb-test
tiup cluster start tidb-test 
tiup cluster display tidb-test 
~~~

画外音：

> 这里做不到更新tidb-server版本时候平滑升级呀？，还需要停止原来的服务 .
>
> https://asktug.com/t/topic/36950
>
> https://asktug.com/t/topic/36090

