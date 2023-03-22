///Bismillahir Rahmanir Rahim
//ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define all(qz) qz.begin(),qz.end()
vector<ll>v[10005];
ll low[10005],tin[10005],vis[10005],timer=1;
set<ll>s;
void dfs(ll n,ll p)
{
    vis[n]=1;
    tin[n]=low[n]=timer++;
    ll cld=0;
    for(auto child:v[n])
    {
        if(child==p)continue;
        if(vis[child]==1)
        {
            low[n]=min(low[n],tin[child]);
        }
        else
        {
            dfs(child,n);
            low[n]=min(low[n],low[child]);
            if(low[child]>=tin[n]&&p!=-1)
            {
                s.insert(n);
            }
            cld++;
        }
        if(p==-1&&cld>1)
        s.insert(n);

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,tc=0;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >>n>>m;
        mem(vis,0),timer=1;
        s.clear();
        for(ll i=1;i<=n;i++)
        v[i].clear();
        while(m--)
        {
            ll x,y;
            cin >>x >> y;
            v[x].pb(y);
            v[y].pb(x);
        }
        dfs(1,-1);
        cout << s.size() << endl;
    }
}

