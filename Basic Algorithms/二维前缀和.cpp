for (int i = 1; i <= n; ++i) //build
    for (int j = 1; j <= m; ++j)
        S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
cout << S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][x1 - 1] << endl; //query