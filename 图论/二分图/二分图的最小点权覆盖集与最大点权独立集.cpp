最小点权覆盖集
二分图最小点权覆盖集解决的是这样一个问题：
在二分图中，对于每条边，两个端点至少选一个，求所选取的点最小权值和。
方法：
1、先对图二分染色，对于每条边两端点的颜色不同
2、然后建立源点S，向其中一种颜色的点连一条容量为该点权值的边
3、建立汇点T，由另一种颜色的点向T连一条容量为该点权值的边
4、对于二分图中原有的边，改为由与S相连的点连向与T相连的点的一条容量为INF的边
跑一遍最大流，其结果就是最小点权和。
原理：
实际为最小割。建好图后，对整张图求最小割，那么不可能割INF的边，所以每对点中连向源汇点边权最小的边被割断
整体来看，就是对于任意一对端点，都选了一个较小权值，得到我们要的结果

最大点权独立集
与最小点权覆盖集相似：
在二分图中，对于每条边，两个端点至多选一条边，求所选取的点的最大权值和。
方法：
先求一次最小点权覆盖集，再用总权值减去它，就得到了最大点权独立集。
原理：
在最小点权独立集中，是每对点至少选择了一个的最小方案，反过来，就是每对点至多选择了一个的最大方案。

洛谷P2274 方格取数问题
方格取数问题就是很经典的最大点权独立集问题：
