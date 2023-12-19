#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
using namespace std;
void muqtu()
{
    ll n;
    cin >> n;
    vl arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    ll total = (n * (n + 1)) / 2;
    ll ans = total - sum;
    cout << ans << endl;
}
int main()
{
    ll t;
    t = 1;
    while (t--)
    {
        muqtu();
    }
}