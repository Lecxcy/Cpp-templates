//原理：利用分块矩阵
//(A, E)
//(0, E)
//用递归写很慢
template <class T> Square <T> operator &(Square <T> A, int num)//A^0~A^n求和
{
    Square <T> temp(A.r * 2, A.c * 2);
    for (int i = 1; i <= A.r; ++i)
        for (int j = 1; j <= A.c; ++j)
            temp[i][j] = A[i][j];
    for (int i = A.c + 1; i <= A.c * 2; ++i) temp[i - A.c][i] = 1;
    for (int i = A.r + 1; i <= A.r * 2; ++i) temp[i][i] = 1;
    temp ^= num + 1;
    Square <T> ans(A.r, A.c);
    for (int i = 1; i <= A.r; ++i)
        for (int j = 1; j <= A.c; ++j)
            ans[i][j] = temp[i][j + A.c];
    return ans;
}
