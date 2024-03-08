#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<ll> arr(10000007);
vector<ll> dp(10000007, 0);
int main()
{
  ll n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  dp[0] = 1;
  for (int i = 0; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[j] <= i)
      {
        dp[i] = (dp[i] + dp[i - arr[j]]) % MOD;
      }
    }
  }

  cout << dp[x] << endl;
}