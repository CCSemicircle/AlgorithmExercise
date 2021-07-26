# 机试错题集

本人一些刷题时遇到的错题，以及解题要点，代码文件为题解。

# 1. 暴力求解

## 1.1 枚举

| 题目                                                         | 错题次数 | 要点                               |
| ------------------------------------------------------------ | -------- | ---------------------------------- |
| [反序数](https://www.nowcoder.com/practice/e0d06e79efa44785be5b2ec6e66ba898?tpId=60&tqId=31035&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⭐        | 1. 反复取模、除，取每位数          |
| [百鸡问题](https://www.nowcoder.com/practice/01d161052db64c249a47fc723b4fd5db?tpId=40&tqId=21487&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking) | ⭐⭐       | 1.分数处理为整数<br />2.注意边界值 |

## 1.2 模拟

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [叠筐](http://acm.hdu.edu.cn/showproblem.php?pid=2074)       | ⭐        | 1.找规律<br />2.数组暂存结果                                 |
| [Repeater](https://www.nowcoder.com/practice/97fd3a67eff4455ea3f4d179d6467de9?tpId=40&tqId=21389&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking) | ⭐⭐       | 1.找规律<br />2.注意中间模板的变化                           |
| [Day of Week](https://www.nowcoder.com/practice/a3417270d1c0421587a60b93cdacbca0?tpId=40&tqId=21439&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking) | ⭐⭐       | 1.1年1月1日为星期一<br />2.用数组来表示，英文单词与月份索引、星期索引的对应<br />3.预处理每月天数 |
| [剩下的树](https://www.nowcoder.com/practice/f5787c69f5cf41499ba4706bc93700a2?tpId=60&tqId=29497&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⭐        | 1.用布尔值数组模拟                                           |
| [手机键盘](https://www.nowcoder.com/practice/20082c12f1ec43b29cd27c805cd476cd?tpId=60&tqId=29478&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⚪        | 1.预处理<br />2.注意找出同一键位的判断方式                   |
| [路径打印](https://www.nowcoder.com/practice/64b472c9bed247b586859978d13145ad?tpId=62&tqId=29457&tPage=1&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking) | ⭐⭐       | 1.将字符串拆分为列表<br />2.注意父路径初始的空格数以及后续空格数的变化 |
| [坠落的蚂蚁](https://www.nowcoder.com/practice/fdd6698014c340178a8b1f28ea5fadf8?tpId=40&tqId=21420&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking) | ⭐        | 1.找规律，简化题目                                           |

# 2. 排序与查找

## 2.1 排序

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [奥运排序问题](https://www.nowcoder.com/practice/100a4376cafc439b86f5f8791fb461f3?tpId=63&tqId=29564&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking) | ⭐⭐       | 1.数字小才更新排名，解决并列排名问题<br />2.注意除数为0的处理，要求判断分子是否为0 |

## 2.2 查找

| 题目                                                         | 错题次数 | 要点                 |
| ------------------------------------------------------------ | -------- | -------------------- |
| [查找](https://www.nowcoder.com/practice/d93db01c2ee44e8a9237d63842aca8aa?tpId=40&tqId=21531&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking) | ⭐⭐       | 1.二分查找           |
| [打印极值点下标](https://www.nowcoder.com/practice/7fd72f8ac7964ba3b8baa8735246e1f1?tpId=40&tqId=21385&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking) | ⭐        | 1.注意边界值（首尾） |
| [找位置](https://www.nowcoder.com/practice/e3b2cc44aa9b4851bdca89dd79c53150?tpId=40&tqId=21560&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking) | ⭐⭐       | 1.使用可重复map统计  |

# 3 字符串

## 3.1 字符串处理

| 题目                                                         | 错题次数 | 要点                           |
| ------------------------------------------------------------ | -------- | ------------------------------ |
| [统计字符](https://www.nowcoder.com/practice/4ec4325634634193a7cd6798037697a8?tpId=63&tqId=29574&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking) | ⚪        | 1.用ASCII符号的数组直接计数    |
| [单词替换](https://www.nowcoder.com/practice/5b58a04679d5419caf62c2b238e5c9c7?tpId=61&tqId=29518&tPage=1&ru=%2Fkaoyan%2Fretest%2F1002&qru=%2Fta%2Fpku-kaoyan%2Fquestion-ranking) | ⭐        | 1.将字符串拆分为列表以方便处理 |
| [浮点数加法](https://www.nowcoder.com/practice/ddec753f446e4ba4944e35378ba635c8?tpId=61&tqId=29551&tPage=3&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking) | ⭐⭐       | 1.补零对齐                     |

## 3.2 字符串匹配

| 题目                                                         | 错题次数 | 要点      |
| ------------------------------------------------------------ | -------- | --------- |
| [String Matching](https://www.nowcoder.com/practice/00438b0bc9384ceeb65613346b42e88a?tpId=62&tqId=29448&tPage=1&rp=1&ru=/ta/sju-kaoyan) | ⭐⭐       | 1.KMP算法 |
| [字符串匹配](https://www.nowcoder.com/practice/fbdc522ef958455687654b38a4ca01e0?tpId=66&tqId=29633&tPage=1&ru=/kaoyan/retest/1004&qru=/ta/buaa-kaoyan/question-ranking) | ⭐⭐       | 1.正则    |

# 4 数据结构

## 4.1 向量

> 暂无错题

## 4.2 队列

| 题目                                                        | 错题次数 | 要点                         |
| ----------------------------------------------------------- | -------- | ---------------------------- |
| [约瑟夫问题NO.2](http://bailian.openjudge.cn/practice/3254) | ⭐        | 1.循环队列<br />2.注意初始化 |

## 4.3 栈

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [括号匹配问题](http://ccnu.openjudge.cn/practice/1978/)      | ⭐        | 1.涉及标记不匹配的括号，初始时全设置为空格，且入栈的为下标以方便处理，如果仅仅是判断是否匹配则可以直接入栈符号 |
| [简单计算器](https://www.nowcoder.com/practice/5759c29a28cb4361bc3605979d5a6130?tpId=63&tqId=29576&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking) | ⭐⭐       | 1.堆栈分别存储运算符和运算数<br />2.用最低级符号初始入栈以便所有运算符入栈，用次低级的符号加在字符串末尾表示运算结束 |

## 4.4 二叉树



# 5 数学问题

## 5.1 进制转换

| 题目                                                         | 错题次数 | 要点                                             |
| ------------------------------------------------------------ | -------- | ------------------------------------------------ |
| [进制转换](https://www.nowcoder.com/practice/0337e32b1e5543a19fa380e36d9343d7?tpId=60&tqId=29473&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⭐        | 1.大整数进制转换，涉及大整数除                   |
| [10进制 VS 2进制](https://www.nowcoder.com/practice/fd972d5d5cf04dd4bb4e5f027d4fc11e?tpId=60&tqId=29498&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⭐⭐       | 1.大整数进制转换，涉及大整数乘除加               |
| [进制转换2](https://www.nowcoder.com/practice/ae4b3c4a968745618d65b866002bbd32?tpId=60&tqId=31034&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⭐⭐       | 1.非大整数进制转换，但是超过10进制，存在字母表示 |

## 5.2 最大公约数与最小公倍数
| 题目                                                         | 错题次数 | 要点                      |
| ------------------------------------------------------------ | -------- | ------------------------- |
| [最简真分数](https://www.nowcoder.com/practice/1f1db273eeb745c6ac83e91ff14d2ec9?tpId=61&tqId=29507&tPage=1&ru=%2Fkaoyan%2Fretest%2F1002&qru=%2Fta%2Fpku-kaoyan%2Fquestion-ranking) | ⭐        | 1.欧几里得算法/辗转相除法 |

## 5.3 质数

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [素数](https://www.nowcoder.com/practice/7f4be54b37a04fdaa4ee545819151114?tpId=66&tqId=29630&tPage=1&ru=/kaoyan/retest/1004&qru=/ta/buaa-kaoyan/question-ranking) | ⭐        | 1.只判断个位数为1的数                                        |
| [Prime Number](https://www.nowcoder.com/practice/c5f8688cea8a4a9a88edbd67d1358415?tpId=62&tqId=29467&tPage=1&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking) | ⭐⭐       | 1.预处理建立素数表<br />2.利用倍数关系判断是否为素数，不再对每个数计算 |

## 5.4 分解质因数

| 题目                                                         | 错题次数 | 要点                                     |
| ------------------------------------------------------------ | -------- | ---------------------------------------- |
| [质因数的个数](https://www.nowcoder.com/practice/20426b85f7fc4ba8b0844cc04807fbd9?tpId=60&tqId=29479&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⭐⭐       | 1.不建素数表，直接不断除求质因素         |
| [整除问题](https://www.nowcoder.com/practice/8e29045de1c84d349b43fdb123ab586a?tpId=62&tqId=29462&tPage=1&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking) | ⭐⭐       | 1.本质是求a^k 与 n! 两者质因子的倍数关系 |

## 5.5 快速幂

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [人见人爱的A^B](http://acm.hdu.edu.cn/showproblem.php?pid=2035) | ⭐⭐       | 1.标准快速幂                                                 |
| [求root(N, k)](https://www.nowcoder.com/practice/9324a1458c564c4b9c4bfc3867a2aa66?tpId=60&tqId=29488&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⭐⭐       | 1.快速幂<br />2.数学推导求最终的结果的简单表达式（等价式）<br />3.注意两式相减求解 |

## 5.6 矩阵与矩阵快速幂

| 题目                                                         | 错题次数 | 要点                                     |
| ------------------------------------------------------------ | -------- | ---------------------------------------- |
| [计算两个矩阵的乘积](https://www.nowcoder.com/practice/ed6552d03e624ba58d16af6d57e1c3e9?tpId=40&tqId=21502&tPage=9&rp=9&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking) | ⭐        | 1.矩阵乘法法则                           |
| [矩阵幂](https://www.nowcoder.com/practice/31e539ab08f949a8bece2a7503e9319a?tpId=67&tqId=29638&tPage=1&ru=/kaoyan/retest/1005&qru=/ta/bupt-kaoyan/question-ranking) | ⭐        | 1.矩阵快速幂<br />2.注意初始化为单位矩阵 |

## 5.7 高精度整数

- 大整数模板见文件BigInteger.cpp。

# 6 贪心

## 6.1 简单贪心

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [代理服务器](https://www.nowcoder.com/practice/1284469ee94a4762848816a42281a9e0?tpId=60&tqId=29476&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⭐⭐       | 1.同一起点出发法，求每次能达到的最远距离<br />2.每次能达到的最远距离为0时代表无法前进 |

## 6.2 区间贪心

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [今年暑假不AC](http://acm.hdu.edu.cn/showproblem.php?pid=2037) | ⭐⭐       | 1.每次找到结束时间最早的节目                                 |
| [Case of Fugitive](http://codeforces.com/problemset/problem/555/B) | ⭐⭐       | 1.用区间去匹配桥，每次尽量找到最匹配桥大小的区间，即在所有满足 minimum <= length <= maximum 的区间中找到maximum最小的区间 |
| [To Fill or Not to Fill](https://www.nowcoder.com/practice/f7eba38f7cd24c45982831e0f38518f9?tpId=63&tqId=29602&tPage=2&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking) | ⭐⭐       | 1.每次求下一站为油价最便宜的一站，没有则在当前站加满，或者除非可以加油至达到终点<br />2.注意两种特殊情况，是否可以达到最近的下一站以及是否可以到达终点，可以设置终点为最后一站统一判断 |

# 7 递归与分治

## 7.1 递归

- 递归的要点在于不关注具体的过程，只关注母问题与子问题的数学关系。

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [汉诺塔Ⅲ](http://acm.hdu.edu.cn/showproblem.php?pid=2064)    | ⭐⭐       | 1.考虑将最大圆盘从第一根杆移动到第三根杆即可得到如下递归关系 |
| [杨辉三角形](https://www.nowcoder.com/practice/ef7f264886a14fdf8a6ed3ac008a23c8?tpId=40&tqId=21535&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking) | ⭐        | 1.找规律即可<br />2.如果用空间换时间，注意数组不要开太大     |
| [全排列](https://www.nowcoder.com/practice/5632c23d0d654aecbc9315d1720421c1?tpId=61&tqId=29515&tPage=1&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking) | ⭐        | 1.先确定前半段，再通过遍历后半段往前半段加字符               |

## 7.2 分治

- **分治法的步骤如下**：

1. **分**：将问题分解为规模更小的子问题
2. **治**：将这些规模更小的子问题逐个击破
3. **合**：将已解决的子问题合并，并最终得出母问题的解

- **分治与递归的联系与区别**：

1. 两者都体现了将问题分解成更小子问题的思想；
2. 递归强调的是可以从子问题逐步推出母问题；
3. 分治强调的是母问题是由多个子问题合并之后解决。

| 题目                                                         | 错题次数 | 要点                                       |
| ------------------------------------------------------------ | -------- | ------------------------------------------ |
| [二叉树](https://www.nowcoder.com/practice/f74c7506538b44399f2849eba2f050b5?tpId=61&tqId=29557&tPage=3&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking) | ⭐        | 1.找到子节点和父节点的关系然后分治递归即可 |
| [2的幂次方](https://www.nowcoder.com/practice/7cf7b0706d7e4b439481f53e5fdac6e7?tpId=62&tqId=29460&tPage=1&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking) | ⭐        | 1.找到规律，递归表示                       |

# 8 搜索

## 8.1 宽度优先搜索

- **BFS方法**：关键是找到状态表示，建立Status结构体，利用优先队列遍历合法状态。
- **BFS的特点**：状态，状态扩展方式，有效状态，队列，标记，有效状态数，最优。

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [Catch That Cow](http://poj.org/problem?id=3278)             | ⭐⭐       | 1.BFS模板题                                                  |
| [Find The Multiple](http://poj.org/problem?id=1426)          | ⭐⭐       | 1.注意找规律减少遍历防止超时                                 |
| [玛雅人的密码](https://www.nowcoder.com/practice/761fc1e2f03742c2aa929c19ba96dbb0?tpId=60&tqId=29484&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking) | ⭐⭐       | 1.通过提前预判断来排除没有结果的情况<br />2.使用map结构判断已经出现的字符串 |

## 8.2 深度优先搜索

- **DFS方法**：

1. 关键是找到正确的状态表示（三元组等）
2. 最外层循环列举在该层的所有状态
3. 利用递归，判断每一条状态分支是否可行
4. 注意使用标记减少遍历
5. 要注意递归层次不过多，避免”爆栈“。

- **剪枝**：通过放弃对某些不可能产生结果的子集的搜索，达到提高效率的目的。

- **标记**：先标记为true，DFS的结果不符合再重新设置为false，有点类似于试错法

- **DFS与BFS**：DFS强调问题是否有解，BFS注重找到最优解

| 题目                                                         | 错题次数 | 要点                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [A Knights's Journey](http://poj.org/problem?id=2488)        | ⭐⭐       | 1.使用scanf避免输入太多超时<br />2.每次遍历下一层状态时，先将下一层状态用字典序排列，以保证结果是最小字典序 |
| [Square](http://poj.org/problem?id=2362)                     | ⭐⭐       | 1.注意找到正确的状态表示（三元组）<br />2.注意使用剪枝，特别是去除上一个已经判断出不能产生结果的长度的棍子<br />3.注意确定递归调用DFS时传入的下一个状态<br />4.注意标记的设置，先设置为true，结果不符合再设置为false，类似于试错法<br />5.注意将棍子长度排序，以方便确定下一个状态 |
| [神奇的口袋](https://www.nowcoder.com/practice/9aaea0b82623466a8b29a9f1a00b5d35?tpId=61&tqId=29531&tPage=2&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking) | ⭐        | 1.注意找出正确的状态表示，不能往前重复计数                   |
| [八皇后](https://www.nowcoder.com/practice/fbf428ecb0574236a2a0295e1fa854cb?tpId=61&tqId=29558&tPage=3&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking) | ⭐⭐       | 1.注意最外层循环列举在该层的所有状态<br />2.同一层确定一个状态后，递归调用DFS确定之后的位置，即可确定该状态下的所有解<br />3.通过上述两个方法，即可遍历所有的解<br />4.通过循环判断是否符合条件，可以在循环前设置flag布尔变量，表意更清楚<br />5.主对角线上x-y相同，副对角线上x+y相同，原理是斜率分别为1和-1 |

# 9. 图论

1. [二叉树的最大路径和](https://www.nowcoder.com/questionTerminal/da785ea0f64b442488c125b441a4ba4a)（2021中南大学大数据组机试原题），错题次数：⭐

# 10. 动态规划

1. [最长递增子序列](https://www.nowcoder.com/questionTerminal/30fb9b3cab9742ecae9acda1c75bf927)（2021中南大学大数据组机试原题），错题次数：⭐