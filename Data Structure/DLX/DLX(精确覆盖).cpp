const int MAXR = 500 + 10;
const int MAXC = 500 + 10;
const int MAXN = MAXR * MAXC;
class DLX
{
public:
    int idx;
    int l[MAXN], r[MAXN], u[MAXN], d[MAXN];
    int row[MAXN], col[MAXN];//记录第i个节点所在的列与行
    int colNodeNum[MAXC], rowBackIdx[MAXR];//记录第i列的节点个数与第i行末尾的节点编号
    int ansLen, ans[MAXR];

    void init(int tr, int tc)
    {
        for (int i = 0; i <= tc; ++i)//0为head节点，1~m为第i列头节点
        {
            l[i] = i - 1, r[i] = i + 1;
            u[i] = d[i] = i;
        }
        l[0] = tc, r[tc] = 0;
        memset(colNodeNum, 0, sizeof(colNodeNum));
        memset(rowBackIdx, 0, sizeof(rowBackIdx));
        idx = tc; ansLen = 0;
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
        ++colNodeNum[tc];
    }

    void remove(int tc)
    {
        r[l[tc]] = r[tc], l[r[tc]] = l[tc];
        for (int i = d[tc]; i != tc; i = d[i])
            for (int j = r[i]; j != i; j = r[j])
                d[u[j]] = d[j], u[d[j]] = u[j], colNodeNum[col[j]]--;
    }

    void resume(int tc)
    {
        for (int i = u[tc]; i != tc; i = u[i])
            for (int j = l[i]; j != i; j = l[j])
                d[u[j]] = j, u[d[j]] = j, colNodeNum[col[j]]++;
        r[l[tc]] = tc, l[r[tc]] = tc;
    }

    bool dance(int deep)//deep从1开始
    {
        if (r[0] == 0)
        {
            ansLen = deep - 1; return 1;
        }
        int c = r[0];
        for (int i = r[0]; i; i = r[i])
            if (colNodeNum[i] < colNodeNum[c]) c = i;
        remove(c);
        for (int i = d[c]; i != c; i = d[i])
        {
            ans[deep] = row[i];
            for (int j = r[i]; j != i; j = r[j]) remove(col[j]);
            if (dance(deep + 1)) return 1;
            else for (int j = l[i]; j != i; j = l[j]) resume(col[j]);
        }
        resume(c);
        return 0;
    }
}dlx;
