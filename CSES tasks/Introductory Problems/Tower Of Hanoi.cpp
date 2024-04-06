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
void rec(ll a, ll b, ll c, ll n)
{
  if (n == 0)
    return;
  rec(a, c, b, n - 1);
  cout << a << " " << c << endl;
  rec(b, a, c, n - 1);
}
void muqtu()
{
  ll n;
  cin >> n;
  cout << pow(2, n) - 1 << endl;
  rec(1, 2, 3, n);
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