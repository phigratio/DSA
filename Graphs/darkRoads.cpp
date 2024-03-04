#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e5 + 10
vector<pair<ll, pair<ll, ll>>> adj;
vector<ll> renk(maxi);
vector<ll> parent(maxi);
ll n, m;
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

void DSU()
{
  for (int i = 0; i < n; i++)
  {
    renk[i] = 1;
    parent[i] = i;
  }
}

int find(ll x)
{
  if (-1 == parent[x])
  {
    return x;
  }
  else
  {
    return find(parent[x]);
  }
}

bool join(ll a, ll b)
{
  a = find(a);
  b = find(b);
  if (a == b)
  {
    return false;
  }
  else if (renk[a] > renk[b])
  {
    renk[a] += renk[b];
    parent[b] = a;
  }
  else
  {
    renk[b] += renk[a];
    parent[a] = b;
  }
  return true;
}
int main()
{
  faster;
  while (1)
  {

    cin >> n >> m;
    if (n == 0 and m == 0)
      break;

    adj.clear();
    renk.clear();
    parent.clear();
    ll mexi = 0;
    for (int i = 0; i < m; i++)
    {
      ll src, dest, weight;
      cin >> src >> dest >> weight;
      mexi += weight;
      adj.push_back({weight, {src, dest}});
      adj.push_back({weight, {dest, src}});
    }

    sort(adj.begin(), adj.end());

    ll count = 0, res = 0;
    DSU();
    for (int i = 1; i <= adj.size(); i++)
    {
      ll wt = adj[i].first;
      ll a = adj[i].second.first;
      ll b = adj[i].second.second;

      if (join(a, b))
      {
        count++;
        res += wt;
      }
      if (count == n - 1)
      {
        break;
      }
    }

    cout << mexi - res << endl;
  }
}