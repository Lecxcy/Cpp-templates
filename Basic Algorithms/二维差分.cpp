dif[x1][y1] += d, dif[x2 + 1][y1] -= d, dif[x1][y2 + 2] -= d, dif[x2 + 1][y2 + 1] += d; //build
for (int i = 1; i <= n; ++i) //query
    for (int j = 1; j <= m; ++j)
    {
        dif[i][j] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
        cout << a[i][j] + dif[i][j] << endl;
    }
