#include<bits/stdc++.h>
#define ll long long
using namespace std;
void muqtu()
{
    ll n;
    cin>>n;
    cout<<n<<" ";
    while (n!=1)
    {
        if(n%2)
        {
            n*=3;
            n+=1;
            cout<<n<<" ";
        }
        else
        {
            n/=2;
            cout<<n<<" ";
        }
    }
    
}
int main() {
    ll t;
    t=1;
    while (t--)
    {
        muqtu();
    }
    
}