#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll maxi = 1e5 + 1;
#define pb push_back
#define f first
#define s second
const ll N = 101;
vector<ll> v(N);
vector<ll> w(N);
ll W, n;
ll minWt[N][maxi];
ll dp[N][maxi];
void muqtu()
{
  cin >> n >> W;
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i] >> v[i];
  }
  for (int i = 0; i <= n; i++)
  {
    for (int val = 0; val < maxi; val++)
    {
      minWt[i][val] = INF;
    }
  }
  dp[0][0] = 1;
  minWt[0][0] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int val = 0; val < maxi; val++)
    {
      if (dp[i - 1][val])
      {
        dp[i][val] = 1;
        minWt[i][val] = min(minWt[i][val], minWt[i - 1][val]);
      }
      if (val - v[i] >= 0 && dp[i][val - v[i]] && minWt[i - 1][val - v[i]] + w[i] <= W)
      {
        dp[i][val] = 1;
        minWt[i][val] = min(minWt[i][val], minWt[i - 1][val - v[i]] + w[i]);
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < maxi; i++)
  {
    if (dp[n][i])
      ans = i;
  }
  cout << ans << endl;

  return;
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