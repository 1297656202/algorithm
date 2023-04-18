最长公共子序列问题：
给定2个字符串，求其最长公共子串。如abcde和dbada的最长公共字串为bd。
动态规划：dp[i][j]表示A串前i个和B串前j个的最长公共子串的长度。

若A[i] == B[j] , dp[i][j] = dp[i-1][j-1] + 1;
否则 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
时间复杂度O(N*M)。

这里也可将其转化为最长递增子序列问题。举例说明： 
A：abdba
B：dbaaba

1：先顺序扫描A串，取其在B串的所有位置：
2：a(2,3,5) b(1,4) d(0)。
3：用每个字母的反序列替换，则最终的最长严格递增子序列的长度即为解。

替换结果：532 41 0 41 532最大长度为3.

简单说明：上面的序列和最长公共子串是等价的。
对于一个满足最长严格递增子序列的序列，该序必对应一个匹配的子串。
反序是为了在递增子串中，每个字母对应的序列最多只有一个被选出。
反证法可知不存在更大的公共子串，因为如果存在，则求得的最长递增子序列不是最长的，矛盾。
最长递增子序列可在O(NLogN)的时间内算出。

ps：LCS在最终的时间复杂度上不是严格的O(nlogn)举个退化的例子：
A：aaaa 
B：aaaa

长度变成了n*m ,最终时间复杂度O(n*m*(lognm)) > O(n*m)。
