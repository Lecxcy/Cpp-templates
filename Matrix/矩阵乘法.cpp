template <class T> Matrix <T> operator *(Matrix <T> A, Matrix <T> B)//乘
{
    if (A.c != B.r) throw;
    Matrix <T> C(A.r, B.c);
    for (int i = 1; i <= A.r; ++i)
        for (int j = 1; j <= A.c; ++j)
            if (A[i][j])//稀疏矩阵优化
            {
                for (int k = 1; k <= B.c; ++k)
                    C[i][k] += A[i][j] * B[j][k];
                    //!!此处有必要时添加取模:C[i][k] = (C[i][k] + (A[i][j] % MOD) * (B[j][k] % MOD)) % MOD;!!
            }
    return C;
}
