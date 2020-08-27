for (int i = 1; i <= n; ++i) S[i] = S[i - 1] + a[i]; //build
cout << S[r] - S[l - 1] << endl; //query
