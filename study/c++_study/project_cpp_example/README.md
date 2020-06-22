# autoconf 和 automake 生成 Makefile 文件



1) 运行autoscan命令



2) 将configure.scan 文件重命名为configure.in，并修改configure.ac文件



3) 在project目录下新建Makefile.am文件，并在src录下也新建makefile.am文件



4) 在project目录下新建NEWS、 README、 ChangeLog 、AUTHORS文件





5) 运行`libtoolize`生成一些libtool 的文件这些文件跟平台适应性有关系。





6) 运行aclocal,autoheader命令





7) 运行autoconf命令

8) 运行automake -a命令

- automake会根据configure.in中的宏把Makefile.am转换成Makefile.in文件

9) 运行./confiugre脚本

执行.／configure命令，最终的Makefile文件产生。



~~~she
autoscan
touch NEWS README ChangeLog AUTHORS
libtoolize
aclocal
autoheader
autoconf
automake -a
./configure
make
~~~





