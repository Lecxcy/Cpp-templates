//字符型
//初始化
const int MAXN = 1e5 + 10;
int son[MAXN][26], cnt[MAXN], idx;
//插入
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; ++i)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
//查询
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; ++i)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

//数字型
//初始化
const int MAXN = 1e5 + 10;
int son[MAXN][2], cnt[MAXN], idx;
//插入
void insert(int x)
{
    int p = 0;
    for (int i = 31; i >= 0; --i)
    {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
//查询
int query(int x)
{
    int p = 0;
    for (int i = 31; i >= 0; --i)
    {
        int u = x >> i & 1;
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}