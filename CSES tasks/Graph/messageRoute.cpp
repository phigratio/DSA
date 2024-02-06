#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
vector<vector<int>> adj(maxi);
vector<bool> vis(maxi, false);
vector<ll> par(maxi);
vector<ll> dist(maxi);
queue<int> q;

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  q.push(1);
  vis[1] = true;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int v : adj[u])
    {
      if (!vis[v])
      {
        dist[v] = dist[u] + 1;
        vis[v] = true;
        par[v] = u;
        q.push(v);
      }
    }
  }

  if (!vis[n])
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  int u = n;
  int k = dist[n];
  vector<int> ans(k + 1);
  for (int i = k; i >= 0; i--)
  {
    ans[i] = u;
    u = par[u];
  }

  cout << k + 1 << endl;
  for (int i = 0; i <= k; i++)
  {
    cout << ans[i] << " ";
  }
}