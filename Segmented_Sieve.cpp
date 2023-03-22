///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
vector<ll>prime;
bool mark[10000005];
void sieve(ll n)
{
    ll i,j;
    prime.clear();
    mark[0]=true;
    mark[1]=true;
    mark[2]=false;
    prime.push_back(2);
    for(i=4; i<=n; i+=2)
        mark[i]=true;
    for(i=3; i<=n; i=i+2)
    {
        if(mark[i]==false)
        {
            prime.push_back(i);
            for(j=i*i; j<=n; j=j+i)
                mark[j]=true;
        }
    }

}
vector<ll> segprime;
vector<ll> segsieve(ll l, ll r)
{

    vector<ll>segprime;
    bool isprime[r-l+1];
    ll i,j;
    for(i=0; i<=r-l; i++)
        isprime[i]=true;
    if(l==1)
        isprime[0]=false;
    for(i=0;prime[i]*prime[i]<=r&&i<prime.size(); i++)
    {
        ll cp = prime[i];
        ll base = (l/cp)*cp;
        if(base<l)
            base = base+cp;
        for(j=base; j<=r; j=j+cp)
            isprime[j-l]=false;
        if(base==cp)
            isprime[base-l]=true;
    }
    for(i=0; i<=r-l; i++)
    {
        if(isprime[i]==true)
            segprime.push_back(i+l);
    }
    return segprime;
}
int main()
{
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    sieve(10000005);
    
    ll l,r,i;
    while(cin >> l >> r)
    {
        segprime=segsieve(l,r);
        for(auto it :segprime)
        {
            cout << it << " ";
        }
        cout << endl;

    }
}
