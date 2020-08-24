void qsort(int a[], int l, int r)
{
    if (l == r) return;
    int i = l - 1, j = r + 1, mid = a[l + r >> 1];
    while (i < j)
    {
        do ++i; while (a[i] < mid);
        do --j; while (a[j] > mid);
        if (i < j) swap(a[i], a[j]);
    }
    qsort(a, l, j); qsort(a, j + 1, r);
}
