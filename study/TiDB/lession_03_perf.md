





### 基本用法



~~~c++
yum clean all
yum makecache
yum update 

画外音：
有可能失败,需要删除目录/etc/yum.repos.d/, xxx.repo 下不合理的,放心删除替换就可以。
CentOS 6
wget -O /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-6.repo
curl -o /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-6.repo

yum install perf // 安装工具

perf record -F 99 -a -g -- sleep 20 

perf report -n --stdio

strace -p 25817 -c
mpstat -P ALL 3

-- 火焰图

git clone https://github.com/brendangregg/FlameGraph
cd FlameGraph    
perf script -i /root/perf.data | ./stackcollapse-perf.pl --all |  ./flamegraph.pl > ksoftirqd.svg
    
    

# -S参数表示设置TCP协议的SYN（同步序列号），-p表示目的端口为80
# -i u10表示每隔10微秒发送一个网络帧
# 注：如果你在实践过程中现象不明显，可以尝试把10调小，比如调成5甚至1
$ hping3 -S -p 80 -i u10 192.168.0.30
~~~







## ref



- 专栏 Linux 性能优化实战 https://github.com/feiskyer/linux-perf-examples

- [Golang 大杀器之性能剖析 PProf](https://segmentfault.com/a/1190000016412013) 阅读耗时

- 性能调优攻略 https://coolshell.cn/articles/7490.html

  

  