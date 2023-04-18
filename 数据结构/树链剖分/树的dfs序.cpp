定义：dfs序：每个节点在dfs深度优先遍历中的进出栈的时间序列。 
定义两个数组，in[x]，out[x]。dfs从根结点开始，每个结点分别记录两个信息：
in[x]，out[x]，in[x]为dfs进入结点x时的时间戳，out[x]为dfs离开结点x时的时间戳。
下面的L和R就是上面的in和out 
dfs序的基本代码：
void dfs(int x,int pre,int d){//L,R表示一个子树的范围  
    L[x]=++tot;  
    dep[x]=d;  
    for(int i=0;i<e[x].size();i++){  
        int y=e[x][i];  
        if(y==pre)continue;  
        dfs(y,x,d+1);  
    }  
    R[x]=tot;  
}
性质：dfs序可以把一棵树区间化，即可以求出每个节点的管辖区间。
对于一棵树的dfs序而言，同一棵子树所对应的一定是dfs序中连续的一段。
