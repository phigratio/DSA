#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
vector<vector<ll>> adj(maxi);
vector<bool> vis(maxi, false);
ll n, k;
vector<ll> arr(maxi + 1);

ll dfs(ll i)
{
  vis[i] = true;
  ll mini = arr[i];
  for (auto j : adj[i])
  {

    if (!vis[j])
    {
      vis[j] = true;
      mini = min(mini, dfs(j));
    }
  }
  return mini;
}
int main()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  for (int i = 1; i <= k; i++)
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