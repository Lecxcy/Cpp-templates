int temp[];
ll revPair(int a[], int l, int r)
{
    if (l == r) return 0;
    int mid = l + r >> 1;
    ll ans = revPair(a, l, mid) + revPair(a, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j]) temp[++k] = a[i++];
        else temp[++k] = a[j++], ans += mid - i + 1;
    }
    while (i <= mid) temp[++k] = a[i++];
    while (j <= r) temp[++k] = a[j++];
    for (int i = l, j = 1; i <= r; ++i, ++j) a[i] = temp[j];
    return ans;
}
