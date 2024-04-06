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
#define s second
ll dp[104][100005];
vector<ll> wt(101), val(101);
ll dyni(ll ind, ll remWt)
{
  if (remWt == 0)
    return 0;
  if (ind < 0)
    return 0;
  if (dp[ind][remWt] != -1)
    return dp[ind][remWt];
  ll ans = dyni(ind - 1, remWt);
  if (remWt - wt[ind] >= 0)
    ans = max(ans, dyni(ind - 1, remWt - wt[ind]) + val[ind]);
  return dp[ind][remWt] = ans;
}
void muqtu()
{
  memset(dp, -1, sizeof(dp));
  ll n, w;
  cin >> n >> w;
  for (int i = 0; i < n; i++)
  {
    cin >> wt[i] >> val[i];
  }

  cout << dyni(n - 1, w);
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