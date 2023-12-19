#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
using namespace std;
void muqtu()
{
    ll n;
    cin>>n;
    vl arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    ll ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]<arr[i])
        {
            ans+=arr[i]-arr[i+1];
            arr[i+1]=arr[i];
        }
    }
    cout<<ans<<endl;
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