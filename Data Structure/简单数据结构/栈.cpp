//初始化
const int MAXN = 1e5 + 10;
int st[MAXN], top = 0;

//添加元素
st[++top] = x;

//删除元素
--top;

//访问栈顶元素
return st[top];

//判断栈是否为空
if (!top) return "empty";
else return "not empty";