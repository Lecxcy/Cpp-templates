//精确查找
function <int(int)> check = [&](int mid) {};
int l, r, ans = -1;
while (l <= r)
{
    int mid = l + r >> 1, t = check(mid);
    if (!t)
    {
        ans = mid; break;
    }
    else
    {
        if (t > 0) r = mid - 1;
        else l = mid + 1;
    }
}
//满足某条件的最大值
function <bool(int)> check = [&](int mid) {};
int l, r, ans = l;
while (l <= r)
{
    int mid = l + r >> 1;
    if (check(mid)) ans = mid, l = mid + 1;
    else r = mid - 1;
}
//满足某条件的最小值
function <bool(int)> check = [&](int mid) {};
int l, r, ans = l;
while (l <= r)
{
    int mid = l + r >> 1;
    if (check(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
}