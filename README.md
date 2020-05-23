# PAT-Advanced-Level-Practice
PAT甲级题库练习题

68. Find More Coins
题意：
给定一系列的硬币值, 然后给定一个目标value， 从所有硬币中找出几个, 使得这几个硬币的和正好等于这个value, 而且这个硬币序列应该是满足硬币值字典序的最小序列.
本题是典型的背包问题，使用动态规划，也可以使用DFS递归，但是最后一个测试点会超时。

Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 104 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that V1 + V2 + ... + Vk = M. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.

Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].

72.Gas Station
题意：在几个候选的建站点里选一个结点建汽油站，让这个结点到各个居民点的距离满足:(按优先级条件递减)

1.到各个居民点的距离必须小于等于 加油站的最大服务距离Ds。

2.再满足1的加油站点中，优先选择min_dis最大的那个点。（就是说每一个候选点都能求出一个最短距离数组dis[],这个数组里的最小值就是min_dis,取几个候选站点中min_dis最大的那个作为站点）

3.如果2不唯一，则优先选择ave_dis最小的作为站点。

4.如果3不唯一，则优先选择标号最小的作为站点。

典型的单源最短路径问题，用Dijkstra算法

A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.

Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive integers: N (≤), the total number of houses; M (≤), the total number of the candidate locations for the gas stations; K(≤), the number of roads connecting the houses and the gas stations; and D
​S​​, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.

Output Specification:
For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output No Solution.