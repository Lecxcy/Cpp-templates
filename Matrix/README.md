# 使用说明
1、矩阵下标统一从1开始计算。  
2、Matrix类和Square类可以互相转换。  
3、在使用快速幂和幂次求和时尽量使用Square。  
4、在需要取模时用所有注释掉的取模代码替换原程序。  
## 1、定义
```cpp
Matrix <int> A; //定义矩阵A
Square <int> A; //定义方阵A
```
## 2、获取元素
```cpp
Matrix <int> A;
A[i][j] //获取第i行第j列的元素
```
## 3、运算
```cpp
Matrix <int> A, B, C;
int MOD;
C = A + B; //加法
C = A - B; //减法
C = A * B; //乘法 注意A.c必须和B.r相等，否则会报错
C = A % MOD; //取模
A += B; //自加
A -= B; //自减
A *= B; //自乘
A %= MOD; //自模

Square <int> S, T;
int pow;
T = S ^ pow; //快速幂
S ^= pow; //自乘
T = S & pow; //计算S ^ 0 ~ S ^ pow求和
```
## 4、输入输出
```cpp
Matrix <int> A;
cin >> A; //读入
cout << A << endl; //输出
```
## 5、例程(不包含模板)
```cpp
//POJ 3233
int main()
{
    int n, k; cin >> n >> k >> MOD;
    Square <int> A(n); cin >> A;
    cout << ((A & k) - (A & 0)) % MOD << endl;
    return 0;
}
```
