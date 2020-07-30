# 使用说明
1、空行对程序运行效率几乎没有影响。  
2、舞蹈链的列数是关键。初始化时列数一定要正确。  
3、两个模板答案的形式不一样。  
4、多重覆盖中的两个剪枝只能用于求最少覆盖行数。  
## 1、初始化
```cpp
dlx.init(MAXR, MAXC); //MAXR行MAXC列
```
## 2、插入节点
```cpp
dlx.insert(r, c); //在第r行第c列插入一个节点
```
## 3、执行
```cpp
dlx.dance(1);
```
## 4、获取答案
```cpp
if (!dlx.dance(1)) cout << "No solution!" << endl;
else for (int i = 1; i <= dlx.ansLen; ++i) cout << dlx.ans[i] << ' '; //精确覆盖

cout << dlx.ansLen << endl; //多重覆盖
```
## 5、例程(不包含模板)
```cpp
//Luogu 4929 精确覆盖
int main()
{
    int n, m; cin >> n >> m;
    dlx.init(n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int x; cin >> x;
            if (x) dlx.insert(i, j);
        }
    if (!dlx.dance(1)) cout << "No Solution!" << endl;
    else
    {
        for (int i = 1; i <= dlx.ansLen; ++i) cout << dlx.ans[i] << ' ';
        cout << endl;
    }
    return 0;
}
```
```cpp
//FZU 1686 多重覆盖
const int MAXNUM = 20;
int mp[MAXNUM][MAXNUM];
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        vector < pair <int, int> > pos;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &mp[i][j]);
                if (mp[i][j]) pos.push_back(make_pair(i, j));
            }
        int n1, m1; scanf("%d%d", &n1, &m1);
        dlx.init((n - n1 + 1) * (m - m1 + 1), pos.size());
        for (int i = 0; i < pos.size(); ++i)
        {
            int lx = max(pos[i].first - n1 + 1, 1), ly = max(pos[i].second - m1 + 1, 1);
            int rx = min(pos[i].first, n - n1 + 1), ry = min(pos[i].second, m - m1 + 1);
            for (int dx = lx; dx <= rx; ++dx)
                for (int dy = ly; dy <= ry; ++dy)
                    dlx.insert((dx - 1) * (m - m1 + 1) + dy, i + 1);
        }
        dlx.dance(1);
        cout << dlx.ansLen << endl;
    }
    return 0;
}
```
