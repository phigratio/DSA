#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
using namespace std;
void muqtu()
{
   int n;
   cin>>n;
   if(n>3)
   {
   int s,e;
   if(n%2)
   {
   s=n;
   e=n-1;
   }
   else
   {
    s=n-1;
    e=n;
   }
 
    while (s>=1)
    {
        cout<<s<<" ";
        s-=2;
    }
 
    while (e!=0)
    {
        cout<<e<<" ";
        e-=2;
    }
   }
   else if(n==1)
   cout<<1<<endl;
   else
   {
    cout<<"NO SOLUTION"<<endl;
   }
   
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