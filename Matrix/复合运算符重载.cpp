//需要使用时在声明中去除斜杠
template <class T> Matrix <T> &Matrix <T>::operator +=(Matrix <T> A)//自加
{
    if (A.r != r || A.c != c) throw;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            v[i][j] += A[i][j];
            //!!此处有必要时添加取模:v[i][j] = (v[i][j] % MOD + A[i][j] % MOD) % MOD;!!
    return *this;
}
template <class T> Matrix <T> &Matrix <T>::operator -=(Matrix <T> A)//自减
{
    if (A.r != r || A.c != c) throw;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            v[i][j] -= A[i][j];
            //!!此处有必要时添加取模(注意负数):v[i][j] = ((v[i][j] % MOD - A[i][j] % MOD) % MOD + MOD) % MOD!!
    return *this;
}
template <class T> Matrix <T> &Matrix <T>::operator *=(Matrix <T> B)//自乘
{
    if (c != B.r) throw;
    Matrix <T> C(r, B.c);
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (v[i][j])//稀疏矩阵优化
            {
                for (int k = 1; k <= B.c; ++k)
                    C[i][k] += v[i][j] * B[j][k];
                    //!!此处有必要时添加取模:C[i][k] = (C[i][k] + (v[i][j] % MOD) * (B[j][k] % MOD)) % MOD;!!
            }
    c = B.c;
    v.clear(); v.resize(r + 1);
    for (int i = 0; i <= r; ++i) v[i].resize(c + 1);
    for (int i = 0; i <= r; ++i)
        for (int j = 0; j <= c; ++j)
            v[i][j] = C[i][j];
    return *this;
}
template <class T> Matrix <T> &Matrix <T>::operator %=(int M)//自模
{
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            v[i][j] = ((v[i][j] % M) + M) % M;
    return *this;
}
template <class T> Square <T> &Square <T>::operator ^=(int num)//乘方
{
    int n = Matrix <T>::r;
    Square <T> ans(n), temp(*this);
    for (int i = 1; i <= n; ++i) ans[i][i] = 1;
    while (num)
    {
        if (num & 1) ans *= temp;//!!此处有必要时添加取模:ans = (ans * temp) % MOD;!!
        temp *= temp;//!!此处有必要时添加取模:temp = (temp * temp) % MOD;!!
        num >>= 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            Matrix <T>::v[i][j] = ans[i][j];
    return *this;
}
