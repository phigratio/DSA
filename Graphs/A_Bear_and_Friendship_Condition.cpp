#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj(1e6 + 1);
vector<ll> renk(1e6 + 1);
vector<ll> parent(1e6 + 1);
vector<ll> size(1e6 + 1);
ll n, m;
void DSU()
{
  for (int i = 0; i < n; i++)
  {
    parent[i] = -1;
    renk[i] = 1;
  }
}
ll find(ll x)
{
  if (-1 == parent[x])
  {
    return x;
  }
  return parent[x] = find(parent[x]);
}
void merge(ll a, ll b)
{
  ll x = find(a);
  ll y = find(b);

  if (x == y)
  {
    return;
  }
  else if (renk[x] > renk[y])
  {
    parent[y] = x;
    renk[x] += renk[y];
  }
  else
  {
    parent[x] = y;
    renk[y] += renk[x];
  }
}
void solve()
{
  cin >> n >> m;
  DSU();
  for (int i = 0; i < m; i++)
  {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);

    merge(a, b);
  }
  bool flag = true;
  map<ll, ll> mp;
  for (int i = 1; i <= n; i++)
  {
    mp[find(i)]++;
  }
  for (int i = 1; i <= n; i++)
  {
    if (adj[i].size() != mp[find(i)] - 1)
    {
      flag = false;
      break;
    }
  }

  if (flag)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}
int main()
{
  ll t;
  t = 1;
  while (t--)
  {
    solve();
  }
}