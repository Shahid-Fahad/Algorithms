
///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
vector<long long int>prime;
bool mark[1000001];
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
    ll sqrtn = sqrt(n);
    for(i=3; i<=sqrtn; i=i+2)
    {
        if(mark[i]==false)
        {
            for(j=i*i; j<=n; j+=2*i)
                mark[j]=true;
        }
    }
    for(ll i=3;i<=n;i=i+2)
        if(mark[i]==false)
        prime.push_back(i);

}
vector<ll> segsieve(ll l, ll r)
{

    vector<ll>segprime;
    bool isprime[r-l+1];
    ll i,j;
    for(i=0; i<=r-l; i++)
        isprime[i]=true;
    if(l==1)
        isprime[0]=false;
    for(i=0; prime[i]*prime[i]<=r; i++)
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
    //ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    sieve(1000000);
    ll l,r,i;
    while(cin >> l >> r)
    {
        vector<ll> segprime;
        segprime = segsieve(l,r);
        ll Min=1000000000000,Max=0,p,p1,p2,p3,p4;
        if(segprime.size()<2)
            cout << "There are no adjacent primes." << endl;
        else
        {
            for(i=0; i<segprime.size()-1; i++)
            {
                p = segprime[i+1]-segprime[i];
                if(p<Min)
                {
                    Min=p;
                    p1=segprime[i];
                    p2=segprime[i+1];
                }
                if(p>Max)
                {
                    Max=p;
                    p3=segprime[i];
                    p4=segprime[i+1];
                }

            }
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",p1,p2,p3,p4);
        }

    }
}
