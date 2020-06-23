# 

## 工程目录结构

- src为代码目录



##  产生Makefile 文件

> automake、autoconf生成configure文件

- GNU Automake

- GNU Autoconf

- GNU m4

- GNU Libtool

  

yum install -y  autoconf automake

![](https://images2015.cnblogs.com/blog/753880/201606/753880-20160605121846586-1241135412.jpg)

1. 运行autoscan命令



2. 将configure.scan 文件重命名为configure.ac，并修改configure.ac文件

- gcc重要选项



3. 在project目录下新建Makefile.am文件，并在src录下也新建Makefile.am文件



4. 在project目录下新建NEWS、 README、 ChangeLog 、AUTHORS文件



5. 运行aclocal,autoheader命令





6. 运行autoconf命令



7. 运行automake -a命令

   automake会根据configure.in中的宏把Makefile.am转换成Makefile.in文件



8. 运行./confiugre脚本




 configure常用选项： ./configure  --help















### 命令

~~~shell
autoscan
touch NEWS README ChangeLog AUTHORS
libtoolize
aclocal
autoheader
autoconf
automake -a
./configure  CFLAGS="-g"
make

https://www.gnu.org/savannah-checkouts/gnu/autoconf/manual/autoconf-2.69/html_node/index.html

~~~





