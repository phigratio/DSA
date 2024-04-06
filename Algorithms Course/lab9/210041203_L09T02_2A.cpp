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

void muqtu()
{
  ll n;
  cin >> n;
  vector<int> nums(n);
  int totalSum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
    totalSum += nums[i];
  }
  if (totalSum % 2 != 0)
  {
    cout << "false\n";
    return;
  }

  int targetSum = totalSum / 2;
  vector<bool> dp(targetSum + 1, false);
  dp[0] = true;

  for (int num : nums)
  {
    for (int j = targetSum; j >= num; j--)
    {
      dp[j] = dp[j] || dp[j - num];
    }
  }

  cout << (dp[targetSum] ? "true" : "false") << endl;
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
