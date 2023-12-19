#include<bits/stdc++.h>
#define ll long long
using namespace std;
void muqtu()
{
    string s;
    cin>>s;
    ll maxi=0;
    ll count=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            count++;
        }
        else
        {
            maxi=max(count,maxi);
            count=0;
        }
        
    }
    maxi=max(count,maxi);
    cout<<maxi+1<<endl;
    
}
int main() {
    ll t;
    t=1;
    while (t--)
    {
        muqtu();
    }
    
}