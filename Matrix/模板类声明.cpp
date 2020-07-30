//erase the slashes when needed
//int MOD;
template <class T> class Matrix
{
public:
    int r, c;
    vector < vector <T> > v;
    Matrix()
    {
        r = c = 0;
        v.clear();
    }
    Matrix(int a, int b): r(a), c(b)
    {
        v.resize(r + 1);
        for (int i = 0; i <= r; ++i) v[i].resize(c + 1);
        for (int i = 0; i <= r; ++i)
            for (int j = 0; j <= c; ++j)
                v[i][j] = 0;
    }
    void clear()
    {
        for (int i = 0; i <= r; ++i)
            for (int j = 0; j <= c; ++j)
                v[i][j] = 0;
    }
    vector <T> &operator [](int x) { return v[x]; }
    //Matrix <T> &operator +=(Matrix <T>);
    //Matrix <T> &operator -=(Matrix <T>);
    //Matrix <T> &operator *=(Matrix <T>);
    //Matrix <T> &operator %=(int);
};
template <class T> class Square: public Matrix <T>
{
public:
    Square(): Matrix <T>() {}
    Square(int n): Matrix <T>(n, n) {}
    Square(int a, int b)
    {
        if (a != b) throw;
        Matrix <T>::r = a, Matrix <T>::c = b;
        Matrix <T>::v.resize(a + 1);
        for (int i = 0; i <= a; ++i) Matrix <T>::v[i].resize(b + 1);
        for (int i = 0; i <= a; ++i)
            for (int j = 0; j <= b; ++j)
                Matrix <T>::v[i][j] = 0;
    }
    Square(Matrix <T> A)
    {
        int mini = min(A.r, A.c);
        Matrix <T>::v.resize(mini + 1);
        Matrix <T>::r = Matrix <T>::c = mini;
        for (int i = 0; i <= mini; ++i) Matrix <T>::v[i].resize(mini + 1);
        for (int i = 1; i <= mini; ++i)
            for (int j = 1; j <= mini; ++j)
                Matrix <T>::v[i][j] = A[i][j];
    }
    operator Matrix <T>()
    {
        Matrix <T> A(Matrix <T>::r, Matrix <T>::c);
        for (int i = 1; i <= Matrix <T>::r; ++i)
            for (int j = 1; j <= Matrix <T>::c; ++j)
                A[i][j] = Matrix <T>::v[i][j];
        return A;
    }
    //Square <T> &operator ^=(int);
};
