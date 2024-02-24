#include <bits/stdc++.h>
using namespace std;

#define FASTIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
using ll = long long;
const ll INF = 1e18;

int main()
{
  FASTIO
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, -c});
  }
  ll dist[n + 1];
  for (int i = 0; i <= n; i++)
    dist[i] = INF;
  dist[1] = 0;
  bool flag = false;
  for (int i = 1; i <= n; i++)
  {
    for (auto e : edges)
    {
      if (dist[get<0>(e)] < INF)
      {
        if (dist[get<0>(e)] + (ll)get<2>(e) < dist[get<1>(e)])
        {
          dist[get<1>(e)] = dist[get<0>(e)] + (ll)get<2>(e);
          if (i == n)
            flag = true;
        }
      }
    }
  }
  if (flag)
    cout << "-1\n";
  else
    cout << -dist[n] << "\n";

  return 0;
}