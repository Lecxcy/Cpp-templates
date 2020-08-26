vector <int> mul(vector <int> &A, int b)
{
    vector <int> temp; int t = 0;
    for (int i = 0; i < A.size() || t; ++i)
    {
        if (i < A.size()) t += A[i] * b;
        temp.push_back(t % 10);
        t /= 10;
    }
    while (temp.size() > 1 && temp.back() == 0) temp.pop_back();
    return temp;
}