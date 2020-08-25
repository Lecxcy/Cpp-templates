//满足某条件的最大值
const double eps = 1e-8;
function <bool(double)> check = [&](double mid) {};
double l, r, ans = l;
while (r - l > eps)
{
    double mid = l + (r - l) / 2;
    if (check(mid)) ans = mid, l = mid;
    else r = mid;
}
//满足某条件的最小值
const double eps = 1e-8;
function <bool(double)> check = [&](double mid) {};
double l, r, ans = l;
while (r - l > eps)
{
    double mid = l + (r - l) / 2;
    if (check(mid)) ans = mid, r = mid;
    else l = mid;
}