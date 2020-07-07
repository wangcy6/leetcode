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





## 扩展





### 思考题：连续7天未登录用户

>  分享最实用的经验 ， 希望每一位来访的朋友都能有所收获！
>
> 不保证一定正确，如果更好方式，疑问，请联系我

