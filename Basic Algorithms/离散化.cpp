function <int(vector <int> &, int)> gtIdx = [&](vector <int> &alls, int now)
{
    return upper_bound(alls.begin(), alls.end(), now) - alls.begin() + 1;
};
//+1：从1开始
sort(alls.begin(), alls.end());
alls.erase(unique(alls.begin(), alls.end()), alls.end());