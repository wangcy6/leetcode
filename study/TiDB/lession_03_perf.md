

















## 发现问题过程

sysbench：

cd /data/tidb/tiup

- 准备数据：

  sysbench --config-file=./sysbench-thread-1.cfg oltp_point_select --tables=16 --table-size=10000 prepare



- 测试结果

  sysbench --config-file=./sysbench-thread-1.cfg oltp_point_select --tables=16 --table-size=10000 run



perf record   -g -p 30584
perf report -n --stdio

perf script -i  ./perf.data | /data/tidb/src/github.com/FlameGraph/stackcollapse-perf.pl --all |  /data/tidb/src/github.com/FlameGraph/flamegraph.pl > tidb_16.svg



/data/tidb/tiup/tidb-deploy/tidb-4000/log

- 了解 系统调用

~~~
# pstack命令可显示每个进程的栈跟踪
sudo apt-get install pstack strace
pstack  16281
strace -p  16281
~~~



### 基础知识补充



~~~c++
http://www.mytidb.com:2379/dashboard/


# 安装perf
yum clean all
yum makecache
yum update 

画外音：
有可能失败,需要删除目录/etc/yum.repos.d/, xxx.repo 下不合理的,放心删除替换就可以。
CentOS 6
wget -O /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-6.repo
curl -o /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-6.repo

yum install perf 



strace -p 25817 -c
mpstat -P ALL 3

# 火焰图
git clone https://github.com/brendangregg/FlameGraph
cd FlameGraph    
perf script -i /root/perf.data | /data/tidb/src/github.com/FlameGraph/stackcollapse-perf.pl --all |  /data/tidb/src/github.com/FlameGraph/flamegraph.pl > ksoftirqd.svg
  
    

# 执行perf记录事件
# -g：启用进程中函数的调用关系（CPU使用超过0.5%时，才会显示调用栈，可以通过man查看）
# -a：追踪所有的CPU的
perf record   -g -p 30584
perf report -n --stdio
    
# 切换到FlameGraph安装路径执行下面的命令生成火焰图
$ perf script -i  perf.data | ./stackcollapse-perf.pl --all | ./flamegraph.pl > nginx.svg
    

# -S参数表示设置TCP协议的SYN（同步序列号），-p表示目的端口为80
# -i u10表示每隔10微秒发送一个网络帧
# 注：如果你在实践过程中现象不明显，可以尝试把10调小，比如调成5甚至1
yum install hping3
$ hping3 -S -p 8081 -i u10 127.0.0.1

# -n DEV 表示显示网络收发的报告，间隔1秒输出一组数据
$ sar -n DEV 1

    
    
# 安装必备docker、curl和perf
$ apt-get install -y docker.io curl build-essential linux-tools-common
# 安装火焰图工具
$ git clone https://github.com/brendangregg/FlameGraph
# 安装wrk
$ git clone https://github.com/wg/wrk
$ cd wrk && make && sudo cp wrk /usr/local/bin/
    

git clone https://github.com/wg/wrk.git  
cd wrk  
make 
    
# 默认测试时间为10s，请求超时2s
$ wrk --latency -c 1000 http://127.0.0.1:8081
 

# 测试时间5分钟
$ wrk --latency -c 1000 -d 300 http://192.168.0.30

Running 10s test @ http://192.168.0.30
  2 threads and 1000 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    14.82ms   42.47ms 874.96ms   98.43%
    Req/Sec   550.55      1.36k    5.70k    93.10%
  Latency Distribution
     50%   11.03ms
     75%   15.90ms
     90%   23.65ms
     99%  215.03ms
  1910 requests in 10.10s, 573.56KB read
  Non-2xx or 3xx responses: 1910
Requests/sec:    189.10
Transfer/sec:     56.78KB
~~~







### 基础知识补充 pprof 





~~~

http://95.169.24.121:10080/debug/pprof/


#  TiDB 内存快照分析
go tool pprof 127.0.0.1:10080/debug/pprof/heap
curl -G 127.0.0.1:10080/debug/pprof/heap > heap.profile

go tool pprof heap.profile


登录 Dashboard 后，可在左侧功能导航处点击「高级调试 → 节点性能分析」进入性能分析页面。

选择一个或多个需要进行性能分析的节点，并选择性能分析时长(默认为 30 秒，最多 120 秒)，点击「开始分析」，即可开始性能分析。
 
# pstack命令可显示每个进程的栈跟踪
sudo apt-get install pstack strace
pstack  16281
strace -p  16281
~~~







## ref

- https://time.geekbang.org/column/article/87342

- 专栏 Linux 性能优化实战 https://github.com/feiskyer/linux-perf-examples

- [Golang 大杀器之性能剖析 PProf](https://segmentfault.com/a/1190000016412013) 阅读耗时

- 性能调优攻略 https://coolshell.cn/articles/7490.html

- Golang 大杀器之跟踪剖析 trace  阅读 40分钟 [Golang 大杀器之跟踪剖析 trace](https://juejin.im/post/6844903887757901831)

  

  