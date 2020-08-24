int qfind(int a[], int l, int r, int k)
{
    if (l == r) return a[l];
    int i = l - 1, j = r + 1, mid = a[l + r >> 1];
    while (i < j)
    {
        do ++i; while (a[i] < mid);
        do --j; while (a[j] > mid);
        if (i < j) swap(a[i], a[j]);
    }
    int len = j - l + 1;
    if (len >= k) return qfind(a, l, j, k);
    else return qfind(a, j + 1, r, k - len);
}
