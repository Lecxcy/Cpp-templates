//加了两个剪枝，速度比大部分网上能找到的模板要快
const int MAXR = 500 + 10;
const int MAXC = 500 + 10;
const int MAXN = MAXR * MAXC;
const int INF = 0x3f3f3f3f;
class Node//剪枝1：考虑贪心地选取每次选定的行，节点越多越优
{
public:
    int idx, num;
    Node() {}
    Node(int a, int b): idx(a), num(b) {}
};
bool cmp(Node x, Node y)
{
    return x.num > y.num;
}
class DLX//重复覆盖
{
public:
    int idx;
    int l[MAXN], r[MAXN], u[MAXN], d[MAXN];
    int row[MAXN], col[MAXN];//记录第i个节点所在的列与行
    int colDelNum[MAXC], colNodeNum[MAXC], rowNodeNum[MAXR], rowBackIdx[MAXR];
    //记录第i列被删的次数、第i列的节点个数、第i行的节点个数与第i行末尾的节点编号
    int ansLen;

    void init(int tr, int tc)
    {
        for (int i = 0; i <= tc; ++i)//0为head节点，1~m为第i列头节点
        {
            l[i] = i - 1, r[i] = i + 1;
            u[i] = d[i] = i;
        }
        l[0] = tc, r[tc] = 0;
        memset(colDelNum, 0, sizeof(colDelNum));
        memset(colNodeNum, 0, sizeof(colNodeNum));
        memset(rowNodeNum, 0, sizeof(rowNodeNum));
        memset(rowBackIdx, 0, sizeof(rowBackIdx));
        idx = tc; ansLen = INF;
    }

    void insert(int tr, int tc)
    {
        ++idx;
        row[idx] = tr, col[idx] = tc;
        u[idx] = u[tc]; d[idx] = tc;//修改当前节点的四个指针
        u[d[idx]] = idx; d[u[idx]] = idx;//修改指向节点的指针
        if (rowBackIdx[tr])
        {
            l[idx] = rowBackIdx[tr]; r[idx] = r[rowBackIdx[tr]];
            r[l[idx]] = idx; l[r[idx]] = idx;
        }
        else l[idx] = r[idx] = idx;
        rowBackIdx[tr] = idx;
        ++colNodeNum[tc]; ++rowNodeNum[tr];
    }

    inline void remove(int tc)
    {
        r[l[tc]] = r[tc], l[r[tc]] = l[tc];
        for (int i = d[tc]; i != tc; i = d[i]) rowNodeNum[row[i]]--;
    }

    inline void resume(int tc)
    {
        r[l[tc]] = tc, l[r[tc]] = tc;
        for (int i = u[tc]; i != tc; i = u[i]) rowNodeNum[row[i]]++;
    }

    int leave()//剪枝2：利用精确覆盖剪枝
    {
        int ret = 0;
        bool vis[MAXC] = {0};
        for (int i = r[0]; i; i = r[i])
        {
            if (!vis[i])
            {
                vis[i] = 1; ++ret;
                for (int j = d[i]; j != i; j = d[j])
                    for (int k = r[j]; k != j; k = r[k])
                        vis[col[k]] = 1;
            }
        }
        return ret;
    }

    void dance(int deep)//deep从1开始
    {
        if (deep - 1 + leave() >= ansLen) return;
        if (r[0] == 0)
        {
            ansLen = deep - 1; return;
        }
        int c = r[0];
        for (int i = r[0]; i; i = r[i])
            if (colNodeNum[i] < colNodeNum[c]) c = i;
        remove(c); colDelNum[c]++;
        Node temp[MAXR]; int cnt = 0;
        for (int i = d[c]; i != c; i = d[i]) temp[++cnt] = Node(i, rowNodeNum[row[i]]);
        sort(temp + 1, temp + 1 + cnt, cmp);

        for (int p = 1; p <= cnt; ++p)
        {
            int i = temp[p].idx;
            for (int j = r[i]; j != i; j = r[j]) if (!colDelNum[col[j]]++) remove(col[j]);
            dance(deep + 1);
            for (int j = l[i]; j != i; j = l[j]) if (!--colDelNum[col[j]]) resume(col[j]);
        }

        resume(c); colDelNum[c]--;
        return;
    }
}dlx;
