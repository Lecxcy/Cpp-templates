//初始化
const int MAXN = 1e5 + 10;
int que[MAXN], l = 1, r = 0;

//添加元素
que[++r] = x;

//删除元素
++l;

//访问队首元素
return que[l];

//访问队尾元素
return que[r];

//判断队列是否为空
if (l > r) return "empty";
else return "not empty";