#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ll n;
  cin >> n;
  ll arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  int mid = n / 2;
  if (!(n & 1))
  {
    mid = n / 2 - 1;
  }
  cout << arr[mid] << endl;
}