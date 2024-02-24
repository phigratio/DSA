#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e6
vector<ll> arr(maxi);
void selectionSort(ll n)
{
  for (int i = 0; i < n; i++)
  {
    int minIdx = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[minIdx] > arr[j])
      {
        minIdx = j;
      }
    }
    if (minIdx != i)
    {
      swap(arr[minIdx], arr[i]);
    }
  }
}
void solve()
{
}
int main()
{
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // sort(arr.begin(), arr.begin() + n);
  selectionSort(n);
  ll count = 1;
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] != arr[i + 1])
    {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}