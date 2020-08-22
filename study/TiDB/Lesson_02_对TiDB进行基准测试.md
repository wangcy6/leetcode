



### 题目

~~~shell
分值：300

题目描述：

使用 sysbench、go-ycsb 和 go-tpc 分别对
 TiDB 进行测试并且产出测试报告。

测试报告需要包括以下内容：
* 部署环境的机器配置(CPU、内存、磁盘规格型号)，拓扑结构(TiDB、TiKV 各部署于哪些节点)
* 调整过后的 TiDB 和 TiKV 配置
* 测试输出结果
* 关键指标的监控截图
	    * TiDB Query Summary 中的 qps 与 duration
	    * TiKV Details 面板中 Cluster 中各 server 的 CPU 以及 QPS 指标
	    * TiKV Details 面板中 grpc 的 qps 以及 duration

输出：写出你对该配置与拓扑环境和 workload 下 TiDB 集群负载的分析，
提出你认为的 TiDB 的性能的瓶颈所在(能提出大致在哪个模块即 可
~~~





### 机器配置

| 软件   | 版本           | 备注      |
| ------ | -------------- | --------- |
| Ubuntu | 18.04          | 虚拟机1个 |
| cpu    | Virtual CPU  3 |           |
| 内存   | 2G             |           |
|        |                |           |



面板：

http://www.mytidb.com:2379/dashboard/#/overview

http://www.mytidb.com:3000/

​        

### 测试方案1 （ 拓扑结构不变，增加线程数量）

> tiup cluster deploy tidb-test v4.0.0 ./topology1.yaml --user root -p

| 拓扑结构 | 个数 | 关键参数 |
| -------- | ---- | -------- |
| Tidb     | 1    |          |
| pd       | 1    | 同一个   |
| TiKV     | 1    | 同一个   |



####  sysbench

![image-20200820195810668](../images/image-20200820195810668.png)

- 准备数据：

  sysbench --config-file=./sysbench-thread-1.cfg oltp_point_select --tables=16 --table-size=10000 prepare



- 测试结果

    sysbench --config-file=./sysbench-thread-1.cfg oltp_point_select --tables=16 --table-size=10000 run



> 非事务仅仅查询

| type         | thread | tps     | qps     | min latency | avg latency | 95th latency | max latency |
| ------------ | ------ | ------- | ------- | ----------- | ----------- | ------------ | ----------- |
| point_select | 1      | 1008.1  | 1008.1  | 0.42        | 0.99        | 1.7          | 44.97       |
| point_select | 3      | 2741.31 | 2741.31 | 0.37        | 1.09        | 2.26         | 39.55       |
| point_select | 8      | 3225.38 | 3225.38 | 0.37        | 2.48        | 6.91         | 62.25       |
| point_select | 16     | 3822.22 | 3822.22 | 0.4         | 4.18        | 17.63        | 87.57       |
| point_select | 32     | 4612.22 | 4612.22 | 0.4         | 6.93        | 17.63        | 87.64       |
| point_select | 64     | 4455.49 | 4455.49 | 0.48        | 14.35       | 34.95        | 132.55      |
| point_select | 128    | 5020.49 | 5020.49 | 0.48        | 25.45       | 56.84        | 182.4       |
| point_select | 256    | 5496.24 | 5496.24 | 0.53        | 46.47       | 99.33        | 306.11      |



> 第一步:观察规律



- 随着线程数量增加，虽然Qps增加，但是线程增加256倍，qps增加5倍，并且平均延迟逐渐增加。推测上下文切换造成的。

![image.png](https://i.loli.net/2020/08/20/iG752NUW6XIYoZm.png)



~~~shell
perf top
Samples: 1M of event 'cpu-clock', Event count (approx.): 42484621630                                                                                          
Overhead  Shared Object                 Symbol                                                                                                                
   3.80%  [kernel]                      [k] finish_task_switch                                                                                                
   3.58%  [kernel]                      [k] _raw_spin_unlock_irqrestore                                                                                       
   2.65%  tidb-server                   [.] runtime.scanobject                                                                                                
   2.44%  tidb-server                   [.] runtime.mallocgc                                                                                                  
   1.57%  tidb-server                   [.] runtime.findObject                                                                                                
   1.50%  tidb-server                   [.] runtime.heapBitsSetType                                                                                           
   1.33%  [kernel]                      [k] do_syscall_64                        
~~~



- 线程数超过内核数量3后，增加线程个数到256，依然增加qps，说明 非纯cpu操作

 **cpu**：

~~~shell
3个线程：

top - 18:56:05 up 6 days, 22:27,  2 users,  load average: 2.53, 1.68, 1.50
Tasks: 119 total,   2 running,  72 sleeping,   8 stopped,   0 zombie
%Cpu0  : 39.8 us, 22.5 sy,  0.0 ni, 32.6 id,  0.1 wa,  0.0 hi,  5.0 si,  0.0 st
%Cpu1  : 42.5 us, 21.2 sy,  0.0 ni, 30.5 id,  0.1 wa,  0.0 hi,  5.6 si,  0.0 st
%Cpu2  : 41.1 us, 21.1 sy,  0.0 ni, 31.3 id,  0.0 wa,  0.0 hi,  6.4 si,  0.0 st
KiB Mem :  2057260 total,   278420 free,  1231612 used,   547228 buff/cache
KiB Swap:   435652 total,   242040 free,   193612 used.   710760 avail Mem

256线程：
top - 18:57:23 up 6 days, 22:29,  2 users,  load average: 3.34, 2.11, 1.67
Tasks: 119 total,   1 running,  72 sleeping,   8 stopped,   0 zombie
%Cpu0  : 59.1 us, 25.7 sy,  0.0 ni,  8.1 id,  0.0 wa,  0.0 hi,  7.1 si,  0.0 st
%Cpu1  : 63.2 us, 23.8 sy,  0.0 ni,  6.1 id,  0.0 wa,  0.0 hi,  6.9 si,  0.0 st
%Cpu2  : 65.7 us, 21.1 sy,  0.0 ni,  5.5 id,  0.0 wa,  0.0 hi,  7.8 si,  0.0 st
KiB Mem :  2057260 total,    69648 free,  1439348 used,   548264 buff/cache
KiB Swap:   435652 total,   242040 free,   193612 used.   503260 avail Mem 
~~~



**性能分析**(对源码还不很了解，tidb内存数据库，依然消耗IO,可能在持久化方面原因)



Tikv：Flame Graph 停留在sendmsg ，在IO操作

![profiling_3_3_tikv_127_0_0_1_20160651773159.svg](../images/image-20200820193036857.png)



从profiling_3_3_tikv_127_0_0_1_20160651773159.svg可以看到用到关键模块：

1. Raftstore：该模块里面我们会介绍 TiKV 如何使用 Raft，如何支持 Multi-Raft

- raftstore::store::worker::read::Lo



2. Storage，该模块里面我们会介绍 Multiversion concurrency control (MVCC)，基于 [Percolator](https://storage.googleapis.com/pub-tools-public-publication-data/pdf/36726.pdf) 的分布式事务的实现



- tikv::storage::mvcc::reader::point_getter::PointGetter<S>::get::hab989dbb164b935e/tikv::storage::mvcc::reader::point_getter::PointGetter<S>::load_data::h764f9cdaa92b90



3. gRPC

​       -  grpc_call_start_batch/~ExecCtx



4. *RocksDB*： is an embeddable persistent key-value store for fast storage

- _ZN7rocksdb16MemTableIterator4SeekERKNS_5SliceE



5. engine_rocks::snapshot：快照



**Tidb： 部分截图**





​	

![image-20200820193026130](../images/image-20200820193026130.png)





从截图可以看到用到关键模块：

1. tidb：server.go  监控连接 并且读取请求

2. executor 执行器相关逻辑

3. distsql：等待返回结果

4. [Session](https://github.com/pingcap/tidb/blob/source-code/session.go#L62)



> 采用默认脚本：/usr/local/share/sysbench
>
> sysbench-thread-1.cfg 执行 :%s/^M//g　来去掉^M
>





####   go-ycsb

> 这里测试Database是TiKV

- 测试命令load &run 

  ~~~
  cd /data/tidb/src/github.com/pingcap/go-ycsb
  
  ./bin/go-ycsb load mysql -P ./workloads/workloada -p recordcount=10000 -p mysql.host=127.0.0.1 -p mysql.port=4000  -p mysql.user=root -p mysql.password=123456 -p mysql.db=test --threads 3
  
  ./bin/go-ycsb run mysql -P ./workloads/workloada -p recordcount=10000 -p mysql.host=127.0.0.1 -p mysql.port=4000  -p mysql.user=root -p mysql.password=123456 -p mysql.db=test --threads 3 
  ~~~

  

- 测试结果分析

1. 并发和延迟之间要均衡，workloada 当线程增加256时候，因为机器配置，性能反而下降。
2.  sql操作是IO操作，增加线程超过内核数量，依然可以发挥多线程优势。

- 测试数据

  

![image](https://user-images.githubusercontent.com/5937331/90873559-ebfab400-e3d0-11ea-905f-b43a933c7651.png)

![image-20200821161648521](https://user-images.githubusercontent.com/5937331/90869904-77714680-e3cb-11ea-96ff-4d7b0ae97b7e.png)







- 小白提问 

  1. 什么是workload负载类型  ？就是测试用例
  
  ~~~
  root@money:/data/tidb/src/github.com/pingcap/go-ycsb/workloads# ls
  minio  workloada  workloadb  workloadc  workloadd  workloade  workloadf  workload_template

  ~~~
  
  ![image-20200820201448205](../images/image-20200820201448205.png)

2. ops是啥

> ops/sec 每秒操作数



####   go-tpc







- 背景知识：



> TPC-C 是一个对 OLTP（联机交易处理）系统进行测试的规范，使用一个商品销售模型对 OLTP 系统进行测试，
>
> 其中包含五类事务：
>
> - NewOrder – 新订单的生成
> - Payment – 订单付款
> - OrderStatus – 最近订单查询
> - Delivery – 配送
> - StockLevel – 库存缺货状态分析



~~~powershell
git clone https://github.com/pingcap/go-tpc.git
make build

# Create 1000 warehouses by HASH 
./bin/go-tpc tpcc -H 127.0.0.1  -P  4000 -D tpcc --warehouses 1000    prepare  -T 3 &

# Run TPCC workloads, you can just run or add --wait option to including wait times
./bin/go-tpc tpcc -H 127.0.0.1  -P  4000 -D tpcc --warehouses 1000  run  -T 3 &

# Cleanup
./bin/go-tpc tpcc --warehouses 1000 cleanup

Usage:
  go-tpc [command]

Available Commands:
  ch          
  help        Help about any command
  tpcc        
  tpch        

Flags:
  -t, --acThreads int       OLAP client concurrency, only for CH-benCHmark (default 1)
      --count int           Total execution count, 0 means infinite
  -D, --db string           Database name (default "test")
  -d, --driver string       Database driver: mysql
      --dropdata            Cleanup data before prepare
  -h, --help                help for go-tpc
  -H, --host string         Database host (default "127.0.0.1")
      --ignore-error        Ignore error when running workload
      --interval duration   Output interval time (default 10s)
      --isolation int       Isolation Level 0: Default, 1: ReadUncommitted, 
                            2: ReadCommitted, 3: WriteCommitted, 4: RepeatableRead, 
                            5: Snapshot, 6: Serializable, 7: Linerizable
      --max-procs int       runtime.GOMAXPROCS
  -p, --password string     Database password
  -P, --port int            Database port (default 4000)
      --pprof string        Address of pprof endpoint
      --silence             Don't print error when running workload
  -T, --threads int         Thread concurrency (default 1)
      --time duration       Total execution time (default 2562047h47m16.854775807s)
  -U, --user string         Database user (default "root")
  
~~~





- 面板参数含义理解

https://asktug.com/_/tidb-performance-map/#/tikv

![image.png](https://i.loli.net/2020/08/21/usKWOaTyMDZ3QpY.png)



### 测试方案 2  调整拓扑配置。









### 遗留TODO

- TiKV面板以前没使用过，里面好多功能，需要你研究一下。





### 参考

- [性能排查手册](https://asktug.com/_/tidb-performance-map)

- 第8章 TiDB 调优指南

- TiDB 源码阅读系列文章

- [如何对 TiDB 进行 TPC-C 测试](https://docs.pingcap.com/zh/tidb/v3.0/benchmark-tidb-using-tpcc)

- [TiKV 性能参数调优](https://docs.pingcap.com/zh/tidb/v3.0/tune-tikv-performance)

  