///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
vector<long long int>prime;
bool mark[1000006];
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
vector<ll>pf;
void primeFactors(ll n)
{
   ll x = sqrt(n);
   for(ll i=0;i<prime.size()&&prime[i]<=x;i++)
   {
       if(n%prime[i]==0)
       {
           while(n%prime[i]==0)
           {
               pf.push_back(prime[i]);
               n = n/prime[i];
           }
       }
       x = sqrt(n);
   }
   if(n>1)
   {
       pf.push_back(n);
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i;
    cin >> n;
    sieve(1000005);
    primeFactors(n);
    for(i=0; i<pf.size(); i++)
        cout << pf[i] << " ";
    cout << endl;

}
