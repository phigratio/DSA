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
  ll a, b;
  cin >> a >> b;
  ll s = a + b;
  if (s % 3 == 0 && 2 * min(a, b) >= max(a, b))
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}
int main()
{
  faster;
  ll t;
  cin >> t; // t=1;
  while (t--)
  {
    muqtu();
  }
  return 0;
}