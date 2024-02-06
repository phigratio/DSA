#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
vector<vector<int>> adj(maxi);
vector<bool> vis(maxi);
vector<bool> color(maxi);
bool pos;
vector<ll> ans[2];
void dfs(ll u, ll col)
{
  if (vis[u])
  {
    if (color[u] != col)
    {
      cout << "-1" << endl;
    }
    return;
  }
  vis[u] = 1;
  color[u] = col;
  ans[col].push_back(u);
  for (auto v : adj[u])
    dfs(v, 1 - col);
}

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

  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
      dfs(i, 0ll);
  }
  for (int i = 0; i < 2; i++)
  {
    cout << ans[i].size() << endl;
    for (auto x : ans[i])
      cout << x << " ";
    cout << endl;
  }

  return 0;
}
