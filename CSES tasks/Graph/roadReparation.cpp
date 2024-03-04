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
    parent[i] = -1;
  }
}

ll find(ll src)
{
  if (parent[src] == -1)
  {
    return src;
  }
  else
  {
    return find(parent[src]);
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
  else if (renk[s1] > renk[s2])
  {
    renk[s1] += renk[s2];
    parent[s2] = s1;
  }
  else
  {
    renk[s2] += renk[s1];
    parent[s1] = s2;
  }

  return true;
}

int main()
{
  faster;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    ll src, dest, weight;
    cin >> src >> dest >> weight;
    src--, dest--;
    adj.push_back({weight, {src, dest}});
    adj.push_back({weight, {dest, src}});
  }

  DSU();
  sort(adj.begin(), adj.end());
  ll count = 0, res = 0;

  for (int i = 0; i < 2 * m; i++)
  {
    ll src = adj[i].second.first;
    ll dest = adj[i].second.second;
    ll weight = adj[i].first;

    if (join(src, dest))
    {
      count++;
      res += weight;
    }
  }

  if (count == n - 1)
    cout << res << endl;
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}
