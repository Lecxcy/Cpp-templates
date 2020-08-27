dif[l] += d, dif[r + 1] -= d; //build
for (int i = 1, s = 0; i <= n; ++i)
    s += dif[i], cout << a[i] + s << endl; //query
