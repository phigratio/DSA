#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll sz = 1e6 + 1;
#define pb push_back
#define f first
#define s second
bool vis[sz];
ll n, m;
vector<ll> ans;
vector<vector<ll>> adj(sz);
void dfs(ll i)
{
  vis[i] = true;
  for (auto x : adj[i])
  {
    if (!vis[x])
      dfs(x);
  }
}
void muqtu()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    ll x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }

  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      ans.pb(i);
      dfs(i);
    }
    }
  cout << ans.size() - 1 << endl;
  for (int i = 0; i < ans.size() - 1; i++)
  {
    cout << ans[i] << " " << ans[i + 1] << endl;
  }
}
int main()
{
  faster;
  ll t;
  t = 1;
  while (t--)
  {
    muqtu();
  }
  return 0;
}