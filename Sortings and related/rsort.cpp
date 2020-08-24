void rsort(int a[], int n)//index = 2
{
    int dig = 0;
    for (int i = 1; i <= n; ++i)
    {
        int temp = a[i], cnt = 0;
        while (temp) ++cnt, temp >>= 1;
        dig = max(dig, cnt);
    }
    for (int k = 0; k < dig; ++k)
    {
        vector <int> buk[2];
        for (int i = 1; i <= n; ++i)
            buk[(a[i] >> k) & 1].push_back(a[i]);
        int now = 0;
        for (auto &i : buk[0]) a[++now] = i;
        for (auto &i : buk[1]) a[++now] = i;
    }
}
