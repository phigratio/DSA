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
  vector<ll> arr(n);
  vector<ll> parent(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    parent[arr[i]]++;
  }
  cout << n - 1 << " ";
  for (int i = 2; i <= n; i++)
  {
    cout << parent[i] << " ";
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