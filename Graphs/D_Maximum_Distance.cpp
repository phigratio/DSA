#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
#define inf 1e18 + 1
vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
vector<bool> visited;
vector<ll> ans;
ll n, m, k;
vector<ll> renk(maxi);
vector<ll> parent(maxi);
ll find(ll a)
{
  if (parent[a] == a)
    return a;
  else
  {
    return find(parent[a]);
  }
}

void merge(ll a, ll b)
{
  ll s1 = find(a);
  ll s2 = find(b);

  if (s1 == s2)
  {
    return;
  }

  if (renk[a] > renk[b])
  {
    parent[b] = a;
    renk[a] += renk[b];
  }
  else
  {
    parent[a] = b;
    renk[b] += renk[a];
  }
}
ll dfs()
{
  ll cnt = 0;
  ll num = 0;
  for (auto i : adj[])
}
int main()
{
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
    renk[i] = 0;
  }
}