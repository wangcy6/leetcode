

### 准备数据
/data/tidb/tiup/tidb-deploy/tidb-4000/log

mysql -h 127.0.0.1 -P 4000 -u root  -p 

explain select * from teacher where age >=18
