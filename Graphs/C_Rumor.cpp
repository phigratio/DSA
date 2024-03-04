#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxi 100005
vector<vector<int>> adj(maxi);
vector<bool> vis(maxi, false);
vector<ll> weight(1e6);
ll dfs(ll i)
{
  ll mini = weight[i];
  vis[i] = true;
  for (auto j : adj[i])
  {
    if (!vis[j])
    {
      mini = min(mini, dfs(j));
    }
  }
  return mini;
}
int main()
{
  ll n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> weight[i];
  }

  for (int i = 0; i < m; i++)
  {
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      ans += dfs(i);
    }
  }

  cout << ans << endl;
}
