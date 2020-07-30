//单位阵可以用A^0获取
template <class T> Square <T> operator ^(Square <T> A, int num)//乘方
{
    int n = A.r;
    Square <T> ans(n);
    for (int i = 1; i <= n; ++i) ans[i][i] = 1;
    while (num)
    {
        if (num & 1) ans *= A; //!!此处有必要时添加取模:ans = (ans * A) % MOD;!!
        A *= A;//!!此处有必要时添加取模:A = (A * A) % MOD;!!
        num >>= 1;
    }
    return ans;
}
