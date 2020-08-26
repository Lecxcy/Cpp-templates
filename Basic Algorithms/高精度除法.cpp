vector <int> div(vector <int> &A, int b, int &r)
{
    vector <int> temp;
    for (int i = A.size() - 1; i >= 0; --i)
    {
        r = r * 10 + A[i];
        temp.push_back(r / b);
        r %= b;
    }
    reverse(temp.begin(), temp.end());
    while (temp.size() > 1 && temp.back() == 0) temp.pop_back();
    return temp;
}