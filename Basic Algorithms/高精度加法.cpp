vector <int> add(vector <int> &A, vector <int> &B)
{
    vector <int> temp; int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); ++i)
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        temp.push_back(t % 10);
        t /= 10;
    }
    if (t) temp.push_back(t);
    return temp;
}