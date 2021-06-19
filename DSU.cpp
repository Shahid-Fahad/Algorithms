///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
ll arr[1e5+1];
ll Find(ll n)
{
    if(arr[n]==n)
        return n;
    else
        return Find(arr[n]);
}
void Union(ll a, ll b)
{
    ll x = Find(a);
    ll y = Find(b);

    arr[x] = y;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n+5];
    for(ll i=1;i<=n;i++)
         arr[i]=i;


}

