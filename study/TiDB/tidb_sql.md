

### 准备数据
/data/tidb/tiup/tidb-deploy/tidb-4000/log

mysql -h 127.0.0.1 -P 4000 -u root  -p 

explain select * from teacher where age >=18


CREATE TABLE `teacher` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `age` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;

INSERT  INTO teacher(id,NAME,age) VALUES (1,'seven',18);
INSERT  INTO teacher(id,NAME,age) VALUES (2,'qingshan',20);

