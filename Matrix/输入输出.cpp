template <class T> istream &operator >>(istream &input, Matrix <T> &A)//读入
{
    for (int i = 1; i <= A.r; ++i)
        for (int j = 1; j <= A.c; ++j)
            input >> A[i][j];
    return input;
}
template <class T> ostream &operator <<(ostream &output, Matrix <T> A)//输出
{
    if (A.r == 0 || A.c == 0) return output;
    output << A[1][1];
    for (int j = 2; j <= A.c; ++j)
        cout << ' ' << A[1][j];
    for (int i = 2; i <= A.r; ++i)
    {
        cout << endl;
        output << A[i][1];
        for (int j = 2; j <= A.c; ++j)
            cout << ' ' << A[i][j];
    }
    return output;
}
