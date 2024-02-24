#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e6
vector<ll> arr(maxi);
vector<ll> arr2(maxi);
// void selectionSort(ll n)
// {
//   for (int i = 0; i < n-1; i++)
//   {
//     int minIdx = i;
//     for (int j = i + 1; j < n; j++)
//     {
//       if (arr[minIdx] > arr[j])
//       {
//         minIdx = j;
//       }
//     }
//     if (minIdx != i)
//     {
//       swap(arr[minIdx], arr[i]);
//     }
//   }
// }

void insertionSort(ll n)
{
  ll key;
  ll i = 0;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
  }

  ll j = i - 1;
  while (j >= 0 and arr[j] > key)
  {
    arr[j + 1] = key;
    j = j - 1;
  }

  arr[j + 1] = key;
}
void solve()
{
}
int main()
{
  ll n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> arr2[i];
  }
  sort(arr.begin(), arr.begin() + n);
  sort(arr2.begin(), arr2.begin() + m);

  ll i = 0;
  ll j = 0;
  ll count = 0;
  while (i < n and j < m)
  {
    ll val = abs(arr[i] - arr2[j]);
    if (val <= k)
    {
      count++;
      i++;
      j++;
    }
    else
    {
      if (arr[i] > arr2[j])
        j++;
      else
        i++;
    }
  }

  cout << count << endl;

  return 0;
}