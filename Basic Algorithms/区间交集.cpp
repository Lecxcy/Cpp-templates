struct seg
{
    int l, r;
    bool operator <(seg others)
    {
        if (l == others.l) return r < others.r;
        else return l < others.l;
    }
};

seg intersec(vector <seg> &a) //若无交集，返回值l > r
{
    int l = -INF, r = INF;
    for (int i = 0; i < n; ++i)
    {
        l = max(l, a[i].l), r = min(r, a[i].r);
        if (l > r) return {l, r};
        //有交集时的逻辑
    }
    return {l, r};
}