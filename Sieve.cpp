///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
vector<long long int>prime;
vector<bool>mark(100000005,true);
vector<ll>hp(100000005,0);
void sieve(ll n)
{
    ll i,j;
    prime.clear();
    mark[0]=mark[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(mark[i]==true)
        {
            prime.push_back(i);
            hp[i]=i;
            for(ll j=2*i;j<=n;j+=i)
            {
                mark[j]=false;
                hp[j]=i;
            }
        }
    }

}
vector<ll>pfact;
void pf(ll n)
{
    pfact.clear();
    while(n>1)
    {
        ll pr = hp[n];
        while(n%pr==0)
        {
            n=n/pr;
            pfact.push_back(pr);
        }
    }
}
int main()
{
    ll i,n,t;
    //cin >> t;
    sieve(100000000);
    cout<<prime.size()<<endl;
    while(t--)
    {
        
    }
}
