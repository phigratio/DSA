#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define pb push_back
#define f first
#define s second

void muqtu()
{
  ll n;
  cin >> n;
  ll arr[n][3];
  ll dp[n + 1][3];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }

  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = dp[i][1] = dp[i][2] = 0;
  }

  for (int i = 1; i <= n; i++)
  {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i - 1][0];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i - 1][1];
    dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i - 1][2];
  }

  cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
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