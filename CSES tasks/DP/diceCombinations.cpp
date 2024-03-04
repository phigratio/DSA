#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long
vector<ll> dp(N, 0);
#define MOD 1000000007
void dyni(ll x)
{
  dp[0] = 1;
  for (int i = 1; i <= x; i++)
  {
    for (int j = 1; j <= 6; j++)
    {
      if (j <= i)
      {
        dp[i] = (dp[i] + dp[i - j]) % MOD;
      }
    }
  }

  cout << dp[x] << endl;
}
int main()
{
  ll n;
  cin >> n;

  dyni(n);
}