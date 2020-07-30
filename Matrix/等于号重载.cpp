template <class T> bool operator ==(const Matrix <T> A, const Matrix <T> B)//判断相等
{
    if (A.r != B.r || A.c != B.c) return 0;
    for (int i = 1; i <= A.r; ++i)
        for (int j = 1; j <= A.c; ++j)
            if (A[i][j] != B[i][j]) return 0;
    return 1;
}
