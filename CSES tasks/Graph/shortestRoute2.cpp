#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
#define maxi 1000000000000

ll dis[N][N];

int main()
{
  ll n, m, q;
  cin >> n >> m >> q;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      dis[i][j] = maxi;
    }
  }

  for (int i = 0; i < m; i++)
  {
    ll a, b, w;
    cin >> a >> b >> w;
    dis[a][a] = 0, dis[b][b] = 0;
    dis[a][b] = min(dis[a][b], w),
    dis[b][a] = min(dis[b][a], w);
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }

  for (int i = 0; i < q; i++)
  {
    ll src, dest;
    cin >> src >> dest;

    if (dis[src][dest] < maxi)
      cout << dis[src][dest] << " " << endl;
    else
      cout << -1 << endl;
  }

  return 0;
}
