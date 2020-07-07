---
title: "每日一题"
date: 2020-07-07
description: "每日一题"
draft: false
categories: ["FQA"]
---





## 题目：连续5天登录用户

现在我们有一张用户登录日志表，记录用户每天的登录时间，

我们想要统计一下，用户每次连续登录的开始日期和结束日期，以及连续登录天数。



| 用户ID | 登录日期   |
| :----- | :--------- |
| 1001   | 2017-01-01 |
| 1001   | 2017-01-02 |
| 1001   | 2017-01-04 |
| 1001   | 2017-01-06 |
| 1002   | 2017-01-02 |
| 1002   | 2017-01-03 |

同学们先思考下，整理下思路，如果没有思路或者某几个点不了解，就可以继续往下看了。



## 思路





![img](https://img-bbs.csdn.net/upload/201708/25/1503642094_168697.png)

-  分组

- 计算个数 必须大于5，并且按照等差数列 最大值和最小只差大于5

  

## 答案



~~~mysql
mysql> select user_id,count(*) as total,max(login_date)-min(login_date) as diff  from test.tm_login_log group by user_id HAVING total >5 and diff >5 ;

+---------+-------+------+
| user_id | total | diff |
+---------+-------+------+
|    1001 |    13 |   15 |
|    1002 |    15 |   16 |
+---------+-------+------+
2 rows in set (0.01 sec)
~~~





~~~mysql
CREATE TABLE test.tm_login_log
(
   user_id int,
  login_date date
)ENGINE=InnoDB;

-- 这里的数据是最简化的情况，每个用户每天只有一条登录信息，
insert into test.tm_login_log values(1001,'2017-01-01');
insert into test.tm_login_log values(1001,'2017-01-02');
insert into test.tm_login_log values(1001,'2017-01-04');
insert into test.tm_login_log values(1001,'2017-01-05');
insert into test.tm_login_log values(1001,'2017-01-06');
insert into test.tm_login_log values(1001,'2017-01-07');
insert into test.tm_login_log values(1001,'2017-01-08');
insert into test.tm_login_log values(1001,'2017-01-09');
insert into test.tm_login_log values(1001,'2017-01-10');
insert into test.tm_login_log values(1001,'2017-01-12');
insert into test.tm_login_log values(1001,'2017-01-13');
insert into test.tm_login_log values(1001,'2017-01-15');
insert into test.tm_login_log values(1001,'2017-01-16');
insert into test.tm_login_log values(1002,'2017-01-01');
insert into test.tm_login_log values(1002,'2017-01-02');
insert into test.tm_login_log values(1002,'2017-01-03');
insert into test.tm_login_log values(1002,'2017-01-04');
insert into test.tm_login_log values(1002,'2017-01-05');
insert into test.tm_login_log values(1002,'2017-01-06');
insert into test.tm_login_log values(1002,'2017-01-07');
insert into test.tm_login_log values(1002,'2017-01-08');
insert into test.tm_login_log values(1002,'2017-01-09');
insert into test.tm_login_log values(1002,'2017-01-10');
insert into test.tm_login_log values(1002,'2017-01-11');
insert into test.tm_login_log values(1002,'2017-01-12');
insert into test.tm_login_log values(1002,'2017-01-13');
insert into test.tm_login_log values(1002,'2017-01-16');
insert into test.tm_login_log values(1002,'2017-01-17');
insert into test.tm_login_log values(1003,'2017-01-18');
~~~





## 如果大量数据怎么办



> 如果这样问，我也不知道怎办? 不管百万，千万 ，还是一个记录
>
> 我思路查看 EXPLAIN执行结果

![image.png](https://i.loli.net/2020/07/07/Bzh5sofOjVyYcUv.png)





观察如下

- Using temporary就意味着使用了内部临时表  ----->内存临时表和“磁盘临时表
- Using filesort -就意味着MySQL 线程需要排序  - --->排序的时候用到了 sort buffer  



![image.png](https://i.loli.net/2020/07/07/vjhCHiUo4KORcIS.png)

画外音：

- 什么是临时表



场景：union去重复



![image.png](https://i.loli.net/2020/07/07/A4j2RCy1Srv7EVW.png)

![image.png](https://i.loli.net/2020/07/07/1UQocar85unV2Wg.png)



> explain select id%10 as m, count(*) as c from t1 group by m;

![image.png](https://i.loli.net/2020/07/07/9nBEHQ5gXeyPrdl.png)

![image.png](https://i.loli.net/2020/07/07/sUhWvXrqkIGajME.png)



> explain select id%10 as m, count(*) as c from t1 group by m order by null;
>
>  ExtraUsing index; Using temporary



要解决 group by 语句的优化问题，你可以先想一下这个问题：执行 group by 语句为什
么需要临时表？

group by 的语义逻辑，是统计不同的值出现的个数。

但是，由于每一行的 id%100 的结
果是无序的，所以我们就需要有一个临时表，来记录并统计结果。

那么，如果扫描过程中可以保证出现的数据是有序的，是不是就简单了呢？  



> explain select SQL_BIG_RESULT id%100 as m, count(*) as c from t1 group by m;
>
>  Using index; Using filesort





> select z, count(*) as c from t1 group by z;  
>
> explain select id%10 as m, count(*) as c from t1 group by m;



区别是什么：字段 id%10 是无序的，字段 z是有序的。





- 什么是sort_buffer？

![image.png](https://i.loli.net/2020/07/07/3hTpazjVLbdtqxm.png)



1. sort_buffer_size，就是 MySQL 为排序开辟的内存（sort_buffer）的大小。

2. 如果要排序的数据量小于 sort_buffer_size，排序就在内存中完成。

3. 但如果排序数据量太大，内存放不下，则不得不利用磁盘临时文件辅助排序  

![image.png](https://i.loli.net/2020/07/07/Q86d2LJTIwyAOam.png)



4. SELECT * FROM `information_schema`.`OPTIMIZER_TRACE`\G

![image.png](https://i.loli.net/2020/07/07/yndIxzLMtcFROi3.png)





ALTER TABLE test.tm_login_log ADD INDEX userid_log(user_id,login_date)

### 优化后

![image.png](https://i.loli.net/2020/07/07/PpQ26IXh8tKYb4J.png)

~~~mysql

explain select user_id,count(*) as total,max(login_date)-min(login_date) as diff  from test.tm_login_log group by user_id HAVING total >5 and diff >5 ;
 
Extra 字段里面多了“Using index”，表示的就是使用了覆盖索引，性能上会
快很多


~~~









## 思考与行动

**基于上面的 union、union all 和 group by 语句的执行过程的分析，**
**MySQL 什么时候会使用内部临时表？**

1. 如果语句执行过程可以一边读数据，一边直接得到结果，是不需要额外内存的，否则就
   需要额外的内存，来保存中间结果；
2. join_buffer 是无序数组，sort_buffer 是有序数组，临时表是二维表结构；
3. 如果执行逻辑需要用到二维表特性，就会优先考虑使用临时表。比如我们的例子中，
union 需要用到唯一索引约束， group by 还需要用到另外一个字段来存累积计数  



- 验证

  

~~~mysql
案例1  count(*)虽然相当于另外一个字段。但是不需要获取内容 比较特殊
explain select user_id,count(*)  from test.tm_login_log group by user_id;

explain select user_id,count(login_date)  from test.tm_login_log group by user_id;

Using index  

案例2 count(*)不变，但是 user_id%10 结果发生变化

explain select user_id%10 as m,count(*)  from test.tm_login_log group by m;
Using index; 
Using temporary;
Using filesort 

案例3 :Using index for group-by 
explain select user_id,max(login_date)  from test.tm_login_log group by user_id;


案例4：
select user_id,login_date,count(*)  from test.tm_login_log group by user_id,login_date;

请使用一条语句 统计各班的男生和女生人数
SELECT class_id, gender, COUNT(*) num FROM students GROUP BY class_id, gender;
~~~





## 参考

- http://blog.sae.sina.com.cn/archives/4096 【正在看】

>  分享最实用的经验 ， 希望每一位来访的朋友都能有所收获！
>
> 不保证一定正确，如果更好方式，疑问，请联系我

