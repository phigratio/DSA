#include <bits/stdc++.h>
using namespace std;

#define FASTIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

bool flag;
#define ll long long
const ll INF = 1e18;
const ll NINF = (-1) * INF;

vector<int> vis(1e5 + 1, 0), vis1(1e5 + 1, 0);
vector<pair<ll, pair<ll, ll>>> adj;
vector<vector<ll>> adj2;
vector<vector<ll>> adj3;
ll n, m;
vector<ll> dist(1e5 + 1, INF);

void dfs(int u)
{
  vis[u] = 1;
  for (auto v : adj2[u])
    if (!vis[v])
      dfs(v);
}

void dfs2(int u)
{
  vis1[u] = 1;
  for (auto v : adj3[u])
    if (!vis1[v])
      dfs2(v);
}

void bellmanFord(ll src, ll dest)
{
  dist[src] = 0;

  for (int i = 0; i < n; i++)
  {
    flag = false;

    for (auto j : adj)
    {
      ll u = j.second.first;
      ll v = j.second.second;
      ll w = j.first;

      if (vis[u] and vis1[v] and dist[u] + w < dist[v])
      {
        flag = true;
        dist[v] = dist[u] + w;
      }
    }
  }

  if (flag)
  {
    cout << -1 << endl;
  }
  else
  {
    if (dist[dest] == INF)
      cout << -1 << endl;
    else
      cout << dist[dest] << endl;
  }
}

int main()
{
  FASTIO

  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    ll u, v;
    ll w;
    cin >> u >> v >> w;
    adj[i] = {w, {u, v}};
    adj2[v].push_back(u);
    adj3[u].push_back(v);
  }

  dfs(1);
  dfs2(n);

  bellmanFord(1, n);

  return 0;
}
