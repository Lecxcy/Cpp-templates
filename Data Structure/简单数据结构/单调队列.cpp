//初始化
const int MAXN = 1e5 + 10;
int que[MAXN], l = 1, r = 0;

//添加元素
while (l <= r && check(que[r], i)) --r;
while (l <= r && que[l] <= i - k) ++l;
que[++r] = i;
if (i >= k) ... //此时que[l]为区间内满足某条件的数，对其进行操作

//删除队首元素
++l;

//删除队尾元素
--r;

//判断队列是否为空
if (l > r) return "empty";
else return "not empty";