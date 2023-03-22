///Bismillahir Rahmanir Rahim
//ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
ll bit[400005];
ll arr[200005];
ll mx=200005;
void update(ll i,ll x)
{
    for(;i<mx;i+=(i&-i))
    bit[i]+=x;
}
ll sum(ll i)
{
    ll ans=0;
    for(;i>0;i-=(i&-i))
    {
        ans+=bit[i];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,tc=0;
    //cin >> t;
    while(t--)
    {
        //tc++;case_(tc);
        ll n,q;
        cin >> n >> q;
        for(ll i=1;i<=n;i++)
        {
            cin >> arr[i];
            update(i,arr[i]);
        }
        while(q--)
        {
            ll tp;
            cin >> tp;
            if(tp==1)
            {
                ll k,u;
                cin >> k >> u;
                update(k,u-arr[k]);
                arr[k]=u;
            }
            else
            {
                ll l,r;
                cin >> l >> r;
                cout << sum(r)-sum(l-1) << endl;
            }
        }
    } 
}