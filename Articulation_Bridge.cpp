///Bismillahir Rahmanir Rahim
//ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define all(qz) qz.begin(),qz.end()
vector<ll>v[10005];
ll low[10005],tin[10005],vis[10005],timer=1;
set<pair<ll,ll>>s;
void dfs(ll n,ll p)
{
    vis[n]=1;
    low[n]=tin[n]=timer++;
    for(ll i=0;i<v[n].size();i++)
    {
        ll child = v[n][i];
        if(child==p)continue;
        if(vis[child]==1)
        low[n]=min(low[n],tin[child]);
        else
        {
            dfs(child,n);
            low[n]=min(low[n],low[child]);
            if(low[child]>tin[n])
            {
               s.insert({min(n,child),max(n,child)});
            }
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll t=1,tc=0;
    cin >> t;
    while(t--)
    {
        cout<<endl;
        ll n;
        cin >> n;
        mem(vis,0),s.clear(),timer=1;
        for(ll i=0;i<n;i++)
        v[i].clear();
        for(ll i=0;i<n;i++)
        {
            ll x,y,k;
            string str;
            cin >> x >> str;
            str.pop_back();
            reverse(all(str));
            str.pop_back();
             reverse(all(str));
            k = stoll(str);
            while(k--)
            {
                cin>>y;
                v[x].pb(y);
                v[y].pb(x);
            }

        }
            for(ll i=0;i<n;i++)
            {
                if(vis[i]==0)
                {
                    dfs(i,-1);
                }
            }
            cout << s.size() <<" critical links\n";
            for(auto it:s)
            {
                cout << it.ff << " - " << it.ss << endl;
            }

    }
}
