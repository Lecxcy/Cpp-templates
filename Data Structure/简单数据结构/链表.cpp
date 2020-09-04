//初始化
const int MAXN = 1e5 + 10;
int e[MAXN], ne[MAXN], idx = 0;
ne[0] = -1;

//添加元素(链表头)
e[++idx] = x, ne[idx] = ne[0], ne[0] = idx;

//删除元素
ne[k] = ne[ne[k]];

//遍历链表
for (int i = ne[0]; i != -1; i = ne[i]) cout << e[i] << ' ';