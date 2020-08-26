bool cmp(string &a, string &b)
{
    if (a.length() != b.length()) return a.length() < b.length();
    else
    {
        for (int i = 0; i < a.length(); ++i)
            if (a[i] != b[i]) return a[i] < b[i];
    }
    return 0;
}
vector <int> sub(vector <int> &A, vector <int> &B)
{
    vector <int> temp; int t = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        temp.push_back((t + 10) % 10);
        if (t < 0) t = 1; else t = 0;
    }
    while (temp.size() > 1 && temp.back() == 0) temp.pop_back();
    //去前导0 注意要留至少一位数
    return temp;
}