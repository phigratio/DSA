#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll maxi = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define pb push_back
#define f first
#define s second
vector<vector<int>> adj(maxi);
vector<ll> subSize(maxi);
void muqtu()
{
  ll n;
  cin >> n;
  vector<ll> arr(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    cin >> arr[i];
  }
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