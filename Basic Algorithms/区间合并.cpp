struct seg
{
    int l, r;
    bool operator <(seg others)
    {
        if (l == others.l) return r < others.r;
        else return l < others.l;
    }
};
vector <seg> unite(vector <seg> &a)
{
    vector <seg> ans;
    if (a.empty()) return ans; //小心re
    sort(a.begin(), a.end());
    int l = a[0].l, r = a[0].r;
    for (int i = 1; i < a.size(); ++i)
        if (a[i].l <= r) r = max(r, a[i].r);
        else ans.push_back({l, r}), l = a[i].l, r = a[i].r;
    ans.push_back({l, r});
    return ans;
}