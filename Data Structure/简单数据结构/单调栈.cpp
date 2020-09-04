//初始化
const int MAXN = 1e5 + 10;
int st[MAXN], top = 0;

//添加元素
while (top && check(st[top], i)) --top;
//此时st[top]为i前第一个满足某性质元素的下标
st[++top] = i;

//删除元素
--top;

//访问栈顶元素
return st[top];

//判断栈是否为空
if (!top) return "empty";
else return "not empty";