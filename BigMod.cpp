///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
ll bigmod(ll b,ll p,ll m)
{
    if(p==0)
        return 1%m;
    ll x = bigmod(b,p/2,m);
    x  = ((x%m)*(x%m))%m;
    if(p%2==1)
        x = ((x%m)*(b%m))%m;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll b,p,m;
    while(cin >> b >> p >> m)
    {
        cout << bigmod(b,p,m) << endl;
    }
}
