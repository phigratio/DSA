#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll maxi = 1e6 + 1;
#define pb push_back
#define f first
vector<vector<ll>> adj(maxi);
vector<ll> subSize(maxi);
#define s second
ll dfs(ll x)
{
  if (adj[x].size() == 0)
    return 1;
  for (int i = 0; i < adj[x].size(); i++)
  {
    subSize[x] += dfs(adj[x][i]);
  }
  return subSize[x] + 1;
}
void muqtu()
{
  ll n;
  cin >> n;
  for (int i = 2; i <= n; i++)
  {
    ll boss;
    cin >> boss;
    adj[boss].pb(i);
  }
  dfs(1);
  for (ll i = 1; i <= n; i++)
  {
    cout << subSize[i] << " ";
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