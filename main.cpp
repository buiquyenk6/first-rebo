#include <bits/stdc++.h>
#define For(i, a, n) for(int i =a; i <= n; i++)
#define Ford(i, a, n) for(int i =a; i >= n; i--)
#define maxn 200001
#define MOD 1000000007
#define ll long long
#define pii pair <int, int>
#define F first
#define S second
#define PB push_back
#define bit(i, x) ((x >> i) & 1)
#define Task "MAZE"

using namespace std;
void ADD(auto &x, auto y)
{
    x += y;
    if(x >= MOD) x -= MOD;
    if(x < 0) x += MOD;
}
int n, m, k, a[20][20], dp[2000][2000];
int dd[20];
vector <int> ke[20];
int kq = 0, sl = 0;
void dequy(int u)
{
    dd[u] = 1;
    sl++;
    if(sl == n)
        kq++;
    for(auto v : ke[u])
        if(dd[v] == 0)
            dequy(v);
    dd[u] = 0;
    sl--;
}
void sub2()
{
    For(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        ke[x].PB(y);
        ke[y].PB(x);
    }
    For(i, 1, n)
        dequy(i);
    cout << kq / 2;
}
void sub3()
{
    For(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x][y] = a[y][x] = 1;
        dp[(1 << x) + (1 << y)][(1 << x) + (1 << y)] = 1;
    }
    For(x, 0, (1 << n) - 1)
        for(int y = x; y > 0; --y &= x)
            if(dp[x][y] != 0)
                For(i, 0, n - 1)
                    For(j, 0, n - 1)
                        if(!bit(i, x) && bit(j, x) && a[i][j])
                        {
                            int u = y;
                            if(bit(j, y))
                                u -= (1 << j);
                            if(u < (1 << i))
                                dp[x + (1 << i)][u + (1 << i)] += dp[x][y];
                        }
    int ans = 0;
    For(i, 0, (1 << n) - 1)
        if(__builtin_popcount(i) == k)
            ans += dp[(1 << n) - 1][i];
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen(Task".INP", "r"))
    {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> n >> m >> k;
    if(k == 2)
        sub2();
    else
        sub3();
}

