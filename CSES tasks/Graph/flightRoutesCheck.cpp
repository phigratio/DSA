#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxi 1e5 + 10

vector<pair<ll, pair<ll, ll>>> adj;
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
    parent[i] = i;
  }
}

ll find(ll src)
{
  if (parent[src] == src)
  {
    return src;
  }
  else
  {
    return parent[src] = find(parent[src]);
  }
}

bool join(ll src, ll dest)
{
  ll s1 = find(src);
  ll s2 = find(dest);

  if (s1 == s2)
  {
    return false;
  }
  else
  {
    parent[s1] = s2;
    return true;
  }
}

int main()
{
  faster;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    ll src, dest;
    cin >> src >> dest;
    src--, dest--;
    adj.pb({1, {src, dest}});
  }

  DSU();
  sort(adj.begin(), adj.end());

  ll count = 0;
  for (int i = 0; i < m; i++)
  {
    ll src = adj[i].second.first;
    ll dest = adj[i].second.second;

    if (join(src, dest))
    {
      count++;
    }
  }

  if (count == n - 1)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}
