//数字操作
//取n的第k位数字
n >> k & 1
//返回n的最后一位1
lowbit(n) = n & -n
//删除n的最后一位1
n & (n - 1)
//判断n是否是2的幂
n && !(n & (n - 1)) //是2的幂并且非0返回1
//判断两数是否异号
(x ^ y) < 0 //异号返回1

//字符操作
//大小写转换
ch ^ ' ' //大写转小写，小写转大写
//转小写
ch | ' '
//转大写
ch & '_'

//集合操作
//取空集
0
//仅含第i个元素(i >= 0)的集合
1 << i
//含有全部n个元素的集合(0 <= i <n)
(1 << n) - 1
//插入第i个元素
S | (1 << i)
//删除第i个元素
S & ~(1 << i)
//两个集合的并集
S | T
//两个集合的交集
S & T
//枚举子集
int sub = sup;
do
{
    //operations
    sub = (sub - 1) & sup;
}
while (sub != sup);
//枚举大小为k的子集
int comb = (1 << k) - 1;
while (comb < 1 << n)
{
    //operations
    int x = comb & -comb, y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
}
//利用遮罩选取两集合中的特定元素
(a & ~mask) | (b & mask)
