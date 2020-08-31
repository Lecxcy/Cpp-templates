for (int i = 1, j = init; vaild(i, j); ++i)
{
    while (vaild(i, j) && check(i, j)) opt(j);
    // operations
}
