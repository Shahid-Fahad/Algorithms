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
int main()
{
    ll i,n,t;
    cin >> t;
    sieve(113);
    while(t--)
    {
        ll n;
        cin >> n;
        cout << prime[n-1] << endl;
    }
}
