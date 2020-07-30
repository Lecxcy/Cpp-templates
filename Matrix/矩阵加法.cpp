template <class T> Matrix <T> operator +(Matrix <T> A, Matrix <T> B)//加
{
    if (A.r != B.r || A.c != B.c) throw;
    Matrix <T> C(A.r, A.c);
    for (int i = 1; i <= A.r; ++i)
        for (int j = 1; j <= A.c; ++j)
            C[i][j] = A[i][j] + B[i][j];
            //!!此处有必要时添加取模:C[i][j] = (A[i][j] % MOD + B[i][j] % MOD) % MOD;!!
    return C;
}
