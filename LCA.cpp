///Bismillahir Rahmanir Rahim
//ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<ll>v[10005];
ll depth[10005],up[10005][15];
void dfs(ll n)
{
    for(auto child:v[n])
    {
        up[child][0]=n;
        depth[child]=depth[n]+1;
        for(ll i=1;i<15;i++)
        {
            up[child][i]=up[up[child][i-1]][i-1];
        }
        dfs(child);
    }
}
ll lca(ll a,ll b)
{
    if(depth[a]<depth[b])
    swap(a,b);
    ll k = depth[a]-depth[b];
    for(ll i=0;i<15;i++)
    {   
        if(k&(1<<i))
        a = up[a][i];
    }
    if(a==b)
    return a;
    for(ll i=14;i>=0;i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
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
        ll n;
        cin>> n;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            while(x--)
            {
                ll y;
                cin>>y;
                v[i].pb(y);
            }
        }
        dfs(0);
        ll q;
        cin>>q;
        while(q--)
        {
            ll x,y;
            cin>> x >> y;
            cout << lca(x,y) << endl;
        }
    } 
}
