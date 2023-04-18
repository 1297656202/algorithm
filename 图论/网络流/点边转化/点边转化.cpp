UVA1660 电视网络 Cable TV Network

给定一张 n 个点的无向图。求最少删除多少个点，使得图不连通。

点边转化，把原来无向图中的每个点 x，拆成入点 x 和出点 x′，
则在无向图中删去一个点，等价于在网络中断开 (x,x′)
对任意 x≠S 且 x≠T 的点 x 连有向边 (x,x′)，容量为 1
对原无向图的每条边 (x,y)，连有向边 (x′,y)和(y′,x)，容量为 +∞，即防止割断。求最小割即可

当然，在点边转化中也可以将一条边截成两半，中间插入一个点，把边的各种信息反映在这个点上
