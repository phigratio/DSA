#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000007
ll n, i, j, k;
ll dp[4][N];
ll vis[4][N];
ll dyni(ll src, ll dest, ll x)
{
  if (x == 0)
  {
    if (src == dest)
      return 1;

    return 0;
  }

  ll ans = dp[src][x];
  if (vis[src][x])
    return ans;

  vis[src][x] = 1;

  ans = 0;

  for (int i = 0; i <= 3; i++)
  {
    if (i == src)
      continue;
    ans += dyni(i, dest, x - 1);

    if (ans >= N)
      ans -= N;
  }

  return ans;
}
int main()
{

  cin >> n;
  cout << dyni(3, 3, n) << endl;
}