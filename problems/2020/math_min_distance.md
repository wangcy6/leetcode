

### 一、描述

八年级数学最短路径问题

如图，直线L是一条河，P，Q是两个村庄．欲在L上的某处修建一个水泵站，向P，Q两地供水，

现有如下四种铺设方案，图中实线表示铺设的管道

，则所需管道最短的是（　　）



![img](https://p0.ssl.img.360kuai.com/t01cc19efe7d58c29ad.webp)



根据两点之间，线段最短，可知选项D铺设的管道，则所需管道最短





- 在一个二维坐标轴地图上有n座房子，给的输入数据是n座房子的x，y坐标，现在要修一条水渠，水渠平行于y轴无限长（垂直于x轴），问每座房子到该水渠的距离之和最小是多少？（垂直最短距离之和）



- 染色问题，给定一个矩阵的size，颜料有c种，每种颜料的量给定，每涂一个格子消耗颜料一升。请问是否能找到染色方案，使得相邻的格子的颜色不同。返回true or false

  



### 二、思路


#### 最迷惑地方




#### 熟悉的子问题



#### 步骤描述




### 三、代码



- 放轻松，虽然是c++实现，拒绝奇技淫巧，通俗易懂。

- golang 



> 分享最实用的经验 ， 希望每一位来访的朋友都能有所收获！ 
>
> 如果有疑问请联系我，一起探讨，进步。





## 四 、 举一反三
- 265.  Paint House II #265

 - [847. 访问所有节点的最短路径](https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes/)

- #### [1293. 网格中的最短路径](https://leetcode-cn.com/problems/Shortest-Path-in-a-Grid-with-Obstacles-Elimination/)



给你一个 m * n 的网格，其中每个单元格不是 0（空）就是 1（障碍物）。每一步，您都可以在空白单元格中上、下、左、右移动。

如果您 最多 可以消除 k 个障碍物，请找出从左上角 (0, 0) 到右下角 (m-1, n-1) 的最短路径，并返回通过该路径所需的步数。

如果找不到这样的路径，则返回 -1。







- #### [1091. 二进制矩阵中的最短路径](https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/)

- 317 Shortest Distance from All Buildings

  https://www.jianshu.com/p/0d8648c02658

  ~~~
  317. 离建筑物最近的距离
  
  You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. 
  
  You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
  
  Each 0 marks an empty land which you can pass by freely.
  Each 1 marks a building which you cannot pass through.
  Each 2 marks an obstacle which you cannot pass through.
  For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2)
  
  int shortestDistance(vector<vector<int>>& grid)
  
  For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
  1 - 0 - 2 - 0 - 1
  |   |   |   |   |
  0 - 0 - 0 - 0 - 0
  |   |   |   |   |
  0 - 0 - 1 - 0 - 0
  The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
  
  作者：Jeanz
  链接：https://www.jianshu.com/p/96e7d72bb912
  来源：简书
  著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
  
  你是个房地产开发商，想要选择一片空地 建一栋大楼。
  你想把这栋大楼够造在一个距离周边设施都比较方便的地方，通过调研，你希望从它出发能在 最短的距离和 内抵达周边全部的建筑物。请你计算出这个最佳的选址到周边全部建筑物的 最短距离和。
  注意：
  
  你只能通过向上、下、左、右四个方向上移动。
  
  给你一个由 0、1 和 2 组成的二维网格，其中：
  
  0 代表你可以自由通过和选择建造的空地
  1 代表你无非通行的建筑物
  2 代表你无非通行的障碍物
  https://www.jianshu.com/p/0d8648c02658
  http://shangdixinxi.com/detail-1318009.html
  https://www.youtube.com/watch?v=F7AM7AGJZYE
  
  https://segmentfault.com/a/1190000008449896 不明白为bfs,不用dfs。
  
  ~~~

  

  ~~~
  
  ~~~

- #### [1368. 使网格图至少有一条有效路径的最小代价](https://leetcode-cn.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)

- 854