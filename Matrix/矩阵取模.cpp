template <class T> Matrix <T> operator %(Matrix <T> A, int M)//模
{
    Matrix <T> C(A.r, A.c);
    for (int i = 1; i <= C.r; ++i)
        for (int j = 1; j <= C.c; ++j)
            C[i][j] = (A[i][j] % M + M) % M;
    return C;
}
